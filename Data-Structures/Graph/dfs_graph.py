from collections import defaultdict
def make_graph(edge_list):
    adj_list = defaultdict(list)
    for i in edge_list:
        adj_list[i[0]].append(i[1])
        adj_list[i[1]].append(i[0])
    return adj_list

def dfs(graph,visited,s):
    if visited[s-1]:
        return
    print(s)
    visited[s-1] = True
    for i in graph[s]:
        dfs(graph,visited,i)

if __name__ == "__main__":
    edge_list = [[1,2],[1,4],[2,5],[2,3],[5,3]]
    graph = make_graph(edge_list)
    visited = [False]*len(graph)
    dfs(graph,visited,1)