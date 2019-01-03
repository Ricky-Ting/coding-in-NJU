#include<iostream>
#include<queue>
using namespace std;
struct cmp1 {
	bool operator () (long long &a, long long &b) {
		return a>b;
	}
};

int n;

int main(void) { 
	scanf("%d",&n);
	long long tmp;
	long long res;
	res=0;
	priority_queue <long long,vector<long long>,cmp1> pq;
	for(int i=0;i<n;i++) {
		scanf("%lld",&tmp);
		pq.push(tmp);
	}
	long long a,b,c;
	if(pq.size()==1)
	{
		printf("%lld\n",pq.top());
		return 0;
	}
	while(pq.size()>1) {
		if((pq.size()%2)==1) {
			a=pq.top(); pq.pop();
			b=pq.top(); pq.pop();
			c=pq.top(); pq.pop();
			res+=(a+b+c);
			pq.push(a+b+c);
		}
		else {
			a=pq.top(); pq.pop();
			b=pq.top(); pq.pop();
			res+=(a+b);
			pq.push(a+b);
		}
	}
	printf("%lld\n",res);
}