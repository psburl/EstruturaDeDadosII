/*	Nome: Wesley Burlani 	Universidade Federal da Fronteira Sul
* 	Matrícula: 1511100022					Estrutura de Dados II
* 	
*	Implementação de uma árvore binária com as funções de Criação,
* 	inserção e impressão da árvore;
*/


#include "Tree.cpp"

Node* CreateEmptyTree();
void CreateNode(int value, Node* Tree);
Node* SearchDad(int value, Node* node);
void printTree(Node* Tree, int tabs);