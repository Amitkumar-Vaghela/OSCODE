def find_waiting_time(processes, n, bt, wt, quantum):
    rem_bt = bt.copy()
    t = 0
    while True:
        flag = True
        for i in range(n):
            if rem_bt[i] > 0 and t < processes[i]:
                flag = False
                t += 1
            if rem_bt[i] > 0 and t == processes[i]:
                wt[i] += quantum
                t += quantum
                rem_bt[i] -= quantum
                if rem_bt[i] <= 0:
                    wt[i] += rem_bt[i]
                    rem_bt[i] = 0
        if flag:
            break
def find_turnaround_time(processes, n, bt, wt, tat):
    for i in range(n):
        tat[i] = bt[i] + wt[i]

def find_average_time(processes, n, bt, quantum):
    wt = [0] * n
    tat = [0] * n
    total_wt = 0
    total_tat = 0
    find_waiting_time(processes, n, bt, wt, quantum)
    find_turnaround_time(processes, n, bt, wt, tat)
    print("Process\tBurst Time\tWaiting Time\tTurnaround Time")
    for i in range(n):
        total_wt += wt[i]
        total_tat += tat[i]
        print(f"P{processes[i]}\t\t{bt[i]}\t\t{wt[i]}\t\t{tat[i]}")
    print(f"Average waiting time = {total_wt / n:.2f}")
    print(f"Average turnaround time = {total_tat / n:.2f}")

if __name__ == "__main__":
    print("Name: Amitkumar, ERP No: 2203031050777")
    processes = [1, 2, 3, 4, 5]
    n = len(processes)
    burst_time = [19, 5, 8, 1, 1]
    quantum = 2
    find_average_time(processes, n, burst_time, quantum)