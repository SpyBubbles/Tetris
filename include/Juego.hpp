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
    sf::VideoMode videoMode;
    sf::Event ev;

    void iniciaVariables();
    void iniciaVentana();
    public:
    Juego();
    virtual ~Juego();

    // Acceder
    const bool running() const;

    // Funciones
    void pollEventos();
    void actualizar();
    void renderizar();
};