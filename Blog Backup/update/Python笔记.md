---
title: Python笔记
date: 2018-02-09 20:42:21
tags:
- Python
- 笔记
---


# Python笔记(未完待续)
## Python特点
- 简单
- 解释型
- 交互式
- 可移植
- 面向对象

## Python特性
- 动态类型
- 自动内存管理
- 大型程序支持
- 内置对象类型

## Python彩蛋
在交互解释器里输入`import this`

 <!-- more -->

## Python解释器
有很多种，最常用的是CPython。 

解释器是输入一行就执行一行

输入`exit()`来退出解释器。

在终端里输入`python3 Filename.py`来执行python文件

在Mac和Linux上可以直接运行`.py`文件，方法是在`.py`文件的第一行加上一个特殊的注释:

```
#!/usr/bin/env python3
```

然后通过命令给`hello.py`以执行权限:

```
$ chmod a+x hello.py
```

以下一行注释是为了告诉Python解释器，按照UTF-8编码读取源代码，否则可能中文会有乱码

```
# -*- coding: utf-8 -*-
```

## Python语法

### 输出
`print()`用`,`隔开多个输出。**遇到逗号会输出一个空格**

#### 格式化输出

##### print()方法

占位符 | 替换内容 
----|-----
%d | 整数  
%f | 浮点数  
%s | 字符串  
%x | 十六进制整数

##### format()方法
另一种格式化字符串的方法是使用字符串的format()方法，它会用传入的参数依次替换字符串内的占位符{0}、{1}……，不过这种方式写起来比%要麻烦得多：



### 输入
`input()`。如:`name = input()`。又如`name = input('please enter your name')`

`input()`返回的是`str`类型，要进行转换，如`int()`

### 注释
以`#`开头

### 数据类型

#### 整数(int)

#### 浮点数(float)

#### 字符串(str)
(`'`和`"`都可以) 可以用`r''`表示`''`里的字符串默认不转义 

`ord()`获取字符的整数表示，`chr()`将编码转换为对应的字符 

`encode()`和`decode()`方法 

`len()`函数计算的是`str`的字符数,如果换成`bytes`,则计算字节数

#### 布尔值(bool) 

(`True`和`False`, `and`、`or`和`not`运算)

#### 空值 

用`None`表示

#### 列表(list)

`classmates = ['Michael', 'Bob', 'Tracy']` 

可以用len()函数获取list的元素个数，

运用索引访问，从0开始，用-1做索引可以直接获取最后一个元素，一次类推，可以获取倒数第2个、倒数第3个···。

list有序可变：`append(element)`方法追加至末尾,`insert(position,element)`方法追插入至指定位置，删除末尾用`pop()`,删除指定位置的用`pop(i)`。

list里的元素可以不同类型，且可嵌套。

list有`sort()`方法

#### 元组(tuple) 

`classmates = ('Michael', 'Bob', 'Tracy')`

tuple与list类似，但是tuple一旦初始化就不能修改,即tuple没有append(),insert()方法。

定义一个只有1个元素的tuple得这样定义:`t=(1,)`。 

tuple里嵌套的list可变

#### 字典(dict) 

(`d = {'Michael': 95, 'Bob': 75, 'Tracy': 85}`)

在其他语言中也称为map，使用键-值(key-value)储存。

一个key只能对应一个value，多次放入会把前面的值冲掉。

用`in`判断key是否存在如`>>> 'Thomas' in d`。`get()`方法，

如果key不存在就返回`None`,或者自己指定的value，如`d.get('Thomas,-1')`

要删除一个key，用pop(key),对应的value也会从dict中删除。

dict的key必须是不可变对象，所以list不能作为key

`dict`的`items()`可以同时迭代key和value:

```
for k,v in d.items():
	print(k,'=',v)
```

list特点：

1. 查找和插入的时间随着元素的增加而增加；
2. 占用空间小，浪费内存很少。

dict特点：

