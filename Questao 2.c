#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

struct Professor{
	int codigo;
	char sexo[2];
	int horasDadas;
	int sexoNum;
	float salarioBruto;
	float desconto;
}professor[5];

int main() {
	setlocale(LC_ALL, "Portuguese");
	int i;
	int qtdHomens = 0;
	int qtdMulheres = 0;
	float salarioBrutoHomens, salarioBrutoMulheres;
	
	for(i = 0; i < 5; i++){
		printf("----- Tela Principal -----\n");
		printf("----- Professor %d -----\n\n", i + 1);
		
		printf("Digite o código do professor: ");
		scanf("%d",&professor[i].codigo);
		
		printf("\nSexo (M) Masculino - (F) Feminino: ");
		scanf("%s",&professor[i].sexo);
		
		if(strcmp(professor[i].sexo, "M") == 0 || strcmp(professor[i].sexo, "F") == 0 || strcmp(professor[i].sexo, "m") == 0 || strcmp(professor[i].sexo, "f") == 0){
			if(strcmp(professor[i].sexo, "M") == 0 || strcmp(professor[i].sexo, "m") == 0){
				professor[i].sexoNum = 1;
			}else{
				professor[i].sexoNum = 0;
			}
		}else{
			printf("Digite um sexo válido");
			i--;
			getch();
			system("cls");
			continue;
		}
		
		
		printf("\nDigite o número de horas dadas por aula: ");
		scanf("%d",&professor[i].horasDadas);
		
		professor[i].salarioBruto = (15 * professor[i].horasDadas) * 20;
		
		system("cls");
	}
	
	for(i = 0; i < 5; i++){
		if(professor[i].sexoNum == 1 && professor[i].horasDadas * 20 > 70){
			professor[i].desconto = professor[i].salarioBruto * 0.08;
			salarioBrutoHomens += professor[i].salarioBruto;
			qtdHomens++;
		}
		if(professor[i].sexoNum == 1 && professor[i].horasDadas * 20 <= 70){
			professor[i].desconto = professor[i].salarioBruto * 0.10;
			salarioBrutoHomens += professor[i].salarioBruto;
			qtdHomens++;
		}
		if(professor[i].sexoNum == 0 && professor[i].horasDadas * 20 > 70){
			professor[i].desconto = professor[i].salarioBruto * 0.05;
			salarioBrutoMulheres += professor[i].salarioBruto;
			qtdMulheres++;
		}
		if(professor[i].sexoNum == 0 && professor[i].horasDadas * 20 <= 70){
			professor[i].desconto = professor[i].salarioBruto * 0.07;
			salarioBrutoMulheres += professor[i].salarioBruto;
			qtdMulheres++;
		}
	}
	
	system("cls");
	printf("----- Resultado dos dados coletados -----\n\n");
	
	for(i = 0; i < 5; i++){
		printf("Professor %d\n\n", i + 1);
		printf("Código: %d\n", professor[i].codigo);
		printf("Salário bruto: %.2f\n", professor[i].salarioBruto);
		printf("Desconto: %.2f\n", professor[i].desconto);
		printf("Salário líquido: %.2f\n\n\n", professor[i].salarioBruto - professor[i].desconto);
	}
	
	getch();
	
	system("cls");
	
	printf("----- Média salárial masculina -----\n\n");
	printf("Média: %.2f\n", salarioBrutoHomens / qtdHomens);
	
	printf("\n\n----- Média salárial feminina -----\n\n");
	printf("Média: %.2f\n", salarioBrutoMulheres / qtdMulheres);
	
	printf("\n\nQtd Homens: %d\n", qtdHomens);
	printf("Qtd Mulheres: %d", qtdMulheres);
	
}
