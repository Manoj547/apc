#include<iostream>
#include<vector>
using namespace std;
struct food
{
	int x,y;
	char val;
}f;
struct snake
{
	int x,y;
	char val;
};
int Points=0;
void printBoard(char board[22][82]);
void createBoard(char board[22][82]);
void eatFood(vector<struct snake>&v,char board[22][82])
{
	board[f.x][f.y]=' ';
	f.x=rand()%20+1;
	f.y=rand()%80+1;
	board[f.x][f.y]='F';
	v.push_back({v[v.size()-1].x,v[v.size()-1].y,'T'});
	v[v.size()-2].val='#';
}
void moveSnake(vector<struct snake>&v,char s,char board[22][82])
{
	int x=v[0].x,y=v[0].y;
	if(s=='w')               // move up
	{		
		if(v[0].x==1)
			v[0].x=20;
		else
			v[0].x-=1;
	}
	else if(s=='s')          // move down
	{
		if(v[0].x==20)
			v[0].x=1;
		else
			v[0].x+=1;
	}
	else if(s=='a')          // move left
	{
		if(v[0].y==1)
			v[0].y=80;
		else
			v[0].y-=1;
	}
	else if(s=='d')         // move right
	{
		if(v[0].y==80)
			v[0].y=1;
		else
			v[0].y+=1;
	}
	if(v[0].x==f.x && v[0].y==f.y)
	{
		eatFood(v,board);
		Points+=10;
	}
	if(v[0].x==v[1].x && v[0].y==v[1].y)
	{
		v[0].x=x;
		v[0].y=y;
	}
	else
	{
		for(int j=v.size();j>1;j--)
		{
			v[j].x=v[j-1].x;
			v[j].y=v[j-1].y;
		}
		v[1].x=x;
		v[1].y=y;
	}
}

void createSnake(char board[22][82])
{
	vector<struct snake>v;
	v.push_back({8,10,'H'});
	v.push_back({8,11,'#'});
	v.push_back({8,12,'#'});
	v.push_back({8,13,'T'});
	for(int i=0;i<v.size();i++)
		board[v[i].x][v[i].y]=v[i].val;
	f.x=4;
	f.y=5;
	f.val='F';
	board[f.x][f.y]=f.val;	
	printBoard(board);
	char s;
	while(true)
	{
		int flag=0;
		cin>>s;
		/*if(!kbhit())
			s=getchar();*/
		system("clear");
		moveSnake(v,s,board);
		for(int i=1;i<v.size();i++)
			if(v[0].x==v[i].x && v[0].y==v[i].y)
			{
				cout<<"Points="<<Points<<endl<<"Game over!"<<endl;
				exit(0);
			}
		createBoard(board);
		for(int i=0;i<v.size();i++)
			board[v[i].x][v[i].y]=v[i].val;
		board[f.x][f.y]=f.val;	
		printBoard(board);
		
	}
}
void createFood(char board[22][82])
{
	f.x=4;
	f.y=5;
	f.val='F';
	board[f.x][f.y]=f.val;
}

void printBoard(char board[22][82])
{
	for(int i=0;i<22;i++)
	{
		for(int j=0;j<82;j++)
			cout<<board[i][j];
		cout<<endl;
	}
	cout<<endl;
}
void createBoard(char board[22][82])
{
	for(int i=0;i<22;i++)
	{
		for(int j=0;j<82;j++)
		{
			if(i==0 || i==21 ||j==81 ||j==0)
				board[i][j]='*';
			else
				board[i][j]=' ';
		}
	}
}
int main()
{
	char board[22][82];	
	createBoard(board);
	createFood(board);
	createSnake(board);	
}

