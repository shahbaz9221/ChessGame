# include"chess.h"
# include<iostream>
# include<math.h>
#include<string>
# include<windows.h>
using namespace std;
void main()
{
	
	 int a=3,b=3,c=4,d=4,x=0,y=0,mod=0,k=0;    //////////////  for castling type 111
	 bool check;
	 bool checkking=true;//for find check
	 int sx[100];int tx[100]; int sy[100]; int ty[100];
	 int i=0,j=0;
	 int p1h1=0,p1h2=0,p2h1=0,p2h2=0,p1k=0,p2k=0;
	 int r1=0,r2=0,r3=0,r4=0,smate=0,flag=0;
	std:: string board1[8][8];
	std::string board2[8][8];


	reset(board1);
	 displayboard(board1,a,b,c,d);
	 while(x==0&&player1win(board1)==false&& player2win(board1)==false && flag==0){
		 mod=y%2;
		if(mod==0)
		{
			cout<<endl;
			cout<<"   Player 1 turn "<<endl;
			
		}
		else
		{
			cout<<endl;
			cout<<"   Player 2 turn "<<endl;
		}

		 moveinput(a,b,c,d,p1h1,p1h2,p2h1,p2h2,p1k,p2k);
		 if(a==111)
		 {
			 if(mod==0)
			 {

			 castling1(board1,p1h1,p1h2,p2h1,p2h2,p1k,p2k);
			 castlingdisplayboard(board1);
			 }
			 else
			 {
				 castling2(board1,p2h1,p2h2,p2k);
				 castlingdisplayboard(board1);
			 }

		 }
		 else
		 {
		 
		 check=validmove(board1,a,b,c,d,mod);///0=mod
		 
		 while(check==false)
		 {
			 cout<<"Invalid again ";
			 moveinput(a,b,c,d,p1h1,p1h2,p2h1,p2h2,p1k,p2k);
			
		 check=validmove(board1,a,b,c,d,mod);//0=mod
		 }

		checkboard(board1,a,b,c,d);
		 if(mod==0)
		 {
		 checkking=check1(board1);
		 checkboardundo(board1,a,b,c,d);
		 }
		 else
		 {
			  checkking=check2(board1);
		 checkboardundo(board1,a,b,c,d);
		 }
		 
		 if(checkking==true)
		 {
		 system("cls");
		 sx[i]=a;sy[i]=b;tx[i]=c;ty[i]=d;
		 displayboard(board1,a,b,c,d);
		 y=y+1;
		 i=i+1;
		 }
		 else
		 {
			 cout<<" In check ";
		
			 if (stalemate(smate)==false)
			 {
				 cout<<"Game ends ";
				 flag=1;
			 }
		 
		 }
		 
		 
		 }
	 }


	 if(player1win(board1)==true)
		 cout<<"Player 1 win";
	 if(player2win(board1)==true)
		 cout<<"Player 2 win";

	 cout<<endl<<endl;
	 cout<<"are you want to watch replay press 1 else 2";
	 int replay1;
	 cin>>replay1;
	 if(replay1==1)
	 {
	 system("cls");
	 reset1(board2);
	 j=0;
	 while(j<i-1)
	 {
		 r1=sx[j];r2=sy[j];r3=tx[j];r4=ty[j];
		 replay(board2,r1,r2,r3,r4);
		 j=j+1;
	    Sleep(1000);
		
		 system("cls");
	 
	 
	 }
	 }

	 


}
