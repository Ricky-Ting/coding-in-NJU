#include<iostream>  
#include<cstring>  
#include<cstdio>  
using namespace std;  
const int nMax=1000;  
int c,d;  
int map[nMax][nMax];  
bool vis[nMax];  
int linkk[nMax];  
  
int dfs(int s){  
    for(int i=1;i<=d;i++){  
        if(!vis[i]&&map[s][i]){  
            vis[i]=1;  
            if(linkk[i]==-1||dfs(linkk[i])){  
                linkk[i]=s;  
                return 1;  
            }  
        }  
    }  
    return 0;  
}  
  
void floyd(int n){  
    for(int k=1;k<=n;k++){  
        for(int i=1;i<=n;i++){  
            for(int j=1;j<=n;j++){  
                if(map[i][k]&&map[k][j]){  
                    map[i][j]=1;  
                }  
            }  
        }  
    }  
}  
int main(){  
    int n,m,a,b,ans,i,j;  
    while(scanf("%d%d",&n,&m)&&(n||m)){  
        c=d=n;  
        ans=0;  
        memset(map,0,sizeof(map));  
        while(m--){  
            scanf("%d%d",&a,&b);  
            map[a][b]=1;  
        }  
        floyd(n);  
        memset(linkk,-1,sizeof(linkk));  
        for(i=1;i<=c;i++){  
            memset(vis,0,sizeof(vis));  
            if(dfs(i))ans++;  
        }  
        printf("%d\n",n-ans);  
    }  
    return 0;  
}  