#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#define INF 100000000000000
using namespace std;

long long cost[200009];
int n,m;
struct edge{
    int to;
    long long w;
    edge(int myto,long long myw):to(myto),w(myw){} //构造函数
};
struct vertex
{
	int v;
	long long val;
	vertex(int myv,long long mycost):v(myv),val(mycost){}
	bool operator <(const vertex &a) const{
		return val>a.val;
	}
};

bool isvis[200009];
long long ans[200009];

static inline int mini(int a,int b) {
	return (a<b)?a:b;
}

vector<edge> E[200009];


void input() {
	scanf("%d%d",&n,&m);
	
	int from,to;
	long long c;
	for(int i=0;i<m;i++) {
		scanf("%d%d%lld",&from,&to,&c);
		E[from].push_back(edge(to,2*c));
		E[to].push_back(edge(from,2*c));
	}
	for(int i=1;i<=n;i++)
		scanf("%lld",&cost[i]);
	for(int i=1;i<=n;i++){
		E[0].push_back(edge(i,cost[i]));
	}
	for(int i=0;i<=n;i++)
		isvis[i]=false;
	for(int i=0;i<=n;i++)
		ans[i]=INF;
}


void solve() {
	priority_queue<vertex> q;
	ans[0]=0;
	q.push(vertex(0,0));
	while(!q.empty()) {
		vertex t=q.top();
		int u=t.v;
		if(!isvis[u]){
			isvis[u]=true;
			for(int i=0;i<E[u].size();i++) {
				int v=E[u][i].to;
				long long a=E[u][i].w;
				
					if(!isvis[v] && ans[v]>ans[u]+a) {
						ans[v]=ans[u]+a;
						q.push(vertex(v,ans[v]));
					}
			}
		}
		q.pop();
	}
    for(int i=1;i<=n;i++)
    	printf("%lld ",ans[i]);
    
}

int main() {
	input();
	solve();
}