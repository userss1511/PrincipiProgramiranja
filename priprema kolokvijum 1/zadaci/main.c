#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int samoglasnik(char c) {
c = tolower(c);
if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
else return 0;
}

void zad1(){

char s[1000];
fgets(s, sizeof(s), stdin);

int n = strlen(s);

for (int i = 0; i < n; i++) {
    if (s[i] == ' ') {
            i++;
            continue;
        }

    int poc = i;

    while (i < n && s[i] != ' ') i++;
    int kraj = i - 1;

    while (poc < kraj) {
        while (poc < kraj && !samoglasnik(s[poc])) poc++;
        while (poc < kraj && !samoglasnik(s[kraj])) kraj--;

            if (poc < kraj) {
                char temp = s[poc];
                s[poc] = s[kraj];
                s[kraj] = temp;

                poc++;
                kraj--;
            }
        }
    }

    printf("%s", s);

}

int sviRazliciti(char s[], int poc, int kraj) {
    for (int i = poc; i <= kraj; i++) {
        for (int j = i + 1; j <= kraj; j++) {
            if (s[i] == s[j])
                return 0;
        }
    }
    return 1;
}

void zad2(){

char s[1000];
scanf("%s", s);

int n = strlen(s);
int max = 0;

for (int i = 0; i < n; i++) {
   for (int j = i; j < n; j++) {
      if (sviRazliciti(s, i, j)) {
                int duzina = j - i + 1;
                if (duzina > max)
                    max = duzina;
            }
        }
    }

for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
        if (sviRazliciti(s, i, j)) {
           int duzina = j - i + 1;
               if (duzina == max) {
                    for (int k = i; k <= j; k++)
                        printf("%c", s[k]);
                    printf("\n");
                }
            }
        }
    }
}

void zad3(){
char s[1000];
scanf("%s", s);

int n = strlen(s);

for (int i = 0; i < n; i++) {
int brojac = 1;
    while (i + 1 < n && s[i] == s[i + 1]) {
        brojac++;
        i++;
        }

        if (brojac == 1) {
            printf("%c", s[i]);
        } else {
            printf("%c%d", s[i], brojac);
        }
    }
}

int zad4(int n) {
if (n == 0) return 0;

int cif = n % 10;
int ostatak = zad4(n / 10);

if (cif > ostatak) return cif;
else return ostatak;
}

int zad5(int n) {
if (n == 0) return 0;
if (n == 1) return 1;
return zad5(n-1) + zad5(n-2);
}

int zad6(int a, int b) {
if (b == 0) return a;
return zad6(b, a%b);
}

int zad7(int niz[], int n) {
if (n == 1) return niz[0];
int ostatak = zad7(niz, n-1);

if (niz[n-1] < ostatak) return niz[n-1];
else return ostatak;
}

int main()
{
    //zad1();
    //zad2();
    //zad3();
    //printf("%d\n", zad4(12834));
    //printf("%d\n", zad5(4));
    //printf("%d\n", zad6(5, 25));
    //int niz[5] = {1, 2, -1, -3, 4};
    //printf("%d\n", zad7(niz, 5));
    return 0;
}
