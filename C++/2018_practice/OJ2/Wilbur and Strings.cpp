#include<iostream>
#include<string>
using namespace std;

int n,m,q;
int table[201][201];
int array[10][3];
string arr[201];
struce node
{
	bool found=true;
	foundnode nodes[4100];
	int node_num;
};

struct foundnode
{
	int n_at;
	int m_at;
};
bool found=false;


void input(void);
void process(string a, int at,int n_at,int m_at);
node find(int a);

int main(void)
{
	input();
	for(int i=1;i<=q;i++)
	{
		process(arr[i]);
	}

}

void input(void)
{
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>table[i][j];
	for(int i=0;i<=9;i++)
		cin>>array[i][1]>>array[i][2];
	for(int i=1;i<=q;i++)
		cin>>arr[i];
	

}

void process(string a)
{
	node tmp;
	tmp=find(int(a[0])-48);
	if(!tmp.found)
	{
		found=false;
		return;
	}
	else
	{

		process2(a,tmp)
		while(counter<=tmp.node_num && !found)
		{
			process2(a,tmp.nodes[counter],at);
			
		}

	}


}


node find(int a)
{
	node tmp;
	tmp.found=false;
	tmp.node_num=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(table[i][j]==a)
			{
				tmp.found=true;
				tmp.nodes.n_at=i;
				tmp.nodes.m_at=j;
				tmp.node_num++;
			}
		}
	return tmp;
}


void process2(string a,foundnode node1,int at)
{
	loopcounter=at;
	foundnode node2;
	node2.n_at=node1.n_at+array[table[node1.n_at][node1.m_at]][1];
	node2.m_at=node1.n_at+array[table[node1.n_at][node1.m_at]][1];

	if(a[loopcounter]==a[loopcounter+1])
	{
		if(loopcounter==a.length()-2)
		{
			found=true;
			return;
		}
		process2(a,node1,at+1);
		process2(a,)
	}
	else
	{

	}
}