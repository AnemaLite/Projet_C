#include"fonctions.h"
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

article_t creer_article(int x, int y){
    article_t article;
    article.x = x;
    article.y = y;
    return article;
};

caisse_t *initialiser_caisse(char * ligne){
    caisse_t *caisse = (caisse_t*) malloc(sizeof(caisse_t));
    caisse->numero = ligne[1]-48;
    int i = 3;
    char *tmp = (char*) malloc(sizeof(char)*10);
    char *tmp2 = (char*) malloc(sizeof(char)*10);
    while(ligne[i]!= ' '){
        tmp[i-3] = ligne[i];
        i++;
    }i++;
    int j = i;
    while(ligne[j] != ' '){
         tmp2[j-i] = ligne[j];
         j++;   
    }
    caisse->debut = atoi((const char*)tmp);
    caisse->fin = atoi((const char*)tmp2);
    free(tmp);
    free(tmp2);
    return caisse;
};

client_t *initialiser_client(char * ligne){
    client_t *client = (client_t*) malloc(sizeof(client_t));
    client->id = (char*) malloc(sizeof(char)*sizeof(ligne));
    int i = 0;
    while(ligne[i]!= ' '){
        client->id[i] = ligne[i];
        i++;
    }i++;
    int j = i;
    char *tmp = (char*) malloc(sizeof(char)*6);
    while(ligne[j] != ' '){
        tmp[j-i] = ligne[j];
        j++;
    }j++;
    int k = j;
    client->entree = atoi(tmp); // Valgrind donne une erreur ici on utilise atoi sur char* dont une partie n'est pas initialisée
    char *tmp2 = (char*) malloc(sizeof(char)*6); // Fonctionne quand même mais à modifier
    while(ligne[k] != ' '){
        tmp2[k-j] = ligne[k];
        k++;
    }k++;
    client->nb_art = atoi(tmp2);
    client->list_art = (article_t*) malloc(sizeof(article_t)*client->nb_art);
    free(tmp);
    free(tmp2);
    for(int i = 0; i < client->nb_art; i ++){
        client->list_art[i] = creer_article(ligne[k+1]-48,ligne[k+2]-48);                                                                                                                                                                                                                  
        k+=4;
    }
    return client;
}

void free_client(client_t * client){
    free(client->id);
    free(client->list_art);
    free(client);
}

client_t **initialiser_tableau_client(char* filename){
    FILE* fichier_client = fopen(filename, "r");
    client_t  **array_client = (client_t**)malloc(sizeof(client_t)*get_nbligne(filename));
    struct stat sb;
    stat(filename, &sb);
    char *file_contents = malloc(sizeof(char)*sb.st_size);
    int i =0;
    while (fscanf(fichier_client, "%[^\n] ", file_contents) != EOF) { 
        array_client[i] = initialiser_client(file_contents);
        afficher_client(array_client[i]);
        i++;
    }
    free(file_contents);
    fclose(fichier_client);
    return array_client;
};

caisse_t **initialiser_tableau_caisse(char* filename){ //erreur dans cette fonction
    FILE* fichier_caisse = fopen(filename, "r");
    caisse_t  **array_caisse = (caisse_t**)malloc(sizeof(caisse_t)*7);
    struct stat sb;
    stat(filename, &sb);
    char *file_contents = malloc(sizeof(char)*sb.st_size);
    int i = 0;
    while (fscanf(fichier_caisse, "%[^\n] ", file_contents) != EOF) { 
        array_caisse[i] = initialiser_caisse(file_contents);
        printf("%s\n", file_contents);
        afficher_caisse(array_caisse[i]);
        i++;
    }
    free(file_contents);
    fclose(fichier_caisse);
    return array_caisse;
};
void free_tableau_client(client_t ** tableau_client){
    for(int i = 0; i < 4; i++){
        free_client(tableau_client[i]);
    }
    free(tableau_client);
}

void free_tableau_caisse(caisse_t ** tableau_caisse){
    for(int i = 0; i < 7; i++){
        free(tableau_caisse[i]);
    }
    free(tableau_caisse);
}

void afficher_client(client_t * client){
    printf("Id : %s \nsortie : %d \nentree : %d\nnb_art: %d\n",client->id,client->sortie,client->entree,client->nb_art);
    for(int i = 0; i < client->nb_art; i++){
        printf("article %d : %d%d\n",i,client->list_art[i].x,client->list_art[i].y);
    }
};

void afficher_caisse(caisse_t * caisse){
    printf("numero : %d\ndebut : %d\nfin : %d\n",caisse->numero,caisse->debut,caisse->fin);
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

//fonction qui lit le nombre de lignes du fichier client et crée des clients

void parse(char* client_source, char* caisse_source){
    //client_t ** tableau_client = initialiser_tableau_client(client_source);
    caisse_t **tableau_caisse = initialiser_tableau_caisse(caisse_source);
    free_tableau_caisse(tableau_caisse);
    //free_tableau_client(tableau_client);
};
