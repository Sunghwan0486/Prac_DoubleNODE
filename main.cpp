#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	char data;
	struct _node* next;
	struct _node* prev;
}node;

node* p_head, * p_end, * temp;
node* p_node_1, * p_node_2, * p_node_3, * p_node_4;

void Init_LinkedList(void);
void InsertNODE(node*);
void DeleteNODE(node*);
void DisplayNODE(void);

int main()
{
	node* p_node;
	int i = 0;

	Init_LinkedList();
	DisplayNODE();
	p_node = (node*)malloc(sizeof(node));
	p_node->data = 'C';

	InsertNODE(p_node);
	DisplayNODE();

	DeleteNODE(p_node);
	DisplayNODE();

	return 0;
}

void Init_LinkedList(void)
{
	node* p_node;
	p_head = (node*)malloc(sizeof(node));
	p_end = (node*)malloc(sizeof(node));

	p_node_1 = (node*)malloc(sizeof(node));
	p_node_1->data = 'A';
	p_head->next = p_node_1;
	p_node_1->next = p_end;
	p_node_1->prev = p_head;
	p_end->next = p_end;
	p_node = p_node_1;

	p_node_2 = (node*)malloc(sizeof(node));
	p_node_2->data = 'B';
	p_node->next = p_node_2;
	p_node_2->next = p_end;
	p_node_2->prev = p_node;
	p_node = p_node_2;

	p_node_3 = (node*)malloc(sizeof(node));
	p_node_3->data = 'D';
	p_node->next = p_node_3;
	p_node_3->next = p_end;
	p_node_3->prev = p_node;
	p_node = p_node_3;

	p_node_4 = (node*)malloc(sizeof(node));
	p_node_4->data = 'E';
	p_node->next = p_node_4;
	p_node_4->next = p_end;
	p_node_4->prev = p_node;
	p_node = p_node_4;
}

void InsertNODE(node* p_node)
{
	node* c_node;
	for (c_node = p_head; c_node != p_end; c_node = c_node->next)
	{
		if (c_node->data < p_node->data && c_node->next->data > p_node->data)
			break;
	}

	p_node->next = c_node->next;
	c_node->next->prev = p_node;
	c_node->next = p_node;
	p_node->prev = c_node;
}

void DeleteNODE(node* p_node)
{
	node* c_node;
	node* del_node;

	for (c_node = p_head; c_node != p_end; c_node = c_node->next)
	{
		if (c_node->next->data == p_node->data)
		{
			del_node = c_node->next;
			break;
		}
	}
	c_node->next = c_node->next->next;
	c_node->next->next->prev = c_node;

}

void DisplayNODE()
{
	node* p_node;
	p_node = p_head->next;

	while (p_node != p_end)
	{
		printf("%2c", p_node->data);
		p_node = p_node->next;
	}

	printf("\n");
}