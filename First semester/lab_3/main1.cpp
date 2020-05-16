#include <iostream>
#include <cmath>
//метод касательных
using namespace std;

const double eps = 0.0001;
double f(double x) {
	return x*x*x + 4*x - 6;
}

double df(double x) {
	return 3 * x*x + 4;
}

double ddf(double x) {
	return 6*x;
}


double solve(double (*f) (double) , double (*df) (double), double x0)
 {
	double x1 = x0 - f(x0) / df(x0);
	while (abs(x1 - x0) > eps)
    {
		x0 = x1;
		x1 = x1 - f(x1) / df(x1);
	}
	return x1;
}

int main()
{
    double area;
    cin>>area;
	double result= solve(f, df, area);
	cout << result << endl;
	return 0;
}


