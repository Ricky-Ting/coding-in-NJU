#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n;
int temp[55];
int mapn[55][55];

int Gauss(int n, int m)
{
    for(int i = 0, k = 0; i < n && k < m; i++, k++) //i代表行k代表消到多少列了
    {
        int maxn = i;
        for(int h = i+1; h < n; h++)  //找出第k列不是0的行
        {
            if(mapn[h][k] > mapn[maxn][k]) 
            {
                maxn = h;
            }
        }
        if(maxn != i) 
        {
            for(int h = k; h < m; h++) //因为第i行第k列是0，所以交换成不是0的行
            {
                swap(mapn[i][h], mapn[maxn][h]);
            }
        }
        if(mapn[i][k] == 0) //第k列全部都是0
        {
            i--;
            continue;
        }
        for(int h = i+1; h < n; h++) //通过第i行消除i~n-1行的第k列元素
        {
            if(mapn[h][k] == 0) //不需要消
                continue;
            for(int l = k; l < m; l++) //消消消。。
            {
                mapn[h][l] = mapn[h][l] ^ mapn[i][l];
            }
        }
    }
    return 0;
}

int solve(int n, int m)
{
    for(int i = 0; i < n; i++) //遍历每一行
    {
        int k;
        for(k = 0; k < m; k++) //遍历第i列
        {
            if(mapn[i][k] != 0) //不是0就退出
            {
                if(k == m-1) //无解
                    return 0;
                break;
            }
        }
        if(k == m) //表示第i行全部是0
            return 1<<(n - i);
    }
    return 1;
}

int main()
{
    int Test;
    cin>>Test;
    while(Test--) 
    {
        cin>>n;
        int x, y;
        memset(temp, 0, sizeof(temp));
        memset(mapn, 0, sizeof(mapn));
        for(int i = 0; i < n; i++) 
        {
            cin>>temp[i]; //输入起始状态
            mapn[i][i] = 1; //变换自己 自己肯定会变换（好别扭。。。）
        }
        for(int i = 0; i < n; i++) 
        {
            cin>>x;
            mapn[i][n] = x ^ temp[i]; //相当于目标状态减去起始状态
        }
        while(true) 
        {
            cin>>x>>y;
            if(x == 0 && y == 0)
                break;
            mapn[y-1][x-1] = 1; //从第0行0列开始
        }
        printf("Before:\n");
        for(int i=0;i<n;i++) {
            for(int j=0;j<n+1;j++)
                printf("%d ", mapn[i][j]);
            printf("\n" );
        }
        Gauss(n, n+1); //高斯消元
        printf("After:\n");
        for(int i=0;i<n;i++) {
            for(int j=0;j<n+1;j++)
                printf("%d ", mapn[i][j]);
            printf("\n");
        }
        int solv = solve(n, n+1); //判断变元

        if(!solv){
            cout<<"Oh,it's impossible~!!"<<endl;
        }
        else{
            cout<<solv<<endl;
        }
    }
    return 0;
}
