#include<iostream>
using namespace std;
struct node
{
    int maxiwei;
    int value[1000];
};

node dp[206],ans[2];



void addition3(node add[],node result[],int add1,int result1);
void multiplication(node multi[],node result[], int multi1, int multi2,int res);

int main(void)
{
    int n;
    cin>>n;
    while(n!=-1)
    {
        for(int i=0;i<=2*n;i++)
        {
            dp[i].maxiwei=0;
            for(int j=0;j<=999;j++)
                dp[i].value[j]=0;
        }
        ans[0].maxiwei=0;
        for(int i=0;i<=999;i++)
            ans[0].value[i]=0;
        
        
        dp[0].maxiwei=0;
        dp[0].value[0]=1;
        dp[2].maxiwei=0;
        dp[2].value[0]=1;
        dp[4].maxiwei=0;
        dp[4].value[0]=2;
        for(int i=6;i<=2*n-2;i=i+2)
        {
            for(int j=0;j<=i-2;j+=2)
            {
                node result[1];
                result[0].maxiwei=0;
                for(int k=0;k<=999;k++)
                {
                    result[0].value[k]=0;
                }
                
                multiplication(dp,result,j,i-2-j,0);
                addition3(result,dp,0,i);
                
            }
            
            
        }
        
        for(int i=2;i<=2*n;i++)
        {
            node result[1];
            result[0].maxiwei=0;
            for(int k=0;k<=999;k++)
            {
                result[0].value[k]=0;
            }
            multiplication(dp,result,i-2,2*n-i,0);
            
            addition3(result,ans,0,0);
            
            
            
        }
        
        
        for(int i=ans[0].maxiwei;i>=0;i--)
            cout<<ans[0].value[i];
        cout<<endl;
        cin>>n;
    }
    
}



void addition3(node add[],node result[],int add1,int result1)
{
    
    int jinwei=0;
    int maxiwei=max(add[add1].maxiwei,result[result1].maxiwei);
    for(int i=0;i<=maxiwei;i++)
    {
        result[result1].value[i]=result[result1].value[i]+(add[add1].value[i]+jinwei);
        jinwei=0;
        if(result[result1].value[i]>=10)
        {
            jinwei=1;
            result[result1].value[i]%=10;
        }
    }
    
    if(jinwei!=0)
    {
        
        maxiwei++;
        result[result1].value[maxiwei]=1;
    }
    result[result1].maxiwei=maxiwei;
    return;
}




void multiplication(node multi[],node result[], int multi1, int multi2,int res)
{
    int maxwei=multi[multi1].maxiwei+multi[multi2].maxiwei+5;
    for(int i=0;i<=multi[multi1].maxiwei;i++)
        for(int j=0;j<=multi[multi2].maxiwei;j++)
        {
            result[res].value[i+j]=result[res].value[i+j]+multi[multi1].value[i]*multi[multi2].value[j];
        }
    int jinwei=0;
    for(int i=0;i<=maxwei;i++)
    {
        result[res].value[i]+=jinwei;
        jinwei=0;
        if(result[res].value[i]>=10)
        {
            jinwei=result[res].value[i]/10;
            result[res].value[i]=result[res].value[i]%10;
        }
    }
    
    for(int i=maxwei;i>=0;i--)
    {
        if(result[res].value[i]!=0)
        {
            result[res].maxiwei=i;
            break;
        }
    }
}

