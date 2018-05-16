#include<iostream>
#include<string>
using namespace std;
struct node
{
	int parent;
	int left;
	int right;
	int num;
	int a[10001];
};  //待初始化
node tree[10001];
int num_d;    //d个数
int num_u;    //u个数
int olength;  //原深度
int clength;  //现深度
int nodecounter; //节点数更新
int current;     //当前节点
string s;    //输入字符串
void initialize(void);
void store(void);
void dfs(int position,int height);
int main(void)
{
	int counter=0;
	getline(cin,s);
	while(s[0]!='#')
	{
		counter++;
		initialize();
		store();
		cout<<"Tree "<<counter<<": "<<olength<<" => "<<clength<<endl;
		getline(cin,s);
	}
}
void initialize(void)
{
	num_d=num_u=olength=clength=0;
	nodecounter=0;
	current=0;
}
void store(void)
{
	tree[0].num=tree[0].left=tree[0].right=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='u')
		{
			current=tree[current].parent;
			num_u++;
		}
		else
		{
			nodecounter++;  //节点数更新
			tree[nodecounter].num=tree[nodecounter].left=tree[nodecounter].right=0; //初始化
			tree[nodecounter].parent=current;
			tree[current].num++;    //父节点子数更新
			tree[current].a[tree[current].num]=nodecounter;  //父节点链接更新
			current=nodecounter; //当前节点更新
			num_d++;
		}
		olength=max(olength,num_d-num_u);
	}
	for(int i=0;i<=nodecounter;i++)
	{
		if(tree[i].num==0)
			continue;
		tree[i].left=tree[i].a[1];
		for(int j=1;j<tree[i].num;j++)
			tree[tree[i].a[j]].right=tree[i].a[j+1];
	}
	dfs(0,0);
}
void dfs(int position,int height)
{
	clength=max(clength,height);
	if(tree[position].left!=0)
		dfs(tree[position].left,height+1);
	if(tree[position].right!=0)
		dfs(tree[position].right,height+1);
}

