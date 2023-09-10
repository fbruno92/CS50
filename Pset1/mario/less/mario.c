#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    //Prompt value from user
    do
    {
        height = get_int("Heigth: ");
    }
    while (height < 1 || height > 8);

    // Print rows
    for (int row = 0; row < height; row++)
    {
        //Print spaces on rows
        for (int space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }
        //Print columms
        for (int columm = 0; columm <= row; columm++)
        {
            printf("#");
        }
        printf("\n");
    }
}


