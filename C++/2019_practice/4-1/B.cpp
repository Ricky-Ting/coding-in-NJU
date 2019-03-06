#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 1005
#define MAXM 1005
using namespace std;
const double EPS = 1e-8;

int id[MAXN+MAXM] = {};
double v[MAXN] = {};
double a[MAXM][MAXN] = {};
int n,m;
int N,M;
struct node{
  int in_counter;
  int out_counter;
  int in_edge[MAXM];
  int out_edge[MAXM];
}point[MAXN];

int sgn(double x) {
  if (x < -EPS) return -1;
  return x > EPS ? 1 : 0;
}

void pivot(int r, int c) {
  swap(id[n + r], id[c]);
  double x = -a[r][c];
  a[r][c] = -1;
  for (int i = 0; i <= n; ++i) a[r][i] /= x;
  for (int i = 0; i <= m; ++i) {
    if (sgn(a[i][c]) && i != r) {
      x = a[i][c];
      a[i][c] = 0;
      for (int j = 0; j <= n; ++j) a[i][j] += x * a[r][j];
    }
  }
}

int simplex() {
  /* important: revert symbols of conditions */
  /* bug fixed thanks to TuoMianZiGan */
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      a[i][j] *= -1;
    }
  }
  for (int i = 1; i <= n; ++i) id[i] = i;
  /* initial-simplex */
  while (true) {
    int x = 0, y = 0;
    for (int i = 1; i <= m; ++i) {
      if (sgn(a[i][0]) < 0) { x = i; break; }
    }
    if (!x) break;
    for (int i = 1; i <= n; ++i) {
      if (sgn(a[x][i]) > 0) { y = i; break; }
    }
    if (!y) return -1; // infeasible
    pivot(x, y);
  }
  /* solve-simplex */
  while (true) {
    int x = 0, y = 0;
    for (int i = 1; i <= n; ++i) {
      if (sgn(a[0][i]) > 0) { x = i; break; }
    }
    if (!x) break; // finished
    double w = 0, t = 0; bool f = true;
    for (int i = 1; i <= m; ++i) {
      if (sgn(a[i][x]) < 0) {
        t = -a[i][0] / a[i][x];
        if (f || t < w) {
          w = t, y = i, f = false;
        }
      }
    }
    if (!y) { return 1; } // unbounded
    pivot(y, x);
  }
  for (int i = 1; i <= n; ++i) v[i] = 0;
  for (int i = n + 1; i <= n + m; ++i) v[id[i]] = a[i - n][0];
  return 0;
}


int solve(){
  memset(a,0,sizeof(a));
  scanf("%d%d",&N,&M);
  n=(M+2)*2; m=2*N+(M+2);
  
  for(int i=0;i<=N+2;i++){
    point[i].in_counter=point[i].out_counter=0;
  }
  int from,to;
  for(int i=1;i<=M;i++){
    scanf("%d%d",&from,&to);
    from++; to++;
    point[from].out_edge[point[from].out_counter]=i; point[from].out_counter++;
    point[to].in_edge[point[to].in_counter]=i; point[to].in_counter++;
  }
  int A,B,C;
  scanf("%d%d%d",&A,&B,&C);
  A++; B++; C++;
  //N+1 implies A', N+2 implies B'
  //M+1 implies A'A, M+2 implies B'B
  point[A].in_edge[point[A].in_counter]=M+1; point[A].in_counter++;
  point[N+1].out_edge[0]=M+1; point[N+1].out_counter=1; 

  point[B].in_edge[point[B].in_counter]=M+2; point[B].in_counter++;
  point[N+2].out_edge[0]=M+2; point[N+2].out_counter=1; 

  a[0][M+1]=1; a[0][M+2+M+2]=1;
  for(int i=1;i<=M+2;i++) {
    a[i][i]=1; a[i][i+M+2]=1; a[i][0]=1;
  }

  int point_counter=1;
  for(int i=(M+2)+1; i<=(M+2)+N;i++) {
    if( (point_counter==(N+1)) || ( point_counter == (B) )  )
      point_counter++;
    for(int j=0;j<point[point_counter].in_counter;j++){
      a[i][point[point_counter].in_edge[j]]=1;
    }
    for(int j=0;j<point[point_counter].out_counter;j++){
      a[i][point[point_counter].out_edge[j]]=-1;
    }
    point_counter++;
  }

  point_counter=1;
  for(int i=(M+2)+N+1; i<=(M+2)+N+N;i++) {
    if( (point_counter==(N+2)) || ( point_counter == (C) )  )
      point_counter++;
    for(int j=0;j<point[point_counter].in_counter;j++){
      a[i][point[point_counter].in_edge[j]+M+2]=1;
    }
    for(int j=0;j<point[point_counter].out_counter;j++){
      a[i][point[point_counter].out_edge[j]+M+2]=-1;
    }
    point_counter++;
  }
 
  simplex();
  if(int(a[0][0])==2)
    printf("yes\n");
  else
    printf("no\n");
  
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}