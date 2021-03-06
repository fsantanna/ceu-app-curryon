#define BALL_RADIUS 20
#define TRAIL_N     10
#define TRAIL_MS   250

#ifndef ALL

native do
    ##define SDL_MATH
end

#include "sdl.ceu"
#include "sdl-gfx.ceu"

input void SDL_QUIT;
input void SDL_REDRAW;
input int SDL_DT;
input _SDL_MouseButtonEvent&& SDL_MOUSEBUTTONDOWN;
input _SDL_KeyboardEvent&&    SDL_KEYDOWN;

native do
    SDL_Renderer* REN = NULL;
    int REN_W, REN_H;
end

#ifdef CEU_TIMEMACHINE
global do
#endif

var _SDL_Window&? win;
    finalize
        win = &_SDL_CreateWindow(HEADER_TITLE,
                 _SDL_WINDOWPOS_UNDEFINED, _SDL_WINDOWPOS_UNDEFINED,
                 600, 400, _SDL_WINDOW_SHOWN);
    with
        _SDL_DestroyWindow(&&win!);
    end

_SDL_GetWindowSize(&&win!, &&_REN_W, &&_REN_H);

finalize
    _REN = _SDL_CreateRenderer(&&win!, -1, 0);
with
    _SDL_DestroyRenderer(_REN);
end

#ifdef CEU_TIMEMACHINE
end
#endif

#else

#ifdef CEU_TIMEMACHINE
input bool OS_RESUME;
class Title with
do
    loop do
        _SDL_SetWindowTitle(_WIN, HEADER_TITLE);
        await OS_RESUME;
    end
end
var Title t;
#else
_SDL_SetWindowTitle(_WIN, HEADER_TITLE);
#endif

#endif
