// example of a skip list

#include<iostream>
#include<stdlib.h>

using namespace std;

struct nodeNL{
	int no;
	nodeNL* next;
};
struct nodeEL{
	int no;
	nodeEL *next;
	nodeNL *child;
};


typedef nodeNL* NL;
typedef nodeEL* EL;

int main()
{
	int n,num;
	// for 10 nodes //
	cout<<"How many nodes you want?? ";
	cin>>n;
	
	//Making the linked list //
	
	NL begin = new nodeNL;
	begin->no = 1;
	nodeNL *start,*head;
	start = head = begin;
	for(int i = 1;i < n;i++){
		nodeNL* p = new nodeNL;
		p->no = i+1;
		begin->next = p;
		begin = begin->next;
	}
	begin->next = NULL;
	begin = head;
	while(begin->next != NULL){
		cout<<begin->no<<" ";
		begin = begin->next;
	}
	cout<<begin->no;
	
	EL p = new nodeEL;
	EL x,y;
	x = y = p;
	p->child = head;
	p->no = head->no;
	
	//setting two more express nodes //
	
	for(int i = 0;i<2;i++){
		// traversing normal lane by three nodes //
		for(int i = 0;i<4;i++){
			head = head->next;
		}
		EL p = new nodeEL;
		p->no = head->no;
		p->child = head;
		x->next = p;
		x = x->next;
	}
	x->next = NULL;

	cout<<"\nEnter the number you want to search ";
	cin>>num;
	A:
	if(num >= y->no && num <= (y->next)->no){
		NL temp = y->child;
		while(temp->no != num){
			temp = temp->next;	
		}
		cout<<"\nYour number found in O(root(n)) time: "<<temp->no;
	}
	else{
		y = y->next;
		goto A;		
	}
	return 0;
}
