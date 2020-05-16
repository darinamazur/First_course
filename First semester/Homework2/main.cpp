#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Ukr");
    char a;
    cin>>a;
    if (((int)a)>=48 && ((int)a)<=57 )
        cout<<"Це цифра";
    if ((((int)a)>=65 && ((int)a)<=90) || (((int)a)>=97 && ((int)a)<=122))
        cout<<"Це буква";
    return 0;
}
