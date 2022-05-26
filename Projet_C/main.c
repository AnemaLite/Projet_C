#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/stat.h>
#include "fonctions.h"

int main(int argc, char* argv[]){
    int n = get_nbligne(argv[1]);
    caisse_t* liste_caisses = malloc(sizeof(caisse_t)*7);
    liste_caisses = initialiser_caisses(argv[2], liste_caisses);
    afficher_caisses(liste_caisses);

    client_t* liste_clients = malloc(sizeof(client_t)*n);
    liste_clients = initialiser_clients(argv[1], liste_clients);
    afficher_clients(liste_clients,n);
    liberer_clients(liste_clients,n);
    free(liste_caisses);
    return 0;
}

