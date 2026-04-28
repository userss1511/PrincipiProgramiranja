#include <stdio.h>
#include <stdlib.h>
#define INT_SIZE sizeof(int)*8

int zad1(int n){
return n & 1;
}

int zad2(int n, int k){
return (n >> k) & 1;
}

int zad3(int n, int k){
return n|(1 << k);
}

int zad4(int n, int k){
return n ^ (1 << k);
}

int zad5(int n){
int i;
int brojac = -1;
for(i = 0; i < INT_SIZE; i++){
    if(zad2(n, i) == 1) {
             brojac = i;
}}
return brojac;
}

int zad6(int n){
int i;
int brojac = -1;
for(i = 0; i < INT_SIZE; i++){
    if(zad2(n, i) == 1) {
             brojac = i;
             break;
}
}
return brojac;
}


int zad7(int n){
int i;
int zero=0;

for(i = 0; i < INT_SIZE; i++){
    if(zad2(n, i) == 0) zero++;


}
return zero;
}

int zad8(int n){
//32 - zad7(n)
int i;
int one=0;

for(i = 0; i < INT_SIZE; i++){
    if(zad2(n, i) == 1) one++;


}
return one;
}

int zad9(int n){
    return ~n;
}

int zad10(int n){
if(zad2(n, 0) == 1){
        n = n >> 1;
        n = n | 128; //128 -> 10000000 00000000 00000000 00000000
  return n;

}
else return n >> 1;
}

int zad11(int n, int k){
for(int i = 0; i < k; i++){
    n = zad10(n);
}
return n;
}

void zad12(int n){
if(n&1 == 1) printf("Neparan\n");

else printf("Paran\n");

}

void zad13(int n){
int i;
int niz[32];
for(i = 0; i < 32; i++){
    int m = n & 1;
    niz[i] = m;
    n = n >> 1;
}
int j;
for(j = 31; j >= 0; j--){
        if(j % 8 == 0) printf("%d ", niz[j]);
        else printf("%d", niz[j]);
}
}



int zad14(int n){
int i;
int niz[32];
for(i = 0; i < 32; i++){
    int m = n & 1;
    niz[i] = m;
    n = n >> 1;
}
int j, min;
for(j = 0; j < 32; j++){
    if(niz[j] == 1){
        min = j;
    }
}
return min+1;

}

int zad15(int n){
int k;
k = n >> 7;
return k&1;

}


int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    //printf("%d\n", zad1(n));
    //printf("%d\n", zad2(n, k));
    //printf("%d\n", zad3Pon(n, k));
    //printf("%d\n", zad4(n, k));
    //printf("%d\n", zad5(n));
    //printf("%d\n", zad6(n));
    //printf("%d\n", zad7(n));
    //printf("%d\n", zad8(n));
    //printf("%d\n", zad9(n));
    //printf("%d\n", zad10(n));
    //printf("%d\n", zad11(n, k));
    //zad12(n);
    //zad13(5);
    //printf("%d\n", zad14(n));
    printf("%d\n", zad15(n));
    return 0;
}
