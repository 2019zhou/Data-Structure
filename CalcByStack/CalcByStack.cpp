// CalcByStack.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//使用栈的数据结构实现一般计算器的加减乘除，并用栈实现二、十进制的转换
//准备完成，配合Qt软件实现桌面可视化功能,
#include <iostream>
#include <ctype.h>
#include "stack.h"
const int opernum = 9;
const int length = 1024;
enum operators { ADD, SUB , MUL, DIV, POW, NEG, L_P, R_P, END };
const char pri[opernum][opernum] = {
	//		      当  前  操 作 符
	//        +    -     *    /    ^    !  (    )    \0
	/*栈 + */'>', '>', '<', '<', '<', '<', '<', '>', '>',
	/*顶 - */'>', '>', '<', '<', '<', '<', '<', '>', '>',
	/*运 * */'>', '>', '>', '>', '<', '<', '<', '>', '>',
	/*算 / */'>', '>', '>', '>', '<', '<', '<', '>', '>',
	/*符 ^ */'>', '>', '>', '>', '>', '<', '<', '>', '>',
	/*	 ! */'>', '>', '>', '>', '>', '>', ' ', '>', '>',
	/*	 ( */'<', '<', '<', '<', '<', '<', '<', '=', ' ',
	/*	 ) */' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	/*	 \0*/'<', '<', '<', '<', '<',  '<', '<',' ', '=',
};

//        +    -     *    /    ^    !  (    )    \0
operators oprank(char op) {
	switch (op) {
	case '+': return ADD;
	case '-': return SUB;
	case '*': return MUL;
	case '/': return DIV;
	case '^': return POW;
	case '!': return NEG;
	case '(': return L_P;
	case ')': return R_P;
	case '\0': return END;
	default: exit(-1);
	}
}

double evaluate(char* S, char*& RPN);					//总体的计算框架
void readnumber(char a, Stack<double>& opnd);					//将数据读入操作栈内
void append(char* rpn, char a);							//将数据放在逆波兰表达式之后
char resultcmp(char op, char opstack);								//用来返回原操作数与栈顶操作数的关系
double calc(double, char, double);
double calc(double, char);
double power(double a, double c);
void ilegalize(char a[]);					//用于处理可以处理的不合规输入，如空格，中文字符和英文字符的问题

int main()
{
    //test for stack basic function
	//Stack<int> S1;
	//S1.push(1);
	//S1.push(2);
	//S1.push(4);
	//S1.push(5);
	//S1.display();
	//S1.pop();
	//S1.display();
	//S1.pop();
	//S1.display();
	//cout << S1.top() << endl;
	std::cout << "请输入一个表达式" << std::endl;
	//输入一个无空格的表达式s,另一个为RPN,即逆波兰表达式
	char stringin[length >> 2] = { 0 };
	std::cin.getline(stringin,length-1);
	//ilegalize(stringin);							//用于处理可以处理的不合规输入，如空格，中文字符和英文字符的问题
	char stringout[length >> 2] = { 0 };
	char* pstringout = stringout;

	std::cout << evaluate(stringin,pstringout) << std::endl;

	return 0;
}

double evaluate(char* S, char*& RPN)
{
	Stack<double> opnd;			//操作数栈
	Stack<char> optr;			//操作符栈
	optr.push('\0');
	//std::cout << optr.empty() << std::ends <<optr.getsize()<< std::endl;
	while (!optr.empty()) {
		if (isdigit(*S)) {			//如果读入的是数
			readnumber(*S,opnd);
			append(RPN, opnd.top());
			//std::cout << opnd.top() << std::endl;
			S++;
		}
		else {						//如果读入的是操作符
			switch (resultcmp(*S, optr.top()))	//返回当前运算符和栈顶运算符的比较结果，查表可知
			{
			case '<':							//入栈，不做计算
				optr.push(*S); S++;
				//std::cout << optr.top() << std::endl;
				break;
			case '=':							//可能的情况只有左右括号，和结束标志
				optr.pop(); S++;
				break;
			case '>': {							//计算
				char op = optr.top();
				append(RPN, op);
				if ('!' == op)					//一元操作符
				{
					opnd.push(calc(opnd.pop(), op));
					optr.pop();
				}
				else {							//二元情况
					double op1 = opnd.pop(), op2 = opnd.pop();
					//std::cout << op1 << std::ends << op2 << std::endl; 到这步中op2中的值是乱码
					double temp = calc(op1, op, op2);
					optr.pop();
					//std::cout << temp <<std::ends<<op1<<std::ends<<op2<< std::endl;
					opnd.push(temp);
				}
				break;
			}
			default: exit(-1);
			}
		}
	}
	return opnd.pop();
}

void readnumber(char a, Stack<double>& opnd)			//将数据读入操作栈内
{
	int t = a - '0';
	opnd.push(t);
}


void append(char* rpn, char a)					//将数据放在逆波兰表达式之后
{
	*rpn = a;
	rpn++;
}

char resultcmp(char op, char opstack)				//用来返回原操作数与栈顶操作数的关系
{
	return pri[oprank(opstack)][oprank(op)];
}

//        +    -     *    /    ^    !  (    )    \0
double calc(double a,char b,double c)
{
	switch (b) {
	case '+': return a + c;
	case '-': return a - c;
	case '*': return a * c;
	case '/': return a / c;
	case '^': return power(a, c);
	default: exit(-1);
	}
}

double calc(double a,char b)
{
	int i = a;
	int sum = 1;
	while (i--) {
		sum *= i;
	}
	return sum;
}


double power(double c, double a) {			//开始这里做错了，因为没有考虑到出栈的时候的顺序问题
	double t = a;
	for (int i = 0; i < c -1; i++) {
		a = a * t;
	}
	return a;
}

//
//void ilegalize(char a[]) {
//	int i = 0;
//	for (int i = 0; i < sizeof(a) / sizeof(char); i++) {
//		if(a[i] == " ")
//	}
//
//}