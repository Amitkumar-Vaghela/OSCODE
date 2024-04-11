#include <stdio.h>

int main() {
    printf("Amitkumar, CRP No: 2203001442\n");
    int pros = 3, rars = 3, pas[3] = {0, 1, 2}, rasa[3] = {2, 1, 3}, avail[3] = {3, 3, 3};
    int f[pros], need[pros][rars], allo[pros][rars];
    for (int k = 0; k < pros; k++) {
        f[k] = 0;
    }
    for (int i = 0; i < pros; i++) {
        for (int j = 0; j < rars; j++) {
            allo[i][j] = rasa[i];
        }
    }
    int flag = 1, y, ed, ans[pros];
    while (flag) {
        flag = 0;
        for (int i = 0; i < pros; i++) {
            if (f[i] == 0) {
                int sum = 0;
                for (int j = 0; j < rars; j++) {
                    if (need[i][j] > avail[j]) {
                        break;
                    }
                    sum += need[i][j];
                }
                if (sum == 0) {
                    ans[ed] = i;
                    ed++;
                    for (y = 0; y < rars; y++) {
                        avail[y] += allo[i][y];
                    }
                    f[i] = 1;
                    flag = 1;
                }
            }
        }
    }
    if (ed < pros) {
        printf("The following system is not safe\n");
    } else {
        printf("Following is the safe sequence\n");
        for (int i = 0; i < pros; i++) {
            printf("P%d ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}