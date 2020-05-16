#include <iostream>
#include <string>
#include <sstream>

using namespace std;
struct TRAIN {
 string name;
 int trainNumber;
 string departureTime;
} train[8];
void printTrain(TRAIN one_train);



int main()
{
 string mystr;
 for (int i = 0; i < 3; i++) {
  cout << "Enter destination name ";
  getline(cin, train[i].name);
  cout << "Enter train number ";
  getline(cin, mystr);
  stringstream(mystr) >> train[i].trainNumber;
  cout << "Enter departure time ";
  getline(cin, train[i].departureTime);
 }

 int N;
 cin >> N;
 bool boolean = false;
 for (int i = 0; i < 3; i++) {
  if (train[i].trainNumber == N) {
   printTrain(train[i]);
   boolean = true;
  }
 }
 if (boolean == false) cout << "No trains with such train number";

}

void printTrain(TRAIN one_train) {
 cout << one_train.name;
 cout << " (" << one_train.trainNumber << ") ";
 cout << one_train.departureTime;
}
