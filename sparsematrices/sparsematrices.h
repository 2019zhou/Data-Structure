#pragma once
#include <fstream>
#include <cstdlib>
const int maxsize = 100;	//此处定义的是三元组表的三元组对象的数目
constexpr auto roww = 50;

//一个三元组
template <typename T>
struct elements
{
	int row;	//这里约定数组的下表从0开始
	int col;
	T e;
};

//三元组表
template <typename T>
class sparsematrices
{
private:
	int row;	//行总数
	int col;	//列总数
	int len;	//非零元个数
public:
//构造函数
	sparsematrices(const char*file); //包括初始化，导入数据的部分
	sparsematrices() { row = 0; col = 0; len = 0; e = new elements<int>[maxsize];}
	//~sparsematrices() { delete[] e; }	//这里产生访问冲突因为e不是单纯的数组，而是一个struct,不可以这么删除
//有关操作
	elements<int>* e;
	int getrow() { return row; };
	int getcol() { return col; };
	int getlen() { return len; };
	void displaytable();
	void display();
	void transposematrix();	//矩阵的转置
	void sorting();	//按行排序的矩阵
	void sortingcol();	//按列排序的矩阵
	void addmatrix(sparsematrices matrix2);
	void submatrix(sparsematrices matrix2);
	void mulmatrix(sparsematrices matrix1, sparsematrices& matrixnew);
	int find(int i);//寻找第i行的元素是否存在，不存在返回-1，存在返回在len为序中的下标
};

template<typename T>
sparsematrices<T>::sparsematrices(const char * file)
{
	//获取行数
	row = 0;
	ifstream f1;
	f1.open(file, ios::in);
	string temp;
	while (getline(f1, temp, '\n'))
	{
		if (temp.size() > 0)
			row++;
	}
	f1.close();
	//获取列数
	col = 0;
	ifstream f2;
	f2.open(file, ios::_Nocreate);
	while (f2.peek() != '\n') {
		f2.get();
		col++;
	}
	col = (col + 1) / 2;
	f2.close();
	//初始化有关数据
	e = new elements<int>[maxsize];
	len = 0;
	ifstream f3;
	int count = 0;
	f3.open(file, ios::in);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col;) {			//开始这里的j的循环条件设置错误
			if (f3.peek() == '0') { 
				f3.get();
				j++;
			}
			else if (f3.peek() == '\n') {
				f3.get();
			}
			else if (f3.peek() == '\t') {
				f3.get();
			}
			else {
				e[len].row = i;
				e[len].col = j;
				f3 >> e[len].e;
				len++;
				j++;
			}
		}
	}
}



template<typename T>
void sparsematrices<T>::displaytable()
{
	cout << "ROW\t" << "COLUMN\t" << "DATA" << endl;
		for (int i = 0; i < len; i++)
			cout << e[i].row << "\t" << e[i].col << "\t" << e[i].e << endl;
	cout << "--------------------" << endl;
}

template<typename T>
void sparsematrices<T>::transposematrix()
{
	//完成两件事情，1.将行，列交换 2.按照列序排列
	for (int i = 0; i < len; i++)
		swap(e[i].col, e[i].row);
	sorting();
}


template<typename T>
void sparsematrices<T>::display()
{
	int num = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (num < len && i == e[num].row && j == e[num].col) {
				cout << e[num].e << "\t";
				num++;
			}
			else cout << "0\t";
		}
		cout << endl;
	}
}

template<typename T>
void sparsematrices<T>::sorting()	
{
	elements<int>*  temp = new elements<int>;
	for (int i = 0; i < len; i++){
		for(int j = i + 1;j < len;j++)
			if (e[i].row > e[j].row) {
				*temp = e[i];
				e[i] = e[j];
				e[j] = *temp;	//可能涉及浅复制和深复制的问题
			}
	}
	delete temp;
}

