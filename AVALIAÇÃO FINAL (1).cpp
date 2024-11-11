#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "portuguese");
	int matriz[10][2], op, id, qtd, estoque;
	float vetor[10], valor;
	
	for(int i = 0; i<10; i++){
		for(int j = 0; j<1; j++){
			printf("\n%dº produto\nID: ", i+1);
			scanf("%d", &matriz[i][j]);
		} for(int j = 1; j<2; j++){
			printf("Quantidade: ");
			scanf("%d", &matriz[i][j]);
		} for(int j = 2; j<3; j++){
			printf("Preço: ");
			scanf("%f", &vetor[i]);
		}
	}
	do{
	printf("\n\nMENU:\n1. Exibir produtos\n2. Vender produtos\n3. Limpar tela\n0. Sair\nOpção selecionada: ");
	scanf("%d", &op);
	switch (op){
		case 1:
		for(int i = 0; i<10; i++){
		for(int j = 0; j<1; j++){
			printf("\n%dº produto\nID: %d", i+1, matriz[i][j]);
		} for(int j = 1; j<2; j++){
			if(matriz[i][j] < 3){
				printf("\nQuantidade: %d - Estoque baixo\n", matriz[i][j]);
			} else {
				printf("\nQuantidade: %d\n", matriz[i][j]);
			}
		} for(int j = 2; j<3; j++){
			printf("Preço: R$ %2.f\n", vetor[i]);
		}
	}
			break;
		case 2:
			printf("Digite o ID do produto desejado: ");
			scanf("%d", &id);
			printf("Digite o quantidade do produto desejado: ");
			scanf("%d", &qtd);
				for(int i = 0; i<10; i++){
					for(int j = 0; j<1; j++){
						if(id == matriz[i][j]){		
						printf("\n%dº produto\nID: %d", i+1, matriz[i][j]);
					for(int j = 2; j<3; j++){
							valor = vetor[i];}
					 for(int j = 1; j<2; j++){
						if(matriz[i][j] >= qtd){
							estoque = matriz[i][j] - qtd;
							matriz[i][j] = estoque;
							valor = qtd*valor;
							printf("\nVenda realizada.\nValor total: R$ %2.f\n", valor);
							printf("O estoque atual é %d.", estoque);
							
						} else if (matriz[i][j] <  qtd){
							printf("\nEstoque insuficiente.");
							
						} else if (matriz[i][j] <= 0) {
							printf("Estoque esgotado, venda não permitida.");
						}
						} 	
				
			}
		}
	}
			
				
		
		
			break;
		case 3:
			system("cls");
			break;
		case 0:
			printf("Espero ter ajudado, volte sempre :)");
			break;
		default:
		    printf("Opção Inválida, tente novamente!");
	}
    }while(op!=0);
}
