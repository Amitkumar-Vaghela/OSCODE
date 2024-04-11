#include <stdio.h>

void findWaitingTime(int process[], int n, int bt[], int wt[]) {
    int i;
    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = bt[i-1] + wt[i-1];
    }
}

void findTurnaroundTime(int process[], int n, int bt[], int wt[], int tat[]) {
    int i;
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findAverageTime(int processes[], int n, int burst_time[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, burst_time, wt);
    findTurnaroundTime(processes, n, burst_time, wt, tat);

    printf("Process  Burst time  Waiting time  Turnaround time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;

    printf("\nAverage waiting time: %.2f", avg_wt);
    printf("\nAverage turnaround time: %.2f", avg_tat);
}

int main() {
    int processes[] = {1, 2, 3, 4};
    int n = sizeof(processes)/sizeof(processes[0]);
    int burst_time[] = {7, 5, 6, 10};

    printf("Name: Amitkumar vaghela, ERP No: 2203031050777\n");
    findAverageTime(processes, n, burst_time);

    return 0;
}