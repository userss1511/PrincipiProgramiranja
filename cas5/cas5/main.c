#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int pow_rek(int a, int b){
//bazni slucaj
if(b == 0) return 1;
else return a*pow_rek(a, b-1);
}

/*
-> 2^3 = 8
a = 2
b = 3
2*pow_rek(a, 2) = 2*2*pow(2, 1) = 2*2*2*pow(2, 0) = 2*2*2*1 = 8
*/

int zbir_cif_rek(int n){
if(n == 0) return 0;
int cif = n % 10;
return cif + zbir_cif_rek(n/10);
}

///123
/*
cif = 3
3 + zbir_cif_rek(12) = 3 + 2 + zbir_cif_rek(1) = 3 + 2 + 1 + zbir_cif_rek(0) = 3 + 2 + 1 + 0 = 6
*/

int dec2bin(int n) {
if(n == 0) return 0;
return n%2 + 10*dec2bin(n/2);
}

double f1(int n){
if(n == 1) return 1;
else return n + 1/(f1(n-1));
}

double f4(int n, int i){
if(i == n) return sqrt(i);
return sqrt(i + f4(n, i+1));
}

void strcpyRek(char* kopija, char* original, int n, int i){
if(i == n){
    kopija[i] = '\0';
    return;
}

kopija[i] = original[i];
strcpyRek(kopija, original, n, i+1);

}

//0 - false
//1 - true
int strcmpRek(char* str1, char* str2, int len1, int len2, int i){
if(len1 != len2) return 0;
if(i == len1) return 1;
if(str1[i] != str2[i]) return 0;
else return strcmpRek(str1, str2, len1, len2, i+1);
}

void preuredi(int *a, int n){
    if(n <= 1) return;

    preuredi(a+1, n-1);

    if(a[0] % 2 != 0){
        int temp = a[0];

        for(int i = 0; i < n-1; i++){
            a[i] = a[i+1];
        }

        a[n-1] = temp;
    }
}

int zad8(int x, int n){
if(n == 0) return 1; //x^0 = 1
if(n % 2 != 0) return x*zad8(x*x, (n-1)/2);
else return zad8(x*x, n/2);
}

//i = strlen(str) - 1
int atoiRek(char* str, int i){
if(i == -1) return 0;
else return (str[i] - '0') + 10*atoiRek(str, i-1);
}

int plocice(int n){
if(n == 0) return 1;
else if(n == 1) return 1;
else return plocice(n-1) + plocice(n-2);
}
int main()
{
    //printf("%d\n", pow_rek(5, 3));
    //printf("%d\n", zbir_cif_rek(1234));
    //printf("%d\n", dec2bin(73));
    //printf("%f\n", f1(5));
    //printf("%f\n", f4(5, 1));
    /*char kopija[100];
    strcpyRek(kopija, "abc", 5, 0);
    printf("%s\n", kopija);*/
    //printf("%d\n", strcmpRek("abcde", "abcde", 5, 5, 0));
    /*int niz[7] = {1, 2, 3, 4, 5, 6, 7};
    preuredi(niz, 7);
    for(int i = 0; i < 7; i++){
        printf("%d ", niz[i]);
    }
    printf("\n");*/

    //printf("%d\n", zad8(3, 3));
    //printf("%d\n", atoiRek("103", 2));
    //printf("%d\n", plocice(4));
    return 0;
}
