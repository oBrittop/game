#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define V 0      // vazio
#define P 1      // parede
#define S 2      // saida
#define Comida 3 // comida
#define TAM 25
#define LINHA 25
#define COLUNA 25

typedef struct
{
    int linha;
    int coluna;
    int pontos;
    int saiu;
} jogador_t;

int mapa[LINHA][COLUNA]; // Variavel global para o mapa

// declarando as funcoes
void monta_mapa(int linha, int coluna);

void funcaow(int key, jogador_t *hero, int mapa[LINHA][COLUNA]); // funcao q se move pra cima
void funcaoa(int key, jogador_t *hero, int mapa[LINHA][COLUNA]); // funcao q se move para esquerda
void funcaod(int key, jogador_t *hero, int mapa[LINHA][COLUNA]); // função q se move para direita
void funcaos(int key, jogador_t *hero, int mapa[LINHA][COLUNA]); // função q se move para baixo

int main(void)
{
    int *ptr = (int *)malloc(1* sizeof(int));
    if (ptr == NULL)
    {
       printf("Erro ao alocar memoria");
    }
    printf("Digite um numero de 1 a 40\n");
    scanf("%d", ptr);
   system("cls");// limpa a tela 
    jogador_t hero;
    // variaveis das  posiçoes iniciais, pontos e sau // sao os parametros da funcao monta_mapa
    hero.linha = 1;  // Posição inicial na linha
    hero.coluna = 1; // Posição inicial na coluna

    FILE *nivel1 = fopen("nivel1.txt", "r"); // Abri o arquivo nivel1

    if (nivel1 == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return 1;
    }
    int i = 0, j = 0;

    for (i = 0; i < LINHA; i++) // passa todas as linhas do aquivo para a matriz mapa
    {
        for (j = 0; j < COLUNA; j++) // passa todas as colunas do arquivo para a matriz mapa
        {
            if (fscanf(nivel1, "%d", &mapa[i][j]) == EOF) // faz parar quando chega no final
            {
                printf("Erro na leitura do arquivo no ponto (%d,%d)\n", i, j);
                break;
            }
        }
    }

    fclose(nivel1); // fecha arquivo 1 dps de passar os parametros pro mapa

    hero.pontos = 0; // Pontuação inicial
    hero.saiu = 0;   // Ainda não saiu//

    int opcoes, key;
    clock_t inicio; // variavel para guradar quando o time comeca a rodar

    system("cls"); // lipma a tela
    printf("-------------------------------------------\n");
    printf("Bem vindo ao labirinto em C!\n");
    printf("\n");
    printf("     \n TELA PRINCIPAL      \n");
    printf("\n");
    printf("      Selecione alguma opcao\n");
    printf("\n");
    printf("      Digite o numero corespondente:\n");
    printf("\n");
    printf("      1: Comecar novo jogo.\n      2: Como jogar.\n      3: Ver recordes.\n"); 
    printf("-------------------------------------------\n");
    scanf("%d", &opcoes);
   

    switch (opcoes)
    {
    case 1:
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");

        hero.coluna = hero.linha = 1; // posicoes iniciais
        monta_mapa(hero.linha, hero.coluna);

        inicio = clock(); // inicia o cronometro

        while (hero.saiu < 1)
        {
            key = getch();
            funcaow(key, &hero, mapa); // W
            funcaoa(key, &hero, mapa); // A
            funcaos(key, &hero, mapa); // S
            funcaod(key, &hero, mapa); // D

            system("cls"); // limpa a tela apos receber a movimentação
            printf("\n");
            printf("\n");
            printf("\n");
            monta_mapa(hero.linha, hero.coluna); // cria o mapa com o valor atualizado

        } //                                        final WHILE nivel1

        FILE *nivel2 = fopen("nivel2.txt", "r"); // Abri o arquivo2

        if (nivel2 == NULL)
        {
            printf("Erro ao abrir o arquivo");
            return 1;
        }
        int i2 = 0, j2 = 0;

        for (i2 = 0; i2 < LINHA; i2++)
        {
            for (j2 = 0; j2 < COLUNA; j2++)
            {
                if (fscanf(nivel2, "%d", &mapa[i2][j2]) == EOF) // faz parar quando chega no final
                {
                    printf("Erro na leitura do arquivo no ponto (%d,%d)\n", i2, j2);
                    break;
                }
            }
        }

        fclose(nivel2); // fecha arquivo 2 dps de passar os parametros pro mapa

        hero.linha = hero.coluna = 1; // posicoes iniciai
        hero.saiu = 0;                // variavel que para o loop

        monta_mapa(hero.linha, hero.coluna); // monta mapa nivel 2

        while (hero.saiu < 1) // while comeco nivel 2
        {
            key = getch();
            funcaow(key, &hero, mapa); // W
            funcaoa(key, &hero, mapa); // A
            funcaos(key, &hero, mapa); // S
            funcaod(key, &hero, mapa); // D
            system("cls");
            printf("\n");
            printf("\n");
            printf("\n");
            monta_mapa(hero.linha, hero.coluna);
        } //                                         fim whille nivel 2

        FILE *nivel3 = fopen("nivel3.txt", "r"); // Abri o nivel3

        if (nivel3 == NULL)
        {
            printf("Erro ao abrir o arquivo");
            return 1;
        }
        int l3 = 0, c3 = 0;

        for (l3 = 0; l3 < LINHA; l3++)
        {
            for (c3 = 0; c3 < COLUNA; c3++)
            {
                if (fscanf(nivel3, "%d", &mapa[l3][c3]) == EOF) // faz parar quando chega no final
                {
                    printf("Erro na leitura do arquivo no ponto (%d,%d)\n", l3, c3);
                    break;
                }
            }
        }

        fclose(nivel3); // fecha arquivo 3 dps de passar os parametros pro mata

        hero.linha = hero.coluna = 1; // posicoes iniciais
        hero.saiu = 0;
        monta_mapa(hero.linha, hero.coluna); // monta mapa nivel 3

        while (hero.saiu < 1) // while comeco nivel 3
        {
            key = getch();
            funcaow(key, &hero, mapa); // W
            funcaoa(key, &hero, mapa); // A
            funcaos(key, &hero, mapa); // S
            funcaod(key, &hero, mapa); // D

            system("cls"); // limpa a tela apos receber o valor
            printf("\n");
            printf("\n");
            printf("\n");
            monta_mapa(hero.linha, hero.coluna); // remonta o mapa com valor atualizado

        } //                                         //fim whille nivel 3

        FILE *nivel4 = fopen("nivel4.txt", "r"); //  Abri o arquivo4

        if (nivel4 == NULL)
        {
            printf("Erro ao abrir o arquivo");
            return 1;
        }
        int l4 = 0, c4 = 0;

        for (l4 = 0; l4 < LINHA; l4++)
        {
            for (c4 = 0; c4 < COLUNA; c4++)
            {
                if (fscanf(nivel4, "%d", &mapa[l4][c4]) == EOF) // faz parar quando chega no final
                {
                    printf("Erro na leitura do arquivo no ponto (%d,%d)\n", l4, c4);
                    printf("\n");
                    printf("\n");
                    printf("\n");
                    printf("\n");
                    break;
                }
            }
        }

        fclose(nivel4); // fecha o arquivo

        hero.linha = hero.coluna = 1; // posiçoes iniciais
        hero.saiu = 0;
        monta_mapa(hero.linha, hero.coluna);

        while (hero.saiu < 1) // while comeco nivel 4
        {
            key = getch();
            funcaow(key, &hero, mapa); // W
            funcaoa(key, &hero, mapa); // A
            funcaos(key, &hero, mapa); // S
            funcaod(key, &hero, mapa); // D

            system("cls"); // limpa a tela apos receber o valor
            printf("\n");
            printf("\n");
            printf("\n");
            monta_mapa(hero.linha, hero.coluna); // remonta o mapa com valor atualizado

        } //                                         // final do while nivel 4

        FILE *nivel5 = fopen("nivel5.txt", "r"); // Abri o arquivo5

        if (nivel5 == NULL)
        {
            printf("Erro ao abrir o arquivo");
            return 1;
        }
        int l5 = 0, c5 = 0;

        for (l5 = 0; l5 < LINHA; l5++)
        {
            for (c5 = 0; c5 < COLUNA; c5++)
            {
                if (fscanf(nivel5, "%d", &mapa[l5][c5]) == EOF) // faz parar quando chega no final
                {
                    printf("Erro na leitura do arquivo no ponto (%d,%d)\n", l5, c5);
                    printf("\n");
                    printf("\n");
                    printf("\n");
                    printf("\n");
                    break;
                }
            }
        }

        fclose(nivel5); // fecha o arquivo

        hero.linha = 15, hero.coluna = 12; // posiçoes iniciais
        hero.saiu = 0;
        monta_mapa(hero.linha, hero.coluna);

        while (hero.saiu < 1) // while comeco nivel 4
        {
            key = getch();
            funcaow(key, &hero, mapa);
            funcaoa(key, &hero, mapa);
            funcaos(key, &hero, mapa);
            funcaod(key, &hero, mapa);

            system("cls"); // limpa a tela apos receber o valor
            printf("\n");
            printf("\n");
            printf("\n");
            monta_mapa(hero.linha, hero.coluna); // remonta o mapa com valor atualizado

        } //           wihlle final nivel5
        system("cls");//limpa a tela 

        clock_t fim = clock();                                          // para cornometro
        double tempo_total = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // CLOCKS_PER_SEC indica quantos "clocks" correspondem a um segundo
        int pontos_total;
        pontos_total = ((hero.pontos + *ptr) - tempo_total) + 15 ;
        printf("-----------------------\n");
        printf("PARABENS\n");
        printf("Voce chegou no final\n");
        free(ptr); // libera a alocação dinamica 

        FILE *records = fopen("records.dat", "ab"); // abre o arquivo bin records

        if (records == NULL)
        {
            printf("Erro ao abrir pasta records\n");
            return 1;
        }
        // passa o endereço, quantos bytes gurada e a quatidade de copias, e o arquivo onde vai ser guradado
        size_t full_verifica_records = fwrite(&pontos_total, sizeof(int), 1, records);

        if (full_verifica_records == 1)
        {
            printf("Sucesso ao gravar sua pontuacao!\nvoce pode acessala em Records, na tela incial\n");
            printf("\n\n");
        }
        else
            printf("Erro ao adicionar pontos aos records!");
        fclose(records); //                   fecha a pasta de records

        printf("Voce foi um dos nosso melhores herois\n");
        printf("Sua pontuacao total eh [%d] pontos \n", pontos_total);
        printf("Seu tempo foi %2.2lf segundos\n", tempo_total);
        printf("-----------------------\n");

        system("pause");
        break;

    case 2:
    system("cls");// limpa a tela
        printf("\n");
        printf("\n");
        printf("\n");
        printf("Bem vindo ao labirinto em C\n\n");
        printf("Seu obejtivo e completar os 5 labirintos mais rapido possivel!\nQuantos mais pontos pegar mais alto sua pontuacao final!\n\n");
        printf("Ultilize 'w''a's'd' para se mover!\n");
        printf("Sobre  o mapa:\n");
        printf("Voce equivale a: $\n");
        printf("Ponotos equivale a: *\n");
        printf("Saida equivale a: =\n");
        printf("\n");
        printf("\n");
        printf("\n");
        break;

    case 3:
    {
        FILE *lrecords = fopen("records.dat", "rb");

        if (lrecords == NULL)
        {
            printf("Erro ao abrir o arquivo!");
        }
        printf("Todos as pontuacoes feita nessa maquina estaou aqui:\n");
        printf("Os pontos totais sao a quantidade de comida que voce pegou \nmais o numero que voce didgitou mais 15 menos o tempo que voce levou!\n");
        while (fread(&pontos_total, sizeof(int), 1, lrecords) == 1)
        {
            printf("Seus pontos totais sao: [%d]\n", pontos_total);
        }
        fclose(lrecords);
    }

    break;
    default:
        printf("Digite uma opçao valida!");
        break;
    }
    return 0;
}

