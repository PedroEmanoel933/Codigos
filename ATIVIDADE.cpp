#include <stdio.h>

int vetor[5];
int matriz[2][2];

int somaVetor() {
    int soma = 0;
    for(int i = 0; i < 5; i++) {
        soma += vetor[i];
    }
    return soma;    
}

void preencherMatriz(int valor) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            matriz[i][j] = valor;
        }
    }
}

void imprimirMatriz() {
    printf("Matriz 2x2 preenchida com a soma:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    for(int i = 0; i < 5; i++) {
        printf("Digite %dº valor: ", i+1);
		scanf("%d", &vetor[i]);
    }
    int soma = somaVetor();
    printf("Soma dos elementos do vetor: %d\n", soma);
    preencherMatriz(soma);
    imprimirMatriz();

}
