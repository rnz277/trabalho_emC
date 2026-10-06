#include <stdio.h>

int main(void)
{
    int equipes;
    int jogos;
    int opacao = 0;
    int i;
    int vitorias;
    int empates;
    int derrotas;
    int pontos = 0;

    printf("Digite a quantidade de equipes de 1 a 10: ");
    scanf("%d", &equipes);

    printf("Digite a quantidade de jogos de 3 a 10: ");
    scanf("%d", &jogos);

    while (jogos < 3)
    {
        printf("Erro quantidade de jogos invalida!\n");
        printf("Digite novamente a quantidade de jogos de 3 a 10: ");
        scanf("%d", &jogos);
    }

    while (opacao != 5)
    {
        printf("\n===Campeonato em C===\n");
        printf("1- Registrar resultados do campeonato\n");
        printf("2- Mostrar resumo do campeonato\n");
        printf("3- Mostrar regulamento\n");
        printf("4- Simular campanha de uma equipe\n");
        printf("5- Encerrar sistema\n");

        printf("Escolha uma das opcoes: ");
        scanf("%d", &opacao);

    switch (opacao)
        {
        case 1:

            for (i = 1; i <= equipes; i++)
            {
                printf("\n===Registre os resultados da Equipe %d===\n", i);

                printf("Quantas vitorias este time obteve: \n");
                scanf("%d", &vitorias);

                printf("Quantos empates esta equipe obteve: \n");
                scanf("%d", &empates);

                printf("Quantas derrotas este time obteve: \n");
                scanf("%d", &derrotas);

                while (vitorias < 0 || empates < 0 || derrotas < 0 ||
                       vitorias + empates + derrotas != jogos)
                {
                    printf("\nErro! Os resultados nao correspondem");
                    printf(" a quantidade de jogos.\n");

                    printf("A equipe deve possuir exatamente %d jogos.\n", jogos);

                    printf("\nDigite novamente os resultados da Equipe %d\n", i);

                    printf("Vitorias: ");
                    scanf("%d", &vitorias);

                    printf("Empates: ");
                    scanf("%d", &empates);

                    printf("Derrotas: ");
                    scanf("%d", &derrotas);
                }

                /* Vitoria = 3, empate = 1, derrota = 0 */
                pontos = (vitorias * 3) + empates;

                printf("\n===A Equipe %d Fez===\n", i);

                printf("Vitorias: %d\n", vitorias);
                printf("Empates: %d\n", empates);
                printf("Derrotas: %d\n", derrotas);
                printf("e somou: %d pontos\n", pontos);

                if (pontos >= 15)
                {
                    printf("\nExcelente campanha\n");
                }
                else if (pontos >= 10 && pontos <= 14)
                {
                    printf("\nBoa campanha\n");
                }
                else if (pontos >= 5 && pontos <= 9)
                {
                    printf("\nCampanha regular\n");
                }
                else
                {
                    printf("\nCampanha ruim\n");
                }
            }

            break;
        case 5:
            printf("\nPrograma Encerrado\n");
            break;
        default:
            printf("\nOpcao ainda nao implementada.\n");
        }
    }
    return 0;
}