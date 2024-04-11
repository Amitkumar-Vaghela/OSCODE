#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
} Process;

void input(Process *p, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &p[i].at);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &p[i].bt);
        p[i].id = i + 1;
    }
}

void sort(Process *p, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void calc(Process *p, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += p[i].at;
        p[i].wt = sum;
        p[i].ct = p[i].wt + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
    }
}

void show(Process *p, int n) {
    int total_wt = 0, total_tat = 0;
    printf("\nProcess\tArrival\tBurst\tCompletion\tTurn Around\tWaiting\n");
    for (int i = 0; i < n; i++) {
        total_tat += p[i].tat;
        total_wt += p[i].wt;
        printf("%d\t\t%d\t%d\t%d\t\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("\nTotal waiting time: %d\n", total_wt);
    printf("Total Turn-around time: %d\n", total_tat);
    printf("Average waiting time: %.2f\n", (float)total_wt / n);
    printf("Average Turn-around time: %.2f\n", (float)total_tat / n);
}

int main() {
    int n;
    printf("Name: Vidhi Pateliya, ERP No: 2203031241412");
    printf("\nEnter the no of processes in your system: ");
    scanf("%d", &n);
    Process *p = malloc(n * sizeof(Process));
    input(p, n);
    sort(p, n);
    calc(p, n);
    show(p, n);
    free(p);
    return 0;
}