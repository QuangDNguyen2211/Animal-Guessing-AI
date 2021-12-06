// QUang Nguyen
// CMPR 131
// Homework 8
// AnimalGuessingGame.cpp

#include<fstream>
#include "Tools.h"
#include "AnimalGuessingGame.h"

void insertNode(ifstream &data, Node<string>* &lastNode)
{
	string item;

	getline(data, item);

	if (data.fail()) return;

	lastNode->data() = item;

	if (data.peek() != '*' && data.peek() != '/')
	{
		lastNode->left() = new Node<string>;
		insertNode(data, lastNode->left());

		lastNode->right() = new Node<string>;
		insertNode(data, lastNode = lastNode->right());
	}
	else
	{
		getline(data, item);
		return;
	}
}

void getData(Node<string>* &Tree, string prompt)
{
	ifstream data;
	openIfStream(data, prompt);

	Node<string>* lastNode = Tree;

	insertNode(data, lastNode);
}

void copy(ofstream &data, Node<string>* &source)
{
		data << source->data() << endl;

		if (source->left() == nullptr && source->right() == nullptr)	{ return; }

		copy(data, source->left());

		data << "*" << endl;

		copy(data, source->right());
}

void storeData(Node<string>* &Tree, string prompt)
{
	ofstream data;
	openOfStream(data, prompt);

	copy(data, Tree);

	data << "//////////" << endl;
}

void choice(Node<string>* Tree, Node<string>* &lastNode)
{
	lastNode = Tree;
	do
	{
		if (lastNode->left() == nullptr && lastNode->right() == nullptr)
			return;

		if (getBool(lastNode->data() + " "))
			lastNode = lastNode->left();
		else
			lastNode = lastNode->right();
	} while (true);
}

bool isAnimal(Node<string>* lastNode)
{
	bool answer;

	answer = getBool("Is is a(n)" + lastNode->data() + "? ");

	return answer;
}

void insert(Node<string>* &lastNode)
{
	string newAnimal;
	string newQuestion;

	newAnimal = getString("\nPlease tell me what animal you are thinking about: ");
	newQuestion = getLine("Please teach me a question that can help me distinguish between " + newAnimal + " and " + lastNode->data() + ": \n-->  ");

	if (getBool("What is the correct answer for a(n) " + newAnimal + "?(y/n) "))
	{
		lastNode->right() = new Node<string>(lastNode->data());

		lastNode->data() = newQuestion;

		lastNode->left() = new Node<string>(newAnimal);
	}
	else
	{
		lastNode->left() = new Node<string>(lastNode->data());

		lastNode->data() = newQuestion;

		lastNode->right() = new Node<string>(newAnimal);
	}

	cout << "\nThank you for teaching me!!" << endl << endl;
}