1. 找和插入的速度极快，不会随着key的增加而变慢；
2. 需要占用大量的内存，内存浪费多。

#### set

set和dict类似，也是一组key的集合，但不存储value。由于key不能重复，所以，在set中，没有重复的key,重复元素在set中自动被过滤。

要创建一个set，需要提供一个list作为输入集合：

```
>>> s = set([1, 2, 3])
>>> s
{1, 2, 3}
```
`add(key)`方法来添加key，`remove(key)`方法可以删除元素

`s1 & s2`：集合交， `s1 | s2`集合并

#### 数据类型转换 

`int()` `float()` `str()` `bool()`

*变量本身类型不固定的语言称之为动态语言，与之对应的是静态语言*
*返回`None`的时候Python的交互环境不显示结果*
*常量名常用大写表示，如`PI`*

*Python中有两种除法,`/`的结果是浮点数，'//'的结果是整数*

*取余为`%`*

*UTF-8为可变长编码，把一个Unicode字符根据不同的数字大小编码成1-6个字节*

### 程序结构

#### 分支语句

##### if语句

```
if <条件判断1>:
    <执行1>
elif <条件判断2>:
    <执行2>
elif <条件判断3>:
    <执行3>
else:
    <执行4>
```

判断条件还可以简写

```
if x:
    print('True')
```
只要`x`是非零数值、非空字符串、非空list等，就判断为`True`，否则为`False`。

#### 循环语句
##### for


```
names = ['Michael', 'Bob', 'Tracy']
for name in names:
    print(name)
```

*`range()`函数可以生成一个整数序列，比如`range(5)`生成的序列是从0开始小于5的整数*

```
sum = 0
for x in range(101):
    sum = sum + x
print(sum)

```

##### while

```
sum = 0
n = 99
while n > 0:
    sum = sum + n
    n = n - 2
print(sum)
```

*`break`和`continue`与C++中类似。*

#### 函数

函数名其实就是指向一个函数对象的引用，完全可以把函数名赋给一个变量，相当于给这个函数起了一个“别名”：`a = abs`

##### 定义函数

```
def my_abs(x):
    if x >= 0:
        return x
    else:
        return -x
```

`return None`可以简写为`return`

###### 空函数

可以用`pass`语句，如：

```
def nop():
	pass
```

`pass`也可以放在其他语句里,如：

```
if condition:
	pass
```

###### 参数检查

```
def my_abs(x):
    if not isinstance(x, (int, float)):
        raise TypeError('bad operand type')
    if x >= 0:
        return x
    else:
        return -x
```

函数可以返回多个值(实质上是tuple)，并可按位置赋给相应的变量

###### 默认参数
`def power(x,n=2):`

*必选参数在前，默认参数在后。*
*不按默认顺序提供参数是，需要把参数名写上。*
*定义默认参数要牢记一点：默认参数必须指向不变对象！不然不同次的调用会出现不同的结果。*


###### 可变参数
`def calc(*numbers):`相当于传入一个tuple

若已有list和tuple 可这样调用`calc(*nums)`

###### 关键字参数

`def person(name, age, **kw):`:会组建一个dict

和可变参数类似，也可以先组装出一个dict，然后，把该dict转换为关键字参数传进去：

###### 命名关键字参数

如果要限制关键字参数的名字，就可以用命名关键字参数，例如，只接收city和job作为关键字参数。这种方式定义的函数如下：

```
def person(name, age, *, city, job):
    print(name, age, city, job)
```
和关键字参数`**kw`不同，命名关键字参数需要一个特殊分隔符`*`，`*`后面的参数被视为命名关键字参数。

如果函数定义中已经有了一个可变参数，后面跟着的命名关键字参数就不再需要一个特殊分隔符*了：

命名关键字参数必须传入参数名，这和位置参数不同。如果没有传入参数名，调用将报错：

命名关键字参数可以有缺省值，从而简化调用：

###### 参数组合

