#include <iostream>
#include <vector>

using namespace std;

class Pieza
{
private:
    vector<vector<vector<bool>>> pieza;

public:
    Pieza();
    vector<vector<bool>> consultarPieza(int ind);
    void RotarPieza(int ind);    // Rotar pieza
    void DesrotarPieza(int ind); // En caso de que no pueda rotar

};

Pieza::Pieza()
{
    pieza = {{{1, 1},
              {1, 1}}, // Cuadrado

             {{0, 0, 0, 0, 0}, // S
              {0, 0, 1, 0, 0},
              {0, 0, 1, 1, 0},
              {0, 0, 0, 1, 0},
              {0, 0, 0, 0, 0}},

             {{0, 0, 0, 0, 0}, // Z
              {0, 0, 0, 1, 0},
              {0, 0, 1, 1, 0},
              {0, 0, 1, 0, 0},
              {0, 0, 0, 0, 0}},

             {{0, 0, 0, 0, 0}, // J
              {0, 0, 1, 1, 0},
              {0, 0, 1, 0, 0},
              {0, 0, 1, 0, 0},
              {0, 0, 0, 0, 0}},

             {{0, 0, 0, 0, 0}, // L
              {0, 1, 1, 0, 0},
              {0, 0, 1, 0, 0},
              {0, 0, 1, 0, 0},
              {0, 0, 0, 0, 0}},

             {{0, 0, 0, 0, 0}, // T
              {0, 0, 1, 0, 0},
              {0, 0, 1, 1, 0},
              {0, 0, 1, 0, 0},
              {0, 0, 0, 0, 0}},

             {{0, 0, 0, 1, 0}, // I
              {0, 0, 0, 1, 0},
              {0, 0, 0, 1, 0},
              {0, 0, 0, 1, 0},
              {0, 0, 0, 0, 0}}};
}

vector<vector<bool>> Pieza::consultarPieza(int ind)
{
    return pieza[ind]; //Retorna una pieza
}

void Pieza::RotarPieza(int ind)
{
    vector<vector<bool>> vAux = pieza[ind]; // replica de pieza
    int indI = 0;
    int indJ = 0;
    int tam = (int)pieza[ind].size();
    for (int i = 0; i < tam; i++)
    {
        for (int j = tam-1; j >= 0; j--)
        {
            pieza[ind][indI][indJ] = vAux[j][i];
            indJ++;
        }
        indI++;
        indJ = 0;
    }
}
void Pieza::DesrotarPieza(int ind) //En caso de que una pieza no se pueda rotar por su posicion
{
    vector<vector<bool>> vAux = pieza[ind];
    int indI = 0;
    int indJ = 0;
    int tam = (int)pieza[ind].size();
    for (int i = tam - 1; i >= 0; i--)
    {
        for (int j = 0; i < tam; j++)
        {
            pieza[ind][indI][indJ] = vAux[j][i];
            indJ++;
        }
        indI++;
        indJ = 0;
    }
}