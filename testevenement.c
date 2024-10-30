#include "evenement.h"
#include <stdio.h>

int main(){
    struct sDate date1, date2;
    printf("Entrez la date 1: ");
    scanf("%d", &date1.annee);
    scanf("%d", &date1.mois);
    scanf("%d", &date1.jour);
    scanf("%d", &date1.heure);
    scanf("%d", &date1.minute);
    printf("Entrez la date 2: ");
    scanf("%d", &date2.annee);
    scanf("%d", &date2.mois);
    scanf("%d", &date2.jour);
    scanf("%d", &date2.heure);
    scanf("%d", &date2.minute);

    char titre[15] = "Les dindons";

    tEvenement evenement = CreerEvenement(titre, date1, date2);
    if (evenement == NULL){
        printf("Erreur lors de la creation de l'evenement\n");
        return 1;
    }
    printf("Evenement cree\n");
    AfficheEvenement(evenement);

    DetruitEvenement(&evenement);

    return 0;
}