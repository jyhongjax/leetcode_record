# include <unordered_map>
using namespace std;

// Definition for a Node.
class Node 
{
public:
	int val;
	Node* next;
	Node* random;

	Node() {}

	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};


class Solution {
public:
	unordered_map <Node*, Node*> node_map;

	Node* copyRandomList(Node* head) 
	{
		Node* result_root = NULL;
		Node* result_node = NULL;
		if (head == NULL)
		{
			return result_root;
		}
		result_root = new Node(head->val, NULL, NULL);
		node_map[head] = result_root;
		if (head->random == head)
		{
			result_root->random = result_root;
		}
		result_node = result_root;
		while (head->next != NULL)
		{
			if (node_map.find(head->next) == node_map.end())
			{
				if (result_root == result_node)
				{
					result_root->next = new Node(head->next->val, NULL, NULL);
					result_node = result_root;
				}
				else
				{
					result_node->next = new Node(head->next->val, NULL, NULL);
				}
				node_map[head->next] = result_node->next;
			}
			else
			{
				result_node->next = node_map[head->next];
			}
			if (head->random != NULL)
			{
				if (node_map.find(head->random) == node_map.end())
				{
					if (result_root == result_node)
					{
						result_root->random = new Node(head->random->val, NULL, NULL);
						result_node = result_root;
					}
					else
					{
						result_node->random = new Node(head->random->val, NULL, NULL);
					}
					node_map[head->random] = result_node->random;
				}
				else
				{
					result_node->random = node_map[head->random];
				}
			}
			result_node = result_node->next;
			head = head->next;
		}
		if (head->random != NULL)
		{
			if (node_map.find(head->random) == node_map.end())
			{
				if (result_root == result_node)
				{
					result_root->random = new Node(head->random->val, NULL, NULL);
					result_node = result_root;
				}
				else
				{
					result_node->random = new Node(head->random->val, NULL, NULL);
				}
				node_map[head->random] = result_node->random;
			}
			else
			{
				result_node->random = node_map[head->random];
			}
		}
		return result_root;
	}
};