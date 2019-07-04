#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream.h>
#include<fstream.h>

//HERE THE KEYBOARD ASCII VALUES ARE STORED
//TO BE USED BY PLAYER TO INPUT THE MOVEMENTS
#define keyup		72
#define keydown		80
#define keyleft		75
#define keyright	77
#define keyesc		27
#define enter           13
#define pause		112

int premove;
int premoveg;
int score;

//THE STRUCTURE IS USED TO STORE THE X & Y CO-ORDINATES OF A POINT
struct points
{
	int x,y;
};


// FUNCTION PRINTS THE PLAYING AREA
void map()
{
	setcolor(BLUE);
	line(35,35,465,35);
	line(465,35,465,465);
	line(465,465,35,465);
	line(35,465,35,35);

	line(65,65,235,65);
	line(235,65,235,235);
	line(235,235,65,235);
	line(65,235,65,65);

	line(265,65,435,65);
	line(435,65,435,235);
	line(435,235,265,235);
	line(265,235,265,65);

	line(265,265,435,265);
	line(435,265,435,435);
	line(435,435,265,435);
	line(265,435,265,265);

	line(65,265,235,265);
	line(235,265,235,435);
	line(235,435,65,435);
	line(65,435,65,265);
}

//FUNTION CHECKS IF THE PLAYER AND GHOST STAYS WITHIN THE BOUNDARIES OF THE ARENA
void check(int i,int j,int &a,int &b,int &c)
{    points hori[12],vert[12],tup,tdown,tleft,tright,plus,cor[4];

	hori[0].x=60;
	hori[0].y=50;
	hori[1].x=240;
	hori[1].y=50;
	hori[2].x=260;
	hori[2].y=50;
	hori[3].x=440;
	hori[3].y=50;
	hori[4].x=60;
	hori[4].y=250;
	hori[5].x=240;
	hori[5].y=250;
	hori[6].x=260;
	hori[6].y=250;
	hori[7].x=440;
	hori[7].y=250;
	hori[8].x=60;
	hori[8].y=450;
	hori[9].x=240;
	hori[9].y=450;
	hori[10].x=260;
	hori[10].y=450;
	hori[11].x=440;
	hori[11].y=450;

	vert[0].x=50;
	vert[0].y=60;
	vert[1].x=50;
	vert[1].y=240;
	vert[2].x=50;
	vert[2].y=260;
	vert[3].x=50;
	vert[3].y=440;
	vert[4].x=250;
	vert[4].y=60;
	vert[5].x=250;
	vert[5].y=240;
	vert[6].x=250;
	vert[6].y=260;
	vert[7].x=250;
	vert[7].y=440;
	vert[8].x=450;
	vert[8].y=60;
	vert[9].x=450;
	vert[9].y=240;
	vert[10].x=450;
	vert[10].y=260;
	vert[11].x=450;
	vert[11].y=440;

	tup.x=250;
	tup.y=450;
	tdown.x=250;
	tdown.y=50;
	tleft.x=450;
	tleft.y=250;
	tright.x=50;
	tright.y=250;

	cor[0].x=50;
	cor[0].y=50;
	cor[1].x=450;
	cor[1].y=50;
	cor[2].x=450;
	cor[2].y=450;
	cor[3].x=50;
	cor[3].y=450;

	plus.x=250;
	plus.y=250;


	//The IF statment to check if the user is moving in a
	// straight line

		for(int d=0;d<12;d++){
			if(i==hori[d].x && j==hori[d].y)
			{
				a=4;
				b=2;
				c=0;
			}
		}
		for(int e=0;e<12;e++){
			if(i==vert[e].x && j==vert[e].y)
			{
				a=1;
				b=3;
				c=0;
			}
		}

		//The IF statment to check if the user is at a corner

		if(i==cor[0].x && j==cor[0].y)
		{
			a=4;
			b=3;
			c=1;
		}
		if(i==cor[1].x && j==cor[1].y)
		{
			a=1;
			b=4;
			c=1;
		}
		if(i==cor[2].x && j==cor[2].y)
		{
			a=1;
			b=2;
			c=1;
		}
		if(i==cor[3].x && j==cor[3].y)
		{
			a=2;
			b=3;
			c=1;
		}

		//The IF condition to check if the user is on a T-Junction

		if(i==tup.x && j==tup.y)
		{
			a=2;
			b=0;
			c=1;
		}
		if(i==tdown.x && j==tdown.y)
		{
			a=4;
			b=0;
			c=1;
		}
		if(i==tleft.x && j==tleft.y)
		{
			a=1;
			b=0;
			c=1;
		}
		if(i==tright.x && j==tright.y)
		{
			a=3;
			b=0;
			c=1;
		}
		if(i==plus.x && j==plus.y)
		{
			a=0;
			b=0;
			c=0;
		}
}

