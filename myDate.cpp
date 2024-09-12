#include <iostream>
#include <string>
#include "myDate.h"

using namespace std;

void J2G(int JD, int &year, int &month, int &day){
  int I, J, K, L, N;
  L= JD+68569;
  N= 4*L/146097;
  L= L-(146097*N+3)/4;
  I= 4000*(L+1)/1461001;
  L= L-1461*I/4+31;
  J= 80*L/2447;
  K= L-2447*J/80;
  L= J/11;
  J= J+2-12*L;
  I= 100*(N-49)+I+L;
  year = I;
  month = J;
  day = K;
}

int G2J(int year, int month, int day){
  int I = year;
  int J = month;
  int K = day;
  int JD= K-32075+1461*(I+4800+(J-14)/12)/4+367*(J-2-(J-14)/12*12)/12-3*((I+4900+(J-14)/12)/100)/4;
  return JD;
}

myDate::myDate(){
  month = 5;
  day = 11;
  year = 1959;
}

myDate::myDate(int M, int D, int Y){
  month = M;
  day = D;
  year = Y;
  int month1 = M;
  int day1 = D;
  int year1 = Y;
  int date = G2J(year, month, day);
  J2G(date, year, month, day);
  if (month1 != month || day1 != day || year1 != year){
    month = 5;
    day = 11;
    year = 1959;
  }
}

string myDate:: display(){
  if (month == 1){
    return "January " + to_string(day) + ", " + to_string(year);
  }
  else if (month == 2){
    return "Febuary " + to_string(day) + ", " + to_string(year);
  }
  else if (month == 3){
    return "March " + to_string(day) + ", " + to_string(year);

  }
  else if (month == 4){
    return "April " + to_string(day) + ", " + to_string(year);

  }
  else if (month == 5){
    return "May " + to_string(day) + ", " + to_string(year);
  }
  else if (month == 6){
    return "June " + to_string(day) + ", " + to_string(year);
  }
  else if (month == 7){
    return "July " + to_string(day) + ", " + to_string(year);
  }
  else if (month == 8){
    return "August " + to_string(day) + ", " + to_string(year);
  }
  else if (month == 9){
    return "September " + to_string(day) + ", " + to_string(year);
  }
  else if (month == 10){
    return "October " + to_string(day) + ", " + to_string(year);
  }
  else if (month == 11){
    return "November " + to_string(day) + ", " + to_string(year);
  }
  else {
    return "December " + to_string(day) + ", " + to_string(year);
  }
}

void myDate::increaseDate(int N){
  int startJulian = G2J(year, month, day);
  int finalDate = startJulian + N;
  J2G(finalDate, year, month, day);
}

void myDate::decreaseDate(int N){
  int startJulian = G2J(year, month, day);
  int finalDate = startJulian - N;
  J2G(finalDate, year, month, day);
}

void myDate::addMonth(){
  int dayset = day;
  int startJulian = G2J(year, month, day);
  int finalDate = startJulian + 35;
  J2G(finalDate, year, month, day);
  if (day != dayset){
    startJulian = G2J(year, month, day);
    finalDate = startJulian - day;
    J2G(finalDate, year, month, day);
    }
}

int myDate::daysBetween(myDate D){
  int thatmonth = D.getMonth();
  int thatday = D.getDay();
  int thatyear = D.getYear();
  int thatJulian = G2J(thatyear, thatmonth, thatday);
  int thisJulian = G2J(year, month, day);
  return thatJulian - thisJulian;
}

int myDate::getMonth(){
  return month;
}

int myDate::getDay(){
  return day;
}

int myDate::getYear(){
  return year;
}

int myDate::dayOfYear(){
  int bJulian = G2J(year, 1, 1);
  int cJulian = G2J(year, month, day);
  return cJulian - bJulian + 1;
  
}

string myDate::dayName(){
  int date = G2J(year, month, day);
  int name = date % 7;
  J2G(date, year, month, day);
  if (name == 0){
    return "Monday";
  }
  else if (name == 1){
    return "Tuesday";
  }
  else if (name == 2){
    return "Wednesday";
  }
  else if (name == 3){
    return "Thursday";
  }
  else if (name == 4){
    return "Friday";
  }
  else if (name == 5){
    return "Saturday";
  }
  else {
    return "Sunday";
  }
}



