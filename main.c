//Autor: Leonardo Braga

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("*************************************\n");
    printf("* Bem-vindo ao Jogo de Adivinhação! *\n");
    printf("*************************************\n\n");

    int seg = time(0);
    srand(seg);
    int num = rand();

    int chute, maior, nivel;
    int acertou = 0;
    int numsecreto = num % 100;
    int cont, numtentativas, tentativas = 1;
    double pts = 500, ptsperd;

    while (nivel > 3 || nivel < 1){
        printf("Qual nível de dificuldade você deseja?\n");
        printf("(1) Fácil - (2) Médio - (3) Difícil\n");
        printf("Escolha: \n");
        scanf("%d", &nivel);

        if((nivel > 3)||(nivel < 1)) {
            printf("Escolha um número inteiro entre 1 e 3.\n\n");
            continue;
        }

        switch (nivel) {
            case 1:
                numtentativas = 20;
                break;

            case 2:
                numtentativas = 15;
                break;

            case 3:
                numtentativas = 10;
                break;
        }
    }

    for(cont = 1; cont <= numtentativas; cont++) {
        printf("Tentativa %d de %d.\n", tentativas, numtentativas);
        printf("Qual o seu chute?\n");
        scanf("%d", &chute);

        if(chute<0){
            printf("Você não pode chutar com números negativos. Tente novamente!\n\n");

            continue;
        }

        acertou = (chute == numsecreto);
        maior = chute > numsecreto;

        if(acertou) {
            break;
        }
        else if(maior)
            printf("Seu chute foi %d e maior que o número secreto!\n\n", chute);
        else
            printf("Seu chute foi %d e menor que o número secreto!\n\n", chute);

        tentativas++;

        ptsperd = abs(chute - numsecreto) / (double)2;
        pts = pts - ptsperd;
    }

    if(acertou) {
        printf("Fim de jogo! Parabéns, você acertou em %d tentativas!\n", tentativas);
        printf("Seu total de pontos foi %.1f.\n", pts);
    }
    else
        printf("Todas as tentativas utilizadas, você perdeu! Tente novamente!\n");

    return 0;
}