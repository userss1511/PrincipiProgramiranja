#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void zad1(char *lozinka){
int len = strlen(lozinka);

if(len < 8) {
    printf("NO\n");
    return;
}

int ind = 1; //1 -> true, 0 -> false
int maloSlovo = 0, velikoSlovo = 0, cifre = 0;

for(int i = 0; i < len; i++){
char c = lozinka[i];
if(islower(c)) maloSlovo++;
else if(isupper(c)) velikoSlovo++;
else if(isdigit(c)) cifre++;
else ind = 0;
}

if(maloSlovo == 0 || velikoSlovo == 0 || cifre == 0) ind = 0;

if(ind == 1){
    printf("YES\n");
}
else {
    printf("NO\n");
}
}

int samoglasnik(char c){
if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return 1;
else return 0;
}

int zad2(char *str){
int len = strlen(str);
char novi[100];
int br1 = 0;
int br2 = len-1;

for(int i = 0; i < len; i++){
char c = str[i];
    if(samoglasnik(c) == 1){
        novi[br1] = c;
        br1++;
    }
    else{
        while(samoglasnik(str[br2]) == 1){
            br2--;
            if(br2 == 0) break;
        }
        novi[br1] = str[br2];
        br1++;
        br2--;
    }

}

novi[br1] = '\0';
if(strcmp(str, novi) == 0) return 1;
else return 0;

}

int zad4(char *str){
int niz[26];
int len = strlen(str);

for(int i = 0; i < 26; i++){
    niz[i] = 0;
}

for(int i = 0; i < len; i++){
    char c = tolower(str[i]);
    int indeks = c - 'a';
    niz[indeks] = niz[indeks] + 1; //niz[indeks]++;
}

for(int i = 0; i < 26; i++){
    if(niz[i] == 0) return 0;

}

return 1;

}

int zad3(){
char str[100];
int x = 0, y = 0;

while(fgets(str, sizeof str, stdin) != NULL){  //North 5
//ako kliknete CTRL + C -> str = NULL prekid unosa
char *smjer = strtok(str, " ");
char *br = strtok(NULL, " ");
int broj = atoi(br);

if(strcmp(smjer, "North") == 0){
    y += broj; //y = y + broj
}
else if(strcmp(smjer, "South") == 0){
    y -= broj;
}
else if(strcmp(smjer, "West") == 0){
    x -= broj;
}

else if(strcmp(smjer, "East") == 0){
    x += broj;
}
}

printf("%d %d\n", x, y);
}

int main()
{
    //char str[100];
    //scanf("%s", str);
    //fgets(str, sizeof str, stdin); //za ucitavanje stringa sa razmakom
    //zad1(str);
    /*int rezZad2 = zad2(str);
    if(rezZad2 == 0) printf("NO");
    else printf("YES");*/

    //printf("%d\n", zad4(str));
    //The quick brown fox jumps over the dog
    //zad3();
    return 0;
}
