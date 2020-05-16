using namespace std;
#pragma warning(disable : 4996)

int flen(char* name) {
  FILE*f = fopen(name, "rb");
  if (f == NULL) {
    return -1;
  }
  fseek(f, 0, SEEK_END);
  int len= ftell(f);
  fclose(f);
  return len;

}
int main()
{char names[3][20] = { "file1.txt" ,"file2.txt" ,"file3.txt" };
  int len[3];
  for (int i = 0; i < 3; i++) {
    len[i] = flen(names[i]);
    if (len[i] == -1)
    {
      cout << "error\n";
      return 0;
    }
    cout << len[i] << endl;
  }

  int Nmax = 0, Nmin = 0;
  for (int i = 1; i < 3; i++) {
    if (len[i] > len[Nmax]) Nmax = i;
    if (len[i] < len[Nmin]) Nmin = i;
  }
  cout << Nmax << " " << Nmin << endl;

  FILE*fw = fopen(names[Nmax], "wb");
  FILE*fr = fopen(names[Nmin], "rb");

  char*  buf = new char[len[Nmin]+1];
  fread(buf, sizeof(char), len[Nmin], fr);
  fwrite(buf, sizeof(char), len[Nmin], fw);
  fclose(fr);
  fclose(fw);
}
