#include "list.h"

#include <stdio.h>
#include <stdlib.h>

struct mys {
    int x, y;
} mys;

int main(int argc, char const *argv[]) {

    struct list* l = create_list();


    struct mys *p = (struct mys*)malloc(sizeof(struct mys));
    p->x = 1;
    p->y = 1;
    add_data(l, "1", p);
    p = (struct mys*)malloc(sizeof(struct mys));
    p->x = 2;
    p->y = 2;
    add_data(l, "2", p);
    p = (struct mys*)malloc(sizeof(struct mys));
    p->x = 3;
    p->y = 3;
    add_data(l, "3", p);

    while (!is_empty(l)) {
        p = pop_data(l);
        printf("%d %d\n", p->x, p->y);

    }

	return 0;
}
