#include<iostream>
#include<stdio.h>
using namespace std;

void print(int arr[][7]);
void interface(int arr[][7]);
void position_X_O(int arr[][7],char [],char[]);
int win(int arr[][7]);

int main()
{
	int t[7][7],pos;
	char p1[20],p2[20],play_again='y';
	while(play_again=='y'|play_again=='Y')
	{
		cout<<"enter player 1 name : ";
		gets(p1);
		cout<<"enter player 2 name : ";
		gets(p2);
		cout<<p1<<" has 0 and "<<p2<<" has X\n";
		interface(t);
		position_X_O(t,p1,p2);
		cout<<"\nWant to play again(y/n) : ";
		cin>>play_again;
	}
	return 0;
}

void position_X_O(int t[][7],char p1[],char p2[])	
{
	int w=0,c=0,pos,flag=0;
	while((w!=1)&(w!=2)&(c!=9))
	{
		c++;
		if(c%2)
		{
			cout<<p1<<"'s turn\n";
			cout<<"enter the position at which you want to insert 0\n";
		}
		else
		{
			cout<<p2<<"'s turn\n";
			cout<<"enter the position at which you want to insert X\n";
		}
		cin>>pos;
		while(flag==0)
		{
			for(int i=0;i<7;i++)
			{
				for(int j=0;j<7;j++)
				{
					if(t[i][j]==pos)
						flag=1;
				}
			}
			if(flag==0)
			{
				cout<<"position not available\nEnter another position : ";
				cin>>pos;
			}
		}
		flag=0;
		for(int i=0;i<7;i++)
		{
			for(int j=0;j<7;j++)
			{
				if(t[i][j]==pos)
				{
					if(c%2==0)
						t[i][j]='X';
					else
						t[i][j]=0;
					break;
				}
			}
		}
		print(t);
		if(c>=5)
		{
			w=win(t);
		}
		if(w==1)
		{
			puts(p1);
			cout<<" win";
		}
		else if(w==2)
		{
			puts(p2);
			cout<<" win";
		}
	}
	if(c==9&&w!=1&&w!=2)
		cout<<"game draw";
}

int win(int t[][7])
{
	if(t[1][1]==t[1][3]&&t[1][1]==t[1][5])
	{
		if(t[1][1]==0)
			return 1;
		else
			return 2;
	}
	if(t[3][1]==t[3][3]&&t[3][1]==t[3][5])
	{
		if(t[3][1]==0)
			return 1;
		else
			return 2;
	}
	if(t[5][1]==t[5][3]&&t[5][1]==t[5][5])
	{
		if(t[5][1]==0)
			return 1;
		else
			return 2;
	}
	if(t[5][1]==t[3][3]&&t[5][1]==t[1][5])
	{
		if(t[5][1]==0)
			return 1;
		else
			return 2;
	}
	if(t[1][1]==t[3][3]&&t[1][1]==t[5][5])
	{
		if(t[1][1]==0)
			return 1;
		else
			return 2;
	}
	if(t[1][1]==t[3][1]&&t[1][1]==t[5][1])
	{
		if(t[1][1]==0)
			return 1;
		else
			return 2;
	}
	if(t[1][3]==t[3][3]&&t[1][3]==t[5][3])
	{
		if(t[1][3]==0)
			return 1;
		else
			return 2;
	}
	if(t[1][5]==t[3][5]&&t[1][5]==t[5][5])
	{
		if(t[1][5]==0)
			return 1;
		else
			return 2;
	}
}

void interface(int t[][7])
{
	int i,j,a=1;
	for(i=0;i<7;i++)
	{
		for(j=0;j<7;j++)
		{
			if(i%2==0)
			{
				t[i][j]='-';
			}
			else
			{
				if(j%2==0)
					t[i][j]='|';
				else
				{
					t[i][j]=a;
					a++;
				}
			}
		}
	}
	print(t);
}
void print(int t[][7])
{
	int i,j;
	for(i=0;i<7;i++)
	{
		for(j=0;j<7;j++)
		{
			if(i%2==0)
			{
				cout<<char(t[i][j]);
			}
			else
			{
				if(j%2==0)
					cout<<char(t[i][j]);
				else
				{
					if(t[i][j]==88)
						cout<<char(t[i][j]);
					else
						cout<<t[i][j];
				}
			}
		}
		cout<<"\n";
	}
}
