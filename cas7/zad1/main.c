#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bodovi(){

    FILE* ulaz = fopen("bodovi.txt", "r");
    FILE* A = fopen("A.txt", "w");
    FILE* B = fopen("B.txt", "w");
    FILE* C = fopen("C.txt", "w");
    FILE* D = fopen("D.txt", "w");
    FILE* E = fopen("E.txt", "w");
    FILE* F = fopen("F.txt", "w");


    if(ulaz == NULL || A == NULL || B == NULL || C == NULL || D == NULL || E == NULL || F == NULL){
        printf("Greska prilikom otvaranja nekog fajla!\n");
    }
    else {
        char line[100];
        fgets(line, 100, ulaz);

        while(!feof(ulaz)){
                //printf("%s", line);
            char* pts_str = strtok(line, ",");
            while(pts_str != NULL){
                int pts = atoi(pts_str);
                if(pts >= 90) fprintf(A, "%d\n", pts);
                else if(pts >= 80) fprintf(B, "%d\n", pts);
                else if(pts >= 70) fprintf(C, "%d\n", pts);
                else if(pts >= 60) fprintf(D, "%d\n", pts);
                else if(pts >= 50) fprintf(E, "%d\n", pts);
                else fprintf(F, "%d\n", pts);

                pts_str = strtok(NULL, ",");
            }
            fgets(line, 100, ulaz);
        }

        fclose(ulaz);
        fclose(A);
        fclose(B);
        fclose(C);
        fclose(D);
        fclose(E);
        fclose(F);
    }

}

int main()
{
    bodovi();
    return 0;
}
