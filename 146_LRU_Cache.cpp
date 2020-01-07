# include <unordered_map>
# include <queue>
# include <iostream>

using namespace std;

struct ValueAndAccessNumber
{
	int myvalue = 0;
	int access_number = 0;
};

class LRUCache 
{
public:
	int capacity_all = 0;
	int current_used = 0;
	unordered_map<int, ValueAndAccessNumber> cache;
	queue<int> access_queue;
	LRUCache(int capacity) 
	{
		capacity_all = capacity;
		current_used = 0;
	}

	int get(int key) 
	{
		if (cache.find(key) != cache.end())
		{
			cache[key].access_number += 1;
			access_queue.push(key);
			return cache[key].myvalue;
		}
		return -1;
	}

	void put(int key, int value) 
	{
		if (cache.find(key) != cache.end())
		{
			cache[key].access_number += 1;
			cache[key].myvalue = value;
			access_queue.push(key);
		}
		else
		{
			current_used += 1;
			if (current_used > capacity_all)
			{
				while (!access_queue.empty())
				{
					int temp = access_queue.front();
					access_queue.pop();
					cache[temp].access_number -= 1;
					if (cache[temp].access_number == 0)
					{
						cache.erase(temp);
						current_used -= 1;
						break;
					}
				}
			}
			cache[key].myvalue = value;
			cache[key].access_number = 1;
			access_queue.push(key);
		}
		return;
	}
};

int main()
{
	LRUCache cache = LRUCache(2);
	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl;
	cache.put(3, 3);
	cout << cache.get(2) << endl;
	cache.put(4, 4);
	cout << cache.get(1) << endl;
	cout << cache.get(3) << endl;
	cout << cache.get(4) << endl;   
	return 0;
}