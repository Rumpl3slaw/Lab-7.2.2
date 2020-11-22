#include <iostream>
#include <iomanip>

using namespace std;

void Create(int** a, const int n, const int k, const int Low, const int High,int i);
void Print(int** a, const int n, const int k,int i,int j);
int SearchMin(int** a, const int n, const int  k);
void Print1(int* a, const int n,int i,int j);

int main()
{
	srand((unsigned)time(NULL));

	int n;
	cout << "Kil`kist` ryadkiv=";
	cin >> n;
	cout << endl;
	int k;
	cout << "Kil`kist` stovptsiv=";
	cin >> k;
	int** a = new int* [n];
	for (int i = 0;i < n;i++)
		a[i] = new int[k];

	int Low = 3;
	int High = 47;
	Create(a, n, k, Low, High,0);
	cout << "Masyv:" << endl;
	Print(a, n, k,0,0);

	int min = SearchMin(a, n, k);
	//cout << "=";
	return 0;

}
void Create(int** a, const int n, const int k, const int Low, const int High,int i)
{
	Create(a, n, k, Low, High, 0);
	if (i < n - 1)
		Create(a, n, k, Low, High, i + 1);
}
void Print(int** a, const int n, const int k,int i,int j)
{
	cout << setw(4) << a[i][j];
	if (i < n - 1 && j < k - 1)
		Print(a, n, k, i + 1, j + 1);
	else;
}
int SearchMin(int** a, const int n, const int k)
{
	int* Min = new int[n];
	for (int i = 0;i < n;i++)
	{
		Min[i] = a[i][0];
		for (int j = 1;j < k;j++)
			if (a[i][j] < Min[i])
				Min[i] = a[i][j];
	}
	cout << "Novuy masyv:" << endl;
	Print1(Min, n,0,0);

	int S = 0;
	for (int i = 0;i < n;i++)
		S += Min[i];
	cout << "Suma elementiv novogo masyvu=" << S;
	return 0;
}
void Print1(int* a, const int n,int i)
{
	cout << setw(5) << a[i];
	if (i < n - 1)
		Print1(a, n, i + 1);
	else;
}
