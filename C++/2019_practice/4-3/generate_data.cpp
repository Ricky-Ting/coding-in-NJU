#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int n,m;
int main() {
	srand((unsigned)time(NULL) );
	n = rand()%12 + 1;
	m = rand()%12 + 1;
   	cout<<m<<" "<<n<<endl;
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			cout<<rand()%2<<" ";
		}
		cout<<endl;
	}	

}
