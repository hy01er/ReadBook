# Ubuntu

#### Ubuntu 软链接
就是Windows的快捷方式：`ln -s {源文件夹 或者 源文件}  {软连接文件夹放在哪里  或者  目的文件}`
1. ln ./src/lib ./     在本级目录建立./src/lib的文件夹软连接，就是把文件夹的软连接放在那里
2. ln ./1.c  ./link_to_c.c  link_to_c.c是1.c的快捷方式