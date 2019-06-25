#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<iostream.h>
char map[20][20];
int p=10,q=10,p1,q1;
class game
{
public:
	void start();
	void print();
	void jump();
	void move(char ch);
	void fall();
	void fall2(char ch);
	void re();
	int score;
	game()
	{score=0;}
//	void score();


};
void game::re()
	{
	randomize();
	p1=random(19);
	q1=random(19);
	}
void game::jump()
	{

		if(((p<19)&&(map[p-1][q]=='\0'))||(map[p-1][q]=='0'))
		{
		p--;
		delay(250);
		print();
		}
		else if((map[p-1][q]=='\0')||(map[p-1][q]=='0'))
		fall();

	}

void game::move(char ch)
	{
	if(ch=='a')
	{
	if((map[p][q-1]=='\0')||(map[p][q-1]=='0'))
	q--;
	}
	else if(ch=='r')
		{
		p=5;
		q=5;
		}
	else if(ch=='o')
		{
		randomize();
		p1=random(19);
		q1=random(19);
		}
	else if(ch=='d')
	{
	if((map[p][q+1]=='\0')||(map[p][q+1]=='0'))
	q++;
	}
	else if(ch=='w')
	for(int i=0;i<3;i++)
	jump();
	else if(ch=='e')
		{
		for(int i=0;i<3;i++)
		{
		q++;
		jump();
		}
		fall2(ch);
		}
	else if(ch=='q')
		{
		for(int i=0;i<3;i++)
		{
		q--;
		jump();
		}
		fall2(ch);

		}
	fall();
	}
void game::fall()
{
while(((map[p+1][q]=='\0')&&(p<=19)&&(p>=1))||(map[p+1][q]=='0'))
{
p++;
delay(250);
print();
}
}
void game::fall2(char ch)
{
if(ch=='q')
{
	while(((map[p+1][q]=='\0')&&(p<=19)&&(p>=1)&&(q!=0)&&(q!=20))||(map[p+1][q]=='0'))
	{
	q--;
	p++;
	delay(250);
	print();
	}
}

if(ch=='e')
{
	while(((map[p+1][q]=='\0')&&(p<=19)&&(p>=1)&&(q!=0)&&(q!=20))||(map[p+1][q]=='0'))
	{
	q++;
	p++;
	delay(250);
	print();
}
}
}
void game::start()
		{
		for(int i=0;i<20;i++)
			{
			for(int j=0;j<20;j++)
				{
				if((i==p)&&(j==q))
					{
					map[i][j]='*';
					}
				else if((i==p1)&&(q1==j))
					map[i][j]='0';
				else if((i==0)||(i==19)&&((i%4!=0)||(j%4!=0))||((i%3==0)&&(j%5!=0)))
					{
					map[i][j]='-';
					}
				else if((j==0)||(j==19))
					{
					map[i][j]='|';
					}
				else
					map[i][j]='\0';
				}
			}
		}
void game::print()
{
clrscr();
start();
for(int i=0;i<20;i++)
	{
	for(int j=0;j<20;j++)
		cout<<map[i][j]<<" ";
		cout<<"\n";
	}
if((p==p1)&&(q==q1))
{
score++;
randomize();
p1=random(19);
q1=random(19);
}
cout<<"\nScore"<<score;

}
void main()
{
clrscr();
game a;
char ch;
do
{
a.print();
ch=getch();
a.move(ch);
}while(ch!='x');
getch();
}