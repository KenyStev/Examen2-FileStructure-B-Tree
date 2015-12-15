#include "mainwindow.h"
#include <QApplication>
#include <iostream>
//#include <qhash.h>
#include "Btree.h"
#include "kid.h"

using namespace std;

unsigned int MurmurHash2 ( const void * key, int len, unsigned int seed )
{
    // 'm' and 'r' are mixing constants generated offline.
    // They're not really 'magic', they just happen to work well.

    const unsigned int m = 0x5bd1e995;
    const int r = 24;

    // Initialize the hash to a 'random' value

    unsigned int h = seed ^ len;

    // Mix 4 bytes at a time into the hash

    const unsigned char * data = (const unsigned char *)key;

    while(len >= 4)
    {
        unsigned int k = *(unsigned int *)data;

        k *= m;
        k ^= k >> r;
        k *= m;

        h *= m;
        h ^= k;

        data += 4;
        len -= 4;
    }

    // Handle the last few bytes of the input array

    switch(len)
    {
    case 3: h ^= data[2] << 16;
    case 2: h ^= data[1] << 8;
    case 1: h ^= data[0];
            h *= m;
    };

    // Do a few final mixes of the hash to ensure the last few
    // bytes are well-incorporated.

    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;

    return h;
}

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

    Btree<Kid* ,3> tree;

    vector<Gift*> r;
    r.push_back(new Gift("Bici",8));
    r.push_back(new Gift("carro",4));
    r.push_back(new Gift("ball",3));
    r.push_back(new Gift("puzle",7));

    Kid keny("Keny",5,r,45,32,8);

    tree.insertar(keny);

    tree.mostrarArbol();

    int x=5;
    cout<<"busca: "<<tree.buscar(x)<<endl;
    cout<<"busca: "<<tree.buscarKid(x)->nombre<<endl;

    return a.exec();
}
