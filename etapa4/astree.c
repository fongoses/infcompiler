#include "astree.h"
#include <string.h>

char error;
ASTREE * TREE;

ASTREE * astreeCreate(int type, ASTREE * S0, ASTREE * S1, ASTREE * S2, ASTREE * S3, HASH_NODE * n){

	ASTREE * node = 0;

	node = (ASTREE*) calloc(1,sizeof(ASTREE));	

	//init
	node->type = type;
	node->symbol= n; //07/05 ponteiro para tb de simbolos	
	node->lineNumber = getLineNumber();
	node->son[0] = S0;
	node->son[1] = S1;
	node->son[2] = S2;
	node->son[3] = S3;
	return node;
}


//retorna o DATATYPE de uma litseq. O tipo da litseq eh o tipo dos literais que a compoem
int getLitSeqType(ASTREE * node){
	
	ASTREE * first,*rest;
	if(!node) return DATATYPE_INVALID;
	
	first = node->son[1]; //lit
	rest=node->son[0];	//litseq
	while(rest){		
		if(first->symbol->decType != node->son[1]->symbol->decType) return DATATYPE_INVALID;
		first=rest->son[1];
		rest=rest->son[0];
	}	
	return first->symbol->decType;	

}

//dado um nodo do tipo dec, retorna o tipo da declaracao.Funcao auxiliar a getDeclarationType
int getType(ASTREE * node){
	
	if(!node) return DATATYPE_INVALID;
	if(!node->son[0]) return DATATYPE_INVALID;
	switch (node->son[0]->type){
		case ASTREE_KWWORD:
			return DATATYPE_WORD;		

		case ASTREE_KWBYTE:
			return DATATYPE_BYTE;		
		
		case ASTREE_KWBOOL:
			return DATATYPE_BOOL;
	
		default: return DATATYPE_INVALID;

	}
}


//Obtem decType(word, byte ou bool) das declaracoes
int getDeclarationType(ASTREE * node){

	if(!node) return DATATYPE_INVALID;
	switch (node->type){

		case ASTREE_VARDEC:
			return getType(node);		
		
	       /* da mesma forma, DECTYPE_VECTOR eh retornado para chamada ou declaracao de vetores */ 
		case ASTREE_VETORDEC:
			return getType(node);		

		case ASTREE_FUNDEC: 	
			return getType(node);		

		case ASTREE_PTRDEC: 	
			return getType(node);		
	
		//literais tb sao declaracoes	
		case ASTREE_LIT_INT:
			return DATATYPE_WORD;

		case ASTREE_LIT_FALSE:		
			return DATATYPE_BOOL;

		case ASTREE_LIT_TRUE:
			return DATATYPE_BOOL;
		
		case ASTREE_LIT_CHAR:
			return DATATYPE_BYTE;
		
		case ASTREE_LIT_STRING:
			return DATATYPE_STRING;
		
		case ASTREE_PARAM:
			return getType(node);
		
		case ASTREE_PTRPARAM:
			return getType(node);
	
				
		//symbols possuem tipo ja associados
		default: return 0;
	}
}

//Obtem dataType (scalar, vector,pointer ou function) das declaracoes
int getDataType (ASTREE * node){

	if(!node) return DEC_ERR;
	switch (node->type){
			
		/* O tipo DECTYPE_SCALAR eh retornado ao se encontrar um nodo ASTREE_VARDEC ou ASTREE_SYMBOL */
		case ASTREE_VARDEC:
			return DECTYPE_SCALAR;
		    
		case ASTREE_SYMBOL: //obs.: symbol eh 'chamada'/utilizacao de variavel
			return DECTYPE_SCALAR;
		
	       /* da mesma forma, DECTYPE_VECTOR eh retornado para chamada ou declaracao de vetores */ 
		case ASTREE_VETORDEC:
			return DECTYPE_VECTOR;
	    
		case ASTREE_VETCALL:
			return DECTYPE_VECTOR;

		case ASTREE_FUNDEC: 	
			return  DECTYPE_FUNCTION;
			
		case ASTREE_FUNCALL: 	
			return  DECTYPE_FUNCTION;

		case ASTREE_PTRDEC: 	
			return  DECTYPE_POINTER;

		case ASTREE_PTRADDR: //PTRADDR: 'chamada'/utilizacao de um ponteiro declarado 	
			return  DECTYPE_POINTER;
	
		case ASTREE_PARAM:
			return DECTYPE_SCALAR;
		
		case ASTREE_PTRPARAM:
			return DECTYPE_POINTER;
		
		//literais possuem dataType scalar
		case ASTREE_LIT_INT:
			return DECTYPE_SCALAR;

		case ASTREE_LIT_FALSE:		
			return DECTYPE_SCALAR;

		case ASTREE_LIT_TRUE:
			return DECTYPE_SCALAR;
		
		case ASTREE_LIT_CHAR:
			return DECTYPE_SCALAR;
		
		case ASTREE_LIT_STRING:
			return DECTYPE_SCALAR;

		default: return DEC_ERR;
	}
}

void setType(ASTREE * node){
	if(!node) return;
	if(!node->symbol) return;
	if(node->symbol->declared) return;
	node->symbol->dataType = getDataType(node); //a partir do ponteiro setado na linha acima, atribui tipo ao elem na tab de simb, mas somente se esse simb ja nao estiver declarado
	node->symbol->decType = getDeclarationType(node);
}

/*Compara tipo de simbolos a partir dos nodos originarios.
Funcao utilizada na comparacao de argumentos de funcoes com os parametros na sua declaracao,
sendo util quando queremos comparar simbolos a partir do nodo da arvore (durante a chamada de funcao, 
os parametros declarados sao recuperados atraves da arvore de sintaxe abstrata) e não diretamente
a partir da tabela de símbolos.

retorno:
	1: mesmo tipo.
	0: tipos diferentes.
*/
int equalType(ASTREE * n1, ASTREE * n2){

	
	if ((!n1) && (!n2)) return 1;
	if ((!n1) && (n2)) return 0;	
	if ((n1) && (!n2)) return 0;
	if ((!(n1->symbol)) || (!(n2->symbol))) return 0;

	return ((n1->symbol->dataType == n2->symbol->dataType) && (n1->symbol->decType == n2->symbol->decType));
	
}

