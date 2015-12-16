#include "kid.h"

Kid::Kid()
{
    index=-1;
    nombre = "";
    se_porto_bien = 0;
    longitud = 0;
    latitud =0;
    edad = 0;
}

Kid::Kid(string n, int spb, int lo, int la, int e)
{
    index=hashFunc(n);
    nombre = n;
    se_porto_bien = spb;
    longitud = lo;
    latitud =la;
    edad = e;
}

void Kid::setRegalos(vector<Gift *> r)
{
    for (int i = 0; i < r.size(); ++i) {
        if(Regalos.size()<fibonachi(se_porto_bien))
            Regalos.push_back(r[i]);
    }
}

void Kid::changeCarbon()
{
    for (int i = 0; i < Regalos.size(); ++i) {
        Regalos[i]->desc = "Carbon";
    }
}
