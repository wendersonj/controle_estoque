#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "funcoes.h"
//#include <conio.h>

using namespace std;

/*AS DUAS FUN��ES QUE PODEM ALTERAR S�O A FUN��O CADASTRAR E REMOVER*/
//obs: a fun��o menu est� recebendo &totalProd para a fun��o Cadastrar poder modificar a vari�vel

// ------------------------------------------------------------------
int main()
{
    //FUNDO TELA BRANCA
    system("color F0");

    //MENSAGEM TELA INICIAL
    Inicial();

    //ACENTUA��O e CARACTERES EM PT-BR
    setlocale(LC_ALL, "Portuguese");

    //VARI�VEIS
    const int TAM = 1000; //QUANTIDADE M�XIMA DE PRODUTOS QUE PODEM SER CADASTRADOS
    int totalProd = 0; //QUANTIDADE DE PRODUTOS J� CADASTRADOS

    int menu_op = 1;

    Produto estoque[TAM];  //VETOR DE PRODUTOS


    //OBS: PRODUTOS COM COD 0 'N�O EXISTEM'

    //COME�O DO PROGRAMA
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
