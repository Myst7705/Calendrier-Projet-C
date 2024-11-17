#include "calendrier.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    struct sDate debut1 = {2003, 12, 02, 12, 30};
    struct sDate fin1 = {2003, 12, 02, 15, 00};
    tEvenement anniv = CreerEvenement("Anniv Yoann", debut1, fin1);

    struct sDate debut12 = {2001, 8, 11, 12, 30};
    struct sDate fin12 = {2001, 8, 11, 15, 00};
    tEvenement tower = CreerEvenement("Mr. president, there has been a second tower", debut12, fin12);

    struct sDate debut2 = {1099, 07, 15, 10, 15};
    struct sDate fin2 = {1099, 07, 16, 21, 25};
    tEvenement jeru = CreerEvenement("Prise de jerusalem par Godefroi", debut2, fin2);

    struct sDate debut3 = {778, 04, 12, 10, 15};
    struct sDate fin3 = {778, 04, 16, 21, 25};
    tEvenement charle = CreerEvenement("Charlemagne en Espagne", debut3, fin3);

    tCalendrier calendrier = NULL;

    struct sDate debutSup = {2000, 04, 12, 10, 15};
    struct sDate finSup = {2005, 04, 12, 10, 15};

    AjouterEvenement(&calendrier, anniv);
    AjouterEvenement(&calendrier, tower);
    

    AfficheCalendrier(calendrier);
    AjouterEvenement(&calendrier, jeru);
    printf("\n\n");

    AfficheCalendrier(calendrier);
    AjouterEvenement(&calendrier, charle);
    printf("\n\n");
    AfficheCalendrier(calendrier);
    printf("\n\n");

    SupprimeEvenementsPeriode(&calendrier, debutSup, finSup);
    printf("\n\n");
    AfficheCalendrier(calendrier);

    DetruitCalendrier(&calendrier);
    printf("Apres destruction calendrier\n");

    return 0;
}