在Python中定义函数，可以用必选参数、默认参数、可变参数、关键字参数和命名关键字参数，这5种参数都可以组合使用。但是请注意，参数定义的顺序必须是：必选参数、默认参数、可变参数、命名关键字参数和关键字参数。


##### 函数递归

*尾递归可以进行优化，但大多数编译器和解释器没有进行优化*

#### 切片

可以对list,tuple,str操作，相当于截取，如:`l[1:3]`取索引为1和2的元素组成一个list，还可以设置间隔如：`l[0:100;5]`每五个取一个

#### 迭代

for...in 可以迭代任何可迭代的对象(如dict)

如何判断是否可以迭代：通过collections模块的Iterable类型判断。
`isinstance('abc', Iterable)`

Python内置的`enumerate`函数可以把一个list变成索引-元素对，这样就可以在for循环中同时迭代索引和元素本身

```
for i,value in enumerate(['A','B','C']):
	print(i,value)
```

#### 列表生成式(List Comprehension)

`list(range(1,11))`生成`[1,2,3,4,5,6,7,8,9,10]`

`[x * x for x in range(1,11)]`生成 `[1,4,9,16,25,36,49,64,81,100]`

`[x * x for x in range(1,11) if x % 2 == 0]`生成`[4,16,36,64,100]`

`[m+n for m in 'ABC' for n in 'XYZ']`生成`['AX', 'AY', 'AZ', 'BX', 'BY', 'BZ', 'CX', 'CY', 'CZ']`

#### 生成器(generator)

边循环边计算，把`[]`变为`()`就可以了

可以通过`next()`打印generator的下一个返回值 

还可以用for循环迭代

```
g = (x*x for x in range(10))
for n in g:
	print(n)
```

如果一个函数定义中包含yield关键字，那么这个函数就不再是一个普通函数，而是一个generator。generator和函数的执行流程不一样。函数是顺序执行，遇到return语句或者最后一行函数语句就返回。而变成generator的函数，在每次调用next()的时候执行，遇到yield语句返回，再次执行时从上次返回的yield语句处继续执行。

#### 迭代器

凡是可作用于`for`循环的对象都是`Iterable`类型；

凡是可作用于`next()`函数的对象都是`Iterator`类型，它们表示一个惰性计算的序列；

可以使用`isinstance()`判断一个对象是否是`Iterator`对象：

集合数据类型如`list`、`dict`、`str`等是`Iterable`但不是`Iterator`，不过可以通过`iter()`函数获得一个`Iterator`对象。

Python的`for`循环本质上就是通过不断调用`next()`函数实现的


#### 函数式编程

##### 高阶函数（Higher-order-function）

函数可以赋值给变量，函数名也是变量

一个函数接受另一个函数作为参数，这种函数被称为高阶函数。

###### `map()`和`reduce()`函数

`map()`函数接受两个参数，一个是函数，一个是`Iterable`,`map`将传入的函数依次作用到序列的每个元素，并把结果作为新的`Iterator`返回

`reduce()`把一个函数作用在一个序列`[x1,x2,x3,...]`上。`reduce`把结果继续和序列的下一个元素做累积计算

`reduce(f, [x1, x2, x3, x4]) = f(f(f(x1, x2), x3), x4)`

###### filter

Python内建的`filter()`函数用于过滤序列。

`filter()`把传入的函数依次作用于每个元素，然后根据返回值是`True`还是`False`决定保留还是丢弃该元素。

`filter()`函数返回的是一个`Iterator`，也就是一个惰性序列，所以要强迫`filter()`完成计算结果，需要用`list()`函数获得所有结果并返回list。

###### sorted

`sorted()`函数也是一个高阶函数，它还可以接收一个`key`函数来实现自定义的排序,如：

`sorted([36, 5, -12, 9, -21], key=abs)`

默认情况下，对字符串排序，是按照ASCII的大小比较的，

要进行反向排序，不必改动key函数，可以传入第三个参数`reverse=True`

##### 返回函数

函数作为返回值

