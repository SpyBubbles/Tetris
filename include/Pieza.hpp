#include <iostream>
#include <vector>

using namespace std;

class Piezas
{
private:
    vector<vector<vector<bool>>> piezas;

public:
    Piezas();
    vector<vector<bool>> ConsultaPieza(int ind);
    void RotarPz(int ind);    // Rotar pieza
    void DesrotarPz(int ind); // En caso de que no pueda rotar

};

Piezas::Piezas()
{
    piezas = {{{1, 1},
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

vector<vector<bool>> Piezas::ConsultaPieza(int ind)
{
    return piezas[ind];
}

void Piezas::RotarPz(int ind)
{
    vector<vector<bool>> vAux = piezas[ind]; // replica de pieza
    int indI = 0;
    int indJ = 0;
    int tam = (int)piezas[ind].size();
    for (int i = 0; i < tam; i++)
    {
        for (int j = tam-1; j >= 0; j--)
        {
            piezas[ind][indI][indJ] = vAux[j][i];
            indJ++;
        }
        indI++;
        indJ = 0;
    }
}
void Piezas::DesrotarPz(int ind)
{
    vector<vector<bool>> vAux = piezas[ind];
    int indI = 0;
    int indJ = 0;
    int tam = (int)piezas[ind].size();
    for (int i = tam - 1; i >= 0; i--)
    {
        for (int j = 0; i < tam; j++)
        {
            piezas[ind][indI][indJ] = vAux[j][i];
            indJ++;
        }
        indI++;
        indJ = 0;
    }
}