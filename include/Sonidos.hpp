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
        void PlayMusic();
        void PauseMusic();
        void PlayLine();
        void PlayGameOver();
        void PlayNewScore();
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

void Sonido::PlayMusic(){
    musica.play();
}

void Sonido::PauseMusic(){
    musica.pause();
}

void Sonido::PlayLine(){
    lineaSonido.play();
}

void Sonido::PlayNewScore(){
    nuevoRecordSonido.play();
}
void Sonido::PlayGameOver(){
    gameOverSonido.play();
}