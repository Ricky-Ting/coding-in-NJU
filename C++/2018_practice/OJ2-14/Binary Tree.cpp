#include<iostream>
#include<cmath>
#include<string>
using namespace std;

void preorder(int p, bool left, bool root );
void inorder(int c);

char T[128];
string s;
int counter=0;
int h;

int main()
{
	cin>>h;
	getchar();
	cin>>s;
	preorder(1,false,true);
	inorder(1);
}

void preorder(int p, bool left, bool root)
{
	if(root)
	{
		T[1]=s[counter];
		p=1;
	}
	if(2*p>pow(2,h)-1)
		return;
	if(left)
	{
		T[2*p]=s[counter];
		p=2*p;
	}
	else if(!root)
	{
		T[2*p+1]=s[counter];
		p=2*p+1;
	}
	counter++;
	preorder(p,true,false);
	preorder(p,false,false);
}

void inorder(int c)
{
	if(2*c>pow(2,h)-1)
	{
		if(T[c]!='#')
			cout<<T[c];
		return;
	}
	inorder(2*c);
	if(T[c]!='#')
		cout<<T[c];
	inorder(2*c+1);

}