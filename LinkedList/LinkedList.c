/*
		Simple Linked List example
*/



#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	struct node *next_node;
} node;

node *head, *tail;

void init_list(void){
	head = (node*)malloc(sizeof(node));
        tail = (node*)malloc(sizeof(node));
        head->next_node = tail;
        tail->next_node = tail;
}

node* insert_after(int value, node* prev_node){
	node* want_node;
        want_node = (node*)malloc(sizeof(node));
        want_node -> value = value;
        want_node -> next_node = prev_node -> next_node;
        prev_node -> next_node = want_node;
	return want_node;
}

node* ordered_insert(int value){
	node *s;
	node *p;
	node *r;
	p = head;
	s = p->next_node;
	while(s -> value <= value && s != tail){
		p = p->next_node;
		s = p->next_node;	
	}
	r = (node*)malloc(sizeof(node));
	r -> value = value;
	p -> next_node = r;
	r -> next_node = s;
	return r;
}

void print_list(node* want_node){
	printf("\n");
	while(want_node != tail){
		printf("%-8d", want_node->value);
		want_node = want_node -> next_node;
	}
}

int main(int argv, char* argc[]){
	node* start_node;
        init_list();
	ordered_insert(10);
	ordered_insert(5);
	ordered_insert(8);
	ordered_insert(9);

	printf("\nInitial Linked List\n");
	print_list(head->next_node);
}

