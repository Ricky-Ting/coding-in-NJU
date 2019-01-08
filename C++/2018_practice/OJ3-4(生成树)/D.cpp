#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int T,n,m;
int A[13][13];
long long C[13][13];
 
void SWITCH(int a, int b);
void input();
void solve();
int main() {
    scanf("%d",&T);
    for(int i=0;i<T;i++) {
        input();
        solve();
    }
}
 
void input() {
    int s,e;
    for(int i=0;i<13;i++) 
        for(int j=0;j<13;j++)
            A[i][j]=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) {
        scanf("%d%d",&s,&e);
        if(s!=e)
            A[s][e]=A[e][s]=1;
    }
}
 
void solve() {
    for(int i=1;i<=n;i++) {
        int count=0;
        for(int j=1;j<=n;j++)
            count+=A[i][j];
        C[i][i]=count;
    }
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=n;j++)
            if(i!=j)
                C[i][j]=-A[i][j];
    for(int i=1;i<n-1;i++){
        if(C[i][i]==0) {
            int j;
            for(j=i+1;j<=n-1;j++)
                if(C[j][i]!=0) {
                    SWITCH(i,j);
                    break;
                }
            if(j==n) {
                printf("0\n");
                return;
            }
        }
 
        for(int j=i+1;j<=n-1;j++) {
        	while(C[j][i]!=0) {
        	  SWITCH(j,i);
          	  long long factor=C[j][i]/C[i][i];
          	  for(int k=i;k<=n-1;k++)
                C[j][k]+=(-factor*C[i][k]);
        	}
        }
    }
    long long ans=1;
    for(int i=1;i<=n-1;i++)
        ans*=C[i][i];
    printf("%lld\n",abs(ans));
}
 
void SWITCH(int a, int b) {
    for(int i=1;i<=n;i++) {
        long long tmp=C[a][i];
        C[a][i]=C[b][i];
        C[b][i]=tmp;
    }
}