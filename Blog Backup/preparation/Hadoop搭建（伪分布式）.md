# Hadoop搭建（伪分布式）

## 前期准备
- 虚拟机：VirtualBox
- 系统：Ubuntu
- Hadoop：hadoop-2.6.0.tar.gz

## 系统安装

默认安装就好，然后在Global Tools中的host network manager中create。然后在虚拟机adapter2选择host-only，并选择刚刚创建的。

## 网络配置
前期可能需要创建root

安装vim: `sudo apt-get install -y vim`(如果安装失败可能需要`sudo apt update`和`sudo apt upgrade`)

`ifconfig`按提示

然后`sudo vim /etc/network/interfaces`
加入以下内容
```
```

