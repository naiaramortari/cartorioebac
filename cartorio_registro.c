#include <stdio.h> //biblioteca de comunica��o do usu�rio
#include <stdlib.h> //biblioteca de aloca��o de epa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h>//biblioteca respons�vel pelas strings


int inclusao() //fun��o por cadastrar os usu�rios no sistema
{
	//in�cio das vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cidade[40];
	//fim das variaveis
	
	printf("CPF: "); //coleta a informa��o do usu�rio
	scanf("%s", cpf); // %s � o armazenamento das strings	
	
	strcpy(arquivo, cpf); //responsavel por copiar o valor das strings
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w");//cria na pasta do projeto - w = whrite
	fprintf(file,cpf); // salva o valor da vari�vel
	fclose(file); //fechar o arquivo
	
	file= fopen(arquivo, "a"); //fopen = abrir o arquivo
	fprintf(file, ",");
	fclose(file);
	
	printf("Nome: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Cidade: ");
	scanf("%s", cidade);
	
	file = fopen(arquivo, "a");
	fprintf(file, cidade);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	system("pause");
	
}	

int consultar()
{
	
	setlocale(LC_ALL, "Portuguese"); //linguagem do programa
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("CPF n�o localizado. \n");
	}	
	
	while (fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);

	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // r � de read
	
	if(file == NULL)
	{
		printf("CPF deletado com sucesso!.\n");
		system("pause");
	}
}
	

int main ()
	{
	int opcao=0;
	int repeticao=1;
	
	for(repeticao=1;repeticao=1;)
	{
		system("cls");	
		
	
		setlocale(LC_ALL, "Portuguese"); //linguagem do programa
	
		printf("---- Cart�rio da EBAC ---\n\n"); //in�cio do enu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Inclus�o de usu�rio\n");
		printf("\t2 - Consultar usu�rio\n");
		printf("\t3 - Deletar usu�rio\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //fim do menu	
	
		scanf("%d", &opcao);
	
		system("cls"); // respons�vel por limpar a tela
		
		switch (opcao)
		{
			case 1:
			inclusao();	// chamada de fun��es
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigada por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Op��o n�o dispon�vel\n"); 
			system("pause");
			break;	//fim da sele��o das op��es
		} 
	
	}
}

