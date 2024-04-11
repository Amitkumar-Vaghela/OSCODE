class Process:
    def __init__(self, pid, arrival_time, burst_time):
        self.id = pid
        self.at = arrival_time
        self.bt = burst_time
        self.ct = 0
        self.tat = 0
        self.wt = 0

def input_processes(n):
    processes = []
    for i in range(n):
        arrival_time = int(input(f"Enter arrival time for process {i + 1}: "))
        burst_time = int(input(f"Enter burst time for process {i + 1}: "))
        processes.append(Process(i + 1, arrival_time, burst_time))
    return processes

def sort_processes(processes):
    return sorted(processes, key=lambda x: x.at)

def calculate_metrics(processes):
    sum_wt = 0
    sum_tat = 0
    for p in processes:
        p.wt = sum_wt
        sum_wt += p.bt
        p.ct = p.wt + p.bt
        p.tat = p.ct - p.at
        sum_tat += p.tat
    return sum_wt, sum_tat

def display_results(processes, total_wt, total_tat):
    print("\nProcess \tArrival\tBurst\tCompletion\tTurn Around\tWaiting")
    for p in processes:
        print(f"{p.id}\t\t{p.at}\t{p.bt}\t{p.ct}\t\t{p.tat}\t\t{p.wt}")
    print(f"\nTotal waiting time: {total_wt}")
    print(f"Total Turn-around time: {total_tat}")
    n = len(processes)
    print(f"Average waiting time: {total_wt / n:.2f}")
    print(f"Average Turn-around time: {total_tat / n:.2f}")

if __name__ == "__main__":
    print("Name: Amitkumar Vaghela, ERP No: 2203031050777")
    n = int(input("Enter the number of processes in your system: "))
    processes = input_processes(n)
    sorted_processes = sort_processes(processes)
    total_wt, total_tat = calculate_metrics(sorted_processes)
    display_results(sorted_processes, total_wt, total_tat)
