#include <stdio.h>
#include <string.h> // Necessário para strcpy (copiar strings dos nomes dos atributos)

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    // Variáveis para as Cartas
    char Estado,Estado2;
    char Nomedacidade[50], Nomedacidade2[50];
    char codigocarta[10], codigocarta2[10];
    int numerodepontosturisticos, numerodepontosturisticos2;
    float area, populacao, area2, populacao2;
    double dp, ppc, dp2, ppc2;
    double pib, pib2;
    
// Variáveis para a Lógica do Jogo
    int escolha1, escolha2;
    int pontos_carta1 = 0, pontos_carta2 = 0;
    
    // Variáveis para guardar nomes e valores para exibição
    char nome_attr1[50], nome_attr2[50];
    double val1_c1 = 0, val1_c2 = 0; // Valores do Atributo 1 (Carta 1, Carta 2)
    double val2_c1 = 0, val2_c2 = 0; // Valores do Atributo 2 (Carta 1, Carta 2)
    // Você pode utilizar o código do primeiro desafio
    // Cadastro das Cartas:
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    // utilizando a função scanf para capturar as entradas.
    // utilize o código do primeiro desafio
    // Exemplo:
    // printf("Digite o código da cidade: ");
    // scanf("%s", codigo);
// --- ETAPA 2: CADASTRO DAS CARTAS (REINTEGRADO) ---

// adicionado dados da carta 1
    printf("*** Cadastrando Cartas de Cidades do Brasil ***\n");
        printf("A seguir digite os Dados da Carta 1: \n");
    printf("Digite o Estado (Um caractere,Ex: Pernambuco = P): \n");
    scanf(" %c" , &Estado); 

    printf("Digite o codigo da carta (ex: P01): \n");
    scanf("%s", codigocarta);

    printf("Digite o nome da cidade (Apenas um nome): \n");
    scanf("%s" , Nomedacidade);

    printf("Digite número populacional da cidade(Apenas em números): \n");
    scanf("%f", &populacao);

    printf("Digite a área da cidade em km²(apenas em números): \n");
    scanf(" %f", &area);

    printf("Digite o PIB da cidade (Em bilhões, apenas o número): \n");
    scanf(" %lf", &pib);

    printf("Digite o número de pontos turísticos da cidade(Apenas números): \n");
    scanf(" %d", &numerodepontosturisticos);

    printf("\n...\n");
    printf("\nCarta Cadastrada Com Sucesso\n");
// adicionado dados da carta 2
printf("\n----------------------------------\n");
        printf("A seguir digite os Dados da Carta 2: \n");
    printf("Digite o Estado (Um caractere,Ex: Pernambuco = P): \n");
    scanf(" %c" , &Estado2);

    printf("Digite o codigo da carta (ex: P01): \n");
    scanf("%s", codigocarta2);

    printf("Digite o nome da cidade (Apenas um nome): \n");
    scanf(" %s" , Nomedacidade2);

    printf("Digite número populacional da cidade(Apenas em números): \n");
    scanf("%f", &populacao2);

    printf("Digite a área da cidade em km²(apenas o numeros): \n");
    scanf("%f", &area2);
    printf("Digite o PIB da cidade (em bilhões, apenas o número): \n");
    scanf("%lf", &pib2);
    printf("Digite o número de pontos turísticos da cidade(Apenas números): \n");
    scanf("%d", &numerodepontosturisticos2);
    printf("\n...\n");
    printf("\nCarta Cadastrada Com Sucesso\n");
    

