/**
 * list data structure containing the tasks in the system
 */
#include "task.h"

typedef struct node {
    Task *task;
     struct node *next;
} node;

// insert and delete operations.
void insert(struct node **head, Task *task);
void delete(struct node **head, Task *task);
void traverse(struct node *head);
struct node* pop(struct node **head);
void insert_end(struct node **head, struct node *new_node);