#include"MAP.CPP"
class TicTacToe
{
Map a;
//int xWin,yWin;
public:
	void system();
	void gameplay();
	void _1vs1();
	void vsX();
	void vs0();
//	int check();
	void vs();

};
void TicTacToe::vs(){}/*{
Map temp1,temp2;
for(int i=0;i<7;i++)
	{
	for(int j=0;j<7;j++)
	temp1.pos[i][j]=temp2.pos[i][j]=a.pos[i][j];
	}
temp1.play=temp2.play=a.play;
do
{
for(int i=1;i<6;i+=2)
	{
	for(int j=1;j<6;j+=2)
		{
		if(temp1.pos[i][j]==' ')
			{
			if(temp1.play=='X')
			{
			temp1.play=temp1.pos[i][j]=temp2.play=temp2.pos[i][j]='0';
			for(int p=1;p<6;p+=2)
				{
				for(int q=1;q<6;q+=2)
					{
					if(temp2.play=='X')
						{
						temp2.play=temp2.pos[i][j]='0';
						}
					else
						{
						temp2.play=temp2.pos[i][j]='X';
						}
					}
				}
			}
			else
			temp1.play=temp1.pos[i][j]=temp2.play=temp2.pos[i][j]='X';
			for(int p=1;p<6;p+=2)
				{
				for(int q=1;q<6;q+=2)
					{
					if(temp2.play=='X')
						{
						temp2.play=temp2.pos[i][j]='0';
						}
					else
						{
						temp2.play=temp2.pos[i][j]='X';
						}
					}
				}

			}
		}
	}
}while(temp1.check()==0);
if((temp1.play=='X')&&(temp1.xWin>temp1.yWin))

}*/
void TicTacToe::vs0(){
clrscr();
char ch;
do
	{
	a.setPlay('X');
	a.print();
	clrscr();
	a.print();
	ch=getch();
	a.mov(ch);
	if(a.check()==1)
	{ch='x';}
	if(ch=='x')
	{break;}
	}while((ch!='5'));
vs();
if((a.getMoves()<8)&&(ch!='x'))
vs0();
}
void TicTacToe::vsX(){
clrscr();
vs();
char ch;
do
	{
	a.setPlay('0');
	a.print();
	clrscr();
	a.print();
	ch=getch();
	a.mov(ch);
	if(a.check()==1)
	{ch='x';}
	if(ch=='x')
	{break;}
	}while((ch!='5'));

if((a.getMoves()<8)&&(ch!='x'))
vsX();
}
void TicTacToe::gameplay(){
char ch;
cout<<"\nEnter the gameplay\n1.1vs1\n2.vs System";
cin>>ch;
if(ch=='1')
	_1vs1();
else
	{
	cout<<"\nPlay as X(y/n)?????";
	cin>>ch;
	a.init();
	if(ch=='y')
		vs0();
	else
		vsX();
	}
}
void TicTacToe::_1vs1(){
clrscr();
char ch;
a.init();
do{
do
	{
	a.setPlay('X');
	a.print();
	clrscr();
	a.print();
	ch=getch();
	a.mov(ch);
	if(a.check()==1)
	{ch='x';}
	if(ch=='x')
	{break;}
	}while(ch!='5');
if(ch=='x')
	break;
do
	{
	a.setPlay('0');
	a.print();
	clrscr();
	a.print();
	ch=getch();
	a.mov(ch);
	if(a.check()==1)
	ch='x';
	if(ch=='x')
	break;
	}while(ch!='5');
if(ch=='x')
	break;
}while((a.getMoves()<8));
clrscr();
a.print();
}
void TicTacToe::system(){

}
void main()
{
TicTacToe t;
t.gameplay();
//getch();
}