//FUNTION TO MOVE THE GHOST AROUND THE ARENA
void movementg(int &i,int &j,int &move,int &a,int &b,int &c,int &speed)
{
	reset:	if(c==1)
				move=random(4)+1;
		if(move==a||move==b){
			goto reset;

		}
		else
			premoveg=move;

		if(move==1){

		i+=speed;

		}
		if(move==2){

		j+=speed;

		}
		if(move==3){

		i-=speed;

		}
		if(move==4){

		j-=speed;

		}

}

//FUNTION TO MOVE THE PLAYER IN THE ARENA
void movement(int &i,int &j,int move,int a,int b,int c,int speed)
{
		//To move the player
		if(move==a || move==b){
			/*The nested IF statment is to check if it is a
			corner*/

			if(c==1)
				move=0;
			else if(c==0)
				move=premove;


		}
		else{
			premove=move;

		}
		if(move==1){

		i+=speed;

		}
		if(move==2){

		j+=speed;

		}
		if(move==3){

		i-=speed;

		}
		if(move==4){

		j-=speed;

		}
}


//THE MAIN FUNTION TO RUN THE GAME
void game()
{
	void menu();
	void game_over();
	int ch,sc=0,p=50,i=50,j=50,speed=10,move=0,pa=2;
	int ig[3],jg[3],speedg=10,moveg[3];
	char temp[10];
	ig[0]=250;
	jg[0]=250;
	ig[1]=250;
	jg[1]=250;
	ig[2]=250;
	jg[2]=250;
	int a,b,c,premove,death=0;
	a=4;
	b=3;
	c=0;
	int ag[3],bg[3],cg[3],z,w;
	cg[0]=cg[1]=cg[2]=0;
	moveg[0]=2;
	moveg[1]=3;
	moveg[2]=1;
	score=0;
	while(death!=2){
			w=0;
			if((i==ig[w] || (i>ig[w]-30 && i<ig[w]+30)) && (j==jg[w] || (j>jg[w]-30 && j<jg[w]+30)))
			{
				death++;
				i=j=250;
				move=a=b=0;
				c=1;
				delay(1000);
				goto print;
			}
			w=1;
			if((i==ig[w] || (i>ig[w]-30 && i<ig[w]+30)) && (j==jg[w] || (j>jg[w]-30 && j<jg[w]+30)))
			{
				death++;
				i=j=250;
				move=a=b=0;
				c=1;
				delay(1000);
				goto print;
			}
			w=2;
			if((i==ig[w] || (i>ig[w]-30 && i<ig[w]+30)) && (j==jg[w] || (j>jg[w]-30 && j<jg[w]+30)))
			{
				death++;
				i=j=250;
				move=a=b=0;
				c=1;
				delay(1000);
				goto print;
			}






		if(kbhit()){
			ch=0;
			ch=getch();
			switch(ch){
				case keyup:
					move=4;
					break;
				case keydown:
					move=2;
					break;
				case keyleft:
					move=3;
					break;
				case keyright:
					move=1;
					break;
				case keyesc:
					closegraph();
					exit(1);
					break;

				case pause:
					pa++;

			}
		}
		if(pa%2==0){
			cleardevice();
			map();
			check(i,j,a,b,c);
			movement(i,j,move,a,b,c,speed);
			print:

			for(z=0;z<3;z++){
				check(ig[z],jg[z],ag[z],bg[z],cg[z]);
				movementg(ig[z],jg[z],moveg[z],ag[z],bg[z],cg[z],speedg);

				setfillstyle(SOLID_FILL,RED);
				setcolor(RED);
				circle(ig[z],jg[z],10);
				floodfill(ig[z],jg[z],RED);
			}
			p=90;
			settextstyle(6,HORIZ_DIR,3);
			setcolor(14);
			setfillstyle(SOLID_FILL,14);
			outtextxy(30,5,"LIFES:");

			for(int l=2;l>death;l--){

				arc(p,20,30,330,10);
				line(p,20,p+8,20-8);
				line(p,20,p+8,20+8);

			       floodfill(p,19,14);
				p+=22;
			}
			outtextxy(300,5,"SCORE:");
			sprintf(temp,"%d",score);
			outtextxy(400,5,temp);

			setcolor(14);
			circle(i,j,10);
			setfillstyle(SOLID_FILL,14);
			floodfill(i,j,YELLOW);
			delay(100);
			sc++;
			if(sc==5){
				score++;
				sc=0;
			}
		}
		else{
			outtextxy(235,200,"PAUSED");
		}
	}
	end:
	if(death==2)
		game_over();

}

