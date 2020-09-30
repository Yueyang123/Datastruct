
# 安装完Git后第一件要做的事，设置用户信息(global可换成local在单独项目生效)：
git config --global user.name "用户名" # 设置用户名
git config --global user.email "用户邮箱"   #设置邮箱
git config --global user.name   # 查看用户名是否配置成功
git config --global user.email   # 查看邮箱是否配置

# 其他查看配置相关
git config --global --list  # 查看全局设置相关参数列表
git config --local --list # 查看本地设置相关参数列表
git config --system --list # 查看系统配置参数列表
git config --list  # 查看所有Git的配置(全局+本地+系统)



2.获取帮助【git help】

git help 命令   # 如：git help init


3.创建本地仓库【git init】

git init 仓库名 # 创建一个新的带Git仓库的项目
git init # 为已存在的项目生成一个Git仓库


4.添加文件到暂存区/文件跟踪标记【git add】

可以使用git add 文件名，将工作空间的文件添加到暂存区，或批量添加文件

git add 文件名 # 将工作区的某个文件添加到暂存区   
git add -u # 添加所有被tracked文件中被修改或删除的文件信息到暂存区，不处理untracked的文件
git add -A # 添加所有被tracked文件中被修改或删除的文件信息到暂存区，包括untracked的文件
git add . # 将当前工作区的所有文件都加入暂存区
git add -i # 进入交互界面模式，按需添加文件到缓存区




5.让Git不Tracked特定文件【.gitignore文件配置】

将未tracked的文件添加到缓存区后，Git就会开始跟踪这个文件了！
对于一些比如：自动生成的文件，日志，临时编译文件等，就
没必要进行跟踪了，这个时候可以编写.gitignore文件，在里面
把不需要跟踪的文件或文件夹都写上，git就不会对这些文件进行跟踪！
另外.gitignore文件与.git文件夹在同级目录下！

如果不想自己写，可以直接到：https://github.com/github/gitignore 复制粘贴！
也可以自行编写，支持简化了的正则表达式(规范与示例模板摘自：Git王者超神之路)

        * ： 匹配零个或多个任意字符
        [abc]：只匹配括号内中的任意一个字符
        [0-9]：- 代表范围，匹配0-9之间的任何字符
        ?：匹配任意一个字符
        *：匹配任意的中间目录，例如a/*/z可以匹配:a/z,a/b/z,a/b/c/z等

示例模板：

# 忽略所有以 .c结尾的文件
*.c

# 但是 stream.c 会被git追踪
!stream.c

# 只忽略当前文件夹下的TODO文件, 不包括其他文件夹下的TODO例如: subdir/TODO
/TODO

# 忽略所有在build文件夹下的文件
build/

# 忽略 doc/notes.txt, 但不包括多层下.txt例如: doc/server/arch.txt
doc/*.txt

# 忽略所有在doc目录下的.pdf文件
doc/**/*.pdf

！！！特别要注意一点！！！：

配置.gitignore只对那些没有添加到版本控制系统的文件生效(未Tracked的文件)！

举个例子：

有A，B两个文件，你先把他两个add了，然后在.gitignore文件中
配置了不跟踪这两个文件，但是你会发现根本不会生效。

git add A
git add B
# 配置不跟踪A和B
git add .gitignore


所以，最好的做法就是在项目刚开始的时候，先添加.gitignore文件。
当然，即使是发生了，还是有解决方法的，可以键入下述命令清除标
记状态，然后先添加.gitignore，再添加文件即可：

git rm -r --cached . # 清除版本控制标记，.代表所有文件，也可指定具体文件


还有，如果你用的是IDEA的编辑器的话，可以下一个.ignore的插件，可以手动
直接勾选不需要跟踪的文件。
6.将暂存区内容提交到本地仓库【git commit】

git commit -m "提交说明" # 将暂存区内容提交到本地仓库
git commit -a -m "提交说明" # 跳过缓存区操作，直接把工作区内容提交到本地仓库


