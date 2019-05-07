#include <iostream>
#include <algorithm>
#include <assert.h>
#include <cstdio>
#define MAXN 310
#define MAXE 100000
using namespace std;
 
int n,m;
struct node{
    int f;
    int t;
    int w;
} edge[MAXE];
 
int fa[MAXN];
 
int make_set(int a) {
    fa[a]=a;
    return a;
}
 
int find_set(int a) {
    if(fa[a]==a)
        return a;
    return fa[a] = find_set(fa[a]);
}
 
int union_set(int a, int b) {
    int va = find_set(a);
    int vb = find_set(b);
    fa[va] = fa[vb];
    return 1;
}
 
bool cmp(node a, node b) {
    return a.w<b.w;
}
 
int main() {
    int ans = 0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) {
        scanf("%d%d%d",&edge[i].f,&edge[i].t,&edge[i].w);
    }
     
     
    for(int i=1; i<=n; i++) {
        make_set(i);
    }
    sort(edge, edge+m, cmp);
 
    int counter = 0;
 
    for(int i=0;i<m;i++) {
        if(find_set(edge[i].f)!=find_set(edge[i].t)) {
            union_set(edge[i].f,edge[i].t);
            counter++;
        }
        if(counter == n-1) {
            printf("%d %d\n",n-1,edge[i].w);
            break;
        }
    }
    return 0;
 
}