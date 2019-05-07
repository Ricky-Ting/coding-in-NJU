#include <iostream>
#include <cstdio>
using namespace std;
#define MAXN 1005
struct {
	long long x, y, z;

} holes[MAXN];
int n;
long long h,r;
int fa[MAXN];
void solve();
void input();
void make_set(int a) {
	fa[a] = a;
	return ;
}

int find_set(int a) {
	if(fa[a]==a)
		return a;
	else
		return fa[a] = find_set(fa[a]);
}

int union_set(int a, int b) {
	fa[find_set(b)] = find_set(a);
	return find_set(a);
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		input();
		solve();
	}
}

void input() {
	scanf("%d%lld%lld",&n,&h,&r);
	for(int i=1; i<=n; i++) {
		scanf("%lld%lld%lld",&holes[i].x, &holes[i].y, &holes[i].z);
		make_set(i);
	}
}

int satisfy(int a, int b) {
	long long dis = (holes[a].x-holes[b].x)*(holes[a].x-holes[b].x) + (holes[a].y-holes[b].y)*(holes[a].y-holes[b].y) + (holes[a].z-holes[b].z)*(holes[a].z-holes[b].z);
	if(dis <= 4*r*r)
		return 1;
	else
		return 0;
}

int get_ground(int a) {
	if(holes[a].z<=r)
		return 1;
	else
		return 0;
}

int get_sky(int a){
	if(holes[a].z + r >= h)
		return 1;
	else
		return 0;
}

void solve() {
	for(int i=1; i<n; i++) {
		for(int j=i+1; j<=n; j++) {
			if(satisfy(i,j))
				union_set(i,j);
		}
	}
	int counter = 0;
	int vis[MAXN];
	memset(vis, 0, sizeof(vis));
	for(int i=1; i<=n; i++) {
		if(get_ground(i)) {
			vis[find_set(i)] = 1;
		}
	}
	int flag = 0; 
	for(int i=1; i<=n; i++) {
		if(get_sky(i)) {
			if(vis[find_set(i)]) {
				flag = 1;
				break;
			}
		}
	}
	if(flag)
		printf("Yes\n");
	else
		printf("No\n");
}