如果不加-m “提交说明”，git会让用你让默认编辑器(如vi)来编写提交说明，
可能有些朋友用不惯vi，要么别漏掉-m “提交说明”，要么自己设置编译器：

git config --global core.edit 喜欢的编辑器


除此之外，有时可能需要修改上次提交的内容，比如修改提交说明，或者修改文件等：

# 合并暂存区和最近的一次commit，生成新的commit并替换掉老的
# 如果缓存区没内容，利用amend可以修改上次commit的提交说明
# 注：因为amend后生成的commit是一个全新的commit，旧的会被
# 删除，所以别在公共的commit上使用amend！切记！！！

git commit --amend 
git commit --amend --no-edit # 沿用上次commit的提交说明


7.查看工作区与缓存区的状态【git status】

git status # 查看工作区与暂存区的当前情况
git status -s # 让结果以更简短的形式输出



8.差异对比(内容变化)【git diff】

git diff # 工作区与缓存区的差异
git diff 分支名 #工作区与某分支的差异，远程分支这样写：remotes/origin/分支名
git diff HEAD  # 工作区与HEAD指针指向的内容差异
git diff 提交id 文件路径 # 工作区某文件当前版本与历史版本的差异
git diff --stage # 工作区文件与上次提交的差异(1.6 版本前用 --cached)
git diff 版本TAG # 查看从某个版本后都改动内容
git diff 分支A 分支B # 比较从分支A和分支B的差异(也支持比较两个TAG)
git diff 分支A...分支B # 比较两分支在分开后各自的改动

# 另外：如果只想统计哪些文件被改动，多少行被改动，可以添加 --stat 参数



9.查看历史提交记录【git log】

git log # 查看所有commit记录(SHA-A校验和，作者名称，邮箱，提交时间，提交说明)
git log -p -次数 # 查看最近多少次的提交记录
git log --stat # 简略显示每次提交的内容更改
git log --name-only # 仅显示已修改的文件清单
git log --name-status # 显示新增，修改，删除的文件清单
git log --oneline # 让提交记录以精简的一行输出
git log –graph –all --online # 图形展示分支的合并历史
git log --author=作者  # 查询作者的提交记录(和grep同时使用要加一个--all--match参数)
git log --grep=过滤信息 # 列出提交信息中包含过滤信息的提交记录
git log -S查询内容 # 和--grep类似，S和查询内容间没有空格
git log fileName # 查看某文件的修改记录，找背锅专用


git blame 文件名 # 查看某文件的每一行代码的作者，最新commit和提交时间



12.为重要的commit打标签【git tag】

对于某些提交，我们可以为它打上Tag，表示这次提交很重要，
比如为一些正式发布大版本的commit，打上TAG，当某个版本
出问题了，通过TAG可以快速找到此次提交，拿到SHA1值，再
去查找问题，比起一个个commit看，省事很多！

Git标签分两种：轻量标签 和 附加标签
前者只是在提交上加个Tag，指向提交的Hash值；
而后者还会保存打标签者的信息，时间和附加信息；

git tag 标记内容 # 轻量标签
git tag -a 标记内容 -m "附加信息" # 附加标签


如果想为之前的某次commit打TAG的话，可以先找出SHA1值，设置调下述命令：

git tag -a 标记内容 版本id # 比如：git tag -a v1.1 bcfed96


默认情况，git push不会把标签推送TAG到远程仓库，如果想推送到服务器，可以：

git push origin 标记内容 # 推送某标签到

# 删除所有本地仓库中不存在的TAG：
git push origin --tags 


另外，可以在新建分支的时候也加上TAG

git checkout -b 分支名 标记内容


还可以用show命令查看标签对应的信息

git show 标记内容

如果你想删除本地Tag：

git tag -d 标记内容

如果是删除远程Tag：

git push origin --delete tag 标记内容


13.Git命令自动补全【输命令的时候按两次tab键】
文件回复/版本回退
1.文件恢复(未commit)【git checkout】

