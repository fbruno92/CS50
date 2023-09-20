#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    // Pede ao usuário o número do cartão de crédito
    long card_number = get_long("Digite o número do seu cartão de crédito: ");

    // Converte o número do cartão em uma string
    char card_string[17];
    sprintf(card_string, "%ld", card_number);

    // Verifica se o número do cartão é válido e qual é a bandeira
    int length = strlen(card_string);
    int sum = 0;
    bool is_valid = false;
    string brand = "INVALID\n";

    for (int i = length - 1; i >= 0; i--)
    {
        int digit = card_string[i] - '0';

        if ((length - i) % 2 == 0)
        {
            digit *= 2;
            sum += digit / 10 + digit % 10;
        }
        else
        {
            sum += digit;
        }
    }

    if (sum % 10 == 0)
    {
        if (length == 15 && (strncmp(card_string, "34", 2) == 0 || strncmp(card_string, "37", 2) == 0))
        {
            brand = "AMEX\n";
            is_valid = true;
        }
        else if (length == 16 && strncmp(card_string, "5", 1) == 0 && (card_string[1] >= '1' && card_string[1] <= '5'))
        {
            brand = "MASTERCARD\n";
            is_valid = true;
        }
        else if ((length == 13 || length == 16) && strncmp(card_string, "4", 1) == 0)
        {
            brand = "VISA\n";
            is_valid = true;
        }
    }

    // Imprime o resultado
    printf("%s", is_valid ? brand : "INVALID\n");

    return 0;
}

