#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum) {
    int rem_bt[n];
    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i];

    int t = 0;
    while (1) {
        int flag = 1;
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0 && t < processes[i]) {
                flag = 0;
                t++;
            }
            if (rem_bt[i] > 0 && t == processes[i]) {
                wt[i] += quantum;
                t += quantum;
                rem_bt[i] -= quantum;
                if (rem_bt[i] <= 0) {
                    wt[i] += rem_bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (flag == 1)
            break;
    }
}

void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findAverageTime(int processes[], int n, int bt[], int quantum) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(processes, n, bt, wt, quantum);
    findTurnaroundTime(processes, n, bt, wt, tat);
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("P%d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }
    printf("Average waiting time = %.2f\n", (float)total_wt / n);
    printf("Average turnaround time = %.2f\n", (float)total_tat / n);
}

int main() {
    printf("Name: Amitkumar, ERP No: 2203031050777\n");
    int processes[] = {1, 2, 3, 4, 5};
    int n = sizeof(processes) / sizeof(processes[0]);
    int burst_time[] = {19, 5, 8, 1, 1};
    int quantum = 2;
    findAverageTime(processes, n, burst_time, quantum);
    return 0;
}