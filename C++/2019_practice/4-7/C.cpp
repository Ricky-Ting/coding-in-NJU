#include <iostream>
#include <algorithm>
#include <assert.h>
#include <cmath>
#include <cstdio>
#define MAXN 5010
#define MAXE 500000
using namespace std;

int n,m,k,mid,l,r;
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
	if(a.w == b.w) 
		return (a.f==1 || a.t==1);
	return a.w<b.w;
}

int kruskal();
int main() {
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++) {
		scanf("%d%d%d",&edge[i].f,&edge[i].t,&edge[i].w);
	}

	l = -1e6;
  	r = 1e6;
  	int cnt1;
  	while(l < r) {
    	mid = (l + r + 1) / 2;
    	cnt1 = kruskal(); 			//kruskal()计算能选到的1-边数目
    	if(cnt1 < k) 
    		r = mid - 1;
    	else if(cnt1 > k) 
    		l = mid;
        else {
        	break;
        	/*输出答案并return*/
        } 	//能正好取到k条1-边
  	}
  	mid=r;

  	//printf("mid=%d\n",mid);
  	for(int i=1;i<=n;i++)
		make_set(i);
	
	for(int i=0;i<m;i++) {
		if(edge[i].f == 1 || edge[i].t == 1)
			edge[i].w += mid;

	}

	long long ans = 0;
	sort(edge,edge+m,cmp);



	int cnt =0;
	for(int i=0;i<m;i++) {
		if(find_set(edge[i].f)!=find_set(edge[i].t)) {
			//if( (edge[i].f==1 || edge[i].t ==1) &&  cnt>=k)
			//	continue;
			union_set(edge[i].f, edge[i].t);
			//printf("Select %d to %d\n",edge[i].f,edge[i].t);


				ans += (edge[i].w);
		}
	}
	ans -= (k*mid);
	
	printf("%lld\n",ans);



}

int kruskal() {
	int ret = 0;
	for(int i=1;i<=n;i++)
		make_set(i);
	for(int i=0;i<m;i++) {
		if(edge[i].f == 1 || edge[i].t == 1)
			edge[i].w += mid;
	}
	sort(edge,edge+m,cmp);
	for(int i=0;i<m;i++) {
		if(find_set(edge[i].f)!=find_set(edge[i].t)) {
			union_set(edge[i].f, edge[i].t);
			if(edge[i].f == 1 || edge[i].t == 1)
				ret++;
		}
	}
	for(int i=0;i<m;i++) {
		if(edge[i].f == 1 || edge[i].t == 1)
			edge[i].w -= mid;
	}
	return ret;

}
