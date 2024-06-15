#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <Pieza.hpp>
#include <time.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Campo : public sf::Drawable
{ // La clase Campo hereda de sf::Drawable para poder ser dibujada en una ventana de SFML
private:
    Piezas piezas;
    int indNewPieza, indColorNewPieza;
    sf::Color newPiezaColor;

    int indX,indY;

    int timer = 0;
    int limitTimer = 30;

    int tablero[20][10];                     // Matriz que representa el estado del tablero del juego. Cada celda puede tener un valor que representa un tipo de pieza.
    sf::RectangleShape formaTablero[20][10]; // Matriz de formas rectangulares que se utilizan para dibujar el tablero en la ventana de SFML.

public:
    Campo();
    bool InstalarPieza();
    bool ActTablero();
    void ActColoresTablero();                                      // Actualiza los colores de las celdas del tablero en función de los valores en la matriz 'tablero'.
    virtual void draw(sf::RenderTarget &, sf::RenderStates) const; // Se utiliza para dibujar el tablero en una ventana de SFML.
};

// Funciones

Campo::Campo()
{
    for (auto &row : tablero)
    {
        std::fill(std::begin(row), std::end(row), 0); // Inicializa todas las celdas de la matriz 'tablero' a 0
    }
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            formaTablero[i][j] = sf::RectangleShape(sf::Vector2f(20, 20)); // Crea una nueva forma rectangular de tamaño 20x20
            formaTablero[i][j].setPosition(j * 20, i * 20);                // Posiciona la forma en la ventana de SFML
            formaTablero[i][j].setFillColor(sf::Color(50, 50, 50, 255));   // Color de relleno inicial
            formaTablero[i][j].setOutlineThickness(2);                     // Grosor del borde
            formaTablero[i][j].setOutlineColor(sf::Color(0, 0, 0, 255));   // Color del borde
        }
    }

}

bool Campo::InstalarPieza()
{
    srand(time(NULL));
    indNewPieza = rand()%7;
    vector<vector<bool>> pieza = piezas.ConsultaPieza(indNewPieza);

    int tam = (int)pieza.size();
    indY = 0;
    indX = 5 - tam / 2;

    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            if (pieza[i][j])
            {
                if (tablero[i][j + indX] > 0) return false;
                    tablero[i][j + indX] = -1;
            }
        }
    }

    int color = 1 + rand()%7;
    indColorNewPieza = color;

    switch(color){
        case 0:
            newPiezaColor = sf::Color(50, 50, 50, 255); // Si el valor es 0, establece el color de relleno a gris oscuro
            break;
        case 1:
            newPiezaColor = sf::Color(255, 166, 0, 255);
            break;
        case 2:
            newPiezaColor = sf::Color(245, 152, 245, 255);
            break;
        case 3:
            newPiezaColor = sf::Color(51, 204, 153, 255);
            break;
        case 4:
            newPiezaColor = sf::Color(255, 110, 110, 255);
            break;
        case 5:
            newPiezaColor = sf::Color(255, 204, 77, 255);
            break;
        case 6:
            newPiezaColor = sf::Color(166, 166, 255, 255);
            break;
        case 7:
            newPiezaColor = sf::Color(138, 194, 247, 255);
            break;

        default:
            break;
            }
    return true;
}

bool Campo::ActTablero(){
    bool limit = 0;
    int aux;

    if(timer >= limitTimer){
        aux = 0;
        for(int i = 18; i >= 0; i--){
            for(int j = 0; j < 20; j++){
                if(tablero[i][j] == -1){
                    if(tablero[i +1][j] <= 0) aux++;
                }
            }
        }
        if (aux == 4){
            indY++;
            for(int i = 18; i >= 0; i--){
                for(int j = 0; j < 20; j++){
                    if(tablero[i][j] == -1){
                        tablero[i][j] = 0;
                        tablero[i+1][j] = -1;
                    }
                }
            }
            aux = 0;
            for(int i = 18; i >= 0; i--){
                for(int j = 0; j < 20; j++){
                    if(tablero[i][j] == -1){
                        if(tablero[i +1][j] <= 0) aux++;
                    }
                }
            }
            if (aux != 4){
                for(int i = 19; i >= 0; i--){
                    for(int j = 0; j < 20; j++){
                        if(tablero[i][j] == -1) tablero[i][j] = indColorNewPieza;
                    }        
                }
                limit = 1;
            }

        }else{
            limit = 1;
        }
        timer = 0;
    }
    timer++;
    return limit;
}

void Campo::ActColoresTablero()
{ // Actualiza los colores de las celdas del tablero
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            switch (tablero[i][j])
            {
            case 0:
                formaTablero[i][j].setFillColor(sf::Color(50, 50, 50, 255)); // Si el valor es 0, establece el color de relleno a gris oscuro
                break;
            case 1:
                formaTablero[i][j].setFillColor(sf::Color(255, 166, 0, 255));
                break;
            case 2:
                formaTablero[i][j].setFillColor(sf::Color(245, 152, 245, 255));
                break;
            case 3:
                formaTablero[i][j].setFillColor(sf::Color(51, 204, 153, 255));
                break;
            case 4:
                formaTablero[i][j].setFillColor(sf::Color(255, 110, 110, 255));
                break;
            case 5:
                formaTablero[i][j].setFillColor(sf::Color(255, 204, 77, 255));
                break;
            case 6:
                formaTablero[i][j].setFillColor(sf::Color(166, 166, 255, 255));
                break;
            case 7:
                formaTablero[i][j].setFillColor(sf::Color(138, 194, 247, 255));
                break;

            default:
                formaTablero[i][j].setFillColor(newPiezaColor);
                break;
            }
        }
    }
}

void Campo::draw(sf::RenderTarget &rt, sf::RenderStates rs) const
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            rt.draw(formaTablero[i][j], rs); // Dibuja cada forma en la ventana de SFML
        }
    }
}