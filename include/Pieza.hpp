#include <iostream>
#include <vector>

using namespace std;

class Pieza
{
private:
    vector<vector<vector<bool>>> pieza;

public:
    Pieza();
    vector<vector<bool>> ConsultaPieza(int ind);
    void RotarPz(int ind);    // rotar pieza
    void DesrotarPz(int ind); // En caso de que no pueda rotar

}

Pieza::Pieza()
{
    pieza = {{{1, 1},
              {1, 1}}, // Cuadrado

             {{0, 0, 0, 0, 0}, // S
              {0, 0, 1, 1, 0},
              {0, 1, 1, 0, 0},
              {0, 0, 0, 0, 0},
              {0, 0, 0, 0, 0}},

             {{0, 0, 0, 0, 0}, // Z
              {0, 1, 1, 0, 0},
              {0, 0, 1, 1, 0},
              {0, 0, 0, 0, 0},
              {0, 0, 0, 0, 0}},

             {{0, 0, 0, 0, 0}, // J
              {0, 0, 0, 0, 0},
              {0, 1, 1, 1, 0},
              {0, 0, 0, 1, 0},
              {0, 0, 0, 0, 0}},

             {{0, 0, 0, 0, 0}, // L
              {0, 0, 0, 0, 0},
              {0, 1, 1, 1, 0},
              {0, 1, 0, 0, 0},
              {0, 0, 0, 0, 0}},

             {{0, 0, 0, 0, 0}, // T
              {0, 0, 0, 0, 0},
              {0, 1, 1, 1, 0},
              {0, 0, 1, 0, 0},
              {0, 0, 0, 0, 0}},

             {{0, 0, 0, 1, 0}, // I
              {0, 0, 0, 1, 0},
              {0, 0, 0, 1, 0},
              {0, 0, 0, 1, 0},
              {0, 0, 0, 0, 0}}};
}

vector<vector<bool>> Pieza::ConsultaPieza(int ind)
{
    return pieza[ind];
}

void Pieza::RotarPz(int ind)
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
void Pieza::DesrotarPz(int ind)
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