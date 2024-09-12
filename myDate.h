#include <string>

using namespace std;

class myDate {
  private:
    int month;
    int day;
    int year;
  public:
    myDate();
    myDate(int M, int D, int Y);
    string display();
    void increaseDate(int N);
    void decreaseDate(int N);
    void addMonth();
    int daysBetween(myDate D);
    int getMonth();
    int getDay();
    int getYear();
    int dayOfYear();
    string dayName();
};