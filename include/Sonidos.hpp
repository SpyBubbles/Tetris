#include <iostream>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

class Sonido{
    private:
        Music musica;
        Sound lineaSonido;
        Sound nuevoRecordSonido;
        Sound gameOverSonido;
        SoundBuffer lineaBuffer;
        SoundBuffer nuevoRecordBuffer;
        SoundBuffer gameOverBuffer;
    public:
        Sonido();
        void playMusic();
        void pauseMusic();
        void playLine();
        void playGameOver();
        void playNewScore();
};

Sonido::Sonido(){
    // Asegúrate de que la ruta relativa a los archivos .ogg sea correcta
    musica.openFromFile("assets/musica/music.ogg");
    musica.setLoop(true);
    musica.setVolume(20);

    if(!lineaBuffer.loadFromFile("assets/musica/line.ogg")){
        cout<<"Error al cargar sonido"<<endl;
    }

    if(!nuevoRecordBuffer.loadFromFile("assets/musica/newScore.ogg")){
        cout<<"Error al cargar sonido"<<endl;
    }

    if(!gameOverBuffer.loadFromFile("assets/musica/gameOver.ogg")){
        cout<<"Error al cargar sonido"<<endl;
    }

    lineaSonido.setBuffer(lineaBuffer);
    nuevoRecordSonido.setBuffer(nuevoRecordBuffer);
    gameOverSonido.setBuffer(gameOverBuffer);
}

void Sonido::playMusic(){
    musica.play();
}

void Sonido::pauseMusic(){
    musica.pause();
}

void Sonido::playLine(){
    lineaSonido.play();
}

void Sonido::playNewScore(){
    nuevoRecordSonido.play();
}
void Sonido::playGameOver(){
    gameOverSonido.play();
}