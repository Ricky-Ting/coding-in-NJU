#include<cstdio>
using namespace std;

int f[100005],r[100005];
int n,m,t;
char c;
int x,y;
void Make_Set(int i) {
	f[i]=i;
	r[i]=0;
	return;
}

int Find_Set(int i) {
	if(i==f[i])
		return i;
	int p=f[i];
	f[i]=Find_Set(f[i]);
	r[i]=(r[i]+r[p])%2;
	return f[i];
}

void Union_Set(int a, int b) {
	int pa,pb;
	pa=Find_Set(a); pb=Find_Set(b);
	f[pa]=pb; 
	r[pa]=(r[a]+r[b]+1)%2;
	return;
}


int main(void) {
	scanf("%d",&t);
	for(int i=0;i<t;i++) {
		scanf("%d%d",&n,&m);
		getchar();

		for(int i=1;i<=n;i++)  //这道题N从1开始 注意分辨
			Make_Set(i);

		for(int i=0;i<m;i++) {
			scanf("%c%d%d",&c,&x,&y);
			getchar();
			if(c=='D')
				Union_Set(x,y);
			else {
				if(Find_Set(x)!=Find_Set(y)) 
					printf("Not sure yet.\n");
				else {
					if(r[x]==r[y])
						printf("In the same gang.\n");
					else
						printf("In different gangs.\n");
				}
			}
		}
	}
	return 0;

}