// heapsort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

//常用的快捷键接口，宏定义
#define parent(i) ((i - 1)>>1)
#define LChild(i) ((i << 1)+1)
#define RChild(i) ((i + 1)<<1)

class heap {
private:
    int n;  //堆中元素的个数，即堆的规模
    vector<int> v;
protected:
    int percolateDown(int n, int i);  //下滤
    void percolateUp(int i);          //上滤
public:
    heap() { n = 0; }
    heap(int a[], int n);
    void insert(int t);
    int delmax();   //delete max
    int getmax() { return v[0]; } //get the max
    bool empty() { return !n; }
    void print() { for (int i = 0; i < n; i++) cout << v[i] << ends; cout << endl; }
    int maxno(int a, int b, int c) {
        int max;
        //检查是否符合要求
        if (a > n - 1) a = b;
        if (b > n - 1) {
            b = a = c;
            return c;
        }
        max = v[a] > v[b] ? a : b;
        max = v[c] > v[max] ? c : max;
        return max;
    }
};

heap::heap(int a[], int num)
{
    /*for (int i = 0; i < num; i++)
        cout << a[i];
    cout << endl;*/
    v.push_back(a[0]);
    //建堆
    for (int i = 0; i < num; i++)
        insert(a[i]);
    /*for (int i = 0; i < num; i++)
        cout << v[i];*/
}

void heap::insert(int t) {
    v.push_back(t);
    n++;
    percolateUp(n);
}

int heap::delmax()
{
    int temp = v[0];
    swap(v[0], v[n - 1]);
    n--;
    percolateDown(n, 0);
    return temp;
}

int heap::percolateDown(int n, int i) {
    int no = -1;
    while (i < n) {
    no = -1;
    //取自己，左孩子，右孩子中的最大者的编号放入no中
    //print();
    no = maxno(LChild(i), RChild(i), i);
    if (no > 0 && i!=no) {
        swap(v[i], v[no]);
        i = no;
    }
    else return i;
    }
    return i;
}


void heap::percolateUp(int i)
{
    while (i > 0 && v[i] > v[parent(i)]) {
            swap(v[i], v[parent(i)]);
            i = parent(i);
    }
}

int main()
{
    int a[20] = { 1, 9, 6, 2, 7 };
    //堆排序
    heap h(a, 5);
    while (!h.empty()) {    //堆不空
        cout << h.delmax() << ends;
    }
    cout << endl;
    return 0;
}

//错误记录，开始没有考虑lchild ,rchild是否存在的情况,下滤开始也没有想清楚