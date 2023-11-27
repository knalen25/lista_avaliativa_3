#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validarPlaca(char placa[]) {
    int comprimento = strlen(placa);

    if ((comprimento == 8 && placa[3] == '-' && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2])) ||
        (comprimento == 7 && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) &&
         isdigit(placa[3]) && isalpha(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]))) {
        return 1; // Placa válida
    } else {
        printf("Placa invalida\n");
        return 0; // Placa inválida
    }
}

int validarDia(char dia[]) {
    char diasValidos[7][15] = {"SEGUNDA-FEIRA", "TERCA-FEIRA", "QUARTA-FEIRA", "QUINTA-FEIRA", "SEXTA-FEIRA", "SABADO", "DOMINGO"};

    for (int i = 0; i < 7; i++) {
        if (strcmp(dia, diasValidos[i]) == 0) {
            return 1; // Dia válido
        }
    }

    printf("Dia da semana invalido\n");
    return 0; // Dia inválido
}

void verificarRodizio(char placa[], char dia[]) {
    int term = placa[strlen(placa) - 1] - '0';
    for (int i = 0; dia[i]; i++) {
        dia[i] = tolower(dia[i]);
    }

    if ((strcmp(dia, "segunda-feira") == 0 && (term == 0 || term == 1)) ||
        (strcmp(dia, "terca-feira") == 0 && (term == 2 || term == 3)) ||
        (strcmp(dia, "quarta-feira") == 0 && (term == 4 || term == 5)) ||
        (strcmp(dia, "quinta-feira") == 0 && (term == 6 || term == 7)) ||
        (strcmp(dia, "sexta-feira") == 0 && (term == 8 || term == 9))) {
        printf("%s nao pode circular %s\n", placa, dia);
    } else if (strcmp(dia, "sabado") == 0 || strcmp(dia, "domingo") == 0) {
        printf("Nao ha proibicao no fim de semana\n");
    } else {
        printf("%s pode circular %s\n", placa, dia);
    }
}

int main() {
    char placa[20];
    char dia[15];

    scanf("%s", placa);
    scanf("%s", dia);

    int placavald = validarPlaca(placa);
    int diavald = validarDia(dia);

    if (placavald && diavald) {
        verificarRodizio(placa, dia);
    }

    return 0;
}
