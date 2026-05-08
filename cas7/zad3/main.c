#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void djeljivi(int k){
    FILE* ulaz = fopen("ulaz.txt", "r");
    FILE* izlaz = fopen("izlaz.txt", "w");

    if(ulaz == NULL && izlaz == NULL){
        printf("Greska prilikom otvaranja fajlova!\n");
    }
    else {
        char line[100];

        while(fgets(line, 100, ulaz) != NULL){
            char* pts_str = strtok(line, ",\n");
            while(pts_str != NULL){
                int pts = atoi(pts_str);
                if(pts % k == 0) fprintf(izlaz, "%d\n", pts);
                pts_str = strtok(NULL, ",\n");
            }
        }

        fclose(ulaz);
        fclose(izlaz);
    }

}

int main()
{
    int k;
    scanf("%d", &k);
    djeljivi(k);
    return 0;
}
