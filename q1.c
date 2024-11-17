#include <stdio.h>

int totalWeight(int box[][10], int numBoxes[], int boxIndex) {
    int total = 0;
    if (boxIndex < 0) {
        return 0;
    }
    
    for (int i = 0; i < numBoxes[boxIndex]; i++) {
        total += box[boxIndex][i];
    }

    total += totalWeight(box, numBoxes, boxIndex - 1);
    return total;
}

int main() {
    int box[][10] = {{2, 5}, {3, 4, 1}, {}, {2}, {3}};
    int numBoxes[] = {2, 3, 0, 1, 1};
    int boxLen = sizeof(numBoxes) / sizeof(numBoxes[0]);

    int total = totalWeight(box, numBoxes, boxLen - 1);
    printf("Total weight of all boxes: %d\n", total);

    return 0;
}
