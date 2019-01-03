#include<iostream>
#include<queue>
#include<string>
using namespace std;

struct node
{
    int x;
    int y;
};

int n;
char maze[101][101];  //0:墙   1:空地    2:起点   3:终点  4:J哥
char maze2[101][101];
int m;
node start,myend;
node mymove[4];


node chal[11];



void input() {
    string s;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        cin>>s;
        for(int j=0;j<n;j++) {
            maze[i][j]=s[j];
            if(maze[i][j]=='S') {
                start.x=i;
                start.y=j;
            }
            if(maze[i][j]=='D') {
                myend.x=i;
                myend.y=j;
            }
            if(maze[i][j]>=49 && maze[i][j]<=57) {
                chal[maze[i][j]-48].x=i;
                chal[maze[i][j]-48].y=j;
            }
            
        }
    }
}
bool satisfy(int vx, int vy) {
    if(vx<0 || vx>=n)
        return false;
    if(vy<0 || vy>=m)
        return false;
    return true;
}


int BFS(int sx, int sy, int ex, int ey) {
    queue<int> q1,q2,q3;
    q1.push(sx); q2.push(sy); q3.push(0);
    while(!q1.empty()) {
        int vx=q1.front(); int vy=q2.front(); int depth=q3.front();
        if(vx==ex && vy==ey)
            return depth;
        maze2[vx][vy]='@';
        for(int i=0;i<4;i++) {
            if(satisfy(vx+mymove[i].x,vy+mymove[i].y) && (maze2[vx+mymove[i].x][vy+mymove[i].y]!='@') ){
                q1.push(vx+mymove[i].x); q2.push(vy+mymove[i].y);
                if(maze2[vx+mymove[i].x][vy+mymove[i].y]!= 'J')
                    q3.push(depth+1);
                else
                    q3.push(depth+2);
                maze2[vx+mymove[i].x][vy+mymove[i].y]='@';
            }
        }
        q1.pop(); q2.pop(); q3.pop();
    }
    return -1;
}

void solve() {
    int sx,sy,ex,ey;
    bool can=true;
    int ans=0;
    for(int i=0;i<=m;i++) {
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                maze2[j][k]=maze[j][k];
        if(i==0) {
            sx=start.x;
            sy=start.y;
        }
        if(i==m) {
            ex=myend.x;
            ey=myend.y;
        }
        else {
            ex=chal[i+1].x;
            ey=chal[i+1].y;
        }
        
        int tmp=BFS(sx,sy,ex,ey);
        if(tmp<0) {
            cout<<"gg\n";
            can=false;
            break;
        }
        else
            ans+=tmp;
        sx=ex; sy=ey;
    }
    if(can)
        cout<<ans<<endl;
}


int main(){
    mymove[0].x=1; mymove[0].y=0;
    mymove[1].x=-1; mymove[1].y=0;
    mymove[2].x=0; mymove[2].y=1;
    mymove[3].x=0; mymove[3].y=-1;
    input();
    solve();
}
