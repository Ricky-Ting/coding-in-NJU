#include<iostream>
using namespace std;
#include<time.h>

struct node
{
	int x;
	int y;
};

int n,m;

int data[20][20];

int T;
node startpoint,endpoint;

int main() {
	srand((int)time(0));

	T=rand()%3+1;   //100
	for(int i=0;i<T;i++) {
		n=rand()%4+1;  //20
		m=rand()%4+2;   //19
		cout<<m<<" "<<n<<endl;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++) 
				data[i][j]=rand()%2;
		startpoint.x=rand()%n;
		startpoint.y=rand()%m;
		endpoint.x=rand()%n;
		endpoint.y=rand()%m;
		while(startpoint.x==endpoint.x && startpoint.y==endpoint.y) {
			endpoint.x=rand()%n;
			endpoint.y=rand()%m;

		}
		data[startpoint.x][startpoint.y]=2;
		data[endpoint.x][endpoint.y]=3;
		for(int i=0;i<n;i++) { 
			for(int j=0;j<m;j++)
				cout<<data[i][j]<<" ";
			cout<<endl;
		}
	}
	cout<<"0 0"<<endl;
	
}
