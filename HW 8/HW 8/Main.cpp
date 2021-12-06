// QUang Nguyen
// CMPR 131
// Homework 8
// Main.cpp

#include <iostream>
#include "Tools.h"
#include "BinaryTree.h"
#include "AnimalGuessingGame.h"


using namespace std;

int main(void)
{
	Node<string> *root = new Node<string>;
	Node<string> *lastNode = new Node<string>;
	string animal;
	
	if (getBool("Do you want to enter a file to start or do you want to make a new one? "))
		getData(root, "Enter the name of the file you wished to open: ");
	else
	{
		animal = getLine("Enter a name of an animal to start: ");
		root->data() = animal;
		cout << endl;
	}

	do
	{
		choice(root, lastNode);
		
		if (isAnimal(lastNode))
			cout << "\nYeah!!! That was easy. TRY HARDER!!" << endl << endl;
		else
			insert(lastNode);

		if (getBool("Do you want to play again? "))
		{
			cout << endl;
			continue;
		}
		else
			break;
	} while (true);

	storeData(root, "Enter the name of the file you wished to save: ");

	cin.ignore(999, '\n');
	return 0;
}
