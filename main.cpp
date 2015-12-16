#include "mainwindow.h"
#include <QApplication>
#include <iostream>
//#include <qhash.h>
#include "Btree.h"
#include "kid.h"
#include "global.h"

using namespace std;

int hash(string key, int seed)
{
    int data[key.length()];
    int ha=0;
    for (int i = 0; i < key.length(); ++i) {
        data[i] = key[i]>>seed;
        ha+=data[i]*(i+1);
    }
    return ha/32;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    QString str = "ma";
//    int hash_val = hash(str.toStdString(),1);//qHash(str, 0);//MurmurHash2((void*)str.c_str(),str.length(),str.length());
//    cout<<"hash val: "<<hash_val<<endl;

//    Btree<Kid* ,3> tree;

//    vector<Gift*> r;
//    r.push_back(new Gift("Bici",8));
//    r.push_back(new Gift("carro",4));
//    r.push_back(new Gift("ball",3));
//    r.push_back(new Gift("puzle",7));

//    Kid *keny = new Kid("Keny",5,45,32,8);

//    tree.insertar(keny);

//    tree.mostrarArbol();

//    Kid *kid = new Kid();
//    kid->index=4;
//    if(tree.buscar(kid))
//    {
//        cout<<"Encontrado: "<<kid->Regalos[0]->desc<<endl;
//        tree.remover(kid);
//    }

//    Kid *kid2 = new Kid();
//    kid2->index=4;
//    if(tree.buscar(kid2))
//    {
//        cout<<"Encontrado: "<<kid2->Regalos[0]->desc<<endl;
//    }else{
//        cout<<"no encontrado"<<endl;
//    }

//    cout<<endl<<endl;
//    string key = "HOLA";
//    cout<<hashCode(key)<<endl;
//    cout<<hashFunc(key)<<endl;

    return a.exec();
}
