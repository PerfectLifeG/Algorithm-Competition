def assign_toys(n, a, max_waiting_time):
    carvers = [0, 0, 0]  # Initialize waiting times for each carver
    for pattern in a:
        min_waiting_time = min(carvers)  # Find the carver with the minimum waiting time
        max_waiting_time = max(min_waiting_time, max_waiting_time)
        carvers[carvers.index(min_waiting_time)] += abs(pattern - min_waiting_time)  # Update waiting time
    return max_waiting_time

def find_best_max_waiting_time(t, test_cases):
    for _ in range(t):
        n = test_cases[_][0]
        a = test_cases[_][1]

        lb = 0
        ub = 10**9

        while lb < ub:
            mid = (lb + ub) // 2
            if assign_toys(n, a, mid) <= mid:
                ub = mid
            else:
                lb = mid + 1

        print(lb)

# Read input
t = int(input())
test_cases = []
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    test_cases.append((n, a))

# Solve the problem
find_best_max_waiting_time(t, test_cases)
