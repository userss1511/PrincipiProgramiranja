#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    ///1. korak
    FILE* f = fopen("test.txt", "w"); ///w, r, a, wb, rb, ab

    ///2. korak
    if(f == NULL){
        printf("Fajl nije uspjesno otvoren!\n");
    }

    else {
        ///3. korak
        for(int i = a; i <= b; i++){
            fprintf(f, "%d\n", i);
        }
    }

    ///4. korak
    fclose(f);
    return 0;
}
