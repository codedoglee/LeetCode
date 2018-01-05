#ifndef CLONE_GRAPH_H_
#define CLONE_GRAPH_H_

/*
 * Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 * OJ's undirected graph serialization:
 * Nodes are labeled uniquely.
 * We use '#' as a separator for each node, and ',' as a separator for node label and each neighbor of the node.
 *
 * As an example, consider the serialized graph {0,1,2# 1,2# 2,2}.
 * The graph has a total of three nodes, and therefore contains three parts as separated by #.
 * First node is labeled as 0. Connect node0 to both node1 and 2.
 * Second node is labeled as 1. Connect node1 to node2.
 * Third node is labeled as 2. Connect node2 to node2(itself), thus forming a self-cycle.
 *
 * Visually, the graph looks like the following:
 * 	   1
 * 	  / \
 * 	 /   \
 * 	0 --- 2
 * 		 / \
 * 		 \_/
 */
#include <vector>
#include <queue>
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
    	if (node == 0) {
    		return 0;
    	}
    	UndirectedGraphNode* cloneNode = new UndirectedGraphNode(node->label);
    	map<int, UndirectedGraphNode*> hashClone;
    	hashClone.insert(pair<int, UndirectedGraphNode*>(cloneNode->label, cloneNode));

    	map<int, vector<int> > labelMap;
    	queue<UndirectedGraphNode*> q;
    	q.push(node);
    	while (!q.empty()) {
    		UndirectedGraphNode* top = q.front();
    		q.pop();
    		if (labelMap.find(top->label) != labelMap.end()) {
    			continue;
    		}
    		vector<int> tvec;
    		for (unsigned int i = 0; i < top->neighbors.size(); ++i) {
    			if (hashClone.find(top->neighbors[i]->label) == hashClone.end()) {
    				UndirectedGraphNode* temp = new UndirectedGraphNode(top->neighbors[i]->label);
    				hashClone.insert(pair<int, UndirectedGraphNode*>(top->neighbors[i]->label, temp));
    			}
    			tvec.push_back(top->neighbors[i]->label);
    			q.push(top->neighbors[i]);
    		}
    		labelMap.insert(pair<int, vector<int> >(top->label, tvec));
    	}

    	map<int, vector<int> >::iterator it = labelMap.begin();
    	for (; it != labelMap.end(); ++it) {
    		UndirectedGraphNode* cur = hashClone[it->first];
    		for (unsigned int i = 0; i < it->second.size(); ++i) {
    			cur->neighbors.push_back(hashClone[it->second[i]]);
    		}
    	}
    	return cloneNode;
    }
};



#endif /* CLONE_GRAPH_H_ */
