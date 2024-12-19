#include "Render.h"
#include "World.h"
#include "Wall.h"

int main() {
    Render* render = new Render();
    World world(20, 20);
    render->addRenderable({
        &world,
        newwin(26, 26 * 2, 1, 1)
        });
    for (;;) {
        int ch = getch();  // Non-blocking call

        if (ch == 'q') {  // Press 'q' to exit
            break;
        }

        render->step();
    }
    delete render;
    return 0;
}
