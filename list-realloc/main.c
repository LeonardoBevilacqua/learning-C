#include "list.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
    NODE node = {0};
    for (int i = 0; i < 10; ++i) {
        if (node.count >= node.capcity) {
            if (node.capcity == 0) node.capcity = 256;
            else node.capcity *= 2;

            node.items = realloc(node.items, sizeof(*node.items) * node.capcity);
        }

        node.items[node.count++] = i;
    }

    for (size_t i = 0; i < node.count; ++i) printf("%d\n", node.items[i]);

    return 0;
}
