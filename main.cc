#include "input.h"
#include "display.h"

int main(void)
{
    /*Window window;

    window.run();*/

    Display display;
    Input input(&display);

    input.run();

    return 0;
}
