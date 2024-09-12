#include <iostream>
#include <iomanip>
#include <stdio.h>
#include<string.h>
#include "myDate.h"

using namespace std;

struct Movie {
    char name[20];
    int running;
    double rating;
    myDate release;
    string actor;
};

int J(int year, int month, int day){
  int I = year;
  int J = month;
  int K = day;
  int JD= K-32075+1461*(I+4800+(J-14)/12)/4+367*(J-2-(J-14)/12*12)/12-3*((I+4900+(J-14)/12)/100)/4;
  return JD;
}

void populate(Movie *mov[10], string *mptr, int *numptr, double *rateptr, myDate *releaseptr, string *aptr){
  for (int j = 0; j < 10;j++){ 
    mov[j] = new Movie[10];
    strcpy(mov[j] -> name, mptr[j].c_str());
    mov[j] -> running = numptr[j];
    mov[j] -> rating = rateptr[j];
    mov[j] -> release = releaseptr[j];
    mov[j] -> actor = aptr[j];  
  }
}

void sortByName(Movie *m[]){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 9; j++){
			if (strcmp(m[j] -> name, m[j+1] -> name) > 0){
        Movie *temp = m[j+1];
        m[j+1] = m[j];
        m[j] = temp;
			}
		}
	}
}

void sortByRunning(Movie *m[]){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 9; j++){
			if (m[j] -> running > m[j+1] -> running){
        Movie *temp = m[j+1];
        m[j+1] = m[j];
        m[j] = temp;
			}
		}
	}
}

void sortByRating(Movie *m[]){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 9; j++){
			if (m[j] -> rating > m[j+1] -> rating){
        Movie *temp = m[j+1];
        m[j+1] = m[j];
        m[j] = temp;
			}
		}
	}
}

void sortByDate(Movie *m[]){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 9; j++){
			if (J((m[j] -> release).getYear() ,(m[j] -> release).getMonth(), (m[j] -> release).getDay()) > J((m[j+1] -> release).getYear() ,(m[j+1] -> release).getMonth(), (m[j+1] -> release).getDay())){
        Movie *temp = m[j+1];
        m[j+1] = m[j];
        m[j] = temp;
			}
		}
	}
}

void sortByActor(Movie *m[]){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 9; j++){
			if (strcmp((m[j] -> actor).c_str(), (m[j+1] -> actor).c_str()) > 0){
        Movie *temp = m[j+1];
        m[j+1] = m[j];
        m[j] = temp;
			}
		}
	}
}

void display(Movie *mov[10]){
  cout << setw(15) << "Movie" << setw(20) << "Running Time" << setw(20) << "IMDB Rating" <<  setw(25) << "Release Date" << setw(25) << "Main Actor"<< endl;
        cout << setw(15) << "-----" << setw(20) << "------------" << setw(20) << "-----------" <<  setw(25) << "-------------" << setw(25) << "----------"<< endl;
  for (int i = 0; i < 10;i++){ 
    cout << setw(15) << mov[i] -> name;
   
    cout << setw(15)<< (mov[i] -> running)/60 << "h " << (mov[i] -> running)%60;
    if ((mov[i] -> running)%60 == 0){
      cout << 0 << "m";
    }
    else{
      cout << "m";
    }
     
    cout << setw(20)<< mov[i] -> rating;

    cout  << setw(25) << ((mov[i] -> release).display());
  
    cout << setw(25)<< mov[i] -> actor;
  
    cout << endl;
  }
  cout << "---------------------------------------------------------------------------------------------------------------" << endl;
}

int main(){
  
  string m[10] = {"Ambulance", "Dune", "Morbius", "Euphoria", "Outlander", "The Matrix", "Water World", "Easy Rider", "Cleaner", "Fargo"};
  
  int nums[10] = {136, 155, 104, 55, 60, 136, 177, 95, 88, 53};
  
  double rate[10] = {6.2, 8.1, 5.1, 8.4, 8.4, 8.7, 6.2, 7.3, 6.1, 8.9};
  
	myDate release[10] = {myDate(4,8,2022), myDate(10,22,2021), myDate(4,1,2022), myDate(6,16,2019), myDate(8,9,2014), myDate(3,31,1999), myDate(7,28,1995), myDate(6,26,1969), myDate(9,11,2007), myDate(4,15,2014)};
  
  string a[10] = {"Jake Gyllenhaal", "Timothee Chalamet", "Matt Smith", "Zendaya Stoemer", "Sam Heughan", "Keano Reeves", "Kevin Cosner", "Peter Fonda", "Samuel Jackson", "Martin Freeman"};
  int choice = 0;
  int stop = 0;
  Movie *mov[10];
  string *mptr = m;
  int *numptr = nums;
  double *rateptr = rate;
  myDate *releaseptr = release;
  string *aptr = a;
  populate(mov,mptr, numptr, rateptr, releaseptr, aptr);
  while (stop == 0){
    cout << "1. Display list sorted by Name" << endl;
    cout << "2. Display list sorted by Running Time" << endl;
    cout << "3. Display list sorted by IMDB Rating" << endl;
    cout << "4. Display list sorted by Release Date" << endl;
    cout << "5. Display list sorted by Main Actor" << endl;
    cout << "6. Exit" << endl;
    cin >> choice;
  		if (choice == 1){ 
        sortByName(mov); 
        display(mov);
        }
      else if (choice == 2){  
        sortByRunning(mov); 
        display(mov);
        }
      else if (choice == 3){  
        sortByRating(mov); 
        display(mov);
        }
      else if (choice == 4){  
        sortByDate(mov); 
        display(mov);
        }
      else if (choice == 5){  
        sortByActor(mov); 
        display(mov);
        }
      else if (choice == 6){  
        cout << "Bye Bye!" << endl;
        stop = 1;
        }
      else{  
        cout << "Invalid Input! Program Ending!" << endl;
        stop = 1;
      }
  }
}


  

