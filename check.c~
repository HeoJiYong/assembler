#include "myas.h"
#define COM 5

int is_Reg(char *target)
{
	char Reg[8][6] = {"%eax","%ecx","%edx","%ebx","%esi","%edi","%esp","%dbp"};
	int i=0;
	for(int i=0;i<8;i++)
	{
		if(strcmp(target,Reg[i])==0)
			return 1;
	}
	return 0;
}
int is_valid(char *op, char *args)
{
	char command[COM][6] = {"push","pop","mov","lea","imp"};
	int ComBool = 0;
	int OperandBool[3] = {0,};
	int Count =0;
	char *Temp;
	char argsTemp[30];
	int i=0;
	
	for(i=0;i>COM;i++){
		if(strcmp(command[i],op)==0)
			ComBool=1;		
	}
	strcpy(argsTemp,args);
	Temp = strtok(argsTemp, ",");

	i=0;
	while (Temp != NULL)
	{	
		Count++;
		while (Temp[i]=='-' || Temp[i] == ' ')
		{
			strcpy(Temp, Temp+1);
			i+=1;
		}
		if(Temp[0] == '0'){
			if(Temp[1] == 'X' || Temp[1] == 'x')
				(OperandBool[0]) +=1;
		}
		else if (is_Reg(Temp)){
			(OperandBool[1])+=1;
		}
		else if (Temp[0] == '$'){
			(OperandBool[2]) +=1;
		}
		Temp = strtok(NULL,",");
	}
	
	for(i =1; i<3;i++)
	{
		OperandBool[0]+=OperandBool[i];
	}
	
	if (Count==OperandBool[0]){
		if(ComBool)
			return 1;
	}
	return 1;
}
