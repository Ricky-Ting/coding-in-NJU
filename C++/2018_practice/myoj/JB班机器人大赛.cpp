#include<cstdio>
using namespace std;
struct node {
    int x;
    int y;
};
node startpoint,endpoint;
int n,m;
bool reachable;
int ans;

int status[200][200];
node mymove[4];

void dfs(int x, int y, int step);

int main() {
    mymove[0].x=1; mymove[0].y=0;
    mymove[1].x=-1; mymove[1].y=0;
    mymove[2].x=0; mymove[2].y=1;
    mymove[3].x=0; mymove[3].y=-1;
    while(1) {
        scanf("%d%d",&m,&n);
        if(n==0 && m==0)
            break;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) {
                scanf("%d",&status[i][j]);
                if(status[i][j]==2) {
                    startpoint.x=i;
                    startpoint.y=j;
                }
                if(status[i][j]==3) {
                    endpoint.x=i;
                    endpoint.y=j;
                }
            }
        reachable=false;
        ans=16;
        dfs(startpoint.x,startpoint.y,0);
        if(reachable)
            printf("%d\n",ans);
        else
            printf("-1\n");
    }
    
}


bool satisfy(int vx, int vy) {
    if(vx<0 || vx>=n)
        return false;
    if(vy<0 || vy>=m)
        return false;
    return true;
}


void dfs(int x, int y, int step) {
    int tx,ty;
    if(step>=10) {
        return;
    }
    bool moved;
    for(int i=0;i<4;i++) {
        tx=x; ty=y;
        moved=false;
        while(satisfy(tx+mymove[i].x,ty+mymove[i].y) && (status[tx+mymove[i].x][ty+mymove[i].y])!=1 ){
        	moved=true;
            tx+=mymove[i].x;
            ty+=mymove[i].y;
            if(tx==endpoint.x && ty==endpoint.y) {
                reachable=true;
                ans=(ans>(step+1))?step+1:ans;
                return;
            }
        }
        
        if(satisfy(tx+mymove[i].x,ty+mymove[i].y) && (status[tx+mymove[i].x][ty+mymove[i].y])==1 && moved)  {
            status[tx+mymove[i].x][ty+mymove[i].y]=0;
            dfs(tx,ty,step+1);
            status[tx+mymove[i].x][ty+mymove[i].y]=1;
        }
        
        
        
    }
    
    
}
