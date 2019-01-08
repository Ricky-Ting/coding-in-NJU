#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 60
int N;
int res[MAXN];
int matrix[MAXN][MAXN+1];
int T;

void init() {
	memset(res,0,sizeof(res));
	memset(matrix,0,sizeof(matrix));
	for(int i=1;i<=N;i++) {
		matrix[i][i]=1;
	}
}


void input() {
	scanf("%d",&N);
	//printf("n=%d\n",N);
	init();
	int bs[MAXN];
	for(int i=1;i<=N;i++) {
		scanf("%d",&bs[i]);
	//	if(T==0 && N==4)
	//		printf("%d ",bs[i]);

	}
	//printf("\n");
	int tmp;
	for(int i=1;i<=N;i++) {
		scanf("%d",&tmp);
		//if(T==0 && N==4)
		//	printf("%d ",tmp);
		if(tmp!=bs[i])
			res[i]=1;
	}
	//printf("\n");
	int a,b;
	scanf("%d",&a);
	scanf("%d",&b);
	while(a!=0) {
		//if(T==0 && N==4)
		//	printf("%d %d\n",a,b);
		matrix[b][a]=1;
		scanf("%d",&a);
		scanf("%d",&b);
	}
	for(int i=1;i<=N;i++) {
		matrix[i][N+1]=res[i];
	}
	/*
	if(T==0 && N==4) {
		printf("Before:\n");
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=N+1;j++)
				printf("%d ",matrix[i][j]);
			printf("\n");
		}

	}
	*/
}

void swapline(int a, int b) {
	int tmp;
	for(int i=1;i<=N+1;i++)  {
		tmp=matrix[a][i];
		matrix[a][i]=matrix[b][i];
		matrix[b][i]=tmp;
	}
	return;
}

int Gauss(int n, int m) {
	int line=1; int row=1;
	while(1) {
		if(row>m || line>n)
			break;

		int maxl=line;
		if(matrix[line][row]==0) {
			for(int i=line+1;i<=n;i++) {
				if(matrix[i][row]!=0) {
					maxl=i;
					break;
				}
			}
		}

		if(matrix[maxl][row]==0) {
			row++;
			continue;
		}

		if(maxl!=line) {
			swapline(maxl,line);
		}


		for(int i=line+1;i<=n;i++) {
			if(matrix[i][row]!=0) {
				for(int j=row;j<=m;j++) 
					matrix[i][j]=matrix[line][j]^matrix[i][j];
			}

		}
		row++; line++;
	}
	return 0;
}





int solve() {
	Gauss(N,N+1);
/*
	if(T==0 && N==4) {
		printf("after\n");
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=N+1;j++)
				printf("%d ",matrix[i][j]);
			printf("\n");
		}
	}
	*/
	for(int i = 1; i <= N; i++) 
    {
        int k;
        for(k = 1; k <= N+1; k++) 
        {
            if(matrix[i][k] != 0) 
            {
                if(k == N+1) 
                    return 0;
                break;
            }
        }
        if(k == N+1+1) 
            return 1<<(N - i + 1);
    }
    return 1;
}


int main(void) {
	
	scanf("%d",&T);
	int ret;
	while(T--) {
		input();
		ret=solve();
		if(ret)
			printf("%d\n",ret);
		else
			printf("Oh,it's impossible~!!\n");
	}
}