如果在工作区直接删除被Git Tracked的文件，暂存区中还会存在该文件，
此时键入：git status，会是这样：

Git告诉你工作区的文件被删除了，你可以 删掉暂存区里的文件或 恢复被删文件

# 删除暂存区中的文件：
git rm 文件名
git commit -m "提交说明"

# 误删恢复文件
git checkout -- 文件名

# 另外注意：git checkout会抛弃当前工作区的更改!!!不可恢复！！！务必小心！！！


2.文件恢复(已add未commit)【git reset HEAD】

如果更改后add到了暂存区，想恢复原状，下述指令可以让文件恢复原状：

git reset HEAD 文件名   
git checkout 文件名


3.版本回退(已commit)【git reset –hard】

文件已经commit了，想恢复成上次commit的版本或者上上次，可以：

git reset HEAD^ # 恢复成上次提交的版本
git reset HEAD^^ # 恢复成上上次提交的版本，就是多个^，以此类推或用~次数
git reset --hard 版本号 # git log查看到的SHA1值，取前七位即可，根据版本号回退

reset命令其实就是：重置HEAD指针，让其指向另一个commit
而这个动作可能会对工作区与缓存区造成影响，举个例子

        本来的分支线：- A - B - C (HEAD, master)
        git reset B后：- A - B (HEAD, master)
        解释：看不到C了，但是他还是存在的，可以通过git reset C版本号找回，前提是
        C没有被Git当做垃圾处理掉(一般是30天)。

reset三个可选参数解析：

        –soft：只是改变HEAD指针指向，缓存区和工作区不变；
        –mixed：修改HEAD指针指向，暂存区内容丢失，工作区不变；
        –hard：修改HEAD指针指向，暂存区内容丢失，工作区恢复以前状态；

4.查看输入指令记录【git reflog】

Git会记住你输入的每个Git指令，比如上面的git reset 切换成一个旧的
commit，然后git log后发现新提交的记录没了，想切换回新的那次commit，
可以先调git reflog 获取新commit的SHA1码，然后git reset 回去。

git reflog


注意：这个指令记录不会永久保存！Git会定时清理用不到的对象！！！
5.撤销某次提交【git revert】

有时可能我们想撤销某次提交所做的更改，可以使用revert命令

git revert HEAD # 撤销最近的一个提交
git revert 版本号 # 撤销某次commit


不是真的把提交给撤销了，而是生成一个新的提交来覆盖旧的提交，被撤销的提交
和新的提交记录都会保存！！！不信你再调一次revert HEAD 会发现被撤销的更改
又变回来了，另外，每次revert后，都需要发起新的commit！
简单点说，撤销的只是文件变化，提交记录依旧是存在的！

6.查看某次提交修改内容【git show】

git show 提交id # 查看某次commit的修改内容


7.查看某个分支的版本号【git rev-parse】

git rev-parse 分支名 # 查看分支commit的版本号，可以写HEAD

8.找回丢失对象的最后一点希望【git fsck】

因为你的某次误操作导致commit丢失，如果git reflog都找不到，你
可以考虑使用git fsck，找到丢失的对象的版本id，然后恢复即可。

git fsck --lost-found

本地分支
1.分支概念

提交记录串成的时间线，默认初始创建的分支(时间线) —— master分支，
如果不切换到其他分支上，每次commit生成的快照都会串在这条分支上！
另外还有个 —— HEAD指针，该指针指向正在工作的本地分支，前面的版
本回退其实修改的就是这个HEAD指针的指向！

比如：在master分支上执行四次commit，分支的状态图如下

不难发现这样的规律：

        每次commit，master都会向前移动一步，指向最新的提交
        HEAD则指向正在工作的本地分支，而git reset修改的就是HEAD指针的指向！

2.创建其他分支的原因

