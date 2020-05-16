#include <iostream>
#include <cmath>

using namespace std;
/*Proc40. Описать функцию Exp1(x, ε) вещественного типа (параметры x, ε —
вещественные, ε > 0), находящую приближенное значение функции exp(x):
exp(x) = 1 + x + x2/(2!) + x3/(3!) + … + xn/(n!) + …
(n! = 1·2·…·n). В сумме учитывать все слагаемые, большие ε. С помощью
Exp1 найти приближенное значение экспоненты для данного x при шести
данных ε.*/

  double exp1(double x, double e)
  {
    double xi=1,ni=1,res=0,tempres=1;
    int i=0;

    while(tempres>e)
        {
        res+=tempres;
        i++;
        xi*=x;
        ni*=i;
        tempres=xi/ni;
         }
    return res;
}

int main()
{
    const int k=6;
    double x,e;
    cin>>x;
    for (int i(0);i<k;i++)
    {
        cin >>e;
        cout<<exp1(x,e);
    }
    return 0;
}
