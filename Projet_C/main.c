#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/stat.h>
#include "fonctions.h"

int main(int argc, char* argv[]){
    //parse(argv[1],argv[2]);
    int n = get_nbligne(argv[2]);
    caisse_t* liste_caisses = malloc(sizeof(caisse_t)*n);
    liste_caisses = initialiser_caisses(argv[2], liste_caisses);
    for(int i = 0; i < 7; i++){
        printf("numero : %d\ndebut : %d\nfin : %d\n",liste_caisses[i].numero,liste_caisses[i].debut,liste_caisses[i].fin);
    }

    client_t* liste_clients = malloc(sizeof(client_t)*get_nbligne(argv[1]));
    liste_clients = initialiser_clients(argv[1], liste_clients);
    for(int i = 0; i < get_nbligne(argv[1]); i++){
        printf("id : %s\n entree : %d\n ",liste_clients[i].id, liste_clients[i].entree);
    }
    free(liste_clients);
    free(liste_caisses);
    //client_t * client = initialiser_client((char*)"Utente1 59 4 S13 S21 S45 S52");
    //caisse_t *caisse = initialiser_caisse("C1 1 14400");
    //afficher_caisse(caisse);
    //free(caisse);
    return 0;
}