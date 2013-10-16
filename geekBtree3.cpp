// Finding if all the leaf nodes are at the same level //

#include<iostream>

using namespace std;

struct node{
	int no;
	node* left;
	node* right;
};

typedef node* Nodep;

void TraceTree(Nodep,int);
void toleft(Nodep head,Nodep jisko);
void toright(Nodep head,Nodep jisko);
Nodep createNode(int n);
void Preorder(Nodep);
void Postorder(Nodep);
void Inorder(Nodep);
void PrintResult(Nodep);
void FindLevel(Nodep,int);

//global variables max and flag
int maximum = 0;
bool flag = false;

int main()
{
	int n,arr[20];
	cout<<"How many nodes you want in the binary tree?\n";
	cin>>n;
	cout<<"Enter the numbers:\n";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	Nodep header = createNode(arr[0]);
	Nodep start = header;
	header->left = header->right = NULL;
	for(int i=1;i<n;i++){
		Nodep new_node = createNode(arr[i]);
		new_node->left = new_node->right = NULL;
		if(new_node->no < start->no){
			toleft(start,new_node);
		}else toright(start,new_node);
	}
	cout<<"\n\n**** YOUR BINARY SEARCH TREE IS READY ****\n";
	A:
	cout<<"\nWhich traversal do you want??\n1)Pre\n2)In\n3)Post\n\n";
	cin>>n;
	switch(n){
		case 1:Preorder(header);break;
		case 2:Inorder(header);break;
		case 3:Postorder(header);break;
		default: cout<<"Please enter correct choice!!!";
	}
	char ch;
	cout<<"\nDo you want to continue?? (y/n)";
	cin>>ch;
	if(ch == 'y'||ch == 'Y')
		goto A;
	PrintResult(start);
	return 0;
}

Nodep createNode(int n){
	Nodep p = new node;
	p->no = n;
	return p;
}

void toleft(Nodep head,Nodep jisko){
	if(head->left == NULL){
		head->left = jisko;
	}
	else{
		head = head->left;
		if(jisko->no < head->no)
		toleft(head,jisko);
		else toright(head,jisko);
	}
}

void toright(Nodep head,Nodep jisko){
	if(head->right == NULL){
		head->right = jisko;
	}
	else{
		head = head->right;
		if(jisko->no > head->no)
		toright(head,jisko);
		else toleft(head,jisko);
	}
}

void Preorder(Nodep p){
	if(p!=NULL){
		cout<<p->no<<" ";
		Preorder(p->left);
		Preorder(p->right);
	}
}

void Inorder(Nodep p){
	if(p!=NULL){
		Inorder(p->left);
		cout<<p->no<<" ";
		Inorder(p->right);
	}
}

void Postorder(Nodep p){
	if(p!=NULL){
		Postorder(p->left);
		Postorder(p->right);
		cout<<p->no<<" ";
	}
}

void PrintResult(Nodep head){
	int level = 0;
	FindLevel(head,level);
	TraceTree(head,level);
	if(flag)
	cout<<"\nLeaves are not at the same level.";
	else cout<<"\nLeaves are at the same level.";
}

void FindLevel(Nodep head,int level){
	if(head!=NULL){
		if(head->left == NULL && head->right == NULL){
			maximum = level;	
		}
		FindLevel(head->left,level+1);
		FindLevel(head->right,level+1);
	}
}

void TraceTree(Nodep head,int level){
	if(head!=NULL){
		if(head->left == NULL && head->right == NULL){
			if(level>maximum || level<maximum)
				flag = true;
		}
		TraceTree(head->left,level+1);
		TraceTree(head->right,level+1);
	}
}
