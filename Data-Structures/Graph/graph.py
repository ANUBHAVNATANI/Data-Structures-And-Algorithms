class Vertex:
    def __init__(self, key):
        self.id = key
        self.connectedTo = {}

    def addNeighbor(self, nbr, weight=0):
        self.connectedTo[nbr] = weight

    def __str__(self):
        return str(self.id)+"connectedTo:"+str([x.id for x in self.connectedTo])

    def getConnections(self):
        return self.connectedTo.keys()

    def getId(self):
        return self.id

    def getWeight(self, nbr):
        return self.connectedTo[nbr]


class Graph:
    def __init__(self):
        self.vertList = {}
        self.numVertex = 0

    def addVertex(self, key):
        self.numVertex = self.numVertex+1
        nVertex = Vertex(key)
        self.vertList[key] = nVertex
        return nVertex

    def getVertex(self, n):
        if n in self.vertList:
            return self.vertList[n]
        else:
            return None

    def __contains__(self, n):
        return n in self.vertList

    def addEdge(self, f, t, cost=0):
        if f not in self.vertList:
            nv = self.addVertex(f)
        if t not in self.vertList:
            nv = self.addVertex(t)
        self.vertList[f].addNeighbor(self.vertList[t], cost)

    def getVertices(self):
        return self.vertList.keys()

    def __iter__(self):
        return iter(self.vertList.values())


if __name__ == "__main__":
    g = Graph()
    for i in range(5):
        g.addVertex(i)
    print(g.vertList)
    g.addEdge(0, 1, 5)
    g.addEdge(2, 4, 6)
    g.addEdge(2, 3, 6)

    for v in g:
        for w in v.getConnections():
            print(v.getId(), w.getId())
