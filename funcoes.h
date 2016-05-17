/*FUN��ES DO SISTEMA DE CONTROLE DE ESTOQUE
-----------------------------------------------



DESENVOLVEDORES:

-
-
-
- WENDERSON J�NIO

LEGENDA:
- produto *p = vetor dos produtos em estoque
- int n = vari�vel da quantidade de produtos cadastrados at� o momento

*/

// --------------
//BIBLIOTECAS AUXILIARES
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

using namespace std;

//STRUCT DE PRODUTO
struct Produto
{
    unsigned int cod;
    char descricao[1000];
    char nome[1000];
    long double preco;
    unsigned int quant;

};


// --------------

/* --> SUM�RIO DE FUN�OES:
-Menu
-Inicial
-ListarTodos
-BaixoEstoque
-ValorTotal
-Remover
-Fun��es que mudam:
    -Codigo
    -Nome
    -Quantidade
    -Preco
    -Descri��o
-Ordenar
-Cadastrar
-MenuEditar
-Editar
-Buscar
-
-
-
-
-

*/


//--------------------------------------------------------------------------------------------------------

//MENU - RECEBE ENTRADA DO OP��O DO USU�RIO, MAS A CHAMADA DA FUN��O � FEITA NO 'MAIN'
int Menu(){

    int op = 0;
    char aux[100];

    do{
        cout << "\n\t\tMENU"
             <<"\nEscola a op��o: "
             <<"\n1 - Cadastrar"
             <<"\n2 - Editar/Alterar Produto"
             <<"\n3 - Buscar Produto"
             <<"\n4 - Remover Produto"
             <<"\n5 - Listar Todos os Produtos"
             <<"\n6 - Listar Todos os Produtos com Baixo Estoque"
             <<"\n7 - Total de Produtos e Valor Total"
             <<"\n8 - Limpar Tela"
             <<"\n0 - Sair"
             <<"\nOp��o: ";
         cin >> aux;

        op = atoi(aux);
    }while(op < 0 || op > 8);


    return op;
}

//--------------------------------------------------------------------------------------------------------

//MENSAGEM DA TELA INICIAL

void Inicial(){

    cout<<"\n"<<endl;

    cout<<"\n     -------  -------   -         --------  -------   -------            -------"
        <<"\n    /        /      /  / |     /     /     /      /  /      /  /        /"
        <<"\n   /        /      /  /  |    /     /     /      /  /      /  /        /"
        <<"\n  /        /      /  /   |   /     /     /______/  /      /  /        /----"
        <<"\n /        /      /  /    |  /     /     /   |     /      /  /        /"
        <<"\n/        /      /  /     | /     /     /    |    /      /  /        /"
        <<"\n-------  -------  /      |/     /     /     |    ------    -------  -------";
    cout<<"\n"<<endl;

    cout<<"\n\t\t\t   ----------  -------"
        <<"\n\t\t\t      /     / /"
        <<"\n\t\t\t     /     / /"
        <<"\n\t\t\t    /     / /---"
        <<"\n\t\t\t   /     / /"
        <<"\n\t\t\t  /     / /"
        <<"\n\t\t\t--------  -------";
    cout<<"\n"<<endl;

    cout<<"\n     -------  -------  ---------  ---------   ---------               -------"
        <<"\n    /        /            /      /        /  /        /  /        /  /"
        <<"\n   /        /            /      /        /  /        /  /        /  /"
        <<"\n  /---      -------     /      /        /  /        /  /        /  /----"
        <<"\n /                /    /      /        /  /  ___   /  /        /  /"
        <<"\n/                /    /      /        /  /  /   | /  /        /  /"
        <<"\n-------  -------     /       --------   --------|-   --------    -------";

    cout<<"\n"<<endl;

    system ("pause");
    system ("cls");
}

//--------------------------------------------------------------------------------------------------------

//LISTAR TODOS OS PRODUTOS
void ListarTodos(Produto * p, int n)
{

    cout << "\n\tPRODUTOS EM ESTOQUE:";

    for(int i = 0; i < n; i++) //
    {
        cout << "\n\nC�digo do produto:\t" << p[i].cod
             << "\nNome do produto:\t" << p[i].nome
             << "\nDescri��o do produto:\t" << p[i].descricao
             << "\nQuantidade:\t" << p[i].quant
             << "\nPre�o:\t" << p[i].preco;
    }
    cout << "\n";
    system("PAUSE");
}

//--------------------------------------------------------------------------------------------------------

