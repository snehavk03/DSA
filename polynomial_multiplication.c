#include<stdio.h>
#include<stdlib.h>

struct node{
    int coeff;
    int expo;
    struct node * next;
};

struct node *insert(struct node *head, int co, int ex) {
    struct node *temp;
    struct node * new = malloc(sizeof(struct node));
    new->coeff = co;
    new->expo = ex;
    new->next = NULL;

    if (head == NULL || ex > head->expo) {
        new->next = head;
        head = new;
    }
    else if(ex == head->expo){
        head->coeff +=co;
        free(new);
    }
    else {
        temp = head;
        while (temp->next != NULL && ex < temp->next->expo) {
            temp = temp->next;
        }
        if (temp->next != NULL && ex == temp->next->expo) {
            temp->next->coeff += co;
            free(new);
        }
        else{
        new->next = temp->next;
        temp->next = new;
    }
    }

    return head;
}


struct node *create(struct node *head, int n) {
    int coeff;
    int expo;

    for (int i = 0; i < n; i++) {
        printf("Enter the coefficient of term %d: ", i + 1);
        scanf("%d", &coeff);
        printf("Enter the exponent of term %d: ", i + 1);
        scanf("%d", &expo);
        head = insert(head, coeff, expo);
    }
    return head;
}

void print(struct node *head) {
    struct node *temp = head;
    if (head == NULL) {
        printf("No polynomial.");
        return;
    }

    while (temp != NULL) {
        printf("%dx^%d ", temp->coeff, temp->expo);
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
}

struct node * multiply(struct node * head1,struct node *head2){
    struct node * head=NULL;
    struct node * ptr1=head1;
    struct node * ptr2=head2;
    int res1,res2;
    while(ptr1!=NULL){
        
        while(ptr2!=NULL){
            res1=ptr1->coeff*ptr2->coeff;
            res2=ptr1->expo+ptr2->expo;
            head=insert(head,res1,res2);
            ptr2=ptr2->next;
            
        }
        ptr1=ptr1->next;
        ptr2=head2;
    }
    return head;
}


int main(){
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *head3 = NULL;
    int n, m;
    printf("Enter the number of terms in polynomial 1: ");
    scanf("%d", &n);
    head1 = create(head1, n);
    printf("Enter the number of terms in polynomial 2: ");
    scanf("%d", &m);
    head2 = create(head2, m);
    print(head1);
    printf(" \n");
    print(head2);
    printf(" \n");
    head3=multiply(head1,head2);
    print(head3);
    return 0;
}
