#include<iostream>
#include<cstdio>
#include<cstring>

#define MOD 100000000

void solve();
int M,N;
int field[12];
int dp[12][1<<12];
int main(){
	scanf("%d%d",&M,&N);
	int index;
	memset(dp,0,sizeof(dp));
	memset(field,0,sizeof(field));
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++) {
			scanf("%d",&index);
			if(!index)
				field[i] |=  (1<<j);
		}
	solve();
}

int is_valid(int s, int ref) {
	if( s & (s<<1) )
		return 0;
	if( s & field[ref])
		return 0;
	return 1;
}

int is_not_adj(int sa, int sb) {
	if(sa & sb)
		return 0;
	return 1;
}



void solve() {
	


	int S = 1<<N;
	for(int i=0;i<S;i++){
		if(is_valid(i,0)) {
			dp[0][i]=1;
		}
	}

	for(int i=1;i<M;i++) {
		for(int j=0;j<S;j++){
			if( !(is_valid(j,i)) )
				continue;
			for(int k=0;k<S;k++) {
				if(  is_valid(k,i-1)   && is_not_adj(j,k) ) {
					dp[i][j] += (dp[i-1][k])%MOD;
					dp[i][j] %= MOD;
				}
			}
		}
	}
	int ans=0;
	for(int i=0; i<S;i++) {
		ans += dp[M-1][i];
		ans %= MOD;
	}
	printf("%d\n",ans);
}