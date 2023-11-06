#include<stdio.h>
#include<stdlib.h>

struct node{
    int coeff;
    int expo;
    struct node * next;
};

struct node * insert(struct node * head,int co,int ex){
    struct node * temp;
    struct node * new=malloc(sizeof(struct node));
    new->coeff=co;
    new->expo=ex;
    new->next=NULL;

    if(head==NULL || ex>head->expo){
        new->next=head;
        head=new;
    }

    else{
        temp=head;
        while(temp->next!=NULL && temp->next->expo>ex){
            temp=temp->next;
        }
        new->next=temp->next;
        temp->next=new;
    }
    return head;
}
struct node * create(struct node * head){
    int n;
    int coeff;
    int expo;

    printf("\nEnter the number of terms in the polynomial: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("\nEnter the coefficient: ");
        scanf("%d",&coeff);

        printf("\nEnter the exponent: ");
        scanf("%d",&expo);
        head=insert(head,coeff,expo);
    }
    return head;

}

void print(struct node * head){
    if (head==NULL){
        printf("No polynomial!");
    }
    else{
        struct node * temp=head;
        while(temp!=NULL){
            printf("(%dx^ %d)",temp->coeff,temp->expo);
            temp=temp->next;
            if(temp!=NULL){
                printf("+");
            }
            else{
                printf("\n");
            }
        }
    }
}

void add(struct node * head1,struct node * head2){
    struct node * ptr1=head1;
    struct node * ptr2=head2;
    struct node * head3=NULL;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->expo==ptr2->expo){
            head3=insert(head3,ptr1->coeff,ptr1->expo);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }

        else if(ptr1->expo > ptr2->expo){
            head3=insert(head3,ptr1->coeff,ptr1->expo);
            ptr1=ptr1->next;
        }

        else if(ptr1->expo<ptr2->expo){
            head3=insert(head3,ptr2->coeff,ptr2->expo);
            ptr2=ptr2->next;
        }
    }
    while(ptr1!=NULL){
        head3=insert(head3,ptr1->coeff,ptr1->expo);
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL){
        head3=insert(head3,ptr2->coeff,ptr2->expo);
        ptr2=ptr2->next;
    }
    printf("Added polynomial is: ");
    print(head3);

}
int main(){
    struct node * head1=NULL;
    struct node * head2=NULL;

    printf("\nEnter the details of polynomial 1");
    head1=create(head1);
    print(head1);
    printf("\nEnter the details of polynomial 2");
    head2=create(head2);
    print(head2);
    add(head1,head2);
    
    return 0;
}

