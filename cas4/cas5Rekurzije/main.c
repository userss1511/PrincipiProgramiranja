#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int faktorijel(int n){
int f = 1;
for(int i = 1; i <= n; i++){
    f *= i; // f = f * i;
}

return f;
}

int faktorijelRekurzija(int n){
if(n == 0) return 1; //Stop slucaj
return n*faktorijelRekurzija(n-1);
}

int zbirBrojeva(int n){
if(n == 0) return 0;
return n + zbirBrojeva(n-1);
}

int proizvodCifara(int n){
if(n == 0) return 1;
return (n%10)*proizvodCifara(n/10);
}

int brojCifara(int n){
if(n == 0) return 0;
return 1+brojCifara(n / 10);
}

int obrniBroj(int n){
if(n == 0) return 0;
int cif = n % 10;
return cif*pow(10, brojCifara(n) - 1) + obrniBroj(n/10);
}

int evenDigits(int n){
if(n == 0) return 0;
int cif = n % 10;
int ostatak = evenDigits(n/10);
if(cif % 2 != 0) return ostatak*10 + cif;
else return ostatak;
}

int oddDigits(int n){
if(n == 0) return 0;
int cif = n % 10;
int ostatak = oddDigits(n/10);
if(cif % 2 == 0) return ostatak*10 + cif;
else return (ostatak*10 + cif)*10;
}

int sumaCifara(int n){
if(n == 0) return 0;
int cif = n % 10;
return cif + sumaCifara(n / 10);
}

int digitalniKorijen(int n){
if(n < 10) return n;
return digitalniKorijen(sumaCifara(n));
}

int main()
{
    //printf("%d\n", faktorijel(3));
    //printf("%d\n", zbirBrojeva(4));
    //printf("%d\n", proizvodCifara(152));
    //printf("%d\n", brojCifara(123));
    //printf("%d\n", obrniBroj(123));
    //printf("%d\n", evenDigits(1234));
    //printf("%d\n", oddDigits(123));
    //printf("%d\n", sumaCifara(1234));
    //printf("%d\n", digitalniKorijen(123));
    return 0;
}
