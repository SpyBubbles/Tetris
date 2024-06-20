#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <Campo.hpp>
#include <fstream>
#include <InterfazUsuario.hpp>
#include <Sonidos.hpp>

class Juego
{
private:
    // Variables
    Campo campo;
    InterfazUsuario interfazUsuario;
    Sonido sonido;

    // Ventana
    sf::RenderWindow *window;
    int heigt = 400; //Medidas de la ventana
    int width = 400;
    sf::Event ev;
    int right;
    int left;
    int up;
    int score = 0;
    int maxScore = 0;
    bool vida = 1;

    void iniciarVariables();
    void iniciarVentana();

public:
    Juego();
    virtual ~Juego();

    // Acceder
    const bool Running() const;

    // Funciones
    void PollEventos();
    void Actualizar();
    void Renderizar();
};

// Funciones privadas
void Juego::iniciarVariables()
{
    this->window = nullptr;
    ifstream in("assets/maxScore/maxScore.txt"); //Recibir el max score del txt
    in >> maxScore; 
    interfazUsuario.SetMaxScore(maxScore); 
    interfazUsuario.SetScore(score); 
}; 

void Juego::iniciarVentana()
{
    this->window = new sf::RenderWindow(sf::VideoMode(this->width, this->heigt), "TETRIS", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60); // Sin este ajuste, las piezas bajan extremadamente rápido
    campo.InstalarPieza(); //Ingresar las piezas al campo
    this->right = 0;
    this->left = 0;
}

// Constructor y Destructor
Juego::Juego()
{
    this->iniciarVariables();
    this->iniciarVentana();
    sonido.PlayMusic(); //Hacer que suene la musica del juego 
}

Juego::~Juego()
{
    delete this->window;
}

// Acceder
const bool Juego::Running() const
{
    return this->window->isOpen();
}

// Funciones

void Juego::PollEventos()
{

    // Event polling
    while (this->window->pollEvent(this->ev))
    { // Mientras existan eventos
        switch (this->ev.type)
        { // Clasificar los tipos de eventos que pueden ocurrir

        case sf::Event::Closed:
            this->window->close();
            break;

        case sf::Event::KeyPressed: // Al presionar la tecla "Escape" cerrar la ventana
            if (this->ev.key.code == sf::Keyboard::Escape)
            {
                this->window->close();
            }
            break;
            default:
            break;
        }
    }
}

void Juego::Actualizar()
{
    this->PollEventos();

    if (vida) //Mientras se tenga vida
    { 

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !up) //Si se presiona tecla up se rota la pieza
            campo.RotarPieza(), up = 1;
        else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            up = 0;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) //Si se presiona down baja la pieza
            campo.ActLimitTimer(5); //Velocidad de la tecla down
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) //Si se presiona espacio se hace "Hard drop"
        {
            campo.ActLimitTimer(1); //Velocidad de la pieza presionando space
        } else {
            campo.ActLimitTimer(30); //Velocidad a la que baja normalmente
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !right) //Se mueve a la derecha la pieza
        {
            campo.Right();
            right = 1;
        }
        else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            right = 0;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && right)
        {
            right++;
            if (right == 6)
                right = 0;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !left) //Se mueve a izquierda la pieza
        {
            campo.Left();
            left = 1;
        }
        else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            left = 0;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && left)
        {
            left++;
            if (left == 6)
                left = 0;
        }

        if (campo.ActTablero()) //Si tablero es true
        {
            if (!campo.InstalarPieza()) //Si ya no pueden agreegarse piezas
            {
                vida = 0;
                this->window->clear();
                sonido.PauseMusic(); //Se pausa la musica del juego
                if (score > maxScore) //En caso de que la socre sea mayor a la maxima score
                {
                    interfazUsuario.NewScoreFunction(); 
                    ofstream out("assets/maxScore/maxScore.txt"); //Se guarda la nueva max score
                    out << score;
                    sonido.PlayNewScore(); //Sonido en caso de una nueva max score
                }
                else
                {
                    interfazUsuario.GameOverFunction();
                    sonido.PlayGameOver(); //Musica de game over
                }
            }
        }
        campo.ActColoresTablero();
        int newScore = campo.Linea() * 1; //Agregar a la socre cada vez que se haga una linea
        score += newScore;
        interfazUsuario.SetScore(score);
        if(newScore > 0) sonido.PlayLine();
    }
}

void Juego::Renderizar()
{
    /*
        @return void
        Renderiza los objetos del juego.
    */
    this->window->clear(sf::Color(20, 20, 20, 255)); // Modifica el color de fondo de la mitad derecha

    this->window->draw(campo);
    // Dibujar los objetos del Juego
    this->window->draw(interfazUsuario);
    this->window->display();
}