#include<iostream>
#include<cstdio>
using namespace std;  //运用堆 左边最大堆 右边最小堆

struct Heap
{
    int key[10000];
    int num;
};

Heap H1,H2;
int P;
int current_set,num;
int tmp,middle;




int parent(int value)
{
    return value/2;
}

int left(int value)
{
    return value*2;
}

int right(int value)
{
    return value*2+1;
}

void insert_max(int value)
{
    int tmp2;
    H1.num++;
    H1.key[H1.num]=value;
    int i=H1.num;
    while(i>1 && H1.key[parent(i)]<H1.key[i])
    {
        tmp2=H1.key[parent(i)];
        H1.key[parent(i)]=H1.key[i];
        H1.key[i]=tmp2;
        i=parent(i);
    }
}

void insert_min(int value)
{
    int tmp2;
    H2.num++;
    H2.key[H2.num]=value;
    int i=H2.num;
    while(i>1 && H2.key[parent(i)]>H2.key[i])
    {
        tmp2=H2.key[parent(i)];
        H2.key[parent(i)]=H2.key[i];
        H2.key[i]=tmp2;
        i=parent(i);
    }
}
void max_heapify(int pos)
{
    int largest,l,r,tmp2;
    l=left(pos);
    r=right(pos);
    if(l<=H1.num && H1.key[l]>H1.key[pos])
        largest=l;
    else
        largest=pos;
    if(r<=H1.num && H1.key[r]>H1.key[largest])
        largest=r;
    if(largest!=pos)
    {
        tmp2=H1.key[pos];
        H1.key[pos]=H1.key[largest];
        H1.key[largest]=tmp2;
        max_heapify(largest);
    }
    
}

void min_heapify(int pos)
{
    int smallest,l,r,tmp2;
    l=left(pos);
    r=right(pos);
    if(l<=H2.num && H2.key[l]<H2.key[pos])
        smallest=l;
    else
        smallest=pos;
    if(r<=H2.num && H2.key[r]<H2.key[smallest])
        smallest=r;
    if(smallest!=pos)
    {
        tmp2=H2.key[pos];
        H2.key[pos]=H2.key[smallest];
        H2.key[smallest]=tmp2;
        min_heapify(smallest);
    }
}

int delete_max()
{
    int tmp2=H1.key[1];
    H1.key[1]=H1.key[H1.num];
    H1.num--;
    max_heapify(1);
    return tmp2;
}

int delete_min()
{
    int tmp2=H2.key[1];
    H2.key[1]=H2.key[H2.num];
    H2.num--;
    min_heapify(1);
    return tmp2;
}



void balance()
{
    while(H1.num-H2.num>1)
    {
        insert_min(middle);
        middle=delete_max();
    }
    while(H2.num-H1.num>1)
    {
        insert_max(middle);
        middle=delete_min();
    }
}

void solve(void)
{
    scanf("%d",&tmp);
    middle=tmp;
    printf("%d ",tmp);
    for(int i=2;i<=num;i++)
    {
        scanf("%d",&tmp);
        if(tmp<middle)
            insert_max(tmp);
        else
            insert_min(tmp);
        balance();
        if(i&1)
        {
            printf("%d ",middle);
            if((i+1)/2 % 10 == 0)
            	printf("\n");
        }

    }
    printf("\n");
}

int main(void)
{
    scanf("%d",&P);
    for(int i=1;i<=P;i++)
    {
        scanf("%d%d",&current_set,&num);
        printf("%d %d\n",current_set,num/2+1);
        H1.num=H2.num=0;
        solve();
    }
}

