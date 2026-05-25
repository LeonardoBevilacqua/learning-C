#include "path.h"
#include <stdio.h>

/*
 * A - B - C - E - G - H
 *       |             |
 *       - D - F - - - -
*/
int main() {
    NODE nodeA = create_node('A');
    NODE nodeB = create_node('B');
    NODE nodeC = create_node('C');
    NODE nodeD = create_node('D');
    NODE nodeE = create_node('E');
    NODE nodeF = create_node('F');
    NODE nodeG = create_node('G');
    NODE nodeH = create_node('H');

    connect_next_nodes(&nodeA, (NODE*[]){ &nodeB, NULL });

    connect_previous_nodes(&nodeB, (NODE*[]){ &nodeA, NULL });
    connect_next_nodes(&nodeB, (NODE*[]){ &nodeC, &nodeD });

    connect_previous_nodes(&nodeC, (NODE*[]){ &nodeB, NULL });
    connect_next_nodes(&nodeC, (NODE*[]){ &nodeE, NULL });

    connect_previous_nodes(&nodeD, (NODE*[]){ &nodeB, NULL });
    connect_next_nodes(&nodeD, (NODE*[]){ &nodeF, NULL });

    connect_previous_nodes(&nodeE, (NODE*[]){ &nodeC, NULL });
    connect_next_nodes(&nodeE, (NODE*[]){ &nodeG, NULL });

    connect_previous_nodes(&nodeF, (NODE*[]){ &nodeD, NULL });
    connect_next_nodes(&nodeF, (NODE*[]){ &nodeH, NULL });

    connect_previous_nodes(&nodeG, (NODE*[]){ &nodeE, NULL });
    connect_next_nodes(&nodeG, (NODE*[]){ &nodeH, NULL });

    connect_previous_nodes(&nodeH, (NODE*[]){ &nodeG, &nodeF });

    navigate_nodes(&nodeA);

    return 0;
}
