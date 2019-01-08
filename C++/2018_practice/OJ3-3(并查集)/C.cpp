#include<iostream>
#include<cstring>
using namespace std;
struct node{
	int value;
	int maximum;
	node* head;
} a[100005];
int n,m;
char str[10];
int d;

void solve();
void Make_Set(int i) {
	a[i].value=1;
	a[i].maximum=i;
	a[i].head=&a[i];
	return;
}

inline int Find_Set(int j){
	return (a[j].head->maximum==n)?-1:a[j].head->maximum;
}

void Union_Set(int p, int q) {
	a[p].head->maximum=a[q].head->maximum;
	for(int i=q;i<=a[q].head->maximum;i++) 
		a[i].head=a[p].head;
	
}


int main(void) {
	scanf("%d%d",&n,&m);
	solve();
	return 0;
}

void solve() {
	for(int i=0;i<=n;i++) {
		Make_Set(i); 
	}
	for(int i=0;i<m;i++) {
		scanf("%s",str);
		if(str[0]=='F'){
			scanf("%d",&d);
			printf("%d\n",Find_Set(d));
		}
		if(str[0]=='K'){
			scanf("%d",&d);
			Union_Set(d,d+1);
		}
	}
	
	return;

}