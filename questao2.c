#include <stdio.h>
#include <math.h>

int main() {
    int mes;
    double Aporte, i, Valor = 0;
    double X = 0;
   
    //quantiodade de meses mk  
    scanf("%d", &mes);

    //Valor aporte mensal
    scanf("%lf", &Aporte);

    //taxa de juros mensal
    scanf("%lf", &i);

    for (int j = 1; j <= mes; j++)
    {
        Valor = Aporte * (1 + i) * (pow(1+i, j) - 1)/i;
        printf("Montante ao fim do mes %d: R$ %.2lf\n", j, Valor);
    }

    return 0;
}
