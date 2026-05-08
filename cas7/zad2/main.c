#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void histogram(){

    FILE* ulaz = fopen("ulaz.txt", "r");
    FILE* izlaz = fopen("histogram.txt", "w");

    if(ulaz == NULL || izlaz == NULL){
        printf("Greska prilikom otvaranja fajlova!\n");
    }

    else {
        int h[26] = {0};

        char line[100];
        fgets(line, 100, ulaz);

        while(!feof(ulaz)){
            int i = 0;
            while(line[i] != '\0'){
                if('a' <= line[i] && line[i] <= 'z') h[line[i] - 'a']++;
                else if('A' <= line[i] && line[i] <= 'Z') h[line[i] - 'A']++;
                i++;
            }

            fgets(line, 100, ulaz);
        }

        for(int i = 0; i < 26; i++){
            if(h[i] > 0)
                fprintf(izlaz, "%c: %d\n", 'A' + i, h[i]);
        }

        fclose(ulaz);
        fclose(izlaz);
    }
}

int main()
{
    histogram();
    return 0;
}
