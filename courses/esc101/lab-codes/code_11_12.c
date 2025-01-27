/* C Program to remove duplicates from a sorted linked list */
#include<stdio.h> 
#include<stdlib.h> 
 typedef struct Node node;
/* Link list node */
struct Node 
{ 
	int data; 
	struct Node* next; 
}; 
node*head;
/* The function removes duplicates from a sorted list */
void removeDuplicates(struct Node* head) 
{ 
	/* Pointer to traverse the linked list */
	struct Node* current = head; 

	/* Pointer to store the next pointer of a node to be deleted*/
	struct Node* next_next; 
	
	/* do nothing if the list is empty */
	if (current == NULL) 
	return; 

	/* Traverse the list till last node */
	while (current->next != NULL) 
	{ 
	/* Compare current node with next node */
	if (current->data == current->next->data) 
	{ 
		/* The sequence of steps is important*/			
		next_next = current->next->next; 
		free(current->next); 
		current->next = next_next; 
	} 
	else /* This is tricky: only advance if no deletion */
	{ 
		current = current->next; 
	} 
	} 
} 

/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginging of the linked list */
void push(struct Node** head_ref, int new_data) 
{ 
	/* allocate node */
	struct Node* new_node = 
			(struct Node*) malloc(sizeof(struct Node)); 
			
	/* put in the data */
	new_node->data = new_data; 
				
	/* link the old list off the new node */
	new_node->next = (*head_ref);	 
		
	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

/* Function to print nodes in a given linked list */
void printList(struct Node *node) 
{ 
	while (node!=NULL) 
	{ 
	printf("%d ", node->data); 
	node = node->next; 
	} 
} 

/* Drier program to test above functions*/
int main() 
{ 
	/* Start with the empty list */
	head = NULL; 
	
	int t;
	scanf("%d",&t);
	for(int i=0; i<t; i++){
	    int n; scanf("%d",&n);
	    push(&head, n);
	}

// 	printf("\n Linked list before duplicate removal "); 
	printList(head); printf("\n");

	/* Remove duplicates from linked list */
	removeDuplicates(head); 

// 	printf("\n Linked list after duplicate removal ");		 
	printList(head);			 
	
	return 0; 
} 
