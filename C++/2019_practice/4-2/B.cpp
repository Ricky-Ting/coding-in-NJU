#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>

#define MAXN 500008
using namespace std;

int n,k,m;
int a[MAXN], b[MAXN];
int one[MAXN];
int way[MAXN];
int dis[20][20];
int counter;
int f[1<<18];

queue<int>q;
int vis[MAXN];
int s[MAXN];
void bfs(int index) {
	memset(s,0,sizeof(s));
	memset(vis,0,sizeof(vis));
	s[index]=0;
	vis[index]=1;
	q.push(index);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		int v1,v2;
		for(int i=1;i<=m;i++) {
			v1 = u + way[i]; 
			v2 = u - way[i];
			if( (v1<=n) && (vis[v1]==0) ) {
				s[v1] = s[u] + 1;
				vis[v1] = 1;
				q.push(v1);
			}

			if( (v2>=0) && (vis[v2]==0) ) {
				s[v2] = s[u] + 1;
				vis[v2] = 1;
				q.push(v2);
			}
		}
	}

}




int main(){
	scanf("%d%d%d",&n,&k,&m);
	int index;
	for(int i=0;i<k;i++){
		scanf("%d",&index);
		a[index]=1;
	}
	counter=0;
	for(int i=0;i<=n;i++) {
		b[i]=a[i]^a[i+1];
		if(b[i]==1){
			counter++;
			one[counter]=i;
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&way[i]);
	}
	for(int i=1; i<=counter;i++) {
		bfs(one[i]);
		for(int j = 1; j<=counter; j++) {
			dis[i][j] = s[one[j]];
		}

	}
	int S=1<<counter;
    for(int i=1;i<S;i++) f[i]=0x3f3f3f3f;
    for(int i=0;i<S;i++)
    {
        int j=0;
        while(i&(1<<j)) j++;
        for(int p=j+1;p<counter;p++)
        {
            if(!(i&(1<<p))&&dis[p+1][j+1])
                f[i|(1<<p)|(1<<j)]=min(f[i|(1<<p)|(1<<j)],f[i]+dis[p+1][j+1]);
        }
    }
    printf("%d\n",f[S-1]);
    return 0;


}