# include<string>
# include<iostream>
# include<math.h>
# include<windows.h>
using namespace std;
void reset(std::string board[8][8])
{
	
	 board[0][0]=" r ";
  board[0][1]=" k ";
  board[0][2]=" b ";
  board[0][3]=" Q ";
  board[0][4]=" K ";
  board[0][5]=" b ";
  board[0][6]=" k ";
  board[0][7]=" r ";
  board[1][0]=" p ";
  board[1][1]=" p ";
  board[1][2]=" p ";
  board[1][3]=" p ";
  board[1][4]=" p ";
  board[1][5]=" p ";
  board[1][6]=" p ";
  board[1][7]=" p ";
  board[2][0]="   ";
  board[2][1]="   ";
  board[2][2]="   ";
  board[2][3]="   ";
  board[2][4]="   ";
  board[2][5]="   ";
  board[2][6]="   ";
  board[2][7]="   ";
  board[3][0]="   ";
  board[3][1]="   ";
  board[3][2]="   ";
  board[3][3]="   ";
  board[3][4]="   ";
  board[3][5]="   ";
  board[3][6]="   ";
  board[3][7]="   ";
  board[4][0]="   ";
  board[4][1]="   ";
  board[4][2]="   ";
  board[4][3]="   ";
  board[4][4]="   ";
  board[4][5]="   ";
  board[4][6]="   ";
  board[4][7]="   ";
  board[5][0]="   ";
  board[5][1]="   ";
  board[5][2]="   ";
  board[5][3]="   ";
  board[5][4]="   ";
  board[5][5]="   ";
  board[5][6]="   ";
  board[5][7]="   ";
  board[6][0]="<p>";
  board[6][1]="<p>";
  board[6][2]="<p>";
  board[6][3]="<p>";
  board[6][4]="<p>";
  board[6][5]="<p>";
  board[6][6]="<p>";
  board[6][7]="<p>";
  board[7][0]="<r>";
  board[7][1]="<k>";
  board[7][2]="<b>";
  board[7][3]="<Q>";
  board[7][4]="<K>";
  board[7][5]="<b>";
  board[7][6]="<k>";
  board[7][7]="<r>";
}
void reset1(std::string board2[8][8])
{
	
	 board2[0][0]=" r ";
  board2[0][1]=" k ";
  board2[0][2]=" b ";
  board2[0][3]=" Q ";
  board2[0][4]=" K ";
  board2[0][5]=" b ";
  board2[0][6]=" k ";
  board2[0][7]=" r ";
  board2[1][0]=" p ";
  board2[1][1]=" p ";
  board2[1][2]=" p ";
  board2[1][3]=" p ";
  board2[1][4]=" p ";
  board2[1][5]=" p ";
  board2[1][6]=" p ";
  board2[1][7]=" p ";
  board2[2][0]="   ";
  board2[2][1]="   ";
  board2[2][2]="   ";
  board2[2][3]="   ";
  board2[2][4]="   ";
  board2[2][5]="   ";
  board2[2][6]="   ";
  board2[2][7]="   ";
  board2[3][0]="   ";
  board2[3][1]="   ";
  board2[3][2]="   ";
  board2[3][3]="   ";
  board2[3][4]="   ";
  board2[3][5]="   ";
  board2[3][6]="   ";
  board2[3][7]="   ";
  board2[4][0]="   ";
  board2[4][1]="   ";
  board2[4][2]="   ";
  board2[4][3]="   ";
  board2[4][4]="   ";
  board2[4][5]="   ";
  board2[4][6]="   ";
  board2[4][7]="   ";
  board2[5][0]="   ";
  board2[5][1]="   ";
  board2[5][2]="   ";
  board2[5][3]="   ";
  board2[5][4]="   ";
  board2[5][5]="   ";
  board2[5][6]="   ";
  board2[5][7]="   ";
  board2[6][0]="<p>";
  board2[6][1]="<p>";
  board2[6][2]="<p>";
  board2[6][3]="<p>";
  board2[6][4]="<p>";
  board2[6][5]="<p>";
  board2[6][6]="<p>";
  board2[6][7]="<p>";
  board2[7][0]="<r>";
  board2[7][1]="<k>";
  board2[7][2]="<b>";
  board2[7][3]="<Q>";
  board2[7][4]="<K>";
  board2[7][5]="<b>";
  board2[7][6]="<k>";
  board2[7][7]="<r>";
}

