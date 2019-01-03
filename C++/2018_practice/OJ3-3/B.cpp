#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,m;
int fa[100003];
struct node {
	int start;
	int end;
	int width;
}edges[200007];

void make_Set(int i) {
	fa[i]=i;
}

int Find_Set(int i) {
	if(fa[i]==i)
		return i;
	return fa[i]=Find_Set(fa[i]);

}

void Union_Set(int a, int b) {
	a=Find_Set(a);
	b=Find_Set(b);
	if(a==b)
		return;
	fa[b]=a;
}

bool Same_Set(int a, int b) {
	return Find_Set(a)==Find_Set(b);
}

bool cmp(node a, node b) {
	return a.width<b.width;
}

int main(void) {
	int x,y;
	int res=0;
	scanf("%d%d%d",&n,&k,&m);
	int cnt=n;
	for(int i=0;i<n;i++)
		make_Set(i);
	for(int i=0;i<k;i++) {
		scanf("%d%d",&x,&y);
		if(!Same_Set(x,y)) {
			cnt--;
			Union_Set(x,y);
		}
	}
	printf("%d ",cnt);
	for(int i=0;i<m;i++)
		scanf("%d%d%d",&edges[i].start,&edges[i].end,&edges[i].width);
	sort(edges,edges+m,cmp);
	for(int i=0;i<m;i++){
		if(cnt==1) break;
		if(!Same_Set(edges[i].start,edges[i].end)) {
			Union_Set(edges[i].start,edges[i].end);
			res+=edges[i].width;
			cnt--;
		}
	}
	printf("%d\n",res);
}



