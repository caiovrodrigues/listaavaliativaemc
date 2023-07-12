# Lista Avaliativa 3 em C - Strings e Função e Struct

1)	Faça um programa em C que apresente as seguintes opções no MENU PRINCIPAL:

	MENU PRINCIPAL
		
1 – Cadastrar alunos
2 – Consultar dados dos alunos
3 – Sair

* Quando a opção escolhida for Cadastrar alunos, o programa deverá cadastrar os seguintes dados: nome, matrícula, idade, sexo, nota de A1, nota de A2 e frequência [n° de aulas].    
	
	-> A cada aluno cadastrado, você deverá perguntar se deseja cadastrar outro aluno, caso negativo, retornar ao menu principal. Cadastrar no máximo 5 alunos !


* Quando a opção escolhida for Consultar dados dos alunos, o programa deverá oferecer outro menu:

1 – Consultar aluno pelo número da matrícula
2 – Consultar aluno pelo nome
3 – Retornar ao menu principal

-> Caso encontre, mostrar todos os dados do aluno, caso negativo, informar que ele não foi cadastrado.

Obs:

•	Você deverá utilizar strings e vetores para armazenar os dados dos alunos;

•	Você deverá criar as seguintes funções no programa acima:
1.	Para verificar se o sexo lido é M ou F; 
2.	Para calcular e retornar a média das notas lidas;
3.	Para verificar se o aluno foi aprovado ou reprovado. Para ser aprovado o aluno deve ter média final >= 6.0 e freqüência >= 60 aulas; Após o cálculo, escrever a resposta.
4.	Para verificar qual a maior média dos alunos cadastrados;
5.	Para calcular o percentual de alunos reprovados;
6.	Uma função para escrever os dados calculados nos ítens 4 e 5. 
   
A opção Sair é a única que permite sair do programa. Antes de sair do programa, você deverá chamar a função criada no item 6.



2)	Programa que lê o código, o sexo (M-Masculino e F-Feminino) e o  número de horas/aula dadas no mês dos professores de uma escola, sabendo que um professor ganha R$ 15,00 hora/aula e que a escola possui 5 professores.
Após a leitura, mostre:

a) Uma listagem contendo o código, o salário bruto, o desconto e o salário líquido de todos os professores;
b) A média aritmética dos salários brutos dos professores do sexo masculino;  
c) A média aritmética dos salários brutos dos professores do sexo feminino;
 Os descontos são assim calculados:

Sexo      Até 70 horas/aula ao mês     Mais que 70 horas/aula ao mês
M                10%                                 8%
F                 7%                                 5%      

3)	Faça um programa em C que leia os seguintes dados de cinco alunos da Faculdade Catolica: 
Nome, Número da matrícula, Telefone, Sexo (M ou F), Freqüência (nº de aulas freqüentadas) e as  duas notas (A1 e A2)


Calcule e mostre:
         
a)Para cada aluno, o nome, o número da matrícula, a freqüência, a média final e a mensagem 
(aprovado ou reprovado). Para ser aprovado a média final >= 6.0 e a frequência >= 60 aulas.

b)A maior e a menor média final da turma. 

c)O nome, número de matrícula e a média final, do aluno(a) com a maior média da turma.

d)O total de alunos aprovados e reprovados.

e)A percentagem de alunos reprovados por freqüência (para ser reprovado por freqüência, a freqüência deve ser menor que 60 aulas).
