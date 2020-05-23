#ifndef GENERIC_LIST

#define GENERIC_LIST

struct node {
    char *identity;
    void *data;
    struct node *next;
} node;

struct list {
    struct node* head;
} list;

struct node *make_node(char *, void *);

void *extract_data_and_free(struct node *);

struct list *create_list();

int is_empty(struct list *);

void add_data(struct list*, char*, void *);

void *get_data(struct list *l, char*);

void *remove_data(struct list *l, char*);

void *pop_data(struct list*);


#endif
