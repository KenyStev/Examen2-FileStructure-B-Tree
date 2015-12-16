#ifndef GLOBAL
#define GLOBAL
static int hashCode(string text){
    int hash = 0, strlen = text.length(), i;
    char character;
    if (strlen == 0)
        return hash;
    for (i = 0; i < strlen; i++) {
        character = text[i];
        hash = (31 * hash) + int(character);
    }
    return hash;
}

static unsigned int MurmurHash2 ( const void * key, int len, unsigned int seed )
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

static unsigned int hashFunc(string key)
{
    return MurmurHash2(key.c_str(),key.length(),1);
}


static int fibonachi(int n, int before, int after, int cont)
{
    if(cont<=n)
        return fibonachi(n, after, after+before, cont+1);
    return before;
}

static int fibonachi(int n)
{
    return fibonachi(n,1,0,0);
}
#endif // GLOBAL

