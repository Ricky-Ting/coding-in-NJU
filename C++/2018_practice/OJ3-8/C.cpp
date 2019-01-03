#include<cstdio>
using namespace std;
#define MAXN 1002
int n;
int a[MAXN][MAXN];
int path[MAXN];
void input() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
}


void solve() {
	path[1]=1;
	for(int i=2;i<=n;i++) {
		if(a[i][path[1]]==1) {
			for(int j=i;j>=2;j--) 
				path[j]=path[j-1];
			path[1]=i;
		}

		else if(a[path[i-1]][i]==1) {
			path[i]=i;
		}

		else {
			for(int j=2;j<=i;j++) {
				if(a[path[j-1]][i] && a[i][path[j]]) {
					for(int k=i;k>j;k--)
						path[k]=path[k-1];
					path[j]=i;
					break;
				}
			}
		} 
	}
	printf("%d\n",n);
	for(int i=1;i<=n;i++)
		printf("%d ",path[i]);
	printf("-1\n");
}

int main(){
	input();
	solve();
}