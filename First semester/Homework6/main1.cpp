#include <iostream>

using namespace std;
/*Matrix17. Дана матрица размера M × N и целое число K (1 ≤ K ≤ M).
Найти сумму и произведение элементов K-й строки данной матрицы.*/
void Input_Matrix(int M,int N,int**Matrix)
{
    for(int i(0);i<M;i++)
    {
        for(int j(0);j<N;j++)
            cin>>Matrix[i][j];
    }
}
void Sum_and_Product_of_K(int K,int N,int**Matrix)
{
    int Sum=0,Product=1;
    for(int j(0);j<N;j++)
    {
        Sum+=Matrix[K][j];
        Product*=Matrix[K][j];
    }
    cout<<Sum<<" "<<Product;
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
bool Wrong_Input(int K,int M)
{
    if (K<0 || K>=M)
        return true;
    else return false;
}
int main()
{
    int M,N,K;
    cin>>M>>N;
    int**Matrix=new int*[M];
      for(int i(0);i<M;i++)
        Matrix[i]=new int[N];
    Input_Matrix(M,N,Matrix);
    Output_Matrix(M,N,Matrix);
    do
    {
      cout<<"input K [0,"<<M<<")"<<" ";
      cin>>K;
    }
    while(Wrong_Input(K,M));
    Sum_and_Product_of_K(K,N,Matrix);
    for(int i(0);i<M;i++)
        delete Matrix[i];
     delete Matrix;
    return 0;
}
