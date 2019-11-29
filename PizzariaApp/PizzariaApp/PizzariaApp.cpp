#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// --- PROTOTIPOS--- //

void LimpaBuffer(); // -- Funcao para limpar o buffer --//
void tela000();  // -- Tela de Login --//
int tela001();  // -- Tela de Menu --//
int tela002(); // -- Tela de Pedido --//
void tela002novoPedido(); // -- Sub tela de pedido --//
void tela002pedidos(); // -- Sub tela de pedido --//
void inicializaPedido(); // -- Inicializa valores --//
int tela002clientes(); // -- Sub tela de pedido --//
int localizaPedido(int cod_pedido); 
int localizaCliente(int id_cliente);
int localizaProduto(int cod_produto);
void clientes(); // -- filtrar os clientes que serao localizados --//
void inicializaCliente(); // -- inicializa valores --//
void tela002novoCliente(); // -- Cadastrar novo cliente atraves da tela de pedidos --//
int tela003(); // -- Inicio da tela de produto --//
void estoque(); // -- Controla estoque de produtos --//
void tela003novoProduto(); // -- Tela para cadastro de novo produto --//
void inicializaProduto(); // -- inicializa valores -- //
int tela004(); // -- Tela de Usuarios --//
void tela004clientes(); // -- Gerenciamento de clientes --//
void colaboradores(); // -- Gerenciamento de colaboradores --//
int tela005(); // -- Tela para extracao de relatorios --//
void acompanhamentoGeral(); // -- tela para extracao do relatorio de acompanhamento geral --//
void despesa(); // -- tela para extracao do relatorio de despesas --//
void faturamento(); // -- tela para extracao do relatorio de faturamento --//

// -------------------------------------------- STRUCTS-------------------------------------------- //

//ponteiro para struct que armazena data e hora  
struct tm* data_hora_atual;

struct usuarios  // struct para login e senha do usuario da pizzaria
{
	char user[5];
	int pass;
	int unidade;

}mLoja[4];


struct cliente
{
	int unidade_pizzaria;
	int id_cliente;
	char nome[50];
	char endereco[50];
	char fone[20];

}mCliente[200];


struct pedido 
{
	int unidade_pizzaria;
	int cod_pedido;
	char nome[35];	
	char fone[20];
	char endereco[60];
	char descricao_produto[50];
	float total;
	int quantidade;

}mPed[500];

struct produto
{
	int unidade_pizzaria;
	int cod_produto;
	char descricao[50];
	float valor_venda;
	float valor_compra;
	int quantidade;

}mProd[100];

struct funcionarios {

	int unidade_pizzaria;
	int id_func;
	char nome[50];
	char endereco[50];
	char fone[50];
	char cargo[20];
	float salario;

}mFuncionario[100];

// ----------------------------------------------- INT MAIN ----------------------------------------------- //

int main()
{
	//funcoes para inicializar valores de variaveis
	inicializaPedido();
	inicializaProduto();
	inicializaCliente();

	//tela inicial do sistema
	tela000();

	return 0;
}

// ----------------------------------------------- FIM INT MAIN ----------------------------------------------- //


// --- FUNCOES--- //

void LimpaBuffer() {  // Funcao para limpar o buffer e evitar sujeiras
	char ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
}


