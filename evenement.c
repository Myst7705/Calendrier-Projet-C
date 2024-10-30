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

    if (ptr_evenement == NULL || !EstValide(debut) || !EstValide(fin) || Compare(debut, fin) > 0){
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
    // FIXME: l'affichage de debutStr est possede par un esprit demoniaque, le probleme est supposement localise ici
    // Fixed (Il fallait penser a ajouter '\0' en 13eme position de la str dans YYYYMMDDTHHMM)
    char str_debut[14];
    //str_debut[13] = '\0'; Solution pre-fix de YYYYMMDDTHHMM (brute force)
    char str_fin[14];

    YYYYMMDDTHHMM(str_debut, evenement->debut);
    YYYYMMDDTHHMM(str_fin, evenement->fin);

    printf("%s du %s au %s\n", evenement->titre, str_debut, str_fin);
}