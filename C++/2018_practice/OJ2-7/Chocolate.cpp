#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

int C,N,M;
double dp[2][102];
int main(void)
{
    cin>>C;
    while(C!=0)
    {
        cin>>N;
        cin>>M;
        
        if(M>N || M>C || (N+M)%2)
        {
            cout<<"0.000"<<endl;
            cin>>C;
            continue;
        }
        if(N>1001)
            N=N%2?1001:1000;
        memset(dp,0,sizeof(dp));
        dp[0][0]=1.0;
        for(int i=1;i<=N;i++)
            for(int j=0;j<=i && j<=C;j++)
            {
                dp[i%2][j]=0.0;
                if((i+j)%2)
                    continue;
                if(j>0)
                    dp[i%2][j]+= dp[1-i%2][j-1]*(double((C-j+1.0)*1.0)/double(C));
                if(j+1<=i-1)
                    dp[i%2][j]+=dp[1-i%2][j+1]*(double((j+1.0)*1.0)/double(C));
            }
        cout<<setiosflags(ios::fixed)<<setprecision(3)<<dp[N%2][M]<<endl;
        cin>>C;
    }
}

