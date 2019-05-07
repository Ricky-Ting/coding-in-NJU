#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define eps 1e-8
#define pb push_back
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define clr(a,b) memset(a,b,sizeof(a)
#define bugc(_) cerr << (#_) << " = " << (_) << endl
#define FAST_IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long ll;
typedef unsigned long long ull;
const int N=2e5+10;

int fa[N];
struct edge{
    int u,v,w;
}e[N];

int fi(int x){
    return fa[x]==x?x:fa[x]=fi(fa[x]);
}

bool cmp(edge x,edge y){
    return x.w<y.w;
}

int main(){
    int n,m,ans=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    }
    sort(e+1,e+1+m,cmp);


    for(int i=1;i<=m;){
        int j=i;
        while(e[j].w==e[i].w) j++;
        printf("j=%d\n",j);
        for(int k=i;k<j;k++){
            int fx=fi(e[k].u),fy=fi(e[k].v);
            if(fx!=fy) {ans++; printf("In 1\n");}
            //printf("ans =%d \n ",ans);

        }
        for(int k=i;k<j;k++){
            int fx=fi(e[k].u),fy=fi(e[k].v);
            if(fx!=fy){
                fa[fx]=fy;
                ans--;
                printf("In 2\n");
            }
           // printf("ans =%d \n ",ans);
        }
        i=j;
    }
    printf("%d\n",ans);
    return 0;
    
}