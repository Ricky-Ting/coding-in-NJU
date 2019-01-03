#include<iostream>
#include<algorithm>
using namespace std;
struct point{
	int start;
	int end;
};
void input(void);
void solve(void);
int current=0;
point times[10005];
int T,E,C;
int n;
bool cmp(const point &x, const point &y) {
	return x.end < y.end;
}

int main(void){
	scanf("%d",&T);
	for(int i=0;i<T;i++) {
		input();
		solve();
	}
	return 0;
}

void input(void) {
	scanf("%d%d%d",&n,&E,&C);
	for(int i=0;i<n;i++)
		scanf("%d%d",&times[i].start,&times[i].end);
}

void solve(void) {
	sort(times,times+n,cmp);
	current=0;
	for(int i=0;i<n;i++) {
		if(times[i].start<current)
			continue;
		else {
			E-=C;
			current=times[i].end;
			if(E<0) {
				printf("Bad Ending\n");
				return;
			}
		}
	}
	if(E>=0)
		printf("Good Ending\n");
	return;
}