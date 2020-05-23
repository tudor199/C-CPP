#include "list.h"

#include <stdlib.h>
#include <string.h>

struct node *make_node(char *identity, void * data) {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->identity = (char*)malloc((strlen(identity) + 1) * sizeof(struct node));
    strcpy(n->identity, identity);
    n->data = data;
    n->next = NULL;
}

void *extract_data_and_free(struct node *n) {
    void *data = n->data;
    free(n->identity);
    free(n);
    return data;
}

struct list *create_list() {
    struct list *l = (struct list*)malloc(sizeof(struct list));
    l->head = NULL;
}

int is_empty(struct list *l) {
    return l->head == NULL;
}
void add_data(struct list *l, char *identity ,void *data) {
    struct node *n = make_node(identity, data);
    if (l->head == NULL) {
        l->head = n;
    } else {
        n->next = l->head;
        l->head = n;
    }
}

void *get_data(struct list *l, char* identity) {
    struct node *n = l->head;
    while (n != NULL) {
        if (!strcmp(n->identity, identity)) {
            return n->data;
        }
        n = n->next;
    }
    return NULL;
}

void *remove_data(struct list *l, char* identity) {
    struct node *n = l->head;
    if (l->head == NULL) {
        return NULL;
    }
    if (!strcmp(l->head->identity, identity)) {
        struct node *aux = l->head;
        l->head = l->head->next;
        return extract_data_and_free(aux);
    }

    while (n->next != NULL) {
        if (!strcmp(n->next->identity, identity)) {
            struct node *aux = n->next;
            n->next = n->next->next;
            return extract_data_and_free(aux);
        }
        n = n->next;
    }
    return NULL;
}

void *pop_data(struct list*l) {
    if (l->head != NULL) {
        struct node *aux = l->head;
        l->head = l->head->next;
        return extract_data_and_free(aux);
    }
    return NULL;
}
