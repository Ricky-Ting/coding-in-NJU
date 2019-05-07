#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define MAXN 300
int n,m;
int fig[MAXN][MAXN];
int degree[MAXN];
int isvis[MAXN];
int bfs(int node);
void solve();
int main() {
	scanf("%d",&n);
	int f,t;
	int cnt = 0;
	while(n!=0) {
		cnt++;
		scanf("%d",&m);
		memset(degree,0,sizeof(degree));
		memset(fig,0,sizeof(fig));
		memset(isvis,0,sizeof(isvis));
		for(int i=0;i<m;i++) {
			scanf("%d%d",&f,&t);
			fig[f][t] = fig[t][f] = 1;
			degree[f]++;
			degree[t]++;
		}
		printf("Case %d: ",cnt);
		if( (m+1)==n) {
			solve();
		}else {
			printf("955\n");
		}

		scanf("%d",&n);
	}
}

void solve() {
	int first = 0;
	for(int i=1;i<=n;i++) {
		if(degree[i]==0) {
			printf("955\n");
			return;
		}
		if(degree[i]>1 && !isvis[i]) {
			int ret = bfs(i);
			if(ret!=1) {
				//printf("Here\n" );
				break;
			}
		}
	}
	if(first==1) {
		printf("996\n");
		return;
	}
	int flag = 0;
	for(int i=1;i<=n;i++)
		if(isvis[i]==0) {
			//printf("%d\n",i);
			flag=1;
		}
	if(flag)
		printf("955\n");
	else
		printf("996\n");
	return;

}

int bfs(int node) {

	queue<int> Q;
	int flag;
	Q.push(node);
	int cur;
	while(!Q.empty()) {
		
		flag = 0;
		cur = Q.front(); Q.pop();
		isvis[cur] = 1;
		for (int i = 1; i <=n; ++i) {
			if(!fig[cur][i])
				continue;
			if(degree[i]==1)
				isvis[i]=1;
			if(degree[i]>1) {
				if(flag>=2) {
					//printf("\n%d,%d,%d\n",cur,next,i);
					return 0;
				}
				else {
					if(!isvis[i]) {
						Q.push(i);
					}
					flag ++;
				}
			}
		}
	}
	return 1;
}