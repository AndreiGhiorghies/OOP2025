#include "Tree.h"

template<typename T>
inline Tree<T>::Tree() : root(nullptr) {}

template<typename T>
Tree<T>::~Tree()
{
	delete_node();
}

template<typename T>
void Tree<T>::add_node(Node<T>* parent, const T& val)
{
	if (parent == nullptr) {
		delete_node();
		root = new Node(val);

		return;
	}

	Node<T>* new_node = new Node<T>*(val);

	if (parent->countChildren >= parent->capacity) {
		Node<T>** new_children = new Node<T>*[parent->capacity * 2];

		for (int i = 0; i < parent->countChildren; i++)
			new_children[i] = parent->children[i];

		delete[] parent->children;

		parent->capacity *= 2;
	}
	
	parent->countChildren[parent->countChildren++] = new_node;
}

template<typename T>
Node<T>* Tree<T>::get_node(Node<T>* parent)
{
	if (parent == nullptr)
		return root;

	if(parent->countChildren > 0)
		return parent->children[0];

	return nullptr;
}

template<typename T>
void Tree<T>::delete_node_rec(Node<T>* current, Node<T>* parent, bool find) {
	for (int i = 0; i < current->countChildren; i++) {
		if (current->children[i] == parent) {
			delete_node_rec(current->children[i], parent, false);
			delete current->children[i];

			for (int j = i; j < current->countChildren - 1; j++)
				current->children[j] = current->children[j + 1];

			current->countChildren--;
			current->children[current->countChildren] = nullptr;

			return;
		}
		else
			delete_node_rec(current->children[i], parent, true);

		if (!find)
			delete current->children[i];
	}

	if (!find) {
		delete[] current->children;
		current->children = nullptr;
	}
}

template<typename T>
void Tree<T>::delete_node(Node<T>* parent)
{
	if (parent != nullptr) {
		delete_node_rec(root, parent);

		return;
	}

	delete_node_rec(root, root, false);
	delete root;
	root = nullptr;
}

template<typename T>
void Tree<T>::find_rec(Node<T>* current, Node<T>*& found, bool(*compare)(const T&), bool ok) {
	if (ok)
		return;

	if (compare(current->value)) {
		found = current;
		ok = true;
		return;
	}

	for (int i = 0; i < current->countChildren; i++)
		find_rec(current->children[i], found, compare, ok);
}

template<typename T>
Node<T>* Tree<T>::find(bool(*compare)(const T&))
{
	Node<T>* found;
	find_rec(root, found, compare);

	return found;
}

template<typename T>
void Tree<T>::insert(Node<T>* parent, const int& index, const T& val)
{
	Node<T>* new_node = new Node<T>*(val);
	if (parent->countChildren >= parent->capacity) {
		Node<T>** new_children = new Node<T>*[parent->capacity * 2];

		for (int i = 0; i < parent->countChildren; i++)
			new_children[i] = parent->children[i];

		delete[] parent->children;

		parent->capacity *= 2;
	}

	if (index > parent->countChildren)
		index = parent->countChildren;

	for (int i = parent->countChildren - 1; i > index; i--)
		parent->children[i] = parent->children[i - 1];

	parent->children[index] = new_node;
	parent->countChildren++;
}

template<typename T>
void Tree<T>::sort(Node<T>* parent, bool(*compare)(const T&, const T&))
{
	if (compare == nullptr)
		compare = [](const T& a, const T& b) {return a < b; };

	for(int i = 0; i < parent->countChildren; i++)
		for(int j = i + 1; j < parent->countChildren; j++)
			if (!compare(parent[i], parent[j])) {
				Node<T>* temp = parent[i];
				parent[i] = parent[j];
				parent[j] = temp;
			}
}

template<typename T>
int Tree<T>::count(Node<T>* parent)
{
	if (parent == nullptr)
		parent = root;

	int n = parent->countChildren;

	for (int i = 0; i < parent->countChildren; i++)
		n += count(parent->children[i]);

	return n;
}
