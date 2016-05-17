#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "funcoes.h"
//#include <conio.h>

using namespace std;

/*AS DUAS FUNÇÕES QUE PODEM ALTERAR SÃO A FUNÇÃO CADASTRAR E REMOVER*/
//obs: a função menu está recebendo &totalProd para a função Cadastrar poder modificar a variável

// ------------------------------------------------------------------
int main()
{
    //FUNDO TELA BRANCA
    system("color F0");

    //MENSAGEM TELA INICIAL
    Inicial();

    //ACENTUAÇÃO e CARACTERES EM PT-BR
    setlocale(LC_ALL, "Portuguese");

    //VARIÁVEIS
    const int TAM = 1000; //QUANTIDADE MÁXIMA DE PRODUTOS QUE PODEM SER CADASTRADOS
    int totalProd = 0; //QUANTIDADE DE PRODUTOS JÁ CADASTRADOS

    int menu_op = 1;

    Produto estoque[TAM];  //VETOR DE PRODUTOS


    //OBS: PRODUTOS COM COD 0 'NÃO EXISTEM'

    //COMEÇO DO PROGRAMA
    while(menu_op != 0)
    {
        if (totalProd == 0)
        {
            Cadastrar(estoque, totalProd);
        }

        //INICIALIZAR O MENU
        menu_op = Menu();

        switch (menu_op)
        {
        case 1:
            Cadastrar(estoque, totalProd);
            break;

        case 2:
            Editar(estoque, totalProd);
            break;

        case 3:
            Buscar(estoque, totalProd);
            break;

        case 4:
            Remover(estoque, totalProd);
            break;

        case 5:
            ListarTodos(estoque, totalProd);
            break;

        case 6:
            BaixoEstoque(estoque, totalProd);
            break;

        case 7:
            TotalProdutos(estoque, totalProd);
            break;

        case 8:
            system("cls");
            break;

        case 0:
            cout << "\nObrigado por utilizar nosso software.\n";
            break;
        }
    }//Fim do while-programa

    system("pause");
}
