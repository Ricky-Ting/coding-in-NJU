#include<iostream>
#include<map>
using namespace std;

struct node {
	int f;
	int re;
	bool is_wake;
};
node s[300005];

int T,K;
int mycounter;
int ans=0;
map<string,int> StudentName;

void input();


int main(void) {
	cin>>T;
	for(int i=0;i<T;i++){
		input();
		printf("%d\n",ans);
	}
}

int Find_Set(int a) {
	if(a==s[a].f)
		return a;
	int fa=s[a].f;
	s[a].f=Find_Set(fa);
	s[a].re=(s[fa].re+s[a].re)%3;
	return s[a].f;
}

void Make_Set(int a) {
	s[a].f=a;
	s[a].re=0;
	s[a].is_wake=true;
}

int getid(string &name) {
	map<string,int>::iterator it;
	it=StudentName.find(name);
	if(it!=StudentName.end())
		return it->second;
	else {
		//printf("counter=%d",counter);
		Make_Set(mycounter);
		StudentName[name]=mycounter;
		mycounter++;
		return mycounter-1;
	}
}


void input() {
	cin>>K;
	int op;
	StudentName.clear();
	ans=0;
	mycounter=0;
	for(int i=0;i<K;i++) {
		cin>>op;
		if(op==0) {
			string s1,s2;
			int id1,id2,fa1,fa2;
			cin>>s1>>s2;
			id1=getid(s1);
			id2=getid(s2);
			if(id1==id2)
				continue;
			fa1=Find_Set(id1); fa2=Find_Set(id2);
			if(fa1!=fa2) {
				s[fa2].f=fa1;
				s[fa2].re=(s[id1].re-s[id2].re+3)%3;
			}
			else {
				if(s[id1].re!=s[id2].re) {
					ans++;
					continue;
				}
			}
			s[id1].is_wake=s[id2].is_wake=false;
		}
		else if(op==1) {
			string s1,s2;
			int id1,id2,fa1,fa2;
			cin>>s1>>s2;
			id1=getid(s1);
			id2=getid(s2);
			if(id1==id2) {
				ans++;
				continue;
			}
			fa1=Find_Set(id1); fa2=Find_Set(id2);
			if(fa1!=fa2) {
				s[fa2].f=fa1;
				s[fa2].re=(s[id1].re-s[id2].re+1+3)%3;
			}
			else {
				if( ((s[id2].re-s[id1].re+3)%3)!=1) {
					ans++;
					continue;
				}
			}
			s[id1].is_wake=s[id2].is_wake=false;
		}
		else if(op==2) {
			string s1;
			int id1;
			cin>>s1;
			id1=getid(s1);
			if(s[id1].is_wake) {
				ans++;
				continue;
			}
			Make_Set(mycounter);
			StudentName[s1]=mycounter;
			mycounter++;
		}

		else if(op==3) {
			string s1;
			int id1;
			cin>>s1;
			id1=getid(s1);
			if(!s[id1].is_wake) {
				ans++;
			}
		}
	}
}