void tela000() { // Tela - Login

	char log[5]; //Compara login com struct
	int senha = 0; //Compara senha com struct

	strcpy(mLoja[0].user, "leon"); 
	strcpy(mLoja[1].user, "luis");
	strcpy(mLoja[2].user, "jeff");
	strcpy(mLoja[3].user, "admn");

	mLoja[0].pass = 123456;
	mLoja[1].pass = 123456;
	mLoja[2].pass = 123456;
	mLoja[3].pass = 123456;

	mLoja[0].unidade = 1;
	mLoja[1].unidade = 2;
	mLoja[2].unidade = 3;

	

	//definir valor pro log
	strcpy(log, " ");

	LimpaBuffer();
	printf("\n\t======================== BEM VINDO ========================\n");
	printf("\n\t\t Digite seu login:\t");
	fgets(log, 5, stdin); //pega login
	printf("\n\t\t Digite sua senha:\t");
	scanf("%d", &senha);//pega senha
	printf("\n\n\t===========================================================\n");
	printf("\n\n\n\n\t** Lembre-se, seus dados cadastrais estao disponiveis no contrato de aquisicao\n"); 
	printf("\tde servicos fornecidos pela empresa @@@@@. \n");
	printf("\tCada unidade possui acesso exclusivo ao sistema integrado para gestao de processos.\n");
	printf("\tPara mais informacoes, contate o administrador do produto **\n\n");

	system("pause");

	if (strcmp(log, mLoja[0].user)==0)
	{
		if (senha == mLoja[0].pass)
		{
			system("cls");
			time_t segundos;
			time(&segundos);
			data_hora_atual = localtime(&segundos);
			printf("==========================================================");
			printf("\n\t Bem Vindo %s", log);
			printf("\n Unidade acessada: %d", mLoja[0].unidade);
			printf("\n Data de Acesso:  %d/", data_hora_atual->tm_mday);//dia
			printf("%d/", data_hora_atual->tm_mon + 1); //mês
			printf("%d", data_hora_atual->tm_year + 1900);//ano
			printf(" %d:", data_hora_atual->tm_hour);//hora
			printf("%d:", data_hora_atual->tm_min);//minuto
			printf("%d\n", data_hora_atual->tm_sec);//segundo  
			printf("\n==========================================================");
			printf("\n\n\n");
			system("pause");
			system("cls");
			tela001();
		}
		else
		{
			system("cls");
			printf("\n\t** Algo deu errado **\n\n Favor verificar os dados inseridos e realizar o acesso novamente");
			printf("\n Pressione ENTER para realizar o acesso\n\n\n");
			system("pause");
			system("cls");
			tela000();
		}
	}
	else if (strcmp(log, mLoja[1].user)==0)
	{
		if (senha == mLoja[1].pass)
		{
			system("cls");
			time_t segundos;
			time(&segundos);
			data_hora_atual = localtime(&segundos);
			printf("==========================================================");
			printf("\n\t Bem Vindo %s", log);
			printf("\n Unidade acessada: %d", mLoja[1].unidade);
			printf("\n Data de Acesso:  %d/", data_hora_atual->tm_mday);//dia
			printf("%d/", data_hora_atual->tm_mon + 1); //mês
			printf("%d", data_hora_atual->tm_year + 1900);//ano
			printf(" %d:", data_hora_atual->tm_hour);//hora
			printf("%d:", data_hora_atual->tm_min);//minuto
			printf("%d\n", data_hora_atual->tm_sec);//segundo  
			printf("\n==========================================================");
			printf("\n\n\n");
			system("pause");
			system("cls");
			tela001();
		}
		else
		{
			system("cls");
			printf("\n\t** Algo deu errado **\n\n Favor verificar os dados inseridos e realizar o acesso novamente");
			printf("\n Pressione ENTER para realizar o acesso\n\n\n");
			system("pause");
			system("cls");
			tela000();
		}
	}
	else if (strcmp(log, mLoja[2].user)==0)
	{
		if (senha == mLoja[2].pass)
		{
			system("cls");
			time_t segundos;
			time(&segundos);
			data_hora_atual = localtime(&segundos);
			printf("==========================================================");
			printf("\n\t Bem Vindo %s", log);
			printf("\n Unidade acessada: %d", mLoja[2].unidade);
			printf("\n Data de Acesso:  %d/", data_hora_atual->tm_mday);//dia
			printf("%d/", data_hora_atual->tm_mon + 1); //mês
			printf("%d", data_hora_atual->tm_year + 1900);//ano
			printf(" %d:", data_hora_atual->tm_hour);//hora
			printf("%d:", data_hora_atual->tm_min);//minuto
			printf("%d\n", data_hora_atual->tm_sec);//segundo
			printf("\n==========================================================");
			printf("\n\n\n");
			system("pause");
			system("cls");
			tela001();
		}
		else
		{
			system("cls");
			printf("\n\t** Algo deu errado **\n\n Favor verificar os dados inseridos e realizar o acesso novamente");
			printf("\n Pressione ENTER para realizar o acesso\n\n\n");
			system("pause");
			system("cls");
			tela000();
		}
	}
	else if (strcmp(log, mLoja[3].user) == 0)
	{
		if (senha == mLoja[3].pass)
		{
			system("cls");
			time_t segundos;
			time(&segundos);
			data_hora_atual = localtime(&segundos);
			printf("==========================================================");
			printf("\n\t Bem Vindo Administrador do Portal");
			printf("\n\nData de Acesso:  %d/", data_hora_atual->tm_mday);//dia
			printf("%d/", data_hora_atual->tm_mon + 1); //mês
			printf("%d", data_hora_atual->tm_year + 1900);//ano
			printf(" %d:", data_hora_atual->tm_hour);//hora
			printf("%d:", data_hora_atual->tm_min);//minuto
			printf("%d\n", data_hora_atual->tm_sec);//segundo
			printf("\n==========================================================");
			printf("\n\n\n");
			system("pause");
			system("cls");
			tela001();

		}

	}
	else
	{
		system("cls");
		printf("\n\t** Algo deu errado **\n\n Favor verificar os dados inseridos e realizar o acesso novamente");
		printf("\n Pressione ENTER para realizar o acesso\n\n\n");
		system("pause");
		system("cls");
		tela000();
	}


	printf("\n\n\n\n"); // para quebra de linha
	system("cls");
}



int tela001() // Tela - Menu
{
	int opcao;

	system("cls");

	do
	{
		printf("\n\t==== Tela Inicial da Pizzaria ===\n");
		printf("\n\t=  1 - Pedidos                  =");
		printf("\n\t=  2 - Produtos                 =");
		printf("\n\t=  3 - Usuarios                 =");
		printf("\n\t=  4 - Relaorio                 =");
		printf("\n\t=  0 - Logout                   =");
		printf("\n\t=================================");
		printf("\n\n\tDigite a opcao desejada:\t ");
		scanf("%d", &opcao);

		switch (opcao)
		{
			case 0: system("cls"); tela000(); break;
			case 1: system("cls"); tela002(); break;
			case 2: system("cls"); tela003(); break;
			case 3: system("cls"); tela004(); break;
			case 4: system("cls"); tela005(); break;
			default: printf("\nDigite uma opcao valida!\n\n"); system("pause"); system("cls"); tela001();
		}
	} while (opcao < 0 || opcao > 5);
	
	return opcao;
}


// ------------------------------------------------------- INICIO TELA DE PEDIDO --------------------------------------------------//

int tela002() { // layout completo de pedidos

	int opcao;

	do
	{
		printf("\n\t==== Tela de Pedido ==================================\n");
		printf("\n\t=  1 - Novos Pedidos                                 =");
		printf("\n\t=  2 - Pedidos                                       =");
		printf("\n\t=  3 - Filtrar Cliente / Cadastrar Novo Cliente      =");
		printf("\n\t=  0 - Retornar a Tela Inicial                       =");
		printf("\n\t======================================================");
		printf("\n\n\tDigite a opcao desejada:\t ");
		scanf("%d", &opcao);

		switch (opcao)
		{
			case 0: system("cls"); tela001(); break;
			case 1: system("cls"); tela002novoPedido(); break;
			case 2: system("cls");  tela002pedidos();  break;
			case 3: system("cls"); tela002clientes();  break;
			default: printf("\nDigite uma opcao valida!\n\n"); system("pause"); system("cls"); tela002();
		}
	} while (opcao < 0 || opcao > 3);
	
	return opcao;
}

