#ifndef GIFT_H
#define GIFT_H
#include <iostream>

using namespace std;

class Gift
{
public:
    Gift(string d, char cp);

    string desc;
    char control_parental;
};

#endif // GIFT_H
