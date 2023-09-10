#include <stdio.h>
#include <cs50.h>
#include <math.h>

int cents, coins;
float change;

int main(void)
{
    do
    {
        change = get_float("Changed Owed: ");   // While change is negative
    }                                          // Request change from the user
    while (change < 0);

    // Convert value to cents
    cents = round(change * 100);

    // Count amount of coins for change
    do
    {
        if (cents >= 25)
        {
            cents = cents - 25;
        }
        else if (cents >= 10)
        {
            cents = cents - 10;
        }
        else if (cents >= 5)
        {
            cents = cents - 5;
        }
        else
        {
            cents = cents - 1;
        }
        coins++;
    }
    while (cents > 0);

     // Print number of coins
     printf("coins: %i\n", coins);
}




