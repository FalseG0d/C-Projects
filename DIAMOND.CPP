#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>

//////////////////////////////////////////////////////////////////////////////

int p=9,q=9;
char c1,c2;

//////////////////////////////////////////////////////////////////////////////

void point(char a[21][21],int x,int y)
 {
  a[x-1][y-1]=218;
  a[x+1][y+1]=217;
  a[x+1][y-1]=192;
  a[x-1][y+1]=191;
 }

//////////////////////////////////////////////////////////////////////////////

void canout(char a[21][21])
 {
  clrscr();
  int i,j;
  point(a,p,q);
  gotoxy(1,1);
  for (i=0;i<21;i++)
   {
    for (j=0;j<21;j++)
     {
      switch (a[i][j])
       {
	case 3:   textcolor(1);
		  cprintf("%c",a[i][j]);
		  break;
	case 4:   textcolor(2);
		  cprintf("%c",a[i][j]);
		  break;
	case 5:   textcolor(3);
		  cprintf("%c",a[i][j]);
		  break;
	case 14:  textcolor(4);
		  cprintf("%c",a[i][j]);
		  break;
	case 15:  textcolor(5);
		  cprintf("%c",a[i][j]);
		  break;
	case 21:  textcolor(6);
		  cprintf("%c",a[i][j]);
		  break;
	case ' ': cprintf("%c",a[i][j]);
		  break;
	case '¿':
	case 'À':
	case 'Ú':
	case 'Ù': textcolor(15+128);
		  cprintf("%c",a[i][j]);
		  break;
       }
     }
    cout<<"\n";
   }
  textcolor(15);
 }
//////////////////////////////////////////////////////////////////////////////

void pointdel(char a[21][21],int x1,int y1)
 {
  a[x1-1][y1-1]=' ';
  a[x1+1][y1+1]=' ';
  a[x1+1][y1-1]=' ';
  a[x1-1][y1+1]=' ';
 }

//////////////////////////////////////////////////////////////////////////////

void diamondco(char a[21][21],char c)
 {
  switch (c)
   {
    case 'w': if (p>1)
	       {
		pointdel(a,p,q);
		p-=2;
		point(a,p,q);
	       }
	      break;
    case 's': if (p<19)
	       {
		pointdel(a,p,q);
		p+=2;
		point(a,p,q);
	       }
	      break;
    case 'a': if (q>1)
	       {
		pointdel(a,p,q);
		q-=2;
		point(a,p,q);
	       }
	      break;
    case 'd': if (q<19)
	       {
		pointdel(a,p,q);
		q+=2;
		point(a,p,q);
	       }
	      break;
   }
  clrscr();
  canout(a);
 }

//////////////////////////////////////////////////////////////////////////////

void shift(char a[21][21],char c)
 {
  char temp;
  char x,y;
  switch (c)
   {
    case 'w': x=p-2;
	      y=q;
	      break;
    case 's': x=p+2;
	      y=q;
	      break;
    case 'a': y=q-2;
	      x=p;
	      break;
    case 'd': y=q+2;
	      x=p;
	      break;
   }
  temp=a[p][q];
  a[p][q]=a[x][y];
  a[x][y]=temp;
 }

//////////////////////////////////////////////////////////////////////////////

int syneli(char a[21][21])
 {
  int i,j,k,n,score=0;

  randomize();

  for (i=1;i<21;i+=2)
   {
    for (j=1;j<21;j+=2)
     {
      for (k=j+2;k<21;k+=2)
       {
	if ( (a[i][j]==a[i][k]) && (a[i][j]==a[i][k+2]) )
	 {
	  score+=3;

	  n=random(6);
	  if (n==0)
	   a[i][j]=3;
	  if (n==1)
	   a[i][j]=4;
	  if (n==2)
	   a[i][j]=5;
	  if (n==3)
	   a[i][j]=14;
	  if (n==4)
	   a[i][j]=15;
	  if (n==5)
	   a[i][j]=21;

	  n=random(6);
	  if (n==0)
	   a[i][k]=3;
	  if (n==1)
	   a[i][k]=4;
	  if (n==2)
	   a[i][k]=5;
	  if (n==3)
	   a[i][k]=14;
	  if (n==4)
	   a[i][k]=15;
	  if (n==5)
	   a[i][k]=21;
	 }
	else
	 break;
       }
     }
   }

  for (i=1;i<21;i+=2)
   {
    for (j=1;j<21;j+=2)
     {
      for (k=j+2;k<21;k+=2)
       {
	if ( (a[j][i]==a[k][i]) && (a[j][i]==a[k+2][i]) )
	 {
	  score+=3;

	  n=random(6);
	  if (n==0)
	   a[i][j]=3;
	  if (n==1)
	   a[i][j]=4;
	  if (n==2)
	   a[i][j]=5;
	  if (n==3)
	   a[i][j]=14;
	  if (n==4)
	   a[i][j]=15;
	  if (n==5)
	   a[i][j]=21;

	  n=random(6);
	  if (n==0)
	   a[k][i]=3;
	  if (n==1)
	   a[k][i]=4;
	  if (n==2)
	   a[k][i]=5;
	  if (n==3)
	   a[k][i]=14;
	  if (n==4)
	   a[k][i]=15;
	  if (n==5)
	   a[k][i]=21;
	 }
	else
	 break;
       }
     }
   }

  return score;
 }

