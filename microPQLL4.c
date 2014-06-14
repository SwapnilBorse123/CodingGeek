// 13/06/14 19:34 // //For numbers less than 32 as of now //

// Program to remove the duplicate elements from the linked list //

#include<stdio.h>
#include<stdlib.h>

struct node{
	int no;
	struct node* next;
};

typedef struct node* Nodep;

Nodep makeLinkedList(int);
void printList(Nodep);

int main(){
	int i,num,t=0;
	printf("How many nodes you want in the linked list??\n");
	scanf("%d",&num);
	Nodep head = makeLinkedList(num);
	Nodep temp = head;
	Nodep p = head->next;
	t = t|1<<(head->no-1);
	while(p!=NULL){
		if(t&1<<(p->no-1)){
			p = p->next;
			if(p == NULL){
				temp->next = NULL;
				break;	
			}
		}
		else if(temp->next == p){
			temp = temp->next;
			t = t | 1<<(p->no-1);
			p = p->next;
		}
		else{
			temp->next = p;
			t = t | 1<<(p->no-1);
			if(p->next == NULL){
				temp->next = p;
			}
			temp = p;
			p = p->next;
		}
	}
	printf("\nThe linked list after removing duplicate nodes is:\n");
	printList(head);
	return 0;
}

Nodep makeLinkedList(int n){
	int exec = 1,i;
	Nodep start,p;
	printf("Enter the numbers:\n");
	for(i = 0;i<n;++i){
		if(exec){
			p = (Nodep)malloc(sizeof(struct node));
			start = p;
			p->next = NULL;
			scanf("%d",&p->no);
			exec = 0;
		}
		else{
			
			Nodep q = (Nodep)malloc(sizeof(struct node));
			q->next = NULL;
			scanf("%d",&q->no);
			p->next = q;
			p = p->next;
		}
	}
	return start;
}

void printList(Nodep head){
	while(head->next!=NULL){
		printf("%d ",head->no);
		head = head->next;
	}
	printf("%d",head->no);
}
