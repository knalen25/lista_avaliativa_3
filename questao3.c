#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void ConferePlacaDia(char placa[], char dia[]) {
    
    if ((strlen(placa) == 8 &&
         isupper(placa[0]) &&
         isupper(placa[1]) &&
         isupper(placa[2]) &&
         placa[3] == '-' &&
         isdigit(placa[4]) &&
         isdigit(placa[5]) &&
         isdigit(placa[6]) &&
         isdigit(placa[7])) ||
        (strlen(placa) == 7 &&
         isupper(placa[0]) &&
         isupper(placa[1]) &&
         isupper(placa[2]) &&
         isdigit(placa[3]) &&
         isupper(placa[4]) &&
         isdigit(placa[5]) &&
         isdigit(placa[6])))
    {
        
    } 
    else {
        printf("Placa invalida\n");
        
    }

    // Verifica se o dia da semana é válido
    if (strcmp(dia, "SEGUNDA-FEIRA") == 0 ||
        strcmp(dia, "TERCA-FEIRA") == 0 ||
        strcmp(dia, "QUARTA-FEIRA") == 0 ||
        strcmp(dia, "QUINTA-FEIRA") == 0 ||
        strcmp(dia, "SEXTA-FEIRA") == 0 ||
        strcmp(dia, "SABADO") == 0 ||
        strcmp(dia, "DOMINGO") == 0)
    {
        //printf("Dia da semana válido!\n");
    } 
    else {
        printf("Dia da semana invalido\n");
        exit(1);  // Saia do programa se o dia não for válido
    }
}

void ConfereRodizio(char placa[], char dia[]) {
    // Converte o dia para minúscula
    for (int i = 0; dia[i]; i++) {
        dia[i] = tolower(dia[i]);
    }

    // SABADO E DOMINGO
    if (strcmp(dia, "sabado") == 0 || strcmp(dia, "domingo") == 0)
    {
        printf("Nao ha proibicao no fim de semana\n");
    }
    else {
        // SEGUNDA
        if ((strlen(placa) == 8 && (placa[7] == '0' || placa[7] == '1')) ||
            (strlen(placa) == 7 && (placa[6] == '0' || placa[6] == '1')) )
        {
            if (strcmp(dia, "segunda-feira") == 0) {
                printf("%s nao pode circular %s\n", placa, dia);
            } else {
                printf("%s pode circular %s\n", placa, dia);
            }
        }
        // TERCA-FEIRA
        else if ((strlen(placa) == 8 && (placa[7] == '2' || placa[7] == '3')) ||
                 (strlen(placa) == 7 && (placa[6] == '2' || placa[6] == '3')) )
        {
            if (strcmp(dia, "terca-feira") == 0) {
                printf("%s nao pode circular %s\n", placa, dia);
            } else {
                printf("%s pode circular %s\n", placa, dia);
            }
        }
        // QUARTA-FEIRA
        else if ((strlen(placa) == 8 && (placa[7] == '4' || placa[7] == '5')) ||
                 (strlen(placa) == 7 && (placa[6] == '4' || placa[6] == '5')) )
        {
            if (strcmp(dia, "quarta-feira") == 0) {
                printf("%s nao pode circular %s\n", placa, dia);
            } else {
                printf("%s pode circular %s\n", placa, dia);
            }
        }
        // QUINTA-FEIRA
        else if ((strlen(placa) == 8 && (placa[7] == '6' || placa[7] == '7')) ||
                 (strlen(placa) == 7 && (placa[6] == '6' || placa[6] == '7')) )
        {
            if (strcmp(dia, "quinta-feira") == 0) {
                printf("%s nao pode circular %s\n", placa, dia);
            } else {
                printf("%s pode circular %s\n", placa, dia);
            }
        }
        // SEXTA-FEIRA
        else if ((strlen(placa) == 8 && (placa[7] == '8' || placa[7] == '9')) ||
                 (strlen(placa) == 7 && (placa[6] == '8' || placa[6] == '9')) )
        {
            if (strcmp(dia, "sexta-feira") == 0) {
                printf("%s nao pode circular %s\n", placa, dia);
            } else {
                printf("%s pode circular %s\n", placa, dia);
            }
        }
    }
}

int main() {
    char placa[9];
    char dia[15];

    //printf("Digite a placa: ");
    scanf("%s", placa);

    //printf("Digite o dia: ");
    scanf("%s", dia);

    ConferePlacaDia(placa, dia);

    // A placa quanto o dia são válidos
    ConfereRodizio(placa, dia);

    return 0;
}
