#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<queue>
using namespace std;  
const int maxn = 600;  
const int INF=1e9+100; 
int counter=0;
int map[maxn][maxn];
int idtable[26][26][26]; 
int n,m; 
int Sto_wag(int N){  
       int dis[maxn],node[maxn],maxj,pre,m,ans=INF;  
       bool visit[maxn];  
       for(int i = 0; i < N; i ++)node[i] = i;  
       while(N > 1){  
              m = -1;maxj = 1;  
              for(int i = 1; i < N; i ++){  
                     dis[node[i]] = map[node[0]][node[i]];  
                     visit[node[i]] = 0;  
                     if(dis[node[i]] > m){  
                            m = dis[node[i]];  
                            maxj = i;  
                     }  
              }  
              pre = 0;visit[node[0]] = 1;  
              for(int j = 1; j < N; j ++){  
                     visit[node[maxj]] = 1;  
                     if(j == N-1){  
                            ans = min(ans, m);  
                            for(int i = 0; i < N; i ++){  
                                   map[node[pre]][node[i]] += map[node[maxj]][node[i]];  
                                   map[node[i]][node[pre]] += map[node[maxj]][node[i]];  
                            }  
                            node[maxj] = node[--N];  
                     }  
                     else{  
                            pre = maxj;m = -1;  
                            for(int i = 1; i < N; i ++)  
                                   if(! visit[node[i]]){  
                                          dis[node[i]] += map[node[pre]][node[i]];  
                                          if(dis[node[i]] > m){  
                                                 m = dis[node[i]];  
                                                 maxj = i;  
                                          }  
                                   }  
                     }  
              }  
       }  
       return ans;  
}

void init() {
       memset(map,0,sizeof(map));
       for(int i=0;i<26;i++)
              for(int j=0;j<26;j++)
                     for(int k=0;k<26;k++)
                            idtable[i][j][k]=-1;
}  

int getid(string s) {
       if(idtable[s[0]-'A'][s[1]-'A'][s[2]-'A']!=-1)
              return idtable[s[0]-'A'][s[1]-'A'][s[2]-'A'];
       else {
              idtable[s[0]-'A'][s[1]-'A'][s[2]-'A']=counter;
              counter++;
              return idtable[s[0]-'A'][s[1]-'A'][s[2]-'A'];
       }
}

void input(void) {
       init();
       cin>>n>>m;
       int from, to;
       string s;
       for(int i=0;i<m;i++){
              cin>>s;
              from=getid(s);
              cin>>s;
              to=getid(s);

              map[from][to]+=1;
              map[to][from]+=1;
       }

}

void solve() {
       printf("%d\n",Sto_wag(n));
}

int main(void) {
       input();
       solve();
}
