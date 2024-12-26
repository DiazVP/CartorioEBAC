#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()
{
	//in�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis
	
	printf("Digite o CPF a ser cadastrado:  ");
	scanf("%s", cpf); //%S refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //FILE existe na biblioteca: cria o arquivo
	file = fopen(arquivo, "w"); //w = write
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //a = atualizar
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //r = read
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel localizar o arquivo. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usur�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
	fclose(file);
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)//for entra depois das vari�veis, mas antes das instru��es
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("### Cart�rio da EBAC ###\n\n"); //In�cio menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o:  "); //Fim do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
		
		system("cls");
		
		switch(opcao) //inicio sele��o de menus
		{
			case 1: 
				registro(); //chamada de fun��es
				break;
				
			case 2:
				consulta();
				break;
			
			case 3:
				deletar();
				break;
				
			default:
				printf("Essa op�ao n�o est� dispon�vel!\n"); 
				system("pause");
				break;
				
		} //fim da sele��o
	}
}