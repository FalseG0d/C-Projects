#include<conio.h>
#include<fstream.h>
class map
{
int p,q,sno;
public:
	map()
	{p=q=10;}
	void menu();
	char field[20][20],ch;
	void move();
	void print();
	void create();
	void start();
	void save();
}temp;
void map::save()
{
ofstream fin;
fin.open("map.dat",ios::trunc);
fin.write((char*)&temp,sizeof(temp));
}
void map::move()
{
if(ch=='w')
	p--;
else if(ch=='s')
	p++;
else if(ch=='m')
	save();
else if(ch=='a')
	q--;
else if(ch=='c')
	{
	if(field[p][q]=='\0')
	field[p][q]=178;
	else if(field[p][q]=='²')
	field[p][q]='\0';
	}
else if(ch=='d')
	q++;
}
void map::start()
{
//ofstream fin;
for(int i=0;i<20;i++)
	{
	for(int j=0;j<20;j++)
		{
		if(field[i][j]=='²')
			field[i][j]=178;
		else if((i==(p-1))&&(j==(q-1)))
			field[i][j]=218;
		else if((i==(p-1))&&(j==(q+1)))
			field[i][j]=191;
		else if((i==(p+1))&&(j==(q+1)))
			field[i][j]=217;
		else if((i==(p+1))&&(j==(q-1)))
			field[i][j]=192;
		else if((i==0)||(i==19))
			field[i][j]='-';
		else if((j==0)||(j==19))
			field[i][j]='|';
		else
			field[i][j]='\0';
		}
	}
//fin.open("map.dat",ios::in);
//fin.write((char*)&temp,sizeof(temp));
//fin.close();
}
void map::print()
{
clrscr();
start();
//ifstream fout;
//fout.open("map.dat",ios::trunc);
//while(fout)
{
//fout.read((char*)&temp,sizeof(temp));
cout<<"\nSerial no: "<<sno<<"\n";
for(int i=0;i<20;i++)
	{
	for(int j=0;j<20;j++)
		cout<<field[i][j];
	cout<<endl;
	}
//fout.close();
}
}
void map::create()
{
cout<<"\nEnter the serial number";
cin>>sno;
do
	{
	print();
	ch=getch();
	move();
	}
while(ch!='x');
}
void map::menu()
{
do
	{
	clrscr();
	cout<<"\nEnter the choice";
	cout<<"\n1.Create a map";
	cout<<"\n2.View maps";
	cout<<"\n3.Exit";
	cin>>ch;
	if(ch=='1')
		create();
	}
while(ch!='3');
}              /*
void main()
{
clrscr();
map a;
a.menu();
getch();
}                */