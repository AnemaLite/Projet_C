#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int x;
    int y;
}article_t;

typedef struct{
    char* id;
    int sortie;
    int entree;
    int nb_art;
    article_t *list_art;
}client_t;

typedef struct{
    int numero;
    int debut;
    int fin;
}caisse_t; 

client_t *initialiser_client(char * ligne){
    client_t *client = (client_t*) malloc(sizeof(client_t));
    client->id = (char*) malloc(sizeof(char)*sizeof(ligne));
    int i = 0;
    while(ligne[i]!= ' '){
        client->id[i] = ligne[i];
        i++;
    }i++;
    //while(ligne[i]!= ' ')
        //client->entree = ""

    return client;
}


//fonction qui lit le nombre de lignes du fichier client et crée des clients

/*void parse(char* client_source, char* caisse_source){
    penser à appeler (et écrire donc) une fonction qui va calculer le temps en fonction des objets à aller chercher
    FILE* fichier_client = fopen(client_source, "r");
    FILE* fichier_caisse = fopen(caisse_source, "r"); 
    client_t test;
    test.id = fgets(test.id,8,fichier_client);
};*/

int main(int argc, char* arv[]){
    //parse(arv[1],arv[2]);
    client_t * client = initialiser_client((char*)"test ");
    printf(client->id);
    free(client->id);
    free(client);
    return 0;
}
