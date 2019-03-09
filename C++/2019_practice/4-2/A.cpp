#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int is_prime[1505];

long long a,b;
char s[20];
void get_prime();
void init();
void solve();
char buf[20];
long long dp[20][170][1500];
long long get_dp(int pos, int s1, int s2, int in_max);
int main() {
	get_prime();
	//unsigned long long maxi=1000000000000000000;
	int T;
	scanf("%d",&T);
	init();
	while(T--)
		solve();

}
void init() {
	for(int i=0;i<20;i++) 
		for(int j=0;j<170;j++)
			for (int k = 0; k < 1500; k++)
				dp[i][j][k]=-1;
	
}

void solve() {
	scanf("%lld%lld",&a,&b);
	
	long long counter1=0,counter2=0;
	sprintf(s,"%lld",a-1);
	int flag=0;
	for(int i=0;i<=(s[0]-'0');i++) {
		if(i==(s[0]-'0'))
			flag=1;
		counter1+=get_dp(strlen(s)-1,i,i*i,flag);
	}
	//printf("counter1=%d\n",counter1);


	sprintf(s,"%lld",b);
	flag=0;
	for(int i=0;i<=(s[0]-'0');i++) {
		if(i==(s[0]-'0'))
			flag=1;
		counter2+=get_dp(strlen(s)-1,i,i*i,flag);
	}
	long long ans=counter2-counter1;
	if(ans!=0) 
		printf("%lld\n",ans);
	else
		printf("a=%lld, b=%lld\n",a,b);
}

long long get_dp(int pos, int s1, int s2, int in_max){
	if(pos==0) {
		if(is_prime[s1] && is_prime[s2])
			return dp[pos][s1][s2]=1;
		else
			return dp[pos][s1][s2]=0;
	}
	if(in_max) {
		long long ret=0;
		int maxi= s[strlen(s)-pos] -'0';
		for(int i=0;i<maxi;i++){
			ret += get_dp(pos-1,s1+i,s2+i*i,0);
		}
		ret += get_dp(pos-1,s1+maxi,s2+maxi*maxi,1);
		return ret;
	}
	if(dp[pos][s1][s2]!=-1)
		return dp[pos][s1][s2];
	
	
	
		dp[pos][s1][s2]=0;
		for(int i=0;i<=9;i++){
			dp[pos][s1][s2]+=get_dp(pos-1,s1+i,s2+i*i,0);
		}
		return dp[pos][s1][s2];
	

}


void get_prime(){
	memset(is_prime,1,sizeof(is_prime));
	is_prime[0]=is_prime[1]=0;
	int counter=2;
	while(counter<1500) {
		for(int i=2;i<=1500/counter;i++) {
			if(i*counter<1500){
				is_prime[i*counter]=0;
			}
		}
		counter++;
		while(counter<1500 && is_prime[counter]==0){
			counter++;
		}
	}
	/*
	for(int i=0;i<1500;i++) {
		if(is_prime[i])
			printf("%d\n",i);
	}
	*/
}
