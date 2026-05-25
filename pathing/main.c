#include "path.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 8
/*
 * A - B - C - E - G - H
 *       |             |
 *       - D - F - - - -
*/
int main() {
    NODE* nodes = malloc(sizeof(NODE) * MAX_NODES);
    char values[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };

    for (int i = 0; i < MAX_NODES; i++) nodes[i] = create_node(values[i]);

    connect_next_nodes(&nodes[0], (NODE*[]){ &nodes[1], NULL });

    connect_previous_nodes(&nodes[1], (NODE*[]){ &nodes[0], NULL });
    connect_next_nodes(&nodes[1], (NODE*[]){ &nodes[2], &nodes[3] });

    connect_previous_nodes(&nodes[2], (NODE*[]){ &nodes[1], NULL });
    connect_next_nodes(&nodes[2], (NODE*[]){ &nodes[4], NULL });

    connect_previous_nodes(&nodes[3], (NODE*[]){ &nodes[1], NULL });
    connect_next_nodes(&nodes[3], (NODE*[]){ &nodes[5], NULL });

    connect_previous_nodes(&nodes[4], (NODE*[]){ &nodes[2], NULL });
    connect_next_nodes(&nodes[4], (NODE*[]){ &nodes[6], NULL });

    connect_previous_nodes(&nodes[5], (NODE*[]){ &nodes[3], NULL });
    connect_next_nodes(&nodes[5], (NODE*[]){ &nodes[7], NULL });

    connect_previous_nodes(&nodes[6], (NODE*[]){ &nodes[4], NULL });
    connect_next_nodes(&nodes[6], (NODE*[]){ &nodes[7], NULL });

    connect_previous_nodes(&nodes[7], (NODE*[]){ &nodes[6], &nodes[5] });

    navigate_nodes(nodes);

    free(nodes);
    return 0;
}
