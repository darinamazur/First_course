#include <iostream>

using namespace std;
/*Series4. Дано целое число N и набор из N вещественных чисел. Вывести сумму
и произведение чисел из данного набора.*/

int main()
{
    int n;
    cin>>n;
    float a;
    int sum=0; int comp=1;
        for (int i=0;i<n;i++)
        {
            cin>>a;
            sum+=a;
            comp*=a;
        }
    cout<<"sum="<<sum<<" "<<"comp="<<comp;

    return 0;
}