闭包：返回闭包时牢记一点：返回函数不要引用任何循环变量，或者后续会发生变化的变量。如果一定要引用循环变量怎么办？方法是再创建一个函数，用该函数的参数绑定循环变量当前的值，无论该循环变量后续如何更改，已绑定到函数参数的值不变：

返回一个函数时，牢记该函数并未执行，返回函数中不要引用任何可能会变化的变量。

##### 匿名函数

当我们在传入函数时，有些时候，不需要显式地定义函数，直接传入匿名函数更方便。`list(map(lambda x: x * x, [1, 2, 3, 4, 5, 6, 7, 8, 9]))`

`lambda x: x * x`实际上就是:

```
def f(x):
	return x * x
```
关键字`lambda`表示匿名函数，冒号前面的x表示函数参数。

匿名函数有个限制，就是只能有一个表达式，不用写`return`，返回值就是该表达式的结果。

##### 装饰器(Decorator)(在代码运行期间动态增加功能的方式)

本质上，decorator就是一个返回函数的高阶函数。

**函数也是个对象**，可以通过`__name__`属性拿到函数的名字

```
def log(func):
    def wrapper(*args, **kw):
        print('call %s():' % func.__name__)
        return func(*args, **kw)
    return wrapper
```

```
@log
def now():
    print('2018-2-9')
```

三层嵌套的decorator

```
def log(text):
    def decorator(func):
        def wrapper(*args, **kw):
            print('%s %s():' % (text, func.__name__))
            return func(*args, **kw)
        return wrapper
    return decorator
```

```
@log('execute')
def now():
    print('2018-2-9')
```

但此时函数名会出现错误，所以完整写法如下：

```
import functools

def log(func):
    @functools.wraps(func)
    def wrapper(*args, **kw):
        print('call %s():' % func.__name__)
        return func(*args, **kw)
    return wrapper
```

##### 偏函数(Partial function)

与数学意义上的偏函数不一样

所以，简单总结`functools.partial`的作用就是，把一个函数的某些参数给固定住（也就是设置默认值），返回一个新的函数，调用这个新函数会更简单。

`functools.partial`就是帮助我们创建一个偏函数的

```
import functools 
int2 = functools.partial(int, base=2)
```

创建偏函数时，实际上可以接收函数对象、`*args`和`**kw`这3个参数

#### 模块(Module)

在Python中，一个.py文件就称之为一个模块（Module）

为了避免模块名冲突，Python又引入了按目录来组织模块的方法，称为包（Package）。

方法是选择一个顶层包名，比如`mycompany`。引入了包以后，只要顶层的包名不与别人冲突，那所有模块都不会与别人冲突。现在，`abc.py`模块的名字就变成了`mycompany.abc`，类似的，`xyz.py`的模块名变成了`mycompany.xyz`。

请注意，每一个包目录下面都会有一个`__init__.py`的文件，这个文件是必须存在的，否则，Python就把这个目录当成普通目录，而不是一个包。`__init__.py`可以是空文件，也可以有Python代码，因为`__init__.py`本身就是一个模块，而它的模块名就是`mycompany`。

类似的，可以有多级目录，组成多级层次的包结构。

##### 作用域

正常的函数和变量名是公开的（public），可以被直接引用

类似`__xxx__`这样的变量是特殊变量，可以被直接引用，但是有特殊用途

类似`_xxx`和`__xxx`这样的函数或变量就是非公开的（private），不应该被直接引用

之所以我们说，private函数和变量“不应该”被直接引用，而不是“不能”被直接引用，是因为Python并没有一种方法可以完全限制访问private函数或变量，但是，从编程习惯上不应该引用private函数或变量。

##### 安装第三方模块 

在Python中，安装第三方模块，是通过包管理工具pip完成的。

#### 面向对象编程

数据封装、继承和多态是面向对象的三大特点

##### 类和实例(Class and Instance)

在Python中，定义类是通过`class`关键字：class后面紧接着是类名，即Student，类名通常是大写开头的单词，紧接着是`(object)`，表示该类是从哪个类继承下来的,如果没有合适的继承类，就使用object类，这是所有类最终都会继承的类。

