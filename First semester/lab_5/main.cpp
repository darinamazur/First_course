#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>

using namespace std;

const int SIZE = 50;   // максимальний розмір уведеного рядка
struct Stack
{
    char data[SIZE];
    int top=-1;
    char peek () {return data[top];}
    void push (char ch) {data[++top]=ch;}
    char pop(){return data[top--];}
};

int prior(char a);
void polish(char*s);     //черга виконання
float Result(Stack x);     // виводимо результат

int main()
{
	char *String = new char[SIZE];
	cin.getline(String, SIZE);
	cout << Result(polish(String)) << endl;
	return 0;
}

int prior(char a) //розставляємо пріоритети операцій
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

void polish (char*s)      //черга
{
    const int zero=48;
	Stack pol;
	Stack symbol;
	for (int i(0); i < strlen(s); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
        {
			int help = s[i]-zero; i++;
			while (s[i] >= '0' && s[i] <= '9' && i<strlen(s))
			{                                                       //записуємо в чергу перший символ
				help = help*10+ s[i]-zero;                           // перевірка цифра/число
				i++;
			}
			i--;                                                     //оскільки ми вийшли з циклу, то далі не цифра
			pol.push(help);                                         //записали цифру/число в чергу
		}
		else                                                            //якщо ми отримали не цифру/число
		{
			if (s[i] == '(') symbol.push(s[i]);                         //маємо відкриваючу дужку - заносимо її в стек
			else {
				if (s[i] == ')')                                        //маємо закриваючу дужку, переносимо всі елементи в чергу
				{
					while (symbol.top() != '(')
					{
						pol.push(symbol.top());
						symbol.pop();
					}
					symbol.pop();
				}
				else{
					if ((prior(symbol.top()) < prior(s[i]))) symbol.push(s[i]);
					else
					{
						while (prior(symbol.top()) >= prior(s[i]))
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
	while (symbol)
	{
		pol.push(symbol.top());
		symbol.pop();
	}
	return pol;
}

float Result(Stack x)
{
	Stack odd;
	while (x)
	{
		char s = x.peek(); //беремо перший елемент черги(верхній)
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
