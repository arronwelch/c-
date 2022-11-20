/* 6.1 Parameterized Types : 6.1.cpp */

#include <iostream>
#include <string>

/* Here is a nontemplate declaration of the BTnode class */
class int_BTnode;

class string_BTnode {
public:
	// ...
private:
	std::string _val;
	int _cnt;
	int_BTnode *_lchild;
	int_BTnode *_rchild;
};

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
private:
	valType _val;
	int _cnt;
	BTnode *_lchild;
	BTnode *_rchild;
};

template <typename elemType>
class BinaryTree {
public:
	// ...
private:
	// BTnode must be qualified with its template parameter list
	BTnode<elemType> *_root;
};

int main()
{
	std::cout << "Hello, 6.1.cpp!\n";
	BTnode< int > bti; // to bind valType to type int
	BTnode< std::string > bts; // to bind valType to the class string type
	BinaryTree< std::string > st; // _root becomes a pointer to a BTnode object holding a value of type string
	BinaryTree< int > it; // _root becomes a pointer to a BTnode object holding a value of type int
}
