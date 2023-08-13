# linux_learn
# 学习Linux基础知识和实践项目
# 项目工程开发
# sample01
1.解决代码耦合、逻辑不清晰和团队合作困难的问题，将功能代码模块化
2.解决随着功能增多带来的项目责任田混淆，将创建模块功能文件夹
3.解决编译困难、繁琐问题，引入make工具
## build
    //gcc编译
    gcc -o main main.c hello/hello.c world/world.c -I world
    或
    gcc -c hello/hello.c
    gcc -c world/world.c
    gcc -c main.c -I world
    gcc -o main main.o hello.o world.o
    //引入make，创建Makefile
    main:main.o hello.o world.o
	    gcc -o main main.o hello.o world.os
    main.o:main.c hello/hello.h world/world.h
	    gcc -c main.c -I world
    hello.o:hello/hello.c hello/hello.h
	    gcc -c hello/hello.c
    world.o:world/world.c world/world.h
	    gcc -c world/world.c
    clean:
	    rm -rf main main.o hello.o world.o
    //引入cmake，创建CMakeLists.txt

# sample02
1.无法跨平台构建问题，引入cmake工具,创建CMakeLists.txt
    //创建存放过程文件的文件夹
    mkdir build
    cmake ../
    make
    //显示详细过程
    make VERBOSE=1
# sample03
1.解决对功能代码文件增加删除时，使用同一个CMakeLists.txt所带来的编译耦合的问题
