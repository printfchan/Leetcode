/************************************************************************/
/* 
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

	1
   / \
  /   \
 0 --- 2
	  / \
	  \_/
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <map>
using namespace std;


struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		UndirectedGraphNode * new_graph = NULL;
		if (node == NULL)
			return new_graph;

		map<int, UndirectedGraphNode*> node_map;
		vector<UndirectedGraphNode*> node_stack;

		new_graph = new UndirectedGraphNode(node->label);

		// insert the new graph into the map
		node_map[node->label] = new_graph;
		// insert the old graph into the stack
		node_stack.push_back(node);

		UndirectedGraphNode * current_node = NULL;
		UndirectedGraphNode * tmp = NULL;
		while (!node_stack.empty())
		{
			current_node = node_stack.back();
			node_stack.pop_back();

			for (int i = 0; i < current_node->neighbors.size(); ++i)
			{
				// if cannot find label in the map, insert it
				if (node_map.find(current_node->neighbors[i]->label) == node_map.end())
				{
					tmp = new UndirectedGraphNode(current_node->neighbors[i]->label);
					node_map[current_node->label]->neighbors.push_back(tmp);
					node_map[tmp->label] = tmp;

					node_stack.push_back(current_node->neighbors[i]);
				}
				else{
					node_map[current_node->label]->neighbors.push_back(node_map[current_node->neighbors[i]->label]);
				}
			}
		}

		return new_graph;
	}
};

int main()
{
	Solution solution;
	UndirectedGraphNode* node = NULL;
	
	node = new UndirectedGraphNode(0);
	node->neighbors.push_back(node);
	node->neighbors.push_back(node);

	solution.cloneGraph(node);

	system("pause");
	return 0;
}