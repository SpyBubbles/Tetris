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
    void ActColoresTablero();                                       // Actualiza los colores de las celdas del tablero en función de los valores en la matriz 'tablero'.
    void ActLimitTimer(int l); 
    void RotarPieza();
    void Right();
    void Left();
    virtual void draw(sf::RenderTarget &, sf::RenderStates) const; // Se utiliza para dibujar el tablero en una ventana de SFML.
    int Linea();
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
    srand(time(NULL)); //Inicializa para generar un numero aleatorio
    indNewPieza = rand()%7; //Genera un numero aleaotrio
    vector<vector<bool>> pieza = piezas.ConsultaPieza(indNewPieza); //Elige una pieza

    int tam = (int)pieza.size();
    indY = 0; //Agregamos puntos iniciales donde queremos que se genere la pieza
    indX = 5 - tam / 2;

    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            if (pieza[i][j])
            {
                if (tablero[i][j + indX] > 0) return false; //NO s epuede instala mas piezas en el campo
                    tablero[i][j + indX] = -1;
            }
        }
    }

    int color = 1 + rand()%7; //Se selecciona una valor al azar para dar color a la pieza
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
    int aux; //Cuantas celdas estan vacias por debajo para poner piezas

    if(timer >= limitTimer){
        aux = 0;
        for(int i = 18; i >= 0; i--){
            for(int j = 0; j < 10; j++){
                if(tablero[i][j] == -1){
                    if(tablero[i +1][j] <= 0) aux++;
                }
            }
        }
        if (aux == 4){ //Si son 4 celdas las que estan vacias se puede poner la pieza
            indY++;
            for(int i = 18; i >= 0; i--){
                for(int j = 0; j < 10; j++){
                    if(tablero[i][j] == -1){
                        tablero[i][j] = 0;
                        tablero[i+1][j] = -1;
                    }
                }
            }
        }else{
            for(int i = 19; i >= 0; i--){
                for(int j = 0; j < 10; j++){
                    if(tablero[i][j] == -1) tablero[i][j] = indColorNewPieza;
                }        
            }
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

void Campo::ActLimitTimer(int l){
    limitTimer = l;
}

void Campo::RotarPieza(){ //Rotar pieza
    piezas.RotarPz(indNewPieza);
    vector<vector<bool>> pieza = piezas.ConsultaPieza(indNewPieza);
    int tam = (int)pieza.size();
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(pieza[i][j]){
                if(indY + i < 0 || indY + i >= 20 || indX + j < 0 || indX + j >= 10 || tablero[indY+1][indX+j] > 0){
                    piezas.DesrotarPz(indNewPieza); //Rotacion imposible
                    return;
                }
            }
        }
    }

    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 10; j++){
            if(tablero[i][j] == -1) tablero[i][j] = 0;
        }
    }

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(pieza[i][j]){
                tablero[i+indY][j+indX] = -1;
            }
        }
    }
}

void Campo::Right(){ //Mover a la izquierda la pieza
    int aux = 0;
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 10; j++){
            if(tablero[i][j] == -1){
                if( j < 9 && tablero[i][j+1] <= 0){
                    aux++;
                }
            }
        }
    }
    if (aux == 4){ //Si tiene espacio para maniobrar
        indX++;
        for(int i = 0; i < 20; i++){
            for(int j = 9; j >= 0; j--){
                if(tablero[i][j] == -1) tablero[i][j] = 0, tablero[i][j+1] = -1;
            }
        }        
    }
}

void Campo::Left(){ //Mover a la derecha la pieza
    int aux = 0;
    for(int i = 0; i < 20; i++){
        for(int j = 1; j < 10; j++){
            if(tablero[i][j] == -1){
                if(tablero[i][j-1] <= 0){
                    aux++;
                }
            }
        }
    }
    if (aux == 4){ //Si tiene espacio para maniobrar
        indX--;
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 10; j++){
                if(tablero[i][j] == -1) tablero[i][j] = 0, tablero[i][j-1] = -1;
            }
        }        
    }
}

int Campo::Linea(){ //Funcion para llevar a cabo la deteccion y eliminacion de una linea
    int aux = 0;
    int lineas = 0;

    for(int i = 19; i >= 0; i--){
        aux = 0;
        for(int j = 0; j < 10; j++){
            if(tablero[i][j] > 0) aux++;
            if(lineas > 0) tablero[i+lineas][j] = tablero[i][j],tablero[i][j] = 0;
        }
        if(aux == 10){
            for(int j = 0;j < 10; j++) tablero[i][j] = 0;
            lineas++;
        }
    }
    return lineas;
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