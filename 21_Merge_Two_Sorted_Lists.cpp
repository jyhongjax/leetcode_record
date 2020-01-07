# include <iostream>
# include <string>
# include <sstream>

using namespace std;

struct ListNode 
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

void deleteList(ListNode* rootnode)
{
	if (rootnode->next != NULL)
	{
		deleteList(rootnode->next);
	}
	delete rootnode;
	return;
}

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
	{
		ListNode* merge_list_root = NULL;
		ListNode* merge_list_node = NULL;
		ListNode* min_node = NULL;
		while (l1 != NULL || l2 != NULL)
		{
			if (l1 == NULL)
			{
				min_node = l2;
			}
			else
			{
				if (l2 == NULL || l1->val < l2->val)
				{
					min_node = l1;
				}
				else
				{
					min_node = l2;
				}
			}
			if (merge_list_root == NULL)
			{
				merge_list_root = new ListNode(min_node->val);
				merge_list_node = merge_list_root;
			}
			else
			{
				merge_list_node->next = new ListNode(min_node->val);
				merge_list_node = merge_list_node->next;
			}
			if (min_node == l1)
			{
				l1 = l1->next;
			}
			else
			{
				l2 = l2->next;
			}
		}
		return merge_list_root;
	}
};

void printList(ListNode* rootnode)
{
	cout << rootnode->val << " ";
	if (rootnode->next != NULL)
	{
		printList(rootnode->next);
	}
	else
	{
		cout << endl;
	}
}

int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int temp = 0;
	istringstream isl(s1);
	istringstream is2(s2);
	ListNode* l1 = NULL;
	ListNode* l2 = NULL;
	ListNode* l1_root = NULL;
	ListNode* l2_root = NULL;
	while (isl >> temp)
	{
		if (l1 == NULL)
		{
			l1 = new ListNode(temp);
			l1_root = l1;
		}
		else
		{
			l1->next = new ListNode(temp);
			l1 = l1->next;
		}
	}
	while (is2 >> temp)
	{
		if (l2 == NULL)
		{
			l2 = new ListNode(temp);
			l2_root = l2;
		}
		else
		{
			l2->next = new ListNode(temp);
			l2 = l2->next;
		}
	}
	Solution solution;
	ListNode* merge_node = solution.mergeTwoLists(l1_root, l2_root);
	printList(merge_node);
	deleteList(l1_root);
	deleteList(l2_root);
	deleteList(merge_node);
	return 0;
}