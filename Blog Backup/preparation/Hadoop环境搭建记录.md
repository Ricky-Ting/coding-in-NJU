# Hadoop环境搭建记录

## 安装系统

安装系统的时候出了很多问题，找不到引导，硬盘被锁啊，感觉不懂的还是很多，最后还是请学长帮忙装好了系统。

## Hadoop环境的搭建

[参考教程](https://blog.csdn.net/fanxin_i/article/details/80425461)

我的理解是主要在master里执行namenode初始化就好了，初始化之前最好把master和slave里hdfs目录下删干净(以后可以写个脚本干这个事)。

## 写脚本

写脚本实现只运行MapReduce和在HDFS上运行MapReduce。

我的理解是只要改改配置文件就好，要运行哪一种方式只要把相应的配置文件拷进去就好。 因为不运行yarn，所以要把yarn的相关配置删除。

```
#!/usr/bin/env bash

echo "This is to run mapreduce on hdfs"
rm -rf ~/hadoop-2.2.0/etc/hadoop
echo "Original config files in hadoop-2.2.0/ect/hadoop deleted"
cp -r ~/hadoopconfig/hadoop-distributed ~/hadoop-2.2.0/etc/
echo "Copy config files of hdfs to hadoop-2.2.0/etc/hadoop"
mv ~/hadoop-2.2.0/etc/hadoop-distributed ~/hadoop-2.2.0/etc/hadoop
echo "Rename successfully"
cd ~/hadoop-2.2.0
echo "About to run start-dfs.sh"
start-dfs.sh
echo "About to run an example on hdfs"
hadoop jar /home/hadoop/hadoop-2.2.0/share/hadoop/mapreduce/hadoop-mapreduce-examples-2.2.0.jar pi 10 10
jps
echo "About to run stop-dfs.sh"
stop-dfs.sh
```

```
#!/usr/bin/env bash

echo "This is to run mapreduce without hdfs"
rm -rf ~/hadoop-2.2.0/etc/hadoop
cp -r ~/hadoopconfig/hadoop-native ~/hadoop-2.2.0/etc/
mv ~/hadoop-2.2.0/etc/hadoop-native ~/hadoop-2.2.0/etc/hadoop
cd ~/hadoop-2.2.0
./bin/hadoop jar ./share/hadoop/mapreduce/hadoop-mapreduce-examples-2.2.0.jar pi 10 10
~
~
~
```