#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
using namespace std;

struct edge{
	int to;
	int a;
	int b;
	edge(int myto,int mya, int myb):to(myto),a(mya),b(myb){} //构造函数
};

struct vertex {
	int v;
	long long cost;
	vertex(int myv,long long mycost):v(myv),cost(mycost){}
	bool operator <(const vertex &a) const{
		return cost>a.cost;
	}
};

int T;
int n,m;
bool isvis[50005];
long long level[50005];

vector<edge> E[100005];

int myLog(long long t) {
	int cnt=0;
	for(;t>1;t>>=1,++cnt);
	return cnt;
}
void input();
void solve();

int main() {
	scanf("%d",&T);
	for(int i=0;i<T;i++) {
		input();
		solve();
		if(level[n]==1e18)
			printf("-1\n");
		else
			printf("%d\n",myLog(level[n]));
	}

}

void input(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		E[i].clear();
	memset(isvis,false,sizeof(isvis));
	//memset(level,-1,sizeof(level));
	for(int i=0;i<=n;i++)
		level[i]=1e18;
	int f,to,a,b;
	for(int i=0;i<m;i++) {
		scanf("%d%d%d%d",&f,&to,&a,&b);
		E[f].push_back(edge(to,a,b));
	}
}

void solve(){
	priority_queue<vertex> q;
	level[1]=1;
	q.push(vertex(1,1));
	while(!q.empty()) {
		vertex t=q.top();
		int u=t.v;
		if(!isvis[u]){
			isvis[u]=true;
			for(int i=0;i<E[u].size();i++) {
				int v=E[u][i].to;
				int a=E[u][i].a;
				if(!(myLog( 1+ a/level[u] )<E[u][i].b))
					if(!isvis[v] && level[v]>level[u]+a) {
						level[v]=level[u]+a;
						q.push(vertex(v,level[v]));
					}
			}
		}
		q.pop();
	}
}