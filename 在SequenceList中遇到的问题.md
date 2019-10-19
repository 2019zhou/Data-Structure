**由于C++模板而造成的链接问题**

> 原理https://blog.csdn.net/imred/article/details/80261632 
- 所以解决方法有两个
- 在函数实现的.cpp文件中加上这样的一行代码：template int add(const int &a, const int &b); 
- 使得其实例化
- 在函数的头文件中完成所有的函数定义
- 所以，最后的建议应该是，如果用到函数的模板，最好在头文件中实现所有的函数

