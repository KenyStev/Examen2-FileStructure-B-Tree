#ifndef KID_H
#define KID_H
#include <iostream>
#include <vector>
#include "gift.h"
#include "global.h"

using namespace std;

class Kid
{
public:
    Kid();
    Kid(string n, int spb, int lo, int la, int e);

    unsigned int index;
    string nombre;
    int se_porto_bien; //valor del 0 al 10,  0 = Diablillo , 10 = La encarnación del Bien.
    vector<Gift*> Regalos;
    int longitud;
    int latitud;
    int edad;

    void setRegalos(vector<Gift*> r);
    void changeCarbon();
};

#endif // KID_H
