#include "path.h"
#include <stdio.h>

/*
 * A - B - C - E - G - H
 *       |             |
 *       - D - F - - - -
*/
int main() {
    NODE nodeA = { 'A', 0 };
    NODE nodeB = { 'B', 0 };
    NODE nodeC = { 'C', 0 };
    NODE nodeD = { 'D', 0 };
    NODE nodeE = { 'E', 0 };
    NODE nodeF = { 'F', 0 };
    NODE nodeG = { 'G', 0 };
    NODE nodeH = { 'H', 0 };

    set_next(&nodeA, (NODE*[]){ &nodeB, 0 });

    set_previous(&nodeB, (NODE*[]){ &nodeA, 0 });
    set_next(&nodeB, (NODE*[]){ &nodeC, &nodeD });

    set_previous(&nodeC, (NODE*[]){ &nodeB, 0 });
    set_next(&nodeC, (NODE*[]){ &nodeE, 0 });

    set_previous(&nodeD, (NODE*[]){ &nodeB, 0 });
    set_next(&nodeD, (NODE*[]){ &nodeF, 0 });

    set_previous(&nodeE, (NODE*[]){ &nodeC, 0 });
    set_next(&nodeE, (NODE*[]){ &nodeG, 0 });

    set_previous(&nodeF, (NODE*[]){ &nodeD, 0 });
    set_next(&nodeF, (NODE*[]){ &nodeH, 0 });

    set_previous(&nodeG, (NODE*[]){ &nodeE, 0 });
    set_next(&nodeG, (NODE*[]){ &nodeH, 0 });

    set_previous(&nodeH, (NODE*[]){ &nodeG, &nodeF });

    navigate_nodes(&nodeA);

    return 0;
}
