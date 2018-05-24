# C++笔记

## stack库

### 构造：`stack<int> s;`

`s.pop() //需自行判断栈是否为空 s.empty()`

`s.push()`

`s.top()`

`s.size()`


## string类

`s.erase(position,number)`

## vector容器

```
vector<int> s;

s.push_back()
s.pop_back();
s.size()



```

## 提高C++输入输出效率

`std::ios::sync_with_stdio(false);` 解除对C的输入输出的兼容

## 保留小数位数

```
#include<iomanip>

cout<<setiosflags(ios::fixed)<<setprecision(3)
```



## map
```
#include<map>
map<int,int> mymap;
```

## set
```
#include<set>
set<int> myset;
myset.insert(value);
myset.size();
```


## memset()

`extern void *memset(void *buffer, int c, int count) `

`char a[100];memset(a, '/0', sizeof(a));`


## 位操作

```
&  //与
|  //或
^  //异或
~  //取反
被移位数<<位数  //左移
>>  //右移

```

### 位操作技巧

#### 1.判断奇偶
`if(a & 1 == 0)`

#### 2.交换两数
```
if(a!=b)
{
	a^=b;
	b^=a;
	a^=b;
}
```

### Priority Queue

```
#include<queue>
using namespace std;

priority_queue <int> pq;
pq.push(1);
a=pq.top();
num=pq.size();
!qp.empty();
pq.pop();
```

如果是结构体,可以再结构体中重载"<"操作符

```
struct info
{
	float score;
	bool operator <(const info &a) const
	{
		return a.socre<score;
	}
};
```

传入结构体可自定义优先级

```
struct cmp
{
	bool operator ()(int a, int b)
	{
		return a>b;
	}
};

priority_queue<int,vector<int>,cmp> q

```

### hash_map

```
#include<hash_map>
hash_map<int,string> mymap;
mymap[key]="data";
```