// --- ETAPA 4: LÓGICA DO JOGO (DESAFIO FINAL) ---

    // 1. Menu Interativo (Escolha 1)
    printf("\n*** Escolha o PRIMEIRO Atributo ***\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de Pontos Turísticos\n");
    printf("5. Densidade Demográfica (Menor Vence!)\n");
    printf("\nDigite sua escolha (1-5): ");
    scanf("%d", &escolha1);
     
    // Validação básica da Escolha 1
    if (escolha1 < 1 || escolha1 > 5) {
        printf("Opção inválida! Encerrando.\n");
        return 1; // Encerra o programa se a primeira escolha for inválida
    }

    // 
    // (Repita para cada propriedade)

    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

    // Exemplo:
    // if (populacaoA > populacaoB) {
    //     printf("Cidade 1 tem maior população.\n");
    // } else {
    //     printf("Cidade 2 tem maior população.\n");
    // }

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);
    
    // 2. Menu Dinâmico (Escolha 2)
    printf("\n*** Escolha o SEGUNDO Atributo ***\n");
    // O menu só exibe opções que NÃO foram a escolha1
    if (escolha1 != 1) printf("1. População\n");
    if (escolha1 != 2) printf("2. Área\n");
    if (escolha1 != 3) printf("3. PIB\n");
    if (escolha1 != 4) printf("4. Número de Pontos Turísticos\n");
    if (escolha1 != 5) printf("5. Densidade Demográfica (Menor Vence!)\n");
    
    printf("\nDigite sua escolha: ");
    scanf("%d", &escolha2);

    // 3. Validação da Escolha 2 (Não pode ser inválida NEM repetida)
    while (escolha2 < 1 || escolha2 > 5 || escolha2 == escolha1) {
        if (escolha2 == escolha1) {
            printf("Erro: Você não pode escolher o mesmo atributo duas vezes!\n");
        } else {
            printf("Erro: Opção inválida!\n");
        }
        printf("Digite novamente: ");
        scanf("%d", &escolha2);
    }
    
    // 4. Processa a Escolha 1 (Calcula pontos e armazena valores/nomes)
    switch (escolha1) {
        case 1:
            strcpy(nome_attr1, "População");
            val1_c1 = populacao; val1_c2 = populacao2;
            pontos_carta1 += (populacao > populacao2) ? 1 : 0;
            pontos_carta2 += (populacao2 > populacao) ? 1 : 0;
            break;
        case 2:
            strcpy(nome_attr1, "Área (km²)");
            val1_c1 = area; val1_c2 = area2;
            pontos_carta1 += (area > area2) ? 1 : 0;
            pontos_carta2 += (area2 > area) ? 1 : 0;
            break;
        case 3:
            strcpy(nome_attr1, "PIB (bilhões)");
            val1_c1 = pib; val1_c2 = pib2;
            pontos_carta1 += (pib > pib2) ? 1 : 0;
            pontos_carta2 += (pib2 > pib) ? 1 : 0;
            break;
        case 4:
            strcpy(nome_attr1, "Pontos Turísticos");
            val1_c1 = numerodepontosturisticos; val1_c2 = numerodepontosturisticos2;
            pontos_carta1 += (numerodepontosturisticos > numerodepontosturisticos2) ? 1 : 0;
            pontos_carta2 += (numerodepontosturisticos2 > numerodepontosturisticos) ? 1 : 0;
            break;
        case 5:
            strcpy(nome_attr1, "Densidade (hab/km²)");
            val1_c1 = dp; val1_c2 = dp2;
            pontos_carta1 += (dp < dp2) ? 1 : 0; // Regra invertida
            pontos_carta2 += (dp2 < dp) ? 1 : 0; // Regra invertida
            break;
    }

    // 5. Processa a Escolha 2 (Calcula pontos e armazena valores/nomes)
    switch (escolha2) {
        case 1:
            strcpy(nome_attr2, "População");
            val2_c1 = populacao; val2_c2 = populacao2;
            pontos_carta1 += (populacao > populacao2) ? 1 : 0;
            pontos_carta2 += (populacao2 > populacao) ? 1 : 0;
            break;
        case 2:
            strcpy(nome_attr2, "Área (km²)");
            val2_c1 = area; val2_c2 = area2;
            pontos_carta1 += (area > area2) ? 1 : 0;
            pontos_carta2 += (area2 > area) ? 1 : 0;
            break;
        case 3:
            strcpy(nome_attr2, "PIB (bilhões)");
            val2_c1 = pib; val2_c2 = pib2;
            pontos_carta1 += (pib > pib2) ? 1 : 0;
            pontos_carta2 += (pib2 > pib) ? 1 : 0;
            break;
        case 4:
            strcpy(nome_attr2, "Pontos Turísticos");
            val2_c1 = numerodepontosturisticos; val2_c2 = numerodepontosturisticos2;
            pontos_carta1 += (numerodepontosturisticos > numerodepontosturisticos2) ? 1 : 0;
            pontos_carta2 += (numerodepontosturisticos2 > numerodepontosturisticos) ? 1 : 0;
            break;
        case 5:
            strcpy(nome_attr2, "Densidade (hab/km²)");
            val2_c1 = dp; val2_c2 = dp2;
            pontos_carta1 += (dp < dp2) ? 1 : 0; // Regra invertida
            pontos_carta2 += (dp2 < dp) ? 1 : 0; // Regra invertida
            break;
    }
    
    // 6. Exibição Clara do Resultado
    printf("\n\n--- Resultado da Rodada ---\n");
    printf("Atributos comparados: %s E %s\n", nome_attr1, nome_attr2);
    
    printf("\n--- Carta 1: %s (%c) ---\n", Nomedacidade, Estado);
    printf("%s: %.2f\n", nome_attr1, val1_c1);
    printf("%s: %.2f\n", nome_attr2, val2_c1);
    printf("Total de Pontos: %d\n", pontos_carta1);

    printf("\n--- Carta 2: %s (%c) ---\n", Nomedacidade2, Estado2);
    printf("%s: %.2f\n", nome_attr1, val1_c2);
    printf("%s: %.2f\n", nome_attr2, val2_c2);
    printf("Total de Pontos: %d\n", pontos_carta2);

    // 7. Tratamento de Empates e Declaração do Vencedor
    printf("\n--- Vencedor da Rodada ---\n");
    if (pontos_carta1 > pontos_carta2) {
        printf("Carta 1 (%s) venceu!\n", Nomedacidade);
    } else if (pontos_carta2 > pontos_carta1) {
        printf("Carta 2 (%s) venceu!\n", Nomedacidade2);
    } else {
        printf("Empate!\n");
    }
    printf("----------------------------------\n");

    return 0;
}
