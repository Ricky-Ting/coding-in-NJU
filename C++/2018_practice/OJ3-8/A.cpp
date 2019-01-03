#include<iostream>
#include<string>
#include<cstring>
using namespace std;
#define MAXN 100005
int n;
int a[27][2];  //0 入度  //1出度
bool iscon[27][27];



void input() {
	cin>>n;
	//cout<<n<<endl;
	string s;
	memset(a,0,sizeof(a));
	for(int i=0;i<27;i++)
		for(int j=0;j<27;j++)
			iscon[i][j]=false;
	for(int i=0;i<27;i++)
		iscon[i][i]=true;
	int from,to;
	bool output=false;
	if(n==4)
		output=false;
	for(int i=0;i<n;i++){
		cin>>s;
		if(output)
			cout<<s<<endl;
		from=s[0]-97;
		to=s[s.size()-1]-97;
		a[from][0]++;
		a[to][1]++;
		iscon[from][to]=iscon[to][from]=true;
	}
	//for(int i=0;i<26;i++)
	//	cout<<a[i][0]<<" "<<a[i][1]<<" ";
}

void solve() {
	bool flag;
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++) {
			if((a[i][0]==0 && a[i][1]==0) || (a[j][0]==0 && a[j][1]==0))
				continue;
			flag=false;
			if(iscon[i][j])
				continue;
			else
				for(int k=0;k<26;k++)
					if(iscon[i][k] && iscon[k][j])
						flag=true;
			if(!flag) {
				cout<<"Nothing"<<endl;
				return;
			}
		}
	bool chudu=false;
	bool rudu=false;
	bool gold=true;
	for(int i=0;i<26;i++) {
		if(a[i][0]==a[i][1])
			continue;
		else if(a[i][0]==a[i][1]+1) {
			if(chudu) {
				gold=false;
				break;
			}
			else
				chudu=true;
			
		}
		else if(a[i][0]+1==a[i][1]) {
			if(rudu) {
				gold=false;
				break;
			}
			else
				rudu=true;
		}
		else {
			gold=false;
			break;
		}
	}
	if(gold) {
		cout<<"Gold"<<endl;
		return;
	}
	int cnt=0;
	for(int i=0;i<26;i++) {
		if((a[i][0]+a[i][1])%2!=0) {
			cnt++;
		}
	}
	if(cnt==0 || cnt==2)
		cout<<"Silver"<<endl;
	else
		cout<<"Nothing"<<endl;
	return;

}
int main(){
	input();
	solve();
}