#include <iostream>
#include <cmath>

using namespace std;
//вивести число 2 в степені n, n<1000

int main()
{
    int n; cin>>n;
    int m; m=(n*log10(2))+1;
    int mas[m];
    int const k=2;

            mas[0]=1;
            for(int i=1;i<m;i++)
                mas[i]=0;
            for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                mas[j]*=k;
            }
            for (int v=0;v<m;v++)
            {
            if((mas[v]/10)!=0)
                {
                    mas[v+1]+=(mas[v]/10);
                    mas[v]%=10;
                }
            }
        }
    for (int i=m-1;i>=0;i--)
        cout<<mas[i];
    return 0;
}
