/*Implemente um sistema simples de gerenciamento de alunos
em C. O programa dever� permitir ao usu�rio adicionar alunos com suas notas,
calcular a m�dia de cada aluno, exibir as informa��es dos alunos e mostrar o
aluno com a maior m�dia. Todo o sistema deve ser organizado por meio de
fun��es.

Requisitos:

Menu principal com op��es:
Adicionar aluno e notas.
Calcular e exibir a m�dia de cada aluno.
Exibir todos os alunos.
Exibir o aluno com maior m�dia.
Sair do programa.
Cada aluno ter� e .
Limitar o n�mero m�ximo de alunos para 10.
Fun��es para cada tarefa: adicionar alunos, calcular m�dia, exibir dados e encontrar o aluno com maior m�dia.
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
		printf("Qual a posi��o do aluno que deseja mostrar?\n");
		scanf("%d", &i);
	if(i <= totalAlunos){
		printf("Nome: %s || Media: %.2f\n", nomes[i], calcularMedia(i));
	}else{
		printf("Aluno n�o existente.!\n");
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
	printf("Aluno com maior m�dia �:\n Nome:%s || Media : %.2f\n", nomes[posicaoMaior], maiorMedia);
}

int main(){
	setlocale(LC_ALL, "portuguese");
	int op;
	
	do{
		printf("\n***** Menu Principal *****\n");
		printf("1 - Adicionar Aluno\n");
		printf("2 - Exibir Aluno e Media\n");
		printf("3 - Exibir todos os alunos e m�dias\n");
		printf("4 - Exibir maior m�dia\n");
		printf("5 - Sair\n");
		printf("\nEscolha uma op��o:\n");
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
				printf("Op��o inv�lida.");
		}		
	}while(op != 5);
}



