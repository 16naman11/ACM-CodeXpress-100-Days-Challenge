'''You are given an array of n points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Print the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.'''


class UnionFind:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.rank = [0] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)

        if root_x != root_y:
            if self.rank[root_x] < self.rank[root_y]:
                self.parent[root_x] = root_y
            elif self.rank[root_x] > self.rank[root_y]:
                self.parent[root_y] = root_x
            else:
                self.parent[root_x] = root_y
                self.rank[root_y] += 1


def manhattan_distance(point1, point2):
    return abs(point1[0] - point2[0]) + abs(point1[1] - point2[1])


def minimum_cost_to_connect_points(points):
    n = len(points)
    edges = []

    for i in range(n):
        for j in range(i + 1, n):
            edges.append((i, j, manhattan_distance(points[i], points[j])))

    edges.sort(key=lambda x: x[2])

    uf = UnionFind(n)
    total_cost = 0

    for edge in edges:
        u, v, cost = edge
        if uf.find(u) != uf.find(v):
            uf.union(u, v)
            total_cost += cost

    return total_cost


# Input reading and processing
T = int(input())
for _ in range(T):
    n = int(input())
    points = []
    for _ in range(n):
        point = list(map(int, input().split()))
        points.append(point)

    result = minimum_cost_to_connect_points(points)
    print(result)
