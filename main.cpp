/************************************/
/*Name: Jaron Corbett               */
/*Date: 3-12-15                     */
/*Program name: slots               */
/************************************/


#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <ctime>
#include "str.h"
#include "symbol.h"
#include "reel.h"

using namespace std;

//read symbols in from file to symbol array
void readsymbols(symbol*);
//use rng to copy symbols from symbol array into machine config
void createconfig(reel*, symbol*);
//print all the reels and stops for current machine config
void printconfig(reel*);
//print one symbol from the specific stop and reel
void printone(reel*);
//rng and each reel to print one random stop from each one
//sum together all bonus values and print total
void spinreel(reel*);



int main()
{
  srand(time(NULL));
  int end = 0;
  symbol *hold = new symbol[6];
  reel *mach = new reel[3];
  readsymbols(hold);
  createconfig(mach, hold);
  


  while(end == 0)
    {
      int select;
      cout << "------------------" << endl;
      cout << "Slot Machine Menu:" << endl;
      cout << "------------------" << endl;
      cout << "1. Create new slot machine" << endl;
      cout << "2. Print slot machine configuration" << endl;
      cout << "3. Print specific slot" << endl;
      cout << "4. Spin the Reels" << endl;
      cout << "5. Exit" << endl;
      cout << "-----------------" << endl;
      cout << "Enter selection: ";
      cin >> select;
      cout << "-----------------" << endl;
      switch(select)
	{
	case 1:
	  //clears previous config
	  delete[] mach;
	  mach = NULL;
	  mach = new reel[3];
	  createconfig(mach, hold);
	  break;
	case 2:
	  printconfig(mach);
	  break;
	case 3:
	  printone(mach);
	  break;
	case 4:
	  spinreel(mach);
	  break;
	case 5:
	  cout << "GOODBYE" << endl;
	  end = 1;
	  break;
	default:
	  cout << "invalid entry" << endl;
	  break;
	}
    }
  delete[] mach;
  mach = NULL;
  delete[] hold;
  hold = NULL;
}

void readsymbols(symbol *s)
{
  char *tmp = new char[20];
  int itmp = 0;
  ifstream fin;
  cout << "Enter File Name: ";
  cin >> tmp;
  char *filename = new char[strlen(tmp)+1];
  strcpy(filename, tmp);
  fin.open(filename);
  //for loop to set all data for all the symbols
  for(int i = 0; i < 6; i++)
    {
      fin >> tmp;
      fin >> itmp;
      s[i].setData(tmp, itmp);
    }
  fin.close();
  delete[] tmp;
  tmp = NULL;
  delete[] filename;
  filename = NULL;
}
      
void createconfig(reel *r, symbol *s)
{
  //loop through each reel to set all the stops
  for(int i = 0; i < 3; i++)
    {
      r[i].setReel(s);
    }
}

void printconfig(reel *r)
{
  //for loop used to make it so that each reel is vertically printed
  for(int i = 0; i < 10; i++)
    {
      r[0].print(i);
      cout << '\t';
      r[1].print(i);
      cout << '\t';
      r[2].print(i);
      cout << endl;
    }
}

void printone(reel *r)
{
  int col = 0;
  int stop = 0;
  cout << "Enter Reel Number: ";
  cin >> col;
  // -- used to go from human logic to computer logic
  col--;
  cout << "Enter Stop Number: ";
  cin >> stop;
  stop--;
  r[col].print(stop);
  cout << endl;
}
  
void spinreel(reel *r)
{
  int j = 0;
  //prints each payline stop and adds the bonus value to int j
  for(int i = 0; i < 3; i++)
    {
      j += r[i].spin();
    }
  //prints the total bonus value amount
  cout << "Bonus Value: " << j;
  cout << endl;
}
