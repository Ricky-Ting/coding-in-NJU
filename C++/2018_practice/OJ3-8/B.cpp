#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<time.h>
#include<cstdlib>
#include<vector>
#include<ctime>
using namespace std;
#define MAXN 22
#define MAXM 60
bool isvis[MAXN];
int degree[MAXN];
int start;
int n,m;
struct edge{
    int to;
    bool visited;
    int reves;
    edge(int myto,bool myvisited,int myreves):to(myto),visited(myvisited),reves(myreves){} //构造函数
};
int dp[MAXN][MAXN];
int chongbian[MAXN];
int sumchongbian;

vector<edge> E[MAXN];
stack<int> s;

void init() {
	for(int i=0;i<MAXN;i++)
		isvis[i]=false;
	memset(degree,0,sizeof(degree));
	memset(dp,0,sizeof(dp));
	memset(chongbian,0,sizeof(chongbian));
	sumchongbian=0;
}

void input() {
	scanf("%d%d",&n,&m);
	init();
	int from,to;
	for(int i=0;i<m;i++) {
		scanf("%d%d",&from,&to);
		E[from].push_back(edge(to,false,-1));
		if(from!=to){
			E[to].push_back(edge(from,false,-1));
			E[from][E[from].size()-1].reves=E[to].size()-1;
			E[to][E[to].size()-1].reves=E[from].size()-1;
		}
		else {
			chongbian[from]++;
			sumchongbian++;
			E[from][E[from].size()-1].reves=E[from].size()-1;
		}
		//if(from!=to)
			dp[from][to]++; dp[to][from]++;
		//degree[from]++; degree[to]++;
	}
}

bool dfs(int x, int depth){
	if(depth==n) {
		return true;
	}
	isvis[x]=true;
	for(int i=0;i<E[x].size();i++) {
		int v=E[x][i].to;
		if(!isvis[v]) {
			if(dfs(v,depth+1))
				return true;
		}
	}
	isvis[x]=false;
	return false;
}
/*
bool dfs2(int x, int counter) {
	if(counter==m) {
		if(x!=start)
			return false;
		else {
			return true;
		}
	}
	for(int i=n;i>=1;i--) {
		if(dp[x][i]) {
			dp[x][i]--;dp[i][x]--;
			if(dfs2(i,counter+1)) {
				printf("%d %d\n",i,x);
				return true;
			}
			dp[x][i]++;dp[i][x]++;
		}
	}
	return false;
}
*/

bool dfs2(int x, int counter) {
	if(counter==m) {
		if(x!=start)
			return false;
		else {
			return true;
		}
	}
	
	int v;
	for(int i=0;i<E[x].size();i++) {
		v=E[x][i].to;
		if(!E[x][i].visited) {
			E[x][i].visited=E[v][E[x][i].reves].visited=true;
			if(dfs2(v,counter+1)) {
				printf("%d %d\n",v,x);
				return true;
			}
			E[x][i].visited=E[v][E[x][i].reves].visited=false;
		}
	}
	return false;
	
}

void solve() {
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++)
			if(dp[i][j] && i!=j)
				degree[i]++;
	}
	int one=0; int start2=1;
	for(int i=1;i<=n;i++)
		if(degree[i]==1) {
			one++;
			start2=i;
		}
	if(one>2) {
		printf("Miss Shizue\n");
		return;
	}


	if(!dfs(start2,1)) {
		printf("Miss Shizue\n");
		return;
	} 

	

	for(int i=1;i<=n;i++)
		if(degree[i]&1) {
			printf("Miss Leon\n");
			return;
		}
	printf("Find Leon\n");
	int v;
	for(int i=1;i<=n;i++) {     //遍历n个节点
		for(int j=0;j<E[i].size();j++) {
			if(E[i][j].reves==-1) {
				v=E[i][j].to;
				for(int k=0;k<E[v].size();k++) {
					if(E[v][k].to==i) {
						E[v][k].reves=j;
						E[i][j].reves=k;
						break;
					}
				}
			}
		}
	}
	srand((unsigned)time(NULL));  
	//start=rand()%n +1;
	start=1;
	dfs2(start,0);
	
}

int main(void) {
	input();
	solve();
}


