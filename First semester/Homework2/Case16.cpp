#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    int n;
    cin>>n;
    switch(n/10)

   {
        case 2: cout << "двадцать ";
            break;
        case 3: cout <<"тридцать ";
            break;
        case 4: cout <<"сорок ";
            break;
        case 5: cout <<"п€тдес€т ";
            break;
        case 6: cout<<"шестдес€т ";
    }
    switch (n%10)
    {
    case 1: cout << "один ";
        break;
    case 2:cout << "два ";
        break;
    case 3:cout << "три ";
        break;
    case 4:cout << "четыре ";
        break;
    case 5:cout << "п€ть ";
        break;
    case 6:cout << "шесть ";
        break;
    case 7:cout << "семь ";
        break;
    case 8:cout << "восемь ";
        break;
    case 9:cout << "дев€ть ";
    }
    switch (n%10)
    {
       case 1: cout<< "год";
        break;
       case 2:
       case 3:
       case 4:
        cout << "года";
        break;
       case 5:
       case 6:
       case 7:
       case 8:
       case 9:
        cout << "лет";
    }

    return 0;
}
/*Case16. ƒано целое число в диапазоне 20Ц69, определ€ющее возраст (в годах).
¬ывести строку-описание указанного возраста, обеспечив правильное со-
гласование числа со словом Ђгодї, например: 20 Ч Ђдвадцать летї, 32 Ч
Ђтридцать два годаї, 41 Ч Ђсорок один годї.*/
