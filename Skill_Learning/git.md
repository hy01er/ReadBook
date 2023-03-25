# Git笔记

## 修改与提交方法

## 记录知识点
一些Git的必备知识点
### 基础配置
+ 我们安装好Git后,一般要进行Git的配置然后才能进行提交拉代码的一些操作,这些基础配置有什么呢?
1. 设置用户名和邮箱(修改引号内的内容)
   (1) `git config --global user.name "username"`
   (2) `git config --global user.email "username@email.com"`
   (3) 可以用以下命令看是否写成功了:`git config --global --list`
2. 产生Public SSH KEY
    (1) `ssh-keygen -t rsa`,三次回车即可
    (2) 然后去用户的根目录找.ssh文件夹,`id_rsa.pub`就是公钥,放到github或者gitee里面的.
    (3) 用`ssh -T git@github.com`测试下是否成功

## 遇到的问题解决
Git中遇到的一些问题,进行记录并写出解决方案

### Git默认不识别大小写
比如,我修改了文件名`skill`,修改为`Skill`,git不识别
解决方案:
 git config core.ignorecase false