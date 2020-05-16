#include <iostream>

using namespace std;
/*For4. Дано вещественное число — цена 1 кг конфет. Вывести стоимость 1,
2, …, 10 кг конфет.*/
int main()
{
    int n;
    cin>>n;
        for(int i=1;i<=10;i++)
            cout<<n*i<<" ";
    return 0;
}
