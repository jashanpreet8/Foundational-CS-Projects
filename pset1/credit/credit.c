#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card;
    do{
        card = get_long("Number(only numerics): ");
      }while(card < 0); 

int card1, card2, card3, card4, card5, card6, card7, card8;
card1 = (((card % 100)/10)*2);
card2 = (((card % 10000)/1000)*2);
card3 = (((card % 1000000)/100000)*2);
card4 = (((card % 100000000)/10000000)*2);
card5 = (((card % 10000000000)/1000000000)*2);
card6 = (((card % 1000000000000)/100000000000)*2);
card7 = (((card % 100000000000000)/10000000000000)*2);
card8 = (((card % 10000000000000000)/1000000000000000)*2);

card1 = ((card1 % 100)/10) + (card1 % 10);
card2 = ((card2 % 100)/10) + (card2 % 10);
card3 = ((card3 % 100)/10) + (card3 % 10);
card4 = ((card4 % 100)/10) + (card4 % 10);
card5 = ((card5 % 100)/10) + (card5 % 10);
card6 = ((card6 % 100)/10) + (card6 % 10);
card7 = ((card7 % 100)/10) + (card7 % 10);
card8 = ((card8 % 100)/10) + (card8 % 10);

int sum1 = (card1 + card2 + card3 + card4 + card5 + card6 + card7 + card8);

int card9, card10, card11, card12, card13, card14, card15, card16;
card9 = (card % 10);
card10 = ((card % 1000)/100);
card11 = ((card % 100000)/10000);
card12 = ((card % 10000000)/1000000);
card13 = ((card % 1000000000)/100000000);
card14 = ((card % 100000000000)/10000000000);
card15 = ((card % 10000000000000)/1000000000000);
card16 = ((card % 1000000000000000)/100000000000000);

int sum2 = (card9 + card10 + card11 + card12 + card13 + card14 + card15 + card16);

int sum3 = sum1 + sum2;

if(sum3 % 10 != 0)
{
    printf("INVALID\n");
    return 0;
}

int length = 0;
long visa = card;
long amex = card;
long master = card;

while(card > 0)
{
   card = (card/10);
    length++;
}

while(visa > 10)
{
    visa /= 10;
}

if(visa == 4 && (length == 13 || length ==16))
{
    printf("VISA\n");
    return 0;
}

while(amex >= 10000000000000)
{
    amex /= 10000000000000;
}

if((amex == 34 || amex  == 37) && length == 15)
{
    printf("AMEX\n");
    return 0;
}

while(master >= 100000000000000)
{
    master /= 100000000000000;
}

if ((master == 51 || master == 52 || master == 53 || master == 54 || master == 55) && length == 16)
{
    printf("MASTERCARD\n");
    return 0;
}
else
{
    printf("INVALID\n");
    return 0;
}
}