// LISTAR PRODUTOS COM BAIXO ESTOQUE
void BaixoEstoque (Produto *p, int n)
{

    for (int i=0; i < n ;  i++)
    {
        if (p[i].quant < 10)
        {
            cout<<"\nO produto de codigo "<<p[i].cod<< " " << "nome "<< p[i].nome << "possui" << p[i].quant  << " produtos no estoque";
        }

        else
        {
            cout << "\nN�o existem produtos com baixo estoque.";
        }

    }

    system("PAUSE");
}

//--------------------------------------------------------------------------------------------------------

//Valor total em estoque.
void ValorTotal(Produto *p, int n)
{
    int soma = 0, produto = 0;

    //Valor total dos produtos no estoque
    for(int i=0; i < n ; i++)
    {
        produto = p[i].quant * p[i].preco;
        soma = produto + soma;
    }

    cout<<"\n O valor total(pre�o) de produtos no estoque �: " << soma << "\n";
}

//--------------------------------------------------------------------------------------------------------

//Total de produtos no estoque
void TotalProdutos (Produto *p, int n){
    int soma = 0;

    for(int i=0; i < n ; i++)
    {

        soma += p[i].quant;
    }

    cout << "\n\tTOTAL EM ESTOQUE\n";
    cout<<"\n O total de produtos no estoque �: "<< soma;

    ValorTotal(p, n);

    system("PAUSE");

}


//--------------------------------------------------------------------------------------------------------

//Fun��o que remove um produto
void Remover(Produto *p)
{
    int z, op; // "z" � o indice do produto

    cout << "\n\tREMOVER\n";

    z = BuscarIndice(p);

    if(z > -1)
    {

        //Mostra as informa��es do produto antes de oferecer confirma��o da remo��o
        cout << "\nC�digo: " << p[z].cod
             << "\nNome: " << p[z].nome
             << "\nDescri��o: " << p[z].descricao
             << "\nPre�o: " <<  p[z].preco
             << "\nQuantidade: " <<  p[z].quant;

        //CONFIRMA��O
        cout << "\n\nConfirme a remo��o:"
             <<"\n1. CONFIRMAR"
             <<"\n2. CANCELAR"
             <<"\nOp��o: ";
        cin >> op;

        if(op == 1)
        {
            //IR� ZERAR TODOS OS VALORES PARA O PRODUTO
            p[z].cod = 0;
            p[z].quant = 0;
            p[z].preco = 0;
            strcpy(p[z].nome, "");

            Ordenar(p);
        }
        else cout << "\nCancelado.";

    }
    else cout << "\nProduto n�o encontrado.";

}

//--------------------------------------------------------------------------------------------------------

//-->FUN��ES QUE "MUDAM ... "
/*
SUM�RIO
-Codigo
-Nome
-Quantidade
-Preco
-Descri��o

*/

//Muda o c�digo do produto com indice z
void Codigo(Produto *p, int z, int n)
{
    char aux[100];

    do
    {
        cout << "\nC�digo: ";
        cin >> aux;
        fflush(stdin);

        p[z].cod = atoi(aux);

        if(p[z].cod == 0) cout << "\nC�digo inv�lido.\n";

        else
        {
            for(int i = 0; i < n; i++)  // verifica se o c�digo digitado existe para outro produto
            {
                if(p[i].cod == p[z].cod)
                {
                    p[z].cod = 0;
                    cout << "\nJ� existe um produto com esse c�digo.\n";
                    break;
                }
            }
        }

    }
    while(p[z].cod == 0);

}

//Muda o nome do produto com indice z
void Nome(Produto *p, int z)
{

    cout << "\nNome: ";
    gets(p[z].nome);
    fflush(stdin);

}

//Muda a quantidade do produto com indice z
void Quantidade(Produto *p, int z)
{
    char aux[100];

    do
    {
        cout << "\nQuantidade: ";
        cin >> aux;
        fflush(stdin);

        p[z].quant = atoi(aux);

    }
    while(p[z].quant == 0);


}

//Muda o pre�o do produto com indice z
void Preco(Produto *p, int z)
{
    char aux[100];

    do
    {
        cout << "\nPre�o: ";
        cin >> aux;
        fflush(stdin);

        p[z].preco = atof(aux);

    }
    while(p[z].preco == 0);

}

//Muda a Descricao do produto com indice z
void Descricao(Produto *p, int z){
    cout << "\nDescri��o: ";
    gets(p[z].descricao);
    fflush(stdin);
}


//--------------------------------------------------------------------------------------------------------

