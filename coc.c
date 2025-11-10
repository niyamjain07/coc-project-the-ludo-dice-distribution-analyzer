#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rolls, i;
    int sides = 6;
    int freq[7] = {0};
    
    printf("Ludo Dice Roll Simulator\n");
    printf("Enter number of rolls: ");
    scanf("%d", &rolls);

    if (rolls <= 0) {
        printf("Invalid number of rolls!\n");
        return 0;
    }

    srand(time(NULL));

    for (i = 0; i < rolls; i++) {
        int res = (rand() % sides) + 1;
        freq[res]++;
    }

    printf("\nFace\tCount\tPercent\n");
    for (i = 1; i <= sides; i++) {
        float p = (freq[i] * 100.0f) / rolls;
        printf("%d\t%d\t%.2f%%\n", i, freq[i], p);
    }

    printf("\nDistribution Graph:\n");
    for (i = 1; i <= sides; i++) {
        printf("%d: ", i);
        int j, stars = (freq[i] * 50) / rolls;
        for (j = 0; j < stars; j++)
            printf("*");
        printf("\n");
    }

    return 0;
}