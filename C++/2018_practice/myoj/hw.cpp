#include<iostream>
#include<queue>
#include<string>
using namespace std;
int n,m;
int mg[101][101];
struct node
{
    int x;
    int y;
};
node start,myend;
node mymove[4];
queue<int> q1;
queue<int> q2;
queue<int> q3;
void input();
void solve();  
bool satisfy(int vx, int vy) {
    if(vx<0 || vx>=n)
        return false;
    if(vy<0 || vy>=m)
        return false;
    return true;
}
int main() {
    input();
    solve();
}
void input() {
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        string s;
        cin>>s;
        for(int j=0;j<m;j++) {
            if(s[j]=='#')
                mg[i][j]=0;
            if(s[j]=='.')
                mg[i][j]=1;
            if(s[j]=='S') {
                mg[i][j]=2;
                start.x=i;
                start.y=j;
            }
            if(s[j]=='G') {
                mg[i][j]=3;
                myend.x=i;
                myend.y=j;
            }
        }
    }
}
void solve() {
    mymove[0].x=1; mymove[0].y=0;
    mymove[1].x=-1; mymove[1].y=0;
    mymove[2].x=0; mymove[2].y=1;
    mymove[3].x=0; mymove[3].y=-1;
    q1.push(start.x); q2.push(start.y); q3.push(0);
    int ans=0;
    while(!q1.empty()) {
        int vx=q1.front(); int vy=q2.front(); int depth=q3.front(); 
        if(vx==myend.x && vy==myend.y) {
            ans=depth;
            break;
        }
        mg[vx][vy]=0;
        for(int i=0;i<4;i++) {
            if(satisfy(vx+mymove[i].x,vy+mymove[i].y) && mg[vx+mymove[i].x][vy+mymove[i].y]!=0) {
                q1.push(vx+mymove[i].x); q2.push(vy+mymove[i].y); q3.push(depth+1);
                mg[vx+mymove[i].x][vy+mymove[i].y]=0;
            }
        }
        q1.pop(); q2.pop(); q3.pop();
    }
    cout<<ans<<endl;
}