通过两个场景来体会创建其他分支的必要性

        场景一：
        项目一般都是一步步迭代升级的，有大版本和小版本的更新：
        大版本一般是改头换面的更新，比如UI大改，架构大改，版本是：
        v2.0.0这样；小版本的更新一般是UI小改，Bug修复优化等，版本是：
        v2.0.11这样；只有一条master分支，意味着：你的分支线会
        非常非常的长，假如你已经发布到了第二个大版本，然后用户反馈
        第一个版本有很严重的BUG，这时候想切回第一个版本改BUG，
        然后改完BUG切回第二个大版本，想想也是够呛的。
        (PS：可能你说我可以对重要的commit打tag，然后找到这个tag
        切回去，当然也行这里是想告诉你引入其他分支会给你带来的便利)
        场景二：
        只有一个master分支的话，假如某次提交冲突了，而这个冲突很难解决或者
        解决不了， 那么，那个整个开发就卡住在这里了，无法继续向后进行了！

3.一个最简单实用的分支管理策略

为了解决只有一个master分支引起的问题，可以引入分支管理，最简单的一种策略如下：

    在master分支上开辟一个新的develop分支，然后我们根据功能或者业务，再在develop
    分支上另外开辟其他分支，完成分支上的任务后，再将这个分支合并到develop分支上！
    然后这个功能分支的任务也到此结束，可以删掉，而当发布正式版后，再把develop分支
    合并到master分支上，并打上TAG。

master与develop分支都作为长期分支，而其他创建的分支作为临时性分支！
简述各个分支的划分：

    master分支：可直接用于产品发布的代码，就是正式版的代码
    develop分支：日常开发用的分支，团队中的人都在这个分支上进行开发
    临时性分支：根据特定目的开辟的分支，包括功能(feature)分支，或者预发布(release)分支，
    又或者是修复bug （fixbug）分支，当完成目的后，把该分支合并到develop分支，
    然后删除 该分支，使得仓库中的常用分支始终只有：master和develop两个长期分支！

4.分支创建与切换【git branch】

git branch 分支名 # 创建分支
git branch # 查看本地分支


比如在master分支上创建develop分支，此时的分支状况如下：

git checkout 分支名 # 切换分支
git checkout -b 分支名 # 创建分支同时切换到这个分支


//develop
切换到develop分支后，改点东西，再commit，此时的分支状况如下：

git checkout master 切回master分支，打开之前修改的文件，发现内容
并没有发生更改，因为刚刚的更改是在develop上提交的，而master上没有
变化，此时的分支状况如下：

5.分支的合并【git merge】 VS 【git rebase】

Git中，可以使用 git merge 和 git rebase 两个命令来进行分支的合并

git merge合并分支

合并的方式分为两种：快速合并 和 普通合并，两者的区别在于：
前者合并后看不出曾经做过合并，而后合并后的历史会有分支记录，如图：

快速合并： 普通合并 ：

示例：

快速合并，把develop分支合并到master分支上，来到master分支后，键入下述命令

git merge develop


打开文件：

普通合并，切到develop分支下，修改note_2.txt的内容，再通过下述指令合并分支：
注：–no-ff参数表示禁用快速合并！

git merge --no-ff -m "合并的信息(TAG)" develop

分支线情况：

git reabse合并分支

rebase(衍合或变基)，发现很多所谓的教程把这个东西写得太深奥了，
其实并没有那么复杂，只是这种合并会使得树整洁，易于跟踪，
举个简单的例子来对比下，有一个项目由两个人同时开发，
当前远程仓库的提交记录是这样的：

然后A和B各自开了一个条分支来完成相应功能，接着他们在自己的
分支上都做了多次的commit，此时两人的分别分支线是这样的：


A先合并，再到B合并，这里我们假设两人做的是完全不关联的模块，合并没有冲突

merge合并

rebase合并

用法：

git rebase 想合并到哪个分支的分支名

6.解决合并冲突

在我们合并分支的时候，有时会遇到合并冲突，然后合并失败的问题，
此时需要我们先解决冲突后才能进行合并，个人开发倒很少会遇到，多人
开发的时候遇到合并冲突则是家常便饭。