//compara os tipos dos argumentos passados na chamada da funcao com os tipos declarados na definicao da funcao
//a funcao espera que tanto a declaracao como a chamada possuam quantidade igual de parametros
//Espera-se como entrada da funcao, um nodo da arvore do tipo ASTREE_FUNCALL
int validArguments(ASTREE * node){
	
	ASTREE * fundecNode;
	ASTREE * currentArg;
	ASTREE * currentParam;
	ASTREE * paramSeq;
	ASTREE * argSeq;
	if(!node) return DATATYPE_INVALID;
	
	argSeq = node->son[0];
	currentArg = argSeq->son[1];
	fundecNode = nodeFind(TREE,ASTREE_FUNDEC,node->symbol->text);
	paramSeq = fundecNode->son[1];
	if(!paramSeq) return DATATYPE_VALID;
	currentParam=paramSeq->son[1];

	//seq de tam 1
	if(paramSeq->type == ASTREE_PARAM) {
		currentParam = 	paramSeq;
		currentArg = argSeq;
//		fprintf(stderr,"symbol: %s cA: %d, cp: %d\n",currentArg->symbol->text,currentArg->symbol->dataType,currentParam->symbol->dataType);		
		if(!equalType(currentArg,currentParam)) return DATATYPE_INVALID;
		return DATATYPE_VALID;
		
	}
	while(paramSeq){
		//fim das duas seq
		if(paramSeq->son[0])
			if(paramSeq->son[0]->type == ASTREE_PARAM){
				currentArg=argSeq->son[1];
				currentParam=paramSeq->son[1];
				//fprintf(stderr,"cA: %d, cp: %d\n",currentArg->symbol->decType,currentParam->symbol->decType);
				if(!equalType(currentArg,currentParam)) return DATATYPE_INVALID;
				if(!equalType(argSeq->son[0],paramSeq->son[0])) return DATATYPE_INVALID;
			}
		
		//qndo n eh o fim		
		if(currentParam){
				
			//fprintf(stderr,"cA: %d, cp: %d\n",currentArg->symbol->decType,currentParam->symbol->decType);
			if(!equalType(currentArg,currentParam)) return DATATYPE_INVALID;
			paramSeq=paramSeq->son[0];
			if(!paramSeq) break;

			currentParam=paramSeq->son[1];
			argSeq=argSeq->son[0];
			currentArg=argSeq->son[1];
		}else break;	
	}	
	return DATATYPE_VALID;
}
//seta uma variavel como declarada apos a primeira passada (no inicio do programa, quando eh zero)
int astreeSetDeclarations(ASTREE * node){

	if(!node) return ;
	int i;
	HASH_NODE *tempNode;

	if (!node) return DEC_ERR;
	
	tempNode=hashFind(node->symbol->text);	
	if(!tempNode) return DEC_OK;
	if(!tempNode->declared) tempNode->declared=1;
	return DEC_OK;
	
}

void  astreeSetSymbolTypes(ASTREE * node){

	int i;
	if (!node) return;

	setType(node);

	for(i=0;i<MAX_SONS;i++){
		astreeSetSymbolTypes(node->son[i]);
	}
}

void  astreeCheckDeclarations(ASTREE * node){

	int i;
	if (!node) return;

	//setType(node);
	
	astreeCheckDeclarationsSingle(node);

	for(i=0;i<MAX_SONS;i++){
		astreeCheckDeclarations(node->son[i]);
	}
}

//checa declaracoes de variaveis
void astreeCheckDeclarationsSingle(ASTREE * node){
	HASH_NODE *tempNode;
	if (!node) return;	

	astreeCheckRedeclarations(node);
	astreeCheckUndeclaredAndDatatype(node);
	
}


