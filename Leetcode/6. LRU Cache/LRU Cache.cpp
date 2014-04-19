/************************************************************************/
/* 
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.

set(key, value) - Set or insert the value if the key is not already present. 
When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

*/
/************************************************************************/

#include <iostream>
#include <unordered_map>
using namespace std;

typedef struct DLNode
{
	DLNode *pre;
	int key;
	int val;
	DLNode *next;
	DLNode(int o_key, int o_val) :key(o_key), val(o_val), pre(NULL), next(NULL)
	{}
}DLNode;

class LRUCache{
public:
	LRUCache(int o_capacity) :capacity(o_capacity), head(NULL), tail(NULL)
	{
		size = 0;
	}

	// if get key exists , move it to the head
	int get(int key) {
		unordered_map<int, DLNode*>::iterator it;
		it = cache_map.find(key);

		if (it == cache_map.end())
		{
			return -1;
		}
		if (it->second->key != head->key)
		{
			it->second->pre->next = it->second->next;
			if (it->second->next != NULL)
			{
				it->second->next->pre = it->second->pre;
			}
			else{
				tail = it->second->pre;
			}

			it->second->pre = NULL;
			it->second->next = head;
			head->pre = it->second;

			head = it->second;
		}
		return it->second->val;
		
	}

	void set(int key, int value) {
		AddNewItem(key, value);
	}

private:
	void AddNewItem(int key, int value)
	{
		unordered_map<int, DLNode*>::iterator it;
		it = cache_map.find(key);

		// if key exists
		if (it != cache_map.end())
		{
			// if key exists, the cache is not empty
			it->second->val = value;
			if (it->second->key != head->key)
			{
				it->second->pre->next = it->second->next;
				if (it->second->next != NULL)
				{
					it->second->next->pre = it->second->pre;
				}
				else{
					tail = it->second->pre;
				}

				it->second->pre = NULL;
				it->second->next = head;
				head->pre = it->second;

				head = it->second;
			}
		}
		else{
			// create a new node;
			DLNode* new_node = new DLNode(key, value);
			if (size == 0)
			{
				head = new_node;
				tail = new_node;
			}
			else{
				head->pre = new_node;
				new_node->next = head;
				head = new_node;
			}
			cache_map[key] = new_node;
			size++;
		}
		if (size > capacity)
		{
			tail = tail->pre;
			cache_map.erase(tail->next->key);
			tail->next = NULL;
			size--;
		}
	}

private:
	unordered_map<int, DLNode*> cache_map;
	DLNode *head;
	DLNode *tail;
	int size;
	const int capacity;
};

int main()
{
	LRUCache lru(2);
	
	lru.set(2, 1);
	lru.set(1, 1);
	cout << lru.get(2) << endl;
	lru.set(4, 1);
	cout << lru.get(1) << endl;
	cout << lru.get(2) << endl;
	/*lru.set(2, 2);
	lru.set(3, 3);
	lru.set(1, 1);
	lru.set(4, 4);
	lru.set(2, 2);
	*/
	//cout << lru.get(4) << endl;

	system("pause");
	return 0;
}
