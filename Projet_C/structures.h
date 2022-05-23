#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct{
    int ligne;
    int colonne;
}article_t;

typedef struct{
    node_t *next;
    node_t *prev;
    article_t article;
}node_t;


typedef struct{
    int taille;
    node_t *first;
    node_t *last;
}liste_article_t;


typedef struct{
    liste_article_t liste_article;
    int entree;
    int temps;
}client_t;



#endif