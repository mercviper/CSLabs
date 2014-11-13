#include <iostream>
#include <string>
using namespace std;

class BinaryTree
{

private:
	struct treeNode{
		string data;
		treeNode * left;
		treeNode * right;
		treeNode * parent;
		int balance;
	};
	treeNode * root;

public:
	BinaryTree(){root=NULL;};
	~BinaryTree();
	void insertNode(treeNode *, treeNode *);
	void insertNode(string);
	void deleteNode(string);
	void rotateRight(treeNode *);
	void rotateLeft(treeNode *);
	int findNode(string);
	int getHeight(treeNode *);
	bool isEmpty();
};
