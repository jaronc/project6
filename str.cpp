void strcpy(char *a, char *b)
{
   while((*b) != '\0')
    {
      (*a) = (*b);
      b++;
      a++;
    }
   (*a) = '\0';
}

int strlen(char *a)
{
  int i = 0; 
  while((*a) != '\0')
    {
      a++;
      i++;
    }
  return i;
}

bool strcmp(char *a, char *b)
{
  bool final = true;
  //compares every char in one array to equiv char in another array
  while((*a) != '\0' and final)
    {
      //if the chars are equal, moves on to next char
      if((*a) == (*b))
	{
	  a++;
	  b++;
	}
      //if chars are not equal, statement false and break while loop
      else
	{
	  final = false;
	}
    }
  //checks that both strings have same length
  if((*a) == (*b))
    {
      return final;
    }
  else
    {
      final = false;
    }
  return final;
}

void strcat(char *a, char *b)
{
  while((*a) != '\0')
    {
      a++;
    }
  while((*b) != '\0')
    {
      (*a) = (*b);
      a++;
      b++;
    }
  (*a) = '\0';
}