void tela002novoPedido() { // cadastra pedido

	FILE* arq = NULL;
	int i = 0;

	int cod_pedido, posicao_pedido;
	system("cls");
	printf("\n===== Cadastro de Pedido =====\n\n");
	printf("\nDigite o cod_pedido a ser procurado: ");
	scanf("%d", &cod_pedido);
	posicao_pedido = localizaPedido(cod_pedido);
	if (posicao_pedido >= 0) //Localizou o pedido
	{
		//mostra os dados do pedido na tela
		printf("\n\tCodigo do Pedido: %d", mPed[posicao_pedido].cod_pedido);
		printf("\n\tUnidade Pedido: %d", mPed[posicao_pedido].unidade_pizzaria);
		printf("\n\tNome Cliente: %s", mPed[posicao_pedido].nome);
		printf("\n\tEndereco Cliente: %s", mPed[posicao_pedido].endereco);
		printf("\n\tFone: %s", mPed[posicao_pedido].fone);
		printf("\n\tSabor: %s", mPed[posicao_pedido].descricao_produto);
		printf("\n\tPreco de venda: %.2f", mPed[posicao_pedido].total);
		printf("\n\n");
		system("pause");
		system("cls");
		tela002();
	}
	else
	{
		system("cls");
		char cadastro;
		//deseja cadastrar?
		LimpaBuffer();
		printf("\tPedido nao localizado!");
		printf("\n\nDeseja cadastrar um novo pedido? (s/n): ");
		scanf("%c", &cadastro);
		if (cadastro == 's')
		{
			//caso positivo, entrar dados
			LimpaBuffer();
			mPed[-posicao_pedido].cod_pedido = cod_pedido;
			printf("\n\nDigite o nome do cliente: ");
			fgets(mPed[-posicao_pedido].nome, (sizeof(mPed[0].nome) / sizeof(char) - 1), stdin);
			LimpaBuffer();
			printf("\nDigite o endereco de entrega: ");
			fgets(mPed[-posicao_pedido].endereco,(sizeof(mPed[0].endereco) / sizeof(char) - 1), stdin);
			LimpaBuffer();
			printf("\nDigite o telefone para contato: ");
			fgets(mPed[-posicao_pedido].fone, (sizeof(mPed[0].fone) / sizeof(char) - 1), stdin);
			LimpaBuffer();
			printf("\nDigite o sabor: ");
			fgets(mPed[-posicao_pedido].descricao_produto, (sizeof(mPed[0].descricao_produto) / sizeof(char) - 1), stdin);
			printf("\nDigite a quantidade da pizza: ");
			scanf("%d", &mPed[-posicao_pedido].quantidade);
			printf("\nDigite a unidade utilizada: ");
			scanf("%d", &mPed[-posicao_pedido].unidade_pizzaria);
			printf("\nDigite o valor total do Pedido: ");
			scanf("%.2f", &mPed[posicao_pedido].total);

			printf("\n\n");
			system("pause");


			arq = fopen("C:\\Users\\Fabio\\Desktop\\file-pizza\\Pedidos.bin", "w+b");
			while (mPed[i].quantidade >= 0 && i < 100)
			{
				fwrite(&mProd[i], sizeof(struct pedido), 1, arq);
				i++;
			}fclose(arq);
			
			system("cls");
			tela002();
		}
		else
		{
			system("cls");
			printf("\tRetornando para a tela de pedido\n");
			system("\n\npause");
			system("cls");
			tela002();
		}
	}
}



void tela002pedidos() { // localiza pedido //

	int cod_pedido, posicao_pedido;
	int opcao, escolhe;

	printf("\t================ Localizar Pedidos / Detalhes =====================\n\n");
	printf("\n 1) Lista de Pedidos\n 2) Localizar Pedido\n 0) Retornar ao menu \n\nDigite a opcao desejada: ");
	scanf("%d", &escolhe);

	if (escolhe == 1)
	{
		system("cls");
		int i = 0;
		printf("======== Conteudo da tabela de Pedidos ========\n");

		while (i < 100 && mPed[i].quantidade > 0)
		{
			printf("\nCod Pedido: %d Produto: %s  Preco: %.2f  Cliente: %s  Endereco: %s  Fone: %s\n", mPed[i].cod_pedido ,mPed[i].descricao_produto, mPed[i].total, mPed[i].nome, mPed[i].endereco, mPed[i].fone);
			i++;
		}
		printf("\n\n");
		system("pause");
		system("cls");
		tela002pedidos();

	}
	else if(escolhe == 2){
			printf("\nDigite o cod_pedido a ser procurado: ");
		scanf("%d", &cod_pedido);
		posicao_pedido = localizaPedido(cod_pedido);
		if (posicao_pedido >= 0) //Localizou o pedido
		{
			//mostra os dados do pedido na tela
			printf("\nCodigo do Pedido: %d", mPed[posicao_pedido].cod_pedido);
			printf("\nUnidade Pedido: %d", mPed[posicao_pedido].unidade_pizzaria);
			printf("\nNome Cliente: %s", mPed[posicao_pedido].nome);
			printf("\nEndereco Cliente: %s", mPed[posicao_pedido].endereco);
			printf("\nFone: %s", mPed[posicao_pedido].fone);
			printf("\nSabor: %s", mPed[posicao_pedido].descricao_produto);
			printf("\nPreco de venda: %.2f", mPed[posicao_pedido].total);
			printf("\n\n");
			printf("\nPara retornar ao menu de pedido tecle 0 ou aperte 1 para localizar outro pedido:\t");
			scanf("%d", &opcao);
			printf("\n\n");
			system("pause");
			system("cls");
			tela002pedidos();
		}
		if (opcao == 0)
		{
			system("cls");
			tela002();
		}
		else {
			system("cls");
			tela002pedidos();
		}

	}
	else if (escolhe == 0) {
		system("cls");
		tela002();
	}
	else
	{
		printf("\n\nDigite uma opcao valida!\n");
		system("pause");
		system("cls");
		tela002pedidos();
	}
}