一个最简单的例子，A和B在develop分支上开辟出两个分支来完成相关的
功能，A做完了，把自己的分支合并到develop分支，此时develop分支向前
移动了几次commit，接着B也完成了他的功能，想把自己分支合并到develop
分支，如果改动的文件和和A改动的文件相同的话，此时就会合并失败，
然后需要处理完冲突，才能够继续合并！简单模拟下这个例子，先试试merge！

merge分支后处理冲突

打开冲突文件，然后处理冲突部分，保留什么代码你自己决定，处理完后把
<<< 和 >>> 这些去掉：

处理后：

然后add，然后commit即可，合并结束：

此时的分支线：

接着试试

rebase分支后处理冲突

重新来一遍，然后把A直接merge到master，再切到B，rebase master，此时出现
合并冲突，这里有三个可选的操作：

git rebase --continue # 处理完冲突后，继续处理下一个补丁
git rebase --abort # 放弃所有的冲突处理，恢复rebase前的情况
git rebase --skip # 跳过当前的补丁，处理下一个补丁，不建议使用，补丁部分的commit会丢失！


好的，有三次补丁要处理，一个个来：

处理后：

接着git add 添加修改后的文件，git rebase –continue继续处理补丁：

接着重复之前的过程：

处理后：

第三个补丁是与A分支无关联的改动，所以没有冲突，所以也就直接合并了！
如果合并中途出了什么差错可以git rebase –abort 恢复rebase前的状况！

最后看下分支线会发现是一条直线，这也是用rebase合并分支的优点：

附上栗子，可以自己试试：GitTest.7z
7.删除分支

对于合并完的分支，基本都没什么作用了，可以使用下述命令删除：

git branch -d 分支名 # 删除分支，分支上有未提交更改是不能删除的
git branch -D 分支名 # 强行删除分支，尽管这个分支上有未提交的更改


8.恢复误删分支

两步，找出被删除分支的最新commit的版本号，然后恢复分支

git log --branches="被删除的分支名" # 找到被删分支最新的commitb版本号
git branch 分支名 版本号(前七位即可) # 恢复被删分支


9.切换分支时保存未commit的更改【git stash】

有时我们可能在某个分支上正编写着代码，然后有一些突发的情况，需要
我们暂时切换到其他分支上，比如要紧急修复bug，或者切换分支给同事
review代码，此时如果直接切换分支是会提示切换失败的，因为这个分支
上做的更改还没有提交，你可以直接add后commit，然后再切换，不过我们
习惯写完某个功能再提交，我们想：

    先暂存这个分支上的改动，切去其他分支上搞完事，然后回来继续
    继续在之前的改动上写代码。

那么可以使用：

git stash # 保存当前的改动


然后放心的切换分支，然后再切换回来，接着使用：

git stash apply #　恢复保存改动


另外有一点一定要注意！！！可以stash多个改动！！如果你切换
到另一个分支又stash了，然后切换回来stash apply是恢复成另一个
分支的stash！！！

如果你这样stash了多次的话，我建议你先键入：

git stash list # 查看stash列表


找到自己想恢复的那个

比如我这里恢复的应该是netword上的stash，而第一个stash是devlop上的
直接git stash apply恢复的就是这个，然而恢复的应该是network的那个stash：

git stash apply stash@{1}


就是这样，按自己需要恢复即可！
10.分支重命名

git branch -m 老分支名 新分支名 # 分支重命名

    1

远程仓库与远程分支
1.远程仓库简述

用于代码托管，可以自己搭建远程仓库，或者选择专业的代码托管平台：
自己搭建的好处有：可控，内网安全，可以做一些定制，比如集成编译，IM等，
当然，肯定是需要一些学习成本的，(PS：我厂就是自己搭的Gitlab，自己配置
还是比较麻烦的，简单点的可以试试 Gogs)

常见的代码托管平台(自己搜关键字去~)：

