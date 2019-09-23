#include <bits/stdc++.h>
using namespace std;
void print(char a[][3])
{
	cout<<a[0][0]<<"\t|"<<a[0][1]<<"\t|"<<a[0][2]<<"\n";
	cout<<a[1][0]<<"\t|"<<a[1][1]<<"\t|"<<a[1][2]<<"\n";
	cout<<a[2][0]<<"\t|"<<a[2][1]<<"\t|"<<a[2][2]<<"\n";
}
void insert(char t,char h,char a[][3])
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(a[i][j] == t)
				a[i][j] = h;
}
int check(char a[][3])
{
	//rows checking
	if(a[0][0] == 'X' && a[0][1] == 'X' && a[0][2] == 'X' || a[0][0] == '0' && a[0][1] == '0' && a[0][2] == '0')return 1;
	if(a[1][0] == 'X' && a[1][1] == 'X' && a[1][2] == 'X' || a[1][0] == '0' && a[1][1] == '0' && a[1][2] == '0')return 1;
	if(a[2][0] == 'X' && a[2][1] == 'X' && a[2][2] == 'X' || a[2][0] == '0' && a[2][1] == '0' && a[2][2] == '0')return 1;
	//diagonal checking
	if(a[0][0] == 'X' && a[1][1] == 'X' && a[2][2] == 'X' || a[0][0] == '0' && a[1][1] == '0' && a[2][2] == '0')return 1;
	if(a[2][0] == 'X' && a[1][1] == 'X' && a[0][2] == 'X' || a[2][0] == '0' && a[1][1] == '0' && a[0][2] == '0')return 1;
	//columns checking	
	if(a[0][0] == 'X' && a[1][0] == 'X' && a[2][0] == 'X' || a[0][0] == '0' && a[1][0] == '0' && a[2][0] == '0')return 1;
	if(a[0][1] == 'X' && a[1][1] == 'X' && a[2][1] == 'X' || a[0][1] == '0' && a[1][1] == '0' && a[2][1] == '0')return 1;
	if(a[0][2] == 'X' && a[1][2] == 'X' && a[2][2] == 'X' || a[0][2] == '0' && a[1][2] == '0' && a[2][2] == '0')return 1;
	return 0;
}
int main() {
	// your code goes here
	char a[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
	string player1,player2;
	print(a);
	cout<<"Enter name of 1st player(X):";
	cin>>player1;
	cout<<"Enter name of 2nd player(0):";
	cin>>player2;
	int fg = 0,i=9;
	char t;
	while(i!=0)
	{
		if(fg == 0)
			{
				cout<<player1<<" enter index of block";
				cin>>t;	insert(t,'X',a);
				print(a);
				if(check(a) == 1){
						cout<<player1<<" won!!";	break;
					}
				fg = 1;
			}
		else
			{
				cout<<player2<<" enter index of block";
				cin>>t;	insert(t,'0',a);
				print(a);
				if(check(a) == 1){
						cout<<player2<<" won!!";
						break;
					}
				fg = 0;	
			}
			i--;
	}
	if(i == 0)
		cout<<"\nGame is a tie!!";
	return 0;
}