void astreeCheckUndeclaredAndDatatype(ASTREE * node){
		
	/*	1) Verifica variaveis nao declaradas
		2) Em alguns tipos de nos, verifica se utilizacao bate com o tipo da declaracao (scalar, vetor, ponteiro, vetor ou funcao)*/	

	
	HASH_NODE *tempNode;
	if(!node) return;

	switch(node->type){
	
		case ASTREE_SYMBOL: //SYMBOL eh um simbolo escalar da ast(veja yacc.y)
			
			tempNode=hashFind(node->symbol->text);
		
			if(!tempNode) error=1; //variavel nao declarada
		
			if(!tempNode->declared){
				fprintf(stdout,"error at line %d: var '%s' not declared.\n",node->lineNumber,node->symbol->text);	
			 	error=1;
				return;
			}
	        	if (tempNode->dataType != DECTYPE_SCALAR ) {
                		fprintf(stderr,"error at line %d: symbol '%s' is beeing used as scalar but its not declared as a scalar.\n",node->lineNumber,node->symbol->text);
               	 		error=1;
            		}
			break;
					
		case ASTREE_VETCALL:
			
			tempNode=hashFind(node->symbol->text);
			
			if(!tempNode) error=1; //variavel nao declarada
			if(!tempNode->declared){
				fprintf(stdout,"error at line %d: vector '%s' not declared.\n",node->lineNumber,node->symbol->text);
				error=1;
			}
            		if(tempNode->dataType != DECTYPE_VECTOR) {                
                		fprintf(stderr,"error at line %d: symbol '%s' is beeing used as a vector but its not declared as a vector.\n",node->lineNumber,node->symbol->text);
                		error=1;
            		}
			break;



		case ASTREE_FUNCALL:
			
			tempNode=hashFind(node->symbol->text);
			
			if(!tempNode){
				fprintf(stdout,"error at line %d: function '%s()' not declared.\n",node->lineNumber,node->symbol->text);
				error=1; //variavel nao declarada
			}
		
			if(!tempNode->declared){
				fprintf(stdout,"error at line %d: function '%s()' not declared.\n",node->lineNumber,node->symbol->text);
				error=1;
			}
			break;
	
		case ASTREE_PTRADDR:
			
			tempNode=hashFind(node->symbol->text);
			
			if(!tempNode){
				fprintf(stdout,"error at line %d: var &%s not declared.\n",node->lineNumber,node->symbol->text);
				error=1; //variavel nao declarada
			}
		
			if(!tempNode->declared){
				fprintf(stdout,"error at line %d: var '%s' not declared.\n",node->lineNumber,node->symbol->text);
				error=1;
			}
			break;

		case ASTREE_PTRVALUE:
			
			tempNode=hashFind(node->symbol->text);
			
			if(!tempNode){
				fprintf(stdout,"error at line %d: var *%s not declared.\n",node->lineNumber,node->symbol->text);			
				error=1; //variavel nao declarada
			}
		
			if(!tempNode->declared){ 
				fprintf(stdout,"error at line %d: var '%s' not declared.\n",node->lineNumber,node->symbol->text);
				error=1;
			}

			break;
			  
		
		case ASTREE_SCALAR_ASS:
			
			tempNode=hashFind(node->symbol->text);
			
			if(!tempNode){
				fprintf(stdout,"error at line %d: var '%s' not declared.\n",node->lineNumber,node->symbol->text);			
				error=1; //variavel nao declarada
			}
		
			if(!tempNode->declared){
				fprintf(stdout,"error at line %d: var '%s' not declared.\n",node->lineNumber,node->symbol->text);
				error=1;
			}
			
			if (tempNode->dataType != DECTYPE_SCALAR ) {
				fprintf(stderr,"error at line %d: symbol '%s' is beeing used as scalar but its not declared as a scalar.\n",node->lineNumber,node->symbol->text);
				error=1;
			}
			
			break;
       
       	
		case ASTREE_PTR_ASS:
			
			tempNode=hashFind(node->symbol->text);
			
			if(!tempNode){
				fprintf(stdout,"error at line %d: var *%s not declared.\n",node->lineNumber,node->symbol->text);			
				error=1; //variavel nao declarada
			}
			
            		if(!tempNode->declared){
				fprintf(stdout,"error at line %d: var '%s' not declared.\n",node->lineNumber,node->symbol->text);
				error=1;
			}          		
			break;

		case ASTREE_DEREF_ASS:
			
			tempNode=hashFind(node->symbol->text);
			
			if(!tempNode){
				fprintf(stdout,"error at line %d: var *%s not declared.\n",node->lineNumber,node->symbol->text);			
				error=1; //variavel nao declarada
			}
		
			if(!tempNode->declared){
				fprintf(stdout,"error at line %d: var '%s' not declared.\n",node->lineNumber,node->symbol->text);
				error=1;
			}
	
		    	if (tempNode->dataType != DECTYPE_POINTER ) {
                		fprintf(stderr,"error at line %d: symbol '%s' is beeing used as a deref but its not declared as a pointer.\n",node->lineNumber,node->symbol->text);
                		error=1;
            		}
			break;


		
		case ASTREE_VET_ASS:
			
			tempNode=hashFind(node->symbol->text);
			
			if(!tempNode){
			fprintf(stdout,"error at line %d: var '%s' not declared.\n",node->lineNumber,node->symbol->text);
			
			error=1; //variavel nao declarada
			}
		
			if(!tempNode->declared){
				fprintf(stdout,"error at line %d: var '%s' not declared.\n",node->lineNumber,node->symbol->text);
				error=1;
			}
			
			if (tempNode->dataType != DECTYPE_VECTOR ) {
                		fprintf(stderr,"error at line %d: symbol '%s' is beeing used as a vector but its not declared as a vector.\n",node->lineNumber,node->symbol->text);
                		error=1;
            		}
			break;
		
		case ASTREE_INPUT:
			
			tempNode=hashFind(node->symbol->text);
			
			if(!tempNode){
				fprintf(stdout,"error at line %d: var '%s' not declared.\n",node->lineNumber,node->symbol->text);
			
				error=1; //variavel nao declarada
			}
		
			if(!tempNode->declared){
				fprintf(stdout,"error at line %d: var '%s' not declared.\n",node->lineNumber,node->symbol->text);
				error=1;
			}
			
			if (tempNode->dataType != DECTYPE_VECTOR ) {
				fprintf(stderr,"error at line %d: symbol '%s' is beeing used as a vector but its not declared as a vector.\n",node->lineNumber,node->symbol->text);
				error=1;
            		}
			break;

	default: return;

	}


}


