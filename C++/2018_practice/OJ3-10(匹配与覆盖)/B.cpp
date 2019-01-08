#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
#define MAXN 500
#define MAXR 50
#define MAXC 20

int T,r,c,n;
int counter;
int dp[MAXN][MAXN];
int mymap[MAXR][MAXC];
int direc[4][2]={-1,0, 1,0, 0,-1, 0,1};
int matching[MAXN];
int check[MAXN];

void init(){
	counter=1;
	memset(mymap,0,sizeof(mymap));
	memset(dp,0,sizeof(dp));
}


void input(){
	cin>>r>>c;
	init();
	string s;
	for(int i=0;i<r;i++) {
		cin>>s;
		for(int j=0;j<c;j++) {
			if(s[j]=='*') {
				mymap[i][j]=counter;
				counter++;
			}
		}
	}
	n=counter-1;

	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++) {
			int x=mymap[i][j];
			if(x==0)
				continue;
			for(int k=0;k<4;k++) {
				if(i+direc[k][0]>=0 && i+direc[k][0]<r && j+direc[k][1]>=0 && j+direc[k][1]<c)
					if(mymap[i+direc[k][0]][j+direc[k][1]]!=0) {
						int y=mymap[i+direc[k][0]][j+direc[k][1]];
						dp[x][y]=1;
						dp[y][x]=1;
					}
			}
		}
}

void floyd(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(dp[i][k] && dp[k][j])
					dp[i][j]=1;
}
bool dfs(int u)
{
    for (int i =1; i <=n; ++i) { 
        int v = i;
        if(!dp[u][v])
        	continue;
        if (!check[v]) {     
            check[v] = true; 
            if (matching[v] == -1 || dfs(matching[v])) {
                matching[v] = u;
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
            memset(check, 0, sizeof(check));
            if (dfs(u))
                ++ans;
        }
    
    return ans;
}

void solve() {
	//floyd();
	//printf("%d\n",n);
	printf("%d\n",n- hungarian()/2 );

}




int main() {
	cin>>T;
	for(int i=0;i<T;i++) {
		input();
		solve();
	}
}