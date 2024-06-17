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
    InterfazUsuario();
    void SetMaxScore(int);
    void SetScore(int);
    void GameOver();
    void NewScore();
    virtual void draw(sf::RenderTarget&,sf::RenderStates) const;
};

InterfazUsuario::InterfazUsuario(){
    if(!font.loadFromFile("assets/8-BIT WONDER.TTF")){
        cout << "Error Font Text" << endl;
    }
    scoreTextTitle.setFont(font);
    scoreTextTitle.setFillColor(sf::Color::White);
    scoreTextTitle.setPosition(Vector2f(235,25));
    scoreTextTitle.setString("Score");

    maxScoreTextTitle.setFont(font);
    maxScoreTextTitle.setFillColor(sf::Color::White);
    maxScoreTextTitle.setPosition(Vector2f(225,200));
    maxScoreTextTitle.setString("Max Score");
    maxScoreTextTitle.setCharacterSize(20);

    scoreText.setFont(font);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(Vector2f(250,70));

    maxScoreText.setFont(font);
    maxScoreText.setFillColor(sf::Color::White);
    maxScoreText.setPosition(Vector2f(265,245));

    textTETRIS.setFont(font);
    textTETRIS.setFillColor(sf::Color::White);
    textTETRIS.setPosition(Vector2f(260,370));
    textTETRIS.setString("TETRIS inc.");
    textTETRIS.setCharacterSize(20);

    gameOverText.setFont(font);
    gameOverText.setFillColor(sf::Color::White);
    gameOverText.setPosition(Vector2f(8,150));
    gameOverText.setString("Game Over");
    gameOverText.setCharacterSize(25);

    newScoreText.setFont(font);
    newScoreText.setFillColor(sf::Color::White);
    newScoreText.setPosition(Vector2f(8,150));
    newScoreText.setString("New Score");
    newScoreText.setCharacterSize(25);
}

void InterfazUsuario::SetScore(int x){
    if(x<=9) scoreText.setString("000" + to_string(x));
    else if(x<=99) scoreText.setString("00" + to_string(x));
    else if(x<=999) scoreText.setString("000" + to_string(x));
    else if(x<=9999) scoreText.setString(to_string(x));
    else scoreText.setString("9999");
}

void InterfazUsuario::SetMaxScore(int x){
    if(x<=9) maxScoreText.setString("000" + to_string(x));
    else if(x<=99) maxScoreText.setString("00" + to_string(x));
    else if(x<=999) maxScoreText.setString("000" + to_string(x));
    else if(x<=9999) maxScoreText.setString(to_string(x));
    else maxScoreText.setString("9999");
}

void InterfazUsuario::GameOver(){
    gameOver = 1;
}

void InterfazUsuario::NewScore(){
    newScore = 1;
}

void InterfazUsuario::draw(sf::RenderTarget &rt ,sf::RenderStates rs) const{
    rt.draw(scoreTextTitle,rs);
    rt.draw(scoreText,rs);
    rt.draw(maxScoreText,rs);
    rt.draw(scoreTextTitle,rs);
    rt.draw(textTETRIS,rs);
    if(gameOver)rt.draw(gameOverText,rs);
    if(newScore)rt.draw(newScoreText,rs);
}