#include<iostream>
#include<cmath>
#include<clocale>

using namespace std;

//Дано коло і пряму на площині, уводиться радіус кола, координати центру та рівняння прямої. Необхідно знайти точки перетину, якщо вони є


int main()
{
    setlocale(LC_CTYPE, "Rus");
	double a, b, r, A, B, C;
	double e = 0.001;
	double x, y,x1,y1;
	cout << "Введите координаты цента окружности\n";
	cin >> a >> b;
	cout << "Введите радиус окружности(r>0)\n";
	cin >> r;
	cout << "Введите значение коэфициентов уравнения прямой Ax+By+C=0 \n";
	cin >> A >> B >> C;
	double d;
	d = abs(A*a + B*b + C) / sqrt(A*A + B*B);
	if (d > r)
		cout << "Окружность и прямая не пересекаются\n";
    else
	if ((d-r)<e)
	{
		x = (a*B*B - A*B*b - A*C) / (A*A + B*B);
		y = (A*A*b - a*A*B - C*B) / (A*A + B*B);
		cout<< "Прямая является касательной в точке (x,y) = ";
		cout<< '(' << x << ',' << y << ')' << endl;
	}
	else
	{
		double temp = abs(B)*sqrt((B*B)*(a*a - b*b + r*r) - C*C + A*A*r*r - 2 * (a*A*b*B - a*A*C - b*B*C));
		x = (-A*B*b - A*C + a*B*B + temp) / (A*A + B*B);
		y = (-A*x - C) / B;
		x1 =(-A*B*b - A*C + a*B*B -temp) / (A*A + B*B);
		y1 = (-A*x1 - C) / B;
		cout<< "Окружность и прямая пересекаются в 2 точках с координатами: (x1,y1) = ";
		cout<< '(' << x << ',' << y << ')' << endl;
		cout<< "(x2,y2) = ";
		cout<< '(' << x1 << ',' << y1 << ')' << endl;

	}
return 0;
}

