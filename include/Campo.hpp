#pragma once
#include <fstream>
#include <string>
#include <vector>

class Campo {
private:
    int x;
    int y;
    std::ifstream archivo;
    std::vector<std::string> shape;

public:
    Campo(int x, int y, std::string recurso);
    Campo(std::string recurso);

    void Mover(int x, int y);
    void AvanzarX(int x);
    void RetrocederX(int x);
    void Dibujar();

    int getX() const;
    int getY() const;
    const std::vector<std::string>& getShape() const;

    ~Campo();
};