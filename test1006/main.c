
#include<stdio.h>
#include<malloc.h>
typedef  struct list {
    int data;
    struct list * next;  //��һ���ڵ��ַ
}list;
//��һ������
struct list * L=NULL;//ͷ
struct list * head=NULL;//��
struct list * p=NULL;
//�ڶ�������
struct list * L1=NULL;//ͷ
struct list * head1=NULL;//��
struct list * p1=NULL;
//��������
struct list * L2=NULL;//ͷ
struct list * q=NULL;
int main(){
	int i=0,length;
	printf("����������ĳ���\n");
	scanf("%d",&length);
	head=(struct list *)malloc(sizeof(struct  list));
	L=head;
	printf("�������������������\n");
	for(i;i<length;i++){
		p = (struct list *)malloc(sizeof(struct  list));
        scanf("%d",&p->data);
        p->next=NULL;
        head->next=p;
        head=p;
    }
    int i1=0,length1;
	printf("����������ĳ���\n");
	scanf("%d",&length1);

	head1=(struct list *)malloc(sizeof(struct  list));
	L1=head1;
	printf("�������������������\n");
	for(i1;i1<length1;i1++){
		p1= (struct list *)malloc(sizeof(struct  list));
        scanf("%d",&p1->data);
        p1->next=NULL;
        head1->next=p1;
        head1=p1;
    }
    p=L->next;//�õ���ԭ�ڵ�
	p1=L1->next;//�õ���ԭ�ڵ�
	L2=(struct list *)malloc(sizeof(struct  list));
    L2=L;//ָ����������ռ�
    L2->next=NULL;
	q=(struct list *)malloc(sizeof(struct  list));
	//ѭ������Ҫ�� ͷ�巨ԭ��
	while(p||p1){
		if(!p){
			q=p1;
			p1=p1->next;
		}
		else if(!p1){
		    q=p;
			p=p->next;
		}else if(p->data<=p1->data){
			q=p;
			p=p->next;
		}else{
			q=p1;
			p1=p1->next;
		}
	    q->next = L2->next;
        L2->next=q;
	}
	free(L1);
    p=L2->next;
    while(p){
	printf("%d ",p->data);
	p=p->next;
	}
}