Github，Git@OSC，GitCafe，GitLab，coding.net，gitc，BitBucket，Geakit，Douban CODE
2.推送本地仓库到远程仓库【git push】

首先建立好与本地仓库同名的远程仓库，然后复制下远程仓库的地址，比如：

键入下述命令关联本地与远程仓库

git remote add origin 远程仓库地址 

    1

可以键入下述命令可查看远程仓库状况

接着把本地仓库推送到远程仓库，这里的 -u参数 作为第一次提交使用，
作用是把本地master分支和远程master分支关联起来(设置默认远程主机)，
后续提交不需要这个参数！

git push -u origin master

    1

另外，如果想修改远程仓库地址，可键入：

git remote set-url origin 远程仓库地址

# 也可以先删除origin后再添加

git remote rm origin    # 删除仓库关联
git remote add origin 远程仓库地址 # 添加仓库关联

    1
    2
    3
    4
    5
    6

或直接修改.git文件夹中的config文件，直接替换圈住位置

还要说明一点，origin 并不是固定的东西，只是后面仓库地址的一个 别名！！
可以写成其他的东西，然后你也可以设置多个仓库关联，用不同的别名标志，比如：

git remote add github https://github.com/coder-pig/SimpleTea.git
git remote add osc git@git.oschina.net:coder-pig/SimpleTea.git

    1
    2

3.克隆远程仓库【git clone】

把项目推送到远程仓库后，其他开发者就可以把项目clone到本地

git clone 仓库地址 # 克隆项目到当前文件夹下
git clone 仓库地址 目录名 # 克隆项目到特定目录下

    1
    2

4.同步远程仓库更新【git fetch】VS 【git pull】

关于获取远程服务器更新的方式有两种，他们分别是fetch和pull，
尽管都可以获取远程服务器更新，但是两者却又是不一样的。

git fetch：

仅仅只是从远处服务器获取到最新版本到本地，假如你不去合并(merge)
的话，本地工作空间是不会发生变化的！比如：
我们在Github上创建一个README.md文件，然后调 git fetch 去获取远程
仓库的更新。

git pull：

一步到位，或者说：pull = fetch + merge，比如：同样修改Github上的
README.md 文件，然后git pull 同步远程仓库的更新

区别显而易见，实际开发中，使用git fetch会更安全一些，毕竟merge的时候
我们可以查看更新的情况，再决定是否进行合并，当然看实际需要吧！
5.推送本地分支到远程仓库

按照前面所讲，在本地开辟分支来完成某些工作，本地提交了多次后，
你想把分支推送到远程仓库，此时远程仓库并没有这个分支，你可以：

git push origin 分支名 # 推送本地分支的内容到远程分支

    1

6.查看远程分支

git branch -r # 查看所有分支

    1

7.拉取远程分支到本地仓库

git checkout -b 本地分支 远程分支 # 会在本地新建分支，并自动切换到该分支
git fetch origin 远程分支:本地分支 # 会在本地新建分支，但不会自动切换，还需checkout
git branch --set-upstream 本地分支 远程分支 # 建立本地分支与远程分支的链接

    1
    2
    3

8.删除远程分支

git push origin :分支名 

    1

9.重命名远程分支

先删除远程分支，然后重命名本地分支，接着再Push到远程仓库
10.为项目添加SSH Key免去提交输入账号密码的麻烦

不知道细心的你有没有发现，仓库地址除了Https外，还有一个SSH，
这里我们简单介绍下两者的区别，第一点：使用Https url可以任意克隆
Github上的项目；而是用SSH url克隆的话，你必须是项目的拥有者或
管理员，而且还要添加SSH Key，否则会无法克隆。还有一点是，
Https每次push都需要输入用户名和密码，而使用SSH则不需要输入
用户名如果配置SSH Key时设置了密码，则需要输入密码，否则直接
git push就可以了！

