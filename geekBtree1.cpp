// Deleting leaf nodes having sum less than K.

#include<iostream>
#include<stdlib.h>

using namespace std;

struct node{
	int no;
	node* left;
	node* right;
};

typedef node* Nodep;

Nodep prune(Nodep root, int k);
Nodep pruneUtil(Nodep root, int k, int *sum);
void toleft(Nodep head,Nodep jisko);
void toright(Nodep head,Nodep jisko);
Nodep createNode(int n);
void Preorder(Nodep);
void Postorder(Nodep);
void Inorder(Nodep);

int main()
{
	int n,arr[20],k;
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
		default: exit(0);

	}
	cout<<endl<<"Enter the value of K: ";
	cin>>k;
	
	start = prune(start,k);
	
	cout<<endl<<"Your tree has been pruned"<<endl;
	goto A;

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

Nodep pruneUtil(Nodep root, int k, int *sum)
{
    // Base Case
    if (root == NULL)  return NULL;
 
    // Initialize left and right sums as sum from root to
    // this node (including this node)
    int lsum = *sum + (root->no);
    int rsum = lsum;
 
    // Recursively prune left and right subtrees
    root->left = pruneUtil(root->left, k, &lsum);
    root->right = pruneUtil(root->right, k, &rsum);
 
    // Get the maximum of left and right sums
    *sum = max(lsum, rsum);
 
    // If maximum is smaller than k, then this node
    // must be deleted
    if (*sum < k)
    {
        free(root);
        root = NULL;
    }
 
    return root;
}
 
// A wrapper over pruneUtil()
Nodep prune(Nodep root, int k)
{
    int sum = 0;
    return pruneUtil(root, k, &sum);
}
