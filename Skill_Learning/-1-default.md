# 默认问题收藏夹

## smPlayer的视频速度调节方法
`[` 减速
`]` 加速


## 安装gcc的方法
到https://github.com/skeeto/w64devkit/releases下载压缩包，然后解压把bin目录配置到环境变量

## wsl2获取ubuntu可安装的列表
wsl --list --online

## java环境配置
jdk生成jre步骤：cmd进入jdk目录,输入命令：`bin\jlink.exe --module-path jmods --add-modules java.desktop --output jre`

1. JAVA_HOME
你的jdk目录
2. CLASS_PATH
.;%JAVA_HOME%\lib\dt.jar;%JAVA_HOME%\lib\tools.jar;
3. PATH
   变量名：Path
　 变量值：%JAVA_HOME%\bin;%JAVA_HOME%\jre\bin;

## vim基本配置


22s