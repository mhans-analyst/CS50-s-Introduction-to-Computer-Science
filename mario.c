#include <stdio.h>
#include <cs50.h>

void print_row(int spaces, int bricks);

int main(void)
{
// Prompt user for height
int height;
do
{height = get_int("Height:");}
while (height < 1);

// Make pyramid of user defined height
for (int i = 1; i <= height; i++)
{print_row(height - i, i);}
}

// Print the number of user defined bricks and align right
void print_row(int spaces, int bricks)
{for (int i = 0; i < spaces; i++)
printf(" ");
for (int i = 0; i < bricks; i++)
{printf("#");}
printf("\n");
}
