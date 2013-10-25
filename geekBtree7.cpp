// program to print the ancestors of a node (recursive approach)//

#include<iostream>

using namespace std;

struct Node{
	int data;
	Node *left,*right;
};

Node* newNode(int n);
int stack[10],top = -1;
bool PrintAncestor(Node*,int);
//void emptyStack(int*);


int main()
{
	struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->right->right = newNode(9);
    root->right->right->left = newNode(10);
    int keys[15],n;
	cout<<"How many elements do you want to enter? ";
    cin>>n;
    cout<<"Enter the elements whose ancestors have to be found out:\n";
    for(int i = 0;i < n;i++){
		cin>>keys[i];
    }
    for(int i = 0;i < n;i++){
		PrintAncestor(root,keys[i]);
    }
    return 0;
}


Node* newNode(int n){
	Node *p = new Node;
	p->data = n;
	p->left = p->right = NULL;
	return p;
}

bool PrintAncestor(Node* h,int key){
	if(h ==NULL){
		return false;
	}
	if(h->data == key){
		return true;
	}
	
	if(PrintAncestor(h->left,key) || (PrintAncestor(h->right,key))){
		cout<<h->data<<" ";
		return true;	
	}
	cout<<"\n";
	return false;
}

/*void emptyStack(int *stk){
	if(top == -1)
		cout<<"No ancestors\n";
	while(top != -1){
		cout<<stk[top--]<<" ";
	}
	cout<<endl;
}*/
