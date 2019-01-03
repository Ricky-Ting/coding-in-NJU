#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node {
	int start;
	int end;
	int distance;
};
int T,n,m;
int fa[30];
int edges[30];
int tmp;
node d[300];
bool cmp(const node &x, const node &y) {
	return x.distance<y.distance;
}


void solve();
void input();
int DFS(int a);

int main(void) {
	scanf("%d",&T);
	for(int i=0;i<T;i++) {
		input();
		solve();
	}
}

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
void input() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
		scanf("%d%d%d",&d[i].start,&d[i].end,&d[i].distance);
}
void solve() {
	sort(d,d+m,cmp);
	int ans=0;
	int cnt=0;
	if(n==0) {
		printf("0\n");
		return;
	}
	for(int i=0;i<n;i++)
		make_Set(i);
	for(int i=0;i<m;i++) {
		if( !Same_Set(d[i].start,d[i].end) ) {
			ans+=d[i].distance;
			Union_Set(d[i].start,d[i].end);
			edges[cnt]=i;
			cnt++;
		}
		if(cnt==n-1)
			break;
	}
	for(int i=0;i<(n-1);i++) {
		tmp=DFS(i);
		if(tmp==ans) {
			printf("Peter can find other ways\n");
			return;
		}
	}
	printf("%d\n",ans);
}

int DFS(int a) {
	int myans=0;
	for(int i=0;i<n;i++)
		make_Set(i);
	int skip=edges[a];
	int cnt=0;
	for(int i=0;i<m;i++) {
		if(i==skip)
			continue;
		if( !Same_Set(d[i].start,d[i].end) ) {
			myans+=d[i].distance;
			Union_Set(d[i].start,d[i].end);
			cnt++;
		}
		if(cnt==n-1)
			break;
	}
	if(cnt!=n-1)
		return -1; 
	return myans;
}
