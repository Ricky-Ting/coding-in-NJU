#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct nodeset
{
    int nodes[18];
    int num;
    int id;
};
int n;
int t[1<<17][20];
int a[20][20];
int solve(nodeset s,int p);
void Search(nodeset s, int p);
int main()
{
    nodeset ini;
    ini.num=ini.id=0;
    scanf("%d",&n);
    int tmp;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&tmp);
        if(tmp==1)
        {
            ini.num++;
            ini.nodes[ini.num]=i;
            ini.id+=(1<<i);
        }
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            scanf("%d",&a[i][j]);
    memset(t,-1,sizeof(t));
    int ans=solve(ini,0);
    printf("%d\n",ans);
    Search(ini,0);
    return 0;
}


int solve(nodeset s,int p)
{
    if(t[s.id][p]!=-1)
        return t[s.id][p];
    if(s.num==1)
    {
        t[s.id][p]=a[p][s.nodes[1]];
        return t[s.id][p];
    }
    t[s.id][p]=100000000;
    for(int i=1;i<=s.num;i++)
    {
        int pp=s.nodes[i];
        nodeset ss=s;
        for(int j=i+1;j<=ss.num;j++)
            ss.nodes[j-1]=ss.nodes[j];
        ss.num-=1;
        ss.id-=(1<<pp);
        solve(ss,pp);
        if(a[p][pp]+t[ss.id][pp]<=t[s.id][p])
        {
            t[s.id][p]=a[p][pp]+t[ss.id][pp];
        }
    }
    
    return t[s.id][p];
}

void Search(nodeset s, int p)
{
    
    if(s.num==1)
    {
        printf("%d",s.nodes[1]);
        return;
    }
    for(int i=s.num;i>=1;i--)
    {
        int pp=s.nodes[i];
        nodeset ss=s;
        for(int j=i+1;j<=ss.num;j++)
            ss.nodes[j-1]=ss.nodes[j];
        ss.num--;
        ss.id=ss.id-(1<<pp);
        if((a[p][pp]+t[ss.id][pp])<=t[s.id][p])
        {
            printf("%d ",pp);
            Search(ss,pp);
            break;
        }
    }
    return;
}

