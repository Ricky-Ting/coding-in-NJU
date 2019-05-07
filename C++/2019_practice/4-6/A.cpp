#include <iostream>
#include <cstdio>
#include <string>
#define MAXN 10006

using namespace std;

int pi[MAXN];
int m;
int n;
string T;
string P;


void compute_pi(void) {
	//int m = strlen(P);
	pi[1] = 0;
	int k = 0;
	for(int q =2; q<=m; q++) {
		while(k>0 && P[k] != P[q-1]) 
			k = pi[k];
		if(P[k] == P[q-1])
			k = k + 1;
		pi[q] = k;
	}

	return;
}



int main(void){
	cin>>T;
	cin>>P;
	m = P.length();
	n = T.length();
	compute_pi();
	int flag = 0;
	int q = 0;
	for(int i=1; i<=n; i++) {
		while(q>0 && P[q] != T[i-1])
			q = pi[q];
		if(P[q] == T[i-1])
			q++;
		if(q == m) {
			cout<< i-m+1 <<endl;
			flag = 1;
			q = pi[q];
		}
		
	}

	if(!flag)
		cout<<"nmdwsm"<<endl;

}