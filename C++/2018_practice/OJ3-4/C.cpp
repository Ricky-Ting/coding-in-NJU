#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

struct node {
	int start;
	int end;
	int distance;
};
struct node2
{
	int a;
	int b;
};

int N;
node d[100000];
node2 c[101];
int counter=0;
int ans=0;
int fa[103];
int k;

bool cmp(const node &x, const node &y) {
	return x.distance<y.distance;
}
void solve();
void input();

int main() {
	input();
	solve();
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
	scanf("%d",&N);
	scanf("%d",&k);
	for(int i=0;i<N;i++) 
		scanf("%d%d",&c[i].a,&c[i].b);
	for(int i=0;i<N;i++)
		for(int j=i+1;j<N;j++) {
			d[counter].start=i;
			d[counter].end=j;
			d[counter].distance=abs(c[i].a-c[j].a)+abs(c[i].b-c[j].b);
			counter++;
		}
}

void solve() {
	int cnt=0;
	sort(d,d+counter,cmp);
	for(int i=0;i<N;i++)
		make_Set(i);
	for(int i=0;i<counter;i++) {
		if( !Same_Set(d[i].start,d[i].end) ) {
			ans=d[i].distance;
			//printf("%d %d to %d\n",ans,d[i].start,d[i].end);
			Union_Set(d[i].start,d[i].end);
			cnt++;
			
		}
		if(cnt==N-k)
			break;
	}
	printf("%d\n",ans);
	//cout<<ans<<endl;
}