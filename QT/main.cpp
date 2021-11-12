#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <string>
#include "listadiaria.h"

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   MainWindow w;
   w.show();
   return a.exec();
   unsigned short int qtd;
   int ch, posicao;
   float valor;
   ListaDeCompras L;
   std::string produto;
   std::cout << "(1) para Inserir na lista" << std::endl;
   std::cout << "(2) para Retirar da lista" << std::endl;
   std::cout << "(3) para Mostrar todos os elementos da lista" << std::endl;
   std::cout << "(4) para Mostrar apenas elementos pendentes da f (carrinho)" << std::endl;
   std::cout << "(5) para Ordenar por Preco" << std::endl;
   std::cout << "(6) para Ordenar por Quantidade" << std::endl;
   std::cout << "(7) para colocar/tirar do carrinho um produto" << std::endl;
   std::cout << "(8) para Sair" << std::endl;
   do {
      std::cout << "Escolha uma opcao: " << std::endl;
      std::cin >> ch;
      switch(ch) {
         case 1: {
            std::cout << "Insira o valor" << std::endl;
            std::cin >> valor;
            std::cout << "Insira a quantidade" << std::endl;
            std::cin >> qtd;
            std::cin.ignore();
            std::cout << "Insira o nome do produto" << std::endl;
            std::getline( std::cin, produto );
            L.InserirElemento( produto, valor, qtd );
            break;
         }
         case 2: {
            std::cout << "Insira a posicao do produto a ser retirado" << std::endl;
            std::cin >> posicao;
            L.RemoverElemento(posicao);
            break;
         }
         case 3: {
            L.DisplayElementos();
            break;
         }
         case 4: {
            L.DisplayPendentes();
            break;
         }
         case 5: {
            L.OrdenarPreco();
            break;
         }
         case 6: {
            L.OrdenarQtd();
            break;
         }
         case 7: {
            std::cout << "Insira a posicao do produto a ser colocado/retirado do carrinho" << std::endl;
            std::cin >> posicao;
            L.Check(posicao);
            break;
         }
         case 8: {
            std::cout << "Sair" << std::endl;
            break;
         }
         default: {
            std::cout << "Escolha Inválida" << std::endl;
         }
      }
   }while(ch!=8);
return 0;
}
