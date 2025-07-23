#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
} Carta;

void compararCartas(Carta c1, Carta c2, int opcao) {
    printf("\nComparando: %s vs %s\n", c1.nome, c2.nome);
    switch (opcao) {
        case 1:
            printf("População: %d vs %d\n", c1.populacao, c2.populacao);
            if (c1.populacao > c2.populacao)
                printf("Eba! Temos um vencedor!: %s\n", c1.nome);
            else if (c1.populacao < c2.populacao)
                printf("Eba! Temos um vencedor!: %s\n", c2.nome);
            else
                printf("Uau! Temos um empate! As cartas estão igualmente poderosas!\n");
            break;
        case 2:
            printf("Área: %.2f vs %.2f\n", c1.area, c2.area);
            if (c1.area > c2.area)
                printf("Eba! Temos um vencedor!: %s\n", c1.nome);
            else if (c1.area < c2.area)
                printf("Eba! Temos um vencedor!: %s\n", c2.nome);
            else
                printf("Uau! Temos um empate! As cartas estão igualmente poderosas!\n");
            break;
        case 3:
            printf("PIB: %.2f vs %.2f\n", c1.pib, c2.pib);
            if (c1.pib > c2.pib)
                printf("Eba! Temos um vencedor!: %s\n", c1.nome);
            else if (c1.pib < c2.pib)
                printf("Eba! Temos um vencedor!: %s\n", c2.nome);
            else
                printf("Uau! Temos um empate! As cartas estão igualmente poderosas!\n");
            break;
        case 4:
            printf("Pontos Turísticos: %d vs %d\n", c1.pontosTuristicos, c2.pontosTuristicos);
            if (c1.pontosTuristicos > c2.pontosTuristicos)
                printf("Eba! Temos um vencedor!: %s\n", c1.nome);
            else if (c1.pontosTuristicos < c2.pontosTuristicos)
                printf("Eba! Temos um vencedor!: %s\n", c2.nome);
            else
                printf("Uau! Temos um empate! As cartas estão igualmente poderosas!\n");
            break;
        case 5:
            printf("Densidade Demográfica: %.2f vs %.2f\n", c1.densidadeDemografica, c2.densidadeDemografica);
            if (c1.densidadeDemografica < c2.densidadeDemografica)
                printf("Eba! Temos um vencedor!: %s\n", c1.nome);
            else if (c1.densidadeDemografica > c2.densidadeDemografica)
                printf("Eba! Temos um vencedor!: %s\n", c2.nome);
            else
                printf("Uau! Temos um empate! As cartas estão igualmente poderosas!\n");
            break;
        default:
            printf("Oops! Não entendi sua escolha. Tente novamente!\n");
            break;
    }
}

int main() {
    Carta carta1 = {"Brasil", 213000000, 8515767.00, 1440000000000.00, 20, 25.00};
    Carta carta2 = {"Japão", 125800000, 377975.00, 4937000000000.00, 15, 333.00};

    int escolha;

    printf("********* SUPER TRUNFO - COMPARAÇÃO DE PAÍSES *********\n");
    printf("Hora da decisão! Qual atributo vai te levar à vitória?\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Escolha seu atributo e prepare-se para o duelo!\n");
    scanf("%d", &escolha);

    compararCartas(carta1, carta2, escolha);

    return 0;
}