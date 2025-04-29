import fileinput

def matrix_mult(a, b, mod):
    return [
        [(a[0][0]*b[0][0] + a[0][1]*b[1][0]) % mod,
         (a[0][0]*b[0][1] + a[0][1]*b[1][1]) % mod],
        [(a[1][0]*b[0][0] + a[1][1]*b[1][0]) % mod,
         (a[1][0]*b[0][1] + a[1][1]*b[1][1]) % mod]
    ]

def matrix_pow(mat, power, mod):
    result = [[1, 0], [0, 1]]
    while power:
        if power % 2 == 1:
            result = matrix_mult(result, mat, mod)
        mat = matrix_mult(mat, mat, mod)
        power //= 2
    return result

def fibonacci_mod(n, m):
    if n == 0:
        return 0
    base = [[1, 1], [1, 0]]
    result = matrix_pow(base, n - 1, pow(2, m))
    return result[0][0]

def main():
    for line in fileinput.input():
        n, m = map(int, line.split()[:2])
        print(fibonacci_mod(n, m))

if __name__ == '__main__':
    main()
