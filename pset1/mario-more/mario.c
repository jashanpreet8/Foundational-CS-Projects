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
       for(int j = 0; j < n-i-1; j++)
       {
         printf(" ");
       }
       for(int k = 0 ; k <= i; k++)
       {
         printf("#");
       }
       for(int x = 0; x < n; x = n)
       {
        printf("  ");
       }
       for(int y = 0; y <= i; y++)
       {
        printf("#");
       }
    printf("\n");
  }
}
