// sparsematrix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//稀疏矩阵的基本操作，加,减,乘,转置，使用顺序存储结构
//资源文件说明，matrix1,matrix2主要用于演示乘法
//matrix1,matrix3可以用于演示element wise的乘法，以及加法，减法
#include <iostream>
#include <fstream>
#include <string>
#include "sparsematrices.h"
using namespace std;

int main()
{
	//读入数据, 初始化在乘，加中需要用到的三元组表
	sparsematrices<int> matrix_l("matrix4.txt");
	sparsematrices<int> matrix_r("matrix5.txt");

	//test
	//cout << matrix_l.getrow() << ends << matrix_l.getcol() << endl;
	//cout << matrix_r.getrow() << ends << matrix_r.getcol() << endl;
	//cout << matrix_l.getlen() << endl;
	
	matrix_l.displaytable();
	matrix_r.displaytable();

	//matrix_l.display();
	//matrix_r.display();

	//矩阵的转置
	//matrix_l.transposematrix();
	//matrix_l.displaytable();

	//矩阵相加
	//matrix_l.addmatrix(matrix_r);
	//matrix_l.displaytable();

	//矩阵相减
	//matrix_l.submatrix(matrix_r);
	//matrix_l.displaytable();

	//矩阵相乘
	sparsematrices<int> matrixnew;
	matrix_l.mulmatrix(matrix_r,matrixnew);
	matrixnew.displaytable();
	return 0;
}