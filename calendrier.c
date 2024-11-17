#include "calendrier.h"
#include <stdlib.h>
#include <stdio.h>

struct sCalendrier{
    tEvenement pEvenement;
    tCalendrier pSuivant;
};

int AjouterEvenement(tCalendrier *pCalendrier, tEvenement evenement){
    // On cree le nouveau tCal avec l'evenement donne
    tCalendrier nouveau = malloc(sizeof(struct sCalendrier));
    nouveau->pEvenement = evenement;
    nouveau->pSuivant = NULL;

    // Si le calendrier est vide, on modifie le pointeur de calendrier donne
    if (*pCalendrier == NULL){
        *pCalendrier = nouveau;
        return 0;
    } 

    // Sinon
    // On itere au travers de la liste chainee en verifiant la validite de notre evenement a rajouter
    tCalendrier courant = *pCalendrier;
    while (courant->pSuivant != NULL){
        if (Titre(courant->pEvenement) == Titre(evenement) || 
            Chevauche(Debut(courant->pEvenement), Fin(courant->pEvenement), Debut(evenement), Fin(evenement))) {
                return -1;
        }

        courant = courant->pSuivant;
    }
    
    // On ajoute le nouveau tCal a la fin du calendrier donne (c-a-d a la suite de courant)
    courant->pSuivant = nouveau;
    return 0;
}

tEvenement PremierEvenement(tCalendrier calendrier){
    return calendrier->pEvenement;
}

tCalendrier SuiteDuCalendrier(tCalendrier calendrier){
    return calendrier->pSuivant;
}

void DetruitCalendrier(tCalendrier* pCalendrier){
    tCalendrier precedent;

    while (*pCalendrier != NULL){
        precedent = *pCalendrier;
        *pCalendrier = (*pCalendrier)->pSuivant;


        DetruitEvenement(&(precedent->pEvenement));
        free(precedent);
    }

    *pCalendrier = NULL;
}

void AfficheCalendrier(tCalendrier calendrier){
    if (calendrier == NULL){
        printf("Calendrier vide\n");
    } else {
        tCalendrier courant = calendrier;
        while (courant != NULL){
            AfficheEvenement(courant->pEvenement);
            courant = courant->pSuivant;
        }
    }

}

int SupprimeEvenementsPeriode(tCalendrier* pCalendrier, struct sDate debut, struct sDate fin){
    int nbSupprime = 0;

    tCalendrier calActuel = *pCalendrier;
    tCalendrier* pDernierPSuivantValide = NULL;
    tCalendrier precedent;

    int estPremierEvenementValide = 1;

    printf("Debut Supprime invalide\n");

    while (calActuel != NULL){
        printf("Debut boucle while\n");
        if (Chevauche(Debut(calActuel->pEvenement), Fin(calActuel->pEvenement), debut, fin)){
            printf("Evenement invalide\n");
            // Si le sCal est invalide, on le free en utilisant un tCal precedent pour ne pas le perdre
            DetruitEvenement(&(calActuel->pEvenement));
            precedent = calActuel;
            calActuel = calActuel->pSuivant;
            free(precedent);
            nbSupprime++;

        } else {
            printf("Evenement valide\n");
            if (!estPremierEvenementValide){
                // On relie le dernier tCal valide avec l'actuel qui est valide
                *pDernierPSuivantValide = calActuel;
            } else {
                *pCalendrier = calActuel;
            }
            // On change le dernier pSuivant valide pour celui actuel qui est valide
            pDernierPSuivantValide = &(calActuel->pSuivant);
            // Puis on passe au cal d'apres
            calActuel = calActuel->pSuivant;

            // Nous ne sommes plus au premier evenement valide
            estPremierEvenementValide = 0;

        }

        // Nous ne sommes plus au premier evenement
        //estPremierEvenement = 0;
    }

    // On signe la fin du calendrier en mettant le dernier pSuivant valide a NULL
    *pDernierPSuivantValide = NULL;

    return nbSupprime;
}