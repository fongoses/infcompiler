            case TAC_LE:
                if(tac->target->decType == DATATYPE_WORD)
                    fprintf(fout,
                    "\tmovl\t$%s, %%edx\n"
                    "\tmovl\t$%s, %%eax\n"
                    "\tcmpl\t%%eax, %%edx\n"
                    "\tjg\t%s\n",tac->op1->text,tac->op2->text,tac->next->target->text);
                if((tac->target->decType == DATATYPE_BYTE) || (tac->target->decType == DATATYPE_BOOL))
                    fprintf(fout,
                    "\tmovzbl\t$%s, %%edx\n"
                    "\tmovzbl\t$%s, %%eax\n"
                    "\tcmpb\t%%al, %%dl\n"
                    "\tjg\t%s\n",tac->op1->text,tac->op2->text,tac->next->target->text);
                break;

            case TAC_GE:
                if(tac->target->decType == DATATYPE_WORD)
                    fprintf(fout,
                    "\tmovl\t$%s, %%edx\n"
                    "\tmovl\t$%s, %%eax\n"
                    "\tcmpl\t%%eax, %%edx\n"
                    "\tjl\t%s\n",tac->op1->text,tac->op2->text,tac->next->target->text);
                if((tac->target->decType == DATATYPE_BYTE) || (tac->target->decType == DATATYPE_BOOL))
                    fprintf(fout,
                    "\tmovzbl\t$%s, %%edx\n"
                    "\tmovzbl\t$%s, %%eax\n"
                    "\tcmpb\t%%al, %%dl\n"
                    "\tjl\t%s\n",tac->op1->text,tac->op2->text,tac->next->target->text);
                break;

            case TAC_EQ:
                if(tac->target->decType == DATATYPE_WORD)
                    fprintf(fout,
                    "\tmovl\t$%s, %%edx\n"
                    "\tmovl\t$%s, %%eax\n"
                    "\tcmpl\t%%eax, %%edx\n"
                    "\tjne\t%s\n",tac->op1->text,tac->op2->text,tac->next->target->text);
                if((tac->target->decType == DATATYPE_BYTE) || (tac->target->decType == DATATYPE_BOOL))
                    fprintf(fout,
                    "\tmovzbl\t$%s, %%edx\n"
                    "\tmovzbl\t$%s, %%eax\n"
                    "\tcmpb\t%%al, %%dl\n"
                    "\tjne\t%s\n",tac->op1->text,tac->op2->text,tac->next->target->text);
                break;

            case TAC_NE:
                if(tac->target->decType == DATATYPE_WORD)
                    fprintf(fout,
                    "\tmovl\t$%s, %%edx\n"
                    "\tmovl\t$%s, %%eax\n"
                    "\tcmpl\t%%eax, %%edx\n"
                    "\tje\t%s\n",tac->op1->text,tac->op2->text,tac->next->target->text);
                if((tac->target->decType == DATATYPE_BYTE) || (tac->target->decType == DATATYPE_BOOL))
                    fprintf(fout,
                    "\tmovzbl\t$%s, %%edx\n"
                    "\tmovzbl\t$%s, %%eax\n"
                    "\tcmpb\t%%al, %%dl\n"
                    "\tje\t%s\n",tac->op1->text,tac->op2->text,tac->next->target->text);
                break;

             case TAC_L:
                if(tac->target->decType == DATATYPE_WORD)
                    fprintf(fout,
                    "\tmovl\t$%s, %%edx\n"
                    "\tmovl\t$%s, %%eax\n"
                    "\tcmpl\t%%eax, %%edx\n"
                    "\tjge\t%s\n",tac->op1->text,tac->op2->text,tac->next->target->text);
                if((tac->target->decType == DATATYPE_BYTE) || (tac->target->decType == DATATYPE_BOOL))
                    fprintf(fout,
                    "\tmovzbl\t$%s, %%edx\n"
                    "\tmovzbl\t$%s, %%eax\n"
                    "\tcmpb\t%%al, %%dl\n"
                    "\tjge\t%s\n",tac->op1->text,tac->op2->text,tac->next->target->text);
                break;

            case TAC_G:
                if(tac->target->decType == DATATYPE_WORD)
                    fprintf(fout,
                    "\tmovl\t$%s, %%edx\n"
                    "\tmovl\t$%s, %%eax\n"
                    "\tcmpl\t%%eax, %%edx\n"
                    "\tjle\t%s\n",tac->op1->text,tac->op2->text,tac->next->target->text);
                if((tac->target->decType == DATATYPE_BYTE) || (tac->target->decType == DATATYPE_BOOL))
                    fprintf(fout,
                    "\tmovzbl\t$%s, %%edx\n"
                    "\tmovzbl\t$%s, %%eax\n"
                    "\tcmpb\t%%al, %%dl\n"
                    "\tjle\t%s\n",tac->op1->text,tac->op2->text,tac->next->target->text);
                break;

            case TAC_JMP:
                fprintf(fout,
                "\tjmp\t%s\n",tac->target->text);
                break;
