#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
#define SIZE 100

char* resize(char* str, int size);

int main()
{
  setlocale(0, "Russian");
  FILE *my = fopen("file.txt", "r");
  char now[2 * SIZE];                 //рядок, з яким працюємо зараз (зчитаний)
  char result[2 * SIZE] = "";          //результат
  char odd[2 * SIZE] = "";              //зайве з попередньої строки
  int width;
  if (my == NULL) perror("Ошибка открытия файла");
  else
  {
    cout << "Введите желаемую ширину текста : ";
    cin >> width;
    while (!feof(my))
    {
      if (fgets(now, SIZE, my) != NULL)
      {
        if (now[strlen(now) - 1] == '\n') now[strlen(now) - 1] = ' ';
        strcpy(result, odd); // в результат копіюємо зайве
        strcpy(result + strlen(odd), now);   // пісяля зайвого ставимо що тепер
        strcpy(now, result); // в що тепер копіюємо рядок із зайвим і теперішній рядок
        int len;
        while ((len = strlen(now)) > width)
        {
          strcpy(result, now);
          result[width] = 0;    // обрізали по ширині
          int i = width;
          while ((result[i] != ' ') && (i > 0)) i--; // знайшли перший пробіл з кінця
          result[i] = 0;
          int cutLen = strlen(result) + 1;   // позиція, з якої почнеться зайве
          cout << resize(result, width) << endl;
          strcpy(now, now + cutLen);
        }
        strcpy(odd, now);
      }
    }
    cout << resize(odd,width) << endl;
  }
  fclose(my);
  return 0;
}

char* resize(char* str, int size)
{
  int count = 0;
  int i = 0;
  while (str[i])
  {
    if (str[i] == ' ')count++;;
    i++;
  }
  int len = i;                                  //довжина рядка
  int need = (size - len + count) / (count + 1);// вставимо пробіл і перед першим словом, бо якщо одне слово, то ми будемо ділити на нуль
  int addition = (size - len + count) % (count + 1);
  int space = size - len + count;// загальна кількість пробілів
  i = 0;
  int j = 0;
  char* buffer = new char[size + 1];// +1, щоб обрізати його потім
  for (int k = 0; k<need + addition; k++,j++) buffer[j] = ' ';
  while (str[i])
  {
    if (str[i] != ' ')buffer[j++] = str[i];
    else for (int k = 0; k<need; k++,j++) buffer[j] = ' ';
    i++;
  }
  buffer[j] = 0;
  strcpy(str, buffer); // строку, яку ми розширили, обновляємо
  delete buffer;
  return str;
}
