#include <stdio.h>
#include <stdlib.h>


void zadatak(int* xPtr){
*xPtr += 1;
}

int zad1(int* aPtr, int* bPtr){
int a = *aPtr;
int b = *bPtr;
return a+b;
}

int zad2(int* aPtr, int* bPtr){
int a = *aPtr;
int b = *bPtr;

if(a > b) return a;
else return b;
}

int zad3(int* aPtr){
int a = *aPtr;
int rez = 1;

for(int i = 1; i <= a; i++){
    rez *= i; //rez = rez * i;
}

return rez;
}

void zad4(int* niz, int n){
for(int i = 0; i < n; i++){
    printf("%d ", niz[i]);
}
printf("\n");
}

void zad5(int* niz, int n){
int* pomNiz = malloc(n*sizeof(int));
//int br = 0;
for(int i = n-1; i >= 0; i--){
    pomNiz[n-i-1] = niz[i];
    //br++;
}

for(int i = 0; i < n; i++){
    niz[i] = pomNiz[i];
}

free(pomNiz);
}


int main()
{
    //staticka alokacija niza
    /*int a[5];

    //dinamicka alokacija niza
    int n  = 3;
    int* b = malloc(n*sizeof(int));
    b[0] = 1;
    printf("%d\n", b[0]);
    free(b);*/

   /* int a;
    int b;
    scanf("%d %d", &a, &b);
    int* aPtr = &a;
    int* bPtr = &b;
    printf("%d\n", zad1(aPtr, bPtr));
    printf("%d\n", zad2(aPtr, bPtr));
    printf("%d\n", zad3(aPtr));*/
     /*int x = 5;
    int* xPtr = &x;
   printf("%d\n", x);
    zadatak(xPtr);
    printf("%d\n", x);*/

    /*int n = 3;
    int* niz = malloc(n*sizeof(int));
    niz[0] = 1;
    niz[1] = 2;
    niz[2] = 3;
   zad4(niz, n);
   zad5(niz, n);
   zad4(niz, n);*/

   //dinamicka alokacije matrice
   int m = 4;
   int n = 3;
   int** mat = malloc(m*sizeof(int*));

   for(int i = 0; i < m; i++){
    mat[i] = malloc(n*sizeof(int));
   }

   for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
        mat[i][j] = i+j;
    }
   }

   for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
        printf("%d ", mat[i][j]);
    }
    printf("\n");
   }

}
