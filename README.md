# Min cost flow problem
This program solves MCF problem only for bipartite graphs\
\
![image](https://user-images.githubusercontent.com/65315002/205456628-abe3dd99-974e-43a1-b876-d557ed365775.png)
# Usage
1. Create vector of departure nodes, destination nodes and vector of vector of Edge
```cpp
vector<Node> departure_nodes;
vector<Node> destination_nodes;
vector<vector<Edge>> edges;
```
2. Add desired nodes to the vectors
```cpp
departure_nodes.push_back(Node("a1", 53));
departure_nodes.push_back(Node("a2", 50));
departure_nodes.push_back(Node("a3", 77));

destination_nodes.push_back(Node("b1", 32));
destination_nodes.push_back(Node("b2", 33));
destination_nodes.push_back(Node("b3", 83));
destination_nodes.push_back(Node("b4", 10));
```
4. Add empty vector to vector, according to amount of created departure nodes
```cpp
	add_empty_vector(edges, departure_nodes.size());
```
5. Add nodes 
```cpp
edges[0].push_back(Edge(10));
edges[0].push_back(Edge(11));
edges[0].push_back(Edge(18));
edges[0].push_back(Edge(32));

edges[1].push_back(Edge(16));
edges[1].push_back(Edge(14));
edges[1].push_back(Edge(20));
edges[1].push_back(Edge(25));

edges[2].push_back(Edge(26));
edges[2].push_back(Edge(28));
edges[2].push_back(Edge(22));
edges[2].push_back(Edge(30));
```
<pre>
   edges[a][b]
   a - departure node
   b - destination node
</pre>
![image](https://user-images.githubusercontent.com/65315002/205458064-0afa5b6b-377e-48d2-a98e-5e95d5518b76.png)
6. Create an instance of MCP class and pass all vectors
```cpp
MCP problem(departure_nodes, destination_nodes, edges);
```
7. To output result write
```cpp
cout << "The total cost is: " << problem.getResult() << '\n';
```
