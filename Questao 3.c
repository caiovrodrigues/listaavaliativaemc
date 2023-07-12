#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char nomeMaiorMedia[50];
int matriculaMaiorMedia;
float maiorMedia;
float menorMedia = 999;
int alunosAprovados;
int alunosReprovados;
float alunosReprovadosFrequencia;

struct alunosCatolica{
	char nome[50];
	int matricula;
	float notaA1;
	float notaA2;
	float media;
	int frequencia;
	long int telefone;
	char sexo[2];
}aluno[5];

int main() {
	setlocale(LC_ALL,"Portuguese");
	int i;
	
	system("color f1");
		
	for(i = 0; i < 5; i++){
		system("cls");
		printf("----- CADASTRO DOS ALUNOS -----\n\n");
		
		printf("Digite o nome do aluno: ");
		scanf("%s",&aluno[i].nome);
		
		printf("\nMatrícula: ");
		scanf("%d",&aluno[i].matricula);
		
		printf("\nTelefone: ");
		scanf("%d",&aluno[i].telefone);
		
		printf("\nSexo (M) ou (F): ");
		scanf("%s",&aluno[i].sexo);
		
		if(strcmp(aluno[i].sexo, "M") == 0 || strcmp(aluno[i].sexo, "F") == 0 || strcmp(aluno[i].sexo, "m") == 0 || strcmp(aluno[i].sexo, "f") == 0){
			
		}else{
			printf("Sexo inválido!");
			i--;
			getch();
			continue;
		}
		
		printf("\nNota A1: ");
		scanf("%f",&aluno[i].notaA1);
		
		printf("\nNota A2: ");
		scanf("%f",&aluno[i].notaA2);
		
		printf("\nFrequência: ");
		scanf("%d",&aluno[i].frequencia);
		
		aluno[i].media = (aluno[i].notaA1 + aluno[i].notaA2) / 2;
		
		if(aluno[i].media > maiorMedia){
			maiorMedia = aluno[i].media;
			strcpy(nomeMaiorMedia, aluno[i].nome);
			matriculaMaiorMedia = aluno[i].matricula;
		}
		
		if(aluno[i].media < menorMedia){
			menorMedia = aluno[i].media;
		}
		
		if(aluno[i].frequencia < 60){
			alunosReprovadosFrequencia++;
		}
		
		if(aluno[i].media >= 6 && aluno[i].frequencia >= 60){
			alunosAprovados++;
		}else{
			alunosReprovados++;
		}
	}
	system("cls");
	for(i = 0; i < 5; i++){
		printf("Nome: %s\n",aluno[i].nome);
		printf("Matrícula: %d\n",aluno[i].matricula);
		printf("Frequência: %d\n",aluno[i].frequencia);
		printf("Média final: %.2f\n",aluno[i].media);
		if(aluno[i].media >= 6 && aluno[i].frequencia >= 60){
			printf("Aprovado!!\n\n");
		}
		if(aluno[i].media >= 6 && aluno[i].frequencia < 60){
			printf("Reprovado por frequência!\n\n");
		}
		if(aluno[i].media < 6 && aluno[i].frequencia >= 60){
			printf("Reprovado por média!\n\n");
		}
		if(aluno[i].media < 6 && aluno[i].frequencia < 60){
			printf("Reprovado por média e por frequência!\n\n");
		}
	}
	
	printf("\nA maior média da turma:\n");
	printf("Nome: %s\n",nomeMaiorMedia);
	printf("Matrícula: %d\n",matriculaMaiorMedia);
	printf("Média final: %.2f\n",maiorMedia);
	
	printf("\n\nAprovados: %d alunos\n", alunosAprovados);
	printf("Reprovados: %d alunos\n\n", alunosReprovados);
	
	printf("%.2f%% dos alunos foram reprovados por frequência", (alunosReprovadosFrequencia / 5) * 100);
}
