#include<iostream>
#include<cmath>
#include<clocale>

using namespace std;

//���� ���� � ����� �� ������, ��������� ����� ����, ���������� ������ �� ������� �����. ��������� ������ ����� ��������, ���� ���� �


int main()
{
    setlocale(LC_CTYPE, "Rus");
	double a, b, r, A, B, C;
	double e = 0.001;
	double x, y,x1,y1;
	cout << "������� ���������� ����� ����������\n";
	cin >> a >> b;
	cout << "������� ������ ����������(r>0)\n";
	cin >> r;
	cout << "������� �������� ������������ ��������� ������ Ax+By+C=0 \n";
	cin >> A >> B >> C;
	double d;
	d = abs(A*a + B*b + C) / sqrt(A*A + B*B);
	if (d > r)
		cout << "���������� � ������ �� ������������\n";
    else
	if ((d-r)<e)
	{
		x = (a*B*B - A*B*b - A*C) / (A*A + B*B);
		y = (A*A*b - a*A*B - C*B) / (A*A + B*B);
		cout<< "������ �������� ����������� � ����� (x,y) = ";
		cout<< '(' << x << ',' << y << ')' << endl;
	}
	else
	{
		double temp = abs(B)*sqrt((B*B)*(a*a - b*b + r*r) - C*C + A*A*r*r - 2 * (a*A*b*B - a*A*C - b*B*C));
		x = (-A*B*b - A*C + a*B*B + temp) / (A*A + B*B);
		y = (-A*x - C) / B;
		x1 =(-A*B*b - A*C + a*B*B -temp) / (A*A + B*B);
		y1 = (-A*x1 - C) / B;
		cout<< "���������� � ������ ������������ � 2 ������ � ������������: (x1,y1) = ";
		cout<< '(' << x << ',' << y << ')' << endl;
		cout<< "(x2,y2) = ";
		cout<< '(' << x1 << ',' << y1 << ')' << endl;

	}
return 0;
}

