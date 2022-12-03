#include <iostream>
#include <vector>

using namespace std;

class Edge;
class Node;

class Node
{
public:
	Node(string name, int flow)
	{
		this->name = name;
		this->flow = flow;
	} 
	string name{};
	int flow{};
};
class Edge
{
public:
	Edge(Node &from, Node &to, int cost)
	{
		this->cost = cost;
		this->from = &from;
		this->to = &to;
	}
	int cost;
	Node* from{ nullptr };
	Node* to{ nullptr };
};

class MCP 
{
public:
	MCP(vector<Node>& departure, vector<Node>& destination, vector<vector<Edge>>& edges)
	{
		int sum = 0;
		int temp_i{ 0 }, temp_j{ 0 };
		while(is_nodes_full(departure, destination) != true)
		{
			int min = INT32_MAX;
			for (int i = 0; i < departure.size(); i++)
			{
				if (departure[i].flow == 0)
					continue;
				int j = 0;
				for (; j < destination.size(); j++)
				{
					if (destination[j].flow == 0)
						continue;
					if (destination[j].flow >= departure[i].flow)
					{
						if ((edges[i][j].cost * departure[i].flow) < min)
						{
							min = edges[i][j].cost * departure[i].flow;
							temp_i = i;
							temp_j = j;
						}
					}
					else
					{
						if ((edges[i][j].cost * destination[j].flow) < min)
						{
							min = edges[i][j].cost * destination[j].flow;
							temp_i = i;
							temp_j = j;
						}
					}
				}
			}

			if (min != INT32_MAX)
			{
				if (departure[temp_i].flow >= destination[temp_j].flow)
				{
					departure[temp_i].flow -= destination[temp_j].flow;
					destination[temp_j].flow = 0;
					sum += min;
				}
				else if (departure[temp_i].flow < destination[temp_j].flow)
				{
					min = edges[temp_i][temp_j].cost * departure[temp_i].flow;
					sum += min;
					destination[temp_j].flow -= departure[temp_i].flow;
					departure[temp_i].flow = 0;
				}
			}
		}
		result = sum;
	}
	int getResult() { return result; }
private:
	bool is_nodes_full(vector<Node>& departure, vector<Node>& destination)
	{
		bool is_full1 = true, is_full2 = true;
		for (auto const& i : departure)
		{
			if (i.flow != 0)
			{
				is_full1 = false;
				break;
			}
		}
		for (auto const& i : destination)
		{
			if (i.flow != 0)
			{
				is_full2 = false;
				break;
			}
		}
		bool result = is_full1 || is_full2;
		return result;
	}
	int result;
};
void add_empty_vector(vector<vector<Edge>>& edges, size_t size)
{
	while(size--)
		edges.push_back(vector<Edge>());
}

int main()
{
	vector<Node> departure_nodes;
	vector<Node> destination_nodes;
	vector<vector<Edge>> edges;

	Node a1("a1", 53);
	Node a2("a2", 50);
	Node a3("a3", 77);
	departure_nodes.push_back(a1);
	departure_nodes.push_back(a2);
	departure_nodes.push_back(a3);

	add_empty_vector(edges, departure_nodes.size());


	Node b1("b1", 32);
	Node b2("b2", 33);
	Node b3("b3", 83);
	Node b4("b4", 10);

	edges[0].push_back(Edge(a1, b1, 10));
	edges[0].push_back(Edge(a1, b2, 11));
	edges[0].push_back(Edge(a1, b3, 18));
	edges[0].push_back(Edge(a1, b4, 32));

	edges[1].push_back(Edge(a2, b1, 16));
	edges[1].push_back(Edge(a2, b2, 14));
	edges[1].push_back(Edge(a2, b3, 20));
	edges[1].push_back(Edge(a2, b4, 25));

	edges[2].push_back(Edge(a3, b1, 26));
	edges[2].push_back(Edge(a3, b2, 28));
	edges[2].push_back(Edge(a3, b3, 22));
	edges[2].push_back(Edge(a3, b4, 30));


	destination_nodes.push_back(b1);
	destination_nodes.push_back(b2);
	destination_nodes.push_back(b3);
	destination_nodes.push_back(b4);

	MCP a(departure_nodes, destination_nodes, edges);
	cout << "The total cost is: " << a.getResult() << '\n';
}