void inicializaPedido()
{
	int i;
	FILE* arq = NULL;

	//Inicializacao da matriz de pedidos
	for (i = 0; i < sizeof(mPed) / sizeof(struct pedido); i++) {
		if (i == 0)
			mPed[i].cod_pedido = 1;
		else
			mPed[i].cod_pedido = -1;

		mPed[i].total = 0.0;
		strcpy(mPed[i].nome, "");
		strcpy(mPed[i].endereco, "");
		strcpy(mPed[i].fone, "");
		strcpy(mPed[i].descricao_produto, "");
		mPed[i].unidade_pizzaria = 0;
		mPed[i].quantidade = 0;
	
	}

	arq = fopen("C:\\Users\\Fabio\\Desktop\\file-pizza\\Pedidos.bin", "rb");
	if (arq != NULL)
	{
		i = 0;
		while (!feof(arq) && i < 500)
		{
			fread(&mPed[i], sizeof(struct pedido), 1, arq);
			i++;
		}
		fclose(arq);
	}

	
	//trecho temporario de codigo, para cadastro inicial de alguns pedidos
	//Pedido 1
	mPed[0].cod_pedido = 1;
	mPed[0].total = 50.00;
	strcpy(mPed[0].nome, "Lucas Scaramelo");
	strcpy(mPed[0].endereco, "R Joao Vieira 80");
	strcpy(mPed[0].fone, "3333-4444");
	strcpy(mPed[0].descricao_produto, "Mussarela");
	mPed[0].quantidade = 2;
	mPed[0].unidade_pizzaria = 1;


	//Pedido 2
	mPed[1].cod_pedido = 2;
	mPed[1].total = 50.00;
	strcpy(mPed[1].nome, "Luis Sousa");
	strcpy(mPed[1].endereco, "R dos Bobos 0");
	strcpy(mPed[1].fone, "2222-6666");
	strcpy(mPed[1].descricao_produto, "Calabresa");
	mPed[1].quantidade = 2;
	mPed[1].unidade_pizzaria = 2;

	//Pedido 3
	mPed[2].cod_pedido = 3;
	mPed[2].total = 60.00;
	strcpy(mPed[2].nome, "Vinicius");
	strcpy(mPed[2].endereco, "R Junior Vilella 190");
	strcpy(mPed[2].fone, "9999-7777");
	strcpy(mPed[2].descricao_produto, "Portuguesa");
	mPed[2].quantidade = 2;
	mPed[2].unidade_pizzaria = 3; 

}

int localizaPedido(int cod_pedido) {
	int i = 0;
	while (i < sizeof(mPed) / sizeof(struct pedido) && mPed[i].cod_pedido != -1)
	{
		if (mPed[i].cod_pedido == cod_pedido)
			return i;
		i++;
	}

	if (mPed[i].cod_pedido == -1)
		return -i;

	return -32000; //Significa que a matriz de pedidos esta cheia e nao localizou o pedido pesquisado
}


//------------------------ clientes dentro do pedido ----- //

int tela002clientes() {

	system("cls");
	int op;
	do
	{
		printf("\n\t==== Filtrar Cliente / Cadastrar Novo Cliente  =======\n");
		printf("\n\t=  1 - Filtrar Cliente                               =");
		printf("\n\t=  2 - Cadastrar Cliente                             =");
		printf("\n\t=  0 - Retornar Tela de Pedido                       =");
		printf("\n\t=                                                    =");
		printf("\n\t= * Para consultar lista de clientes va para o menu  =");
		printf("\n\t=  de usuarios **                                    =");
		printf("\n\t======================================================");
		printf("\n\n\tDigite a opcao desejada:\t ");
		scanf("%d", &op);

		switch (op)
		{
			case 0: system("cls"); tela002(); break;
			case 1: system("cls"); clientes(); break;
			case 2: system("cls"); tela002novoCliente(); break;
			default: printf("\nDigite uma opcao valida!\n\n"); system("pause"); system("cls"); tela002clientes();
		}
	} while (op < 0 || op > 2);

	return op;
}

void clientes(){
	int id_cliente, posicao_cliente;
	int opcao;

	printf("\t================ Filtrar Cliente =====================\n\n");
	printf("\nDigite o cod_pedido a ser procurado: ");
	scanf("%d", &id_cliente);
	posicao_cliente = localizaCliente(id_cliente);
	if (posicao_cliente >= 0) //Localizou o pedido
	{

		//mostra os dados do pedido na tela
		printf("\nNome Cliente: %s", mCliente[posicao_cliente].nome);
		printf("\nEndereco Cliente: %s", mCliente[posicao_cliente].endereco);
		printf("\nFone: %s", mCliente[posicao_cliente].fone);
		printf("\nUnidade: %d", mCliente[posicao_cliente].unidade_pizzaria);

		printf("\n");
		printf("\nPara retornar ao menu de pedido tecle 0 ou aperte 1 para localizar outro cliente:");
		scanf("%d", &opcao);

		if (opcao == 0)
		{
			system("cls");
			tela002();
		}
		else {
			system("cls");
			clientes();
		}
	}

	system("pause");
}


