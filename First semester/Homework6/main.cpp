#include <iostream>

using namespace std;
/*Matrix5. Даны целые положительные числа M, N, число D и набор из M чисел. Сформировать матрицу размера M × N,
у которой первый столбец совпада-ет с исходным набором чисел, а элементы каждого следующего столбца равны сумме соответствующего
элемента предыдущего столбца и числа D (в результате каждая строка матрицы будет содержать элементы арифме-тической прогрессии).*/

void Input_Matrix(int M,int N,int**Matrix)
{
    for(int i(0);i<M;i++)
    {
        for(int j(0);j<N;j++)
            cin>>Matrix[i][j];
    }
}
void Input_the_First_Column(int M,int**Matrix)
{
    int j=0;
    for(int i(0);i<M;i++)
        cin>>Matrix[i][j];
}
void Creating_Arithmetic_Progression(int M,int N,int D,int**Matrix)
{
    Input_the_First_Column(M,Matrix);
    for(int i(0);i<M;i++)
        for(int j(1);j<N;j++)
        Matrix[i][j]=Matrix[i][j-1]+D;
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
int main()
{
    int M,N,D;
    cin>>M>>N>>D;
    int**Matrix=new int*[M];
      for(int i(0);i<M;i++)
        Matrix[i]=new int[N]; //объявление матрицы
    Creating_Arithmetic_Progression(M,N,D,Matrix);
    Output_Matrix(M,N,Matrix);
     for(int i(0);i<M;i++)
        delete Matrix[i];
     delete Matrix;
    return 0;
}
