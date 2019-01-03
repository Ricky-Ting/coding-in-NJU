#include<iostream>
#include<algorithm>
using namespace std;
void solve(void);
void input(void);
struct node {
	int a;
	int b;
	bool visited;
};

int binary(int m);
bool cmp(const node &x, const node &y) {
	return min(y.a,x.b)>min(y.b,x.a) || (min(y.a,x.b)==min(y.b,x.a) && y.a>x.a);
}
node cities[100005];
int T,n;
int money,spend;
int main(void) {
	scanf("%d",&T);
	for(int i=0;i<T;i++) {
		input();
		solve();
		printf("%d\n",spend);
	}
}

void input(void) {
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d%d",&cities[i].a,&cities[i].b);
		cities[i].visited=false;
	}
}
void solve(void) {
	sort(cities,cities+n,cmp);
	spend=0;
	money=0;
	for(int i=0;i<n;i++) {
		spend+=min(cities[i].a,money);
		money-=min(cities[i].a,money);
		money+=(cities[i].b);
	}
}

