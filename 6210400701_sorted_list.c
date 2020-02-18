//6210400701 Theeraporn Bupatham
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
int main(){
    int input;
    struct node *head = NULL, *tail = NULL, *tmp;
    while (scanf("%d", &input) == 1){
        if (input <= -1)
            break;
        if (head == NULL){
            head = tail = (struct node *)malloc(sizeof(struct node));
            tail->data = input;
            tail->next = NULL;
        }
        else {
            for (tmp = head;tmp; tmp = tmp->next ){
                if (tmp == head && input <= tmp->data){
                        tmp = (struct node *)malloc(sizeof(struct node));
                        tmp->data = input;
                        tmp->next = head;
                        head = tmp;
                        break;
                }
                else if (input > tmp->data ){
                    if (tmp->next == NULL){
                        tail->next = (struct node *)malloc(sizeof(struct node));
                        tail = tail->next;
                        tail->data = input;
                        tail->next = NULL;
                        break;
                    }
                    else if (input <= (tmp->next)->data ) {
                        struct node *new = (struct node *)malloc(sizeof(struct node));
                        new->data = input;
                        new->next = tmp->next;
                        tmp->next = new;
                        break;
                    }   
                }
            }
        }
    }
    for (tmp = head;tmp; tmp = tmp->next ){
            printf("%d\n",tmp->data);
    }
    return 0;
}