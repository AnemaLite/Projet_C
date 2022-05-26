#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct{
    int x;
    int y;
}article_t;

typedef struct{
    char* id;
    //int sortie;
    int entree;
    int nb_art;
    article_t *list_art;
}client_t;

typedef struct{
    int numero;
    int debut;
    int fin;
}caisse_t; 

#endif