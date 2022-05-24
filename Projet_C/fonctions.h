#ifndef FONCTIONS_H
#define FONCTIONS_H

#include"structures.h"

void afficher_client(client_t * client);
void afficher_caisse(caisse_t * caisse);
int get_nbligne(char * filename);
void parse(char* client_source, char* caisse_source);
article_t creer_article(int x, int y);
caisse_t *initialiser_caisse(char * ligne);
client_t *initialiser_client(char * ligne);
client_t **initialise_tableau_client(char* filename);
void free_client(client_t * client);
void free_tableau_client(client_t ** tableau_client);
#endif