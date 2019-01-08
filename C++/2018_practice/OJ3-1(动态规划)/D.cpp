#include<iostream>
#include<cstring>
using namespace std;
#define INF 100000000;
struct node
{
    int x;
    int y;
};
node chery[600];

int dp[30][30][30][30];
int k;

int DP(int x1,int y1, int x2, int y2);

int main(void)
{
    int t=1;;
    int n,m;
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        for(int i=1;i<=k;i++)
            scanf("%d%d",&chery[i].x,&chery[i].y);
        memset(dp,-1,sizeof(dp));
        int ans=DP(0,0,n,m);
        printf("Case %d: %d\n",t,ans);
        t++;
    }
}


int DP(int x1,int y1, int x2, int y2)
{
    if(dp[x1][y1][x2][y2]!=-1)
        return dp[x1][y1][x2][y2];
    dp[x1][y1][x2][y2]=INF;
    int tmp=0;
    for(int i=1;i<=k;i++)
        if((x1<chery[i].x) &&(chery[i].x<=x2) && (y1<chery[i].y) &&(chery[i].y<=y2) )
            tmp++;
    if(tmp==0)
        return dp[x1][y1][x2][y2];
    if(tmp==1)
        return dp[x1][y1][x2][y2]=0;
    
    for(int i=x1+1;i<x2;i++)
        dp[x1][y1][x2][y2]=min(dp[x1][y1][x2][y2],DP(x1,y1,i,y2)+DP(i,y1,x2,y2)+y2-y1);
    for(int i=y1+1;i<y2;i++)
        dp[x1][y1][x2][y2]=min(dp[x1][y1][x2][y2],DP(x1,y1,x2,i)+DP(x1,i,x2,y2)+x2-x1);
    return dp[x1][y1][x2][y2];
}
