from collections import defaultdict,deque
def make_graph(edge_list):
    adj_list = defaultdict(list)
    for i in edge_list:
        adj_list[i[0]].append(i[1])
        adj_list[i[1]].append(i[0])
    return adj_list

def bfs(graph,visited,s):
    queue = deque([])
    distance = [0]*len(graph)
    queue.append(s)
    visited[s-1] = True
    distance[s-1] = 0
    while(len(queue)!=0):
        s = queue.popleft()
        print(s)
        for i in graph[s]:
            if visited[i-1]:
                continue
            visited[i-1] = True
            distance[i-1] = distance[s-1]+1
            queue.append(i)
    print(distance)

if __name__ == "__main__":
    edge_list = [[1,2],[1,4],[2,5],[2,3],[5,6],[3,6]]
    graph = make_graph(edge_list)
    visited = [False]*len(graph)
    bfs(graph,visited,1)