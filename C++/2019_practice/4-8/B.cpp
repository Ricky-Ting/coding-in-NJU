#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define MAXN 600
int dire[8][2] = {
	2,1,
	2,-1,
	-2,1,
	-2,-1,
	1,2,
	1,-2,
	-1,2,
	-1,-2
};
int isvis[MAXN][MAXN];
char fig[MAXN][MAXN];
struct node
{
	int x;
	int y;
	int dis;
	int way;
};
int h,w;
int mini[MAXN][MAXN];
int way[MAXN][MAXN];
int satifsy(int a, int b);
int main() {
	scanf("%d%d",&h,&w);
	char buf[MAXN];
	getchar();
	for(int i=1;i<=h;i++) {
		cin.getline(buf,MAXN);
		//cout<<buf<<endl;

		for(int j=1; j<=w; j++) {
			fig[i][j] = buf[j-1];
		}
	}
	
	memset(isvis,0,sizeof(isvis));
	memset(way,0,sizeof(way));
	way[1][1]=1;
	queue<node> Q;
	node tmp; tmp.x=1; tmp.y=1; tmp.dis =0; tmp.way =1;
	isvis[tmp.x][tmp.y]=1;
	Q.push(tmp);
	while(!Q.empty()) {
		node cur = Q.front(); Q.pop();
		//printf("cur %d %d\n",cur.x,cur.y );
		if(fig[cur.x][cur.y]!=' ' && fig[cur.x][cur.y]!='0') {
			cur.dis+=1;
			Q.push(cur);
			fig[cur.x][cur.y]= fig[cur.x][cur.y]-1;
			continue;
		}
		//cout<<"H"<<endl;
		for(int i=0;i<8;i++) {
			int nx = cur.x + dire[i][0];
			int ny = cur.y + dire[i][1];
			if(satifsy(nx,ny) && fig[nx][ny]!='#') {
				//cout<<"n"<<nx<<" "<<ny<<endl;
				if(fig[nx][ny]==' ') {
					if(isvis[nx][ny]) {
						if(cur.dis+1 <= mini[nx][ny]) {
							way[nx][ny] += way[cur.x][cur.y];
						}
					} else {
						node tmp2; tmp2.x=nx; tmp2.y = ny; tmp2.dis = cur.dis+1;
						way[nx][ny]+=way[cur.x][cur.y];
						mini[nx][ny] = tmp2.dis;
						//printf("Here %d %d\n",nx,ny);
						isvis[nx][ny]=1;
						Q.push(tmp2);
					}
				} else {
					//cout<<"E"<<endl;
					if(isvis[nx][ny]) {
						if(cur.dis+1<=mini[nx][ny]) 
							way[nx][ny]+=way[cur.x][cur.y];
					}
					else {
						node tmp2; tmp2.x = nx; tmp2.y = ny; tmp2.dis = cur.dis+1;
						way[nx][ny]+=way[cur.x][cur.y];
						isvis[nx][ny]=1;
						mini[nx][ny] = tmp2.dis;
						Q.push(tmp2);
					}
				}
			}
		}
	}
	if(!isvis[h][w])
		cout<<"endless nightmare..."<<endl;
	else
		cout<<mini[h][w]<<" "<<way[h][w]<<endl;
		
}

int satifsy(int a, int b) {
	if(a<1 || a>h)
		return 0;
	if(b<1 || b>w)
		return 0;
	return 1;
}