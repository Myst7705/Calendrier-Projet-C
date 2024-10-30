#include "date.h"
#include <stdio.h>

static int estBissextile(const int n);
static int estMinuteValide(const int n);
static int estHeureValide(const int n);
static int estJourValide(const int jour, const int mois, const int annee);
static int estMoisValide(const int n);
static void yearToStr(char *destination, int annee);
static void monthToStr(char *destination, int mois);
static void dayToStr(char *destination, int jour);
static void heureToStr(char *destination, int heure);
static void minuteToStr(char *destination, int minute);


// Fonctions de validite generale de la date
int EstValide(const struct sDate date){
    return estMinuteValide(date.minute) && estHeureValide(date.heure) && estJourValide(date.jour, date.mois, date.annee);
}

static int estBissextile(const int n){
    return n % 400 == 0 || (n % 4 == 0 && n % 100 != 0);
}

static int estMinuteValide(const int n){
    return n >= 0 && n <= 59;
}

static int estHeureValide(const int n){
    return n >= 0 && n <= 23;
}

// Verification de la validite du jour, ainsi que du nombre de jours dans le mois de la date
static int estJourValide(const int jour, const int mois, const int annee){
    if (!estMoisValide(mois) || jour <= 0 || jour > 31){
        return 0;
    } else if ((mois == 1 || mois == 3 || mois == 5 || mois == 7 || mois == 8 || mois == 10 || mois == 12) && jour > 31){
        return 0;
    } else if ((mois == 4 || mois == 6 || mois == 9 || mois == 11) && jour > 30){
        return 0;
    } else if (mois == 2 && ((estBissextile(annee) && jour > 29) || (!estBissextile(annee) && jour > 28))){
        return 0;
    }
    return 1;
}

static int estMoisValide(const int n){
    return n >= 1 && n <= 12;
}


int Compare(const struct sDate reference, const struct sDate autreDate){
    // Verification d'egalite entre les dates
    if (reference.annee == autreDate.annee && reference.mois == autreDate.mois 
    && reference.jour == autreDate.jour && reference.heure == autreDate.heure && reference.minute == autreDate.minute){
        return 0;
    }

    // On verifie 1 a 1 les egalites, et on renvoie la difference le cas echeant
    if (reference.annee != autreDate.annee){
        return reference.annee - autreDate.annee;
    } else if (reference.mois != autreDate.mois){
        return reference.mois - autreDate.mois;
    } else if (reference.jour != autreDate.jour){
        return reference.jour - autreDate.jour;
    } else if (reference.heure != autreDate.heure){
        return reference.heure - autreDate.heure;
    } else {
        return reference.minute - autreDate.minute;
    }
}

int Appartient(const struct sDate date, const struct sDate debut, const struct sDate fin){
    if (Compare(debut, date) <= 0 && Compare(date, fin) <= 0){
        return 1;
    }
    return 0;
}

int Chevauche(const struct sDate debut1, const struct sDate fin1, const struct sDate debut2, const struct sDate fin2){
    return Appartient(fin1, debut2, fin2) || Appartient(debut2, debut1, fin1);
}

// Convertit les elements de date (entiers) en caracteres grace a des fonctions auxiliaires
void YYYYMMDDTHHMM(char* destination, const struct sDate date){
    
    yearToStr(destination, date.annee);
    monthToStr(destination, date.mois);
    dayToStr(destination, date.jour);
    heureToStr(destination, date.heure);
    minuteToStr(destination, date.minute);
    destination[8] = 'T';
}

static void yearToStr(char *destination, int annee){
    destination[3] = '0';
    destination[2] = '0';
    destination[1] = '0';
    destination[0] = '0';

    int i = 3;
    while (annee > 0){
        destination[i] = annee % 10 + '0';
        annee = annee / 10;
        i--;
    }
}

static void monthToStr(char *destination, int mois){
    destination[5] = '0';
    destination[4] = '0';

    int i = 5;
    while (mois > 0){
        destination[i] = mois % 10 + '0';
        mois = mois / 10;
        i--;
    }
}

static void dayToStr(char *destination, int jour){
    destination[7] = '0';
    destination[6] = '0';

    int i = 7;
    while (jour > 0){
        destination[i] = jour % 10 + '0';
        jour = jour / 10;
        i--;
    }
}

static void heureToStr(char *destination, int heure){
    destination[10] = '0';
    destination[9] = '0';

    int i = 10;
    while (heure > 0){
        destination[i] = heure % 10 + '0';
        heure = heure / 10;
        i--;
    }
}

static void minuteToStr(char *destination, int minute){
    destination[12] = '0';
    destination[11] = '0';

    int i = 12;
    while (minute > 0){
        destination[i] = minute % 10 + '0';
        minute = minute / 10;
        i--;
    }
}





int main(){
    int annee1, annee2, mois1, mois2, jour1, jour2, heure1, heure2, minute1, minute2;
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

    /*printf("Date 2\n");
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

    printf("%d\n", Appartient(date3, date1, date2));*/

    char dateStr[14];
    YYYYMMDDTHHMM(dateStr, date1);
    printf("%s\n", dateStr);

    return 0;
}

