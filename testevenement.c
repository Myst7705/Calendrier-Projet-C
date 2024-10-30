#include "evenement.h"
#include <stdio.h>

int main(){
    struct sDate date1, date2;
    printf("Entrez la date 1: ");
    scanf("%d", &date1.annee);
    scanf("%hhd", &date1.mois);
    scanf("%hhd", &date1.jour);
    scanf("%hhd", &date1.heure);
    scanf("%hhd", &date1.minute);
    printf("Entrez la date 2: ");
    scanf("%d", &date2.annee);
    scanf("%hhd", &date2.mois);
    scanf("%hhd", &date2.jour);
    scanf("%hhd", &date2.heure);
    scanf("%hhd", &date2.minute);

    char titre[] = "Destruction de la republique";

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