import sys

def bfs(graph, start_i, start_j):
    if start_i < 0 or start_j < 0 or start_i >= len(graph) or start_j >= len(graph[start_i]):
        return 0
    if type(graph[start_i][start_j]) is int:
        return graph[start_i][start_j]

    total = 0
    stack = [(start_i, start_j)]
    while len(stack) > 0:
        i, j = stack.pop()

        if i < 0 or j < 0 or i >= len(graph) or j >= len(graph[i]):
            continue

        if graph[i][j] != 'W':
            continue

        graph[i][j] = 'X'
        total += 1
        stack.append((i-1, j))
        stack.append((i-1, j+1))
        stack.append((i, j+1))
        stack.append((i+1, j+1))
        stack.append((i+1, j))
        stack.append((i+1, j-1))
        stack.append((i, j-1))
        stack.append((i-1, j-1))

    bfs_mark(graph, start_i, start_j, total)
    return total

def bfs_mark(graph, i, j, mark):
    stack = [(i, j)]
    while len(stack) > 0:
        i, j = stack.pop()

        if i < 0 or j < 0 or i >= len(graph) or j >= len(graph[i]):
            continue

        if graph[i][j] != 'X':
            continue

        graph[i][j] = mark
        stack.append((i-1, j))
        stack.append((i-1, j+1))
        stack.append((i, j+1))
        stack.append((i+1, j+1))
        stack.append((i+1, j))
        stack.append((i+1, j-1))
        stack.append((i, j-1))
        stack.append((i-1, j-1))


def main():
    cases = int(sys.stdin.readline())
    sys.stdin.readline()
    first_case = True
    for case in range(cases):
        matrix = []
        while True:
            line = sys.stdin.readline().replace('\n', '')
            if line[0] != 'W' and line[0] != 'L':
                break
            matrix.append(line)

        if first_case:
            first_case = False
        else:
            print()

        graph = [[c for c in word] for word in matrix]

        while True:
            if len(line.split()) < 2:
                break
            else:
                i = int(line.split()[0]) - 1
                j = int(line.split()[1]) - 1
                print(bfs(graph, i, j))
                line = sys.stdin.readline().replace('\n', '')


if __name__ == '__main__':
    main()