void monta_mapa(int linha, int coluna)
{
    int l, c;
    for (l = 0; l < TAM; l++)
    {
        for (c = 0; c < TAM; c++)
        {
            if (l == linha && c == coluna)
            {
                printf("$"); // representa quem esta no labirinto
            }
            else
            {
                if (mapa[l][c] == V)
                {
                    printf(" "); // V = 0 Cria o espaço vazio
                }
                if (mapa[l][c] == S)
                {
                    printf("="); // S = 2 Cria a saida
                }
                if (mapa[l][c] == P)
                {
                    printf("%c", 219); // Caractere todo preenchido(parede)
                }
                if (mapa[l][c] == Comida)
                {
                    printf("%c", 43); // Comida
                }
            }
        }
        printf("\n");
    }
    printf("\n\n");
} // fim da função monta o mata

// função para se mover para cima
void funcaow(int key, jogador_t *hero, int mapa[LINHA][COLUNA])
{

    if (key == 'w' || key == 'W')
    {
        (hero->linha)--;
        if (mapa[hero->linha][hero->coluna] == P)
        {
            (hero->linha)++;
        }
        if (mapa[hero->linha][hero->coluna] == Comida)
        {
            (hero->pontos)++;
            mapa[hero->linha][hero->coluna] = V;
        }
        if (mapa[hero->linha][hero->coluna] == S)
        {
            (hero->saiu)++;
        }
    }
}
// funcao que se move para esquerda
void funcaoa(int key, jogador_t *hero, int mapa[LINHA][COLUNA])
{
    if (key == 'a' || key == 'A')
    {
        (hero->coluna)--;
        if (mapa[hero->linha][hero->coluna] == P)
        {
            (hero->coluna)++;
        }
        if (mapa[hero->linha][hero->coluna] == Comida)
        {
            (hero->pontos)++;
            mapa[hero->linha][hero->coluna] = V;
        }
        if (mapa[hero->linha][hero->coluna] == S)
        {
            (hero->saiu)++;
        }
    }
}

