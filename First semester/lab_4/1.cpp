#include <cstring>
#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;


char* getShared(char* str1, char* str2, char* shared){
  if (!(*str1)) return shared;
  char* best = new char[strlen(str1) + strlen(str2) + strlen(shared) + 1];
  strcpy(best, shared);
  best = getShared(str1 + 1, str2, best);
  int iter = 0;
  while (str2[iter])
  {
    if (str2[iter] == *str1)
    {
      char* buffer = new char[strlen(str1) + strlen(str2) + strlen(shared) + 1];
      buffer[0] = 0;
      strcpy(buffer, shared);
      buffer[strlen(buffer) + 1] = 0;
      buffer[strlen(buffer)] = *str1;
      buffer = getShared(str1 + 1, str2 + iter + 1, buffer);
      if (strlen(buffer)>strlen(best))
      {
        delete[] best;
        best = buffer;
      }
    }
    iter++;
  }
  shared = best;
  return shared;
}

int main()
{
  setlocale(0, "Russian");
  char* a = "abae";
  char* b = "baсe";
  char* sh = "";
  cout << "Наименьшее необходимое количество операций : " << ' ' << strlen(b) - 2 * strlen(getShared(a, b, sh)) + strlen(a) << endl;
}
