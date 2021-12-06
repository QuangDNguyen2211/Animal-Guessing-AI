// QUang Nguyen
// CMPR 131
// Homework 8
// AnimalGuessingGame.h

#include <iostream>
#include "BinaryTree.h"

using namespace std; 

void getData(Node<string>* &Tree, string prompt);
void choice(Node<string>* Tree, Node<string>* &lastNode);
bool isAnimal(Node<string>* lastNode);
void insert(Node<string>* &lastNode);
void storeData(Node<string>* &Tree, string prompt);
