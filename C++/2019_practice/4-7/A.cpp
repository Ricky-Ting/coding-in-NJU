#include <iostream>
#include <algorithm>
#include <assert.h>
#include <cstdio>
#define MAXN 1005
#define MAXE 200100
using namespace std;
int n,m;
struct node{
	int f;
	int t;
	int w;
} edge[MAXE];

int fa[MAXN];

int make_set(int a) {
	fa[a]=a;
	return a;
}

int find_set(int a) {
	if(fa[a]==a)
		return a;
	return fa[a] = find_set(fa[a]);
}

int union_set(int a, int b) {
	int va = find_set(a);
	int vb = find_set(b);
	fa[va] = fa[vb];
	return 1;
}

bool cmp(node a, node b) {
	return a.w<b.w;
}

int main() {
	int ans = 0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) {
		scanf("%d%d%d",&edge[i].f,&edge[i].t,&edge[i].w);
	}
	
	
	for(int i=1; i<=n; i++) {
		make_set(i);
	}

	sort(edge, edge+m, cmp);
	//int cur = 0;
	//int i = 0;
	

	for(int i=0; i<m;) {
		//printf("w=%d\n",edge[i].w);
		int j=i;
		while( edge[j].w == edge[i].w)
			j++;
		//printf("j=%d\n",j);
		for(int k=i; k<j; k++) {
			int a = find_set(edge[k].f);
			int b = find_set(edge[k].t);
			if(a!=b ) {
				ans++;
				//printf("In 1\n");
			}
			//printf("ans =%d \n ",ans);
		}
		for(int k=i; k<j; k++) {
			int a = find_set(edge[k].f);
			int b = find_set(edge[k].t);
			if(a!=b){

				union_set(edge[k].f,edge[k].t);
			

				//printf("In 2\n");
				ans--;
			}

			//printf("ans =%d \n ",ans);
		}
		i = j;

	}
	printf("%d\n",ans);
	return 0;


}