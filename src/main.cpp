#include <iostream>
#include <thread>
#include <Juego.hpp>

int main(int argc, char const *argv[])
{
    Juego juego;

    // Game loop
    while (juego.Running()){ // Mientras la ventana este abierta

        // Update
        juego.actualizar();

        // Render
        juego.renderizar();


    }
    
    return 0;
}