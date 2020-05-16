#include <iostream>

using namespace std;
/*Series16∞. ƒано целое число K и набор ненулевых целых чисел; признак его за-
вершени€ Ч число 0. ¬ывести номер последнего числа в наборе, больше-
го K. ≈сли таких чисел нет, то вывести 0.*/

int main()
{
    int k;
    cin>>k;
    int a=1,numtemp=0,number=0;
        while (a!=0)
        {
            cin>>a;
            numtemp++;
            if(a>k)
            number=numtemp;
        }
    cout<<number;
    return 0;
}
