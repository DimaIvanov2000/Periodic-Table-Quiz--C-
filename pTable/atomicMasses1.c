#include<stdio.h>

int cur;
int numMasses=31;
char masses[31][8]={
    "1.0079","4.0026","6.941","9.0122","10.811","12.011","14.0067","15.9994","18.9984","20.179",
    "22.9898","24.305","26.9815","28.0855","30.9738","32.066","35.453","39.948","39.0983","40.078",
    "44.9559","47.90","50.9415","51.9961","54.938","55.847","58.9332","58.71","63.546","65.39",
    "69.723"
};
char names[118][14]=
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

int main(void)
{
    int i,j;
    char input;
    char sInput[30];

    srand((unsigned int) time(NULL));

    do
    {
        system("cls");
        printf("Select a mode:\n\n  O - In Order\n  R - In Random Order");
        input=getch();
        switch(input)
        {
            case 'o':case 'O':
                cur=0;
                for(i=0;i<numMasses;i++)
                {
                    system("cls");
                    printf("What is the atomic mass of %s?\n\n",names[i]);

                    scanf("%s",&sInput);

                    if(strcmp(sInput,masses[i])==0)
                    {
                        printf("\n\nCorrect!");
                        cur++;
                    }
                    else
                    {
                        printf("\n\nNo, the answer was %s",masses[i]);
                    }
                    getch();
                }
                system("cls");
                printf("You got %i / %i, nice.\n\n",cur,numMasses);
                getch();
                break;
            case 'r':case 'R':
                do
                {
                    i=rand()%numMasses;
                    system("cls");
                    printf("What is the atomic mass of %s?\n\n",names[i]);

                    scanf("%s",&sInput);

                    if(strcmp(sInput,masses[i])==0)
                    {
                        printf("\n\nCorrect!");
                    }
                    else
                    {
                        printf("\n\nNo, the answer was %s",masses[i]);
                    }
                    input=getch();
                }
                while(input!=27);
                input=0;
                break;
        }
    }
    while(input!=27);

    return 0;
}
