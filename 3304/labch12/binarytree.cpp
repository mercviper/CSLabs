#ifndef BinaryTree_h
	#include "BinaryTree.h"
#endif

void BinaryTree::insertNode(treeNode * newNode, treeNode * currNode){
	if(isEmpty()){
		root = newNode;
	}
	//else traverse list until NULL is found, add, then balance.
	else{
		if(newNode->data.compare(currNode->data)>0){
			//currNode->balance--;
			if(currNode->right==NULL){
				currNode->right=newNode;/*
				newNode->parent=currNode;
				currNode=root;
				if(getHeight(currNode->left)-getHeight(currNode->right)>1)
					rotateRight(currNode->left);
				if(getHeight(currNode->left)-getHeight(currNode->right)<-1)
					rotateLeft(currNode->right);*/
			}
			else{
				insertNode(newNode,currNode->right);
			}
		}
		else{
			currNode->balance++;
			if(currNode->left==NULL){
				currNode->left=newNode;/*
				newNode->parent=currNode;
				currNode=root;
				if(getHeight(currNode->left)-getHeight(currNode->right)>1)
					rotateRight(currNode->left);
				if(getHeight(currNode->left)-getHeight(currNode->right)<-1)
					rotateLeft(currNode->right);*/
			}
			else{
				insertNode(newNode,currNode->left);
			}
		}
	}

}

int BinaryTree::getHeight(treeNode * node)
{
   /* base case tree is empty */
   if(node == NULL)
       return 0;
 
   /* If tree is not empty then height = 1 + max of left
      height and right heights */
   return 1 + max(getHeight(node->left), getHeight(node->right));
} 

void BinaryTree::rotateLeft(treeNode * pivot){
	treeNode * parent=pivot->parent;
	parent->right=pivot->left;
	pivot->left=parent;
	pivot->parent=parent->parent;
	parent->parent=pivot;
	if(pivot->parent==NULL)
		root=pivot;
	else if(pivot->parent->left==parent)
		pivot->parent->left=pivot;
	else
		pivot->parent->right=pivot;
} 

void BinaryTree::rotateRight(treeNode * pivot){
	treeNode * parent=pivot->parent;
	parent->left=pivot->right;
	pivot->right=parent;
	pivot->parent=parent->parent;
	parent->parent=pivot;
	if(pivot->parent==NULL)
		root=pivot;
	else if(pivot->parent->left==parent)
		pivot->parent->left=pivot;
	else
		pivot->parent->right=pivot;
} 

void BinaryTree::insertNode(string newString){
	treeNode * newNode = new treeNode;
	newNode->data=newString;
	newNode->left=NULL;
	newNode->parent=NULL;
	newNode->right=NULL;
	newNode->balance=0;
	insertNode(newNode, root);
}

int BinaryTree::findNode(string str){
	treeNode * index = root;
	bool found=false;
	while(!found && index!=NULL){
		if(str.compare(index->data)==0){
			found=true;
		}
		else if(str.compare(index->data)>0){
			index=index->right;
		}
		else{
			index=index->left;
		}
	}
	if(found)
		return 1;
	else
		return -1;
}

bool BinaryTree::isEmpty(){
	if(root==NULL)
		return true;
	else 
		return false;
}
