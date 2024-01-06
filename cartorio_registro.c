#include <stdio.h> //biblioteca de comunicação do usuário
#include <stdlib.h> //biblioteca de alocação de epaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h>//biblioteca responsável pelas strings


int inclusao() //função por cadastrar os usuários no sistema
{
	//início das variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cidade[40];
	//fim das variaveis
	
	printf("CPF: "); //coleta a informação do usuário
	scanf("%s", cpf); // %s é o armazenamento das strings	
	
	strcpy(arquivo, cpf); //responsavel por copiar o valor das strings
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w");//cria na pasta do projeto - w = whrite
	fprintf(file,cpf); // salva o valor da variável
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
		printf("CPF não localizado. \n");
	}	
	
	while (fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informações do usuário: ");
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
	file = fopen(cpf, "r"); // r é de read
	
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
	
		printf("---- Cartório da EBAC ---\n\n"); //início do enu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Inclusão de usuário\n");
		printf("\t2 - Consultar usuário\n");
		printf("\t3 - Deletar usuário\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //fim do menu	
	
		scanf("%d", &opcao);
	
		system("cls"); // responsável por limpar a tela
		
		switch (opcao)
		{
			case 1:
			inclusao();	// chamada de funções
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
			printf("Opção não disponível\n"); 
			system("pause");
			break;	//fim da seleção das opções
		} 
	
	}
}

