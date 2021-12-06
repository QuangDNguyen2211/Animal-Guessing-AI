#ifndef BINARYTREE_H
#define BINARYTREE_H

// QUang Nguyen
// CMPR 131
// Homework 8
// BinaryTree.h

#include <iostream>

using namespace std;

template<class ItemType>
class Node
{
public:
	typedef ItemType valueType;
	typedef Node* branch;

	Node(void) : leftBranch(nullptr), rightBranch(nullptr) {}
	Node(ItemType _dataValue) : dataValue(_dataValue), leftBranch(nullptr), rightBranch(nullptr) {}
	Node(ItemType _dataValue, Node* _left, Node* _right) : dataValue(_dataValue), leftBranch(_left), rightBranch(_right) {}

	valueType &data(void) { return dataValue; }
	valueType data(void) const { return dataValue; }

	branch &left(void) { return leftBranch; }
	branch left(void) const { return leftBranch; }

	branch &right(void) { return rightBranch; }
	branch right(void) const { return rightBranch; }

private:
	ItemType dataValue;
	branch leftBranch;
	branch rightBranch;
};

#endif
