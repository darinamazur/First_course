#include <iostream>

using namespace std;

int main()
{
    int x,y;
    cin >> x>>y;
    cout<<((x>0 && y>0) ||(x<0 && y<0));
    return 0;
}
