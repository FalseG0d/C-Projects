#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>


class Map
{

int moves,p,q,xWin,yWin;
public:
char pos[7][7],play;
	Map(){
	moves=0;
	p=1;
	q=1;
	}
void print();
int check();
int getMoves(){
return moves;
}
void setPlay(char ch){
play=ch;
}
void refresh();
void init();
int intInArray(int x,char ch);
void mov(char ch);

};

void Map::mov(char ch){
switch(ch)
	{
	case 'w':
		if(p>1)
		p-=2;
		break;
	case 's':
		if(p<5)
		p+=2;
		break;
	case 'a':
		if(q>1)
		q-=2;
		break;
	case 'd':
		if(q<5)
		q+=2;
		break;
	case '5':if(pos[p][q]==' '){
		pos[p][q]=play;
		moves++;
		xWin=yWin=0;
		}
		break;
	}
}
void Map::refresh()
{
for(int i=0;i<7;i++)
	{
	for(int j=0;j<7;j++)
		{
		if((i%2==0)||(j%2==0))
		{
		if((i==p-1)&&(j==q-1))
			pos[i][j]='Ú';
		else if((i==p-1)&&(j==q+1))
			pos[i][j]='¿';
		else if((i==p+1)&&(j==q-1))
			pos[i][j]='À';
		else if((i==p+1)&&(j==q+1))
			pos[i][j]='Ù';
		else if((i%2==0)&&(j%2==0))
			pos[i][j]='+';
		else if(i%2==0)
			pos[i][j]='-';
		else if(j%2==0)
			pos[i][j]='|';

		}
		}
	}
}

void Map::init()
{
for(int i=0;i<7;i++)
	{
	for(int j=0;j<7;j++)
		{
		if((i%2==0)||(j%2==0))
		{
		if((i==p-1)&&(j==q-1))
			pos[i][j]='Ú';
		else if((i==p-1)&&(j==q+1))
			pos[i][j]='¿';
		else if((i==p+1)&&(j==q-1))
			pos[i][j]='À';
		else if((i==p+1)&&(j==q+1))
			pos[i][j]='Ù';
		else if((i%2==0)&&(j%2==0))
			pos[i][j]='+';
		else if(i%2==0)
			pos[i][j]='-';
		else if(j%2==0)
			pos[i][j]='|';

		}
		else
			pos[i][j]=' ';
		}
	}
}

int Map::check(){
int scoreX1=0,scoreY1=0,scoreX2=0,scoreY2=0;
for(int i=0;i<7;i++)
	{
	for(int j=0;j<7;j++)
		{
		if((i%2!=0)||(j%2!=0))
			{
			if(pos[i][j]=='X'){
				scoreX1+=i;
				scoreX2+=j;
				}
			else if(pos[i][j]=='0'){
				scoreY1+=i;
				scoreY2+=j;
				}
			}
		}
	}
if((scoreX2%3==0)&&(scoreX1%3==0)&&(scoreX1+scoreX2>2))
	{
	cout<<"\nX wins";
	getch();
	xWin++;
	return 1;
	}
else if((scoreY2%3==0)&&(scoreY1%3==0)&&(scoreY1+scoreY2>2))
	{
	cout<<"\n0 wins";
	getch();
	yWin++;
	return 1;
	}
return 0;
}


void Map::print()
{
refresh();
for(int i=0;i<7;i++)
	{
	for(int j=0;j<7;j++)
		{
		cout<<pos[i][j]<<" ";
		}
	cout<<"\n";
	}
}              /*
int main()
{
clrscr();
Map a;
char ch;
cout<<"\nPlay as......";
cin>>ch;
a.setPlay(ch);
a.init();
do
	{
	a.print();
	clrscr();
	a.print();
	ch=getch();
	a.mov(ch);
	}while(ch!='x');
return 0;
}            */
