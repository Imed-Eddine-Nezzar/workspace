#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int num;
    struct Node* next;
} node_s, * node_ptr;


node_ptr unintialized_node() {
    return (node_ptr) malloc(sizeof(node_s));
}


node_ptr initialized_node(int n, node_ptr next) {
    node_ptr tmp = unintialized_node();
    tmp->num = n;
    tmp->next = next;
    return tmp;
}

void delete_node(node_ptr n) {
    if (n) free(n);
}


node_ptr list_append(node_ptr head, int x) {
    if (head == NULL)
        return initialized_node(x, NULL);

    node_ptr it = head;
    for (; it->next; it = it->next)
        ;

    it->next = initialized_node(x, NULL);
    return head;
}

node_ptr list_remove(node_ptr head, int x) {
    if (head) {
        node_ptr prev = head;
        if (head->num == x) {
            head = head->next;
            delete_node(prev);
            return head;
        }

        node_ptr it = head;
        for (; it; it = it->next) {
            if (it->num == x) {
                prev->next = it->next;
                delete_node(it);
            }
            prev = it;
        }
        return head;
    }
    return NULL;
}

void list_destroy(node_ptr* head) {
    node_ptr tmp;
    while (*head) {
        tmp = *head;
        *head = (*head)->next;
        delete_node(tmp);
    }
}

int list_search(node_ptr head, int val) {
    for (int i = 0; head; head = head->next, ++i)
        if (head->num == val)
            return i;
    return -1;
}

void list_display(node_ptr head) {
    for (; head; head = head->next)
        printf("[%d]->", head->num);
    printf("NULL\n");
}

/* int main() { */
/*     node_ptr my_list = NULL; */
/*     int i = 10; */
/*     while (i--) my_list = list_append(my_list, i); */
/*     list_display(my_list); */
/*  */
/*     my_list = list_remove(my_list, 3); */
/*     my_list = list_remove(my_list, 0); */
/*     my_list = list_remove(my_list, 9); */
/*  */
/*     list_display(my_list); */
/*     list_destroy(&my_list); */
/* } */

int main(void) {

    int num;
    int input;
    node_ptr llist = NULL;

    do {
        printf("\n-- Menu Selection --\n");
        printf("0) Quit\n");
        printf("1) Insert\n");
        printf("2) Delete\n");
        printf("3) Search\n");
        printf("4) Display\n");
        scanf("%d", &input);

        switch (input) {

            case 0:
                printf("Goodbye ...\n");
                input = 0;
                break;

            case 1:
                printf("Your choice: `Insertion'\n");
                printf("Enter the value which should be inserted: ");
                scanf("%d", &num);
                llist = list_append(llist, num);
                break;

            case 2:
                printf("Your choice: `Deletion'\n");
                printf("Enter the value which should be deleted: ");
                scanf("%d", &num);
                llist = list_remove(llist, num);
                break;

            case 3:
                printf("Your choice: `Search'\n");
                printf("Enter the value you want to find: ");
                scanf("%d", &num);
                // declare variables right close to the code block
                // using them
                // 'retval' should be declared here
                int retval = list_search(llist, num);
                if (retval == -1)
                    printf("Value `%d' not found\n", num);
                else
                    printf("Value `%d' located at position `%d'\n", num, retval);
                break;

            case 4:
                printf("You choice: `Display'\n");
                list_display(llist);
                break;

            default:
                printf("Please pick one of the choices.\n");

        } /* switch */
    } while (input != 0);

    list_destroy(&llist);
    return 0;
}

