#include <iostream>

using namespace std;
/*For16°. Дано вещественное число A и целое число N (> 0). Используя один
цикл, вывести все целые степени числа A от 1 до N.*/

int main()
{
    int a,n,res=1;
    cin>>a>>n;
        for (int i=0;i<n;i++)
            res*=a;
        cout<<res;
    return 0;
}
