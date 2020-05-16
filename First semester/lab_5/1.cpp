#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include "stack"
#include <queue>
#include <cctype>

using namespace std;

const int SIZE = 50;   // ������������ ����� ��������� �����

int prior(char a);
queue<char> polish(char s[]);     //����� ���������
float result(queue<char> x);     // �������� ���������

int main()
{
	char *String = new char[SIZE];
	cin.getline(String, SIZE);
	cout << result(polish(String)) << endl;
	return 0;
}

int prior(char a) //������������ ��������� ��������
{
	switch (a)
	{
    case '^':
        return 4;
	case '*':
	case '/':
		return 3;

	case '-':
	case '+':
		return 2;

	case '(':
		return 1;
	}
}

queue<char> polish (char*s)      //�����
{
    const int zero=48;
	queue<char> pol;
	stack <char> symbol;
	for (int i(0); i < strlen(s); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
        {
			int help = s[i]-zero; i++;
			while (s[i] >= '0' && s[i] <= '9' && i<strlen(s))
			{                                                       //�������� � ����� ������ ������
				help = help*10+ s[i]-zero;                           // �������� �����/�����
				i++;
			}
			i--;                                                     //������� �� ������ � �����, �� ��� �� �����
			pol.push(help);                                         //�������� �����/����� � �����
		}
		else                                                            //���� �� �������� �� �����/�����
		{
			if (s[i] == '(') symbol.push(s[i]);                         //���� ���������� ����� - �������� �� � ����
			else {
				if (s[i] == ')')                                        //���� ���������� �����, ���������� �� �������� � �����
				{
					while (symbol.top() != '(')
					{
						pol.push(symbol.top());
						symbol.pop();
					}
					symbol.pop();
				}
				else{
					if (symbol.empty() || (prior(symbol.top()) < prior(s[i]))) symbol.push(s[i]);
					else
					{
						while (!symbol.empty() && prior(symbol.top()) >= prior(s[i]))
						{
							pol.push(symbol.top());
							symbol.pop();
						}
						symbol.push(s[i]);
					}
				}
			}
		}
	}
	while (!symbol.empty())
	{
		pol.push(symbol.top());
		symbol.pop();
	}
	return pol;
}

float result(queue<char> x)
{
	stack<float> odd;
	while (!x.empty())
	{
		char s = x.front(); //������ ������ ������� �����(������)
		switch (s){
			case '+': {float a, b;
				a = odd.top();
				odd.pop();
				b = odd.top();//first
				odd.pop(); odd.push(a + b ); break; }
			case '-': {float a, b;
				a = odd.top();
				odd.pop();
				b = odd.top();//first
				odd.pop(); odd.push(b - a ); break; }
			case '*': {float a, b;
				a = odd.top();
				odd.pop();
				b = odd.top();//first
				odd.pop(); odd.push(a*b); break; }
			case '/': {float a, b;
				a = odd.top();
				odd.pop();
				b = odd.top();//first
				odd.pop(); odd.push(b/a); break; }
			case '^': {float a, b;
				a = odd.top();
				odd.pop();
				b = odd.top();//first
				odd.pop(); odd.push(pow(b , a )); break; }
			default:{odd.push(s); }

		}
		x.pop();
	}
	return odd.top();
}
