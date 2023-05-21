#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <time.h>
#include <windows.h>
using namespace std;
int a[38]={0};
int O[10];
int X[10];
int winRed;
int winBlue;
int m;
void initial()
{
    for(int i=1;i<=36;i++)
      {
        if((i==6)||(i==7)||(i==8)||(i==12)||(i==18)||(i==21)||(i==22)||(i==28)||(i==33)||(i==34)||(i==35))
           a[i]=1;
        else if((i==4)||(i==9)||(i==10)||(i==11)||(i==16)||(i==19)||(i==24)||(i==30)||(i==31)||(i==32)||(i==36))
            a[i]=2;
      }
}
void SetColorAndBackGround(int ForgC,int BackC)
{
    WORD wColor=((BackC & 0x0F)<<4)+(ForgC & 0x0F);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),wColor);
}
void printGame()
{
  int k;
  for(int i=1;i<=36;i++)
 {
      if(a[i]==1)
      {
        SetColorAndBackGround(7,4);
        cout<<"|  Red ";
      }
      else if(a[i]==2)
      {
        SetColorAndBackGround(7,1);
        cout<<"| Blue ";
      }
      else if(a[i]==3)
      {
        if(i<10)
        {
          SetColorAndBackGround(7,0);
          cout<<"|  "<<i<<"   ";
        }
        else
        {
           SetColorAndBackGround(7,0);
           cout<<"|  "<<i<<"  ";
        }
        a[i]=0;
      }
      else
      {
       if(i<10)
       {
         SetColorAndBackGround(7,0);
         cout<<"|  "<<i<<"   ";
       }
       else
       {
          SetColorAndBackGround(7,0);
          cout<<"|  "<<i<<"  ";
       }
      }
      if(i%3==0)
       cout<<"|"<<endl;
      if(i%12==0)
      {
        SetColorAndBackGround(7,0);
        cout<<"|____________________|"<<endl<<endl;
      }
      if((1<=i)&&(i<=3))
    {
        if(((a[i]==1)&&(a[i+3]==1)&&(a[i+6]==1))||((a[i+3]==1)&&(a[i+6]==1)&&(a[i+9]==1)))
      {
           O[i]=1;
           X[i]=0;
      }
       else if(((a[i]==2)&&(a[i+3]==2)&&(a[i+6]==2))||((a[i+3]==2)&&(a[i+6]==2)&&(a[i+9]==2)))
      {
           O[i]=0;
           X[i]=1;
      }
       else
      {
           O[i]=0;
           X[i]=0;
      }
     }
      if((13<=i)&&(i<=15))
    {
        if(((a[i]==1)&&(a[i+3]==1)&&(a[i+6]==1))||((a[i+3]==1)&&(a[i+6]==1)&&(a[i+9]==1)))
      {
           O[i-9]=1;
           X[i-9]=0;
      }
       else if(((a[i]==2)&&(a[i+3]==2)&&(a[i+6]==2))||((a[i+3]==2)&&(a[i+6]==2)&&(a[i+9]==2)))
      {
           O[i-9]=0;
           X[i-9]=1;
      }
       else
      {
           O[i-9]=0;
           X[i-9]=0;
      }
     }
      if((25<=i)&&(i<=27))
    {
        if(((a[i]==1)&&(a[i+3]==1)&&(a[i+6]==1))||((a[i+3]==1)&&(a[i+6]==1)&&(a[i+9]==1)))
      {
           O[i-18]=1;
           X[i-18]=0;
      }
       else if(((a[i]==2)&&(a[i+3]==2)&&(a[i+6]==2))||((a[i+3]==2)&&(a[i+6]==2)&&(a[i+9]==2)))
      {
           O[i-18]=0;
           X[i-18]=1;
      }
       else
      {
           O[i-18]=0;
           X[i-18]=0;
      }
     }
 }
  }
