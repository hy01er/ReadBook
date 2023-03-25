# Git笔记
Git可以用于文件版本管理,下图表示了Git管理文件的三种状态:
![Git工作流](../Source/pic/skill_learning/git工作三种状态.png)
## 修改与提交方法
1. 修改拉取,提交,推送--日常工作三板斧
   (1) 拉代码,一般用`git clone + github 链接`
   (2) 本地修改后,用`git add + 修改文件`
   (3) 提交修改:`git commit .` `git commit -m "XXX"` `git commit --amend`(amend用于追加)
   (4) 推送到远端:`git push origin 本地分支名:远端分支名`(本地和远端均为master可以省略分支名)

2. `cherry-pick`加某修改到你的修改上(commit id只需要前6位即可)
   **它的作用相当于在你的提交后面加上你要cherry-pick的提交**
   (1)`git cherry-pick + 提交id/分支名`,意思是将某个修改/某个分支合并到当前分支

   (2)有可能出现冲突,出现冲突后,可以使用解冲突,然后add文件后,输入`git cherry-pick --continue`直到合并完成;如果你发现冲突后,不想cherry-pick了,想恢复原来的样子,用`git cherry-pick --abort`就好了

   (3)注意此时你的提交`id`变成了你cherry-pick的提交了,如果直接提交可能就会提交到别人的修改上去

   (4)如果需要提交到你的修改,需要改commit id或者重新提交,否则可能提交到别人的修改上去了,实际工作过程中,如果你的提交依赖对方的提交,你是需要等他提交之后才能提交的,这样就不会和别人的修改提交到一起了

3. `rebase`解决冲突--个人最常用的解冲突方法,比如对方修改先merge了导致你的冲突了
   (1)`git pull --rebase`,这个就是说拉取远端最新代码,和当前的代码合并成一个节点,可以看出这是一个pull拉取操作,出现冲突后,需要解冲突add文件

    (2)然后`git rebase --continue`直到合并完成

    (3)此时change id让仍旧是你的id,直接提交远端,就会提交你的修改

4. 代码回退
   如果不小心改错了代码add了,或者commit了,甚至已经push了,怎么办呢,就需要代码回退掉

   ~~(0) 想要去掉工作空间的某个文件的修改或者全部修改(慎重使用!找不回来的)
    `git checkout -- <filePath>`
    `git checkout .`
    `git checkout <commitID> -- <filePath>`(回退到某版本)
    这个命令会去掉本地工作空间所有修改,并且找不回来,极不推荐,推荐使用git stash存储一下~~

   (1) 误add的修改解决方案
    `git reset HEAD --<filePath>`,回退修改到工作空间

   (2) 误commit修改解决方案
   有三种方案,分别是回退到暂存区,回退到工作空间,~~回退到清空工作空间~~

    a.回退修改到暂存区(不删除工作区改动的代码，撤销commit，不撤销git add)
    `git reset --soft HEAD^`  //回到上一个版本
    `git reset --soft 版本号前6位` // 回退到版本x,可以通过工具或者`git log`获取版本号

    b. 回退到工作空间(不删除工作区改动的代码，撤销commit，撤销git add)
    `git reset --mixed HEAD^`  //回到上一个版本
    `git reset --mixed 版本号前6位` // 回退到版本x,可以通过工具或者`git log`获取版本号

    ~~c.回退到某版本最初的样子,清空工作空间(删除工作区的代码，撤销commit，撤销git add . 回到上一次commit的状态)~~
    ~~`git reset --hard HEAD^`  //回到上一个版本~~
    ~~`git reset --hard 版本号前6位` // 回退到版本x,可以通过工具或者`git log`获取版本号~~
    **注意:git reset --hard 使用后代码就找不回,极不推荐使用!!!!!!!!**

   (3) 误push的修改解决方案
   `git revert -v 版本号`
   `git push origin`
   也就是revert后重新push就行了.

   注意:git revert也会作为一次新提交,版本号会是最新的,之前的都会保留
## 记录知识点
一些Git的必备知识点
### 基础配置
####我们安装好Git后,一般要进行Git的配置然后才能进行提交拉代码的一些操作,这些基础配置有什么呢?
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
 `git config core.ignorecase false`