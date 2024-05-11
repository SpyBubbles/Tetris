#include <ftxui/dom/elements.hpp>   // for filler, text, hbox, vbox
#include <ftxui/screen/screen.hpp>  // for Full, Screen
#include <ftxui/dom/node.hpp>       // for Render
#include <ftxui/screen/color.hpp>   // for ftxui
#include <stdio.h>                  // for getchar
#include <iostream>
#include <string>
#include <thread>
#include <list>
#include <fstream>
#include <experimental/random>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    list<string> textos;
    fstream imagen;
    //imagen.open("./assets/Cubo/C.txt");
    imagen.open("./assets/Linea/l2.txt");
    //imagen.open("./assets/Linea/l1.txt");
    //imagen.open("./assets/L/L1.txt");

    string linea;
    while (getline(imagen,linea))
    {
        textos.push_back(linea);
    }
    imagen.close();

    int fotograma = 0;
    string reset;
    int AltoLimite = 20;
    int AnchoLimite = 24;
    int posX = 0; //18 Limite de altura
    int posY = 1;    //limite Izquierda Cubo
    //int posY = 20;  //limite Derecha depende de la pieza

    while (true){
    //fotograma++;
    //Element personaje = spinner(21,fotograma);  
    Decorator colorFondo = bgcolor(Color::GreenYellow);
    Decorator colorTexto = color(Color::Black);
    Element dibujo = border ({
        hbox() | colorFondo | colorTexto 
    });

    Dimensions Alto = Dimension::Fixed(AltoLimite);
    Dimensions Ancho = Dimension::Fixed(AnchoLimite);

    Screen pantalla = Screen::Create(Ancho,Alto);
    Render (pantalla,dibujo);

    int l = 0;
    for (auto &&texto : textos)
    {
        int i = 0;
        for (auto &&letra : texto)
        {
            pantalla.PixelAt(posY + i, posX + l).character = letra;
            i++;
        }
        l++;
    }
    posX++;
    posY = posY + 2;

    if (posX >= AltoLimite-2)
    {
        posX=0;
    }

    if (posY >= AnchoLimite-8)
    {
        posY=1;
    }

    Render(pantalla,dibujo);
    pantalla.Print();
        reset = pantalla.ResetPosition();
    cout << reset;
    this_thread::sleep_for(0.6s);
    }
    return 0;
    /*
  auto cell = [](const char* t) { return text(t) | border; };
  auto document =  //
      gridbox({
          {
              
              
              cell("SCORE"),
          },
          {
              //
              gridbox({
                  {
                      //
                      
                  },
                  {
                      cell("LEVEL"),
                      
                  },
              }),
              //
          },
          {
              cell("LINES"),
          },
      });
  auto screen = Screen::Create(Dimension::Fit(document));
  Render(screen, document);
  screen.Print();
  getchar();
  */
}