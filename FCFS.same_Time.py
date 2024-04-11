def find_waiting_time(process, n, bt, wt):
    wt[0] = 0
    for i in range(1, n):
        wt[i] = bt[i - 1] + wt[i - 1]

def find_turnaround_time(process, n, bt, wt, tat):
    for i in range(n):
        tat[i] = bt[i] + wt[i]

def find_average_time(processes, n, burst_time):
    wt = [0] * n
    tat = [0] * n
    total_wt = 0
    total_tat = 0

    find_waiting_time(processes, n, burst_time, wt)
    find_turnaround_time(processes, n, burst_time, wt, tat)

    print("Process\tBurst time\tWaiting time\tTurnaround time")
    for i in range(n):
        print(f"{processes[i]}\t\t{burst_time[i]}\t\t{wt[i]}\t\t{tat[i]}")
        total_wt += wt[i]
        total_tat += tat[i]

    avg_wt = total_wt / n
    avg_tat = total_tat / n

    print(f"\nAverage waiting time: {avg_wt:.2f}")
    print(f"Average turnaround time: {avg_tat:.2f}")

if __name__ == "__main__":
    processes = [1, 2, 3, 4]
    n = len(processes)
    burst_time = [6, 5, 3, 2]

    find_average_time(processes, n, burst_time)
