#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int brojRijeci(char* str){
int brojac = 0;
int len = strlen(str);
for(int i = 0; i < len; i++){
    if(str[i] == ' ' || str[i] == '.' || str[i] == '\n') brojac++;
}

return brojac;
}

int uporedi(char* str1, char* str2){
int len1 = strlen(str1);
int len2 = strlen(str2);
if(len1 != len2) return 0;

for(int i = 0; i < len1; i++){
    if(tolower(str1[i]) != tolower(str2[i])) return 0;
}

return 1;
}

void zad2PrvaGrupa(char* str, char* rijec, char* zamjena){
int duzina = brojRijeci(str);
char* nizStringova[duzina];
char* r = strtok(str, " .");
int i = 0;

while(r != NULL){
    if(uporedi(rijec, r) == 1){
        nizStringova[i++] = zamjena;
    }
    else nizStringova[i++] = r;
    r =  strtok(NULL, " .");
}

for(int i = 0; i < duzina; i++){
    printf("%s ", nizStringova[i]);
}
}

double zad3PrvaGrupa(int n){
if(n == 0) return 1;
return ((double) (n) / (n+1)) * zad3PrvaGrupa(n-1);
}

void zad2DrugaGrupa(){
char str[1000];
fgets(str, sizeof str, stdin);

int brojac = 0;
int len = strlen(str);
char* r = strtok(str, " .\n");

while(r != NULL){
    char c1 = r[0];
    char c2 = r[strlen(r) - 1];
    if(tolower(c1) == tolower(c2)) {
        if(strlen(r) != 1){
        brojac++;
        printf("%s\n", r);
        }

    }
    r = strtok(NULL, " .\n");

}

printf("%d\n", brojac);
}


double zad3DrugaGrupa(int n){
if(n == 0) return 0;
return zad3DrugaGrupa(n - 1) + (double)(2*n) / (2*n + 1);
}
int main()
{
   /*int m = 4;
   int n = 3;
   int** mat = malloc(m*sizeof(int*));

   for(int i = 0; i < m; i++){
    mat[i] = malloc(n*sizeof(int));


   }*/

   /*char str[] = "Strukture podataka su osnova svakog programa jer podaci omogucavaju rad programa.";
   char rijec[] = "programa";
   char zamjena[] = "sistema";*/

   //zad2PrvaGrupa(str, rijec, zamjena);
   //printf("%f\n", zad3PrvaGrupa(4));
   //zad2DrugaGrupa();
    printf("%f\n", zad3DrugaGrupa(3));
    return 0;
}
