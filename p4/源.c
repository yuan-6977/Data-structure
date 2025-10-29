#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
struct Node* head;//头指针

void Insert(int x) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));//动态分配，temp指向新节点
	temp->data = x;//data赋值为x
	temp->next = head;//在最前方插入，新节点的指针指向原第一个节点
	head = temp;//头指针改为指向新节点
}

void Print() {
	struct Node* temp = head;//利用temp遍历，此处不能直接用head遍历，否则会丢失头节点地址
	printf("List is:");
	while (temp != NULL) {//当temp=NULL时，说明已到链表末端，结束遍历
		printf(" %d", temp->data);
		temp = temp->next;//遍历
	}
	printf("\n");
}
int main() {
	head = NULL;//空
	int n, i, x;
	printf("How many numbers?");
	scanf_s("%d", &n);

	printf("Enter the number: ");
	for (i = 0; i < n; i++) {
		scanf_s("%d", &x);
		Insert(x);
	}
	Print();
}
