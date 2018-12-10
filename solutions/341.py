import sys
import queue

class Edge:

    def __init__(self, to_node, cost):
        self.to_node = to_node
        self.cost = cost

class VisitedNode:

    def __init__(self):
        self.visited = False
        self.cost = 10000000
        self.path = []


def dijkstra(graph, from_node, to_node):
    visited_nodes = [VisitedNode() for i in range(len(graph))]
    visited_nodes[from_node].cost = 0
    visited_nodes[from_node].path = [from_node]
    p_queue = queue.PriorityQueue()
    p_queue.put((0, from_node))
    while not p_queue.empty():
        cost, root_node = p_queue.get()

        if visited_nodes[root_node].visited:
            continue

        for edge in graph[root_node]:
            if visited_nodes[root_node].cost + edge.cost < visited_nodes[edge.to_node].cost:
                visited_nodes[edge.to_node].cost = visited_nodes[root_node].cost + edge.cost
                visited_nodes[edge.to_node].path = visited_nodes[root_node].path + [edge.to_node]
                p_queue.put((visited_nodes[edge.to_node].cost, edge.to_node))

    return visited_nodes[to_node].cost, visited_nodes[to_node].path

def main():
    case = 0
    number_of_nodes = int(sys.stdin.readline())
    while number_of_nodes > 0:
        graph = []
        for i in range(number_of_nodes):
            line = sys.stdin.readline()
            number_of_edges = int(line.split()[0])
            edges = []
            for j in range(number_of_edges):
                to_node = int(line.split()[j*2+1]) - 1
                cost = int(line.split()[j*2+2])
                edges.append(Edge(to_node=to_node, cost=cost))
            graph.append(edges)

        case += 1
        line = sys.stdin.readline()

        from_node = int(line.split()[0]) - 1
        to_node = int(line.split()[1]) - 1
        delay, path = dijkstra(graph, from_node, to_node)
        formatted_path = (' {}'*len(path)).format(*[i+1 for i in path])
        print('Case {}: Path ={}; {} second delay'.format(case, formatted_path, delay))

        line = sys.stdin.readline()
        while len(line.split()) == 0:
            line = sys.stdin.readline()

        number_of_nodes = int(line)


if __name__ == '__main__':
    main()