void tela002novoCliente() { // cadastra cliente

	FILE* arq = NULL;
	int id_cliente, posicao_cliente;
	int i = 0;

	system("cls");
	printf("\n===== Cadastro de Novo Cliente =====\n\n");
	printf("\nDigite o Id a ser procurado: ");
	scanf("%d", &id_cliente);
	posicao_cliente = localizaCliente(id_cliente);
	if (posicao_cliente >= 0) //Localizou o cliente
	{
		//mostra os dados do cliente na tela
		printf("\nNome Cliente: %s", mCliente[posicao_cliente].nome);
		printf("\nEndereco Cliente: %s", mCliente[posicao_cliente].endereco);
		printf("\nFone: %s", mCliente[posicao_cliente].fone);
		printf("\nUnidade: %d", mCliente[posicao_cliente].unidade_pizzaria);
		printf("\n\n");
		system("pause");
		system("cls");
		clientes();
	}
	else
	{
		system("cls");
		char cadastro;
		//deseja cadastrar?
		LimpaBuffer();
		printf("\tCliente nao localizado!");
		printf("\n\nDeseja cadastrar um novo cliente? (s/n): ");
		scanf("%c", &cadastro);
		if (cadastro == 's')
		{
			//caso positivo, entrar dados
			LimpaBuffer();
			mCliente[-posicao_cliente].id_cliente = id_cliente;
			printf("\n\nDigite o nome do cliente: ");
			fgets(mCliente[-posicao_cliente].nome, (sizeof(mCliente[0].nome) / sizeof(char) - 1), stdin);
			LimpaBuffer();
			printf("\nDigite o endereco: ");
			fgets(mCliente[-posicao_cliente].endereco, (sizeof(mCliente[0].endereco) / sizeof(char) - 1), stdin);
			LimpaBuffer();
			printf("\nDigite o telefone: ");
			fgets(mCliente[-posicao_cliente].fone, (sizeof(mCliente[0].fone) / sizeof(char) - 1), stdin);
			printf("\nDigite a unidade da pizzaria que será cadastrado: ");
			scanf("%d", &mCliente[-posicao_cliente].unidade_pizzaria);


			arq = fopen("C:\\Users\\Fabio\\Desktop\\file-pizza\\Clientes.bin", "w+b");
			while (mCliente[i].id_cliente >= 0 && i < 500)
			{
				fwrite(&mCliente[i], sizeof(struct cliente), 1, arq);
				i++;
			}fclose(arq);

			system("cls");
			tela002();
		}
		else
		{
			system("cls");
			printf("\tRetornando para a tela de pedido\n");
			system("\n\npause");
			system("cls");
			tela002();
		}
	}
}

void inicializaCliente()
{
	int i;
	FILE* arq = NULL;

	//Inicializacao da matriz de cliente dentro da tela de pedidos
	for (i = 0; i < sizeof(mCliente) / sizeof(struct cliente); i++) {
		if (i == 0)
			mCliente[i].id_cliente = 1;
		else
			mCliente[i].id_cliente = -1;

		mCliente[i].unidade_pizzaria = 0;  //observar
		strcpy(mCliente[i].nome, "");
		strcpy(mCliente[i].endereco, "");
		strcpy(mCliente[i].fone, "");
		
	}

	arq = fopen("C:\\Users\\Fabio\\Desktop\\file-pizza\\Clientes.bin", "rb");
	if (arq != NULL)
	{
		i = 0;
		while (!feof(arq) && i < 200)
		{
			fread(&mCliente[i], sizeof(struct cliente), 1, arq);
			i++;
		}
		fclose(arq);
	}

	
	//trecho temporario de codigo, para cadastro inicial de alguns clientes
	//Cliente 1
	mCliente[0].id_cliente = 1;
	mCliente[0].unidade_pizzaria = 1;
	strcpy(mCliente[0].nome, "Lucas Scaramelo");
	strcpy(mCliente[0].endereco, "R Joao Vieira 80");
	strcpy(mCliente[0].fone, "4002-8922");


	//Cliente 2
	mCliente[1].id_cliente = 2;
	mCliente[1].unidade_pizzaria = 3;
	strcpy(mCliente[1].nome, "Luis Sousa");
	strcpy(mCliente[1].endereco, "R dos bobos 0");
	strcpy(mCliente[1].fone, "4002-8922");

	//Cliente 3
	mCliente[2].id_cliente = 3;
	mCliente[2].unidade_pizzaria = 2;
	strcpy(mCliente[2].nome, "Leornardo Rodrigues");
	strcpy(mCliente[2].endereco, "R Vieira 180");
	strcpy(mCliente[2].fone, "4002-8922");
}


int localizaCliente(int id_cliente) {
	int i = 0;
	while (i < sizeof(mCliente) / sizeof(struct cliente) && mCliente[i].id_cliente != -1)
	{
		if (mCliente[i].id_cliente == id_cliente)
			return i;
		i++;
	}

	if (mCliente[i].id_cliente == -1)
		return -i;

	return -32000;
}

// --------------------------------------- FIM TELAS DE PEDIDO ------------------------------------------------------------------------ //

// -----------------------------------------------------------------------------------------------------------------------------------//

// ------------------------------------------------------- INICIO TELA DE PRODUTO --------------------------------------------------//

