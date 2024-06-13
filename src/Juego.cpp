#include "Juego.hpp"

// Funciones privadas
void Juego::iniciaVariables(){
 this->window = nullptr;
}

void Juego::iniciaVentana(){
    //this->videoMode.height = 620;
    //this->videoMode.width = 320;
    this->videoMode.getDesktopMode;
    this->window = new sf::RenderWindow (this->videoMode,"TETRIS",sf::Style::Titlebar | sf::Style::Close);
}

// Constructor y Destructor
Juego::Juego(){
    this->iniciaVariables();
    this->iniciaVentana();
}

Juego::~Juego(){
    delete this->window;
}

// Acceder
const bool Juego::running() const{
    return this->window->isOpen();
}

// Funciones

void Juego::pollEventos(){

    // Event polling
    while (this->window->pollEvent(this->ev)){ // Mientras existan eventos
        switch (this->ev.type){ // Clasificar los tipos de eventos que pueden ocurrir
               
            case sf::Event::Closed: 
                this->window->close();
            break; 

            case sf::Event::KeyPressed: // Al presionar la tecla "Escape" cerrar la ventana
                    if (this->ev.key.code == sf::Keyboard::Escape){
                    this->window->close();
                }
            break;
        }
    }
}

void Juego::actualizar(){
    this->pollEventos();
}

void Juego::renderizar(){
    /*
        @return void
        Renderiza los objetos del juego.
    */

    this->window->clear(sf::Color(255, 0, 0, 255));

    // Dibujar los objetos del Juego

    this->window->display();
}
