/*****************************************************************************

main.c

SDL2 Hello World

*****************************************************************************/

/*============================================================================
Includes
============================================================================*/

#include "SDL2/SDL.h"

/*============================================================================
Macros
============================================================================*/

/*============================================================================
Types and Structures
============================================================================*/

/*============================================================================
Memory Constants
============================================================================*/

/*============================================================================
Module Variables
============================================================================*/

/*============================================================================
Module Prototypes
============================================================================*/

/*============================================================================
Implementation
============================================================================*/


/*==========================================================================*/
int main(                               /* program entry point              */
    int                 argc,           /* number of arguments              */
    const char**        argv            /* list of arguments                */
) {                                     /* return program exist status      */

    /*--------------------------------------------------------------------
    Literal Constants
    --------------------------------------------------------------------*/
    #define SCREEN_WIDTH  ( 640 )
    #define SCREEN_HEIGHT ( 640 )
    #define PITCH         ( SCREEN_WIDTH * sizeof( unsigned long ) )

    /*--------------------------------------------------------------------
    Local Variables
    --------------------------------------------------------------------*/
    unsigned long       blue;           /* example blue channel value       */
    SDL_Event           event;          /* SDL event data                   */
    static unsigned long
                        pixels[ SCREEN_HEIGHT ][ SCREEN_WIDTH ];
                                        /* local pixel data                 */
    SDL_Renderer *      renderer;       /* SDL rendering context            */
    int                 result;         /* SDL return result                */
    int                 running;        /* program running flag             */
    SDL_Texture *       texture;        /* SDL example texture              */
    SDL_Window *        window;         /* SDL window object                */
    unsigned short      x_index;        /* horizontal data index            */
    unsigned short      y_index;        /* vertical data index              */

    /*--------------------------------------------------------------------
    Initialize SDL.
    --------------------------------------------------------------------*/
    result = SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER );
    if( result != 0 ) {
        return 1;
    }
    atexit( SDL_Quit );

    /*--------------------------------------------------------------------
    Create SDL window.
    --------------------------------------------------------------------*/
    window = SDL_CreateWindow(
        "Hello World!",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );
    if( window == NULL ) {
        SDL_Quit();
        return 1;
    }

    /*--------------------------------------------------------------------
    Create SDL rendering context.
    --------------------------------------------------------------------*/
    renderer = SDL_CreateRenderer( window, -1, 0 );
    if( renderer == NULL ) {
        SDL_DestroyWindow( window );
        SDL_Quit();
        return 1;
    }

    /*--------------------------------------------------------------------
    Create a streaming texture.
    --------------------------------------------------------------------*/
    texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        SCREEN_WIDTH,
        SCREEN_HEIGHT
    );
    if( texture == NULL ) {
        SDL_DestroyRenderer( renderer );
        SDL_DestroyWindow( window );
        SDL_Quit();
        return 1;
    }

    /*--------------------------------------------------------------------
    Manipulate pixel data.
    --------------------------------------------------------------------*/
    blue = 0;
    for( y_index = 0; y_index < SCREEN_HEIGHT; ++y_index ) {
        blue = ( unsigned long ) (
            ( y_index * 60 ) / ( float ) SCREEN_HEIGHT
        );
        for( x_index = 0; x_index < SCREEN_WIDTH; ++x_index ) {
            pixels[ y_index ][ x_index ] = 0xFF000000 | blue;
        }
    }

    /*--------------------------------------------------------------------
    Write pixels to texture.
    --------------------------------------------------------------------*/
    SDL_UpdateTexture( texture, NULL, &pixels, PITCH );

    /*--------------------------------------------------------------------
    Render loop.
    --------------------------------------------------------------------*/
    running = 1;
    while( running == 1 ) {

        /*----------------------------------------------------------------
        Dequeue pending events.
        ----------------------------------------------------------------*/
        while( SDL_PollEvent( &event ) ) {
            if( event.type == SDL_QUIT ) {
                running = 0;
                break;
            }
        }

        /*----------------------------------------------------------------
        Exit the render loop more responsively.
        ----------------------------------------------------------------*/
        if( running == 0 ) {
            break;
        }

        /*----------------------------------------------------------------
        Update the rendering context.
        ----------------------------------------------------------------*/
        SDL_RenderClear( renderer );
        SDL_RenderCopy( renderer, texture, NULL, NULL );
        SDL_RenderPresent( renderer );

        /*----------------------------------------------------------------
        Cede time to the OS.
        ----------------------------------------------------------------*/
        SDL_Delay( 1000 );
    }

    /*--------------------------------------------------------------------
    Free SDL resources.
    --------------------------------------------------------------------*/
    SDL_DestroyTexture( texture );
    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
    SDL_Quit();

    /*--------------------------------------------------------------------
    Return to shell.
    --------------------------------------------------------------------*/
    return 0;
}