template<typename T>
void sparsematrices<T>::addmatrix(sparsematrices matrix2)	//由于是按照顺序存储，故加法效率可以提升
{
	if (row != matrix2.row || col != matrix2.col) {
		cout << "矩阵的行，列不合法" << endl;
		exit(0);
	}
	else {
		int len2 = matrix2.getlen();
		for(int i = 0;i < len;i++)
			for (int j = 0; j < len2; j++)
			{
				//cout << e[i].row << ends << matrix2.e[j].row << 
				if (e[i].row == matrix2.e[j].row && e[i].col == matrix2.e[j].col)
					e[i].e += matrix2.e[j].e;
				if (e[i].row < matrix2.e[j].row) break;
			}
	}
}


template<typename T>
void sparsematrices<T>::submatrix(sparsematrices matrix2)
{
	if (row != matrix2.row || col != matrix2.col) {
		cout << "矩阵的行，列不合法" << endl;
		exit(0);
	}
	else {
		int len2 = matrix2.getlen();
		for (int i = 0; i < len; i++)
			for (int j = 0; j < len2; j++)
			{
				if (e[i].row == matrix2.e[j].row && e[i].col == matrix2.e[j].col)
					e[i].e -= matrix2.e[j].e;
				if (e[i].row < matrix2.e[j].row) break;
			}
	}
}

template<typename T>
void sparsematrices<T>::mulmatrix(sparsematrices matrix1, sparsematrices& matrixnew) 
{
	if (row!= matrix1.col || col != matrix1.row) 
	{
		cout << "矩阵的行列不合法" << endl;
		exit(0);
	}
	matrixnew.row = row;
	matrixnew.col = matrix1.col;
	matrixnew.len = 0;

	//构建reference表格,当数据差值很大是，referencethis表格似乎占据了很大的空间,但也不过是根号n的复杂度，所以还是减少了一个复杂度
	int reference[50] = {0};
	int count = 0;
	for (int i = 1; i <= len; i++) {
		if (e[i].row != e[i - 1].row) {
			reference[i] = i;
		}
		else reference[i] = reference[i - 1] ;
	}
	/*for (int k = 0; k < len; k++)
		cout << reference[k] << ends;*/

	//具体计算稀疏矩阵
	int num = 0;
	int m = 0;
	int ctemp[roww] = {0};
	if (len * matrix1.len != 0) {
		for (int i = 0; i < row; i++)	//处理this matrix中的每一行数据
		{
			if (find(i) == -1) continue;	//如果发现第一个矩阵第i行没有非0元素，下一循环
			memset(ctemp, 0, sizeof(ctemp));	//数组清零
			m = find(i);	//m存row开始的位置
			//计算matrixnew中i行的积并存入ctemp[]中
			do {
				for (int k = 0; k < matrix1.getlen(); k++) {
					if (matrix1.e[k].row == e[m].col)
					{
						ctemp[matrix1.e[k].col] += matrix1.e[k].e * e[m].e;
						//cout << "列数" << matrix1.e[k].col << ends;
						//cout << ctemp[matrix1.e[k].col] << endl;
					}
				}
				m++;
			} while (reference[m] == reference[m - 1]);
		//将ctemp[]中的非零元压缩存储
			for (int j = 0; j < row; j++)
			{
				if (ctemp[j])
				{
					matrixnew.e[num].e = ctemp[j];
					matrixnew.e[num].row = i;
					matrixnew.e[num].col = j;
					matrixnew.len++;
					num++;
					//matrixnew.displaytable();
				}
			}
		}
		
	}
}


template<typename T>
void sparsematrices<T>::sortingcol()
{
	elements<int>* temp = new elements<int>;
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++)
			if (e[i].col > e[j].col) {
				*temp = e[i];
				e[i] = e[j];
				e[j] = *temp;	//可能涉及浅复制和深复制的问题
			}
	}
	delete temp;
}

//应该只有reference这里有问题

template<typename T> ////寻找第i行的元素是否存在，不存在返回-1，存在返回在len为序中的下标
int sparsematrices<T>::find(int t) {
	for (int i = 0; i < len; i++) {
		if (e[i].row == t)
			//cout << i;
			return i;
	}
	return -1;
}