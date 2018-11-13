#include "myas.h"

int set_mcode(char *pmcode, char log[10][10], int index)
{
	char Reg[8][6] = {"%eax","%ecx","%edx","%ebx","%esp","%ebp","%esi","%edi",};
	int i;
	for (i=0;i<8;i++)
	{
		if(strcmp(log[index],Reg[i])==0)
			return i;
	}
	return 0;
}

int Is_Reg(char *target)
{
	char Reg[8][6] = {"%eax","%ecx","%edx","%ebx","%esp","%ebp","%esi","%edi",};
	int i=0;
	for (i=0;i<8;i++)
	{
		if (strcmp(target,Reg[i])==0){
			if(i==0){
				return 4;
			}
			else
			return 1;
		}
	}
	return 0;
}
int Is_Imm(char *target)
{
	if(target[0] == '$')
		return 1;
	else
		return 0;
}
int Is_Eax(char *target)
{
	if(strcmp(target,"%eax")==0)
		return 1;
	else
		return 0;
}
int CheckIndex(char *t)
{
	if(Is_Reg(t)){
		return 1;
	}
	else if(Is_Mem(t)){
		return 2;
	}
	else if(Is_Imm(t)){
		return 3;
	}
	return 0;
}


int instr_trans(char *op, char *args, char* mcode)
{
	char Index[10] = {0,};
	char CopyString[30];
	char *TokkenString;
	char Tokken_Log[10][10];
	int i;
	int count =0;
	
	if(!is_valid(op,args)){
		printf("Error: %s %s is not Valid\n",op,args);
		return 0;
	}
	
	strcpy(CopyString,args);
	TokkenString = strtok(CopyString,",");
	
	while(TokkenString !=NULL)
	{
		while(TokkenString[i] == '-' || TokkenString[i] == ' ')
		{
			strcpy(TokkenString,TokkenString+1);
			i+=1;
		}
		Index[count] = CheckIndex(TokkenString);
		strcpy(Tokken_Log[count],TokkenString);
		count +=1;
		TokkenString = strtok(NULL,",");
	}
	
	for(i=0;Index[i+1] !=0;i++)
	{
		switch(Index[i])
		{
			case 1:
				switch(Index[i+1])
				{
					case 1:
					strcpy(mcode,"89");
						break;
					case 2:
					case 3:
					default:
						strcpy(mcode,"error\n");
						break;
				}
				break;
				
			case 2:
				switch(Index[i+1])
				{
					case 1:
					strcpy(mcode,"8b");
					break;
					case 2:
					case 3:
					default:
						strcpy(mcode,"error\n");
						break;	
					case 4:
						strcpy(mcode,"a1");
						break;
				}
				break;
				
			case 3:
				switch(Index[i+1])
				{
					case 1:
						switch(set_mcode(mcode, Tokken_Log,i+1))
						{
							case 0: strcpy(mcode,"b8");
								break;
							case 1: strcpy(mcode,"b9");
								break;
							case 2: strcpy(mcode,"ba");
								break;
							case 3: strcpy(mcode,"bb");
								break;
							case 4: strcpy(mcode,"bc");
								break;
							case 5: strcpy(mcode,"bd");
								break;
							case 6: strcpy(mcode,"be");
								break;
							case 7: strcpy(mcode,"bf");
								break;
							default:
								break;
						}
						break;
					case 2:
					case 3:
					default:
						strcpy(mcode,"error\n");
						break;
				}
				break;
				
			case 4:
				switch(Index[i+1])
				{
					case 2:
						strcpy(mcode,"89");
						break;
					default:
						strcpy(mcode,"error\n");
						break;
				}
				break;
				
			default:
				strcpy(mcode, "error\n");
				exit(1);
				break;
		}
	}
	return 1;	
}
