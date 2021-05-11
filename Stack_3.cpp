//3-� �������
//����� ���������� �� ������������ � ������ ������ ��� ���������������� ��������, �������� ���� ����� Ctrl+A, �����
// Ctrl+K+U - ������ �����������
// Ctrl+K+C - ����������������
// ��� ���������� ������ �������� �� �������� Ctrl

#include <stdio.h>
#include <malloc.h>

struct stack {
	int number;
	struct stack* next;
};

typedef struct stack stacknode;
typedef stacknode* stacknodeptr;
int counter = 0;

void push_el(stacknodeptr*, int);
int pop_el(stacknodeptr*);
int is_empty(stacknodeptr);
void print_stack(stacknodeptr);
int count_elements(stacknodeptr);
int menu();

int main() {
	stacknodeptr stackptr = NULL;
	int value;
	printf("Enter the max number of elements in stack\n");
	scanf_s("%d", &counter);
	while (1) {
		switch (menu()) {
		case 1:
			if (count_elements(stackptr) < counter) {
				printf("Enter the number \n");
				scanf_s("%d", &value);
				push_el(&stackptr, value);
			}
			else printf("You entered the maximum amount of elements.\n");
			break;
		case 2:
			if (!is_empty(stackptr))
				printf("The deleted value is %d\n", pop_el(&stackptr));
			else printf("Error.There aren't any data in stack.\n");
		case 3:
			print_stack(stackptr);
			break;
		case 4:
			printf("The amount of elements in stack: %d\n", count_elements(stackptr));
			break;
		case 5:
			return(0);
		default: printf("Error in enter.\n");
			break;
		}
	}
}

int menu() {
	int sw;
	printf("Choose the option:\n");
	printf("1)Enter the element\n");
	printf("2)Delete the element\n");
	printf("3)Print stack\n");
	printf("4)Count elements\n");
	printf("5)Exit\n");
	scanf_s("%d", &sw);
	return(sw);
}

void push_el(stacknodeptr* top_ptr, int info) {
	stacknodeptr new_ptr;
	new_ptr = new stacknode;
	if (new_ptr != NULL) {
		new_ptr->number = info;
		new_ptr->next = *top_ptr;
		*top_ptr = new_ptr;
	}
	else printf("Error in memory allocation.\n");
}

int pop_el(stacknodeptr* top_ptr) {
	stacknodeptr temp_ptr;
	int pop_value;
	temp_ptr = *top_ptr;
	pop_value = (*top_ptr)->number;
	*top_ptr = (*top_ptr)->next;
	free(temp_ptr);
	return pop_value;
}

void print_stack(stacknodeptr current_ptr) {
	if (current_ptr == NULL)
		printf("Error. There aren't any data in stack.\n");
	else {
		printf("The stack.\n");
		while (current_ptr != NULL)
		{
			printf("%d\n", current_ptr->number);
			current_ptr = current_ptr->next;
		}
	}
}

int count_elements(stacknodeptr current_ptr) {
	int counter = 0;
	while (current_ptr != NULL)
	{
		current_ptr = current_ptr->next;
		counter++;
	}
	return(counter);
}

int is_empty(stacknodeptr top_ptr) {
	return (top_ptr == NULL);
}