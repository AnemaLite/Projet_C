#include"fonctions.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>

void afficher_clients(client_t * liste_clients, int taille){
    for(int i = 0; i < taille; i++){
        printf("%s %d %d\n",liste_clients[i].id, liste_clients[i].entree,liste_clients[i].nb_art);
        for(int j = 0; j < liste_clients[i].nb_art; j++){
            printf("%d%d ",liste_clients[i].list_art[j].x,liste_clients[i].list_art[j].y);
        }
        printf("\n");
    }
}

void afficher_caisses(caisse_t * liste_caisses){
    for(int i = 0; i < 7; i++){
        printf("numero : %d\ndebut : %d\nfin : %d\n",liste_caisses[i].numero,liste_caisses[i].debut,liste_caisses[i].fin);
    }
}

caisse_t* initialiser_caisses(char* caisses, caisse_t* liste_caisses){
    //caisses is the file name
    FILE* fichier = NULL;
    fichier = fopen(caisses, "r");
    char read[500] = "";
    int i = 0;
    while(fgets(read, 500, fichier) != NULL){
        caisse_t caisse;
        char* id = strtok(read, " ");
        memmove(id, id+1, strlen(id));        
        caisse.numero = atoi(id);
        char* debut = strtok(NULL, " ");
        caisse.debut = atoi(debut);
        char* fin = strtok(NULL, " ");
        caisse.fin = atoi(fin);
        liste_caisses[i] = caisse;
        memset(read, 0, 500);
        i++;

    }
    fclose(fichier);
    return liste_caisses;
}


client_t* initialiser_clients(char* clients, client_t* liste_clients){
    FILE* fichier = NULL;
    fichier = fopen(clients, "r");
    char read[500] = "";
    int j = 0;
    while(fgets(read, 500, fichier) != NULL){
        client_t client;
        char *tmp = strtok(read, " ");
        client.id = malloc(sizeof(char)*15);
        strcpy(client.id,tmp);
        client.entree = atoi(strtok(NULL, " "));
        client.nb_art = atoi(strtok(NULL, " "));
        client.list_art = malloc(sizeof(article_t)*client.nb_art);
        for(int i = 0; i < client.nb_art; i++){
            article_t article;
            char* art;
            art = strtok(NULL, " ");
            article.x = art[1]-48;
            article.y = art[2]-48;
            client.list_art[i] = article; 
        }
        liste_clients[j] = client;
        memset(read, 0, 500);
        j++;
    }
    fclose(fichier);
    return liste_clients;
}

void liberer_clients(client_t * liste_clients, int taille){
    for(int i = 0; i < taille; i++){
        free(liste_clients[i].id);
        free(liste_clients[i].list_art);
    }
    free(liste_clients);
}

int get_nbligne(char * filename){
    FILE * fichier = fopen(filename,"r") ;
    int c;
    int nLignes = 0;
    int c2 = '\0';
    while((c=fgetc(fichier)) != EOF){
        if(c=='\n')
            nLignes++;
        c2 = c;
    }
    if(c2 != '\n')
        nLignes++;
    fclose(fichier);
    return nLignes;
};
