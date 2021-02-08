#include <iostream>
#include "list.h"
	List::List() : first{nullptr} {}

	List::~List()
	{
		Node *n = first;
		while (n != nullptr)
		{
			Node *temp = n->next;
			delete n;
			n = temp;
		}
	}

	bool List::exists(int d) const
	{
		Node *n = first;
		while (n != nullptr)
		{
			if (n->value == d)
			{
				return true;
			}
			n = n->next;
		}
		return false;
	}

	int List::size() const
	{
		int count = 0;
		Node *n = first;
		while (n != nullptr)
		{
			count++;
			n = n->next;
		}
		return count;
	}

	bool List::empty() const
	{
		return first == nullptr;
	}

	void List::insertFirst(int d)
	{
		Node *temp = first;
		first = new Node(d, temp);
	}

	/* removes the first element less than/equal to/greater than d,depending on the value of df. Does nothing if there is no valueto remove. The enum values are accessed with List::DeleteFlag::LESS,..., outside the class */
	enum class DeleteFlag
	{
		LESS,
		EQUAL,
		GREATER
	};

	void List::remove(int d, DeleteFlag df)
	{
		Node *n = first;
		Node *n_old = first;
		while (n != nullptr)
		{
			switch (df)
			{
			case DeleteFlag::LESS:
				if (n->value < d)
				{
					removeNodes(n, n_old);
					return;
				}
				break;
			case DeleteFlag::EQUAL:
				if (n->value == d)
				{
					removeNodes(n, n_old);
					return;
				}
				break;
			case DeleteFlag::GREATER:
				if (n->value > d)
				{
					removeNodes(n, n_old);
					return;
				}
			}
			n_old = n;
			n = n->next;
		}
	}

	/* prints the contents of this list */
	void List::print() const
	{
		Node *n = first;
		while (n != nullptr)
		{
			std::cout << n->value << "\n"; 
			n = n->next;
		}
	}

	void List::removeNodes(Node *n, Node *n_old)
	{
		if (n == first)
		{
			first = first->next;
		}
		else
		{
			n_old->next = n->next;
		}
		delete n;
	}
