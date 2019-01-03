#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<queue>

#define MAXN 1000005

using namespace std;
int a[MAXN], b[MAXN];
long long asum,bsum;
int n;
long long flow;
long long mini(long long a, long long b){
    return a<b?a:b;
}



void input(void){
    scanf("%d",&n);
    asum=bsum=0;
    for(int i=1;i<=n;i++) {
        scanf("%d%d",&a[i],&b[i]);
        asum+=a[i];
        bsum+=b[i];
    }
    flow=mini(asum,bsum);
}

void solve() {
    for(int i=1;i<=n;i++) {
        flow=mini(flow,asum-a[i]+bsum-b[i]);
    }
	printf("%lld\n",flow);
}


int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++) {
        //init();
    	input();
    	solve();
    }
	return 0;
}