#pragma once
template<typename T>
class List;

template<typename T>
class Node {
public:
	T value;

	Node<T>** children;

	int capacity, countChildren;

	Node(T val) : value(val) {
		capacity = 1;
		countChildren = 0;

		children = new Node<T>*[capacity];
	}
};

template<typename T>
class List {
public:
	Node<T>* val;
	List<T>* next;

	List() : val(nullptr), next(nullptr) {}
	List(Node<T>* n) : val(n), next(nullptr) {}
};

template<typename T>
class Tree {
private:
	Node<T>* root;

	void delete_node_rec(Node<T>* current, Node<T>* parent, bool find = true);
	void find_rec(Node<T>* current, Node<T>*& found, bool(*compare)(const T&), bool ok = false);

public:
	Tree();
	~Tree();

	void add_node(Node<T>* parent, const T& val);
	Node<T>* get_node(Node<T>* parent = nullptr);
	void delete_node(Node<T>* parent = nullptr);
	Node<T>* find(bool (*compare)(const T&));
	void insert(Node<T>* parent, const int& index, const T& val);
	void sort(Node<T>* parent, bool (*compare)(const T&, const T&) = nullptr);
	int count(Node<T>* parent = nullptr);
};
