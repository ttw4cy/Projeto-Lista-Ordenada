
#include "listadiaria.h"
#include <iostream>
#include <string>

void swap(compras *xp, compras *yp)
{
    compras temp = *xp;
    *xp = *yp;
    *yp = temp;
}

ListaDeCompras::ListaDeCompras()
{
    queue = new compras[Tamanho_Fila_CO];
    ultimo = -1;
}
ListaDeCompras::~ListaDeCompras()
 {
    delete[] queue;
 }
void ListaDeCompras::InserirElemento( std::string elemento, float valor , unsigned short  qtd )
{
    if(EstaVazia()){
        ultimo = 0;
    }
    else
    {
        ultimo++;
    }
    queue[ultimo].qtd = qtd;
    queue[ultimo].valor = valor;
    for( int i = 0; i < TamanhoElementos; i++ )
        queue[ultimo].elemento[i] = elemento[i];
}
void ListaDeCompras::RemoverElemento( int posicao )
{
    if( EstaVazia() )
    {
        std::cout << "Erro, a fila esta vazia" << std::endl;
        return;
    }
    else if( ultimo == 0 )
    {
        for( int i = 0; i < TamanhoElementos; i++ )
        {
            queue[ultimo].elemento[i] = '\0';
        }
        ultimo = -1;
    } else
    {
        for ( int j = posicao; j < ultimo; j++)
        {

            for ( int i = 0; i < TamanhoElementos; i++)
            {
                queue[j].elemento[i] = queue[j+1].elemento[i] ;
            }

        }
        for( int i = 0; i < TamanhoElementos; i++ )
        {
            queue[ultimo].elemento[i] = '\0';
        }
        ultimo--;
    }
}
void ListaDeCompras::Check( int posicao )
{
    if(queue[posicao].feito == false)
        queue[posicao].feito = true;
    else
        queue[posicao].feito = false;
}
void ListaDeCompras::DisplayElementos()
{
    for (int i = 0; i <= ultimo; i++)
    {
        std::cout << "Na posicao " << i << " temos: " << queue[i].qtd << " " << queue[i].elemento
        << " que tem como valor " << queue[i].valor << std::endl;
    }

}
void ListaDeCompras::DisplayPendentes()
{
   for (int i = 0; i <= ultimo; i++)
    {
        if( queue[i].feito == false )
        {
            std::cout << "Na posicao " << i << " temos: " << queue[i].qtd << " " << queue[i].elemento
            << " que tem como valor " << queue[i].valor << std::endl;
        }
    }
}
void ListaDeCompras::OrdenarPreco()
{
   int i, j;
   bool trocado;
   for (i = 0; i < ultimo; i++)
   {
     trocado = false;
     for (j = 0; j < ultimo-i; j++)
     {
        if (queue[j].valor > queue[j+1].valor)
        {
           swap(&queue[j], &queue[j+1]);
           trocado = true;
        }
     }

     // Se nenhum elemento for trocado entao sair do loop pelo break
     if (trocado == false)
        break;
   }
}
void ListaDeCompras::OrdenarQtd()
{
   int i, j;
   bool trocado;
   for (i = 0; i < ultimo; i++)
   {
     trocado = false;
     for (j = 0; j < ultimo-i; j++)
     {
        if (queue[j].qtd > queue[j+1].qtd)
        {
           swap(&queue[j], &queue[j+1]);
           trocado = true;
        }
     }

     // Se nenhum elemento for trocado entao sair do loop pelo break
     if (trocado == false)
        break;
   }
}
int ListaDeCompras::EstaVazia()
{
    if(ultimo == -1)
        return true;
    else
        return false;
}


