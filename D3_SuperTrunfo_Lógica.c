#include <stdio.h>
#include <string.h>

// Definindo estrutura da carta
typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
} Carta;

// Função para exibir o menu e garantir que o segundo atributo seja diferente do primeiro
int selecionarAtributo(int atributoSelecionado) {
    int escolha;
    printf("\nHora da decisão! Qual atributo vai te levar à vitória?\n");
    if (atributoSelecionado != 1) printf("1 - População\n");
    if (atributoSelecionado != 2) printf("2 - Área\n");
    if (atributoSelecionado != 3) printf("3 - PIB\n");
    if (atributoSelecionado != 4) printf("4 - Pontos Turísticos\n");
    if (atributoSelecionado != 5) printf("5 - Densidade Demográfica\n");
    printf("Escolha seu atributo e prepare-se para o duelo!\n");
    scanf("%d", &escolha);

    // Validação
    if (escolha < 1 || escolha > 5 || escolha == atributoSelecionado) {
        printf("Oops! Não entendi sua escolha. Tente novamente!\n");
        return selecionarAtributo(atributoSelecionado);
    }

    return escolha;
}

// Função para obter valor numérico para cálculo
float getValor(Carta c, int atributo) {
    switch (atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontosTuristicos;
        case 5: return c.densidadeDemografica;
        default: return 0;
    }
}

// Função para comparar dois atributos e determinar vencedor da rodada
void compararCartas(Carta c1, Carta c2, int atr1, int atr2) {
    float v1_a1 = getValor(c1, atr1);
    float v2_a1 = getValor(c2, atr1);

    float v1_a2 = getValor(c1, atr2);
    float v2_a2 = getValor(c2, atr2);

    // Comparações individuais
    const char *vencedorA1 = (atr1 == 5) ? 
        ((v1_a1 < v2_a1) ? c1.nome : (v1_a1 > v2_a1) ? c2.nome : "Uau! Temos um empate! As cartas estão igualmente poderosas!") :
        ((v1_a1 > v2_a1) ? c1.nome : (v1_a1 < v2_a1) ? c2.nome : "Uau! Temos um empate! As cartas estão igualmente poderosas!");

    const char *vencedorA2 = (atr2 == 5) ? 
        ((v1_a2 < v2_a2) ? c1.nome : (v1_a2 > v2_a2) ? c2.nome : "Uau! Temos um empate! As cartas estão igualmente poderosas!") :
        ((v1_a2 > v2_a2) ? c1.nome : (v1_a2 < v2_a2) ? c2.nome : "Uau! Temos um empate! As cartas estão igualmente poderosas!");

    // Soma dos atributos
    float somaC1 = (atr1 == 5 ? -v1_a1 : v1_a1) + (atr2 == 5 ? -v1_a2 : v1_a2);
    float somaC2 = (atr1 == 5 ? -v2_a1 : v2_a1) + (atr2 == 5 ? -v2_a2 : v2_a2);

    // Determinar vencedor final
    const char *vencedorFinal = (somaC1 > somaC2) ? c1.nome :
                          (somaC1 < somaC2) ? c2.nome : "Uau! Temos um empate! As cartas estão igualmente poderosas!";

    // Exibir resultado
    printf("\nUhul! Já Temos o Resultado da Rodada:\n");
    printf("------------------------------------\n");
    printf("País 1: %s\n", c1.nome);
    printf("País 2: %s\n\n", c2.nome);

    printf("Atributo 1 (%d): %.2f vs %.2f → %s venceu\n", atr1, v1_a1, v2_a1, vencedorA1);
    printf("Atributo 2 (%d): %.2f vs %.2f → %s venceu\n\n", atr2, v1_a2, v2_a2, vencedorA2);

    printf("Ei, Veja a Soma dos atributos:\n");
    printf("%s: %.2f\n", c1.nome, somaC1);
    printf("%s: %.2f\n\n", c2.nome, somaC2);

    if (strcmp(vencedorFinal, "Empate") == 0)
        printf("Uhul! Já Temos o Resultado da Rodada: Empate!\n");
    else
        printf("Uhul! Já Temos o Resultado da Rodada: %s venceu a rodada!\n", vencedorFinal);
    printf("------------------------------------\n");
}

int main() {
    // Cartas pré-cadastradas
    Carta brasil = {"Brasil", 213000000, 8515767.00, 1440000000000.00, 20, 25.00};
    Carta japao = {"Japão", 125800000, 377975.00, 4937000000000.00, 15, 333.00};

    printf("********* SUPER TRUNFO — Nível Mestre *********\n");

    int atributo1 = selecionarAtributo(0);  // sem restrições
    int atributo2 = selecionarAtributo(atributo1);  // com exclusão do primeiro

    compararCartas(brasil, japao, atributo1, atributo2);

    return 0;
}
