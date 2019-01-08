#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define MAXN 300
int n,m,k;
struct Edge
{
	int to;
	Edge(int myto): to(myto) {}
};
vector<Edge> edge[MAXN];
int matching[MAXN];
int check[MAXN];

void init(){
	for(int i=1;i<=n+m;i++)
		edge[i].clear();
}


void input(){
	scanf("%d%d",&m,&k);
	int a,x,y;
	init();
	for(int i=0;i<k;i++){
		scanf("%d%d%d",&a,&x,&y);
		edge[x].push_back(Edge(y+n));
		edge[y+n].push_back(Edge(x));
	}
	
}
/* 模板copy自网上，网址:https://www.renfei.org/blog/bipartite-matching.html */
bool dfs(int u)
{
    for (int i =0; i < edge[u].size(); ++i) { 
        int v = edge[u][i].to;
        if (!check[v]) {     
            check[v] = true; 
            if (matching[v] == -1 || dfs(matching[v])) {
                matching[v] = u;
                matching[u] = v;
                return true;
            }
        }
    }
    return false; 
}

int hungarian()
{
    int ans = 0;
    memset(matching, -1, sizeof(matching));
    for (int u=1; u <= n; ++u) {
        if (matching[u] == -1) {
            memset(check, 0, sizeof(check));
            if (dfs(u))
                ++ans;
        }
    }
    return ans;
}





void solve(){
	printf("%d\n",hungarian());
	return;
}


int main(void){
	while(1){
		scanf("%d",&n);
		if(n==0)
			return 0;
		input();
		solve();
	}
}