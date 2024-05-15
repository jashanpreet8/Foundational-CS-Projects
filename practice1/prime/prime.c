#include <cs50.h>
#include <stdio.h>

int min, max, i;
bool prime(int number);

int main(void)
{
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
if( number <= 1 )
 {return false;}
for(int x = 2; x < number; x++)
 { if(number % x == 0)
   {return false;}
 }
return true;
}

