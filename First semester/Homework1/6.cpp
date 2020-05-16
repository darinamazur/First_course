#include <iostream>

using namespace std;

int main()
{
    int a,b,c,s,n;
    cin >>a>>b>>c;
    if (!((a>c)&&(b>c)))
        cout << "error";
    else
    {
        n=(a/c)*(b/c);
        s=(a*b)-(n*c*c);
        cout << n << endl <<s;
    }

    return 0;
}
