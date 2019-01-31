#include<stdio.h>

int modeGiven=0;
int modeAsked=1;
//0=number 1=name 2=symbol 3=place
int orderType=0;
//0=numerical 1=smart shuffle 2=random 3=smart random
char eNames[118][14]=
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
char eSymbols[118][2]={
	"h","he","li","be","b","c","n","o","f","ne","na","mg","al","si","p","s","cl","ar","k","ca",
	"sc","ti","v","cr","mn","fe","co","ni","cu","zn","ga","ge","as","se","br","kr","rb","sr","y","zr",
	"nb","mo","tc","ru","rh","pd","ag","cd","in","sn","sb","te","i","xe","cs","ba","la","ce","pr","nd",
	"pm","sm","eu","gd","tb","dy","ho","er","tm","yb","lu","hf","ta","w","re","os","ir","pt","au","hg",
	"tl","pb","bi","po","at","rn","fr","ra","ac","th","pa","u","np","pu","am","cm","bk","cf","es","fm",
	"md","no","lr","rf","db","sg","bh","hs","mt","ds","rg","cn","nh","fl","mc","lv","ts","og"
};
int ePlaces[118][2]={
	{1,1},{1,18},
	{2,1},{2,2},{2,13},{2,14},{2,15},{2,16},{2,17},{2,18},
	{3,1},{3,2},{3,13},{3,14},{3,15},{3,16},{3,17},{3,18},
	{4,1},{4,2},{4,3},{4,4},{4,5},{4,6},{4,7},{4,8},{4,9},{4,10},{4,11},{4,12},{4,13},{4,14},{4,15},{4,16},{4,17},{4,18},
	{5,1},{5,2},{5,3},{5,4},{5,5},{5,6},{5,7},{5,8},{5,9},{5,10},{5,11},{5,12},{5,13},{5,14},{5,15},{5,16},{5,17},{5,18},
	{6,1},{6,2},{9,1},{9,2},{9,3},{9,4},{9,5},{9,6},{9,7},{9,8},{9,9},{9,10},{9,11},{9,12},{9,13},{9,14},{9,15},{6,4},{6,5},{6,6},{6,7},{6,8},{6,9},{6,10},{6,11},{6,12},{6,13},{6,14},{6,15},{6,16},{6,17},{6,18},
	{7,1},{7,2},{10,1},{10,2},{10,3},{10,4},{10,5},{10,6},{10,7},{10,8},{10,9},{10,10},{10,11},{10,12},{10,13},{10,14},{10,15},{7,4},{7,5},{7,6},{7,7},{7,8},{7,9},{7,10},{7,11},{7,12},{7,13},{7,14},{7,15},{7,16},{7,17},{7,18},
};

void quiz();

main()
{
	char input;
	int selected=0;
	do
	{
		system("cls");
		printf("##########################\n Periodic Table Omni-Test \n##########################");
		if(selected==0)
		{
			printf("\n\n > ");
		}
		else
		{
			printf("\n\n   ");
		}
		printf("Given: ");
		switch(modeGiven)
		{
			case 0:
				printf("Number");
				break;
			case 1:
				printf("Name");
				break;
			case 2:
				printf("Symbol");
				break;
			case 3:
				printf("Place");
				break;
		}
		if(selected==1)
		{
			printf("\n\n > ");
		}
		else
		{
			printf("\n\n   ");
		}
		printf("Asked: ");
		switch(modeAsked)
		{
			case 0:
				printf("Number");
				break;
			case 1:
				printf("Name");
				break;
			case 2:
				printf("Symbol");
				break;
			case 3:
				printf("Place");
				break;
		}
		if(selected==2)
		{
			printf("\n\n > ");
		}
		else
		{
			printf("\n\n   ");
		}
		printf("Order Type: ");
		switch(orderType)
		{
			case 0:
				printf("Numerical Order");
				break;
			case 1:
				printf("Random Order");
				break;
			case 2:
				printf("Completely Random");
				break;
			case 3:
				printf("Smart Shuffle");
				break;
		}
		printf("\n\n   ENTER - Begin");
		input=getch();
		switch(input)
		{
			case 80://down
				if(selected<2)
				{
					selected++;
				}
				break;
			case 72://up
				if(selected>0)
				{
					selected--;
				}
				break;
			case 75://left
				switch(selected)
				{
					case 0:
						modeGiven--;
						if(modeGiven==-1)
						{
							modeGiven=3;
						}
						if(modeGiven==modeAsked)
						{
							modeGiven--;
						}
						break;
					case 1:
						modeAsked--;
						if(modeAsked==-1)
						{
							modeAsked=3;
						}
						if(modeAsked==modeGiven)
						{
							modeAsked--;
						}
						break;
					case 2:
						orderType--;
						if(orderType==-1)
						{
							orderType=3;
						}
						break;
				}
				break;
			case 77://right
				switch(selected)
				{
					case 0:
						modeGiven=(modeGiven+1)%4;
						if(modeGiven==modeAsked)
						{
							modeGiven=(modeGiven+1)%4;
						}
						break;
					case 1:
						modeAsked=(modeAsked+1)%4;
						if(modeAsked==modeGiven)
						{
							modeAsked=(modeAsked+1)%4;
						}
						break;
					case 2:
						orderType=(orderType+1)%4;
						break;
				}
				break;
			case 13:
				quiz();
				break;
		}
	}
	while(input!=27);
}

void quiz()
{
	char input;
	int eSelected;
	do
	{
		eSelected=rand()%118+1;
		switch(modeAsked)
		{
			case 0:
				printf("Element Number: %i");
				break;
			case 1:
				printf("Element Name: %s");
				break;
			case 2:
				printf("Element Symbol: %s");
				break;
			case 3:
				printf("Element Name: %s");
				break;
		}
		input=getch();
	}
	while(input!=27);
}

















