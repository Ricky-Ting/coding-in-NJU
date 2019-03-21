#include<cstdio>
int n,m;
int v[1000007];
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) 
		scanf("%d",&v[i]);
	double maxm=0; int a,b,c;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&c);
		maxm = (maxm> double((v[a]+v[b]))/double(c))?maxm:double((v[a]+v[b]))/double(c);
	}
	printf("%.6lf\n",maxm);
}	