/*
	A partir de um nodo que representa uma sequencia, calcula o tamanho dessa sequencia
	Essa funcao eh util quando ha necessidade de descobrir, por exemplo, o numero de parametros/argumentos
	de uma funcao
*/
int getSeqSize(ASTREE* node){

	if(!node) return 0;
	return 1 + getSeqSize(node->son[0]);

}
void astreeCheckRedeclarations(ASTREE * node){

	HASH_NODE *tempNode;
	if (!node) return;
	int paramNum;
	switch (node->type){ 
		case ASTREE_VARDEC:					
			
			tempNode=hashFind(node->symbol->text);
			//TODO: ajustar para analisar o campo declaration do no		
			if(!tempNode) return;

			if(tempNode->declared){				
				fprintf(stdout,"error at line %d: Var '%s' already declared at line %d.\n",node->lineNumber,tempNode->text,tempNode->lineNumber);
				error=1;
				return;
			}

			break;
		
		case ASTREE_PTRDEC:					
			
			tempNode=hashFind(node->symbol->text);
			//TODO: ajustar para analisar o campo declaration do no		
			if(!tempNode) return;

			if(tempNode->declared) 	{				
				fprintf(stdout,"error at line %d: Var $'%s' already declared at line %d.\n",node->lineNumber,tempNode->text,tempNode->lineNumber);
				error=1;
				return;
			}
			break;

		
		case ASTREE_VETORDEC:					
			
			tempNode=hashFind(node->symbol->text);
			//TODO: ajustar para analisar o campo declaration do no		
			if(!tempNode) return;

			if(tempNode->declared) 	{				
				fprintf(stdout,"error at line %d: Vector '%s' already declared at line %d.\n",node->lineNumber,tempNode->text,tempNode->lineNumber);
				error=1;
				return;
			}

			break;
		
	
		case ASTREE_FUNDEC:					
			
			tempNode=hashFind(node->symbol->text);
			//TODO: ajustar para analisar o campo declaration do no		
			if(!tempNode) return;

			if(tempNode->declared) 	{				
				fprintf(stdout,"error at line %d: Function '%s' already declared at line %d.\n",node->lineNumber,tempNode->text,tempNode->lineNumber);
				error=1;
				return;
			}
			//get numberofparams
			if(node->son[1])//se ha parametros
				node->symbol->paramNum = getSeqSize(node->son[1])-1; //passa para a funcao o nodo ASTREE_ARGSEQ
				//-1 pois a o tipo faz parte dessa sequencia(no lado esq da recursao), e acaba contando
			else node->symbol->paramNum = 0;						
			break;
				

		default: return;
	}

	if(!node->symbol->declared) astreeSetDeclarations(node);

}



//checa natureza/tipo de expressoes
int astreeCheckNature(ASTREE * node){

	if(!node) return ;
	int i;
	HASH_NODE *tempNode;
	int result;
	int resultTemp;	
	int itemNum; //para verificacao de elementos na declaracao de vetor	
	int temp;
	char * ptrl;//para strtol
	ASTREE*decTemp;
	int paramNum; //numero de parametros da funcao
	if (!node) return DATATYPE_INVALID;	

	switch (node->type){ 
	
        case ASTREE_LIT_INT: return DATATYPE_WORD;
    
        case ASTREE_LIT_FALSE: return DATATYPE_BOOL;
         
        case ASTREE_LIT_TRUE: return DATATYPE_BOOL;
        
        case ASTREE_LIT_CHAR: return DATATYPE_BYTE;        
        
	case ASTREE_LIT_STRING: return DATATYPE_STRING;  
	
	case ASTREE_LIT_SEQ:
		result = astreeCheckNature(node->son[1]);
		resultTemp = getLitSeqType(node->son[0]);
		if(result != resultTemp){			
			fprintf(stderr,"error at line %d: initializing vector with multiple types.\n",node->lineNumber);
			 return DATATYPE_INVALID;
		}
		return result;	
        
        case ASTREE_PTRADDR: return DECTYPE_POINTER;
         
        case ASTREE_PTRVALUE: return DECTYPE_POINTER;
        	
	case ASTREE_SYMBOL: return node->symbol->decType;
	
	case ASTREE_ADD:
		result = astreeCheckMathExpression(node);
		if (result == DATATYPE_INVALID){
		//	fprintf(stderr,"symbol: %s decType: %d, dataType: %d\n",node->son[0]->symbol->text,node->son[0]->symbol->decType,node->son[0]->symbol->dataType); 
			fprintf(stderr,"error at line %d: sum operator expects word/byte types of operands.\n",node->lineNumber);
			return DATATYPE_INVALID;
		}		
		return result;

	case ASTREE_MIN:
		result = astreeCheckMathExpression(node);
		if (result == DATATYPE_INVALID){ 
			fprintf(stderr,"error at line %d: min operator expects word/byte types of operands.\n",node->lineNumber);
			return DATATYPE_INVALID;
		}		
		return result;
	
	case ASTREE_MUL:
		result = astreeCheckMathExpression(node);
		if (result == DATATYPE_INVALID){ 
			fprintf(stderr,"error at line %d: mul operator expects word/byte types of operands.\n",node->lineNumber);
			return DATATYPE_INVALID;
		}		
		return result;


	case ASTREE_DIV:
		result = astreeCheckMathExpression(node);
		if (result == DATATYPE_INVALID){ 
			fprintf(stderr,"error at line %d: div operator expects word/byte types of operands.\n",node->lineNumber);
			return DATATYPE_INVALID;
		}		
		return result;


	case ASTREE_PROGRAM:				
		return astreeCheckNature(node->son[0]);

	case ASTREE_GLOBALSEQ:
		resultTemp= astreeCheckNature(node->son[0]);
		result = astreeCheckNature(node->son[1]);
		if((result == DATATYPE_INVALID) || (resultTemp == DATATYPE_INVALID)) return DATATYPE_INVALID;
		return DATATYPE_VALID;	
	
	case ASTREE_FUNDEC:
		return astreeCheckNature(node->son[3]); //check blocks
	
	/*Obs, nao eh necessario verificar parametros na declaracao(PARAMSEQ), apenas na chamada (ARGSEQ)	
	case ASTREE_PARAMSEQ:
		//sequencia de argumentos de funcao eh semelhante a globalseq (apenas verifica tipos da sequencia um a 1)
		resultTemp= astreeCheckNature(node->son[0]);
		result = astreeCheckNature(node->son[1]);
		if((result == DATATYPE_INVALID) || (resultTemp == DATATYPE_INVALID)) return DATATYPE_INVALID;
		return DATATYPE_VALID;	
	*/	
	
	case ASTREE_BLOCK:
		return astreeCheckNature(node->son[0]);
	
	case ASTREE_COMMANDSEQ:
		
		resultTemp= astreeCheckNature(node->son[0]);
		result = astreeCheckNature(node->son[1]);
		if((result == DATATYPE_INVALID) || (resultTemp == DATATYPE_INVALID)) return DATATYPE_INVALID;
		return DATATYPE_VALID;	
		

	case ASTREE_SCALAR_ASS:	
		result = astreeCheckNature(node->son[0]);
		if(node->symbol->decType == result) return DATATYPE_ASSIGN;
		return DATATYPE_INVALID;	

	
	/*Verificacao de tipo nas declaracoes*/

	case ASTREE_VARDEC:
		temp=astreeCheckNature(node->son[1]);
		if (node->symbol->decType == temp) return DATATYPE_VALID;		
		fprintf(stderr,"error at line %d: declaration type mismatch of its initialization.\n",node->symbol->lineNumber);
		return DATATYPE_INVALID;

	
	case ASTREE_VETORDEC:
		if(node->son[2]){
			itemNum = strtol(node->son[1]->symbol->text,&ptrl,16);		
			if(itemNum != getSeqSize(node->son[2])){
				fprintf(stderr,"error at line %d: vector size differs from the vector initialization.\n",node->symbol->lineNumber);
				return DATATYPE_INVALID;
			}	
		}
		
		if(node->symbol->decType == astreeCheckNature(node->son[2])) return DATATYPE_VALID;	
		fprintf(stderr,"error at line %d: vector declaration type mismatch of its initialization.\n",node->symbol->lineNumber);
		return DATATYPE_INVALID;

	case ASTREE_FUNCALL:
		paramNum = getSeqSize(node->son[0]); 
		//verifica se numero de argumentos passados bate com numero de parametros declarados na funcao	
		if (node->symbol->paramNum != paramNum){
			fprintf(stderr,"error at line %d: function '%s' expects %d parameters, but it was given %d.\n",node->lineNumber,node->symbol->text,node->symbol->paramNum,paramNum);			
			return DATATYPE_INVALID; //se numero de parametros nao bate, nem testa os tipos
		}
		
		//verifica ARGSEQ
		if(node->son[0]) //valida argumentos apenas se existirem
			//valida tipos dos argumentos passados com os declarados na funcao
			if(validArguments(node) == DATATYPE_INVALID) {
				fprintf(stderr,"error at line %d: function '%s' mismatching type of its declaration\n",node->lineNumber,node->symbol->text);
				return DATATYPE_INVALID;
			}
		return node->symbol->decType;
	
	/*case ASTREE_ARGSEQ:
		//sequencia de argumentos de funcao eh semelhante a globalseq (apenas verifica tipos da sequencia um a 1)
		resultTemp= astreeCheckNature(node->son[0]);
		result = astreeCheckNature(node->son[1]);
		if((result == DATATYPE_INVALID) || (resultTemp == DATATYPE_INVALID)) return DATATYPE_INVALID;
		return DATATYPE_VALID;	
	*/
	
	case ASTREE_VETCALL:	
		result = astreeCheckNature(node->son[0]);
		if((result == DATATYPE_WORD) || (result == DATATYPE_BYTE)) return result;

		
		return DATATYPE_INVALID;	
		
	default: return 1;

    }

}
	
