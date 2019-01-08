#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

struct node {
	int start;
	int end;
	int distance;
};

int N;
node d[100000];
int a[101][101];
int counter=0;
int ans=0;
int fa[103];

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
	for(int i=0;i<N;i++) 
		for(int j=0;j<N;j++) 
			scanf("%d",&a[i][j]);
	for(int i=0;i<N;i++)
		for(int j=i+1;j<N;j++) {
			d[counter].start=i;
			d[counter].end=j;
			d[counter].distance=a[i][j];
			counter++;
		}
}

void solve() {
	int cnt=N-1;
	sort(d,d+counter,cmp);
	for(int i=0;i<N;i++)
		make_Set(i);
	for(int i=0;i<counter;i++) {
		if( !Same_Set(d[i].start,d[i].end) ) {
			ans+=d[i].distance;
			Union_Set(d[i].start,d[i].end);
			cnt--;
			if(cnt==0)
				break;
		}
	}
	printf("%d\n",ans);
	//cout<<ans<<endl;
}