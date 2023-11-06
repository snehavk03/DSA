#include<stdio.h>
#include<stdlib.h>

struct node
{
    long int digit;
    struct node *next;
};

struct node * push(struct node * head,int val){
    struct node * new=malloc(sizeof(struct node));
    new->digit=val;
    new->next=head;
    head=new;
    return head;
}

struct node * add(struct node * head1,struct node * head2){
    if(head1->digit==0){
        return head1;
    }
    if(head2->digit==0){
        return head2;
    }

    struct node * ptr1=head1;
    struct node *ptr2=head2;
    struct node * head3=NULL;

    int sum=0,carry=0;
    while(ptr1||ptr2){
        sum=0;
        if(ptr1!=NULL){
            sum=sum+ptr1->digit;
        }
        if(ptr2!=NULL){
            sum=sum+ptr2->digit;
            
        }
        sum=sum+carry;
        carry=sum/10;
        sum=sum%10;

        head3=push(head3,sum);
        if(ptr1!=NULL){
            ptr1=ptr1->next;
        }
        if(ptr2!=NULL){
            ptr2=ptr2->next;
        }
    }
    if(carry){
        head3=push(head3,carry);
    }
    return head3;
}

struct node * reversell(struct node * head){
    if(head==NULL){
        return head;
    }
    struct node * current=NULL;
    struct node * next=head->next;
    head->next=NULL;

    while(next!=NULL){
        current=next;
        next=next->next;
        current->next=head;
        head=current;
    }
    return head;

}

struct node * add_node(struct node * head,int val){
    struct node *new=malloc(sizeof(struct node));
    new->digit=val;
    new->next=NULL;

    new->next=head;
    head=new;
    return head;
}

struct node * create(struct node *head,int n){
    while (n!=0){
        head=add_node(head,n%10);
        n=n/10;
    }
    return head;
}


void print_nodes(struct node * head){
    struct node* temp=head;
        while(temp!=NULL){
            printf("%d",temp->digit);
            temp=temp->next;
        }
    
}

int main()
{
    struct node *head1,*head2;
    head1 = NULL;
    head2=NULL;

    long int n1,n2;
    printf("\nEnter the number 1: ");
    scanf("%d",&n1);

    printf("\nEnter the number 2: ");
    scanf("%d",&n2);
    
    head1=create(head1,n1);
    print_nodes(head1);
    printf("\n");

    head2=create(head2,n2);
    print_nodes(head2);

    head1=reversell(head1);
    head2=reversell(head2);

    printf("\nReversed Linked lists: \n");
    print_nodes(head1);
    printf("\n");
    print_nodes(head2);

    struct node * head3=NULL;
    head3=add(head1,head2);
    printf("\n");
    printf("\n");
    printf("Sum of the two long integers is: ");
    print_nodes(head3);

    return 0;
}
