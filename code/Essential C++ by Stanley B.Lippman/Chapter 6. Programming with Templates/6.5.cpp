/* 6.5 A Function Template Output Operator */

#include <iostream>
#include <string>
#include <vector>

// forward declaration of BTnode class template
template <typename valType>
class BTnode;

template <typename Type>
class BinaryTree; // forward declaration

template <typename valType>
class BTnode
{
	friend class BinaryTree<valType>;

public:
	// ...
	BTnode();
	BTnode(const valType &);
	void insert_value(const valType &val);
	void remove_value(const valType &val, BTnode *&prev);
	static void preorder_value(BTnode *pt, std::ostream &os);
	static void inorder_value(BTnode *pt, std::ostream &os);
	static void postorder_value(BTnode *pt, std::ostream &os);
	static void display_val(BTnode *pt, std::ostream &os = std::cout);
	static void lchild_leaf(BTnode *leaf, BTnode *subtree);

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

template <typename valType>
void BTnode<valType>::
	insert_value(const valType &val)
{
	if (val == _val)
	{
		_cnt++;
		return;
	}

	if (val < _val)
	{
		if (!_lchild)
			_lchild = new BTnode(val);
		else
			_lchild->insert_value(val);
	}
	else
	{
		if (!_rchild)
			_rchild = new BTnode(val);
		else
			_rchild->insert_value(val);
	}
}

template <typename valType>
void BTnode<valType>::
	remove_value(const valType &val, BTnode *&prev)
{
	if (val < _val)
	{
		if (!_lchild)
			return; // not present
		else
			_lchild->remove_value(val, _lchild);
	}
	else if (val > _val)
	{
		if (!_rchild)
			return; // not present
		else
			_rchild->remove_value(val, _rchild);
	}
	else
	{
		// ok: found it;
		// reset the tree then delete this node

		if (_rchild)
		{
			prev = _rchild;
			if (_lchild)
			{
				if (!prev->_lchild)
					prev->_lchild = _lchild;
				else /*BTnode<valType>::*/
					lchild_leaf(_lchild, prev->_lchild);
			}
		}
		else
			prev = _lchild;
		delete this;
	}
}

template <typename valType>
void BTnode<valType>::
	preorder_value(BTnode *pt, std::ostream &os)
{
	if (pt)
	{
		display_val(pt, os);
		if (pt->_lchild)
			preorder_value(pt->_lchild, os);
		if (pt->_rchild)
			preorder_value(pt->_rchild, os);
	}
}

template <typename valType>
void BTnode<valType>::
	inorder_value(BTnode *pt, std::ostream &os)
{
	if (pt)
	{
		if (pt->_lchild)
			inorder_value(pt->_lchild, os);
		display_val(pt, os);
		if (pt->_rchild)
			inorder_value(pt->_rchild, os);
	}
}

template <typename valType>
void BTnode<valType>::
	postorder_value(BTnode *pt, std::ostream &os)
{
	if (pt)
	{
		if (pt->_lchild)
			postorder_value(pt->_lchild, os);
		if (pt->_rchild)
			postorder_value(pt->_rchild, os);
		display_val(pt, os);
	}
}

template <typename valType>
void BTnode<valType>::
	display_val(BTnode *pt, std::ostream &os)
{
	os << pt->_val << ' ';
}

template <typename valType>
void BTnode<valType>::
	lchild_leaf(BTnode *leaf, BTnode *subtree)
{
	while (subtree->_lchild)
		subtree = subtree->_lchild;
	subtree->_lchild = leaf;
}

template <typename elemType>
class BinaryTree
{
	friend std::ostream& operator<<(std::ostream&, const BinaryTree<elemType>&);
public:
	BinaryTree();
	BinaryTree(const BinaryTree &);
	~BinaryTree();
	BinaryTree &operator=(const BinaryTree &);
	void insert(const elemType &elem);
	void remove(const elemType &elem);
	void clear()
	{
		if (_root)
		{
			clear(_root);
			_root = 0;
		}
	}
	void remove_root();
	void preorder() const { BTnode<elemType>::preorder_value(_root, std::cout); }
	void inorder() const { BTnode<elemType>::inorder_value(_root, std::cout); }
	void postorder() const { BTnode<elemType>::postorder_value(_root, std::cout); }

