#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <Campo.hpp>

class Juego
{
    private:
    // Variables
    Campo campo;

    // Ventana
    sf::RenderWindow* window;
    int heigt = 400;
    int width = 400;
    sf::Event ev;
    int right;
    int left;

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
    this->window = new sf::RenderWindow(sf::VideoMode(this->width,this->heigt),"TETRIS",sf::Style::Titlebar | sf::Style::Close );
    this->window->setFramerateLimit(60); // Sin este ajuste, las piezas bajan extremadamente rápido
    campo.InstalarPieza();
    this->right = 0;
    this->left = 0;
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
            default:
            break;
        }
    }
}

void Juego::actualizar(){
    this->pollEventos();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) campo.ActLimitTimer(5);
    else{
        campo.ActLimitTimer(30);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&!right){
        campo.Right();
        right = 1;
    }else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        right = 0;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&right){
        right++;
        if (right == 6) right = 0;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&!left){
        campo.Left();
        left = 1;
    }else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        left = 0;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&left){
        left++;
        if (left == 6) left = 0;
    }

    if(campo.ActTablero()){
        if(!campo.InstalarPieza()){
            cout << "Game Over" << endl;
            this->window->close();
        }
    }
    campo.ActColoresTablero();
}

void Juego::renderizar(){
    /*
        @return void
        Renderiza los objetos del juego.
    */
    this->window->clear(sf::Color(20, 20, 20, 255)); // Modifica el color de fondo de la mitad derecha
    
    this->window->draw(campo);
    // Dibujar los objetos del Juego
    this->window->display();
}