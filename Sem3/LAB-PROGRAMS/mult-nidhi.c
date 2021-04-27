#include<stdio.h>
#include<stdlib.h>

struct node
{
int coeff,expo;
struct node *next;
};

struct node *getnode(int c,int e){
struct node *p;
p=(struct node *)malloc(sizeof(struct node));
p->coeff=c;
p->expo=e;
p->next=NULL;
return p;
}

struct node *createpoly(struct node *poly){
struct node *p, *q;
int n,c,e;
printf("Enter number of terms : \n");
scanf("%d",&n);
printf("Enter coefficient and power from the highest degree term: \n");
for(int i=0;i<n;i++){
scanf("%d%d",&c,&e);
p=getnode(c,e);
if(poly==NULL){
poly=p;
q=p;
}else{
q->next=p;
q=q->next;
}
}
return poly;
}

void display(struct node *poly){
if(poly==NULL)
printf("\nEmpty Polynomial\n");
else{
struct node *q;
q=poly;
printf("\nPolynomial :  ");
while(q->next!=NULL){
printf("%d*(x^%d)  +  ",q->coeff,q->expo);
q=q->next;
}
printf("%d*(x^%d)",q->coeff,q->expo);
}
}
struct node *insertend(struct node *head,int c,int e){
struct node *p;
p=getnode(c,e);
if(head==NULL)
head=p;
else{
struct node *q;
q=head;
while(q->next!=NULL)
q=q->next;
q->next=p;
}
return head;
}

struct node *multipoly(struct node *poly1, struct node *poly2){
int resc,rese;
struct node *result=NULL;
if(poly1==NULL)
return poly2;
if(poly2==NULL)
return poly1;
struct node *p1, *p2;
for(p1=poly1;p1!=NULL;p1=p1->next){
for(p2=poly2;p2!=NULL;p2=p2->next){
resc=p1->coeff*p2->coeff;
rese=p1->expo+p2->expo;
result=insertend(result,resc,rese);
}
}
return result;
}
struct node *simplify(struct node *res){
struct node *p, *q, *temp;
if(res!=NULL){
for(p=res;p->next!=NULL;p=p->next){
for(q=p;q->next!=NULL;q=q->next){
temp=q->next;
while(temp!=NULL && temp->expo==p->expo){
p->coeff=p->coeff+temp->coeff;
q->next=temp->next;
free(temp);
temp=q->next;
}
}
}
}
return res;
}

int main()
{   struct node *poly1, *poly2, *respoly;
poly1=poly2=NULL;
printf("\nFor polynomial One, ");
poly1=createpoly(poly1);
display(poly1);
printf("\n\nFor polynomial Two, ");
poly2=createpoly(poly2);
display(poly2);
respoly=multipoly(poly1, poly2);
printf("\n\nAfter Multiplication,  ");
display(respoly);
printf("\n\nAfter Simplification,  ");
display(simplify(respoly));
return 0;
}
