
#include <stdio.h>

int main(void)
{
    int equipes, jogos, opcao = 0, i;
    int vitorias, empates, derrotas, pontos;
    int equipesRegistradas = 0;
    int maiorPontuacao = 0;
    int melhorEquipe = 0;
    int simulacao;
    int somaPontos = 0;

    int vitoriasEquipe[10];
    int empatesEquipe[10];
    int derrotasEquipe[10];
    int pontosEquipe[10];

    printf("Digite a quantidade de equipes de 1 a 10: ");
    scanf("%d", &equipes);

    while (!(equipes >= 1 && equipes <= 10))
    {
        printf("Quantidade de equipes invalida!\n");
        printf("Digite novamente de 1 a 10: ");
        scanf("%d", &equipes);
    }

    printf("Digite a quantidade de jogos por equipe de 3 a 10: ");
    scanf("%d", &jogos);

    while (!(jogos >= 3 && jogos <= 10))
    {
        printf("Quantidade de jogos invalida!\n");
        printf("Digite novamente de 3 a 10: ");
        scanf("%d", &jogos);
    }

    while (opcao != 5)
    {
        printf("\n========== CAMPEONATO EM C ==========\n");
        printf("1 - Registrar resultados das equipes\n");
        printf("2 - Mostrar resultados por equipe\n");
        printf("3 - Mostrar regulamento\n");
        printf("4 - Simular campanha de uma equipe\n");
        printf("5 - Encerrar sistema\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:

            if (equipesRegistradas == equipes)
            {
                printf("\nTodas as equipes ja foram registradas!\n");
                break;
            }

            for (i = equipesRegistradas; i < equipes; i++)
            {
                printf("\n========== EQUIPE %d ==========\n", i + 1);

                printf("Quantidade de vitorias: ");
                scanf("%d", &vitorias);

                printf("Quantidade de empates: ");
                scanf("%d", &empates);

                printf("Quantidade de derrotas: ");
                scanf("%d", &derrotas);

                while (!(vitorias >= 0 &&
                         empates >= 0 &&
                         derrotas >= 0 &&
                         vitorias + empates + derrotas == jogos))
                {
                    printf("\nResultados invalidos!\n");
                    printf("A soma deve ser igual a %d jogos.\n", jogos);

                    printf("\nDigite novamente:\n");

                    printf("Vitorias: ");
                    scanf("%d", &vitorias);

                    printf("Empates: ");
                    scanf("%d", &empates);

                    printf("Derrotas: ");
                    scanf("%d", &derrotas);
                }

                pontos = (vitorias * 3) + empates;

                vitoriasEquipe[i] = vitorias;
                empatesEquipe[i] = empates;
                derrotasEquipe[i] = derrotas;
                pontosEquipe[i] = pontos;

                somaPontos += pontos;
                equipesRegistradas++;

                if (melhorEquipe == 0)
                {
                    maiorPontuacao = pontos;
                    melhorEquipe = i + 1;
                }
                else if (pontos > maiorPontuacao)
                {
                    maiorPontuacao = pontos;
                    melhorEquipe = i + 1;
                }

                printf("\n===== RESULTADO DA EQUIPE %d =====\n", i + 1);
                printf("Jogos: %d\n", jogos);
                printf("Vitorias: %d\n", vitorias);
                printf("Empates: %d\n", empates);
                printf("Derrotas: %d\n", derrotas);
                printf("Pontos: %d\n", pontos);

                if (pontos >= 15)
                {
                    printf("Excelente campanha!\n");
                }
                else if (pontos >= 10 && pontos <= 14)
                {
                    printf("Boa campanha!\n");
                }
                else if (pontos >= 5 && pontos <= 9)
                {
                    printf("Campanha regular!\n");
                }
                else
                {
                    printf("Campanha ruim!\n");
                }
            }

            printf("\nTodas as equipes foram registradas!\n");
            break;

        case 2:

            printf("\n========== RESULTADOS POR EQUIPE ==========\n");

            if (equipesRegistradas == 0)
            {
                printf("Nenhuma equipe foi registrada ainda!\n");
            }
            else
            {
                printf("\nQuantidade de equipes: %d\n", equipesRegistradas);
                printf("Quantidade de jogos por equipe: %d\n", jogos);

                printf("\n%-8s %-7s %-10s %-9s %-10s %-8s\n",
                       "Equipe", "Jogos", "Vitorias",
                       "Empates", "Derrotas", "Pontos");

                printf("---------------------------------------------------------\n");

                for (i = 0; i < equipesRegistradas; i++)
                {
                    printf("%-8d %-7d %-10d %-9d %-10d %-8d\n",
                           i + 1,
                           jogos,
                           vitoriasEquipe[i],
                           empatesEquipe[i],
                           derrotasEquipe[i],
                           pontosEquipe[i]);
                }

                printf("---------------------------------------------------------\n");

                printf("\nSoma dos pontos: %d\n", somaPontos);

                printf("Media de pontos por equipe: %.2f\n",
                       (float)somaPontos / equipesRegistradas);

                printf("\n========== MELHOR CAMPANHA ==========\n");
                printf("Equipe: %d\n", melhorEquipe);
                printf("Pontuacao: %d\n", maiorPontuacao);
            }

            break;

        case 3:

            printf("\n========== REGULAMENTO ==========\n");

            printf("\nPontuacao:\n");
            printf("Vitoria: 3 pontos\n");
            printf("Empate: 1 ponto\n");
            printf("Derrota: 0 pontos\n");

            printf("\nRegras:\n");
            printf("Quantidade de equipes: 1 a 10\n");
            printf("Quantidade de jogos por equipe: 3 a 10\n");
            printf("A soma de vitorias, empates e derrotas\n");
            printf("deve ser igual a quantidade de jogos.\n");

            printf("\nClassificacao das campanhas:\n");
            printf("15 pontos ou mais: Excelente campanha\n");
            printf("10 a 14 pontos: Boa campanha\n");
            printf("5 a 9 pontos: Campanha regular\n");
            printf("Menos de 5 pontos: Campanha ruim\n");

            break;

        case 4:

            printf("\n========== SIMULACAO DE CAMPANHA ==========\n");

            printf("Quantidade de jogos: %d\n", jogos);

            printf("\nDigite a quantidade de vitorias: ");
            scanf("%d", &vitorias);

            printf("Digite a quantidade de empates: ");
            scanf("%d", &empates);

            printf("Digite a quantidade de derrotas: ");
            scanf("%d", &derrotas);

            while (!(vitorias >= 0 &&
                     empates >= 0 &&
                     derrotas >= 0 &&
                     vitorias + empates + derrotas == jogos))
            {
                printf("\nResultados invalidos!\n");
                printf("A soma deve ser igual a %d jogos.\n", jogos);

                printf("\nDigite novamente:\n");

                printf("Vitorias: ");
                scanf("%d", &vitorias);

                printf("Empates: ");
                scanf("%d", &empates);

                printf("Derrotas: ");
                scanf("%d", &derrotas);
            }

            simulacao = (vitorias * 3) + empates;

            printf("\n========== RESULTADO DA SIMULACAO ==========\n");

            printf("Vitorias: %d\n", vitorias);
            printf("Empates: %d\n", empates);
            printf("Derrotas: %d\n", derrotas);
            printf("Pontos: %d\n", simulacao);

            if (simulacao >= 15)
            {
                printf("Excelente campanha!\n");
            }
            else if (simulacao >= 10 && simulacao <= 14)
            {
                printf("Boa campanha!\n");
            }
            else if (simulacao >= 5 && simulacao <= 9)
            {
                printf("Campanha regular!\n");
            }
            else
            {
                printf("Campanha ruim!\n");
            }

            break;

        case 5:

            printf("\nPrograma encerrado!\n");
            break;

        default:

            printf("\nOpcao invalida!\n");
            break;
        }
    }

    return 0;
}
