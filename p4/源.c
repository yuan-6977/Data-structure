#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
struct Node* head;//ͷָ��

void Insert(int x) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));//��̬���䣬tempָ���½ڵ�
	temp->data = x;//data��ֵΪx
	temp->next = head;//����ǰ�����룬�½ڵ��ָ��ָ��ԭ��һ���ڵ�
	head = temp;//ͷָ���Ϊָ���½ڵ�
}

void Print() {
	struct Node* temp = head;//����temp�������˴�����ֱ����head����������ᶪʧͷ�ڵ��ַ
	printf("List is:");
	while (temp != NULL) {//��temp=NULLʱ��˵���ѵ�����ĩ�ˣ���������
		printf(" %d", temp->data);
		temp = temp->next;//����
	}
	printf("\n");
}
int main() {
	head = NULL;//��
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