另外，SSH，Secure shell(安全外壳协议)，专为远程登陆会话
与其他网络服务提供安全性的协议，而SSH传输的数据是可以经过压缩的，
可以加快传输的速度，出于安全性与速度，我们优先考虑使用SSH协议，
而SSH的安全验证规则又分为基于密码和基于密钥两种！
我们这里用的是基于第二种的，即在本地创建一对密钥，
公钥(id_rsa.pub)和私钥(id_rsa),然后把公钥的内容贴到
Github账号的ssh keys中，这样就建立了本地和远程的认证关系，
当我们再push到远程仓库，会将你本地的公共密钥与服务器的进行匹配，
如果一致验证通过直接推送更新！

下面我们来建立ssh key，首先来到电脑的根目录下，这里假定我们没
创建过SSH key：

执行完ssh-keygen那个指令后，后面依次要你输入文件名，
直接回车会生成两个默认的秘钥文件，接着提示输入密码，
直接回车，如果这里你输入密码了的话，那么push的时候
你还是需要输入密码，接着又输多一次密码，同样回车，
然后出现最下面的这串东西就说明ssh key已经创建成功了！

我们接着可以用编辑器打开id_rsa.pub文件或者键入:

clip <id_rsa.pub

    1

复制文件内容，然后打开Github，点击你的头像，选择：Settings，
然后点击左侧SSH Keys,然后New SSH Key

然后Github会给你发来一个提示创建了一个新ssh key的邮件，
无视就好，接下来我们可以键入：ssh -T git@github.com，
然后如果你上面设置过密码则需要输入密码，
否则直接输入yes然后一直按回车就好！，最后出现Hi xxx那句话
就说明ssh key配置成功了！

PS：其他远程仓库配置方法与此类同，
内容参考自：https://help.github.com/articles/generating-an-ssh-key/
附1：Github客户端

其实，安装好Git后，就一有一个GitGui的东东了，就可以直接
用有用户界面的Git来做版本管理的工作了，而Github客户端则是
Github给我们提供的一个专门用来管理Github项目的一个工具而已。
比如，假如你装了Github客户端，在Clone项目的时候，你只需点击：

就能直接把项目clone下来，就是一些Git操作的图形化罢了，首先来到下面的链接
下载Github客户端：https://desktop.github.com/
文件很小，后面点击运行文件后，他还要在线下载安装，100多m，
然后傻瓜式安装，安装完成后，会自动打开Github客户端，然后
使用你的Github账号登陆，接着他会默认为你创建SSH Key信息，
接着的你自己摸索了！

这里另外补充一点，就是win 8.1装Github客户端的问题，
昨晚安装的时候一直报这个错误：

直接，win + x，选择”命令行提示符(管理员)“，执行以下下面的这个指令：

%SYSTEMROOT%\SYSTEM32\REGSVR32.EXE %SYSTEMROOT%\SYSTEM32\WUAUENG.DLL

    1

然后再点击Github的安装程序，等待安装完成即可，下载并不需梯子。
附2：删除Git仓库

点击进入你的仓库，点击Setting，拉到最后：

点击Delete this repository

弹出的对话框中输入要删除的仓库名称，接着点击删除

附3：为开源项目贡献代码

你可以Clone别人的开源项目，在看别人代码的时候，你觉得作者有
某些地方写得不好，写错，或者你有更好的想法，你在本地修改后，
想把修改push推送到开源项目上，想法很好，但是你不是项目的拥
有着和参与者，是无法推送更改的！！！这样是为了
避免熊孩子，毕竟熊孩子无处不在，参与开源项目的方法有两种：

第一种方法：
是让作者把你加为写作者，添加协作者流程：点击仓库的Settings
–>Collaborators然后输入想添加的人的用户名或者邮箱，点击
添加即可。

