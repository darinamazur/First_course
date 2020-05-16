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
  char now[2 * SIZE];                 //�����, � ���� �������� ����� (��������)
  char result[2 * SIZE] = "";          //���������
  char odd[2 * SIZE] = "";              //����� � ���������� ������
  int width;
  if (my == NULL) perror("������ �������� �����");
  else
  {
    cout << "������� �������� ������ ������ : ";
    cin >> width;
    while (!feof(my))
    {
      if (fgets(now, SIZE, my) != NULL)
      {
        if (now[strlen(now) - 1] == '\n') now[strlen(now) - 1] = ' ';
        strcpy(result, odd); // � ��������� ������� �����
        strcpy(result + strlen(odd), now);   // ����� ������� ������� �� �����
        strcpy(now, result); // � �� ����� ������� ����� �� ������ � �������� �����
        int len;
        while ((len = strlen(now)) > width)
        {
          strcpy(result, now);
          result[width] = 0;    // ������� �� �����
          int i = width;
          while ((result[i] != ' ') && (i > 0)) i--; // ������� ������ ����� � ����
          result[i] = 0;
          int cutLen = strlen(result) + 1;   // �������, � ��� ��������� �����
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
  int len = i;                                  //������� �����
  int need = (size - len + count) / (count + 1);// �������� ����� � ����� ������ ������, �� ���� ���� �����, �� �� ������ ����� �� ����
  int addition = (size - len + count) % (count + 1);
  int space = size - len + count;// �������� ������� ������
  i = 0;
  int j = 0;
  char* buffer = new char[size + 1];// +1, ��� ������� ���� ����
  for (int k = 0; k<need + addition; k++,j++) buffer[j] = ' ';
  while (str[i])
  {
    if (str[i] != ' ')buffer[j++] = str[i];
    else for (int k = 0; k<need; k++,j++) buffer[j] = ' ';
    i++;
  }
  buffer[j] = 0;
  strcpy(str, buffer); // ������, ��� �� ���������, ����������
  delete buffer;
  return str;
}