	bool empty() { return _root == 0; }

private:
	// BTnode must be qualified with its template parameter list
	BTnode<elemType> *_root;

	// copy a subtree addressed by src to tar
	void copy(BTnode<elemType> *tar, BTnode<elemType> *src);
	void clear(BTnode<elemType> *);
	void print(std::ostream& os) const
	{ BTnode<elemType>::inorder_value(_root, os); }
};

//ostream& operator<<(ostream&, const int_BinaryTree&);

//ostream& operator<<(ostream&, const BinaryTree<int>&);

template <typename elemType>
std::ostream&
operator<<(std::ostream &os, const BinaryTree<elemType> &bt)
{
	os << "Tree: " << std::endl;
	bt.print(os);
	return os;
}

template <typename elemType>
inline BinaryTree<elemType>::
	BinaryTree() : _root(0)
{
}

template <typename elemType>
inline BinaryTree<elemType>::
	BinaryTree(const BinaryTree &rhs)
{
	copy(_root, rhs._root);
}

template <typename elemType>
inline BinaryTree<elemType>::
	~BinaryTree()
{
	clear();
}

template <typename elemType>
inline BinaryTree<elemType> &
BinaryTree<elemType>::
operator=(const BinaryTree &rhs)
{
	if (this != &rhs)
	{
		clear();
		copy(_root, rhs._root);
	}
	return *this;
}

template <typename elemType>
inline void
BinaryTree<elemType>::
	insert(const elemType &elem)
{
	if (!_root)
		_root = new BTnode<elemType>(elem);
	else
		_root->insert_value(elem);
}

template <typename elemType>
inline void
BinaryTree<elemType>::
	remove(const elemType &elem)
{
	if (_root)
	{
		if (_root->_val == elem)
			remove_root();
		else
			_root->remove_value(elem, _root);
	}
}

template <typename elemType>
void BinaryTree<elemType>::
	clear(BTnode<elemType> *pt)
{
	if (pt)
	{
		clear(pt->_lchild);
		clear(pt->_rchild);
		delete pt;
	}
}

template <typename elemType>
void BinaryTree<elemType>::
	remove_root()
{
	if (!_root)
		return;

	BTnode<elemType> *tmp = _root;
	if (_root->_rchild)
	{
		_root = _root->_rchild;

		// ok, now we must reattach the left child to the
		// bottom of the right child's left subtree
		if (tmp->_lchild)
		{
			// factor out just for readability
			BTnode<elemType> *lc = tmp->_lchild;
			BTnode<elemType> *newlc = _root->_lchild;
			if (!newlc)
				// no subtree, let's directly attach it
				_root->_lchild = lc;

			// lchild_leaf() will travel the left subtree
			// looking for a null left child to attach ...
			// lchild_leaf() is a static member function
			else
				BTnode<elemType>::lchild_leaf(lc, newlc);
		}
	}
	else
		_root = _root->_lchild;

	delete tmp; // ok: now we remove the node previously root
}

int main()
{
	std::cout << "Hello, 6.4!\n";

	BinaryTree<std::string> bt;

	bt.insert("Piglet");
	bt.insert("Eeyore");
	bt.insert("Roo");
	bt.insert("Tigger");
	bt.insert("Chris");
	bt.insert("Pooh");
	bt.insert("Kanga");

	std::cout << "Preorder traversal: \n";
	bt.preorder();

	bt.remove("Piglet");
	std::cout << "\n\nPreorder traversal after Piglet removal: \n";
	bt.preorder();

	bt.remove("Eeyore");

	std::cout << "\n\nPreorder traversal after Eeyore removal: \n";
	bt.preorder();

	std::cout << "\n\nInorder traversal after Eeyore removal: \n";
	bt.inorder();

	std::cout << "\n\nPostorder traversal after Eeyore removal: \n";
	bt.postorder();

	std::cout << "\n";

//	std::cout << bt << std::endl;

	return 0;
}
