// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill_amount, float tax_percent, int tip_percent);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
float half(float bill_amount, float tax_percent, int tip_percent)
{
    float i = (((tax_percent/100)*bill_amount) + bill_amount);
    float j = (((tip_percent/100.0)*i) + i);
    return (j/2);
}
