#include "date.h"
#include <stdio.h>

int main(){
    /*int annee1, mois1, jour1, heure1, minute1;
    printf("Date 1\n");
    struct sDate date1;
    scanf("%d", &annee1);
    scanf("%d", &mois1);
    scanf("%d", &jour1);
    scanf("%d", &heure1);
    scanf("%d", &minute1);
    date1.annee = annee1;
    date1.mois = mois1;
    date1.jour = jour1;
    date1.heure = heure1;
    date1.minute = minute1;

    printf("Date 2\n");
    struct sDate date2;
    scanf("%d", &annee2);
    scanf("%d", &mois2);
    scanf("%d", &jour2);
    scanf("%d", &heure2);
    scanf("%d", &minute2);
    date2.annee = annee2;
    date2.mois = mois2;
    date2.jour = jour2;
    date2.heure = heure2;
    date2.minute = minute2;

    struct sDate date3 = {.annee = 2000, .mois = 12, .jour = 2, .heure = 12, .minute = 30};

    printf("%d\n", Appartient(date3, date1, date2));

    char dateStr[14];
    YYYYMMDDTHHMM(dateStr, date1);
    printf("%s\n", dateStr);*/

    struct sDate date1 = {2024, 10, 31, 14, 30};
    struct sDate date2 = {2003, 12, 2, 12, 15};
    struct sDate date3 = {1112, 6, 14, 2, 0};
    char dateStr1[14], dateStr2[14], dateStr3[14];
    YYYYMMDDTHHMM(dateStr1, date1);
    YYYYMMDDTHHMM(dateStr2, date2);
    YYYYMMDDTHHMM(dateStr3, date3);

    printf("%s\n%s\n%s\n", dateStr1, dateStr2, dateStr3);

    return 0;
}