#include <cs50.h>
#include <stdio.h>

int main(void)
{
int s, e;
do
{
   s = get_int("population start size?");
}while(s < 9);

do
{
    e = get_int("end population size?");
}while(e < s);
    /*TODO: Calculate number of years until we reach threshold


     nb = s/3  d = s/4  l = s + nb - d
     if l=e n=1 else
     while(l != e);
     int n = 0;
     if(s == e)
     n = 0
     else
     n = n + n/3 - n/4                               */

int y = 0;
while(s < e)
{
    s = s + (s/3) - (s/4);
    y++;
}

    // TODO: Print number of years
    printf("years:%i\n" ,y);
}
