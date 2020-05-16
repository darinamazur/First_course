#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    switch (n)
    {
         case 1: cout << 31; break;
        case 2: cout << 28; break;
        case 3: cout << 31; break;
        case 4: cout << 30; break;
        case 5: cout << 31; break;
        case 6: cout << 30; break;
        case 7: cout << 31; break;
        case 8: cout << 31; break;
        case 9: cout << 30; break;
        case 10: cout << 31; break;
        case 11: cout << 30; break;
        case 12: cout << 31; break;
        default: cout << "this mounth is not real";
    }

    return 0;
}
/*Case4∞. ƒан номер мес€ца Ч целое число в диапазоне 1Ц12 (1 Ч €нварь, 2 Ч
февраль и т. д.). ќпределить количество дней в этом мес€це дл€ невисо-
косного года.*/
