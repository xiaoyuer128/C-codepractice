
#include<stdio.h>
#include<malloc.h>
typedef  struct list {
    int data;
    struct list * next;  //下一个节点地址
}list;
//第一条链表
struct list * L=NULL;//头
struct list * head=NULL;//首
struct list * p=NULL;
//第二条链表
struct list * L1=NULL;//头
struct list * head1=NULL;//首
struct list * p1=NULL;
//代理链表
struct list * L2=NULL;//头
struct list * q=NULL;
int main(){
	int i=0,length;
	printf("请输入链表的长度\n");
	scanf("%d",&length);
	head=(struct list *)malloc(sizeof(struct  list));
	L=head;
	printf("请依次输入链表的内容\n");
	for(i;i<length;i++){
		p = (struct list *)malloc(sizeof(struct  list));
        scanf("%d",&p->data);
        p->next=NULL;
        head->next=p;
        head=p;
    }
    int i1=0,length1;
	printf("请输入链表的长度\n");
	scanf("%d",&length1);

	head1=(struct list *)malloc(sizeof(struct  list));
	L1=head1;
	printf("请依次输入链表的内容\n");
	for(i1;i1<length1;i1++){
		p1= (struct list *)malloc(sizeof(struct  list));
        scanf("%d",&p1->data);
        p1->next=NULL;
        head1->next=p1;
        head1=p1;
    }
    p=L->next;//得到首原节点
	p1=L1->next;//得到首原节点
	L2=(struct list *)malloc(sizeof(struct  list));
    L2=L;//指向已有链表空间
    L2->next=NULL;
	q=(struct list *)malloc(sizeof(struct  list));
	//循环里主要是 头插法原理
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
