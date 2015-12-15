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

Kid::Kid(string n, int spb, vector<Gift*> r, int lo, int la, int e)
{
    index=n.length();
    nombre = n;
    se_porto_bien = spb;
    Regalos = r;
    longitud = lo;
    latitud =la;
    edad = e;
}