void game_over()
{
	void menu();
	char temp[50];
	cleardevice();
	setcolor(RED);
	rectangle(0,10,635,435);
	rectangle(10,20,625,425);
	settextstyle(1,HORIZ_DIR,7);
	outtextxy(155,100,"GAME OVER");
	settextstyle(6,HORIZ_DIR,4);
	outtextxy(235,200,"SCORE:");
	sprintf(temp,"%d",score);
	outtextxy(355,200,temp);
	settextstyle(6,HORIZ_DIR,1);
	outtextxy(195,250,"(PRESS ANY KEY TO CONTINUE)");
	getch();
	cleardevice();
	menu();
}

//THE DISPLAY MENU FUNCTION
void options()
{
	setcolor(WHITE);
	rectangle(0,10,635,435);
	rectangle(10,20,625,425);
	settextstyle(BOLD_FONT, HORIZ_DIR, 5);
	outtextxy(185,20,"PAC-MAN");
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	outtextxy(235,200,"PLAY GAME");
	outtextxy(235,230,"Instructions");
	outtextxy(235,260,"Credits");
	outtextxy(235,290,"EXIT");
}

//TO SELECT THE MENU
void menu()
{
	void instructions();
	void credits();
	void loading();
	int i=1,y=206,p=0;
	options();

	setfillstyle(SOLID_FILL,WHITE);

	arc(220,y,30,330,10);
	line(220,y,228,y-8);
	line(220,y,228,y+8);
	floodfill(219,y,WHITE);
	while(1)
	{
		if(kbhit())
		{
			int ch=0;
			ch=getch();
			switch(ch)
			{
				case keyup:

					if(i!=1)
					{
						i--;
						y-=30;
						p=1;
					 }
					 break;

				case keydown:

					if(i!=4)
					{
						i++;
						y+=30;
						p=1;
					}
					break;

				case enter:
					if(i==1)
						loading();
					else if(i==2)
						instructions();
					else if(i==3)
						credits();
					else if(i==4)
						exit(1);
					break;
			 }
		}
		if(p==1)
		{
		cleardevice();
		setfillstyle(SOLID_FILL,WHITE);

		arc(220,y,30,330,10);
		line(220,y,228,y-8);
		line(220,y,228,y+8);
		floodfill(219,y,WHITE);
		options();
		p=0;
		}
	}
}

//FUNCTION TO DISPLAY THE LOADING PAGE
void loading()
{
	cleardevice();
	int x=170;
	rectangle(170,200,470,220);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	outtextxy(170,180,"LOADING,PLEASE WAIT");
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	outtextxy(170,230,"PAC-MAN BEING CREATED");
	for(int i=0;i<100;i++)
	{
		delay(20);
		bar(170,200,x,220);
		x++;
	}
	cleardevice();
	rectangle(170,200,470,220);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	outtextxy(170,180,"LOADING,PLEASE WAIT");
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	outtextxy(170,230,"GHOST ARE BEING TELEPORTED");
	for(i=0;i<100;i++)
	{
		delay(20);
		bar(170,200,x,220);
		x++;
	}
	cleardevice();
	rectangle(170,200,470,220);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	outtextxy(170,180,"LOADING,PLEASE WAIT");
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	outtextxy(170,230,"ARENA WILL BE READY SOON");
	for(i=0;i<100;i++)
	{
		delay(20);
		bar(170,200,x,220);
		x++;
	}
	cleardevice();
	game();
	getch();
	}

//FUNCTION TO DISPLAY THE CREDITS
void credits()
{
	cleardevice();
	rectangle(0,10,635,435);
	settextstyle(BOLD_FONT,HORIZ_DIR,5);
	outtextxy(170,30,"CREDITS");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	outtextxy(140,150,"SAVARGAONKAR HIMANSHU ARVIND");
	outtextxy(140,180,"G. PRANEETH");
	outtextxy(140,220,"VIRUPAKSHAN");
	settextstyle(6,HORIZ_DIR,1);
	outtextxy(145,350,"(PRESS ANY KEY TO CONTINUE)");

	void menu();
	getch();
	cleardevice();
	menu();
}

//FUNCTION TO DISPLAY THE INSTRUCTIONS
void instructions()
{
	cleardevice();
	char s[100];
	int ycor=150;
	rectangle(0,10,635,450);
	settextstyle(BOLD_FONT,HORIZ_DIR,5);
	outtextxy(100,30,"INSTRUCTIONS");
	settextstyle(6,HORIZ_DIR,1);
	fstream x;
	x.open("instr.txt",ios::in);
	while(!x.eof())
	{
		ycor+=20;
		x.getline(s,80);
		outtextxy(0,ycor,s);
	}
	settextstyle(1,HORIZ_DIR,1);
	outtextxy(145,410,"(PRESS ANY KEY TO CONTINUE)");

	getch();
	cleardevice();

	menu();
}


void main()
{
	int gd=DETECT;
	int gm;
	initgraph(&gd,&gm, "C:\\TurboC3\\BIN\\BGI");
	randomize();
	menu();
	closegraph();
getch();
}