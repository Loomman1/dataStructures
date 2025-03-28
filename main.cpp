#include <iostream>
#include <sstream>

//������������ ���:
//�� ���������� ���������� ��� ���������� ���������� �������.
//������ ����� ��������������� ����������, ������������� ����������� �������.
class structura {
private:


public:

};

//�������
//����� � ������� �������� ������������ �� ��������.
void generateMatr(int min, int max, double **a, int N, int M) {
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			a[i][j] = rand() % (max - min + 1) + min;
		}
	}
}
void printMatr(double** a, int N, int M) {
	std::cout << "\n������� "<<N<<" x "<<M<<":\n";
	for (int i = 0; i < N; ++i, std::cout<<std::endl)
		for (int j = 0; j < M; ++j)
		{
			std::cout << a[i][j] << "\t";
		}

}
//����� ������� ������������ � �������
double findSecondMin(double **a, int N, int M)
{
	double min_val = DBL_MAX, min_sec= DBL_MAX;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (a[i][j] < min_val)
			{
				min_val = a[i][j];
			}
			if (a[i][j]<min_sec && a[i][j]>min_val)
			{
				min_sec = a[i][j];
			}
		}
	}
	if (min_sec == DBL_MAX)
		std::cout << "��� �������� ������� ���������\n";
	else
		std::cout << "\nmin sec = " << min_sec<<"\n";
	return min_sec;
}
//����� ������� ����������������
struct freq {
	double number;
	int freq;
};
double findFirstNonRepeating(double** a, int N, int M) {
	freq* fr=new freq[N*M];
	// ������� ������� ������� �����
	int nUniq=0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int fl = 0;
			for (int k = 0; k < nUniq; k++)
			{
				if (a[i][j] == fr[k].number)
				{
					fr[k].freq++; fl = 1;
					break;
				}
			}
			if (fl == 0)
			{
				fr[nUniq].number=a[i][j];
				fr[nUniq].freq = 1;
				nUniq++;
			}
		}
	}
	//�����
	std::cout << "\n�������� : �������\n";
	for (int j = 0; j < nUniq; j++)
	{
		std::cout << fr[j].number << " : " << fr[j].freq << "\n";
	}

	// ��������� �����������: ����� ������� ���������������� �����
	double nonRep = DBL_MAX;
	for (int j = 0; j < nUniq; j++)
	{
		if (fr[j].freq == 1)
		{
			std::cout << "������ ��������������� ����� = " << nonRep << "\n";
			nonRep = fr[j].number;
		}
	}
	if (nonRep == DBL_MAX)
		std::cout << "\n��������������� ����� �� ���� �������\n";


	return nonRep;
}


//���� (���������� ����� �������)
struct element {
	int intVal;
	double dblVal;
	element() {
		intVal = -1;
		dblVal = -1;
	}
	element(element &el){
		intVal = el.intVal;
		dblVal = el.dblVal;
	}
	element(int p1, double p2) {
		intVal = p1;
		dblVal = p2;
	}
	~element() {};

	void printVals() {
		std::cout << "\nint = " << intVal << " dbl = " << dblVal << "\n";
	}
};
class Steck {
private:
	element *vals;//�� ��������� - 100 ��
	const int maxSize = 10000;
	int size=100;
	int head = -1;
public:
	Steck();
	Steck(int size);
	Steck(Steck &steck);
	~Steck();

	void push(element el);//������� ��������
	element pop();//������� � ���������
	bool isEmpty();//��������: ���� �� ����
	element top();//������� ��� ��������
	double evaluatePostfix(std::string);//���������� ������������ ���������

};
Steck::Steck() {
	size = 100;
	vals = new element[size];
}
Steck::Steck(Steck& steck) {
	head = steck.head;
	size = steck.size;
	vals = new element[size];;
	for (int i = 0; i <= head; i++) {
		vals[i] = steck.vals[i];
	}
}
Steck::~Steck() {
	delete[] vals;
}
Steck::Steck(int sz) {
	if (sz > maxSize)
		sz = maxSize;
	vals = new element[sz];
	size = sz;
}
void Steck::push(element el) {
	if (head < size - 1)
	{
		head++;
		vals[head] = el;//��������� �����������/������
	}
	else {
		std::cout << "\n������������ �����\n";
	}

}

element Steck::pop() {
	if (isEmpty())
	{
		std::cerr << "\n������: ���� ����\n";
		exit(EXIT_FAILURE);
	}
	return vals[head--];
}
bool Steck::isEmpty() {
	return head == -1;
}
element Steck::top() {
	return vals[head];
}
double Steck::evaluatePostfix(std::string str) {
	std::stringstream ss(str);
	ss >> str;
	
}

int main() 
{
	//��������
	/*srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	const int N = 10, M=10;
	double **a=new double*[N];
	for (int i = 0; i < N; i++)
	{
		a[i] = new double[M];
	}

	generateMatr(-10, 10, a, N, M);
	printMatr(a, N, M);
	double min_second_val=findSecondMin(a, N, M);
	findFirstNonRepeating(a, N, M);
	for (int i = 0; i < N; i++)
		delete[] a[i];
	delete []a;*/


	//����, LIFO - ctrl+z
	element el1(1, 22.5), el2(4, 12.4), el3(5, -3.7);
	Steck st;
	st.push(el1);
	st.top().printVals();
	st.push(el2);
	st.top().printVals();
	st.push(el3);
	st.top().printVals();
	st.pop().printVals();
	st.top().printVals();
	//���������� ���������� ������������ ��������� ��� ������ �����
	std::string expression = "3 4 + 2 * 7 /";//3+4=7-> 7*2=14 ->14/7=2
	double result = st.evaluatePostfix(expression);
	return 0;
}