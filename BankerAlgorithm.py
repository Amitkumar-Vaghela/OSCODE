def main():
    print("Amitkumar, CRP No: 2203001442")
    pros = 3
    rars = 3
    pas = [0, 1, 2]
    rasa = [2, 1, 3]
    avail = [3, 3, 3]
    f = [0] * pros
    need = [[0] * rars for _ in range(pros)]
    allo = [[rasa[i] for _ in range(rars)] for i in range(pros)]
    flag = 1
    ed = 0
    ans = [0] * pros
    while flag:
        flag = 0
        for i in range(pros):
            if f[i] == 0:
                sum_need = sum(need[i][j] for j in range(rars))
                if sum_need == 0:
                    ans[ed] = i
                    ed += 1
                    for y in range(rars):
                        avail[y] += allo[i][y]
                    f[i] = 1
                    flag = 1
    if ed < pros:
        print("The following system is not safe")
    else:
        print("Following is the safe sequence")
        for i in range(pros):
            print("P%d" % ans[i], end=" ")

if __name__ == "__main__":
    main()
