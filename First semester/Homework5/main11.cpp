#include <iostream>
#include <cmath>

using namespace std;
/*Array131. Дано множество A из N точек на плоскости и точка B (точки заданы своими координатами x, y).
Найти точку из множества A, наиболее близ-кую к точке B.
 Расстояние R между точками с координатами (x1, y1) и (x2, y2)...(формула)*/
//Для координат использовать 2 разных массива
    float lline (float x1, float y1, float x2, float y2)
    {
        float l;
        l=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
        return l;
    }
    void input(int n, float*a)
    {
        for(int i(0);i<n;i++)
            cin>>a[i];
    }
    void minmax(float*a,float*b,int n,float bx,float by,float axmin,float aymin,float lmin)
    {
    lmin=lline(a[0],b[0],bx,by);
    axmin=a[0];aymin=b[0];
   for (int i(1);i<n;i++)
  {
        if (lline(a[i],b[i],bx,by)<lmin)
        {
            lmin=lline(a[i],b[i],bx,by);
            axmin=a[i]; aymin=b[i];
        }
  }
   cout<<axmin<<" "<<aymin;
    }
int main()
{
  int n;cin>>n;
  float ax[10],ay[10],bx,by,lmin,axmin,aymin;
  cin>>bx>>by;
    cout<<endl;
  input(n,&ax[n]);
    cout<<endl;
  input(n,&ay[n]);
     cout<<endl;
    minmax(&ax[n],&ay[n],n,bx,by,axmin,aymin,lmin);
    return 0;
}
