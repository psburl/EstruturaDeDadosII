/*	Nome: Wesley Burlani 	Universidade Federal da Fronteira Sul
* 	Matrícula: 1511100022					Estrutura de Dados II
* 	
*	Implementação de uma árvore binária com as funções de Criação,
* 	inserção e impressão da árvore;
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tree.h"

using namespace std;

int main(){
	
	Node* tree = CreateEmptyTree();

	char value[6];

	while(scanf("%s", value) && strcmp(value, "exit"))
		CreateNode(atoi(value), &tree);
	
	printTree(tree, 0);

}