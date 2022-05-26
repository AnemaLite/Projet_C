#ifndef FONCTIONS_H
#define FONCTIONS_H

#include"structures.h"

void afficher_clients(client_t * liste_client, int taille);
void afficher_caisses(caisse_t * caisse);
int get_nbligne(char * filename);
caisse_t* initialiser_caisses(char* caisses, caisse_t* liste_caisses);
client_t* initialiser_clients(char* clients, client_t* liste_clients);
void liberer_clients(client_t * liste_clients, int taille);

#endif
