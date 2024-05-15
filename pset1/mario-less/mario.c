#include <cs50.h>
#include <stdio.h>

int main()
{
  int n;
  do
  {
     n = get_int("Height of the pyramid?");
  }
  while(n < 1 || n > 8);


  for(int i = 0; i < n; i++)
  {

       for(int k = 0; k < n-i-1; k++)
       {
         printf(" ");
       }
       for(int j = 0 ;j <= i; j++)
       {
         printf("#");
       }
    printf("\n");
  }
}