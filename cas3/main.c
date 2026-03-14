#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int zad1(char* str, char c){
int len = strlen(str);
int brojac = 0;

for(int i = 0; i < len; i++){
    char karakter = str[i];
    if(karakter == c){
        brojac++;
    }
}

return brojac;
}

void zad2(char* str){
int len = strlen(str);
for(int i = len-1; i >= 0; i--){
    printf("%c", str[i]);
}
printf("\n");
}

void zadatak2(char* str){
char rez[100];
int br = 0;
int len = strlen(str);

for(int i = len - 1; i >= 0; i--){
    rez[br] = str[i];
    br++;
}

rez[br] = '\0';
printf("%s\n", rez);
}

int zad3(char* str){
int len = strlen(str);

for(int i = 0; i < len; i++){
    char c = str[i];
    if(islower(c)) return 0;
}

return 1;
}

void zad4(char* str){
char samoglasnici[100];
char suglasnici[100];
int len = strlen(str);
int br1 = 0, br2 = 0;

for(int i = 0; i < len; i++){
    char c = str[i];

    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        //samoglasnik je karakter
        samoglasnici[br1] = c;
        br1++;
    }
    else {
        //suglasnik je karakter
        suglasnici[br2] = c;
        br2++;
    }
}

samoglasnici[br1] = '\0';
suglasnici[br2] = '\0';
str = strcat(samoglasnici, suglasnici);
printf("%s\n", str);

}

int zad5(char* str){
int len = strlen(str);

for(int i = 0; i < len; i++){
    char c = str[i];
    int brojPojavljivanja = zad1(str, c);
    if(brojPojavljivanja > 1) return 0;
}

return 1;
}

int zad6(char* str1, char*str2){
int len1 = strlen(str1);
int len2 = strlen(str2);

for(int i = 0; i < len2; i++){
    char c = str2[i];
    int brP = zad1(str1, c); //broj pojavljivanja karaktera c (iz str2) u stringu str1
    if(brP == 0) return 0;

}

return 1;
}

int  zad7(char* str1, char* str2){
int len1 = strlen(str1);
int len2 = strlen(str2);

/*
for() // prolazenje duzine naseg podniza
    for() // prolazenje mogucim indeksima naseg podniza
        for() // izdvajanje podniza iz originalnog niza
*/

for(int i = 0; i <= len1 - len2; i++){
    char podstring[100];
    int br = 0;
    for(int j = i; j < i+len2; j++){
        podstring[br] = str1[j];
        br++;
    }
    podstring[br] = '\0';
    if(strcmp(str2, podstring) == 0) return 1;
}

return 0;
}

int zad8(char* str){
int len = strlen(str);
int brA = 0, brB = 0;
int i = 0;

for(i = 0; i < len; i++){
        char c = str[i];
        if(c != 'a') break;
        brA++;
}

if(str[i] != 'c') return 0;
int j = 0;

for(j = i+1; j < len; j++){
    char c = str[j];
    if(c != 'b') break;
    brB++;
}

if(j != len) return 0;
if(brB != brA) return 0;
return 1;

}

void zad9(char* str1, char* str2){
char rez[100];
int br = 0;
int len1 = strlen(str1);
int len2 = strlen(str2);

for(int i = 0; i < len2; i++){
    rez[br] = str1[i];
    rez[br+1] = str2[i];
    br += 2; //br = br + 2;
}

for(int i = len2; i < len1; i++){
    rez[br] = str1[i];
    br++;
}

rez[br] = '\0';
printf("%s\n", rez);

}

int main()
{
    int n = 100;
    char str[n];
    //char* str = malloc(n*sizeof(char));
    scanf("%s", str);
    //fgets(str, sizeof str, stdin);
    //printf("%s\n", str);
    //printf("%d\n", zad1(str, 'a'));
    //zad2(str);
    //zadatak2(str);
    //printf("%d\n", zad3(str));
    //zad4(str);
    //printf("%d\n", zad5(str));
    //printf("%d\n", zad6(str, "abc"));
    //printf("%d\n", zad7(str, "abc"));
    //printf("%d\n", zad8(str));
    //zad9(str, "AB");
    //free(str);
    return 0;
}
