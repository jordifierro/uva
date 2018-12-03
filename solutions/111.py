import fileinput

def lcs(list_a, list_b):
    dp = []
    dp = [[0 for o in range(len(list_b) + 1)] for e in range(len(list_a) + 1)]
    max_cs = 0
    for i in range(len(list_a)):
        for j in range(len(list_b)):
            if list_a[i] == list_b[j]:
                dp[i+1][j+1] = dp[i][j] + 1
            else:
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j])

            if dp[i+1][j+1] > max_cs:
                max_cs = dp[i+1][j+1]

    return max_cs

def main():
    length = None
    correct_order_map = None
    for case_line in fileinput.input():
        elements = [int(x) for x in case_line.split()]
        if len(elements) == length:
            if correct_order_array is None:
                correct_order_map = {str(elements[i]): i for i in range(len(elements))}
                correct_order_array = [correct_order_map[str(i+1)] for i in range(len(elements))]
            else:
                elements_map = {str(elements[i]): i for i in range(len(elements))}
                elements_array = [elements_map[str(i+1)] for i in range(len(elements))]
                print(lcs(correct_order_array, elements_array))
        else:
            length = elements[0]
            correct_order_array = None

if __name__ == '__main__':
    main()
