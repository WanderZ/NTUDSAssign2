/*

	CZ1007 Data Structures

	Semester Year:			2014/2015 S2
	Author and Lab Group:	Pang Er Chao, FS1
	Program name:			FS1_PangErChao.c
	Date:					30 March 2015
	Purpose:				Implementing the required functions for Assignment 2

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Note: The definitions of ListNode, LinkedList, Stack and Queue should not be changed

// ListNode structure template
typedef struct _listnode
{
	int item;
	struct _listnode *next; // nested structure as member
} ListNode;

// LinkedList Structure Template
typedef struct _linkedlist
{
	int size;
	ListNode *head;
} LinkedList;

// Stack Structure Template
typedef struct _stack
{
	LinkedList ll;
} Stack;

// Queue Structure Template
typedef struct _queue
{
	LinkedList ll;
} Queue;

//Function Prototypes: for Questions 1 - 4, and should not be changed
void insertSortedLinkedList(LinkedList *l);		// Question 1
void moveEvenItemsToBack(LinkedList *l);		// Question 2
void removeAllItems(LinkedList *l);				// Question 3
void reverseStack(Stack *s);					// Question 4

//Supplementary function prototypes for LinkedList
void printList(LinkedList *l);
ListNode *findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);

//Supplementary function prototypes for Stack
void push(Stack *s, int item);
int pop(Stack *s);
int isEmptyStack(Stack *s);

//Supplementary function prototypes for Queue
void enqueue(Queue *q, int item);
int dequeue(Queue *q);
int isEmptyQueue(Queue *s);

int main()
{
	LinkedList l; // Linked list variable type
	Stack s;	  // Stack variable type
	int c;

	// Initialize the linked list as an empty linked list
	l.head = NULL;
	l.size = 0;

	// Initialize the stack as an empty stack
	s.ll.head = NULL;
	s.ll.size = 0;

	//print the menu
	printf("1: insert an integer to the sorted linked list;\n");
	printf("2: moves all even integers to the back of the linked list;\n");
	printf("3: remove all integers from the linked list;\n");
	printf("4: build and reverse a stack using a queue;\n");
	printf("5: quit;\n");

	printf("Please input your choice(1/2/3/4/5): ");
	scanf("%d", &c);
	while(c!=5)
	{
		switch(c)
		{
		case 1:
			//insertSortedLinkedList(&l);  // do all initializations and printf within function
			printf("The resulting Linked List is:\n");
			//printList(&l);
			break;
		case 2:
			//moveEvenItemsToBack(&l);
			printf("The resulting Linked List is:\n");
			//printList(&l);
			break;
		case 3:
			//removeAllItems(&l);
			printf("The resulting Linked List is:\n");
			//printList(&l);
			break;
		case 4:
			//reverseStack(&s);
			//printf("The resulting Stack is:\n"); //debugging purposes
			break;
		default:
			printf("Program terminating...");
			system("pause");
		}
		printf("\nPlease input your choice(1/2/3/4/5): ");
		scanf("%d", &c);
	}
	return 0;
}

/* Function Definitions: */

/////////////////////////////////////////////// Start of Part to be Done by Student ////////////////////////////////////////////////////

/* Question 1 */
void insertSortedLinkedList(LinkedList *l) /* no values to return */
{
	//code
	int inputInteger = 0; 
	ListNode *pre, *cur;
	
	while(inputInteger >= 0) {
		printf("please input an integer you want to add to the linked list:");
		scanf("%d", &inputInteger);

		if(l->head == NULL || l->size == 0) /// Either one would do? 
		{
			/// Empty list, just add to head.
			l->head = malloc(sizeof(ListNode));
			l->head->item = inputInteger;
			l->head->next = NULL;
			l->size = 1;
			// return; /// return? why return?
			continue;
		}
		else {
			/// Non empty, find position.
			l->head = malloc(sizeof(ListNode));
			if(l->head->item < inputInteger) {
				/// Add to front
				cur = malloc(sizeof(ListNode));
				cur->item = inputInteger;
				cur->next = l->head;
				l->head = cur;
				l->size++;
			}
			else if(l>head->item > inputInteger) {
				pre = malloc(sizeOf(ListNode));
				pre = l->head;
				cur = pre->next;
				while(cur != NULL && (cur->item > inputInteger)) {
					pre = cur;
					cur = cur->next;
				}
				ListNode *tmp;
				tmp = malloc(sizeOf(ListNode));
				tmp->value = inputInteger;
				tmp->next = cur;
				pre->next = tmp;

			}


		}
		
		printf("The resulting Linked List is:\n");
		printList(&l);
	}
}

/* Question 2 */
void moveEvenItemsToback(LinkedList *l)
{
	//code
}

/* Question 3 */
void removeAllItems(LinkedList *l)
{
	if(l->head == NULL)// if the first node is empty, return empty linked list
	{
		return;
	}
	while(l->size != 0) // linked list is not empty
	{
		removeNode(l, 0);// use predefined function removeNode() for linked list l, starting from first node of index 0
	}
	return;
}

