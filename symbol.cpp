#include <iostream>
#include "str.h"
#include "symbol.h"

using namespace std;

symbol::symbol()
{
  name = NULL;
  bonus = 0;
  tf = false;
}

symbol::symbol(const symbol &s)
{
  //exactly sized char array and copies from another symbol
  name = new char[strlen(s.name)+1];
  strcpy(name, s.name);
  bonus = s.bonus;
  tf = s.tf;
}

symbol::~symbol()
{
  //deallocated all memory for char array
  delete[] name;
  name = NULL;
  bonus = 0;
  tf = false;
}

void symbol::setData(char *n, int b)
{
  //takes char* and int to create all data members for symbol
  name = new char[strlen(n)+1];
  strcpy(name, n);
  bonus = b;
  if(b == 0)
    {
      tf = false;
    }
  else
    {
      tf = true;
    }
}


char* symbol::getName() const
{
  return name;
}

int symbol::getBonus() const
{
  return bonus;
}

void symbol::print() const
{
  //prints all data members for one symbol
  cout << name << '\t' << bonus << ' ' << tf << '\t';
}
