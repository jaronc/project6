#include <iostream>
#include <cstdlib>
#include <ctime>
#include "str.h"
#include "symbol.h"
#include "reel.h"



using namespace std;



reel::reel()
{
  stops = new symbol[10];
  payline = 0;
}

reel::~reel()
{
  //deallocated memory
  delete[] stops;
  stops = NULL;
  payline = 0;
}

reel::reel(const reel &r)
{
  payline = r.payline;
  //uses symbol member function to copy all member data
  for(int i = 0; i < 10; i++)
    {
      stops[i].setData(r.stops[i].getName(), r.stops[i].getBonus());
    }
}

void reel::setReel(symbol *s)
{
  int i = 0;
  //used to randomly generate new machine configuration
  for(int j = 0; j < 10; j++)
    {
      i = rand()%6;
      stops[j].setData(s[i].getName(), s[i].getBonus());
    }
}

int reel::spin()
{ 
  //sets payline stop number
  payline = rand()%10;
  stops[payline].print();
  //returns the bonus value to be added to total bonus in the main function
  return stops[payline].getBonus();
}

void reel::print(int i) const
{
  //prints one stop data
  stops[i].print();
    
}
