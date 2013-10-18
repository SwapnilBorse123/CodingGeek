// Program to print the depth of the deepest odd level leaf node

#include<iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

Node* newNode(int a);
void callingMethod(Node*);
void FindOddLeafDeepest(Node* h,int level,int*);
//global variables
int maximum = 0,temp = 0;

int main()
{
	struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->left->right->left = newNode(9);
    root->right->right->right->right = newNode(10);
    root->right->right->right->right->left = newNode(11);
    root->right->right->right->right->left->right = newNode(12);
	callingMethod(root);
    cout<<"The Deepest odd level leaf is at level :"<<maximum<<" and the value is: "<<temp;
	return 0;
}

Node* newNode(int a){
	Node* p = new Node;
	p->data = a;
	p->left = p->right = NULL;
	return p;	
}

void callingMethod(Node* h){
	int level = 1;
	FindOddLeafDeepest(h,level,&maximum);
	//cout<<"The deepest level is: "<< max;
}

void FindOddLeafDeepest(Node* h,int level,int* max){
	if(h!=NULL){
		if(h->left == NULL && h->right == NULL){
			if(level % 2 != 0 && level > *max){
				*max = level;
				temp = h->data;
			}
		}
		FindOddLeafDeepest(h->left,level+1,&maximum);
		FindOddLeafDeepest(h->right,level+1,&maximum);
	}
}


/*input tree 

 	   1
     /   \
    2     3
  /      /  \  
 4      5    6
        \     \
         7     8
        /       \
       9         10
                 /
                11
                 \
                 12
                 
OUTPUT: level starts from 1 and thus its 7th level with value 12 

*/