void moveinput(int & sx,int & sy,int & tx,int & ty,int & p1h1,int & p1h2,int & p2h1,int & p2h2,int & p1k,int &p2k)
{
	cout<<"source input : ";
	cin>>sx>>sy;
	cout<<"Target input : ";
	cin>>tx>>ty;

	if(sx==0 && sy==0)
		p1h1=p1h1+1;
	if(sx==0 && sy==7)
		p1h2=p1h2+1;
	if(sx==7 && sy==0)
		p2h1=p2h1+1;
	if(sx==7&&sy==7)
		p2h2=p2h2+1;
	if(sx==0&&sy==4)
		p1k=p1k+1;
	if(sx==7&&sy==4)
		p2k=p2k+1;
}
//change the board and characters
void displayboard(std::string board[8][8],int a, int b,int c,int d)/////  display board    //////
{
		
  board[c][d]=board[a][b];
 /* if(c>0&&d>0)
  board[a][b]="   ";
  else if(c>0&&d==0)
    board[a][b]="   ";
  else if(c==0&&d>0)
	  board[a][b]="   ";
  else if(c==0&&d==0)
	  board[a][b]=="   ";
	  */
  board[a][b]="   ";
	
		
	for(int i=0;i<8;i++)
	{
		

		for(int j=0;j<8;j++)
		{
			board[i][j];
		}
	}
	cout<<endl;
	cout<<"      0   1   2   3   4   5   6   7"<<endl;
	for(int i=0;i<8;i++)
	{
		
		cout<<"    !---!---!---!---!---!---!---!---!";
		cout<<endl;
		
		cout<<"  "<<i<<" "<<char(179);
		for(int j=0;j<8;j++)
		{
			cout<<board[i][j];
			cout<<char(179);
		}
		cout<<endl;
		cout<<"    "<<char(179);
		for(int j=0;j<8;j++)
		{
			cout<<' '<<' '<<' ';
			cout<<char(179);
		}
		cout<<endl;
		
	}
	
	cout<<"    |---|---|---|---|---|---|---|---|";
	
	}



void castlingdisplayboard(std::string board[8][8])/////  display board    //////
{
		
  
	
		
	for(int i=0;i<8;i++)
	{
		

		for(int j=0;j<8;j++)
		{
			board[i][j];
		}
	}
	cout<<endl;
	cout<<"      0   1   2   3   4   5   6   7"<<endl;
	for(int i=0;i<8;i++)
	{
		
		cout<<"    !---!---!---!---!---!---!---!---!";
		cout<<endl;
		
		cout<<"  "<<i<<" "<<char(179);
		for(int j=0;j<8;j++)
		{
			cout<<board[i][j];
			cout<<char(179);
		}
		cout<<endl;
		cout<<"    "<<char(179);
		for(int j=0;j<8;j++)
		{
			cout<<' '<<' '<<' ';
			cout<<char(179);
		}
		cout<<endl;
		
	}
	
	cout<<"    |---|---|---|---|---|---|---|---|";
	
	}

int playerturn(int &a)
{
	
	if(a%2==0)
		return 0;
	else
		return 1;
	a=a+1;
}

