typedef struct Canal{

    char nomeCanal[30];
    int numCanal;

}canal;

typedef struct sNo{

    canal info;
    struct sNo *dir;
    struct sNo *esq;

}NO;