#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;


struct node
{
	int x;
	int y;
};

int compare(const void *ele1,const void *ele2)  
{  
    node *node1,*node2;  
    node1=(node*)ele1;  
    node2=(node*)ele2;  
    if(node1->x==node2->x) 
    	return (node1->y - node2->y);  
    return (node1->x - node2->x );  
} 

int searchpath(node node1,int dx, int dy);

bool search(node node1);


int a[5001];
int b[5001];
int R,C;
int n;
node nodes[5001];

int main(void)
{
	int dx,dy,px,py;
	cin>>R>>C;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>nodes[i].x>>nodes[i].y;
	}
	int MAX=2,steps;
	qsort(nodes+1,n,sizeof(node),compare);
	for(int i=1;i<n-1;i++)
		for(int j=i+1;j<n;j++)
		{
			dx=nodes[j].x-nodes[i].x;
			dy=nodes[j].y-nodes[i].y;
			px=nodes[i].x-dx;
			py=nodes[i].y-dy;
			if(px>0 && px<=R && py>0 && py<=C)
				continue;
			if(nodes[i].x+MAX*dx>R)
				break;
			py=nodes[i].y+MAX*dy;
			if(py<1 || py>C)
				continue;
			steps=searchpath(nodes[j],dx,dy);
			MAX=max(MAX,steps);
		}
		if(MAX>2)
			cout<<MAX<<endl;
		else
			cout<<0<<endl;
		return 0;

}

int searchpath(node node1,int dx, int dy)
{
	int steps=2;
	node1.x+=dx;
	node1.y+=dy;
	while(node1.x<=R && node1.x>=1 && node1.y<=C && node1.y>=1)
	{
		if(!search(node1))
		{
			steps=0;
			break;
		}
		node1.x+=dx;
		node1.y+=dy;
		steps++;
	}
	return steps;
}

bool search(node node1)
{
	for(int i=1;i<=n;i++)
		if(nodes[i].x==node1.x && nodes[i].y==node1.y)
			return true;
	return false;
}