int astreeCheckMathExpression(ASTREE * node){

		
	if(!node) return DATATYPE_INVALID;

	if ((astreeCheckNature(node->son[0])== DATATYPE_WORD)
		&& (astreeCheckNature(node->son[1]) == DATATYPE_WORD)) 
			return DATATYPE_WORD;

	if ((astreeCheckNature(node->son[0])== DATATYPE_BYTE) 
		&& (astreeCheckNature(node->son[1]) == DATATYPE_WORD)) 
			return DATATYPE_WORD;            

	if ((astreeCheckNature(node->son[0])== DATATYPE_WORD) 
		&& (astreeCheckNature(node->son[1]) == DATATYPE_BYTE))
			return DATATYPE_WORD;

	if ((astreeCheckNature(node->son[0])== DATATYPE_BYTE) 
		&& (astreeCheckNature(node->son[1]) == DATATYPE_BYTE))
			return DATATYPE_WORD; //soma de bytes retorna word
    
	if ((astreeCheckNature(node->son[0])== DATATYPE_WORD) 
		&& (astreeCheckNature(node->son[1]) == DECTYPE_POINTER))
			return DECTYPE_POINTER; 

	if ((astreeCheckNature(node->son[0])== DECTYPE_POINTER) 
		&& (astreeCheckNature(node->son[1]) == DATATYPE_WORD))
			return DECTYPE_POINTER; 

	if ((astreeCheckNature(node->son[0])== DECTYPE_POINTER) 
		&& (astreeCheckNature(node->son[1]) == DECTYPE_POINTER)) 
			return DECTYPE_POINTER;
	
	return DATATYPE_INVALID;
}