void play(int player,int& i,int& k)
{
  if (player<3)
{
   int bug1=0;
   int bug2=0;
   int bug3=0;
   int bug4=0;
   int bug5=0;
   printGame();
   cout<<"Player"<<player<<endl;
   do{
     do{
        cout<<"請輸入顏色位置(原位置,目的地):";
        cin>>k>>i;
        if(((1<=i)&&(i<=9))||((13<=i)&&(i<=21))||((25<=i)&&(i<=33)))
          {
            if(a[i+3]==3)
              bug1=1;
            else if(a[i+3]!=3)
              bug1=0;
              if(a[i+3]!=player)
                bug2=1;
              else
                bug2=0;
          }
          if(a[k]!=player)
            bug3=1;
          else
            bug3=0;
          if(((4<=k)&&(k<=12))||((16<=k)&&(k<=24))||((28<=k)&&(k<=36)))
          {
           if((a[k-3]==1)||(a[k-3]==2))
             bug4=1;
           else
             bug4=0;
          }
          if(k==i+3)
            bug5=1;
          else
            bug5=0;
     }while(i<1||i>36||bug1||bug2||bug3||bug4||bug5||k<1||k>36);
   }while(a[i]!=0);
   a[i]=player;
}
  else if(player==3)
{
   a[k]=player;
}
}
void win()
{
       if((O[1]==1)&&(O[2]==1)&&(O[3]==1))
        {
           winRed=1;
           winBlue=0;
       }
       else if((X[1]==1)&&(X[2]==1)&&(X[3]==1))
    {
          winRed=0;
          winBlue=1;
    }
       else if((O[1]==1)&&(O[4]==1)&&(O[7]==1))
    {
          winRed=1;
          winBlue=0;
    }
       else if((X[1]==1)&&(X[4]==1)&&(X[7]==1))
    {
          winRed=0;
          winBlue=1;
    }
       else if((O[1]==1)&&(O[5]==1)&&(O[9]==1))
    {
          winRed=1;
          winBlue=0;
    }
       else if((X[1]==1)&&(X[5]==1)&&(X[9]==1))
    {
          winRed=0;
          winBlue=1;
    }
       else if((O[2]==1)&&(O[5]==1)&&(O[8]==1))
       {
          winRed=1;
          winBlue=0;
       }
       else if((X[2]==1)&&(X[5]==1)&&(X[8]==1))
       {
          winRed=0;
          winBlue=1;
       }
       else if((O[3]==1)&&(O[6]==1)&&(O[9]==1))
       {
          winRed=1;
          winBlue=0;
       }
       else if((X[3]==1)&&(X[6]==1)&&(X[9]==1))
       {
          winRed=0;
          winBlue=1;
       }
       else if((O[3]==1)&&(O[5]==1)&&(O[7]==1))
    {
          winRed=1;
          winBlue=0;
    }
       else if((X[3]==1)&&(X[5]==1)&&(X[7]==1))
    {
          winRed=0;
          winBlue=1;
    }
       else if((O[4]==1)&&(O[5]==1)&&(O[6]==1))
       {
          winRed=1;
          winBlue=0;
       }
       else if((X[4]==1)&&(X[5]==1)&&(X[6]==1))
       {
          winRed=0;
          winBlue=1;
       }
       else if((O[7]==1)&&(O[8]==1)&&(O[9]==1))
       {
          winRed=1;
          winBlue=0;
       }
       else if((X[7]==1)&&(X[8]==1)&&(X[9]==1))
       {
          winRed=0;
          winBlue=1;
       }
       else
       {
           winRed=0;
           winBlue=0;
       }
}
int main()
{
 int i=0;
 int k=0;
 int player=0;
 initial();
 win();
 do
  {
    play(1,i,k);
    play(3,i,k);
    win();
    play(2,i,k);
    play(3,i,k);
    win;
  }while((winRed==0)&&(winBlue==0));
   if(winRed==1)
    {
      SetColorAndBackGround(7,4);
      cout<<"Red "<<" win";
      SetColorAndBackGround(7,0);
    }
   else if(winBlue==1)
    {
      SetColorAndBackGround(7,1);
      cout<<"Blue "<<" win";
      SetColorAndBackGround(7,0);
    }
 return 0;
}
