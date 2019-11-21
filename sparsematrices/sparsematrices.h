#pragma once
#include <fstream>
#include <cstdlib>
const int maxsize = 100;	//�˴����������Ԫ������Ԫ��������Ŀ
constexpr auto roww = 50;

//һ����Ԫ��
template <typename T>
struct elements
{
	int row;	//����Լ��������±��0��ʼ
	int col;
	T e;
};

//��Ԫ���
template <typename T>
class sparsematrices
{
private:
	int row;	//������
	int col;	//������
	int len;	//����Ԫ����
public:
//���캯��
	sparsematrices(const char*file); //������ʼ�����������ݵĲ���
	sparsematrices() { row = 0; col = 0; len = 0; e = new elements<int>[maxsize];}
	//~sparsematrices() { delete[] e; }	//����������ʳ�ͻ��Ϊe���ǵ��������飬����һ��struct,��������ôɾ��
//�йز���
	elements<int>* e;
	int getrow() { return row; };
	int getcol() { return col; };
	int getlen() { return len; };
	void displaytable();
	void display();
	void transposematrix();	//�����ת��
	void sorting();	//��������ľ���
	void sortingcol();	//��������ľ���
	void addmatrix(sparsematrices matrix2);
	void submatrix(sparsematrices matrix2);
	void mulmatrix(sparsematrices matrix1, sparsematrices& matrixnew);
	int find(int i);//Ѱ�ҵ�i�е�Ԫ���Ƿ���ڣ������ڷ���-1�����ڷ�����lenΪ���е��±�
};

template<typename T>
sparsematrices<T>::sparsematrices(const char * file)
{
	//��ȡ����
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
	//��ȡ����
	col = 0;
	ifstream f2;
	f2.open(file, ios::_Nocreate);
	while (f2.peek() != '\n') {
		f2.get();
		col++;
	}
	col = (col + 1) / 2;
	f2.close();
	//��ʼ���й�����
	e = new elements<int>[maxsize];
	len = 0;
	ifstream f3;
	int count = 0;
	f3.open(file, ios::in);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col;) {			//��ʼ�����j��ѭ���������ô���
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
	//����������飬1.���У��н��� 2.������������
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
				e[j] = *temp;	//�����漰ǳ���ƺ���Ƶ�����
			}
	}
	delete temp;
}

template<typename T>
void sparsematrices<T>::addmatrix(sparsematrices matrix2)	//�����ǰ���˳��洢���ʼӷ�Ч�ʿ�������
{
	if (row != matrix2.row || col != matrix2.col) {
		cout << "������У��в��Ϸ�" << endl;
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
		cout << "������У��в��Ϸ�" << endl;
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
		cout << "��������в��Ϸ�" << endl;
		exit(0);
	}
	matrixnew.row = row;
	matrixnew.col = matrix1.col;
	matrixnew.len = 0;

	//����reference���,�����ݲ�ֵ�ܴ��ǣ�referencethis����ƺ�ռ���˺ܴ�Ŀռ�,��Ҳ�����Ǹ���n�ĸ��Ӷȣ����Ի��Ǽ�����һ�����Ӷ�
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

	//�������ϡ�����
	int num = 0;
	int m = 0;
	int ctemp[roww] = {0};
	if (len * matrix1.len != 0) {
		for (int i = 0; i < row; i++)	//����this matrix�е�ÿһ������
		{
			if (find(i) == -1) continue;	//������ֵ�һ�������i��û�з�0Ԫ�أ���һѭ��
			memset(ctemp, 0, sizeof(ctemp));	//��������
			m = find(i);	//m��row��ʼ��λ��
			//����matrixnew��i�еĻ�������ctemp[]��
			do {
				for (int k = 0; k < matrix1.getlen(); k++) {
					if (matrix1.e[k].row == e[m].col)
					{
						ctemp[matrix1.e[k].col] += matrix1.e[k].e * e[m].e;
						//cout << "����" << matrix1.e[k].col << ends;
						//cout << ctemp[matrix1.e[k].col] << endl;
					}
				}
				m++;
			} while (reference[m] == reference[m - 1]);
		//��ctemp[]�еķ���Ԫѹ���洢
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
				e[j] = *temp;	//�����漰ǳ���ƺ���Ƶ�����
			}
	}
	delete temp;
}

//Ӧ��ֻ��reference����������

template<typename T> ////Ѱ�ҵ�i�е�Ԫ���Ƿ���ڣ������ڷ���-1�����ڷ�����lenΪ���е��±�
int sparsematrices<T>::find(int t) {
	for (int i = 0; i < len; i++) {
		if (e[i].row == t)
			//cout << i;
			return i;
	}
	return -1;
}