void astreePrintSingle(ASTREE * node){

	if(!node) return ;
	
	fprintf(stdout,"ASTREE(");
	switch( node->type){
		case  ASTREE_SYMBOL: fprintf(stdout,"ASTREE_SYMBOL {%s}",node->symbol->text); break;
		case  ASTREE_LIT_INT: fprintf(stdout,"ASTREE_LIT_INT {%s}",node->symbol->text); break;
		case  ASTREE_ADD: fprintf(stdout,"ASTREE_ADD"); break;
		case  ASTREE_MIN: fprintf(stdout,"ASTREE_MIN"); break;
		case  ASTREE_MUL: fprintf(stdout,"ASTREE_MUL"); break;
		case  ASTREE_DIV: fprintf(stdout,"ASTREE_DIV"); break;
		case  ASTREE_SCALAR_ASS: fprintf(stdout,"ASTREE_SCALAR_ASS {%s}",node->symbol->text); break;
		case  ASTREE_LIT_SEQ: fprintf(stdout,"ASTREE_LIT_SEQ"); break;
		case  ASTREE_VARDEC: fprintf(stdout,"ASTREE_VARDEC {%s}",node->symbol->text); break;
		case  ASTREE_ARGSEQ: fprintf(stdout,"ASTREE_ARGSEQ"); break;
		case  ASTREE_FUNCALL: fprintf(stdout,"ASTREE_FUNCALL {%s}",node->symbol->text); break;
		case  ASTREE_VETCALL: fprintf(stdout,"ASTREE_VETCALL {%s}",node->symbol->text); break;
		case  ASTREE_PTRADDR: fprintf(stdout,"ASTREE_PTRADDR {%s}",node->symbol->text); break;
		case  ASTREE_PTRVALUE: fprintf(stdout,"ASTREE_PTRVALUE {%s}",node->symbol->text); break;
		case  ASTREE_LIT_FALSE: fprintf(stdout,"ASTREE_LIT_FALSE {%s}",node->symbol->text); break;
		case  ASTREE_LIT_TRUE: fprintf(stdout,"ASTREE_LIT_TRUE {%s}",node->symbol->text); break;
		case  ASTREE_LIT_CHAR: fprintf(stdout,"ASTREE_LIT_CHAR {%s}",node->symbol->text); break;
		case  ASTREE_VETORDEC: fprintf(stdout,"ASTREE_VETORDEC {%s}",node->symbol->text); break;
		case  ASTREE_FUNDEC: fprintf(stdout,"ASTREE_FUNDEC {%s}",node->symbol->text); break;
		case  ASTREE_PARAMSEQ: fprintf(stdout,"ASTREE_PARAMSEQ"); break;
		case  ASTREE_LOCALDECSEQ: fprintf(stdout,"ASTREE_LOCALDECSEQ"); break;
		case  ASTREE_KWWORD: fprintf(stdout,"ASTREE_KWWORD"); break;
		case  ASTREE_KWBOOL: fprintf(stdout,"ASTREE_KWBOOL"); break;
		case  ASTREE_KWBYTE: fprintf(stdout,"ASTREE_KWBYTE"); break;
		case  ASTREE_PROGRAM: fprintf(stdout,"ASTREE_PROGRAM"); break;
		case  ASTREE_LIT_STRING: fprintf(stdout,"ASTREE_LIT_STRING {%s}",node->symbol->text); break;
		case  ASTREE_GLOBALSEQ: fprintf(stdout,"ASTREE_GLOBALSEQ"); break;
		case  ASTREE_INPUT: fprintf(stdout,"ASTREE_INPUT {%s}",node->symbol->text); break;
		case  ASTREE_OUTPUT: fprintf(stdout,"ASTREE_OUTPUT"); break;
		case  ASTREE_RETURN: fprintf(stdout,"ASTREE_RETURN"); break;
		case  ASTREE_PTR_ASS: fprintf(stdout,"ASTREE_PTR_ASS {%s}",node->symbol->text); break;
		case  ASTREE_DEREF_ASS: fprintf(stdout,"ASTREE_DEREF_ASS {%s}",node->symbol->text); break;
		case  ASTREE_VET_ASS: fprintf(stdout,"ASTREE_VET_ASS {%s}",node->symbol->text); break;
		case  ASTREE_EXPRESSION: fprintf(stdout,"ASTREE_EXPRESSION"); break;
		case  ASTREE_OUTPUTSEQ: fprintf(stdout,"ASTREE_OUTPUTSEQ"); break;
		case  ASTREE_IF: fprintf(stdout,"ASTREE_IF"); break;
		case  ASTREE_IF_ELSE: fprintf(stdout,"ASTREE_IF_ELSE"); break;
		case  ASTREE_LOOP: fprintf(stdout,"ASTREE_LOOP"); break;
		case  ASTREE_BLOCK: fprintf(stdout,"ASTREE_BLOCK"); break;
		case  ASTREE_PARAM: fprintf(stdout,"ASTREE_PARAM {%s}",node->symbol->text); break;
		case  ASTREE_PTRPARAM: fprintf(stdout,"ASTREE_PTRPARAM {%s}",node->symbol->text); break;
		case  ASTREE_LE: fprintf(stdout,"ASTREE_LE"); break;
		case  ASTREE_GE: fprintf(stdout,"ASTREE_GE"); break;
		case  ASTREE_EQ: fprintf(stdout,"ASTREE_EQ"); break;
		case  ASTREE_NE: fprintf(stdout,"ASTREE_NE"); break;
		case  ASTREE_AND: fprintf(stdout,"ASTREE_AND"); break;
		case  ASTREE_OR: fprintf(stdout,"ASTREE_OR"); break;
		case  ASTREE_L: fprintf(stdout,"ASTREE_L"); break;
		case  ASTREE_G: fprintf(stdout,"ASTREE_G"); break;
		case  ASTREE_NOT: fprintf(stdout,"ASTREE_NOT"); break;
		case  ASTREE_COMMANDSEQ: fprintf(stdout,"ASTREE_COMMANDSEQ"); break;
		case  ASTREE_PTRDEC: fprintf(stdout,"ASTREE_PTRDEC {%s}",node->symbol->text); break;
		default: fprintf(stdout, "ASTREE UNKNOWN"); break;
	}
	
	fprintf(stdout,")\n");
	return;
}

void astreePrintTree(ASTREE * node, int level) {
	int i =0;
		
	if(!node) return;
	for(i=0;i< level; i++)
		fprintf(stdout,"    ");
		
	astreePrintSingle(node);

	for(i=0;i<MAX_SONS;i++)
		if(node->son[i])
			astreePrintTree(node->son[i],level+1);

}

void getDecType(char * dstbuffer, int code){
	if (!dstbuffer) return;
	
	switch (code){

		case 	ASTREE_KWWORD: strcpy(dstbuffer,"word ");
			break;

		case 	ASTREE_KWBOOL: strcpy(dstbuffer,"bool ");
			break;

		case 	ASTREE_KWBYTE: strcpy(dstbuffer,"byte ");
			break;
	}

}

