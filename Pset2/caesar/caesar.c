#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

// Função para verificar se a chave é válida (deve ser um número inteiro)
bool is_valid_key(const char *key)
{
    while (*key)
    {
        if (!isdigit(*key))
        {
            return false;
        }
        key++;
    }
    return true;
}

int main(int argc, char *argv[])
{
    // Verifica se o número de argumentos na linha de comando está correto
    // e se a chave é válida
    if (argc != 2 || !is_valid_key(argv[1]))
    {
        printf("Uso: %s chave\n", argv[0]);
        return 1;
    }

    // Obtém a chave dos argumentos da linha de comando
    int chave = atoi(argv[1]);

    printf("Texto simples:  ");
    char texto_simples[1000];
    fgets(texto_simples, 1000, stdin);

    printf("Texto cifrado: ");

    // Itera sobre cada caractere do texto simples
    for (int i = 0; texto_simples[i] != '\0'; i++)
    {
        // Verifica se é uma letra
        if (isalpha(texto_simples[i]))
        {
            char base = isupper(texto_simples[i]) ? 'A' : 'a';
            // Aplica a cifra de César e imprime o caractere cifrado
            printf("%c", (char)(((texto_simples[i] - base + chave) % 26) + base));
        }
        else
        {
            // Se não for uma letra, imprime o caractere como está
            printf("%c", texto_simples[i]);
        }
    }

    printf("\n");
    return 0;
}
