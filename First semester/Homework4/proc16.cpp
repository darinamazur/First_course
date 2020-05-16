#include <iostream>

using namespace std;
/*Proc16. Описать функцию Sign(X) целого типа, возвращающую для веществен-
ного числа X следующие значения:
–1, если X < 0; 0, если X = 0; 1, если X > 0.
С помощью этой функции найти значение выражения Sign(A) + Sign(B) для
данных вещественных чисел A и B.*/
    int sign(float x)
    {
        if(x>0) return 1;
        if (x==0) return 0;
        else return -1;
    }

int main()
{
    float a,b;
    cin >>a>>b;
    cout<<(sign(a)+sign(b));

    return 0;
}
