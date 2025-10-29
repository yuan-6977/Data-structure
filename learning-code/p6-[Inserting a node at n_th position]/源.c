#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* link;
};
struct Node* head;

Insert(int data, int pos) {
	struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
	temp1->data = data;
	if (pos == 1) {
		temp1->link = head;
		head = temp1;
	}
	else {
		struct Node* temp2 = head;
		for (int i = 0; i < pos - 2; i++)//ע����pos-2����Ϊ�տ�ʼtemp2=head��ָ����ǵ�һ���ڵ㣬temp2��Ҫ�ƶ���pos��ǰһ����㣬Ϊpos-2��
			temp2 = temp2->link;

		temp1->link = temp2->link;//��Ҫ��temp2->link��temp2��죡����
		temp2->link = temp1;
	}
}

Print() {
	struct Node* temp = head;
	printf("List is:");
	while(temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->link;//�������
	}
	printf("\n");
}

int main() {
	head = NULL;
	int n = 0;
	printf("How many numbers?");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		int num = 0,pos =0;
		printf("Enter the num and position: ");
		scanf_s("%d %d", &num, &pos);
		Insert(num, pos);
		Print();
	}
}