//Ordena os produtos em ordem alfab�tica
//e coloca todos os produtos com c�digo = 0 nas �ltimas posi��es
void Ordenar(Produto *p, int n)
{

    unsigned int codAux;
    char nomeAux[1000];
    long double precoAux;
    unsigned int quantAux;


    for(int i = 0; i < n; i++)
    {

        for(int j = i+1; j <= n; j++)
        {

            if(stricmp(p[i].nome, p[j].nome) > 0 || p[i].cod == 0)
            {

                codAux = p[j].cod;
                p[j].cod = p[i].cod;
                p[i].cod = codAux;

                strcpy(nomeAux, p[j].nome);
                strcpy(p[j].nome, p[i].nome);
                strcpy(p[i].nome, nomeAux);

                precoAux = p[j].preco;
                p[j].preco = p[i].preco;
                p[i].preco = precoAux;

                quantAux = p[j].quant;
                p[j].quant = p[i].quant;
                p[i].quant = quantAux;

            }

        }

    }
}



//--------------------------------------------------------------------------------------------------------

//Cadastra novo produto
void Cadastrar ( Produto *p, int &n, int tam)
{
    if(n < tam - 1) //VERIFICA��O DE LIMITE
    {

        if(n == 0) cout << "\n\tAVISO\n"
                                    << "\nN�o existem produtos cadastrados."
                                    <<"\nPor favor, cadastre um produto\n";

        else
        {
            cout << "\n\tCADASTRAR\n";
        }

        Codigo(p, n);
        Nome(p, n);
        Quantidade(p, n);
        Preco(p, n);

        Ordenar(p);

        n++;

        cout << "\n";
        system("PAUSE");
    }

    else
    {
        cout << "\nFalha no cadastro do produto. Quantidade de produtos m�ximos cadastrados.";
        system("PAUSE");
    }

}

//--------------------------------------------------------------------------------------------------------


//MENU PARA EDI��O DE INFORMA��ES DOS PRODUTOS
//Exibe menu para usuario escolher o que quer editar do produto
//e retorna a op��o do usu�rio
int MenuEditar()
{
    char aux[100];
    int op;

    do
    {
        cout << "\n1. C�digo"
             << "\n2. Descri��o"
             << "\n3. Quantidade"
             << "\n4. Pre�o"
             << "\n5. Sair"
             << "\nDigite a op��o que deseja alterar no produto: ";

        cin >> aux;
        fflush(stdin);

        op = atoi(aux);

        if(op < 1 || op > 5) cout << "\nOp��o inv�lida!\n";

    }
    while(op < 1 || op > 5);

    return op;

}


//--------------------------------------------------------------------------------------------------------


//Fun��o para editar dados do produto
void Editar (Produto *p, int n)
{
    char aux[100];
    int z, op; // "z" � o indice do produto

    system("cls");
    cout << "\n\tEDITAR\n";
    z = BuscarIndice(p);

    if(n > -1)
    {
        do
        {
            op = MenuEditar();

            if(op != 5) cout << "\nNovos dados"; // op = 5 � op��o sair

            switch(op)
            {

            case 1:
                Codigo(p, z, n);
                break;

            case 2:
                Nome(p, z);
                break;

            case 3:
                Quantidade(p, z);
                break;

            case 4:
                Preco(p, z);
                break;


            }

            if(op != 5)  // a op��o 5 � para sair do menu editar
            {

                do
                {
                    cout << "\nDeseja editar algo mais deste produto? 1.Sim  2.N�o"
                         << "\nOp��o: ";
                    cin >> aux;
                    fflush(stdin);

                    op = atoi(aux);

                    if(op < 1 || op > 2) cout << "\nOp��o inv�lida!";

                }
                while(op < 1 || op > 2);

                if(op != 1)
                {
                    do
                    {
                        cout << "\nDeseja editar outro produto? 1.Sim  2.N�o"
                             << "\nOp��o: ";

                        cin >> aux;
                        fflush(stdin);

                        op = atoi(aux);

                        if(op < 1 || op > 2) cout << "\nOp��o inv�lida!";

                    }
                    while(op < 1 || op > 2);

                    if(op == 1)
                    {
                        Editar(p);

                    }
                }
                else
                {
                    system("cls");
                    cout << "\n\tEDITAR\n";
                }
            }
        }
        while(op == 1);
    }
}

//--------------------------------------------------------------------------------------------------------

//Fun��o que busca um produto pelo c�digo
//e exibe seus dados
void Buscar(Produto *p)
{

    int z; // "z" � o indice do produto

    cout << "\n\tBUSCAR\n";

    z = BuscarIndice(p);

    if(z > -1)
    {
        cout << "\nC�digo: " << p[z].cod
             << "\nNome: " << p[z].nome
             << "\nDescri��o: " << p[z].descricao
             << "\nQuantidade: " << p[z].quant
             << "\nPre�o: " << p[z].preco
             << "\n\n";

        system("PAUSE");
    }
}
