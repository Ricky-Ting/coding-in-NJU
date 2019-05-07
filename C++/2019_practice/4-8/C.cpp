#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
#define MAXN 105
struct node
{
	int x;
	int y;
};

int n,m;
int fig[MAXN][MAXN];
int isvis[MAXN][MAXN];
int dire[4][2] = { 0,1, 0,-1, 1,0, -1,0   };

void solve(void);
int satisfy(int a, int b);
int main() {
	scanf("%d%d",&n,&m);
	char buf[105];
	for(int i=1;i<=n;i++) {
		scanf("%s",buf);
		for(int j=1;j<=n;j++) {
			fig[i][j] = buf[j-1] - '0';
		}

	}
	for(int i=1;i<=m;i++) {
		solve();
	}
}

void solve() {
	node tmp;
	int ans =0;
	scanf("%d%d",&tmp.x,&tmp.y);
	memset(isvis,0,sizeof(isvis));
	isvis[tmp.x][tmp.y] =1;
	ans=1;
	queue<node> Q;
	Q.push(tmp);
	while(!Q.empty()) {
		node v = Q.front(); Q.pop();
		for(int i=0;i<4;i++) {
			if(satisfy(v.x+dire[i][0], v.y+dire[i][1]) && fig[v.x][v.y]!=fig[v.x+dire[i][0]][v.y+dire[i][1]] && isvis[v.x+dire[i][0]][v.y+dire[i][1]]==0){
				ans++;
				node tmp2; tmp2.x = v.x+dire[i][0]; tmp2.y=v.y+dire[i][1];
				isvis[tmp2.x][tmp2.y]=1;
				Q.push(tmp2);
			}
		}
	}
	printf("%d\n",ans);

}

int satisfy(int a, int b) {
	if(a<1 || a>n)
		return 0;
	if(b<1 || b>n)
		return 0;
	return 1;
}