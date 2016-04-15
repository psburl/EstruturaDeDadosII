/*	Nome: Wesley Burlani 	Universidade Federal da Fronteira Sul
* 	Matrícula: 1511100022					Estrutura de Dados II
* 	
*	Implementação de uma árvore binária com as funções de Criação,
* 	inserção e impressão da árvore;
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
	
using namespace std;


//Classe Nó da árvore
class Node{
	
	public: 
		int value;
		Node* right;
		Node* left;


	//Cria um nó sem nenhum valor;
	Node(){
		this->right = NULL;
		this->left = NULL;
	}

	// Cria um nó e insere o valor dele;
	Node(int value){
		this->right = NULL;
		this->left = NULL;
		this->value = value;
	}

};


//Criar um árvore vazia;
Node* CreateEmptyTree(){
	return NULL;
}


Node* SearchDad(int value, Node* node){
	
	//Caso o nó a ser inserido seja maior que o atual;
	if(node->value < value){

		// Caso o nó atual não tenha filhos a sua direita;
		//(Ele é o pai)
		if(node->right == NULL)
			return node;

		//Caso ele tenha filhos à sua direita;
		else
			SearchDad(value, node->right);	
	}

	//Caso o nó a ser inserido seja menor que o atual;
	else{

		// Caso o nó atual não tenha filhos a sua esqerda;
		//(Ele é o pai)
		if(node->left == NULL)
			return node;

		//Caso ele tenha filhos à sua esquerda;
		else
			SearchDad(value, node->left);	

	}
}


//insere um novo nó com seu respectivo valor;
void CreateNode(int value, Node** node){

	//Cria o primeiro nó(nó raiz da árvore)
	if(*node == NULL){
		*node = new Node(value);
	}

	//Cria nós diferentes do primeiro nó da árvore
	else{

		//Procura qual será o pai do nó à ser inserido;
		Node * pai = SearchDad(value, (*node));
		
		// Veirifica se o nó é o filho da direita, esquerda ou se é igual ao pai;
		if(pai->value < value)
			pai->right = new Node(value);
		
		else if(pai->value > value)
			pai->left = new Node(value);

		else
			cout << "o valor já está inserido na árvore";
	}
		
}


// Imprime um árvore

/*	Cada tab representa um nível a mais na árvore
* 	Exemplo:
* 		1
* 			2
*
* 	Significa que 2 é filho de 1;
*/
void printTree(Node* Tree, int tabs){
	
	Node* node = Tree;
	int tabLeft, tabRight, auxTab;

	tabRight = tabLeft = tabs;
	auxTab = tabLeft + tabRight;

	// Verifica se a árvore não está vazia;
	if(Tree != NULL){

		// imprime a quantidade necessária de tabs;
		while(auxTab--)
			cout<< "     ";
		
		// Imprime o nó atual;
		printf("%5d\n",node->value);


		if(node->left != NULL)
			printTree(node->left,++tabLeft);

		if(node->right != NULL)
			printTree(node->right,++tabRight);
	}
}

