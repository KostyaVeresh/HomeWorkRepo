#include <iostream>

using namespace std;

void decToBin(int num, int *length, short mas[])
{
	while (num > 0)
	{
		++*length;
		mas[*length] = num % 2;
		num = num / 2;
	}
}

void printBinNum(short mas[], int length)
{
	for (int i = length; i >= 0; --i)
	{
		cout << mas[i];
	}
	cout << endl;
}

int binToDec(int length, short mas[])
{
	int num = mas[0];
	int deg = 2;
	for (int i = 1; i <= length; ++i)
	{
		num += mas[i] * deg;
		deg = deg * 2;
	}
	return num;
}

int main()
{
	setlocale(LC_ALL,"Russian");
	int const length = 100;
	int a = 0;
	int b = 0;
	short binA[length] = {0};
	short binB[length] = {0};
	int lengthA = -1;
	int lengthB = -1;
	cout << "Введите 2 числа в десятичной системе:" << endl;
	cin >> a >> b;
	decToBin(a, &lengthA, binA);
	decToBin(b, &lengthB, binB);
	cout << "В двоичной системе:" << endl;
	printBinNum(binA, lengthA);
	printBinNum(binB, lengthB);
	cout << "Сумма чисел в двоичной записи: ";
	int tmp = 0;
	if (lengthA > lengthB)
		tmp = lengthA;
	else
		tmp = lengthB;
	for (int i = 0; i <= tmp; ++i)
	{
		binA[i] = binA[i] + binB[i];
	}
	for (int i = 0; i <= tmp; ++i)
	{
		if (binA[i] == 2)
		{
			binA[i] = 0;
			++binA[i + 1]; 
		}
		if (binA[i] == 3)
		{
			binA[i] = 1;
			++binA[i + 1];
		}
	}

	if (binA[tmp + 1] != 0)
		++tmp;
	printBinNum(binA, tmp);
	a = binToDec(tmp, binA);
	cout << "Сумма чисел в десятичной записи: " << a;
	scanf("%*s");
	return 0;
}