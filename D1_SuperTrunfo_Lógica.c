#include <stdio.h>

int main() {
    // Variáveis das Cartas
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char nomeCidade1[100], nomeCidade2[100];
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    int pontosTuristicos1, pontosTuristicos2;
    float densidade1, densidade2, pibPerCapita1, pibPerCapita2;
    float superpoder1, superpoder2;

    // Entrada Carta 1
    printf("Digite os dados da Carta 1:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    while (getchar() != '\n');
    printf("Código da Carta: ");
    scanf("%s", codigo1);
    while (getchar() != '\n');
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1);
    while (getchar() != '\n');
    printf("População: ");
    scanf("%lu", &populacao1);
    while (getchar() != '\n');
    printf("Área (em km²): ");
    scanf("%f", &area1);
    while (getchar() != '\n');
    printf("PIB (em bilhões): ");
    scanf("%f", &pib1);
    while (getchar() != '\n');
    printf("Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Cálculos Carta 1
    densidade1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;
    superpoder1 = populacao1 + area1 + (pib1 * 1000000000) + pontosTuristicos1 + pibPerCapita1 + (1 / densidade1);

    // Entrada Carta 2
    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    while (getchar() != '\n');
    printf("Código da Carta: ");
    scanf("%s", codigo2);
    while (getchar() != '\n');
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);
    while (getchar() != '\n');
    printf("População: ");
    scanf("%lu", &populacao2);
    while (getchar() != '\n');
    printf("Área (em km²): ");
    scanf("%f", &area2);
    while (getchar() != '\n');
    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);
    while (getchar() != '\n');
    printf("Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculos Carta 2
    densidade2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;
    superpoder2 = populacao2 + area2 + (pib2 * 1000000000) + pontosTuristicos2 + pibPerCapita2 + (1 / densidade2);

    // Exibir valores calculados 
    printf("\n--- VALORES CALCULADOS ---\n");
    printf("Carta 1 - Densidade: %.2f, PIB per Capita: %.2f, Super Poder: %.2f\n", densidade1, pibPerCapita1, superpoder1);
    printf("Carta 2 - Densidade: %.2f, PIB per Capita: %.2f, Super Poder: %.2f\n", densidade2, pibPerCapita2, superpoder2);

    // COMPARAÇÃO FIXA: apenas um atributo numérico
    // Neste exemplo, estamos comparando DENSIDADE POPULACIONAL (menor vence)

    printf("\n--- COMPARAÇÃO DE DENSIDADE POPULACIONAL ---\n");

    if (densidade1 < densidade2) {
        printf("Carta 1 venceu! Menor densidade populacional.\n");
    } else if (densidade2 < densidade1) {
        printf("Carta 2 venceu! Menor densidade populacional.\n");
    } else {
        printf("Empate! As duas cartas têm a mesma densidade populacional.\n");
    }

    return 0;
}
