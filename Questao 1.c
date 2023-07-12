#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

int i = 0;
char nomeMaiorMedia[40];
float maiorMedia;
float qtdAlunos, qtdAlunosReprovados;

struct aluno{
	char nome[40];
	char sexo[2];
	int matricula, frequencia, idade;
	float nota1, nota2;
	float media;
}aluno[5];

void calculaMedia(float nota1, float nota2, int i){
	float media;
	int frequencia;
	
	frequencia = aluno[i].frequencia;
	
	media = (nota1 + nota2) / 2;
	
	aluno[i].media = media;
	
	if(media > maiorMedia){
		strcpy(nomeMaiorMedia,aluno[i].nome);
		maiorMedia = media;
	}
	
	printf("Nome: %s\n",aluno[i].nome);
	printf("Média: %.2f\n",aluno[i].media);
	if(media >= 6 && frequencia >= 60){
		printf("Aprovado!!!\n\n");
	}else if(media < 6 || frequencia < 60){
		printf("Reprovado!\n\n");
		qtdAlunosReprovados++;
	}
}

void maiorMediafnc(){
	printf("A maior média da turma foi de %s com %.2f", nomeMaiorMedia, maiorMedia);
}

void resultado(){
	int q;
	for(q = 0; q < 5; q++){
		if(aluno[q].matricula != 0){
			calculaMedia(aluno[q].nota1, aluno[q].nota2, q);
			qtdAlunos++;
		}
	}
}

void switchOne(){
	setlocale(LC_ALL, "Portuguese");
	int escolha, opcao2;
	char fetchNome[40];
	int fetchMatricula;
	int sair = 1;
	int p;
	
	printf("\n\nDigite a opção desejada: ");
	scanf("%d",&escolha);
	
	switch(escolha){
		case 1:
			while(i < 5 && sair == 1){
				system("cls");
				printf("------- TELA DE CADASTRO DE ALUNOS -------\n");
				
				printf("\nNome do aluno: ");
				scanf("%s",&aluno[i].nome);
				
				fflush(stdin);
				
				printf("\nMatrícula do aluno: ");
				scanf("%d",&aluno[i].matricula);
				
				printf("\nIdade do aluno: ");
				scanf("%d",&aluno[i].idade);
				
				printf("\nSexo do aluno (M) ou (F): ");
				scanf("%s",&aluno[i].sexo);
				
				if(strcmp(aluno[i].sexo, "M") == 0 || strcmp(aluno[i].sexo, "F") == 0 || strcmp(aluno[i].sexo, "m") == 0 || strcmp(aluno[i].sexo, "f") == 0){
					
				}else{
					printf("Erro! Coloque um sexo válido: M ou F");
					getch();
					continue;
				}
				
				printf("\nFrequência do aluno: ");
				scanf("%d",&aluno[i].frequencia);
				
				printf("\n1 ° nota do aluno: ");
				scanf("%f",&aluno[i].nota1);
				
				printf("\n2 ° nota do aluno: ");
				scanf("%f",&aluno[i].nota2);
				i++;
				if(i == 5){
					printf("\nNúmero máximo de alunos cadastrados atingido!");
					getch();
					main();
				}else{
					printf("\n0 - Sair ou 1 - Cadastrar mais um aluno: ");
					scanf("%d",&sair);
					if(sair == 0){
						main();
					}
				}
			}
			if(i == 5){
				printf("\nNúmero máximo de alunos cadastrados atingido!");
				getch();
				main();
			}
			getch();
			main();
			break;
		case 2:
			system("cls");
			printf("------- TELA DE CADASTRO DE ALUNOS -------\n\n");
			printf("1 - Consultar aluno pelo nome\n");
			printf("2 - Consultar aluno pelo número da matrícula\n");
			printf("3 - Retornar ao menu principal");
			
			printf("\n\nDigite a opção desejada: ");
			scanf("%d",&opcao2);
			
			switch(opcao2){
				case 1:
					system("cls");
					printf("------- TELA DE CONSULTA POR NOME -------\n\n");
					printf("Digite o nome do aluno: ");
					scanf("%s",&fetchNome);
					
					for(p = 0; p < 5; p++){
						if(!strcmp(fetchNome, aluno[p].nome)){
							printf("\nAluno encontrado!!");
							printf("\nNome: %s",aluno[p].nome);
							printf("\nMatrícula: %d",aluno[p].matricula);
							printf("\nIdade: %d",aluno[p].idade);
							printf("\nSexo: %s",aluno[p].sexo);
							printf("\nNota A1: %.2f",aluno[p].nota1);
							printf("\nNota A2: %.2f",aluno[p].nota2);
							printf("\nFrequência: %d",aluno[p].frequencia);
							getch();
							menu();
						}
					}
					printf("\nAluno não cadastrado...");
					getch();
					main();
					break;
				case 2:
					system("cls");
					printf("------- TELA DE CONSULTA POR MATRÍCULA -------\n\n");
					printf("Digite a matrícula do aluno: ");
					scanf("%d",&fetchMatricula);
					
					for(p = 0; p < 5; p++){
						if(fetchMatricula == aluno[p].matricula){
							printf("\nAluno encontrado!!");
							printf("\nNome: %s",aluno[p].nome);
							printf("\nMatrícula: %d",aluno[p].matricula);
							printf("\nIdade: %d",aluno[p].idade);
							printf("\nSexo: %s",aluno[p].sexo);
							printf("\nNota A1: %.2f",aluno[p].nota1);
							printf("\nNota A2: %.2f",aluno[p].nota2);
							printf("\nFrequência: %d",aluno[p].frequencia);
							getch();
							menu();
						}
					}
					printf("\nAluno não cadastrado...");
					getch();
					main();
					break;
				case 3:
					main();
				default:
					printf("Digite uma opção válida!");
					getch();
					main();
			}
		case 3:
			system("cls");
			printf("------- RESULTADO DOS ALUNOS -------\n\n");
			if(aluno[0].matricula == 0){
				printf("Nenhum aluno cadastrado...");
				getch();
				main();
			}else{
				resultado();
				maiorMediafnc();
				printf("\n\nQtd. alunos total: %.0f\nAlunos reprovados: %.0f\n", qtdAlunos, qtdAlunosReprovados);
				printf("\n%.2f%% dos alunos reprovaram", qtdAlunosReprovados / qtdAlunos * 100);
				getch();
				exit(0);
			}
		default:
			printf("Digite uma opção válida!");
			getch();
			main();
	}
}

void menu(){
	system("cls");
	system("color f1");
	printf("------- BEM-VINDO A TELA PRINCIPAL -------\n\n");
	printf("1 - Cadastrar alunos\n");
	printf("2 - Consultar dados dos alunos\n");
	printf("3 - Sair");
	
	switchOne();
}

int main(){
	menu();
}







