#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAddKid_clicked()
{
    Kid *newKid = new Kid(ui->txtName_addKid->text().toStdString(),ui->txtSPB->value(),ui->txtLO->value(),ui->txtLA->value(),ui->txtEdad->value());

    if(!tree.buscar(newKid))
    {
        tree.insertar(newKid);
    }else{
        cout<<"Ya existe"<<endl;
    }
    ui->txtName_addKid->clear();
    ui->txtSPB->clear();
    ui->txtLO->clear();
    ui->txtLA->clear();
    ui->txtEdad->clear();
}

void MainWindow::on_pushButton_clicked()
{
    QString desc = ui->txtDesc->text();
    QChar cp = ui->txtCP->currentText().at(0);
    ui->listDesc->addItem(desc);
    ui->listCP->addItem(cp);
}

void MainWindow::on_btnAddListTo_clicked()
{
    Kid *newKid = new Kid();
    newKid->nombre = ui->txtName_addGift->text().toStdString();
    newKid->index = hashFunc(newKid->nombre);
    vector<Gift*> gifts;

    if(tree.buscar(newKid))
    {
        for (int i = 0; i < ui->listDesc->count(); ++i) {
            Gift *item = new Gift(ui->listDesc->item(i)->text().toStdString(),ui->listCP->item(i)->text().toStdString().c_str()[0]);
            gifts.push_back(item);
        }
    }
    newKid->setRegalos(gifts);

    ui->txtName_addGift->clear();
    ui->listDesc->clear();
    ui->listCP->clear();
    ui->txtDesc->clear();
}

void MainWindow::on_btnSearch_clicked()
{
    Kid *newKid = new Kid();
    newKid->nombre = ui->txtName_search->text().toStdString();
    newKid->index = hashFunc(newKid->nombre);

    ui->textInfo->clear();
    ui->textListAntes->clear();
    ui->textListDespues->clear();

    if(tree.buscar(newKid))
    {
        cout<<"Lo encontro"<<endl;
        ui->textInfo->appendPlainText("Nombre: " + QString(newKid->nombre.c_str()));
        ui->textInfo->appendPlainText("Edad: " + QString::number(newKid->edad));
        ui->textInfo->appendPlainText("Se Porto Bien: " + QString::number(newKid->se_porto_bien));
        ui->textInfo->appendPlainText("Latitud: " + QString::number(newKid->latitud));
        ui->textInfo->appendPlainText("Longitud: " + QString::number(newKid->longitud));

        ui->textListAntes->appendPlainText("Lista de Regalos");
        for (int i = 0; i < newKid->Regalos.size(); ++i) {
            ui->textListAntes->appendPlainText(QString("%1 - %2").arg(newKid->Regalos[i]->desc.c_str()).arg(newKid->Regalos[i]->control_parental));
        }

        for (int i = 0; i < newKid->Regalos.size(); ++i) {
            switch (newKid->edad) {
            case 0 ... 3:
                if(newKid->Regalos[i]->control_parental!='A')
                {
                    newKid->Regalos.erase(newKid->Regalos.begin()+i);
                    i=0;
                }
                break;
            case 4 ... 8:
                if(newKid->Regalos[i]->control_parental!='B')
                {
                    newKid->Regalos.erase(newKid->Regalos.begin()+i);
                    i=0;
                }
                break;
            case 9 ... 13:
                if(newKid->Regalos[i]->control_parental!='C')
                {
                    newKid->Regalos.erase(newKid->Regalos.begin()+i);
                    i=0;
                }
                break;
            default:
                if(newKid->Regalos[i]->control_parental!='D')
                {
                    newKid->Regalos.erase(newKid->Regalos.begin()+i);
                    i=0;
                }
                break;
            }
        }

        if(newKid->se_porto_bien<=3)
            newKid->changeCarbon();

        ui->textListDespues->appendPlainText("Lista de Regalos Actualizada");
        for (int i = 0; i < newKid->Regalos.size(); ++i) {
            ui->textListDespues->appendPlainText(QString("%1 - %2").arg(newKid->Regalos[i]->desc.c_str()).arg(newKid->Regalos[i]->control_parental));
        }
    }
}
