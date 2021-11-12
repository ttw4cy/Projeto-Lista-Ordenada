
#ifndef LISTADIARIA_H
#define LISTADIARIA_H

#define Tamanho_Fila_CO 150
#define Tamanho_Fila_AF 25
#define TamanhoElementos 20

#include <string>


 struct compras {
    float valor;
    char elemento[TamanhoElementos];
    unsigned short int qtd;
    bool feito = false;
};



class ListaDeCompras
{
    public:
        ListaDeCompras(); // Constructor
        ~ListaDeCompras();
        void InserirElemento( std::string elemento, float valor , unsigned short int qtd);
        void RemoverElemento( int posicao );
        void Check( int posicao );
        void DisplayElementos();
        void DisplayPendentes();
        void OrdenarPreco();
        void OrdenarQtd();
        int EstaVazia();
        compras *queue;
        int ultimo;

    private:
        //compras *queue;
        //int ultimo;
};



#endif
