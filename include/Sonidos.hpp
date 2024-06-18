#include <iostream>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

class Sonidos{
    private:
        Music musica;
        Sound lineaSonido;
        Sound nuevoRecordSonido;
        Sound gameOverSonido;
        SoundBuffer lineaBuffer;
        SoundBuffer nuevoRecordBuffer;
        SoundBuffer gameOverBuffer;
    public:
        Sonidos();
        void PlayMusic();
        void PauseMusic();
        void PlayLine();
        void PlayGameOver();
        void PlayNewScore();
};

Sonidos::Sonidos(){
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

void Sonidos::PlayMusic(){
    musica.play();
}

void Sonidos::PauseMusic(){
    musica.pause();
}

void Sonidos::PlayLine(){
    lineaSonido.play();
}

void Sonidos::PlayNewScore(){
    nuevoRecordSonido.play();
}
void Sonidos::PlayGameOver(){
    gameOverSonido.play();
}