第二种方法：
点击Fork按钮，把这个项目fork到自己的账号下，然后Clone
到本地，然后做你想做的修改，commit提交，然后push到自己账
号里的仓库，然后打开开源项目，点击，然后新建一个
pull request，接着设置自己的仓库为源仓库，设置源分支，
目标仓库与目标分支，然后还有pull request的标题和描述信息，
填写完毕后，确定，这个时候开源项目的作者就会收到一个pull
request的请求，由他来进行审核，作者审查完代码觉得没问题
的话，他可以点击一下merge按钮即可将这个pull request合并
到自己的项目中，假如作者发现了你代码中还有些bug，他可以
通过Pull Request跟你说明，要修复了xxBUG才允许合并，那么
你再修改下BUG，提交，更改后的提交会进入Pull Request，
然后作者再审核这样！

PS:假如作者不关闭或者merge你的这个Pull Request，你可以一直
commit骚扰主项目…( ╯□╰ )
Git工作流

关于Git工作流，看到一篇图文并茂很好的文章，就不重复造轮子了，
此处只是做下对应工作流的简述，详情见：Git Workflows and Tutorials
1.集中式工作流

类似于SVN，不过只有一条master分支，然后一群人就在这条分支上嗨，比如有小A和小B：
(冲突解决参照上面的套路)

        1.项目管理者初始化仓库，然后推到远程仓库
        2.其他人克隆远程仓库项目到本地
        3.小A和小B完成各自的工作
        4.小A先完成了，git push origin master 把代码推送到远程仓库
        5.小B后完成了，此时推送代码到远程仓库，出现文件修改冲突
        6.小B需要先解决冲突，git pull –rebase origin master，然后rebase慢慢玩
        7.小B把冲突解决后，git push origin master 把代码推送到远程仓库

2.功能分支工作流

和集中式分部流相比只是分支再不是只有master，而是根据功能开辟新的分支而已，示例：
注：这里的仓库管理者是拥有仓库管理权限的人

        1.小A要开发新功能，git branch -b new-feature 开辟新分支
        2.小A在new-feature上新功能相关的编写，他可以这个分支推到远程仓库
        3.功能完成后，发起请求pull request(合并请求)，把new-feature合并到master分支
        4.仓库管理员可以看到小A的更改，可以进行一些评注，让小A做某些更改，
        然后再发起pull request，或者把pull request拉到本地自行修改。
        5.仓库管理员觉得可以了，合并分支到master上，然后把new-feature分支删掉

3.Gitflow工作流

其实就是功能分支工作流做了一些规范而已，大概流程参见上面Git分支里的：
一个最简单实用的分支管理策略。
4.Forking工作流

分布式工作流，每个开发者都拥有自己独立的仓库，和上面的附3：为开源项目贡献代码
套路类似，把项目fork到自己的远程仓库，完成相应更改，然后pull request到源仓库，
源仓库管理者可以决定是否合并。
5.Pull Request工作流

和Forking工作流类似，Pull Requests是Bitbucket上方便开发者之间协作的功能
查缺补漏

一些高级技巧，工具，插件安利
1.巨好用的Git图形化工具SourceTree

命令行虽酷炫可装逼，但是有时用图形化工具还是能提高我们不少效率的，
如题，SourceTree，官网下载地址：https://www.sourcetreeapp.com/
2.把提交的commit从一个分支放到另一个分支【git cherry-pick】

有时你可能需要把某个分支上的commit放到另一个分支上，这个时候可以
使用cherry-pick，比如有下面这样两个分支：

master分支：A -> B -> C
feature分支：a -> b

现在想把feature上的b，放到master的C后，可以这样：

    Step 1：切换到feature分支上，git log拿到b commit的版本号(SHA1)
    Step 2：切换到master分支，键入：git cherry-pick 版本号

出现上面这种情况的话说明出现冲突了，处理冲突后，git add 和 git commit 走一波
即可。
问题解决
1.fatal: refusing to merge unrelated histories

问题描述：在Github上新建了一个仓库，里面带有一个licence文件，然后本地
本地项目想推到这个远程仓库上，git remote 设置了远程仓库后，push提示先pull，
pull的时候就报这个错了，解决方法如下：

git pull origin master --allow-unrelated-histories