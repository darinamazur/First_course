#include <iostream>
#include <cmath>
#include <clocale>


using namespace std;

double definite_integral(double(*functionPointer)(double), double from, double to, int n, double stringency = 0.00001)
{
	double res(0);
	double step = (to - from) / n;
	for (; from < to; from += step)
	res += ((functionPointer(from) + functionPointer(from + step)) / 2) * step; // метод трапеции
	return res;

}

double integral(double (*functionPointer)(double), double from, double to, int n, double stringency = 0.00001)
{
	double sum1 = 0;
	double sum2 = 0;
	sum1 = definite_integral(functionPointer, from, to, n);
	n*=2;
	sum2 = definite_integral(functionPointer, from, to, n);
		while (abs(sum1 - sum2) > stringency)
		{
		    n*=2;
			sum1 = sum2;
			sum2 = definite_integral(functionPointer, from, to, n);
		}
	return sum2;
}

    double funct(double x)
	{
		return x/(2*x*x-1);
	}

	double my_sin(double x)
	{
		return sin(x);
	}

	double my_cos(double x)
	{
		return cos(x);
	}

	int main()
	{
		setlocale(0, "Russian");
		int n = 1000;
		double to, from;
		cin>>to>>from;
		cout <<"Значение интеграла : " << integral(funct, to, from, n) << endl;
		cout <<"Значение интеграла : " << integral(my_sin, to, from, n) << endl;
		cout <<"Значение интеграла : " << integral(my_cos, to, from, n) << endl;
		return 0;
	}
