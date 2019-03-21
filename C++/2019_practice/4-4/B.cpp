#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXN 100006
int n,k,l;
int a[MAXN];
int volume[MAXN];
int used[MAXN];
int main() {
	memset(used,0,sizeof(used));
	memset(volume,0,sizeof(volume));
	scanf("%d%d%d",&n,&k,&l);
	for(int i=0;i<n*k;i++) {
		scanf("%d",&a[i]);
	}
	sort(a,a+n*k);
	volume[0] = a[0];
	used[0]=1;
	int flag=0;
	for(int i=1; i<n ;i++) {
		for(int j =i*k ; j>=0; j--){
			if(!used[j] && a[j]-a[0]<=l) {
				used[j]=1;
				volume[i] = a[j];
				break;
			}
			if(j==0)
				flag=1;
		}
	}
	int ans=0;
	for(int i=0;i<n;i++) {
		ans += volume[i];
	}
	if(flag)
		ans =0;
	printf("%d\n",ans);
}