定义好了`Student`类，就可以根据`Student`类创建出Student的实例，创建实例是通过类名+()实现的。如:`bart = Student()`

由于类可以起到模板的作用，因此，可以在创建实例的时候，把一些我们认为必须绑定的属性强制填写进去。通过定义一个特殊的`__init__`方法，在创建实例的时候，就把`name`，`score`等属性绑上去：

```
class Student(object):

    def __init__(self, name, score):
        self.name = name
        self.score = score
```
和普通的函数相比，在类中定义的函数只有一点不同，就是第一个参数永远是实例变量self，并且，调用时，不用传递该参数。除此之外，类的方法和普通函数没有什么区别，所以，你仍然可以用默认参数、可变参数、关键字参数和命名关键字参数。

###### 数据封装

和静态语言不同，Python允许对实例变量绑定任何数据，也就是说，对于两个实例变量，虽然它们都是同一个类的不同实例，但拥有的变量名称都可能不同：

##### 访问限制

如果要让内部属性不被外部访问，可以把属性的名称前加上两个下划线`__`，在Python中，实例的变量名如果以`__`开头，就变成了一个私有变量（private），只有内部可以访问，外部不能访问

需要注意的是，在Python中，变量名类似`__xxx__`的，也就是以双下划线开头，并且以双下划线结尾的，是特殊变量，特殊变量是可以直接访问的，不是private变量，所以，不能用`__name__`、`__score__`这样的变量名。

双下划线开头的实例变量是不是一定不能从外部访问呢？其实也不是。不能直接访问`__name`是因为Python解释器对外把`__name`变量改成了`_Student__name`，所以，仍然可以通过`_Student__name`来访问`__name`变量：

##### 继承和多态

在OOP程序设计中，当我们定义一个class的时候，可以从某个现有的class继承，新的class称为子类（Subclass），而被继承的class称为基类、父类或超类（Base class、Super class）。

继承有什么好处？最大的好处是子类获得了父类的全部功能。由于`Animial`实现了`run()`方法，因此，`Dog`和`Cat`作为它的子类，什么事也没干，就自动拥有了`run()`方法：

当子类和父类都存在相同的`run()`方法时，我们说，子类的`run()`覆盖了父类的`run()`，在代码运行的时候，总是会调用子类的`run()`。这样，我们就获得了继承的另一个好处：多态。

所以，在继承关系中，如果一个实例的数据类型是某个子类，那它的数据类型也可以被看做是父类。但是，反过来就不行

###### 静态语言 vs 动态语言

对于静态语言（例如Java）来说，如果需要传入`Animal`类型，则传入的对象必须是`Animal`类型或者它的子类，否则，将无法调用`run()`方法。

对于Python这样的动态语言来说，则不一定需要传入`Animal`类型。我们只需要保证传入的对象有一个`run()`方法就可以了

这就是动态语言的“鸭子类型”，它并不要求严格的继承体系，一个对象只要“看起来像鸭子，走起路来像鸭子”，那它就可以被看做是鸭子。

Python的“file-like object“就是一种鸭子类型。对真正的文件对象，它有一个`read()`方法，返回其内容。但是，许多对象，只要有`read()`方法，都被视为“file-like object“。许多函数接收的参数就是“file-like object“，你不一定要传入真正的文件对象，完全可以传入任何实现了`read()`方法的对象。

##### 获取对象信息

###### 使用type()

判断对象类型

###### 使用isinstance()

###### 使用dir()

如果要获得一个对象的所有属性和方法，可以使用`dir()`函数，它返回一个包含字符串的list


##### 实例属性和类属性




疑惑：
python的动态类型是否是用指针实现的




参考:

1. [Python教程](https://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000/00143186738532805c392f2cc09446caf3236c34e3f980f000)
2. 《Python学习手册》 by Mark Lutz(O'REILLY Press,2011)