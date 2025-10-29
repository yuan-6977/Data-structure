#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* link;
};
struct Node* head;

void Insert(int num, int pos) {
	struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
	temp1->data = num;
	temp1->link = NULL;
	if (pos == 1) {
		temp1->link = head;
		head = temp1;
	}
	else {
		struct Node* temp2 = head;
		for (int i = 0; i < pos - 2; i++)
			temp2 = temp2->link;
		temp1->link = temp2->link;
		temp2->link = temp1;
	}
}

void Delete(int pos) {
	struct Node* temp1 = head;
	if (pos == 1) {
		head = temp1->link;
		free(temp1);
		return;
	}//刚开始我忽略了pos=1的情况，要特别注意，头指针head是一个特殊情况
	for (int i = 0; i < pos - 2; i++)
		temp1 = temp1->link;
	struct Node* temp2 = temp1->link;
	temp1->link = temp2->link;
	free(temp2);
}

void Print() {
	struct Node* temp = head;
	printf("List is: ");
	for (int i = 0; temp != NULL; i++) {
		printf("%d ", temp->data);
		temp = temp->link;
	}
	printf("\n");
}

int main() {
	head = NULL;

	int n = 0;
	printf("how many numbers?");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		int num = 0, pos = 0;
		printf("Enter the num and pos:");
		scanf_s("%d %d", &num, &pos);
		Insert(num, pos);
		Print();
	}

	int sec = 0;
	printf("Do you want to delete any node?\n");
	scanf_s("%d", &sec);
	if (sec == 1) {
		int pos = 0;
		printf("Enter the position of the node:");
		scanf_s("%d", &pos);
		Delete(pos);
		Print();
	}
}