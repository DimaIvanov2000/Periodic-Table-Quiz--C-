//#include<stdio.h>
//
//int summate();
//
//char elements[118][14]=
//{
//	"hydrogen","helium","lithium","beryllium","boron","carbon","nitrogen","oxygen","fluorine","neon",
//	"sodium","magnesium","aluminium","silicon","phosphorus","sulfur","chlorine","argon","potassium","calcium",
//	"scandium","titanium","vanadium","chromium","manganese","iron","cobalt","nickel","copper","zinc",
//	"gallium","germanium","arsenic","selenium","bromine","krypton","rubidium","strontium","yttrium","zirconium",
//	"niobium","molybdenum","technetium","ruthenium","rhodium","palladium","silver","cadmium","indium","tin",
//	"antimony","tellurium","iodine","xenon","caesium","barium","lanthanum","cerium","praseodymium","neodymium",
//	"promethium","samarium","europium","gadolinium","terbium","dysprosium","holmium","erbium","thulium","ytterbium",
//	"lutetium","hafnium","tantalum","tungsten","rhenium","osmium","iridium","platinum","gold","mercury",
//	"thallium","lead","bismuth","polonium","astatine","radon","francium","radium","actinium","thorium",
//	"protactinium","uranium","neptunium","plutonium","americium","curium","berkelium","californium","einsteinium","fermium",
//	"mendelevium","nobelium","lawrencium","rutherfordium","dubnium","seaborgium","bohrium","hassium","meitnerium","darmstadtium",
//	"roentgenium","copernicium","nihonium","flerovium","moscovium","livermorium","tennessine","oganesson"
//};
//
//int misArray[118]={0};
//int mistakeCoeff=5;
//
//main()
//{
//	srand((unsigned int) time(NULL));
//	int i;
//	int j;
//	int prob;
//	int chosen;
//	char input;
//	char answer[20];
//	printf("=============================================\n   Periodic Table Ultimate Quiz Selection\n=============================================\n\n1. At. Number >> Name [P A L]");
//	do
//	{
//		input=getch();
//		switch(input)
//		{
//			case '1':
//				do
//				{
//					i=0;
//					prob=summate()*mistakeCoeff+118;
//					do
//					{
//						for(j=0;j<=misArray[i];j++)
//						{
//							if(rand()%prob==0)
//							{
//								system("cls");
//								chosen=i+1;
//								printf("What is the name of element %i ?\n\n",chosen);
//								scanf("%s",&answer);
//								if(strcmp(answer,elements[chosen-1])==0)
//								{
//									printf("\n\nCorrect!\n\nEsc. Back");
//									if(misArray[chosen-1]!=0)
//									{
//										misArray[chosen-1]-=mistakeCoeff;
//									}
//								}
//								else
//								{
//									printf("\n\nIncorrect...\n\nEsc. Back");
//									misArray[chosen-1]+=mistakeCoeff;
//								}
//								i=119;
//								break;
//							}
//							else
//							{
//								prob--;
//							}
//						}
//						i++;
//					}
//					while(i<118);
//				}
//				while(getch()!=27);
//				break;
//		}
//	}
//	while(getch()!=27);
//}
//
//int summate()
//{
//	int sum=0;
//	int i;
//	for(i=0;i<118;i++)
//	{
//		sum+=misArray[i];
//	}
//	return sum;
//}

#include<stdio.h>

void numName();
void nameNum();
void symName();
void nameSym();

char elements[118][14]=
{
	"hydrogen","helium","lithium","beryllium","boron","carbon","nitrogen","oxygen","fluorine","neon",
	"sodium","magnesium","aluminium","silicon","phosphorus","sulfur","chlorine","argon","potassium","calcium",
	"scandium","titanium","vanadium","chromium","manganese","iron","cobalt","nickel","copper","zinc",
	"gallium","germanium","arsenic","selenium","bromine","krypton","rubidium","strontium","yttrium","zirconium",
	"niobium","molybdenum","technetium","ruthenium","rhodium","palladium","silver","cadmium","indium","tin",
	"antimony","tellurium","iodine","xenon","caesium","barium","lanthanum","cerium","praseodymium","neodymium",
	"promethium","samarium","europium","gadolinium","terbium","dysprosium","holmium","erbium","thulium","ytterbium",
	"lutetium","hafnium","tantalum","tungsten","rhenium","osmium","iridium","platinum","gold","mercury",
	"thallium","lead","bismuth","polonium","astatine","radon","francium","radium","actinium","thorium",
	"protactinium","uranium","neptunium","plutonium","americium","curium","berkelium","californium","einsteinium","fermium",
	"mendelevium","nobelium","lawrencium","rutherfordium","dubnium","seaborgium","bohrium","hassium","meitnerium","darmstadtium",
	"roentgenium","copernicium","nihonium","flerovium","moscovium","livermorium","tennessine","oganesson"
};

int aProbs=0;
int misArray[118]={0};
int misCoef=3;

main()
{
	srand((unsigned int) time(NULL));
	char input;
	int i;
	do
	{
		system("cls");
		printf("=============================================\n   Periodic Table Ultimate Quiz Selection\n=============================================\n\n1. Number >> Name\n2. Name >> Number [NOT WORKING]\n3. Symbol >> Name[NOT WORKING]\n4. Name >> Symbol[NOT WORKING]\n\nT: Toggle Adjusted Probabilities:");
		if(aProbs==0)
		{
			printf("[OFF]");
		}
		else
		{
			printf("[ON]");
		}
		printf("\n\nArrows. Adjust Mistake Probability Coefficient [ %i ]\n\n",misCoef);
		input=getch();
		for(i=0;i<118;i++)
		{
			misArray[i]=0;
		}
		switch(input)
		{
			case '1':
				numName();
				break;
			case '2':
				nameNum();
				break;
			case '3':
				symName();
				break;
			case '4':
				nameSym();
				break;
			case 't':
				aProbs=(aProbs+1)%2;
				break;
			case 72:
				misCoef++;
				break;
			case 80:
				if(misCoef!=0)
				{
					misCoef--;
				}
				break;
		}
	}
	while(input!=27);
}

void numName()
{
	int i,j;
	int chosen;
	char answer[20];
	int prob;
	do
	{
		prob=118;
		if(aProbs==1)
		{
			for(i=0;i<118;i++)
			{
				prob+=misArray[i]*misCoef;
			}
		}
		i=0;
		do
		{
			for(j=0;j<=misArray[i]*aProbs;j++)
			{
				if(rand()%prob==0)
				{
					chosen=i+1;
					system("cls");
					printf("What is the name of element # %i ?\n\n",chosen);
					scanf("%s",&answer);
					if(strcmp(answer,elements[chosen-1])==0)
					{
						printf("\n\nCorrect!\n");
						if(misArray[chosen-1]!=0)
						{
							misArray[chosen-1]-=misCoef;
						}
					}
					else
					{
						printf("\n\nIncorrect...\n\n O  %s\n X  %s",elements[chosen-1],answer);
						misArray[chosen-1]+=misCoef;
					}
					i=118;
					break;
				}
				else
				{
					prob--;
				}
			}
			i++;
		}
		while(i<118);
	}
	while(getch()!=27);
}

void nameNum()
{
	
}

void symName()
{
	
}

void nameSym()
{
	
}
