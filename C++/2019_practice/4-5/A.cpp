#include <iostream>
#include <cstdio>
#define MAXN 1005
using namespace std;
int n,m;

int fa[MAXN];

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
	scanf("%d%d",&n,&m);
	for(int i = 1; i<=n; i++)
		make_set(i);
	int a,b;
	for(int i=0; i<m; i++) {
		scanf("%d%d",&a,&b);
		union_set(a,b);
	}
	int counter = 0;
	for(int i=1; i<=n; i++) {
		if(fa[i] == i)
			counter++;
	}
	printf("%d\n", n-counter);
	return 0;

}