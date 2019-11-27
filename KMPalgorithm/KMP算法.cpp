// KMP算法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//这里将实现KMP算法的基本算法，和改进模式
//重点在KMP算法的实现
//子串由matlab自动生成
//开始使用了STL库中的string,
//next, match两个命名可能都有命名冲突


#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//构造next表
int* nexttable(string p)
{
	int n = p.length();
	int* q;
	q = new int[n];
	q[0] = -1;
	int i = 0;
	int t = -1;
	while (i < n - 1)	//注意这里是n -1 ，开始使用n 导致了string subscript out of range
	{
		if (0 > t || p[t] == p[i]) {
			t++; i++;
			q[i] = p[t] != p[i] ? t : q[t];  //和之前相比 只是改成了q[i] = t;
		}
		else t = q[t];
	}

	for (int i = 0; i < n; i++) {
		cout << q[i] << endl;
	}
	return q;
}




//kmp主算法实现
int matching(string substr,string mainstr)
{
	int* next = nexttable(substr);	//next表格
	/*for (int i = 0; i < substr.length(); i++) {
		cout << next[i] << endl;
	}*/
	int lensub = substr.length();
	int lenmain = mainstr.length();
	int i = 0;
	int t = 0;
	while (i < lensub  && t < lenmain) {
		if (0 > i || substr.at(i) == mainstr.at(t) ){
			t++;
			i++;
		}
		else i = next[i];//模式串回退
	}
	delete[] next;
	return t - i;
}


int main()
{
	//先进行基本的文件输入输出设置
	string substring;
	ifstream fin;
	fin.open("testkmp1.txt",ios::in);
	//输入文件的子串
	if(fin.is_open()) 
		getline(fin, substring);
	else cerr << "error in open the file" << endl;
	fin.close();
	
	string mainstring;
	ifstream fin2;
	fin2.open("testkmp2.txt", ios::in);
	//输入文件的子串
	if (fin2.is_open()) 
		while(getline(fin2, mainstring));
	else  cerr << "error in open the file" << endl;
	fin2.close();

	int m;	//m用来存放串匹配的位置
	m = matching(substring, mainstring);

	//输出至resultkmp1.txt
	ofstream fout;
	fout.open("resultkmp1.txt", ios::app);
	if (fout.is_open()) 
		fout << "和substring" << substring << "匹配的第一个在：" << m << "位置";
	else cerr << "error in open the file" << endl;
	fout.close();
	
	return 0;
}

