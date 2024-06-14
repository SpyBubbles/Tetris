#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Juego
{
    private:
    // Variables


    // Ventana
    sf::RenderWindow* window;
    int heigt = 0;
    int width = 0;
    sf::Event ev;

    void iniciaVariables();
    void iniciaVentana();
    public:
    Juego();
    virtual ~Juego();

    // Acceder
    const bool Running() const;

    // Funciones
    void pollEventos();
    void actualizar();
    void renderizar();
};

// Funciones privadas
void Juego::iniciaVariables(){
 this->window = nullptr;
};

void Juego::iniciaVentana(){
    this->width = sf::VideoMode::getDesktopMode().width;
    this->heigt = sf::VideoMode::getDesktopMode().height;
    this->window = new sf::RenderWindow(sf::VideoMode(this->width,this->heigt),"TETRIS",sf::Style::Titlebar | sf::Style::Close);
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
const bool Juego::Running() const{
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

    this->window->clear(sf::Color(105, 55, 100, 255));

    // Dibujar los objetos del Juego

    this->window->display();
}