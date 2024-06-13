#include <iostream>
#include <thread>
#include "Juego.hpp"
/*#include <stdio.h>                  // for getchar
#include <iostream>
#include <string>
#include <thread>
#include <list>
#include <fstream>
#include <experimental/random>*/

int main() //int argc, char const *argv[]
{
    Juego juego;

    // Game loop
    while (juego.running()){ // Mientras la ventana este abierta

        // Update
        juego.actualizar();


        // Render
        juego.renderizar();


    }
    
    return 0;
}