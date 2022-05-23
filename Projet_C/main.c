#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct{
    char* id;
    int sortie;
    int nb_art;
    article_t *liste_art;
}client_t;

typedef struct{
    int x;
    int y;
}article_t;

typedef struct{
    int numero;
    int debut;
    int fin;
}caisse_t; 

client_t *initialiser_client(char * ligne){
    client_t *client;
    int i = 0;
    while(ligne[i]!= " "){
        client->id[i] = ligne[i];
        i++;
    }
    return client;
}


//fonction qui lit le nombre de lignes du fichier client et crée des clients

void parse(char* client_source, char* caisse_source){
    //penser à appeler (et écrire donc) une fonction qui va calculer le temps en fonction des objets à aller chercher
    FILE* fichier_client = fopen(client_source, "r");
    //FILE* fichier_caisse = fopen(caisse_source, "r"); 
    client_t test;
    test.id = fgets(test.id,8,fichier_client);
    printf(test.id);
};

int main(int argc, char* arv[]){
    parse(arv[1],arv[2]);
    return 0;
}