bool validmove(std::string board[8][8],int & sx,int & sy,int & tx,int & ty ,int m)
{
	int j=0;
	string source,target;
	source=board[sx][sy];
	target=board[tx][ty];
	if(m==0) //////for player 1 black pieces
	{
		if((source==" p "||source==" k "||source==" r "||source==" Q "||source==" K "||source==" b " )&&(target=="<p>"||target=="<k>"||target=="<r>"||target=="<Q>"||target=="<K>"||target=="<b>"||target=="   " ))
		
		{
		if(source==" p ")   ////////pawn
		{
		 if(ty==sy && (tx-sx==1||tx-sx==-1) && target=="   ") return true;
          if((ty-sy==1||ty-sy==-1) && (tx-sx==1||tx-sx==-1) && target!= "   "&&target!="   "&&target!=" p "&&target!=" r "&&target!=" Q "&&target!=" k "&&target!=" K "&&target!=" b ") return true;
		  if( sx==1 && (sx-tx==2||sx-tx==-2) && target == "   ") return true;
		  else return false;
		}

		if(source==" k ")////for knight
		{
			 if((tx<8&&tx>=0)&&(ty>=0&&ty<8)||(sx>1&&sx<6&&sy>1&&sy<6)){
					if(((ty-sy==2||ty-sy==-2)&&(tx-sx==1||tx-sx==-1))||((ty-sy==1||ty-sy==-1)&&(target!=" p "&&target!=" r "&&target!=" Q "&&target!=" k "&&target!=" K "&&target!=" b ")))
			      return true;

					else	if(sx>1&&sx<6&&sy>1&&sy<6)
			{
				if(tx==sx+2&&ty==sy+1&&target!=" p "&&target!=" r "&&target!=" Q "&&target!=" k "&&target!=" K "&&target!=" b ")return true;
				else if(tx==sx-2&&ty==sy+1&&target!=" p "&&target!=" r "&&target!=" Q "&&target!=" k "&&target!=" K "&&target!=" b ")return true;
				else if(tx==sx+2&&ty==sy-1&&target!=" p "&&target!=" r "&&target!=" Q "&&target!=" k "&&target!=" K "&&target!=" b ")return true;
				else if(tx==sx-2&&ty==sy-1&&target!=" p "&&target!=" r "&&target!=" Q "&&target!=" k "&&target!=" K "&&target!=" b ")return true;
				else if(ty==sy+2&&tx==sx+1&&target!=" p "&&target!=" r "&&target!=" Q "&&target!=" k "&&target!=" K "&&target!=" b ")return true;
				else if(ty==sy+2&&tx==sx-1&&target!=" p "&&target!=" r "&&target!=" Q "&&target!=" k "&&target!=" K "&&target!=" b ")return true;
				else if(ty==sy-2&&tx==sx+1&&target!=" p "&&target!=" r "&&target!=" Q "&&target!=" k "&&target!=" K "&&target!=" b ")return true;
				else if(ty==sy-2&&tx==sx-1&&target!=" p "&&target!=" r "&&target!=" Q "&&target!=" k "&&target!=" K "&&target!=" b ")return true;
				else return false;
			}
			
				
					else 
						return false;
				}
				else
					return false;
		}
		if(source==" b ")///bishop
		{
			if(abs(tx-sx)==abs(ty-sy))
			{
				if(tx>sx)///downward
				{
					
				if(ty>sy)
				{
				   int i=sx+1,j=sy+1;
				   while(i<tx)
				   {
					   j=sy+1;
					   int w=0;
					   while(j<ty)
					   {
						   int k=i-1,l=j-1;
						   if((i==k+1)&&(j==l+1))
						   {
							   if(board[i][j]!="   ")
							   return false;
							   else
								   return true;
						   }

						   j=j+1;
					   }
					   i=i+1;
				   }
				}
				else if(ty<sy)
				{
					
				   int i=sx+1,j=sy-1;
				   while(i<tx)
				   {
					   j=sy-1;
					   
					   while(j>=ty)
					   {
						   int k=i-1,l=j-1;
						   if((i==k+1)&&(j==l+1))
						   {
							   if(board[i][j]!="   ")
							   return false;
							   else
								   return true;
						   }

						   j=j-1;
					   }
					   i=i+1;
				   }
				}

				}
				else  if(sx>tx)///upward
				   {
					   int i=tx+1,j=ty+1;
				   while(i<sx)
				   {
					   j=ty;
					   while(j<sy)
					   {
						   int k=i-1,l=j-1;

						   if(i==k+1&&j==l+1)
						   {
							   if(board[i][j]!="   ")
							   return false;
							   else
								   return true;
						   }
						   j=j+1;
					   }
					   i=i+1;
				   }
				}
				else if(target=="   "&&target=="<p>"&&target=="<k>"&&target=="<K>"&&target=="<b>"&&target=="<Q>"&&target=="<r>")
					   return true;
				   else
					   return false;
			}
			else
				return false;
		}
		
		if(source==" Q ")
		{
		 if(abs(tx-sx) == abs(ty-sy)){ // Moving diagonally
      if(tx>sx){ // South
        int j = min(ty, sy)+1;/////j for column    i for rows
        for(int i = sx+1; i < (unsigned)tx; ++i){
          if(board[i][j] != "   ") return false;
          j=j+1;
        }
        return true;
      }
      if(tx<sx && ty>sy){ // North
        int j = min(ty, sy)+1;
        for(int i = sx+1; i < (unsigned)tx; ++i){
          if(board[i][j] != "   ") return false;
          j=j+1;
        }
        return true;
      }
    }
    if(tx==sx || ty==sy){ // Moving straight
      if(ty==sy){ // Moving vertically
        if(tx>sx){ // Downards
          for(int i = (unsigned)(sx+1); i < (unsigned)tx; ++i){
            if(board[i][ty] != "   ") return false;
          }
        } else { // Upwards
          for(int i = (unsigned)tx; i < (unsigned)(sx-1); ++i){
            if(board[i][ty] != "   " ) return false;
          }
        }
        return true;
      }
      if(tx==sx){ // Moving horizontally
        if(ty>sy){ // Rightwards
          for(int j = (unsigned)(sy+1); j < (unsigned)tx; ++j){
            if(board[tx][j] != "   ") return false;
          }
        }
        if(ty<sy){ // Leftwards
          for(int j = (unsigned)ty; j < (unsigned)(sy-1); ++j){
            if(board[tx][j] != "   ") return false;
          }
        }
        return true;
      }
    }
    return false;
		}

		if(source==" r ")///rock
		{
			 if(ty==sy){ // Moving vertically
      if(tx>sx){ // Downards
        for(int i = (unsigned)(sx+1); i < (unsigned)tx; ++i){
          if(board[i][ty] != "   ") return false;
        }
      } else { // Upwards
        for(int i = (unsigned)tx; i < (unsigned)(sx-1); ++i){
          if(board[i][ty] != "   ") return false;
        }
      }
      return true;
    }
    if(tx==sx){ // Moving horizontally
      if(ty>sy){ // Rightwards
        for(int j = (unsigned)(sy+1); j < (unsigned)tx; ++j){
          if(board[tx][j] != "   ") return false;
        }
      }
      if(ty<sy){ // Leftwards
        for(int j = (unsigned)ty; j < (unsigned)(sy-1); ++j){
          if(board[tx][j] != "   ") return false;
        }
      }
      return true;
    }
    return false;
		}
		if(source==" K ")///king
		{
			if(((abs(tx-sx))==1||((abs(ty-sy))==1))&&(target=="<p>"||target=="<k>"||target=="<K>"||target=="<b>"||target=="<Q>"||target=="<r>"||target=="   "))
				return true;
			else
				return false;
		}

		}
		else
			return false;
		}
		else///for white
		{
			if(source=="<p>"||source=="<k>"||source=="<r>"||source=="<Q>"||source=="<K>"||source=="<b>" )
			{
			if(source=="<p>")   ////////pawn
		{
			if(sx==6&&tx==5&&sy==ty&&target=="   ")return true;

			else	if(sx==6&&tx==4&&sy==ty&&target=="   ")return true;
			else if(sx>6&&tx<sx-2&&tx<sx&&target=="   ")return true;
			else if(sx>=6&&tx==sx-1&&ty==sy+1&&target!="   "&&target!="<p>"&&target!="<r>"&&target!="<Q>"&&target!="<k>"&&target!="<K>"&&target!="<b>")return true;
			else if(sx>=6&&tx==sx-1&&ty==sy-1&&target!="   "&&target!="<p>"&&target!="<r>"&&target!="<Q>"&&target!="<k>"&&target!="<K>"&&target!="<b>")return true;
			else   if(ty==sy && abs(tx-sx)==1 && target=="   ") return true;
			else if(abs(ty-sy)==1 && abs(tx-sx)==1 && target!= "   ") return true;
			if( sx==6 && abs(sx-tx)==2 && target == "   ") return true;
			else return false;
		}
			if(source=="<k>")///////////knight
			{
				if((abs(tx-sx)==2 && abs(ty-sy)==1) || (abs(ty-sy)==2 && abs(tx-sx)==1)){
                 return true;
    }
			}

			if(source=="<b>")///bishop
			{
		if(target==" p "||target==" k "||target==" K "||target==" b "||target==" Q "||target==" r "||target=="   ")
				{
                 if(abs(tx-sx) == abs(ty-sy)){ // Moving diagonally
          if(tx>sx)//"\"down
		  {
			  j=sy+1;
          for(int i = sx+1; i < tx; i++){
           if(board[i][j] != "   ") return false;
          j=j+1;
        }
        return true;
      }
      if(tx>sx&&ty<sy){ //"/"down
        j=sy-1;
        for(int i = sx+1; i <tx; i++){
          if(board[i][j] != "   ") return false;
          j=j-1;;
        }
        return true;
      }
    }
				 if(tx<sx&&ty>sy)//upward/
	{
	    j=sy+1;
		for(int i=sx-1;i>tx;i--,j++){
			if(board[i][j]!="   ")return false;
			j=j+1;
		}
		return true;
	}

		if(tx<sx&&ty<sy)//upward"\"
		{
	    j=sy-1;
		for(int i=sx-1;i>tx;i--,j--){
			if(board[i][j]!="   ")return false;
			j=j+1;
		}
		return true;
	}

		}		
		else
			return false;
			}
			if(source=="<r>")/////rock
			{

		if(ty==sy){ // Moving vertically
      if(tx>sx){ // Downards
        for(int i = (sx+1); i <tx; ++i){
          if(board[i][ty] != "   ") return false;
        }
      } else { // Upwards
        for(int i = sx-1; i >tx;i--){
          if(board[i][ty] != "   ") return false;
        }
      }
      return true;
    }
    if(tx==sx){ // Moving horizontally
      if(ty>sy){ // Rightwards
        for(int j = sy+1; j < ty; j++){
          if(board[tx][j] != "   ") return false;
        }
      }
      if(ty<sy){ // Leftwards
        for(int j = ty; j >sy; j--){
          if(board[tx][j] != "   ") return false;
        }
      }
      return true;
    }
    return false;
			}

			if(source=="<K>")////king
			{

				if(abs(tx-sx)<=1 && abs(ty-sy)<=1) return true;
				  return false;
			}

			if(source=="<Q>")///queen
			{
				if(target==" p "||target==" k "||target==" K "||target==" b "||target==" Q "||target==" r "||target=="   ")
				{
                 if(abs(tx-sx) == abs(ty-sy)){ // Moving diagonally
          if(tx>sx)//"\"down
		  {
			  j=sy+1;
          for(int i = sx+1; i < tx; i++){
           if(board[i][j] != "   ") return false;
          j=j+1;
        }
        return true;
      }
      if(tx>sx&&ty<sy){ //"/"down
        j=sy-1;
        for(int i = sx+1; i <tx; i++){
          if(board[i][j] != "   ") return false;
          j=j-1;;
        }
        return true;
      }
    }
    if(tx==sx || ty==sy){ // Moving straight
      if(ty==sy){ // Moving vertically
        if(tx>sx){ // Downards
          for(int i = (sx+1); i <tx; i++){
            if(board[i][ty] != "   ") return false;
          }
        } else { // Upwards
          for(int i = tx; i < sx-1; i++){
            if(board[i][ty] != "   ") return false ;
          }
        }
        return true;
      }
       // Moving horizontally
        if(ty>sy){ // Rightwards
          for(int j = sy+1; j < ty; j++){
            if(board[tx][j] != "   ") return false;
          }
        }
        if(ty<sy){ // Leftwards
          for(int j =ty-1; j > sy; j--){
            if(board[tx][j] != "   ") return false;
          }
        }
        return true;
      
    }
	if(tx<sx&&ty>sy)//upward/
	{
	    j=sy+1;
		for(int i=sx-1;i>tx;i--,j++){
			if(board[i][j]!="   ")return false;
			j=j+1;
		}
		return true;
	}

		if(tx<sx&&ty<sy)//upward"\"
		{
	    j=sy-1;
		for(int i=sx-1;i>tx;i--,j--){
			if(board[i][j]!="   ")return false;
			j=j+1;
		}
		return true;
	}
    return false;

			}
				
			
				else
					return false;
			}
			}
				}
			
	}
	bool player1win(std::string board[8][8])
	{
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				if(board[i][j]=="<K>")
					return false;
			}
		}
		return true;
	
	}

	bool player2win(std::string board[8][8])
	{
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				if(board[i][j]==" K ")
					return false;
			}
		}
		return true;
	
	}
	void replay(std::string board2[8][8],int &sx1, int &sy1,int &tx1,int &ty1)
	{
		 board2[tx1][ty1]=board2[sx1][sy1];
  
  board2[sx1][sy1]="   ";
  
   

	
		
	for(int i=0;i<8;i++)
	{
		

		for(int j=0;j<8;j++)
		{
			board2[i][j];
		}
	}
	cout<<endl;
	cout<<"      0   1   2   3   4   5   6   7"<<endl;
	for(int i=0;i<8;i++)
	{
		
		cout<<"    !---!---!---!---!---!---!---!---!";
		cout<<endl;
		
		cout<<"  "<<i<<" "<<char(179);
		for(int j=0;j<8;j++)
		{
			cout<<board2[i][j];
			cout<<char(179);
		}
		cout<<endl;
		cout<<"    "<<char(179);
		for(int j=0;j<8;j++)
		{
			cout<<' '<<' '<<' ';
			cout<<char(179);
		}
		cout<<endl;
		
	}
	
	cout<<"    |---|---|---|---|---|---|---|---|";
	
	}
	void castling1(std::string board[8][8],int & p1h1,int & p1h2,int & p2h1,int & p2h2,int & p1k,int & p2k)
	{
		int a=0,b=0;
		if(p1k==0)
		{
			cout<<"Enter position of rock :";
		    cin>>a>>b;
			if(a==0&&b==0)
			{
				if(p1h1==0)
				{
					if(board[0][1]=="   "&&board[0][2]=="   "&&board[0][3]=="   ")
					{
						board[0][0]="   ";
						board[0][3]=" r ";
						board[0][2]=" K ";
						board[0][4]="   ";

					}
					else
						cout<<"you are not in state for doing castling ";

				}
			
				else
						cout<<"you are not in state for doing castling ";
			}
			if(a==0&&b==7)
			{
				if(p1h2==0)
				{
					if(board[0][5]=="   "&&board[0][6]=="   ")
					{
						board[0][4]="   ";
						board[0][5]=" r ";
						board[0][6]=" K ";
						board[0][7]="   ";

					}
					else
						cout<<"you are not in state for doing castling ";

				}
			
				else
						cout<<"you are not in state for doing castling ";
			}

		}
		else
			cout<<"you are not in state for doing castling ";
		}

	void castling2(std::string board[8][8],int & p2h1,int & p2h2,int & p2k)
	{

		int a=0,b=0;
		if(p2k==0)
		{
			cout<<"Enter position of horse :";
		    cin>>a>>b;
			if(a==7&&b==0)
			{
				if(p2h1==0)
				{
					if(board[7][1]=="   "&&board[7][2]=="   " && board[7][3]=="   ")
					{
						board[7][0]="   ";
						board[7][3]="<r>";
						board[7][2]="<K>";
						board[7][4]="   ";

					}
					else
						cout<<"you are not in state for doing castling ";

				}
			
				else
						cout<<"you are not in state for doing castling ";
			}
			if(a==7&&b==7)
			{
				if(p2h2==0)
				{
					if(board[7][5]=="   "&&board[7][6]=="   ")
					{
						board[7][4]="   ";
						board[7][5]="<r>";
						board[7][6]="<K>";
						board[7][7]="   ";

					}
					else
						cout<<"you are not in state for doing castling ";

				}
			
				else
						cout<<"you are not in state for doing castling ";
			}

		}
		else
			cout<<"you are not in state for doing castling ";
	
	}
	bool check1(std::string board[8][8])
	{
		int x1=0,y1=0,x2=0,y2=0;//// x for row  y for column
		int flag=0,c=0,a=0,b=0,x=0,y=0;

		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				if(board[i][j]==" K ")
				{
					x1=i;
					y1=j;
			}
		}
		}
		for(int a=y1+1;a<8;a++)////horizontal right
		{
			
			if((board[x1][a]=="<Q>")||(board[x1][a]=="<r>"))
			{
				for(int b=y1+1;b<a&&flag==0;b++)///for checking space
				{
					if(board[x1][b]=="   ")
						flag=0;
					else
						flag=1;
				}
			if(flag==0)
			return false;
			}
		}

		for(int a=y1-1;a>=0;a--)///left horizontal 
		{
			if((board[x1][a]=="<Q>")||(board[x1][a]=="<r>"))
			{
				for(int b=y1-1;b>a&&flag==0;b--)
				{
					if(board[x1][b]=="   ")
						flag=0;
					else
						flag=1;
				}
				if(flag==0)
				return false;
			}
		}

		for(int a=x1+1;a<8;a++)
		{
			if((board[a][y1]=="<Q>")||(board[a][y1]=="<r>"))///down
			{
				for(int b=x1+1;b<a&&flag==0;b++)
				{
					if(board[b][y1]=="   ")
						flag=0;
					else
						flag=1;
				}
				if(flag==0)
				return false;
		}
		}
		for(int a=x1-1;a>=0;a--)
		{
			if((board[a][y1]=="<Q>")||(board[a][y1]=="<r>"))///up
			{
				for(int b=x1-1;b>a&&flag==0;b--)
				{
					if(board[b][y1]=="   ")
						flag=0;
					else
						flag=1;
				}
				if(flag==0)
				return false;
		}
		}
		 x=x1+1;
		for(int b=y1+1;x<8&&b<8;x++,b++)///for"\" down
		{
			int x2=x+1,y2=b+1;
			if((x2-x)==(y2-b))
			{
				if((board[x][b]=="<Q>")||(board[x][b]=="<b>"))
				{
				   	int c=x1+1;
					for(int d=y1+1;c<x,d<b&&flag==0;c++,d++)
					{
						if(board[c][d]=="   ")
							flag=0;
						else
							flag=1;

					}
					if(flag==0)
					return false;
			}
			}

		}
		 x=x1+1;
		for(int b=y1-1;x<8&&b>=0;x++,b--)//down /
		{
			 x2=x+1;y2=b-1;
			if((x2-x)==(b-y2))
			{
				if((board[x][b]=="<Q>")||(board[x][b]=="<b>"))
				{
					c=x1+1;
					for(int d=y1-1;c<x,d>b&&flag==0;c++,d--)
					{
						if(board[c][d]=="   ")
							flag=0;
						else
							flag=1;
					}
					if(flag==0)
					return false;
				}
			}
		}
		a=x1-1;
		for(int b=y1-1;a>=0&&b>=0;a--,b--)//up
		{
			 x2=a-1;y2=b-1;
			if((a-x2)==(b-y2))
			{
			if(board[a][b]=="<b>"||board[a][b]=="<Q>")
			{
				x=x1-1;
				for(int y=y1-1;x>a&&y>b&&flag==0;x--,y--)
				{
					if(board[x][y]=="   ")
						flag=0;
					else
						flag=1;
				}
				if(flag==0)
					return false;
			}
			}
		}
		x=x1+1;
		y=y1+1;
		if(x1> 0&& x1<7 && y1>0 && y1<7)
		{
			if((board[x][y]=="<p>")||(board[x][y-2]=="<p>")||(board[x][y]=="<K>")||(board[x-2][y-2]=="<K>")||(board[x-1][y]=="<K>")||(board[x][y-1]=="<K>")||(board[x][y-2]=="<K>")||(board[x-1][y-2]=="<K>")||(board[x-2][y-1]=="<K>")||(board[x-2][y]=="<K>"))

			return false;
		}
		else if(x1==0&&y1==0)
		{
			if(board[x][y]=="<p>"||board[x][y-1]=="<K>"||board[x-1][y]=="<K>"||board[x][y]=="<K>")
				return false;
		}
		else if(x1==0&&y1==7)
		{
			if(board[x][y-2]=="<p>"||board[x-1][y-2]=="<K>"||board[x][y-2]=="<K>"||board[x][y-1]=="<K>")
				return false;

		}
		else if(x1==7&&y1==0)
		{
			if(board[x-2][y-1]=="<K>"||board[x-2][y]=="<K>"||board[x-1][y]=="<K>")
				return false;

		}
		else if(x1==7&&y1==7)
		{
			if(board[x-2][y-2]=="<K>"||board[x-1][y-2]=="<K>"||board[x-2][y-1]=="<K>")
				return false;

		}
		else if(x1==0&&y1>0&&y1<7)
		{
			if(board[x][y]=="<p>"||board[x][y-2]=="<p>"||board[x][y]=="<K>"||board[x][y-1]=="<K>"||board[x-1][y-2]=="<K>"||board[x][y-1]=="<K>"||board[x-1][y]=="<K>")
				return false;
		}
		else if(x1==7&&y1>0&&y1<7)
		{
			if(board[x-1][y]=="<K>"||board[x-1][y-2]=="<K>"||board[x-2][y-2]=="<K>"||board[x-2][y-1]=="<K>"||board[x-2][y]=="<K>")
				return false;
		}
		else if(y1==0&&x1>0&&x1<7)
		{
			if(board[x-1][y]=="<K>"||board[x][y]=="<K>"||board[x-2][y]=="<K>"||board[x][y-1]=="<K>"||board[x-2][y-1]=="<K>"||board[x][y]=="<p>")
				return false;
		}
		else if(y1==7&&x1>0&&x1<7)
		{
			if(board[x-2][y-1]=="<K>"||board[x-2][y-2]=="<K>"||board[x-1][y-2]=="<K>"||board[x][y-2]=="<K>"||board[x][y-1]=="<K>"||board[x][y-2]=="<p>")
				return false;
		}
		x=x1;y=y1;
		if(x>1&&x<6&&y>1&&y<6)
		if(board[x-2][y-1]=="<k>"||board[x-2][y+1]=="<k>"||board[x-1][y-2]=="<k>"||board[x-1][y+2]=="<k>"||board[x+1][y-2]=="<k>"||board[x+1][y+2]=="<k>"||board[x+2][y-1]=="<k>"||board[x+2][y+1]=="<k>")
		{
			return false;
		}
		///////// horse remaining check//////


		
		return true;
	
	}
	
	void ggg (std::string board[8][8],int p1,int p2,int d1,int d2,int player)
	{
		if(player==1 && board[p1][p2]==" p " && d1==7  )
		{
			system("cls");
			cout<<"Make your choice"<<endl;
			cout<<"1 for queen"<<endl;
			cout<<"2 for rook"<<endl;
			cout<<"3 for bisup"<<endl;
			cout<<"4 for knight"<<endl;

		}
		if(player==2 && board[p1][p2]=="<p>" && d1==0  )
		{
			system("cls");
			cout<<"Make your choice"<<endl;
			cout<<"1 for queen"<<endl;
			cout<<"2 for rook"<<endl;
			cout<<"3 for bisup"<<endl;
			cout<<"4 for knight"<<endl;

		}

		int i;

		cin>>i;
		//  player 1
		 if (i==1 && player == 1)
		{
			board[p1][p2]='Q';
		}
	
		 if (i==2 && player == 1)
		{
			board[p1][p2]='R';
		}
		 if (i==3 && player == 1)
		{
			board[p1][p2]='B';
		}
		 if (i==4 && player == 1)
		{
			board[p1][p2]='K';
		}
		// player 2
		 if (i==1 && player == 2)
		{
			board[p1][p2]='Q';
		}
	 if (i==1 && player == 2)
		{
			board[p1][p2]='R';
		 }
		 if (i==1 && player == 2)
		{
			board[p1][p2]='B';
		 }
		 if (i==1 && player == 2)
		{
			board[p1][p2]='K';
		
		 }
	
	
	
	}

	void checkboard(std::string board[8][8],int a,int b,int c,int d)
	{
		board[c][d]=board[a][b];
		board[a][b]="   ";
	}
	void checkboardundo(std::string board[8][8],int a,int b,int c,int d)
	{
		board[a][b]=board[c][d];
		board[c][d]="   ";
		
	}

	bool check2(std::string board[8][8])
	{
		int x1=0,y1=0,y=0,flag=0,x=0,a=0,c=0,x2=0,y2=0;

		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				if(board[i][j]=="<K>")
				{
					x1=i;
					y1=j;
				}
			}
		}
		y=y1;
		for(int x=x1-1;x>=0;x--)/////for up
		{
			if(board[x][y]==" Q "||board[x][y]==" r ")
			{
				for(int b=x1-1;b>x&&flag==0;b--)
				{
					if(board[b][y]=="   ")
						flag=0;
					else
						flag=1;
				}
				if(flag==0)
					return false;
			}
		}
		y=y1;
		for(int x=x1+1;x<=7;x++)///down
		{
			if(board[x][y]==" Q "||board[x][y]==" r ")
			{
				for(int b=x1+1;b<x&&flag==0;b++)
				{
					if(board[b][y]=="   ")
						flag=0;
					else
						flag=1;
				}
				if(flag==0)
					return false;
			}
		}
		x=x1;
		for(int y=y1+1;y<8;y++)//right
		{
			if(board[x][y]==" Q "||board[x][y]==" r ")
			{
				for(int b=y1+1;b<8&&flag==0;b++)
				{
					if(board[x][b]=="   ")
						flag=0;
					else
						flag=1;
				}
				if(flag==0)
					return false;
			}
		}
		x=x1;
		for(int y=y1-1;y>=0;y--)//for left
		{
			if(board[x][y]==" Q "||board[x][y]==" r ")
			{
				for(int b=y1-1;b>y&&flag==0;b--)
				{
					if(board[x][b]=="   ")
						flag==0;
					else
						flag=1;
				}
				if(flag==0)
					return false;
			}
		}
		x=x1-1;
		for(int y=y1+1;y<8&&x>=0;x--,y++)///up "/"
		{
			if(board[x][y]==" Q "||board[x][y]==" b ")
			{
				a=x1-1;
				for(int b=y1+1;a>x,b<y&&flag==0;b++,a--)
				{
					if(board[a][b]=="   ")
						flag=0;
					else
						flag=1;
				}
				if(flag==0)
					return false;
			}
		}
			x=x1-1;
		for(int y=y1-1;y>=0&&x>=0;x--,y--)/// up"\"
		{
			
			if(board[x][y]==" Q "||board[x][y]==" b ")
			{
				a=x1-1;
				for(int b=y1-1;a>x&&flag==0;b--,a--)
				{
					if(board[a][b]=="   ")
						flag=0;
					else
						flag=1;
				}
				if(flag==0)
					return false;
			}
		
		}
		///////////////////////////////

		x=x1+1;
		y=y1+1;
		if(x1>0&&x1<7&&y1>0&&y1<7)
		{
			if((board[x-2][y]==" p ")||(board[x-2][y-2]==" K ")||(board[x-2][y-2]==" K ")||(board[x-1][y]==" K ")||(board[x][y-1]==" K ")||(board[x][y-2]==" K ")||(board[x-1][y-2]==" K ")||(board[x-2][y-1]==" K ")||(board[x-2][y]==" K "))

			return false;
		}
		else if(x1==0&&y1==0)
		{
			if(board[x][y-1]==" K "||board[x-1][y]==" K "||board[x][y]==" K ")
				return false;
		}
		else if(x1==0&&y1==7)
		{
			if(board[x-1][y-2]==" K "||board[x][y-2]==" K "||board[x][y-1]==" K ")
				return false;

		}
		else if(x1==7&&y1==0)
		{
			if(board[x-2][y-1]==" K "||board[x-2][y]==" K "||board[x-1][y]==" K ")
				return false;

		}
		else if(x1==7&&y1==7)
		{
			if(board[x-2][y-2]==" K "||board[x-1][y-2]==" K "||board[x-2][y-1]==" K ")
				return false;

		}
		else if(x1==0&&y1>0&&y1<7)
		{
			if(board[x][y]==" K "||board[x][y-1]==" K "||board[x-1][y-2]==" K "||board[x][y-1]==" K "||board[x-1][y]==" K ")
				return false;
		}
		else if(x1==7&&y1>0&&y1<7)
		{
			if(board[x-1][y]==" K "||board[x-1][y-2]==" K "||board[x-2][y-2]==" K "||board[x-2][y-1]==" K "||board[x-2][y]==" K ")
				return false;
		}
		else if(y1==0&&x1>0&&x1<7)
		{
			if(board[x-1][y]==" K "||board[x][y]==" K "||board[x-2][y]==" K "||board[x][y-1]==" K "||board[x-2][y-1]==" K ")
				return false;
		}
		else if(y1==7&&x1>0&&x1<7)
		{
			if(board[x-2][y-1]==" K "||board[x-2][y-2]==" K "||board[x-1][y-2]==" K "||board[x][y-2]==" K "||board[x][y-1]==" K ")
				return false;
		}
		x=x1;y=y1;
		if(x>1&&x<6&&y>1&&y<6)
		if(board[x-2][y-1]==" k "||board[x-2][y+1]==" k "||board[x-1][y-2]==" k "||board[x-1][y+2]==" k "||board[x+1][y-2]==" k "||board[x+1][y+2]==" k "||board[x+2][y-1]==" k "||board[x+2][y+1]==" k ")
		{
			return false;
		}
		
        ////////////////////////////
		return true;
	
		}
		
bool stalemate(int &i)
{
	i=i+1;
	if(i>2)
	{
		return false;
	}
	else
	{
		return true;
		i=0;
	}
}

