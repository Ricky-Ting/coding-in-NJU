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