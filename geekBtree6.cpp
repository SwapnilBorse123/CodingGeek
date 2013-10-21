#include<iostream>

using namespace std;

struct node{
	int no;
	node* left;
	node* right;
};

typedef node* Nodep;

void toleft(Nodep head,Nodep jisko);
void toright(Nodep head,Nodep jisko);
Nodep createNode(int n);
void callingMethod(Nodep);
void diff_bet_odd_even_level(Nodep,int*,int*,int);


int odd = 0,even = 0;

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
	callingMethod(start);
	cout<<"\n\n**** The difference between odd and even level nodes is: ****\n"<<(odd - even);
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

void callingMethod(Nodep h){
	int level = 1;
	diff_bet_odd_even_level(h,&even,&odd,level);
}


void diff_bet_odd_even_level(Nodep h,int* ev,int* od,int level){
	if(h!=NULL){
		if(level % 2 == 0)
			*ev = *ev + h->no;
		else *od = *od + h->no;
		
		diff_bet_odd_even_level(h->left,&even,&odd,level+1);
		diff_bet_odd_even_level(h->right,&even,&odd,level+1);
	}
}
