#include <iostream>

using namespace std;
/*Matrix29. Дана матрица размера M × N.
В каждой ее строке найти количество элементов, меньших среднего арифметического всех элементов этой строки.*/
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
int Average_of_line(int*i,int N,int**Matrix)
{
    int Sum=0,Average;
        for (int j(0);j<N;j++)
        Sum+=Matrix[*i][j];
        Average=Sum/N;
    return Average;
}
int Amount_Less_than_Average(int*i,int N,int**Matrix)
{
    int Amount=0;
    for (int j(0);j<N;j++)
        if(Matrix[*i][j]<Average_of_line(i,N,Matrix))
            Amount++;
    return Amount;
}
void Output_Amount(int M,int N,int**Matrix)
{
    for(int i(0);i<M;i++)
    cout<<Amount_Less_than_Average(&i,N,Matrix)<<" ";
}
int main()
{
    int M,N;
    cin>>M>>N;
    int**Matrix=new int*[M];
      for(int i(0);i<M;i++)
        Matrix[i]=new int[N];
    Input_Matrix(M,N,Matrix);
    Output_Matrix(M,N,Matrix);
    Output_Amount(M,N,Matrix);
    for(int i(0);i<M;i++)
        delete Matrix[i];
     delete Matrix;
    return 0;
}
