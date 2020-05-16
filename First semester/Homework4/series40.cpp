#include <iostream>
#include <clocale>

using namespace std;
/*Series40. ƒано целое число K, а также K наборов ненулевых целых чисел.  а-
ждый набор содержит не менее трех элементов, признаком его завершени€
€вл€етс€ число 0. ƒл€ каждого набора выполнить следующее действие: ес-
ли набор €вл€етс€ пилообразным (см. задание Series23), то вывести коли-
чество его элементов; в противном случае вывести номер первого элемен-
та, который не €вл€етс€ зубцом.*/

int main()
{
    int k;
    cin>>k;
    for (int i(0);i<k;i++)
    {
    int a1,a2,a=1,counter=2;
    bool b=true;
    cin>>a1>>a2;
    while(a!=0)
    {
        cin>>a; counter++;
        if (((a1<a2)&&(a<a2))||((a1>a2)&&(a>a2)))
        {
            a1=a2;
            a2=a;
        }
        else
        {
            b=false;cout<<a<<endl; break;

        }
    }

    if (b) cout<<(counter-1)<<endl;
        }
    return 0;
}