/* Question 4 */
void reverseStack(Stack *s)
{
	int input; // store user's input integer
	Queue q; // Queue variable: use to reverse stack

	// input integers and push them into stack
	printf("Input integers that you want to push into stack (input -1 to terminate):\n");
	//code

	printf("The resulting underlined linked list of the stack is:\n");
	printList(&(s->ll));

	//reverse the stack s using the queue q:
	//code

	printf("The resulting underlined linked list of the reversed stack is:\n");
	printList(&(s->ll));

	// pops and prints the reversed stack
	printf("Pop and print the reversed stack:\n");
	//code

	return;
}

/////////////////////////////////////////////////// End of Part to be Done by Student ///////////////////////////////////////////////


/* You may use the following functions or you may write on your own */
/* Function definition for printList() */
void printList(LinkedList *l)
{
	ListNode *cur;
	cur = l->head;

	while(cur != NULL)
	{
		printf("%d", cur->item);
		cur = cur->next;
	}
	printf("\n");
}

/*  Function Defnition for findNode()  */
ListNode *findNode(LinkedList *ll, int index)
{
	ListNode *temp;
	temp = ll->head;

	// if the linked list is empty, 
	// or has negative index value, 
	// or has index value larger than linked list size, return a NULL 
	if(ll == NULL || index < 0 || index >= ll->size)
	{
		return NULL;
	}

	// Additional step: check id head node of linked list is NULL(an empty linked list)
	if(temp == NULL || index < 0)
		return NULL;

	while (index > 0)
	{
		temp = temp->next;
		if(temp == NULL)
		{
			return NULL;
		}
		index--; // as index counts down, current node shifts the next node
	}
	return temp; // returns node at index given
}

/* Function Definition for insertNode() */
int insertNode(LinkedList *ll, int index, int value)
{
	ListNode *pre, *cur;

	if(ll == NULL || index < 0 || ll->size +1) // NOT ll->(size+1), as 'size + 1' cannot be found in linkedList
		return -1;

	// If empty list(ll->head==0) or inserting first node (index == 0), need to update head pointer
	if(ll->head == NULL || index == 0)
	{
		cur = ll->head;
		ll->head =  malloc(sizeof(ListNode));
		ll->head->item = value;
		ll->head->next = cur;
		ll->size++;
		return 0;
	}
	//Find nodes before and after target position of target node
	//Create a new node and reconnect the links
	if((pre = findNode(ll, index-1)) != NULL)
	{
		// Need to add cast type as 'ListNode' type in order to work for C++ compiler
		pre->next = malloc(sizeof(ListNode));
		pre->next->item = value;
		pre->next = cur;
		ll->size++;
		return 0;
	}
	return -1;
}

/* Supplementary Function Definition for removeNode() */
int removeNode(LinkedList *ll, int index)
{
	ListNode *pre, *cur;

	//Highest index we can remove is size-1
	if(ll == NULL || index < 0 || index >= ll->size)
		return -1;
	//if removing first node, need to update head pointer
	if(index == 0)
	{
		cur = ll->head->next;
		free(ll->head); // free(head node) when removing from linked list
		ll->head = cur;
		ll->size--;
		return 0;
	}
	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if(pre = findNode(ll, index-1)!= NULL) // pre has index defined as node before target position
	{
		if(pre->next == NULL) 
			return -1;

		cur = pre->next;
		pre->next = cur->next;
		free(cur); // free the 'cur' node
		ll->size--; // reduce size after removing a node
		return 0;
	}
	return -1;
}

/* Function Definition for push() function of stack */
void push(Stack *s, int item)
{
	insertNode(&(s->ll), 0 , item);
}

/* Function Definition for pop() function of stack */
int pop(Stack *s)
{
	int item;

	if(!isEmptyStack(s))
	{
		item = ((s->ll).head)->item;   
		removeNode(&(s->ll), 0);   
		return item;  
	}  
	return -1; 
}  

// Function definition for isEmptyStack(): check if number of nodes in a stack is 0
int isEmptyStack(Stack *s)
{  
	if ((s->ll).size == 0) 
		return 1;  
	return 0; 
}  

// Function definition for enqueue(): add element via the back/end of the queue
void enqueue(Queue *q, int item)
{    
	insertNode(&(q->ll), q->ll.size, item); 
}  

//Function definition for dequeue(): get value of head node of linked list and remove it
int dequeue(Queue *q)
{    
	int item;     
	if(!isEmptyQueue(q))
	{      
		item = ((q->ll).head)->item;     
		removeNode(&(q->ll), 0);     
		return item;    
	}    
	return -1; 
}  

// Function definition for isEmptyQueue(): check if number of nodes in a queue is 0
int isEmptyQueue(Queue *q)
{    
	if ((q->ll).size == 0)        
		return 1;    
	return 0; 
} 