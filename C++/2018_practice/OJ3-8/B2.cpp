#include<cstdio>
#include<algorithm>
#include<iostream>
#define NODE 410
using namespace std;

int n, m;

struct Node{
	int head;
	int d;
} node[NODE];

struct Edge{
	int n;
	int v;
	bool c;
	int oppos;
} edge[42000];
int P;

bool check[NODE];
//int number = 0;
int deep = 1;
bool dfs(int u){
	//number++;
	//if(number >= 1000)
	//	return false;
	if(deep == n)
		return true;
	int now = node[u].head;
	while(edge[now].n != -1){
		int v = edge[now].v;
		if(check[v]){
			now = edge[now].n;
			continue;
		}
		check[v] = true;
		deep++;
		if(dfs(v))
			return true;
		deep--;
		check[v] = false;
		now = edge[now].n;
	}
	return false;
}

int dep = 0;
bool get_path(int u, int fa){
	if(dep == m)
		return true;
	int now = node[u].head;
	while(edge[now].n != -1){
		//cout << "# " << u << " " << now << endl;
		/*
		if(edge[now].v == fa){
			edge[now].c = true;
		}
		*/
		if(edge[now].c ){
			now = edge[now].n;
			//node[u].head = now;
			continue;
		}
		else{
			
			int v = edge[now].v;
			edge[now].c = true;
			edge[edge[now].oppos].c = true;
			dep++;
			if(get_path(v, u)){
				//cout << dep << " ";
				//dep--;
				printf("%d %d\n", u, v);
				return true;
			}
			edge[now].c = false;
			edge[edge[now].oppos].c = false;
			dep--;
			now = edge[now].n;
		}
	}
	return false;
}

int main(){
	//number = 0;
	P = 1;
	scanf("%d %d", &n, &m);
	for(int i(1);i <= n;i++){
		node[i].head = i;
		node[i].d = 0;
		edge[i].n = -1;
		check[i] = false;
		P++;
	}
	
	int reduce = 0;
	for(int i(0);i < m;i++){
		int u, v;
		scanf("%d %d", &u, &v);
		
		edge[P].n = node[u].head;
		edge[P].v = v;
		edge[P].c = false;
		edge[P].oppos = P+1;
		node[u].head = P;
		node[u].d++;
		P++;
		
		if(u == v){
			node[v].d++;
			edge[P-1].oppos-1;
			reduce++;
			continue;
		}
		
		swap(u, v);
		edge[P].n = node[u].head;
		edge[P].v = v;
		edge[P].c = false;
		edge[P].oppos = P-1;
		node[u].head = P;
		node[u].d++;
		P++;
	}
	//m -= reduce;
	
	int odd = 0;
	//int odd1, odd2 = 1;
	int only = 0;
	for(int i(1);i <= n;i++){
		if(node[i].d%2 == 1){
			odd++;
			//odd1 = odd2;
			//odd2 = i;
		}
		if(node[i].d == 1){
			only++;
		}
	}

	
	bool is_meet_girl = false;
	bool is_meet_boss = false;
	if(only > 2){
		is_meet_girl = true;
	}
	else if(only == 0){
		check[1] = true;
		if(!dfs(1))
			is_meet_girl = true;
	}
	else{
		int start = 0;
		for(int i(1);i <= n;i++){
			if(node[i].d == 1){
				start = i;
				break;
			}
		}
		check[start] = true;
		if(!dfs(start))
			is_meet_girl = true;
	}
	if(odd != 0){
		is_meet_boss = true;
	}

	if(is_meet_girl){
		printf("Miss Shizue\n");
		return 0;
	}
	
	if(is_meet_boss){
		printf("Miss Leon\n");
		return 0;
	}
	
	printf("Find Leon\n");
	
	get_path(1, 0);
}

/*
5
10
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 4
3 5
4 5

7
21
1 2
1 3
1 4
1 5
1 6
1 7
2 3
2 4
2 5
2 6
2 7
3 4
3 5
3 6
3 7
4 5
4 6
4 7
5 6
5 7
6 7
*/
