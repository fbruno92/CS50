#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool is_valid_key(const char *key) {
    int len = strlen(key);

    if (len != 26) {
        printf("A chave deve conter exatamente 26 caracteres.\n");
        return false;
    }

    int freq[26] = {0}; // Frequência de cada caractere na chave

    for (int i = 0; i < len; i++) {
        if (!isalpha(key[i])) {
            printf("A chave deve conter apenas caracteres alfabéticos.\n");
            return false;
        }

        int index = toupper(key[i]) - 'A';

        // Verifica se a letra já foi usada na chave
        if (freq[index] > 0) {
            printf("A chave deve conter caracteres únicos.\n");
            return false;
        }

        freq[index]++;
    }

    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s chave_de_substituicao\n", argv[0]);
        return 1;
    }

    if (!is_valid_key(argv[1])) {
        return 1;
    }

    // Obtém a chave da linha de comando
    char *chave = argv[1];

    printf("Texto simples:  ");
    char texto_simples[1000];
    fgets(texto_simples, 1000, stdin);

    printf("Texto cifrado: ");

    // Itera sobre cada caractere do texto simples
    for (int i = 0; texto_simples[i] != '\0'; i++) {
        if (isalpha(texto_simples[i])) {
            char base = isupper(texto_simples[i]) ? 'A' : 'a';
            char chave_caractere = toupper(chave[texto_simples[i] - base]);
            char novo_caractere = (isupper(texto_simples[i])) ? chave_caractere : tolower(chave_caractere);
            printf("%c", novo_caractere);
        } else {
            printf("%c", texto_simples[i]);
        }
    }

    printf("\n");
    return 0;
}
