#include<cstdio>
#include<stack>
#include<vector>
using namespace std;
struct node
{
    int w1;
    int w2;
};
struct vertex{
    int prev;
    int val;
};

struct edge{
    int to;
    int w;
    edge(int myto,int myw):to(myto),w(myw){} //构造函数
};
int w[100];
vector<edge> E[51];
stack<int> s;
int n,m;
node start;
bool isvis[51];
int endv;
vertex dp[51];
int ans;

int maxi(int a, int b) {
    return (a>b)?a:b;
}



void input() {
    scanf("%d%d",&n,&m);
    scanf("%d%d",&start.w1,&start.w2);
   
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    int from,to,weight;
    for(int i=0;i<m;i++) {
        scanf("%d%d%d",&from,&to,&weight);
        E[from].push_back(edge(to,weight));
    }
    scanf("%d",&endv);
    dp[0].val=0;
    dp[0].prev=-1;
    for(int i=1;i<=n;i++) {
        dp[i].prev=-1;
        isvis[i]=false;
    }
    ans=1e18;
 	if(start.w1<start.w2) {
        int tmp=start.w1;
        start.w1=start.w2;
        start.w2=tmp;
    }
}

void dfs(int sv, int ev, node people, int sum) {
    if(sv==ev) {
        if(sum<ans) {
            while(!s.empty())
                s.pop();
            int tmp=ev;
            while(tmp!=-1) {
                s.push(tmp);
                tmp=dp[tmp].prev;
            }
            ans=sum;
        }
        return;
    }
    for(int i=0; i<E[sv].size();i++) {
        if(isvis[E[sv][i].to])
            continue;
        int v=E[sv][i].to;
        isvis[v]=true;
        dp[v].prev=sv;
        int oldw=w[v];

        int tmpsum=sum+(E[sv][i].w)*(people.w1+people.w2);

        node tmp=people;
        w[v]=tmp.w1;
        tmp.w1=tmp.w2;
        tmp.w2=oldw;

        dfs(v,ev,tmp,tmpsum);

        dp[v].prev=-1;
        isvis[v]=false;
        w[v]=oldw;
    }
}





void solve(void){
    //for(int i=0;i<n;i++)
        dfs(0,endv,start,0);

}

void output(void){
    while(!s.empty()) {
        printf("%d ",s.top());
        s.pop();
    }
}

int main(void) {
    input();
    solve();
    output();
}
