#include<iostream>
#include<queue>
using namespace std;
struct node {
	int l;
	int r;
};

node tree[101];
int n;
int pre[101];
int in[101];
int pos;
queue<int> q1;
queue<int> q2;
void input() {
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&pre[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&in[i]);
	for(int i=0;i<n;i++) 
		tree[i].l=tree[i].r=-1;
	pos=0;
}
int BuildTree(int start,int end) {
	if(start==end) {
		pos++;
		return pre[pos-1];
	}
	int tmp=pre[pos];
	int tmp2;
	for(int i=0;i<n;i++)
		if(in[i]==tmp)
			tmp2=i;
	pos++;
	if(start<=tmp2-1)
		tree[tmp].l=BuildTree(start,tmp2-1);
	if(tmp2+1<=end)
		tree[tmp].r=BuildTree(tmp2+1,end);
	return tmp;
}
void solve() {
	int root=BuildTree(0,n-1);
	q1.push(root); q2.push(1);
	int counter=1;
	while(!q1.empty()) {
		int nd=q1.front(); int depth=q2.front();
		if(depth>counter) {
			counter++;
			printf("\n");
		}
		printf("%d ",nd);
		if(tree[nd].l!=-1) {
			q1.push(tree[nd].l);
			q2.push(depth+1);
		}
		if(tree[nd].r!=-1) {
			q1.push(tree[nd].r);
			q2.push(depth+1);
		}
		q1.pop(); q2.pop();
	}
	printf("\n");
}
int main() {
	input();
	solve();
}