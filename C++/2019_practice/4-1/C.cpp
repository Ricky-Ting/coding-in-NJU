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


int main(){
  scanf("%d%d",&N,&M);
  n=M; m=2*N+M;
  for(int i=0;i<=N;i++){
    point[i].in_counter=point[i].out_counter=0;
  }
  int from,to,w;
  for(int i=1;i<=M;i++){
    scanf("%d%d%d",&from,&to,&w);
    a[0][i]=w;
    point[from].out_edge[point[from].out_counter]=i; point[from].out_counter++;
    point[to].in_edge[point[to].in_counter]=i; point[to].in_counter++;
  }
  for(int i=1;i<=M;i++){
    a[i][i]=1;
    a[i][0]=1;
  }
  for(int i=M+1;i<=M+N;i++){
    for(int j=0;j<point[i-M].in_counter;j++){
      a[i][point[i-M].in_edge[j]]=1;
      a[i+N][point[i-M].in_edge[j]]=-1;
    }
    for(int j=0;j<point[i-M].out_counter;j++){
      a[i][point[i-M].out_edge[j]]=-1;
      a[i+N][point[i-M].out_edge[j]]=1;
    }
    a[i][0]=0;
    a[i+N][0]=0;
  }
  simplex();
  printf("%d\n",int(a[0][0]));
}