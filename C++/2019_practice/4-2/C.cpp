#include<iostream>
#include<cstdio>
#include<assert.h>
using namespace std;
#define MAXP 100
#define MAXC 100
#define MAXCH 100007
#define M 1000000007

struct node{
	int p_counter;
	int p_index[MAXP];
	int c_counter;
	int c_index[MAXC];
}chain[MAXCH];

int dp[MAXCH];
int T;
int n,m;
void init();
void solve();
void input();
int get_dp(int a);
int main(){
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&m);
		init();
		input();
		solve();
	}
}

void init() {
	for(int i=1;i<=n;i++){
		dp[i]=-1;
		chain[i].p_counter=chain[i].c_counter=0;
	}
}


void input() {

	
	int f,t;
	for(int i=0;i<m;i++){
		scanf("%d%d",&f,&t);
		chain[f].c_index[chain[f].c_counter]=t;
		chain[f].c_counter++;
		chain[t].p_index[chain[t].p_counter]=f;
		chain[t].p_counter++;
	}

}

void solve(){
	for(int i=1;i<=n;i++){
		if(dp[i]==-1){
			get_dp(i);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(dp[i]!=-1 && chain[i].p_counter==0)
			ans+=dp[i];
			ans%=M;
	}
	printf("%d\n",ans);
}

int get_dp(int a) {
	if(dp[a]!=-1)
		return dp[a];
	dp[a]=0;
	for(int i=0;i<chain[a].c_counter;i++){
		dp[a]+= get_dp(chain[a].c_index[i]);
		dp[a]=dp[a]%(M);
	}
	if(chain[a].c_counter==0)
		dp[a]=1;
	dp[a]%=M;
	return dp[a];
}

