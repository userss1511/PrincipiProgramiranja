#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int brojRijeci(char* str){
int len = strlen(str);
int brojac = 0;
for(int i = 0; i < len; i++){
    if(str[i] == ' ' || str[i] == '.')  {
            brojac++;
    }
    }

return brojac;
}

int strCompare(char* str1, char* str2){
int len1 = strlen(str1);
int len2 = strlen(str2);
if(len1 != len2) return 0;
for(int i = 0; i < len1; i++){
    if(tolower(str1[i]) != tolower(str2[i])) return 0;
}

return 1;
}

void zad2DrugaGrupa(){
char str[100];
fgets(str, sizeof str, stdin);
int len = strlen(str);
int duzina = brojRijeci(str);
char *strNiz[duzina];
int i = 0;
char* r = strtok(str, " .");
while(r != NULL){
    strNiz[i++] = r;
    r = strtok(NULL, " .");
}

int niz[duzina];
for(int i = 0; i < duzina; i++) niz[i] = 1;

for(int i = 0; i < duzina; i++){
   for(int j = 0; j < duzina; j++) {
    if(i != j && strCompare(strNiz[i], strNiz[j]) == 1) niz[i]++;
   }
}

for(int i = 0; i < duzina; i++){
    printf("%s %d\n", strNiz[i], niz[i]);
}

}

int min = 10;
int zad3DrugaGrupa(int n, int k){
if(n == 0) {
    if(min == 10) return -1;
    else return min;
}
int cif = n % 10;
if(cif < min && cif > k) min = cif;
return zad3DrugaGrupa(n/10, k);
}

int samoglasnik(char c){
c = tolower(c);
if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
else return 0;
}

int uslov(char* str){
int len = strlen(str);
int brojac = 0;
for(int i = 0; i < len; i++){
    if(samoglasnik(str[i]) == 1) brojac++;
}

if(brojac >= 3) return 1;
else return 0;
}

void zad2PrvaGrupa(){
char str[1000];
fgets(str, sizeof str, stdin);
char rez[100];
int maxLen = 0;
char* rijec = strtok(str, " .");
while(rijec != NULL){
    if(uslov(rijec) == 1){
        if(strlen(rijec) > maxLen){
            maxLen = strlen(rijec);
            strcpy(rez, rijec);
        }
    }

    rijec = strtok(NULL, " .");
}

printf("%s\n", rez);
}

int max = -1;
int zad3PrvaGrupa(int n){
if(n == 0) return max;
int cif = n % 10;
if(cif > max && cif % 2 == 0) max = cif;
else return zad3PrvaGrupa(n/10);
}

int main()
{
    /*int n  = 3;
    int* niz = malloc(n*sizeof(int));
    b[0] = 1;
    printf("%d\n", b[0]);
    free(b);*/
    /*char str[100];
    fgets(str, sizeof str, stdin);
    printf("%d\n", brojRijeci(str));*/
    //zad2DrugaGrupa();
    //printf("%d\n", zad3DrugaGrupa(12345, 4));
    //zad2PrvaGrupa();
    printf("%d\n", zad3PrvaGrupa(1369));

    return 0;
}