void astreeCreateCode(ASTREE * node, int level){

	if((!node) || (!outputFile)) return ;
	char buffer[200]; //temporary buffer for chars
	int i;
	
	for(i=0;i< level; i++)
		fprintf(outputFile,"  ");
	
	switch( node->type){
		case  ASTREE_SYMBOL: 
			fprintf(outputFile,"%s",node->symbol->text); 
			break;

		case  ASTREE_LIT_INT: 
			fprintf(outputFile,"%s",node->symbol->text); 
			break;

		case  ASTREE_ADD:
			astreeCreateCode(node->son[0],0); 
			fprintf(outputFile," + "); 
			astreeCreateCode(node->son[1],0); 
			break;

		case  ASTREE_MIN: 
			astreeCreateCode(node->son[0],0); 
			fprintf(outputFile," - "); 
			astreeCreateCode(node->son[1],0); 
			break;

		case  ASTREE_MUL: 
			astreeCreateCode(node->son[0],0); 
			fprintf(outputFile," * "); 
			astreeCreateCode(node->son[1],0); 
			break;

		case  ASTREE_DIV: 
			astreeCreateCode(node->son[0],0); 
			fprintf(outputFile," / "); 
			astreeCreateCode(node->son[1],0); 
			break;

		case  ASTREE_SCALAR_ASS: 
			fprintf(outputFile,"%s = ",node->symbol->text); 
			astreeCreateCode(node->son[0],0);
			break;

		case  ASTREE_LIT_SEQ: 
			astreeCreateCode(node->son[0],0);
			fprintf(outputFile," ");
			astreeCreateCode(node->son[1],0);
			break;

		case  ASTREE_VARDEC:
			getDecType(buffer,node->son[0]->type);
			fprintf(outputFile,"%s %s:",buffer,node->symbol->text); 
			astreeCreateCode(node->son[1],0);
			fprintf(outputFile,";\n");
			break;

		case  ASTREE_ARGSEQ:			
			//rever esses ifs
			if(node->son[0]){ //se ha mais elem na seq
				astreeCreateCode(node->son[0],0);
				fprintf(outputFile,",");
				astreeCreateCode(node->son[1],0);			
			}else 	//se ha somente 1 elem na seq
				if(node->son[1]){
				astreeCreateCode(node->son[0],0);
			}		
			break;

		case  ASTREE_FUNCALL: 
			fprintf(outputFile,"%s(",node->symbol->text); 
			astreeCreateCode(node->son[0],0);
			fprintf(outputFile,")");		
			break;

		case  ASTREE_VETCALL: 
			fprintf(outputFile,"%s[",node->symbol->text);
			astreeCreateCode(node->son[0],0);
			fprintf(outputFile,"]");
			break;
		
		case  ASTREE_PTRADDR: 
			fprintf(outputFile,"& %s",node->symbol->text); 
			break;
	
		case  ASTREE_PTRVALUE: 
			fprintf(outputFile,"* %s",node->symbol->text); 
			break;
	
		case  ASTREE_LIT_FALSE: 
			fprintf(outputFile,"%s",node->symbol->text); 
			break;

		case  ASTREE_LIT_TRUE: 
			fprintf(outputFile,"%s",node->symbol->text); 
			break;

		case  ASTREE_LIT_CHAR: 
			fprintf(outputFile,"%s",node->symbol->text); 
			break;

		case  ASTREE_VETORDEC: 
			getDecType(buffer,node->son[0]->type);
			if(node->son[2]){
				fprintf(outputFile,"%s %s[%s]:",buffer,node->symbol->text,node->son[1]->symbol->text); 
				astreeCreateCode(node->son[2],0);
				fprintf(outputFile,";");
			}else fprintf(outputFile,"%s %s [%s];",buffer,node->symbol->text,node->son[1]->symbol->text);			 
			fprintf(outputFile,"\n");
			break;

		case  ASTREE_FUNDEC: 
			getDecType(buffer,node->son[0]->type);
			fprintf(outputFile,"%s %s ( ",buffer, node->symbol->text);
			astreeCreateCode(node->son[1],0); //paramseq
			fprintf(outputFile, ")\n");			
			astreeCreateCode(node->son[2],0); //localdecseq
			astreeCreateCode(node->son[3],0); //blococomandos
			fprintf(outputFile,"\n");	
			break;

		case  ASTREE_PARAMSEQ:
			if(node->son[0]) { //se ha mais elementos na seq							
				astreeCreateCode(node->son[0],0);
				fprintf(outputFile,",");
				astreeCreateCode(node->son[1],0);
			}else if (node->son[1]){				
				astreeCreateCode(node->son[1],0);				
			}
			break;

		case  ASTREE_LOCALDECSEQ: 
			astreeCreateCode(node->son[0],level);
			astreeCreateCode(node->son[1],level);			
			break;

		case  ASTREE_KWWORD: 
			fprintf(outputFile,"word"); 
			break;

		case  ASTREE_KWBOOL: 
			fprintf(outputFile,"bool"); 
			break;

		case  ASTREE_KWBYTE: 
			fprintf(outputFile,"byte");
			break;
	
		case  ASTREE_PROGRAM:
			astreeCreateCode(node->son[0],0);
			fprintf(outputFile,"\n");
			break;
	
		case  ASTREE_LIT_STRING: 
			fprintf(outputFile,"%s",node->symbol->text); 
			break;

		case  ASTREE_GLOBALSEQ: 
			astreeCreateCode(node->son[0],0);
			astreeCreateCode(node->son[1],0);		
			break;
	

		case  ASTREE_INPUT: 
			fprintf(outputFile,"input %s",node->symbol->text);
			break;

		case  ASTREE_OUTPUT: 
			fprintf(outputFile,"output ");
			astreeCreateCode(node->son[0],0);
			break;

		case  ASTREE_RETURN: 
			fprintf(outputFile,"return");
			astreeCreateCode(node->son[0],level+1);
			break;

		case  ASTREE_PTR_ASS: 
			fprintf(outputFile,"&%s =  ",node->symbol->text);
			astreeCreateCode(node->son[0],level+1);			
			break;

		case  ASTREE_DEREF_ASS:		
			fprintf(outputFile,"*%s =  ",node->symbol->text);
			astreeCreateCode(node->son[0],level+1);
			break;
			
		case  ASTREE_VET_ASS:			
			fprintf(outputFile,"%s[",node->symbol->text);
			astreeCreateCode(node->son[0],0);
			fprintf(outputFile,"] = ");
			astreeCreateCode(node->son[1],0);	
			break;

		case  ASTREE_EXPRESSION: 
			fprintf(outputFile,"("); 
			astreeCreateCode(node->son[0],0);
			fprintf(outputFile,")");
			break;

		case  ASTREE_OUTPUTSEQ: 
			if(node->son[0]) { //se ha mais elementos na seq							
				astreeCreateCode(node->son[0],0);
				fprintf(outputFile,",");
				astreeCreateCode(node->son[1],0);
			}else if (node->son[1]){				
				astreeCreateCode(node->son[1],0);				
			}			
			break;

		case  ASTREE_IF: 
			fprintf(outputFile,"if ( ");
			astreeCreateCode(node->son[0],0);
			fprintf(outputFile," ) then ");
			astreeCreateCode(node->son[1],0);
			break;

		case  ASTREE_IF_ELSE:
			fprintf(outputFile,"if ( ");
			astreeCreateCode(node->son[0],0);
			fprintf(outputFile," ) then ");
			astreeCreateCode(node->son[1],0);
			fprintf(outputFile,"\nelse ");
			astreeCreateCode(node->son[2],0);
			break;

		case  ASTREE_LOOP: 
			fprintf(outputFile,"loop ( "); 
			astreeCreateCode(node->son[0],level);
			fprintf(outputFile," ) ");
			astreeCreateCode(node->son[1],level);
			break;
	
		case  ASTREE_BLOCK: 
			fprintf(outputFile,"{\n");
			astreeCreateCode(node->son[0],0);
			fprintf(outputFile,"}");
			break;

		case  ASTREE_PARAM:
			getDecType(buffer,node->son[0]->type);
			fprintf(outputFile,"%s %s",buffer,node->symbol->text); //tipo eh um filho do no
			break;

		case  ASTREE_PTRPARAM:
			getDecType(buffer,node->son[0]->type);
			fprintf(outputFile,"%s $%s",buffer,node->symbol->text); //tipo eh um filho do no
			break;

		case  ASTREE_LE:
			astreeCreateCode(node->son[0],level); 
			fprintf(outputFile," <= ");
			astreeCreateCode(node->son[1],level);
			break;

		case  ASTREE_GE:
 			astreeCreateCode(node->son[0],level); 
			fprintf(outputFile," >= ");
			astreeCreateCode(node->son[1],level);
			break;

		case  ASTREE_EQ:
			astreeCreateCode(node->son[0],level); 
			fprintf(outputFile," == ");
			astreeCreateCode(node->son[1],level);
			break;

		case  ASTREE_NE: 
			astreeCreateCode(node->son[0],level); 
			fprintf(outputFile," != ");
			astreeCreateCode(node->son[1],level);	
			break;

		case  ASTREE_AND:
 			astreeCreateCode(node->son[0],level); 
			fprintf(outputFile," && ");
			astreeCreateCode(node->son[1],level);
			break;	

		case  ASTREE_OR:
			astreeCreateCode(node->son[0],level); 
			fprintf(outputFile," || ");
			astreeCreateCode(node->son[1],level);
			break;	
 
		case  ASTREE_L:
			astreeCreateCode(node->son[0],level); 
			fprintf(outputFile," < ");
			astreeCreateCode(node->son[1],level);
			break;
 
		case  ASTREE_G:
			astreeCreateCode(node->son[0],level); 
			fprintf(outputFile," > ");
			astreeCreateCode(node->son[1],level);
			break;
			 
		case  ASTREE_NOT:			
			fprintf(outputFile,"!");
			astreeCreateCode(node->son[0],level); 
			break; 

		case  ASTREE_COMMANDSEQ:
			//rever ifs				
			if(node->son[0]) { //se ha mais elementos na seq							
				astreeCreateCode(node->son[0],0);
				astreeCreateCode(node->son[1],0);
				fprintf(outputFile,";\n");
			}else if (node->son[1]){				
				astreeCreateCode(node->son[1],0);								
				fprintf(outputFile,";\n");			
			}			
			break;

		case  ASTREE_PTRDEC: 			
			getDecType(buffer,node->son[0]->type);
			fprintf(outputFile,"%s $%s:",buffer,node->symbol->text); 
			astreeCreateCode(node->son[1],level+1);
			fprintf(outputFile,";\n");
			break;

		default: fprintf(outputFile, "**ERROR"); break;
		}		
	return;
}

/*
	Encontra um nodo dentre aqueles que possuem alguma referencia para a tabela de simbolos,
	como por exemplo declaracoes, atribuicoes, alguns comandos, etc.
	Type se refere ao tipo de nodo a ser encontrado (ASTREE_FUNDEC, etc..)
	

*/
ASTREE * nodeFind(ASTREE * tree, int type, char * symboltext){

	int i;
	ASTREE * resultSon;
	if(!tree) return 0;
	if(!symboltext) return 0;

	if(tree->symbol) 
		if ((tree->type==type) && (!strcmp(tree->symbol->text,symboltext))){
			return tree;
		}
	for(i=0;i<MAX_SONS;i++){
		resultSon=nodeFind(tree->son[i],type,symboltext);
		if(resultSon) return resultSon;
	}
	return 0;
}

