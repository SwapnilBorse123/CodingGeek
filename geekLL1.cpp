// swapping k^th element from beginning with kth element from end, don't swap data but adjust pointers


#include<iostream>
#include<stdlib.h>

using namespace std;

struct node{
	int no;
	node* next;
};

typedef node* Node;
//function prototype
void swap_ptr(node* head,int n,int k);
void skip_alter(node* head);

int main()
{
	int n,k,choice = 0;
	char ch;
	A:
	cout<<"How many nodes you want?? ";
	cin>>n;
	
	//Making the linked list //
	
	node* begin = new node;
	begin->no = 1;
	node *start,*head;
	start = head = begin;
	for(int i = 1;i < n;i++){
		node* p = new node;
		p->no = i+1;
		begin->next = p;
		begin = begin->next;
	}
	begin->next = NULL;
	
	// printing the list //
	
	cout<<"Before swapping the pointers: \n";
	while(start->next != NULL){
		cout<<start->no<<" ";	
		start = start->next;
	}
	cout<<start->no;
	cout<<endl<<endl;
	// printing address to run the check
	
	// calling the function //
	
	// using choice
	cout<<"U wanna skip or swap? 1)Swap 2)Skip :  ";
	cin>>choice;
	switch(choice){
		case 1:{
			cout<<"Enter which place from both the sides you want to swap: ";
			cin>>k;
			cout<<endl;
			swap_ptr(head,n,k);
			break;
		}
		case 2:skip_alter(head);break;
		default: cout<<"Enter the correct choice";
	}

	cout<<"\n\nDo you want to continue?(y or n)\n";
	cin>>ch;
	if(ch == 'y')
		goto A;
	return 0;
}


void swap_ptr(node* head,int n,int k){
	Node shuruwat,tail;
	tail = shuruwat = head;
	if(head == NULL)
		cout<<"Linked List not present(Empty List):\n";
	// Adjusting Head and Tail pointers //
	if(k != 1){
		for(int i = 0;i<k-2;i++){
			head = head->next;
		}
	}
	for(int i = 0;i<n-k-1;i++)
		tail = tail->next;
	// Considering the four cases //
	
	// The first node swap condition
	if(k == 1){
		shuruwat = tail->next;
		shuruwat->next = head->next;
		tail->next = head;
		head->next = NULL;
	}
	// The same node condition
	else if(head->next == tail->next){
		cout<<"Same node: cannot be swapped\n";
		exit(EXIT_SUCCESS);
	}
	// The tail head adjacent condition
	else if(tail->next == head){
		Node temp = head->next;
		Node temp1 = temp->next;
		tail->next = temp;
		temp->next = head;
		head->next = temp1;
	}
	// The head tail adjacent condition
	else if(head->next = tail){
		Node temp = (tail->next)->next;
		head->next = tail->next;
		(tail->next)->next = tail;
		tail->next = temp;
	}
	// The remaining anywhere else condition //
	else{
		Node temp3 = head->next;
		Node temp1 = temp3->next;
		Node temp2 = (tail->next)->next;
		head->next = tail->next;
		head = head->next;
		head->next = temp1;
		tail->next = temp3;
		temp3->next = temp2;
		
	}
	while(shuruwat->next != NULL){
		cout<<shuruwat->no<<" ";
		shuruwat = shuruwat->next;	
	}
	cout<<shuruwat->no;
}

void skip_alter(node* head){
	Node shuruwat = head;
	while((head->next)->next != NULL){
		head->next = (head->next)->next;
		head = head->next;
	}
	head->next = NULL;
	cout<<endl;
	while(shuruwat->next != NULL){
		cout<<shuruwat->no<<" ";
		shuruwat = shuruwat->next;	
	}
	cout<<shuruwat->no;
}
