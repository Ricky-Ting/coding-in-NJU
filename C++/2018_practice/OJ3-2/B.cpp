#include<iostream>
#include<queue>
using namespace std;
struct node{
	long long ha;
};
struct node2{
	int un;
	int day;
};
void input(void);
void solve(void);
node happy[20004];
node2 unhappy[20004];
int T,n,h;
int wake[20004];
int day;
bool ishappy;
int main(void) {
	scanf("%d",&T);
	for(int i=0;i<T;i++) {
		input();
		if(!ishappy) {
			printf("Bob will be unhappy!\n");
			continue;
		}
		solve();
		printf("%d %lld\n",day,happy[n-1].ha);
	}
	return 0;
}

void input(void) {
	ishappy=true;
	int tmp;
	scanf("%d%d",&n,&h);
	
	scanf("%lld",&happy[0].ha);
	happy[0].ha+=h;
	if(happy[0].ha<=0) 
		ishappy=false;
	for(int i=1;i<n;i++) {
		scanf("%d",&wake[i]);
		happy[i].ha=happy[i-1].ha+wake[i];
		if(happy[i].ha<=0) 
			ishappy=false;
	}
	for(int i=0;i<n;i++) {
		scanf("%d",&unhappy[i].un);
		unhappy[i].day=i;
	}
	long long add=0;
	for(int i=0;i<n;i++) {
		add+=unhappy[i].un;
		happy[i].ha-=add;
	}
	return;
}

void solve(void) {
	priority_queue <int> pq;
	day=n;
	long long add=0;
	for(int i=0;i<n;i++) {
		pq.push(unhappy[i].un);
		happy[i].ha+=add;
		if(happy[i].ha>0)
			continue;
		else {
			while(happy[i].ha<=0) {
				happy[i].ha+=pq.top();
				add+=pq.top();
				pq.pop();
				day--;
			}
		}
	}
}
