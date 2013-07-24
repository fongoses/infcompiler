            case TAC_MIN:
                if(tac->target->decType == DATATYPE_WORD)
                    fprintf(fout,
                    "\tmovl\t$%s, %%edx\n"
                    "\tmovl\t$%s, %%eax\n"
                    "\tmovl\t%%edx, %%ecx\n"
                    "\tsubl\t%%eax, %%ecx\n"
                    "\tmovl\t%%ecx, %%eax\n"
                    "\tmovl\t%%eax, %s\n",tac->op1->text,tac->op2->text,tac->target->text);
                if(tac->target->decType == DATATYPE_BYTE)
                    fprintf(fout,
                    "\tmovzbl\t$%s, %%eax\n"
                    "\tmovl\t%%eax, %%edx\n"
                    "\tmovzbl\t$%s, %%eax\n"
                    "\tmovl\t%%edx, %%ecx\n"
                    "\tsubl\t%%eax, %%ecx\n"
                    "\tmovl\t%%ecx, %%eax\n"
                    "\tmovb\t%%al, %s\n",tac->op1->text,tac->op2->text,tac->target->text);
                break;

            case TAC_MUL:
                if(tac->target->decType == DATATYPE_WORD)
                    fprintf(fout,
                    "\tmovl\t$%s, %%edx\n"
                    "\tmovl\t$%s, %%eax\n"
                    "\timull\t%%edx, %%eax\n"
                    "\tmovl\t%%eax, %s\n",tac->op1->text,tac->op2->text,tac->target->text);
                if(tac->target->decType == DATATYPE_BYTE)
                    fprintf(fout,
                    "\tmovzbl\t$%s, %%eax\n"
                    "\tmovzbl\t$%s, %%edx\n"
                    "\timull\t%%edx, %%eax\n"
                    "\tmovl\t%%al, %s\n",tac->op1->text,tac->op2->text,tac->target->text);
                break;

            case TAC_DIV:
                if(tac->target->decType == DATATYPE_WORD)
                    fprintf(fout,
                    "\tmovl\t$%s, %%eax\n"
                    "\tmovl\t$%s, %%edx\n"
                    "\tmovl\t%%edx, 44(%%esp)\n"
                    "\tmovl\t%%eax, %%edx\n"
                    "\tsarl\t$31, %%edx\n"
                    "\tidivl\t44(%%esp)\n"
                    "\tmovl\t%%eax, %s\n",tac->op1->text,tac->op2->text,tac->target->text);
                if(tac->target->decType == DATATYPE_BYTE)
                    fprintf(fout,
                    "\tmovzbl\t$%s, %%eax\n"
                    "\tmovsbl\t%%al, %%eax\n"
                    "\tmovzbl\t$%s, %%edx\n"
                    "\tmovsbl\t%%dl, %%edx\n"
                    "\tmovl\t%%edx, 44(%%esp)\n"
                    "\tmovl\t%%eax, %%edx\n"
                    "\tsarl\t$31, %%edx\n"
                    "\tidivl\t44(%%esp)\n"
                    "\tmovb\t%%al, %s\n",tac->op1->text,tac->op2->text,tac->target->text);
                break;
