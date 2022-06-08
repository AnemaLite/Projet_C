#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/stat.h>
#include "fonctions.h"

int cmp_clients(const void * ptr1, const void * ptr2){
    client_t premier = *(const client_t*) ptr1;
    client_t second = *(const client_t*) ptr2;
    return (int) (premier.entree - second.entree); 
}

int cmp_caisses(const void * ptr1, const void * ptr2){ // tri croissant sur l'heure d'ouverture 
    caisse_t premier = *(const caisse_t*) ptr1;
    caisse_t second = *(const caisse_t*) ptr2;
    return (int) (premier.debut - second.debut); 
}


int cmp_caisses_2(const void * ptr1, const void * ptr2){ // tri croissant sur l'heure de fermeture
    caisse_t premier = *(const caisse_t*) ptr1;
    caisse_t second = *(const caisse_t*) ptr2;
    return (int) (premier.fin - second.fin); 
}

int main(int argc, char* argv[]){
    int l = get_nbligne(argv[1]);

    client_t *clients = malloc(sizeof(client_t)*l);
    clients = initialiser_clients(argv[1],clients);

    caisse_t* caisses = malloc(sizeof(caisse_t)*7);
    caisses = initialiser_caisses(argv[2],caisses);
    /*for(int i = 0; i < 7; i++){
        caisses[i].occupation = malloc(sizeof(occupation_t)*l);
    }*/
    caisses->occupation = malloc(sizeof(occupation_t)*l);


    caisse_t* caisses2 = malloc(sizeof(caisse_t)*7);
    caisses2->occupation = malloc(sizeof(occupation_t)*l);
    caisses2 = initialiser_caisses(argv[2], caisses);
    memcpy(caisses2, caisses, 7);
    qsort(clients, l, sizeof(client_t), cmp_clients);
    /*  ouverture_caisses = qsort
    fermetures_caisses = qsort */

    afficher_caisses(caisses);
    qsort(caisses, 7, sizeof(caisse_t), cmp_caisses);
    qsort(caisses2, 7, sizeof(caisse_t), cmp_caisses_2);

    int temps = 0, res = 0;
    for(int i = 0; i < l; i++){
        arrivee_caisse_client(clients[i], caisses, &res, &temps);
        for(int j = 0; j < 7; j++){
            if(caisses[j].numero == res){
                occupation_t occupation;
                occupation.client = clients[i].id;
                if(caisses[j].nb == 0){
                    occupation.debut = temps;
                    occupation.fin = temps + 5*clients[i].nb_art;
                    caisses[j].occupation[i] = occupation;
                }
                else{
                    occupation.debut = caisses[j].occupation[caisses[j].nb-1].fin;
                    occupation.fin = occupation.debut + 5*clients[i].nb_art;
                    caisses[j].occupation[i] = occupation;
                }
                caisses[j].nb++;
                break;
            }
        }
    }

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < caisses[i].nb; j++){
            printf("Caisse %d : %d %d %s\n", j, caisses[i].occupation[j].debut, caisses[i].occupation[j].fin, caisses[i].occupation[j].client);
        }
    }
    //printf("%d\n",temps_magasin(liste[0],1));
    liberer_clients(clients,l);
    return 0;
}

