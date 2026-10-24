#include <cs50.h>
#include <stdio.h>

int main(void)
{ // Name of output
    int cents;
    do
    { // Callculate how much change is owed
        cents = get_int("Change Owed; ");
    }
    while (cents < 0);
    int coins = 0;
    // Define how much each coin is worth
    int values[] = {25, 10, 5, 1};
    // Minimum number of coins needed for change
    for (int i = 0; i < 4; i++)
    {
        coins += cents / values[i];
        cents %= values[i];
    }
    printf("%i\n", coins);
}
