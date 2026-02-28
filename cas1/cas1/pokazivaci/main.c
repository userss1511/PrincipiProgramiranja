#include <stdio.h>
#include <stdlib.h>

void fun1(int x){
    x = x + 1;
}

int funkcija1(int x){
return x + 1;
}

void fun1Pokazivac(int* xPtr){
    *xPtr = *xPtr + 1;
}
int main()
{
    /*int x = 7;
    //int *xPtr = NULL;
    int* xPtr = &x;
    printf("%d\n", x);
    printf("%p\n", xPtr);
    printf("%d\n", *xPtr);
    //scanf("%d", &x);*/
    int x = 10;
    int* xPtr = &x;
    //x = funkcija1(x);
    //x = x + 1;
    //fun1(x);
    fun1Pokazivac(xPtr);
    fun1Pokazivac(&x);
    printf("%d\n", x);

    return 0;
}
