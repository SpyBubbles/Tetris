#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class InterfazUsuario: public sf::Drawable {
    private:
        Font font; 
        Text scoreText;
        Text scoreTextTitle;
        Text maxScoreTextTitle;
        Text maxScoreText;
        Text gameOverText;
        Text textTETRIS;
        Text newScoreText;
        bool newScore = 0;
        bool gameOver = 0;
    
    public:
    InterfazUsuario(); //Constructor
    void setMaxScore(int); //Valor numerico de puntuacion maxima
    void setScore(int); //Valor numerico de puntuacion
    void gameOverFunction(); //Texto gam over 
    void newScoreFunction(); //Tecto new score
    virtual void draw(sf::RenderTarget&,sf::RenderStates) const;
};

InterfazUsuario::InterfazUsuario(){
    if(!font.loadFromFile("assets/8-BIT WONDER.TTF")){ //Tomar la tipografia para los textos
        cout << "Error Font Text" << endl;
    }
    scoreTextTitle.setFont(font);                       //Declaracion de los aspctos de el titulo de score
    scoreTextTitle.setFillColor(sf::Color::White);
    scoreTextTitle.setPosition(Vector2f(229,25));
    scoreTextTitle.setString("Score");

    maxScoreTextTitle.setFont(font);                    //Declaracion de los aspctos de el titulo de maxima score
    maxScoreTextTitle.setFillColor(sf::Color::White);
    maxScoreTextTitle.setPosition(Vector2f(212,150));
    maxScoreTextTitle.setString("Max Score");
    maxScoreTextTitle.setCharacterSize(20);

    scoreText.setFont(font);                            //Declaracion de los aspctos de score
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(Vector2f(245,70));

    maxScoreText.setFont(font);                         //Declaracion de los aspctos de la max score
    maxScoreText.setFillColor(sf::Color::White);
    maxScoreText.setPosition(Vector2f(245,185));

    textTETRIS.setFont(font);                           //Declaracion de los aspctos de tetris
    textTETRIS.setFillColor(sf::Color::White);
    textTETRIS.setPosition(Vector2f(275,370));
    textTETRIS.setString("TETRIS");
    textTETRIS.setCharacterSize(10);

    gameOverText.setFont(font);                         //Declaracion de los aspctos de el titulo de game over
    gameOverText.setFillColor(sf::Color::White);
    gameOverText.setPosition(Vector2f(10,150));
    gameOverText.setString("Game Over");
    gameOverText.setCharacterSize(20);

    newScoreText.setFont(font);                         //Declaracion de los aspctos de el tituo de new score
    newScoreText.setFillColor(sf::Color::White);
    newScoreText.setPosition(Vector2f(10,180));
    newScoreText.setString("New Score");
    newScoreText.setCharacterSize(20);
}

void InterfazUsuario::setScore(int x){                  //Funcionalidad de el valor numerico de la puntuacion
    if(x<=9) scoreText.setString("000" + to_string(x));
    else if(x<=99) scoreText.setString("00" + to_string(x));
    else if(x<=999) scoreText.setString("000" + to_string(x));
    else if(x<=9999) scoreText.setString(to_string(x));
    else scoreText.setString("9999");
}

void InterfazUsuario::setMaxScore(int x){               //Declaracion de el valor numerico de la puntuacion maxima
    if(x<=9) maxScoreText.setString("000" + to_string(x));
    else if(x<=99) maxScoreText.setString("00" + to_string(x));
    else if(x<=999) maxScoreText.setString("000" + to_string(x));
    else if(x<=9999) maxScoreText.setString(to_string(x));
    else maxScoreText.setString("9999");
}

void InterfazUsuario::gameOverFunction(){   //Retornar 1 si es game over
    gameOver = 1;
}

void InterfazUsuario::newScoreFunction(){   //Retornar 1 si es new score
    newScore = 1;
}

void InterfazUsuario::draw(sf::RenderTarget &rt ,sf::RenderStates rs) const{ //Dibujar en la pantalla los textos
    rt.draw(scoreTextTitle,rs);
    rt.draw(scoreText,rs);
    rt.draw(maxScoreText,rs);
    rt.draw(maxScoreTextTitle,rs);
    rt.draw(textTETRIS,rs);
    if(gameOver)rt.draw(gameOverText,rs);
    if(newScore)rt.draw(newScoreText,rs);
}