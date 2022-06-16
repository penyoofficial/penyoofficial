# Java Web Learning Note

在学完Java基础知识之后，我们开始联想：如何应用我们的Java技术呢？

答案是在**Web开发**中应用。为此我们需要学习：
- 数据库
    - [MySQL](#数据库mysql)
    - JDBC
    - Maven
    - MyBatis
- 前端
    - HTML + CSS + JavaScript
    - Ajax + Vue + Element
- Java Web核心技术
    - Tomcat + HTTP + Servlet
    - Request + Response
    - JSP
    - Cookie + Session
    - Filter + Listener

**路漫漫其修远兮，吾将上下而求索！**

## 数据库：MySQL

SQL（Structured Query Language），结构化查询语言，于所有的**关系型**数据库管理系统（DBMS）所通用。

市面上有几百款DBMS，为什么我们单单选择MySQL学习呢？因为相较于Oracle和MS SQL Server，它是唯一一个主流且开源的DBMS，也是如今许多互联网公司的首选。哪怕将来我们的工作环境用的DBMS不是MySQL，我们也可以用通用的SQL操作它们。**所以我们学习MySQL其实就是学习SQL。**

从[这里](https://dev.mysql.com/downloads/mysql/)获取最新版本或者从[这里](https://downloads.mysql.com/archives/community/)获取老版本。

### MySQL配置

我们将从官网上获取到一个压缩包，解压到合适的路径后，**需要增加环境变量**为其下的*bin*文件夹。

向其根目录添加内容如下的*my.ini*：
```text
[mysql]
default-character-set=utf8

[mysqld]
character-set-server=utf8
default-storage-engine=INNODB
sql_mode=STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION
```
在**管理员级**命令行中输入以下命令来初始化：
```text
mysqld --initialize-insecure
```
安装服务：
```text
mysqld -install
```
启动服务：
```text
net start mysql
```
完成上列操作后，你的计算机就是一台MySQL服务器了。

管理员注册（假设你要设置用户名为root，密码为1234）：
```text
mysqladmin -u root password 1234
```
用户登录（方括号内是选配）：
```text
mysql -u root -p 1234 [-h 127.0.0.1 -P 3306]
```
完成上列操作后，你就已经连接到MySQL服务了。

如果你需要退出，你可以：
```text
exit
```
或
```text
quit
```
如果你需要结束服务，你可以：
```text
net stop mysql
```
如果你要移除服务，你可以：
```text
mysqld -remove mysql
```

### 关系型数据库