int tela003() { // layout completo de produtos

	system("cls");
	int opcao;

	do
	{
		printf("\n\t==== Tela de Produtos ================================\n");
		printf("\n\t=  1 - Gerenciamento de Estoque                      =");
		printf("\n\t=  2 - Cadastrar Novo Produto                        =");
		printf("\n\t=  0 - Retornar a Tela Inicial                       =");
		printf("\n\t======================================================");
		printf("\n\n\tDigite a opcao desejada:\t ");
		scanf("%d", &opcao);

		switch (opcao)
		{
			case 0: system("cls"); tela001(); break;
			case 1: system("cls"); estoque(); break;
			case 2: system("cls"); tela003novoProduto(); break;
			default: printf("\nDigite uma opcao valida!\n\n"); system("pause"); system("cls"); tela003();
		}
	} while (opcao < 0 || opcao > 2);

	return opcao;
}

void estoque() {
	
	system("cls");
	int cod_produto;
	int op;


	printf("\n 1) Filtrar produto\n 2) Lista de Produtos\n 3) Retornar a tela de produtos \n\n\t Digite a opcao desejada:");
	scanf("%d", &op);

	if (op == 2)
	{
		// trazer resultado da struct produto
		int i = 0;
		printf("\n\n Conteudo da tabela de Produtos\n");

		while (i < 100 && mProd[i].quantidade > 0)
		{
			printf("\nProduto: %s\tQtde: %d\tUnidade: %d\tPreco:%.2f\tCusto: %.2f", mProd[i].descricao, mProd[i].quantidade,mProd[i].unidade_pizzaria,mProd[i].valor_compra, mProd[i].valor_venda);
			i++;
		}
		printf("\n\n");
		system("pause");
		system("cls");
		estoque();
	}
	else if(op == 1)
	{
		int opcao, posicao_produto;

		system("cls");
		printf("\nDigite o produto a ser procurado: ");
		scanf("%d", &cod_produto);
		posicao_produto = localizaProduto(cod_produto);
		if (posicao_produto >= 0) //Localizou o produto
		{
			//mostra os dados do produto na tela
			printf("\nDescricao: %s", mProd[posicao_produto].descricao);
			printf("\nQuantidade em Estoque: %d", mProd[posicao_produto].quantidade);
			printf("\nPreco de venda: %.2f", mProd[posicao_produto].valor_venda);
			printf("\nPreco de compra(gasto): %.2f", mProd[posicao_produto].valor_compra);
			printf("\nUnidade pizzaria: %d", mProd[posicao_produto].unidade_pizzaria);
			printf("\n");

			printf("\n\Para retornar ao menu de produtos tecle 0 ou\naperte 1 para gerenciamento de produtos:\t");
			scanf("%d", &opcao);
			if (opcao == 0)
			{
				system("cls");
				tela003();
			}
			else {
				system("cls");
				estoque();
			}

		}
		else
		{
			printf("\n Produto nao encontrado!");
			printf("\n\nPara retornar ao menu de produtos tecle 0 ou aperte 1 para gerenciamento de produtos:");
			scanf("%d", &opcao);
			if (opcao == 0)
			{
				system("cls");
				tela003();
			}
			else {
				system("cls");
				estoque();
			}
		}
		
	}
	else if (op == 3)
	{
		system("cls");
		tela003();
	}
	else
	{
		system("cls");
		printf("\n\t ** Favor selecionar uma opcao valida **\n");
		system("pause");
		estoque();
	}
}

void inicializaProduto()
{
	int i;
	FILE* arq = NULL;

	//Inicializacao da matriz de protudos
	for (i = 0; i < sizeof(mProd) / sizeof(struct produto); i++) {
		if (i == 0)
			mProd[i].cod_produto = 1;
		else
			mProd[i].cod_produto = -1;

		mProd[i].quantidade = 0;
		mProd[i].valor_compra = 0.0;
		mProd[i].valor_venda = 0.0;
		mProd[i].unidade_pizzaria = 0;
		strcpy(mProd[i].descricao, "");
	}

	arq = fopen("C:\\Users\\Fabio\\Desktop\\file-pizzaria\\Produtos.bin", "rb");
	if (arq != NULL)
	{
		i = 0;
		while (!feof(arq) && i < 100)
		{
			fread(&mProd[i], sizeof(struct produto), 1, arq);
			i++;
		}
		fclose(arq);
	}


	
	//trecho temporario de codigo, para cadastro inicial de alguns produtos
	//Produto 1
	mProd[0].cod_produto = 1;
	mProd[0].unidade_pizzaria = 2;
	mProd[0].valor_compra = 20.00;
	mProd[0].valor_venda = 25.00;
	mProd[0].quantidade = 50;
	strcpy(mProd[0].descricao, "Pizza de Calabresa");

	//Produto 2
	mProd[1].cod_produto = 2;
	mProd[1].unidade_pizzaria = 3;
	mProd[1].valor_compra = 20.00;
	mProd[1].valor_venda = 25.00;
	mProd[1].quantidade = 50;
	strcpy(mProd[1].descricao, "Pizza de Mussarela");


	//Produto 3
	mProd[2].cod_produto = 3;
	mProd[2].unidade_pizzaria = 1;
	mProd[2].valor_compra = 25.00;
	mProd[2].valor_venda = 30.00;
	mProd[2].quantidade = 50;
	strcpy(mProd[2].descricao, "Pizza de Calabresa");
	
}