// função que se move para baixo
void funcaos(int key, jogador_t *hero, int mapa[LINHA][COLUNA])
{

    if (key == 's' || key == 'S')
    {
        if (hero->linha + 1 < LINHA)
        { // Verifica se está dentro do limite inferior
            (hero->linha)++;
            if (mapa[hero->linha][hero->coluna] == P)
            {
                (hero->linha)--; // Desfaz o movimento se encontrar uma parede
            }
            else if (mapa[hero->linha][hero->coluna] == Comida)
            {
                (hero->pontos)++;
                mapa[hero->linha][hero->coluna] = V; // Marca como vazio após pegar a comida
            }
            else if (mapa[hero->linha][hero->coluna] == S)
            {
                (hero->saiu)++; // Jogador encontrou a saída
            }
        }
    }
}

// função que se move para a direita
void funcaod(int key, jogador_t *hero, int mapa[LINHA][COLUNA])
{
    if (key == 'd' || key == 'D')
    {
        (hero->coluna)++;
        if (mapa[hero->linha][hero->coluna] == P)
        {
            (hero->coluna)--;
        }
        if (mapa[hero->linha][hero->coluna] == Comida)
        {
            (hero->pontos)++;
            mapa[hero->linha][hero->coluna] = V;
        }
        if (mapa[hero->linha][hero->coluna] == S)
        {
            (hero->saiu)++;
        }
    }
}
/// 500 linhas feitas apenas pelo Gustavo R Brito, com o auxilio do Chat GPT e chats do Dicord com ajuda de intusiastas da programação... 