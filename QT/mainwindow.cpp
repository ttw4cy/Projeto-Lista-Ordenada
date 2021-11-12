#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "listadiaria.h"
#include <QMessageBox>

ListaDeCompras l;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_BotaoAdd_clicked()
{
    QString nome = ui->CaixaNome->text();
    QString qtd = ui->CaixaQtd->text();
    QString preco = ui->CaixaPreco->text();


    int num = qtd.toInt();
    float valor = preco.toFloat();
    std::string str = nome.toStdString();


     l.InserirElemento(str, valor, num);

     ui->CaixaNome->setText("");
     ui->CaixaQtd->setText("");
     ui->CaixaPreco->setText("");

     BotaoAtt();
     TotalAtt();

}




void MainWindow::on_OrdenarQTD_clicked()
{
    l.OrdenarQtd();
    BotaoAtt();

}


void MainWindow::on_OrdenarPreco_clicked()
{
    l.OrdenarPreco();
    BotaoAtt();

}



void MainWindow::on_ListaNome_doubleClicked(const QModelIndex &index)
{

    int i = ui->ListaNome->currentRow();
    l.RemoverElemento(i);

    BotaoAtt();
    TotalAtt();


}

void MainWindow::BotaoAtt(){

    ui->ListaNome->clear(); //Atualização Da lista Nome
    for (int i = 0; i <= l.ultimo; ++i) {
        //QString a = QString::number(l.queue[i].elemento);
        ui->ListaNome->addItem(l.queue[i].elemento);
    }

    ui->ListaQtd->clear(); //Atualização Da lista Quantidade
    for (int i = 0; i <= l.ultimo; ++i) {
        QString b = QString::number(l.queue[i].qtd);
        ui->ListaQtd->addItem(b);
    }
    ui->ListaResultado->clear(); //Atualização Da lista valor
    for (int i = 0; i <= l.ultimo; ++i) {
        QString c = QString::number(l.queue[i].valor);
        ui->ListaResultado->addItem(c);
    }
}

void MainWindow::TotalAtt(){


    ui->ValorTotal->clear(); //Atualização Da lista valor
    float aux = 0;
    QString c;
    for (int i = 0; i <= l.ultimo; ++i) {
       aux = aux + (l.queue[i].valor*l.queue[i].qtd);
    }
    c = QString::number(aux);
    ui->ValorTotal->addItem(c);
}




