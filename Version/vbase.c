#include <SDL2/SDL.h>
#include "function.h"

#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 920

int main() {
    init(WINDOW_WIDTH, WINDOW_HEIGHT);
    changeColor(255, 255, 255);
    drawCircle(300, 300, 100);
    changeColor(255, 255, 0);
    drawLine(0, 0, 200, 200);
    drawSquare(400, 400, 50);
    //sprite(0, 500, "assets/image.bmp");
    drawPoint(300, 50);
    actualize();

    SDL_bool program_launched = SDL_TRUE;
    while(program_launched) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    program_launched = SDL_FALSE;
                    break;
                case SDL_KEYDOWN:
                    lastKeyPressed(&event);
                    switch (event.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            program_launched = SDL_FALSE;
                            break;
                        default:
                            break;
                    }
                default:
                    break;
            }
        }
    }
    freeAndTerminate();
}