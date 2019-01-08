#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define MAXN 500
struct node{
	int x;
	int y;
	bool add;
};
node an[MAXN];
node bn[MAXN];

int i,j,n;
int a,b;
int l[1010],lx[1010],ly[1010],s[1010];
int vx[1010],vy[1010],w[1010][1010];
inline int max(int a,int b){return (a>b)?a:b;}
inline bool dfs(int p){
	int i=0,t=0;
	vx[p]=1;
	for (i=1;i<=n;i++){
		if (vy[i])	continue;
		t=lx[p]+ly[i]-w[p][i];
		if (t==0)	{
			vy[i]=1;	if (l[i]==-1||dfs(l[i]))	{l[i]=p;	return true;}
		}	else if (s[i]>t)	s[i]=t;
	}
	return false;
}
inline int km(){
	int i=0,j=0,x=0,d=0,ans=0;
	memset(l,-1,sizeof(l));	memset(ly,0,sizeof(ly));
	for (x=1;x<=n;x++){
		memset(s,0x3f3f3f3f,sizeof(s));
		while (1){
			memset(vx,0,sizeof(vx));	memset(vy,0,sizeof(vy));
			if (dfs(x))	break;
			d=0x3f3f3f3f;
			for (i=1;i<=n;i++)	if (!vy[i]&&d>s[i])	d=s[i];
			for (i=1;i<=n;i++)	if (vx[i])	lx[i]-=d;
			for (i=1;i<=n;i++)	if (vy[i])	ly[i]+=d;	else s[i]-=d;
		}
	}
	for (i=1;i<=n;i++)	if (l[i]>-1)	ans+=w[l[i]][i];
	return ans;
}
int main (){
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) {
		scanf("%d%d",&an[i].x,&an[i].y);
		an[i].add=false;
	}

	for(int i=1;i<=b;i++) {
		scanf("%d%d",&bn[i].x,&bn[i].y);
		bn[i].add=false;
	}
	n=max(a,b);
	for(int i=a+1;i<=n;i++) 
		an[i].add=true;
	for(int i=b+1;i<=n;i++) 
		bn[i].add=true;

	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++){
			if(an[i].add || bn[j].add)
				w[i][j]=0;
			else {
				w[i][j]=-abs(an[i].x-bn[j].x)-abs(an[i].y-bn[j].y);
			}
			lx[i]=max(lx[i],w[i][j]);	
		}
	printf("%d\n",-km());
return 0;
}