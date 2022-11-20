/* 6.3 Handling Template Type Parameters */

#include <iostream>
#include <string>
#include <vector>

// forward declaration of BTnode class template
template <typename valType>
class BTnode;

template <typename Type>
class BinaryTree; // forward declaration

// forward declaration of BTnode class template
template <typename valType>
class BTnode {
	friend class BinaryTree<valType>;
public:
	// ...
	BTnode();
	BTnode(const valType&);
private:
	valType _val;
	int _cnt;
	BTnode *_lchild;
	BTnode *_rchild;
};

template <typename valType>
inline BTnode<valType>::
BTnode()
{
	_cnt = 1;
	_lchild = _rchild = 0;
}

// preferred initialization method for
// type parameter passed to a constructor
template <typename valType>
inline BTnode<valType>::
BTnode(const valType &val)
	// just in case valType is a class type
	: _val(val)
{
	// not recommended; could be a class type
	// not wrong, but inefficient
	/* _val = val; */

	// ok: these types are invariant ...
	_cnt = 1;
	_lchild = _rchild = 0;
}

template <typename elemType>
class BinaryTree {
public:
	BinaryTree();
	BinaryTree(const BinaryTree&);
	~BinaryTree();
	BinaryTree& operator=(const BinaryTree&);

	bool empty() { return _root == 0; }
	void clear();
private:
	// BTnode must be qualified with its template parameter list
	BTnode<elemType> *_root;

	// copy a subtree addressed by src to tar
	void copy(BTnode<elemType>*tar, BTnode<elemType>*src);
};

template <typename elemType>
inline BinaryTree<elemType>::
BinaryTree() : _root(0)
{}

template <typename elemType>
inline BinaryTree<elemType>::
BinaryTree(const BinaryTree &rhs)
	{ copy(_root, rhs._root); }

template <typename elemType>
inline BinaryTree<elemType>::
~BinaryTree()
	{ clear(); }

template <typename elemType>
inline BinaryTree<elemType>&
BinaryTree<elemType>::
operator=(const BinaryTree &rhs)
{
	if (this != &rhs)
		{ clear(); copy(_root, rhs._root); }
	return *this;
}

template <typename elemType>
inline void
BinaryTree<elemType>::
clear()
{}

int main()
{
	std::cout << "Hello, 6.1.cpp!\n";
	BTnode< int > bti; // to bind valType to type int
	BTnode< std::string > bts; // to bind valType to the class string type
	BTnode< std::vector < std::string > > btvs;
	BinaryTree< std::string > st; // _root becomes a pointer to a BTnode object holding a value of type string
	BinaryTree< int > it; // _root becomes a pointer to a BTnode object holding a value of type int
}
