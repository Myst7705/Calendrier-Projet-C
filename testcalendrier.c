#include "calendrier.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    struct sDate debut1 = {2003, 12, 02, 12, 30};
    struct sDate fin1 = {2003, 12, 02, 15, 00};
    tEvenement anniv = CreerEvenement("Anniv Yoann", debut1, fin1);
    struct sDate debut2 = {1099, 07, 15, 10, 15};
    struct sDate fin2 = {1099, 07, 16, 21, 25};
    tEvenement jeru = CreerEvenement("Prise de jerusalem par Godefroi", debut2, fin2);

    tCalendrier calendrier = NULL;
    printf("Avant ajout evenement\n");
    AjouterEvenement(&calendrier, jeru);
    printf("Apres ajout evenement 1\n");
    AfficheCalendrier(calendrier);
    AjouterEvenement(&calendrier, anniv);
    printf("Apres ajout evenement 2\n");

    AfficheCalendrier(calendrier);

    DetruitCalendrier(&calendrier);
    printf("Apres destruction calendrier\n");

    return 0;
}