#define NULL nullptr

#include <iostream>
#include <sstream>
#include <string>

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

void deleteListCycle(ListNode* rootnode, ListNode* cyclenode, int n=0)
{
	if (rootnode->next == cyclenode)
	{
		n++;
		if (n < 2)
		{
			deleteListCycle(rootnode->next, cyclenode, n);
		}
	}
	delete rootnode;
	return;
}

class Solution 
{
public:
	ListNode* detectCycle(ListNode* head) 
	{
		if (head == NULL || head->next == NULL)
		{
			return NULL;
		}
		ListNode* slow_node = head;
		ListNode* fast_node = head->next;
		while (slow_node != fast_node)
		{
			if (slow_node->next == NULL || fast_node->next == NULL || fast_node->next->next == NULL)
			{
				return NULL;
			}
			slow_node = slow_node->next;
			fast_node = fast_node->next->next;
		}
		slow_node = slow_node->next;
		while (head != slow_node)
		{
			head = head->next;
			slow_node = slow_node->next;
		}
		return slow_node;
	}
};

int main()
{
	string s;
	getline(cin, s);
	int n = s.find_last_of(' ');
	string s1(s.begin(), s.begin() + n);
	string s2(s.begin() + n, s.end());
	istringstream is1(s1);
	istringstream is2(s2);
	ListNode* ln = NULL;
	ListNode* ln_root = NULL;
	int temp = 0;
	while (is1 >> temp)
	{
		if (ln)
		{
			ln->next = new ListNode(temp);
			ln = ln->next;
		}
		else
		{
			ln = new ListNode(temp);
			ln_root = ln;
		}
	}
	while (is2 >> temp)
	{
		if (temp > 0)
		{
			ListNode* ln_temp = ln_root;
			while (temp--)
			{
				temp--;
				ln_temp = ln_temp->next;
			}
			ln->next = ln_temp;
		}
	}
	Solution solution;
	ListNode* ln_result = solution.detectCycle(ln_root);
	if (ln_result)
	{
		cout << ln_result->val << endl;
		deleteListCycle(ln_root, ln_result);
	}
	else
	{
		cout << "none" << endl;
		deleteList(ln_root);
	}
	return 0;
}