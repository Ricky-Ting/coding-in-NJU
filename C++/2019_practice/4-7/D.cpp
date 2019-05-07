#include <iostream>
#include <algorithm>
#include <assert.h>
#include <cmath>
#include <cstdio>
#define MAXN 550
#define MAXE 500000
using namespace std;

int s,p;
struct node{
	int f;
	int t;
	double w;
} edge[MAXE];

struct vertex{
	int x;
	int y;
} v[MAXN];

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
	int counter = 0;
	scanf("%d%d",&s,&p);
	for(int i=1; i<=p ;i++){
		make_set(i);
		scanf("%d%d",&v[i].x, &v[i].y);
	}
	for(int i=1; i<p ;i++) {
		for(int j=i+1; j<=p; j++) {
			edge[counter].f = i;
			edge[counter].t =j;
			edge[counter].w = sqrt( (v[i].x-v[j].x)*(v[i].x-v[j].x) + (v[i].y-v[j].y)*(v[i].y-v[j].y) );
			counter++;
		}
	}

	sort(edge, edge+counter, cmp);
	int cnt = 0;
	for(int i=0;i<counter; i++) {
		if(find_set(edge[i].f)!=find_set(edge[i].t)) {
            union_set(edge[i].f,edge[i].t);
            cnt++;
        }
        if(cnt == p-s) {
            printf("%.2lf\n",edge[i].w);
            break;
        }
	}


}