//////////////////////////////////////////////////////////////////////////////

void main()
 {
  clrscr();

  int i,j,k,l,x=0,y=1;
  char a[21][21],b[21][21],ch,ch1,ch2;

  int moves=0,exps=0;
  int score=0,sc=0,sc1=0;

  textcolor(15);

  randomize();

//////////////////////////////////////////////////////////////////////////////

  clrscr();
  cout<<" *       *    * * *    *        * * *    * * *      *   *      * * *     \n";
  cout<<"  *  *  *     * *      *        *        *   *     *  *  *     * *       \n";
  cout<<"   *   *      * * *    * * *    * * *    * * *    *       *    * * *     \n";
  cout<<"Hello, this is Deepak and Apporv here....\n";
  cout<<"This is a prototype of Diamond Shifter....\n";
  getch();
  cout<<"We hope you will enjoy....\n";

//////////////////////////////////////////////////////////////////////////////

  getch();
  clrscr();
  cout<<"÷Some basic techniques to be followed for better experience....:\n";
  cout<<"  1. You are requested to wait while the system configures the program.\n";
  cout<<"  2. You are requested to be patient and concentrate upon your gameplay.\n";
  cout<<"  3. Whenever there is a hault in the program, please wait until the program         configures everything.\n";
  cout<<"  4. Cursor control understanding:\n";
  cout<<"       * Whenever you see \" a normal cursor \" , you are eligible to use the              keyboard.\n";
  cout<<"       * Whenever you see \" no cursor \" , you are requested to be patient                and wait.\n";
  cout<<"       * Whenever you see \" a solid cursor \" , the game is over.\n";
  cout<<"  5. If you want to exit from the gameplay at any point of time, press:\n";
  cout<<"       ## ( after selection of the diamond )  '0' .\n";
  cout<<"  6. If you try to put in illegal commands,\n";
  cout<<"       ## ( not mentioned in the rules )\n";
  cout<<"     then you are responsible for the fate of the program.\n";
  cout<<"  7. Do not try to change the program logic.\n";
  cout<<"  8. You are requested to turn 'on' your speakers for better experience.\n";
  cout<<"  9. Copyright by:\n";
  cout<<"       * Deepak Dhingra\n";
  cout<<"       * Apoorv Garg\n";
  getch();
  cout<<"                           THANK YOU FOR READING....\n";

//////////////////////////////////////////////////////////////////////////////

  getch();
  clrscr();
  cout<<"Enter your choice:\n";
  cout<<" 1. Play now....\n";
  cout<<" 2. Quick rules....\n";
  cout<<" 3. Exit\n";
  do
   {
    cin>>ch;
   } while ( ch<='0' || ch>'3' );

//////////////////////////////////////////////////////////////////////////////

  if (ch=='2')
   {
    clrscr();
    cout<<"\n÷Rules:\n";
    cout<<" 1. In this game,you have to match atleast three diamonds to gain points.\n";
    cout<<" 2. Points will be given on the basis of number of diamonds in a combination you    are making.\n";
    cout<<"                                  Points\n";
    cout<<"        1.   3 diamonds combo  :    3\n";
    cout<<"        2.   4 diamonds combo  :    6\n";
    cout<<"        3.   5 diamonds combo  :   12\n";
    cout<<" 3. In order to navigate through the playing screen you need to use:\n";
    cout<<"        1.   w  :  up.\n";
    cout<<"        2.   s  :  down.\n";
    cout<<"        3.   a  :  left.\n";
    cout<<"        4.   d  :  right.\n";
    cout<<" 4. To select the diamond for swapping, press '5'.\n";
    cout<<" 5. To select the diamond to be swapped with, press:\n";
    cout<<"        1.   w  :  upper diamond.\n";
    cout<<"        2.   s  :  lower diamond.\n";
    cout<<"        3.   a  :  left diamond.\n";
    cout<<"        4.   d  :  right diamond.\n";
    cout<<" 6. If you want to reload the game with original score, press:\n";
    cout<<"        ## ( after selection of the diamond )  'l' .\n";
    cout<<"        ** But you can reload only once in a gameplay.\n";
    cout<<"    So, use it carefully.\n";
    getch();
   }
  if (ch=='3')
   goto l2;

  _setcursortype(_NOCURSOR);

  cout<<"So let's get started";
  for (l=0;l<5;l++)
   {
    cout<<".";
    delay(400);
   }

  _setcursortype(_NORMALCURSOR);

  clrscr();
  cout<<"÷GAMEPLAY available....\n";
  cout<<"  * You have to reach a minimum score deadline within limited moves                 provided to you.\n";
  getch();
  clrscr();

//////////////////////////////////////////////////////////////////////////////

  do
   {
    for (i=0;i<21;i++)
     {
      for (j=0;j<21;j++)
       {
	a[i][j]=32;
       }
     }

    _setcursortype(_NOCURSOR);

    do
     {
      if ( (syneli(a)!=0) && (i>0) )
       {
	clrscr();
	cout<<"LOADING";
	for (l=0;l<5;l++)
	 {
	  delay(100);
	  cout<<".";
	 }
       }

      for (i=0;i<21;i++)
       {
	for (j=0;j<21;j++)
	 {
	  if ( (i%2!=0) && (j%2!=0) )
	   {
	    k=random(6);
	    if (k==0)
	     a[i][j]=3;
	    if (k==1)
	     a[i][j]=4;
	    if (k==2)
	     a[i][j]=5;
	    if (k==3)
	     a[i][j]=14;
	    if (k==4)
	     a[i][j]=15;
	    if (k==5)
	     a[i][j]=21;
	   }
	 }
       }
     } while (syneli(a)!=0);

    _setcursortype(_NORMALCURSOR);

//////////////////////////////////////////////////////////////////////////////

    x=0;
    y=1;
    score=0;
    sc=0;
    sc1=0;

    clrscr();
    cout<<"Enter the maximum moves available\t";
    cin>>moves;
    cout<<"Enter the score expected\t\t";
    cin>>exps;

    l1:

     textcolor(15+128);
     cprintf("PRESS ANY KEY TO CONTINUE....\n");

     do
      {
       do
	{
	 c1=getch();
	 diamondco(a,c1);
	} while (c1!='5');
       c2=getch();

       if (c2=='0')
	{
	 clrscr();
	 cout<<"All your progress will be lost....!\n";
	 cout<<"Do you still wish to exit....? (y/n) || (Y/N)\n";
	 cin>>ch2;
	 if ( (ch2=='y') || (ch2=='Y') )
	  goto l2;
	 else
	  goto l1;
	}

       if ( (c2=='l') && (y==1) )
	{
	 clrscr();
	 cout<<"Do you want to reload your gameplay....?  (y/n) || (Y/N)\n";
	 cin>>ch2;

	 if ( (ch2=='y') || (ch2=='Y') )
	  {

	   _setcursortype(_NOCURSOR);

	   do
	    {
	     if ( (syneli(a)!=0) && (i>0) )
	      {
	       clrscr();
	       cout<<"LOADING";
	       for (l=0;l<5;l++)
		{
		 delay(100);
		 cout<<".";
		}
	      }

	     for (i=0;i<21;i++)
	      {
	       for (j=0;j<21;j++)
		{
		 if ( (i%2!=0) && (j%2!=0) )
		  {
		   k=random(6);
		   if (k==0)
		    a[i][j]=3;
		   if (k==1)
		    a[i][j]=4;
		   if (k==2)
		    a[i][j]=5;
		   if (k==3)
		    a[i][j]=14;
		   if (k==4)
		    a[i][j]=15;
		   if (k==5)
		    a[i][j]=21;
		  }
		}
	      }
	    } while (syneli(a)!=0);

	   _setcursortype(_NORMALCURSOR);

	   y=0;
	   clrscr();
	   cout<<"Gameplay successfully reloaded....!\n";
	   cout<<"Now you cannot reload your gameplay again....!\n";
	   getch();

	   clrscr();
	   goto l1;
	  }

	 else
	  {
	   clrscr();
	   cout<<"It's OK....\n";
	   cout<<"You can use your reload some other time....!\n";
	   cout<<"Feel free to use it....!\n";
	   getch();
	   clrscr();
	   goto l1;
	  }

	}

       else if ( (y==0) && (c2==l) )
	{
	 clrscr();
	 cout<<"Sorry, you are left with no reloads....!\n";
	 getch();
	 clrscr();
	 goto l1;
	}

       for (i=0;i<21;i++)
	{
	 for (j=0;j<21;j++)
	  b[i][j]=a[i][j];
	}
       shift(b,c2);
       sc1=syneli(b);

       if (sc1==0)
	{
	 sound(100);
	 cout<<"\nInvalid move....!\n";
	 delay(500);
	 nosound();
	}

       if (sc1>0)
	{
	 shift(a,c2);
	 sc=syneli(a);
	 clrscr();
	 score=score+sc;
	 moves--;
	 /*
	 do
	  {
	   for (i=0;i<21;i++)
	    {
	     for (j=0;j<21;j++)
	      b[i][j]=a[i][j];
	    }
	   if (syneli(b)!=0)
	    score+=syneli(a);
	  } while (syneli(b)!=0);
	 */
	 sound(1000);
	 canout(a);
	 cout<<"\nCurrent Score\t"<<score;
	 cout<<"\nMoves left\t"<<moves;
	 cout<<"\nTarget\t\t"<<exps;
	 delay(50);
	 nosound();
	}

       if ( (moves<=0) || (score>=exps) )
	{

	 _setcursortype(_NOCURSOR);

	 getch();
	 clrscr();
	 cout<<"LOADING";
	 for (l=0;l<5;l++)
	  {
	   cout<<".";
	   delay(400);
	  }

	 _setcursortype(_SOLIDCURSOR);

	 clrscr();
	 sound(1500);
	 cout<<"\nGame over....!\n";
	 delay(1000);
	 nosound();
	 x=1;
	}

       if (score>=exps)
	{
	 cout<<"Analysing data";
	 for (l=0;l<5;l++)
	  {
	   cout<<".";
	   delay(400);
	  }

	 for (l=0;l<8;l++)
	  {
	   if (l==0)
	    cout<<"\nYou win....\n";
	   sound(300*l);
	   delay(150);
	  }
	 nosound();
	 x=1;
	}

       else if ( (score<exps) && (x==1) )
	{
	 cout<<"Analysing data";
	 for (l=0;l<5;l++)
	  {
	   cout<<".";
	   delay(400);
	  }

	 for (l=8;l>0;l--)
	  {
	   if (l==8)
	    cout<<"\nYou lose....!\n";
	   sound(50*l);
	   delay(150);
	  }
	 nosound();
	 x=1;
	}

      } while (x==0);

    _setcursortype(_NORMALCURSOR);

    getch();
    clrscr();
    cout<<"Do you wish to play again.... (y/n) || (Y/N) ?\n";
    cin>>ch1;
   } while ( (ch1=='y') || (ch1=='Y') );

//////////////////////////////////////////////////////////////////////////////

  l2:

   _setcursortype(_NOCURSOR);

   clrscr();
   for (i=1;i<=14;i++)
    {
     sound(500+100*i);

     if (i%2==0)
      {
       textcolor(2);
       textbackground(4);
      }

     else
      {
       textcolor(4);
       textbackground(2);
      }

     switch (i)
      {
       case 1:  gotoxy(35,13);
		cprintf("T");
		break;
       case 2:  gotoxy(35+i-1,13);
		cprintf("H");
		break;
       case 3:  gotoxy(35+i-1,13);
		cprintf("A");
		break;
       case 4:  gotoxy(35+i-1,13);
		cprintf("N");
		break;
       case 5:  gotoxy(35+i-1,13);
		cprintf("K");
		break;
       case 6:  gotoxy(35+i-1,13);
		cprintf(" ");
		break;
       case 7:  gotoxy(35+i-1,13);
		cprintf("Y");
		break;
       case 8:  gotoxy(35+i-1,13);
		cprintf("O");
		break;
       case 9:  gotoxy(35+i-1,13);
		cprintf("U");
		break;
       case 10: gotoxy(35+i-1,13);
		cprintf(".");
		break;
       case 11: gotoxy(35+i-1,13);
		cprintf(".");
		break;
       case 12: gotoxy(35+i-1,13);
		cprintf(".");
		break;
       case 13: gotoxy(35+i-1,13);
		cprintf(".");
		break;
       case 14: gotoxy(35+i-1,13);
		cprintf("");
		break;
      }
     delay(100);
    }

   delay(500);
   gotoxy(35,13);
   textcolor(i+128);
   textbackground(i+1);
   cprintf("THANK YOU....\n");
   nosound();

   _setcursortype(_NORMALCURSOR);

//////////////////////////////////////////////////////////////////////////////

  getch();
 }