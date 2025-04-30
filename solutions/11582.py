import sys

def mod_exp(a, b, m):
    result = 1
    a = a % m
    while b > 0:
        if b % 2 == 1:
            result = (result * a) % m
        b = b // 2
        a = (a * a) % m
    return result

def get_pisano_period(m):
    pisano = [0, 1]
    prev, curr = 0, 1
    repeated = False

    while not repeated:
        prev, curr = curr, (prev + curr) % m
        pisano.append(curr)

        if prev == 0 and curr == 1:
            pisano.pop()
            pisano.pop()
            repeated = True

    return pisano
    
def main():
    input_data = sys.stdin.read().split()
    cases = int(input_data[0])
    idx = 1
    pisanos = {}

    for i in range(cases):
        a = int(input_data[idx])
        b = int(input_data[idx + 1])
        n = int(input_data[idx + 2])
        idx += 3

        if n == 1:
            print(0)
        else:
            if n not in pisanos:
                pisanos[n] = get_pisano_period(n)
            print(pisanos[n][mod_exp(a, b, len(pisanos[n]))])

if __name__ == '__main__':
    main()
