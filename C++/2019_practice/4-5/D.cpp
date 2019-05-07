#include <cstdio>
#include <map>
#include <cstring>
#define MAXN 10010
using namespace std;
int n,m;
int counter = 0;
int fa[MAXN], val[MAXN];
map <int, int> my_map;
void make_set(int a) {
	fa[a] = a;
	return ;
}

int find_set(int a) {
	if(fa[a]==a)
		return a;
	int tmp = find_set(fa[a]);
	val[a] = (val[a] + val[fa[a]]) % 2;
	return fa[a] = tmp;
}

int union_set(int x, int y, int d) {
	int a = find_set(x);
	int b = find_set(y);
	if(a == b) {
		if( (val[x] - val[y] + 4) % 2 == d )
			return 1;
		else
			return 0;
	} else {
		fa[a] = b;
		val[a] = (val[y] - val[x] + d + 4) % 2;
		return 1;
	}
}

int get_map(int a) {
	if(my_map.find(a) == my_map.end())
		my_map[a] = counter++;
	return my_map[a];
}


int main() {
	scanf("%d%d",&n,&m);
	
	int i; 
	char s[10]; int d,a,b; 
	for(int i=0;i<MAXN;i++) 
		make_set(i);
	memset(val,0,sizeof(val));

	for(i=0; i<m; i++) {
		scanf("%d%d%s",&a,&b,s);
		a--;
		int x = get_map(a);
		int y = get_map(b);
		if(s[0] == 'o')
			d = 1;
		else
			d = 0;
		if(union_set(x,y,d) == 0) break;
	}
	printf("%d\n",i);
}