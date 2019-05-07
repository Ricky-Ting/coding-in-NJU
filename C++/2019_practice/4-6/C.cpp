#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long 
#define MAXT 1000010
#define MAXN 1000010
#define MAXS 1000010
using namespace std;
char TT[MAXT];
int v[MAXT];
long long n,K;
ll ans=0;
long long P=0;
void dfs(int node, int cur, int dept);
void dfs2(int node);
struct Trie {
	int nxt[MAXN+10][26], tot, root;
	Trie(){
		tot = 1;
		root = newNode();
	}
	int newNode() {
		memset(nxt[tot], 0, sizeof(nxt[tot]));
		return tot++;
	}
	void append(char *s) {
		int cur = root;
		for(; *s != 0; s++) {
			int id = *s - 'a';
			if(nxt[cur][id]==0)
				nxt[cur][id] = newNode();
			cur = nxt[cur][id];
		}
	}
} s;
struct SeqAM{
	int nxt[MAXN+10][26], tot, root, val[MAXN+10];
	SeqAM() {
		tot = 1;
		root = newNode();
	}
	int newNode(){
		memset(nxt[tot], 0, sizeof(nxt[tot]));
		val[tot] = 0;
		return tot++;
	}
	void build(char *s, int *v) {
		int n = strlen(s);
		for(int i=0;i<n;i++) 
			val[newNode()] = v[i];
		for(int i=n-2; i>=-1; i--) {
			memcpy(nxt[i+2], nxt[i+3], sizeof(nxt[i+3]));
			nxt[i+2][s[i+1] - 'a'] = i+3;
		}
	}
} T;

ll qpow(ll a, ll n, ll mod) {
	ll ans = 1;
	a %= mod;
	while(n>0) {
		if(n&1)
			(ans *= a)%= mod;
		(a*=a) %= mod;
		n>>=1;
	}
	return ans;
}

int main(void) {
	scanf("%s",TT);
	int len = strlen(TT);
	for(int i=0;i<len;i++) 
		scanf("%d",&v[i]);
	scanf("%lld%lld",&n,&K);
	char ss[MAXS];
	for(int i=0;i<n;i++) {
		scanf("%s",ss);
		//int len2 = strlen(ss);
		/*
		for(int i=1;i<=len2;i++) {
			sprintf(buf,"%s",ss);
			buf[i]='\0';
			s.append(buf);
		}
		*/
		s.append(ss);
	}
	T.build(TT,v);
	dfs(s.root,1,0);
	dfs2(s.root);
	//printf("num=%lld \n ans=%lld\n",P,ans);


	ll niyuan = qpow(P,K-2,K);
	ans = (niyuan*ans)%K; 
	printf("%lld\n",ans);
}

void dfs(int node, int cur, int dept) {
	if(cur==0)
		return;
	for(int i=0;i<26;i++) {
		if(s.nxt[node][i]!=0) 
			dfs(s.nxt[node][i],T.nxt[cur][i],dept+1);
		
	}
	ans += (v[cur-2]*dept);
	ans %= K;
	
}

void dfs2(int node) {

	for(int i=0;i<26;i++) {
		if(s.nxt[node][i]!=0) 
			dfs2(s.nxt[node][i]);
	}
	if(node!=s.root)
		P++;
}