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





int instr_trans(char *op, char *args, char* mcode)
{

	return 1;	
}
