#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void zad1(){

    FILE* ulaz = fopen("ulaz1.txt", "r");
    FILE* izlaz = fopen("izlaz1.txt", "w");

    if(ulaz == NULL || izlaz == NULL){
        printf("Greska prilikom otvaranja fajlova!\n");
    }
    else {
        char w[100];
        char rijec[100];

        printf("Unesi string w: ");
        scanf("%s", w);

        while(fscanf(ulaz, "%s", rijec) != EOF){
            if(strstr(rijec, w) != NULL){
                fprintf(izlaz, "%s\n", rijec);
            }
        }

        fclose(ulaz);
        fclose(izlaz);
    }
}

int jeSamoglasnik(char c){
    c = tolower(c);
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

int alternirajuca(char* rijec){
    int i = 0;

    while(rijec[i+1] != '\0'){
        int s1 = jeSamoglasnik(rijec[i]);
        int s2 = jeSamoglasnik(rijec[i+1]);
        if(s1 == s2) return 0;

        i++;
    }

    return 1;
}

void zad3(){

    FILE* ulaz = fopen("ulaz2.txt", "r");
    FILE* izlaz = fopen("izlaz2.txt", "w");

    if(ulaz == NULL || izlaz == NULL){
        printf("Greska prilikom otvaranja fajlova!\n");
    }
    else {
        char rijec[100];

        while(fscanf(ulaz, "%s", rijec) != EOF){

            if(alternirajuca(rijec)){
                fprintf(izlaz, "%s\n", rijec);
            }
        }

        fclose(ulaz);
        fclose(izlaz);
    }
}

int palindrom(char* rijec){
    int i = 0;
    int j = strlen(rijec) - 1;

    while(i < j){
        if(rijec[i] != rijec[j])
            return 0;
        i++;
        j--;
    }

    return 1;
}

void zad4(){

    FILE* ulaz = fopen("ulaz3.txt", "r");
    FILE* izlaz = fopen("izlaz3.txt", "w");

    if(ulaz == NULL || izlaz == NULL){
        printf("Greska prilikom otvaranja fajlova!\n");
    }
    else {
        char rijec[100];

        while(fscanf(ulaz, "%s", rijec) != EOF){

            if(palindrom(rijec)){
                fprintf(izlaz, "%s\n", rijec);
            }
        }

        fclose(ulaz);
        fclose(izlaz);
    }
}

void zad5(){

    FILE* ulaz = fopen("ulaz4.txt", "r");
    FILE* fSam = fopen("samoglasnici.txt", "w");
    FILE* fSug = fopen("suglasnici.txt", "w");

    if(ulaz == NULL || fSam == NULL || fSug == NULL){
        printf("Greska pri otvaranju fajlova!\n");
    }
    else {
        int h[26] = {0};
        char c;

        while((c = fgetc(ulaz)) != EOF){
            if(isalpha(c)){
                c = tolower(c);
                h[c - 'a']++;
            }
        }

        // ispis samoglasnika
        for(int i = 0; i < 26; i++){
            if(h[i] > 0){
                char slovo = 'a' + i;

                if(jeSamoglasnik(slovo)){
                    fprintf(fSam, "%c %d\n", slovo, h[i]);
                }
            }
        }

        // ispis suglasnika
        for(int i = 0; i < 26; i++){
            if(h[i] > 0){
                char slovo = 'a' + i;

                if(!jeSamoglasnik(slovo)){
                    fprintf(fSug, "%c %d\n", slovo, h[i]);
                }
            }
        }

        fclose(ulaz);
        fclose(fSam);
        fclose(fSug);
    }
}

int zad1Rek(int n){

    if(n < 10) return n;

    int cif = n % 10;
    int ost = n / 10;

    int pret = ost % 10;

    if(cif == pret){
        return zad1Rek(ost) * 100 + cif;
    }
    else{
        return zad1Rek(ost) * 10 + cif;
    }
}


//ako se niz zavrsava na 0 -> prethodna cifra moze biti i 0 i 1 (duzina n-1)
//ako se niz zavrsava na 1 -> prethodna cifra mora biti 0 (duzina n-2)

int zad2Rek(int n){
    if(n == 0) return 1;
    if(n == 1) return 2;

    return zad2Rek(n-1) + zad2Rek(n-2);
}

int i = 0;
void zad3Rek(char* s, char* out){

    while(s[i] != '\0' && s[i] != ']'){

        if(isdigit(s[i])){
            char broj[20];
            int b = 0;

            while(isdigit(s[i])){
                broj[b++] = s[i++];
            }
            broj[b] = '\0';

            int k = atoi(broj);

            i++; // preskoci '['

            char temp[1000] = "";
            zad3Rek(s, temp);

            i++; // preskoci ']'

            // dodaj k puta u out
            for(int j = 0; j < k; j++){
                strcat(out, temp);
            }
        }
        else{
            int len = strlen(out);
            out[len] = s[i];
            out[len + 1] = '\0';
            i++;
        }
    }
}


int main()
{
    //zad1();
    //zad3();
   // zad4();
    //zad5();
    //printf("%d\n", zad1Rek(555));
    //printf("%d\n", zad2Rek(4));

   char out[200] = "";
   zad3Rek("3[a]2[bc]", out);
   //zad3Rek("3[a2[c]]", out);
   //zad3Rek("2[abc]3[cd]ef", out);
   printf("%s\n", out);
    return 0;
}
