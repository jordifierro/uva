import sys

def largest_submatrix(square_matrix):
    n = len(square_matrix)
    dp = [[[False for k in range(n)] for j in range(n)] for i in range(n)]
    for i in range(n):
        for j in range(n):
            k = j
            for l in range(j, n):
                if square_matrix[i][l] == '1':
                    dp[i][k][l] = True
                else:
                    k = l + 1

    maximum = 0
    for i in range(n):
        for j in range(i, n):
            k = 0
            for l in range(k, n):
                if dp[l][i][j]:
                    maximum = max(maximum, (j-i+1)*(l-k+1))
                else:
                    k = l + 1

    return maximum


def main():
    cases = int(sys.stdin.readline())
    first_case = True
    for case in range(cases):
        sys.stdin.readline()
        line = sys.stdin.readline().replace('\n', '')
        matrix = []
        matrix.append(line)
        for i in range(1, len(line)):
            matrix.append(sys.stdin.readline().replace('\n', ''))

        if first_case:
            first_case = False
        else:
            print()
        print(largest_submatrix(matrix))

if __name__ == '__main__':
    main()