void tela003novoProduto() { // cadastra produto

	FILE* arq = NULL;
	int i = 0;

	int cod_produto, posicao_produto;
	system("cls");
	printf("\n===== Cadastro de Produtos =====\n\n");
	printf("\nDigite o produto a ser procurado: ");
	scanf("%d", &cod_produto);
	posicao_produto = localizaProduto(cod_produto);
	if (posicao_produto >= 0) //Localizou o produto
	{
		//mostra os dados do produto na tela
		printf("\nDescricao: %s", mProd[posicao_produto].descricao);
		printf("\nQuantidade em Estoque: %d", mProd[posicao_produto].quantidade);
		printf("\nPreço de compra: %.2f", mProd[posicao_produto].valor_compra);
		printf("\nPreço de venda: %.2f", mProd[posicao_produto].valor_venda);
		printf("\nUnidade da pizzaria: %d", mProd[posicao_produto].unidade_pizzaria);
		printf("\n\n");
		system("pause");
		system("cls");
		tela003();
	}
	else
	{
		char cadastro;
		//deseja cadastrar?
		LimpaBuffer();
		printf("Produto nao encontrado. Deseja cadastrar? (s/n): ");
		scanf("%c", &cadastro);
		if (cadastro == 's')
		{
			//caso positivo, entrar dados
			LimpaBuffer();
			mProd[-posicao_produto].cod_produto = cod_produto;
			printf("\n\nDigite a descricao: ");
			fgets(mProd[-posicao_produto].descricao, (sizeof(mProd[0].descricao) / sizeof(char) - 1), stdin);
			printf("\nDigite a quantidade em estoque: ");
			scanf("%d", &mProd[-posicao_produto].quantidade);
			printf("\nDigite o preco de venda: ");
			scanf("%f", &mProd[-posicao_produto].valor_venda);
			printf("\nDigite o preco de compra(gasto para aderir o produto): ");
			scanf("%f", &mProd[-posicao_produto].valor_compra);
			printf("\nDigite a unidade em que o produto será cadastrado: ");
			scanf("%d", &mProd[-posicao_produto].unidade_pizzaria);

			while (mProd[i].quantidade >= 0 && i < 100)
			{
				arq = fopen("C:\\Users\\Fabio\\Desktop\\file-pizzaria\\Produtos.bin", "w+b");
				fwrite(&mProd[i], sizeof(struct produto), 1, arq);
				i++;
			}fclose(arq);


		}
		else
		{
			printf("\t Retornando para a tela de produto");
			system("\n\npause");
			system("cls");
			tela003();
		}

	}
	system("pause");

}



int localizaProduto(int cod_produto) {
	int i = 0;
	while (i < sizeof(mProd) / sizeof(struct produto) && mProd[i].cod_produto != -1)
	{
		if (mProd[i].cod_produto == cod_produto)
			return i;
		i++;
	}

	if (mProd[i].cod_produto == -1)
		return -i;

	return -32000; //Significa que a matriz de produtos esta cheia e nao localizou o produto pesquisado
}


// ------------------------------------------------------- FIM TELA DE PRODUTO --------------------------------------------------//
// ------------------------------------------------------------------------------------------------------------------------------//

// ------------------------------------------------------- INICIO TELA DE USUARIOS ----------------------------------------------//

int tela004() { // layout usuarios 
	
	int opcao;

	do
	{
		printf("\n\t==== Tela de Usuarios ================================\n");
		printf("\n\t=  1 - Lista de Clientes Todas Unidades              =");
		printf("\n\t=  2 - Colaboradores                                 =");
		printf("\n\t=  0 - Retornar a Tela Inicial                       =");
		printf("\n\t======================================================");
		printf("\n\n\tDigite a opcao desejada:\t ");
		scanf("%d", &opcao);

		switch (opcao)
		{
			case 0: system("cls"); tela001(); break;
			case 1: system("cls"); tela004clientes(); break;
			case 2: system("cls"); colaboradores(); break;
			default: printf("\nDigite uma opcao valida!\n\n"); system("pause"); system("cls"); tela004();
		}
	} while (opcao < 0 || opcao > 2);

	return opcao;
}


void tela004clientes() {

	system("cls");
	int op;

	printf("===== Lista Clientes =====");

	// trazer lista de clientes cadastrados na struct
	int i = 0;
	printf("\n\n Conteudo da tabela de Clientes\n");

	while (i < 500 && mCliente[i].id_cliente >= 0)
	{
		printf("\nNome: %s  fone: %s  Unidade: %d  Endereco: %s", mCliente[i].nome, mCliente[i].fone, mCliente[i].unidade_pizzaria, mCliente[i].endereco);
		i++;
	}

	printf("\n\n");
	system("pause");
	system("cls");
	tela004();

}

void colaboradores() {


}




// ------------------------------------------------------- FIM TELA DE USUARIOS ----------------------------------------------//

// ------------------------------------------------------------------------------------------------------------------------------//

// ------------------------------------------------------- INICIO TELA DE RELATORIOS ----------------------------------------------//

int tela005() { // Menu relatorios

	int opcao;

	do
	{
		printf("\n\t==== EXtracao de Relatorios ==========================\n");
		printf("\n\t=  1 - Acompanhamento Geral                          =");
		printf("\n\t=  2 - Relatorio de Despesas                         =");
		printf("\n\t=  3 - Relatorio de Faturamento                      =");
		printf("\n\t=  0 - Retornar a Tela Inicial                       =");
		printf("\n\t======================================================");
		printf("\n\n\tDigite o numero do relatorio a ser extraido:\t ");
		scanf("%d", &opcao);

		switch (opcao)
		{
		case 0: system("cls"); tela001(); break;
		case 1: system("cls"); acompanhamentoGeral(); break;
		case 2: system("cls"); despesa(); break;
		case 3: system("cls"); faturamento(); break;
		default: printf("\nDigite uma opcao valida!\n\n"); system("pause"); system("cls"); tela005();
		}
	} while (opcao < 0 || opcao > 3);

	return opcao;
}



