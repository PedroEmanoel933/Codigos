/*Implemente um sistema simples de gerenciamento de alunos
em C. O programa deverá permitir ao usuário adicionar alunos com suas notas,
calcular a média de cada aluno, exibir as informações dos alunos e mostrar o
aluno com a maior média. Todo o sistema deve ser organizado por meio de
funções.

Requisitos:

Menu principal com opções:
Adicionar aluno e notas.
Calcular e exibir a média de cada aluno.
Exibir todos os alunos.
Exibir o aluno com maior média.
Sair do programa.
Cada aluno terá e .
Limitar o número máximo de alunos para 10.
Funções para cada tarefa: adicionar alunos, calcular média, exibir dados e encontrar o aluno com maior média.
*/
#include <stdio.h>
#include <string.h>
#include <locale.h>
#define MAX_ALUNOS 10

char nomes[MAX_ALUNOS][50];
float notas[MAX_ALUNOS][3];
int totalAlunos = 0;
void adicionarAluno(){
	if(totalAlunos >= MAX_ALUNOS){
		printf("Limite de Alunos Atingido!\n");
		return;
	}
	printf("Digite o nome do aluno: ");
	scanf(" %[^\n]", nomes[totalAlunos]);
	for(int i = 0; i < 3; i++){
		printf("Digite a nota %d: ", i+1);
		scanf("%f", &notas[totalAlunos][i]);
	}
	totalAlunos++;
	printf("Aluno Cadastrado!\n");
}
float calcularMedia(int index){
	float soma = 0;
	for(int i = 0; i < 3; i++){
		soma += notas[index][i];
	}	
	return soma / 3;
}
void exibirAlunos(){
	if(totalAlunos == 0){
		printf("Nenhum Aluno Cadastrado.\n");
		return;
	}
	printf("\nLista de Alunos: \n");
	for(int i = 0 ; i < totalAlunos; i++){
		printf("Nome: %s || Media: %.2f\n", nomes[i], calcularMedia(i));
	}
}
void exibirAlunoMedia(){
	int i = 0;
	if(totalAlunos == 0){
		printf("Nenhum Aluno Cadastrado.\n");
		return;
	}	
		printf("Qual a posição do aluno que deseja mostrar?\n");
		scanf("%d", &i);
	if(i <= totalAlunos){
		printf("Nome: %s || Media: %.2f\n", nomes[i], calcularMedia(i));
	}else{
		printf("Aluno não existente.!\n");
	}
}
void alunoMaiorMedia(){
	if(totalAlunos == 0){
		printf("nenhum aluno Cadastrado.\n");
		return;
	}
	int posicaoMaior = 0;
	float maiorMedia = calcularMedia(0);
	for(int i = 1; i < totalAlunos; i++){
		if(calcularMedia(i) > maiorMedia){
			maiorMedia = calcularMedia(i);
			posicaoMaior = i;
		}
	}
	printf("Aluno com maior média é:\n Nome:%s || Media : %.2f\n", nomes[posicaoMaior], maiorMedia);
}

int main(){
	setlocale(LC_ALL, "portuguese");
	int op;
	
	do{
		printf("\n***** Menu Principal *****\n");
		printf("1 - Adicionar Aluno\n");
		printf("2 - Exibir Aluno e Media\n");
		printf("3 - Exibir todos os alunos e médias\n");
		printf("4 - Exibir maior média\n");
		printf("5 - Sair\n");
		printf("\nEscolha uma opção:\n");
		scanf("%d", &op);		
		switch(op){
			case 1: 
				adicionarAluno();
				break;
			case 2: 
				exibirAlunoMedia();
				break;
			case 3: 
				exibirAlunos();
				break;
			case 4: 
				alunoMaiorMedia();
				break;
			case 5: 
				printf("Finalizando o programa...\n");
				break;
			default:
				printf("Opção inválida.");
		}		
	}while(op != 5);
}



