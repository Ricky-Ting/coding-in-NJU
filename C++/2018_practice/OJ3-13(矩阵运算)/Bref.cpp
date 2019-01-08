#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const double eps=1e-9;
const int MAXN=220;
double a[MAXN][MAXN],x[MAXN];//  a和x分别为方程的左边的矩阵和等式右边的值，求解之后x存的就是结果
int equ,var;//  方程数和未知数个数
//  返回0表示无解，1表示有解
int N,M,u,v;
int Gauss(){
    int i,j,k,col,max_r;
    for(k=0,col=0;k<equ&&col<var;k++,col++){
        max_r=k;
        for(i=k+1;i<equ;i++)if(fabs(a[i][col])>fabs(a[max_r][col]))max_r=i;
        if(fabs(a[max_r][col])<eps)return 0;
    printf("After sawp\n");
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++)
            printf("%lf ", a[i][j]);
        printf("\n");
    }   
     printf("\n");

     for(int i=0;i<N;i++)
        printf("%lf ", x[i]);
    printf("\n\n");

        if(k!=max_r){
            for(j=col;j<var;j++)swap(a[k][j],a[max_r][j]);
            swap(x[k],x[max_r]);
        }x[k]/=a[k][col];
        for(j=col+1;j<var;j++)a[k][j]/=a[k][col];
        a[k][col]=1;

        for(i=0;i<equ;i++)if(i!=k){
            x[i]-=x[k]*a[i][k];
            for(j=col+1;j<var;j++)a[i][j]-=a[k][j]*a[i][col];
            a[i][col]=0;
        }

        /*
        for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++)
            printf("%lf ", a[i][j]);
        printf("\n");
    }   
    */

    }
    return 1;
}

double r;
void solve(){
    memset(a,0,sizeof(a));
    for(int i=0;i<M;i++){
        scanf("%d%d%lf",&u,&v,&r);
        --u;--v;
        double s=1.0/r;
        a[u][u]+=s;
        a[v][v]+=s;
        a[u][v]-=s;
        a[v][u]-=s;
    }//a[N-1][N-1]+=1;
    printf("初始值\n");
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++)
            printf("%lf ", a[i][j]);
        printf("\n");
    }   
     printf("\n");
    x[0]=1.0; x[N-1]=-1.0;
    equ=N; var=N;
    Gauss();
    printf("%.2f\n",x[0]);
}
int main(){
    while(~scanf("%d%d",&N,&M))solve();
    return 0;
}