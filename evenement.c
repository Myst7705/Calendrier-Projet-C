#include "evenement.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct sEvenement{
    char *titre;
    struct sDate debut;
    struct sDate fin;
};

tEvenement CreerEvenement(const char* titre, struct sDate debut, struct sDate fin){
    // Initialise l'evenement que l'on retournera et verifie si tout est valide
    const tEvenement ptr_evenement = malloc(sizeof(struct sEvenement));

    if (ptr_evenement == NULL || !EstValide(debut) || !EstValide(fin)){
        return NULL;
    }

    // On remplace les attributs de notre evenement
    ptr_evenement->debut = debut;
    ptr_evenement->fin = fin;
    // Alloue la memoire pour le titre de l'evenement
    ptr_evenement->titre = malloc(strlen(titre) + 1);

    // Verification de l'allocation memoire du titre
    if (ptr_evenement->titre == NULL){
        return NULL;
    }
    // Copie du titre donne dans l'espace cree
    strcpy(ptr_evenement->titre, titre);

    return ptr_evenement;
}

char* Titre(tEvenement evenement){
    return evenement->titre;
}

struct sDate Debut(tEvenement evenement){
    return evenement->debut;
}

struct sDate Fin(tEvenement evenement){
    return evenement->fin;
}

void DetruitEvenement(tEvenement* pEvenement){
    free((*pEvenement)->titre);
    free(*pEvenement);
    *pEvenement = NULL;
}

void AfficheEvenement(tEvenement evenement){
    char debutStr[14], finStr[14];
    YYYYMMDDTHHMM(debutStr, evenement->debut);
    YYYYMMDDTHHMM(finStr, evenement->fin);
    printf("%s du %s au %s\n", evenement->titre, debutStr, finStr);
}