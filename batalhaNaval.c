#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    int tabuleiro[10][10] = {{0}};
    int tamanhotabuleiro = sizeof(tabuleiro)/sizeof(tabuleiro[0]);
    void mostratabuleiro(){
        printf("  A  B  C  D  E  F  G  H  I  J\n");
        for(int i = 0; i < tamanhotabuleiro; i++){
            printf("%d ", i);
            for(int j = 0; j < tamanhotabuleiro; j++){
                printf("%d  ", tabuleiro[i][j]);
            }
        printf("\n");
        }
    }
    // tipo := horizontal, vertical, diagonal1 (/), diagonal2 (\)
    void criaembarcacao(int tipo, int coordx, int coordy){
        switch(tipo)
        {
            case 0:
                if(coordx > 7) {
                    printf("erro\n");
                    break;
                }
                if(
                    tabuleiro[coordy][coordx] == 3 ||
                    tabuleiro[coordy][coordx + 1] == 3 ||
                    tabuleiro[coordy][coordx + 2] == 3
                ) {
                    printf("erro\n");
                    break;
                }
                tabuleiro[coordy][coordx] = 3;
                tabuleiro[coordy][coordx + 1] = 3;
                tabuleiro[coordy][coordx + 2] = 3;
                break;
            case 1:
                if(coordy > 7) {
                    printf("erro\n");
                    break;
                }
                if(
                    tabuleiro[coordy][coordx] == 3 ||
                    tabuleiro[coordy + 1][coordx] == 3 ||
                    tabuleiro[coordy + 2][coordx] == 3
                ) {
                    printf("erro\n");
                    break;
                }
                tabuleiro[coordy][coordx] = 3;
                tabuleiro[coordy + 1][coordx] = 3;
                tabuleiro[coordy + 2][coordx] = 3;
                break;
            case 2:
                if(coordy > 7 || coordx > 7) {
                    printf("erro\n");
                    break;
                }
                if(
                    tabuleiro[coordy][coordx] == 3 ||
                    tabuleiro[coordy - 1][coordx + 1] == 3 ||
                    tabuleiro[coordy - 2][coordx + 2] == 3
                ) {
                    printf("erro\n");
                    break;
                }
                tabuleiro[coordy][coordx] = 3;
                tabuleiro[coordy - 1][coordx + 1] = 3;
                tabuleiro[coordy - 2][coordx + 2] = 3;
                break;
            case 3:
                if(coordy < 3 || coordx > 7) {
                    printf("erro\n");
                    break;
                }
                if(
                    tabuleiro[coordy][coordx] == 3 ||
                    tabuleiro[coordy + 1][coordx + 1] == 3 ||
                    tabuleiro[coordy + 2][coordx + 2] == 3
                ) {
                    printf("erro\n");
                    break;
                }
                tabuleiro[coordy][coordx] = 3;
                tabuleiro[coordy + 1][coordx + 1] = 3;
                tabuleiro[coordy + 2][coordx + 2] = 3;
                break;
        }
    }
    criaembarcacao(3, 5, 5);
    criaembarcacao(2, 3, 3);
    criaembarcacao(0, 6, 2);
    criaembarcacao(1, 1, 4);

    mostratabuleiro();
    
    return 0;
}
