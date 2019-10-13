/*
Created by Ezgi Kotan.
C++ program that helps the user to solve the N-Puzzle problem
*/
#include <iostream>
#include <ctime> // For time()
#include <cstdlib>  // For srand() and rand() 
#include <iomanip>
#include <algorithm> //shufftle
using namespace std;
int main()
{
	int size;
	char move,guessMove;
	cout<< "Please enter the problem size" << endl;
	cin>>size;
	cout<< "Your initial random board is" << endl;

	//variable
	int table[size][size]; //main array
	int Goalstate[size][size]; //expected
	//intellegent moves arrays
	int left[size][size]; 
	int right[size][size];
	int up[size][size];
	int down[size][size];

	int start=1,tempLeft,tempRight,tempUp,tempDown,wrongLeft=0,wrongRight=0,wrongUp=0,wrongDown=0;
	int rnum=0, indexRow=0 , indexColumn =0,temp=0,count=0,sayac=0;
	bool flag,flagSayac;
	int wrongNumber=0;
	
	srand(time(0));  // Initialize random number generator. 
	rnum = ( rand() % (size*size) ) + 1;
	table [0][0] = rnum;
	
	//GENERATION STATE NUMBER
	for(int a=0; a<size; a++)//row	
	{ 
		for(int b=0; b<size; b++)//column	
		{ 

			Goalstate[a][b]=start;
			start=start+1;
		}
	}

	//GENERATION RANDOM NUMBER 
	for(int r=0; r<size; r++)//row	
	{ 
		for(int c=0; c<size; c++)//column	
		{ 
			do
			{
				rnum = (rand() % (size*size)) + 1;
				flag=true;
				for(int i=0; i<size; i++)//row
				{
					for(int k=0; k<size ; k++)//column
					{
						if(rnum==table[i][k])
						{
							flag=false;
							break;
						}
					}
				}

			}while(!flag);

			table[r][c]=rnum;
		}
	}
	//screen output was made to look smooth
	if(size==3)
	{
		for(int r=0; r<size; r++)//row	
		{ 
			for(int c=0; c<size; c++) //column 
			{ 
				if(table[r][c]==(size*size))
				{
					cout << '*' << ' ';
					indexRow=r;
					indexColumn=c;
				}
				else
				cout << table[r][c] << ' '; //display table	 
			}
			cout << endl;
		}   
	}
	else
	{	
		for(int r=0; r<size; r++)//row	
		{ 
			for(int c=0; c<size; c++) //column
			{ 
				if(table[r][c]==(size*size))
				{
					cout << '*' << ' ' << ' ';
					indexRow=r;
					indexColumn=c;
				}
				else if(table[r][c]<10)
				cout << table[r][c] << ' '<<' ' ;	
				else	
				cout << table[r][c] << ' '; //display table
			}
			cout << endl;
		}   
	}
	
	cout<< "Your move: ";
	cin>> move;
	cout<<move<< endl;
	while ( move!='q' && move!='Q')  // quit if move is Q
	{
		wrongLeft=0;
		wrongRight=0;
		wrongDown=0;
		wrongUp=0;
		if(move=='L' || move=='l') // if move left
		{
			if(indexColumn==0) //will not go left
			{
				cout<<"Can't move left\n";
			}
			else // move left
			{
				temp= table[indexRow][indexColumn];
				table[indexRow][indexColumn] = table[indexRow][indexColumn-1];
				table[indexRow][indexColumn-1]=temp;
			}
			if(size==3)
			{
				for(int r=0; r<size; r++)//row	
				{ 
					for(int c=0; c<size; c++) //column 
					{ 
						if(table[r][c]==(size*size))
						{
							cout << '*' << ' ';
							indexRow=r;
							indexColumn=c;
						}
						else
						cout << table[r][c] << ' '; //display table	 
					}
					cout << endl;
				}   
			}
			else
			{	
				for(int r=0; r<size; r++)//row	
				{ 
					for(int c=0; c<size; c++) //column
					{ 
						if(table[r][c]==(size*size))
						{
							cout << '*' << ' ' << ' ';
							indexRow=r;
							indexColumn=c;
						}
						else if(table[r][c]<10)
						cout << table[r][c] << ' '<<' ' ;	
						else	
						cout << table[r][c] << ' '; //display table
					}
					cout << endl;
				}   
			}
			++count;

		}
		else if(move=='R' || move=='r') // if move is right
		{
			if(indexColumn==size-1) // will not go right
			{
				cout<<"Can't move right\n";
			}
			else
			{
				temp= table[indexRow][indexColumn];
				table[indexRow][indexColumn] = table[indexRow][indexColumn+1];
				table[indexRow][indexColumn+1]=temp;
			}
			if(size==3)
			{
				for(int r=0; r<size; r++)//row	
				{ 
					for(int c=0; c<size; c++) //column 
					{ 
						if(table[r][c]==(size*size))
						{
							cout << '*' << ' ';
							indexRow=r;
							indexColumn=c;
						}
						else
						cout << table[r][c] << ' '; //display table	 
					}
					cout << endl;
				}   
			}
			else
			{	
				for(int r=0; r<size; r++)//row	
				{ 
					for(int c=0; c<size; c++) //column
					{ 
						if(table[r][c]==(size*size))
						{
							cout << '*' << ' ' << ' ';
							indexRow=r;
							indexColumn=c;
						}
						else if(table[r][c]<10)
						cout << table[r][c] << ' '<<' ' ;	
						else	
						cout << table[r][c] << ' '; //display table
					}
					cout << endl;
				}   
			}
			++count;
		}
		else if(move=='U' || move=='u') // if move is up
		{
			if(indexRow==0) //will not go up
			{
				cout<<"Can't move up\n";
			}
			else
			{
				temp= table[indexRow][indexColumn];
				table[indexRow][indexColumn] = table[indexRow-1][indexColumn];
				table[indexRow-1][indexColumn]=temp;
			}
			if(size==3)
			{
				for(int r=0; r<size; r++)//row	
				{ 
					for(int c=0; c<size; c++) //column 
					{ 
						if(table[r][c]==(size*size))
						{
							cout << '*' << ' ';
							indexRow=r;
							indexColumn=c;
						}
						else
						cout << table[r][c] << ' '; //display table	 
					}
					cout << endl;
				}   
			}
			else
			{	
				for(int r=0; r<size; r++)//row	
				{ 
					for(int c=0; c<size; c++) //column
					{ 
						if(table[r][c]==(size*size))
						{
							cout << '*' << ' ' << ' ';
							indexRow=r;
							indexColumn=c;
						}
						else if(table[r][c]<10)
						cout << table[r][c] << ' '<<' ' ;	
						else	
						cout << table[r][c] << ' '; //display table
					}
					cout << endl;
				}   
			}
			++count;
		}
		else if(move=='D' || move=='d') //if move is down
		{
			if(indexRow==size-1) //will not go down
			{
				cout<<"Can't move down\n";
			}
			else
			{
				temp= table[indexRow][indexColumn];
				table[indexRow][indexColumn] = table[indexRow+1][indexColumn];
				table[indexRow+1][indexColumn]=temp;
			}
			if(size==3)
			{
				for(int r=0; r<size; r++)//row	
				{ 
					for(int c=0; c<size; c++) //column 
					{ 
						if(table[r][c]==(size*size))
						{
							cout << '*' << ' ';
							indexRow=r;
							indexColumn=c;
						}
						else
						cout << table[r][c] << ' '; //display table	 
					}
					cout << endl;
				}   
			}
			else
			{	
				for(int r=0; r<size; r++)//row	
				{ 
					for(int c=0; c<size; c++) //column
					{ 
						if(table[r][c]==(size*size))
						{
							cout << '*' << ' ' << ' ';
							indexRow=r;
							indexColumn=c;
						}
						else if(table[r][c]<10)
						cout << table[r][c] << ' '<<' ' ;	
						else	
						cout << table[r][c] << ' '; //display table
					}
					cout << endl;
				}   
			}
			++count;
		}
		else if(move=='I' || move=='i') //move is intelligent
		{
			cout<<"Intelligent move chooses ";
			for(int z=0; z<size ; ++z)
			{
				for(int y=0 ;y<size ;++y) //hepsini ayrı ayrı arrayde tuutum ki hangi harekette en az yanlış yer çıkacak
				{
					left[z][y]=table[z][y];
					right[z][y]=table[z][y];
					up[z][y]=table[z][y];
					down[z][y]=table[z][y];
				}
			}
			
			//if done Left 
			if(indexColumn==0)
			{
				wrongLeft=100;
			}
			else
			{
				tempLeft= left[indexRow][indexColumn];
				left[indexRow][indexColumn] = left[indexRow][indexColumn-1];
				left[indexRow][indexColumn-1]=tempLeft;
			}
			//if done right
			if(indexColumn==size-1)
			{
				wrongRight=100;
			}
			else
			{
				tempRight= right[indexRow][indexColumn];
				right[indexRow][indexColumn] = right[indexRow][indexColumn+1];
				right[indexRow][indexColumn+1]=tempRight;
			}
			//if done down
			if(indexRow==size-1)
			{
				wrongDown=100;
			}
			else
			{
				tempDown= down[indexRow][indexColumn];
				down[indexRow][indexColumn] = down[indexRow+1][indexColumn];
				down[indexRow+1][indexColumn]=tempDown;
			}
			//if done up
			if(indexRow==0)
			{
				wrongUp=100;
			}
			else
			{
				tempUp= up[indexRow][indexColumn];
				up[indexRow][indexColumn] = up[indexRow-1][indexColumn];
				up[indexRow-1][indexColumn]=tempUp;
			}
			for(int m=0; m<size; m++)//row	
			{ 
				for(int n=0; n<size; n++)//column	
				{ 
					
					if(wrongLeft != 100 && left[m][n]!=Goalstate[m][n] )
					{
						++wrongLeft;
						if(left[m][n]==size*size)
							wrongLeft=wrongLeft-1;
					}
					if(wrongRight != 100 && right[m][n]!=Goalstate[m][n] )
					{
						++wrongRight;
						if(right[m][n]==size*size)
							wrongRight=wrongRight-1;
					}
					if(wrongDown != 100 && down[m][n]!=Goalstate[m][n] )
					{
						++wrongDown;
						if(down[m][n]==size*size)
							wrongDown=wrongDown-1;
					}
					if(wrongUp != 100 && up[m][n]!=Goalstate[m][n] )
					{
						++wrongUp;
						if(up[m][n]==size*size)
							wrongUp=wrongUp-1;
						
					}
				}
			}
			//hangi harekette en az sayıda yanlış yerde bulunan sayı çıakrsa onu hareket ettireceğim
			if(wrongLeft == wrongRight && wrongLeft == wrongUp && wrongLeft == wrongDown )
			{
				for(int p=0; p<size ; ++p)
				{
					for(int w=0 ;w<size ;++w)
					{
						table[p][w]=left[p][w];
					}
				}
				cout<< "L" << endl;
			}
			else if(wrongLeft < wrongRight && wrongLeft < wrongUp && wrongLeft < wrongDown )
			{
				for(int p=0; p<size ; ++p)
				{
					for(int w=0 ;w<size ;++w)
					{
						table[p][w]=left[p][w];
					}
				}
				cout<< "L" << endl;
			}
			else if(wrongRight < wrongLeft && wrongRight < wrongUp && wrongRight < wrongDown )
			{
				for(int p=0; p<size ; ++p)
				{
					for(int w=0 ;w<size ;++w)
					{
						table[p][w]=right[p][w];
					}
				}
				cout << "R" << endl;
			}
			else if(wrongUp < wrongLeft && wrongUp < wrongRight && wrongUp < wrongDown )
			{
				for(int p=0; p<size ; ++p)
				{
					for(int w=0 ;w<size ;++w)
					{
						table[p][w]=up[p][w];
					}
				}
				cout << "U" << endl;
			}
			else if(wrongDown < wrongLeft && wrongDown < wrongUp && wrongDown < wrongRight )
			{
				for(int p=0; p<size ; ++p)
				{
					for(int w=0 ;w<size ;++w)
					{
						table[p][w]=down[p][w];
					}
				}
				cout << "D" << endl;
			}
			else if(wrongLeft == wrongRight )
			{
				for(int p=0; p<size ; ++p)
				{
					for(int w=0 ;w<size ;++w)
					{
						table[p][w]=left[p][w];
					}
				}
				cout<< "L" << endl;
			}
			else if(wrongLeft == wrongUp)
			{
				for(int p=0; p<size ; ++p)
				{
					for(int w=0 ;w<size ;++w)
					{
						table[p][w]=left[p][w];
					}
				}
				cout<< "L" << endl;
			}
			else if(wrongLeft == wrongDown)
			{
				for(int p=0; p<size ; ++p)
				{
					for(int w=0 ;w<size ;++w)
					{
						table[p][w]=left[p][w];
					}
				}
				cout<< "L" << endl;
			}
			else if(wrongRight == wrongDown)
			{
				for(int p=0; p<size ; ++p)
				{
					for(int w=0 ;w<size ;++w)
					{
						table[p][w]=right[p][w];
					}
				}
				cout << "R" << endl;
			}
			else if(wrongUp == wrongDown)
			{
				for(int p=0; p<size ; ++p)
				{
					for(int w=0 ;w<size ;++w)
					{
						table[p][w]=up[p][w];
					}
				}
				cout << "U" << endl;
			}
			else if(wrongUp == wrongRight)
			{
				for(int p=0; p<size ; ++p)
				{
					for(int w=0 ;w<size ;++w)
					{
						table[p][w]=up[p][w];
					}
				}
				cout << "U" << endl;
			}
			else
				cout<<"error"<<endl;
			if(size==3)
			{
				for(int r=0; r<size; r++)//row	
				{ 
					for(int c=0; c<size; c++) //column 
					{ 
						if(table[r][c]==(size*size))
						{
							cout << '*' << ' ';
							indexRow=r;
							indexColumn=c;
						}
						else
						cout << table[r][c] << ' '; //display table	 
					}
					cout << endl;
				}   
			}
			else
			{	
				for(int r=0; r<size; r++)//row	
				{ 
					for(int c=0; c<size; c++) //column
					{ 
						if(table[r][c]==(size*size))
						{
							cout << '*' << ' ' << ' ';
							indexRow=r;
							indexColumn=c;
						}
						else if(table[r][c]<10)
						cout << table[r][c] << ' '<<' ' ;	
						else	
						cout << table[r][c] << ' '; //display table
					}
					cout << endl;
				}   
			}
			++count;
		}
		else if(move=='S' || move=='s')
		{
			
			random_shuffle(&Goalstate[0][0],&Goalstate[size][size]);
			for(int s=0; s<size ; ++s)
			{
				for(int x=0 ;x<size ;++x)
				{
					table[s][x]==Goalstate[s][x];
				}
			}
			if(size==3)
			{
				for(int r=0; r<size; r++)//row	
				{ 
					for(int c=0; c<size; c++) //column 
					{ 
						if(table[r][c]==(size*size))
						{
							cout << '*' << ' ';
							indexRow=r;
							indexColumn=c;
						}
						else
						cout << table[r][c] << ' '; //display table	 
					}
					cout << endl;
				}   
			}
			else
			{	
				for(int r=0; r<size; r++)//row	
				{ 
					for(int c=0; c<size; c++) //column
					{ 
						if(table[r][c]==(size*size))
						{
							cout << '*' << ' ' << ' ';
							indexRow=r;
							indexColumn=c;
						}
						else if(table[r][c]<10)
						cout << table[r][c] << ' '<<' ' ;	
						else	
						cout << table[r][c] << ' '; //display table
					}
					cout << endl;
				}   
			}

		}
		else
		{
			cout<<"Wrong command , enter again !"<<endl;
		}
		for(int t=0; t<size ; ++t)
		{
			for(int b=0 ;b<size ;++b)
			{
				if(table[t][b]==Goalstate[t][b])
					++sayac;
			}
		}
		if(sayac==size*size)
		{
			cout<<"Problem Solved!"<<endl;
			move='q';
		}
		cout<< "Your move: ";
		cin>> move;

	}

	cout<<"Total number of moves "<<count<<endl;
	return 0;
}
