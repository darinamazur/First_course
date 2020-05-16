#include <iostream>

using namespace std;
/*String5. Дано целое число N (1 ≤ N ≤ 26).
Вывести N последних строчных (то есть маленьких) букв латинского алфавита в обратном порядке (начиная с буквы «z»).
 */
void Output_symbols(int N);
int main()
{
   int N;
   cin>>N;
   if(N>=1 && N<=26)
    Output_symbols(N);
   else cout<<"Error";
    return 0;
}
void Output_symbols(int N)
 {
     for(int i(122);i>(122-N);i--)
        cout<<char(i);
 }
