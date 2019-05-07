#include <iostream>
#include <cstdio>
#define MAXN 1005
using namespace std;
int n,m,k;
int niubi[MAXN];
int niubi_counter[MAXN];
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
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k; i++) {
		scanf("%d",&niubi[i]);
	}
	for(int i=1;i<=n;i++)
		make_set(i);
	int a,b;
	for(int i=0; i<m; i++) {
		scanf("%d%d",&a,&b);
		union_set(a,b);
	}
	if(k==0) {
		printf("%d\n",n*(n-1)/2 - m);
		return 0;
	}
	int other_counter  = n;
	int max_niubi_index = 0;
	int max_niubi = 0;
	for(int i=1; i<=k ;i++) {
		niubi_counter[i] = 0;
		for(int j=1; j<=n; j++) {
			if(find_set(j) == find_set(niubi[i])) {
				niubi_counter[i]++;
			}
		}
		if(niubi_counter[i]>max_niubi) {
			max_niubi = niubi_counter[i];
			max_niubi_index = i;
		}
		other_counter = other_counter - niubi_counter[i];
	}

	int ans =0;
	for(int i=1; i<=k; i++) {
		if(i==max_niubi_index) {
			ans += (other_counter+niubi_counter[i])*(other_counter+niubi_counter[i]-1)/2;
		}
		else
			ans += (niubi_counter[i])*(niubi_counter[i]-1)/2;
	}
	ans -= m;
	printf("%d\n",ans);


}