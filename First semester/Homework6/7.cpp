#include <iostream>

using namespace std;
/*Matrix79. Дана матрица размера M × N.
Упорядочить ее столбцы так, чтобы их максимальные элементы образовывали возрастающую последователь-ность.*/
void Input_Matrix(int M,int N,int**Matrix)
{
    for(int i(0);i<M;i++)
    {
        for(int j(0);j<N;j++)
            cin>>Matrix[i][j];
    }
}
void Output_Matrix(int M,int N,int**Matrix)
{
    for(int i(0);i<M;i++)
    {
        for(int j(0);j<N;j++)
            cout<<Matrix[i][j]<<" ";
        cout<<endl;
    }
}
int Max_element_of_column(int j,int M,int**Matrix)
{
    int Max=Matrix[0][j];
        for(int i(1);i<M;i++)
        {
            if(Matrix[i][j]>Max)
                Max=Matrix[i][j];
        }
    return Max;
}
void Swap (int*x,int*y)
{
    int t=*x; *x=*y; *y=t;
}
void Swap_columns(int M,int N,int**Matrix)
{
    int N_temp=N;
    while(N_temp>0)
    {
    for(int j(0);j<N;j++)
    {
        if(j+1<N && j>=0)
        {
        if(Max_element_of_column(j,M,Matrix)>Max_element_of_column(j+1,M,Matrix))
        for(int i(0);i<M;i++)
            Swap(&Matrix[i][j],&Matrix[i][j+1]);
        }
    }
     N_temp--;
    }
}
int main()
{
    int M,N;
    cin>>M>>N;
    int**Matrix=new int*[M];
      for(int i(0);i<M;i++)
        Matrix[i]=new int[N];
     Input_Matrix(M,N,Matrix);
     Swap_columns(M,N,Matrix);
     Output_Matrix(M,N,Matrix);
    for(int i(0);i<M;i++)
        delete Matrix[i];
     delete Matrix;
    return 0;
}
