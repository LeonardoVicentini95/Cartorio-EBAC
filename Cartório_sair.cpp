#include <stdio.h> // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // Biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> // Biblioteca de aloca��o de texto por regi�o
#include <string.h> //Biblioteca repons�vel pela string

int registro () //fun��o responsavel por cadastrar usu�rio no sistema
{//inicia cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);// %s referese a strings
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores dos string
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa write
	fprintf(file,cpf); // Salvo o valor da vari�vel 
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); // cria o arquivo
	fprintf(file,nome); // Salvo o valor da vari�vel 
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta ()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Usu�rio n�o localizado\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:\n ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	remove(cpf);
	
	if(file == NULL)
	{
	printf("Usu�rio n�o encontrado.\n");
	system("pause");
	}
}

int main ()
{
	int opcao=0;	//Definindo as vari�veis 
	int laco=1;	
	char senhadigitada[]="a";
	int comparacao;
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
	
	printf("### Cart�rio da EBAC ###\n\n");
		
		system("cls");
	
		for(laco=1;laco=1;){
	
			system("cls");//responsavel por limpar a tela 
		
			printf("### Cart�rio da EBAC ###\n\n");//Iicio do menu
			printf("Escolha a op��o desejada no menu: \n\n");
			printf("\t1 Registrar nomes\n");
			printf("\t2 Consultar nomes\n");
			printf("\t3 Deletar nomes\n");
			printf("\t4 Sair do sistema\n\n");
			printf("Op��o: ");
	
			scanf("%d", &opcao);
	
			system("cls");//Fim do menu
		
			switch(opcao)
			{
				case 1:
				registro();//Chamada de fun��es 
				break;
			
				case 2:
				consulta();
				break;
			
				case 3:
				deletar();
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
				default:
				printf("Voc� escolheu uma op��o invalida\n");
				system("pause");
				break;
			}	//fim da sele��o 
		}
	}