void acompanhamentoGeral() {

	char unidade;
	int i = 0;
	int contador = 0;
	float totalLucro = 0.0;
	float totalDesp = 0.0;

	LimpaBuffer();
	printf("\t====== Relatorio de Acompanhamento Geral ======");
	printf("\n\nDeseja extrair o relatorio por unidade especifica? (s/n): ");
	scanf("%c", &unidade);
	if (unidade == 's')
	{
		int escolha;
		printf("\n\nDigite a unidade desejada: ");
		scanf("%d", &escolha);
		if (escolha == 1)
		{
			system("cls");
			printf("\n\n Relatorio Geral Unidade 1\n\n");

			while (i < sizeof(mPed) / sizeof(struct pedido) && mPed[i].unidade_pizzaria == 1)
			{
				printf("\nPedido: %s\tQtde: %d\tPreco:%.2f\tCliente: %s", mPed[i].descricao_produto, mPed[i].quantidade, mPed[i].total, mPed[i].nome);
				i++;
			}for (i = 0; i < sizeof(mPed) / sizeof(struct pedido); i++) //exibe valor total do lucro
			{
				totalLucro += mPed[i].quantidade * mPed[i].total;
			}
			printf("\n\n ======= Total: %.2f =======", totalLucro);
			printf("\n\n");
			system("pause");
			system("cls");
			tela005();
		}
		else if (escolha == 2)
		{
			system("cls");
			printf("\n\n Relatorio Geral Unidade 2\n\n");

			while (i < sizeof(mPed) / sizeof(struct pedido) && mPed[i].unidade_pizzaria == 2)
			{
				if (mPed[i].unidade_pizzaria == escolha)
				{
					printf("\nPedido: %s\tQtde: %d\tPreco:%.2f\tCliente: %s", mPed[i].descricao_produto, mPed[i].quantidade, mPed[i].total, mPed[i].nome);
					return i;
					i++;
				}
			}for (i = 0; i < sizeof(mPed) / sizeof(struct pedido); i++)
			{
				totalLucro += mPed[i].quantidade * mPed[i].total;
			}
			printf("\n ======= Total: %.2f =======", totalLucro);
			printf("\n\n");
			system("pause");
			system("cls");
			tela005();
		}
		else if (escolha == 3)
		{
			system("cls");
			printf("\n\n Relatorio Geral Unidade 3\n\n");

			while (mPed[i].unidade_pizzaria == 3)
			{
				printf("\nPedido: %s\tQtde: %d\tPreco:%.2f\tCliente: %s", mPed[i].descricao_produto, mPed[i].quantidade, mPed[i].total, mPed[i].nome);
				i++;
			}for (i = 0; i < sizeof(mPed) / sizeof(struct pedido); i++)
			{
				totalLucro += mPed[i].quantidade * mPed[i].total;
			}
			printf("\n ======= Total: %.2f =======", totalLucro);
			printf("\n\n");
			system("pause");
			system("cls");
			tela005();
		}
		else
		{
			printf("\n\nDigite uma opcao valida!\n\n");
			system("pause");
			system("cls");
			acompanhamentoGeral();
		}

	}
	else
	{
		//dados gerais
		system("cls");
		printf("====== Relatorio Geral ======\n\n");

		while (i < sizeof(mPed) / sizeof(struct pedido) && mPed[i].quantidade > 0)
		{
			printf("\nUnidade: %d Cod Pedido: %d   Preco: %.2f  Qntde: %d\n", mPed[i].unidade_pizzaria, mPed[i].cod_pedido, mPed[i].total, mPed[i].quantidade);
			i++;
			
		}for ( i = 0; i < sizeof(mPed) / sizeof(struct pedido); i++)
			{
			totalLucro += mPed[i].quantidade * mPed[i].total;
			}
		
		printf("\n ======= Total Faturado: %.2f =======", totalLucro);
		printf("\n\n\n");

		while (contador < sizeof(mProd) / sizeof(struct produto) && mProd[contador].quantidade > 0)
		{
			printf("\nUnidade: %d Cod Produto: %d   Preco Gasto: %.2f  Qntde: %d\n", mProd[contador].unidade_pizzaria, mProd[contador].cod_produto, mProd[contador].valor_compra, mProd[contador].quantidade);
			contador++;

		}for (i = 0; i < sizeof(mProd) / sizeof(struct produto); i++)
		{
			totalDesp += mProd[i].quantidade * mProd[i].valor_compra;
		}
		printf("\n ======= Total Despesas: %.2f =======", totalDesp);
		printf("\n\n");
		system("pause");
		system("cls");
		tela005();
	}

}



void despesa() {
	
	printf("\t=== Relatorio Geral de Despesas (Todas unidades) ===");
	 //soma entre dos valores: valor_compra(struct produto) + salario(struct funcionarios)

}

void faturamento() {
	printf("\t=== Relatorio Geral de Faturamento (Todas unidades) ===\n\n");
	//soma total do preco de todos os pedidos
	int i = 0;
	float total = 0.0;
	while (i < sizeof(mPed) / sizeof(struct pedido) && mPed[i].quantidade > 0)
	{
		printf("\nUnidade: %d Cod Pedido: %d  Preco: %.2f  Qntde: %d\n", mPed[i].unidade_pizzaria, mPed[i].cod_pedido, mPed[i].total, mPed[i].quantidade);
		i++;

	}for (i = 0; i < sizeof(mPed) / sizeof(struct pedido); i++)
	{
		total += mPed[i].quantidade * mPed[i].total;
	}

	printf("\n ======= Total de Faturamento Geral: %.2f =======", total);
	printf("\n\n");
	system("pause");
	system("cls");
	tela005();
}




