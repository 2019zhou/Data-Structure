// 离散事件模拟--队列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 存储结构：顺序表存储，
// 银行有多个服务窗口

#include <iostream>
#include "Queue.h"
using namespace std;

void simulate(int nWin, int servTime); //模拟银行
void time(int i);
int bestwindow(Queue windows[], int nWin);//自动选择最好的窗口

void simulate(int nWin, int servTime)
{

	Queue* windows = new Queue[nWin];
	for (int i = 0; i < servTime; i++)
	{
		if(rand() % (1 + nWin)){
			customer c;
			c.time = 1 + rand() % 40;
			//cout << c.time << endl;
			c.window = bestwindow(windows,nWin);
			windows[c.window].enqueue(c);
		}


		//for (int i = 0; i < nWin; i++) {
		//	cout << "this is window " << i + 1 << ":\t";
		//	windows[i].display();
		//	cout << endl;
		//	cout << windows[i].rear << ends << windows[i].front << endl;			//only for debug
		//	cout << windows[i]._size << endl;
		//}
		//cout << endl;


		for (int i = 0; i < nWin; i++) {
			if (windows[i].empty() > 0) {
				windows[i].frontdec();
				if ((windows[i].getrear()-1) <= 0)		//这里getfront就是顾客时间
					windows[i].dequeue();
			}
		}
		time(i);
		
		for (int i = 0; i < nWin; i++) {
			cout << "this is window " << i + 1 << ":\t";
			windows[i].display();
			cout << endl;
			//cout << windows[i].rear << ends << windows[i].front << endl;			//only for debug
			//cout << windows[i]._size << endl;
		}
		cout << endl;
	}
	delete[] windows;
}


int bestwindow(Queue windows[],int nWin)
{
	int minSize = windows[0].size(), optiWin = 0;
	for(int i = 0;i <nWin;i++)
		if (minSize > windows[i].size()) {		//选择人最少的队伍
			minSize = windows[i].size();
			optiWin = i;
		}
	return optiWin;
}

void time(int i)					//用来处理当前的时间问题
{
	int hour;
	int minute;
	hour = i / 60;
	minute = i % 60;
	cout << "现在是" << hour << ":" << minute << endl;
}


int main()
{
	printf("银行排队窗口，基本参数设置\n");
	printf("银行排队窗口：");
	int nWin;
	cin >> nWin;
	printf("银行工作总时间(h)：");
	double servicetime;
	cin >> servicetime;

	simulate(nWin, servicetime*60);

	return 0;
}
