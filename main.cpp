//Jose Angel Pacheco Cervantes

#include <iostream>
#include <string>
using namespace std;

// Clase principal
class Pez {
protected:
    string especie;
    string color;

public:
    Pez(string _especie, string _color) : especie(_especie), color(_color) {}
    virtual void nadar() const {
        cout << "Nadando como un pez genérico" << endl;
    }
    virtual ~Pez() {}
};

// Herencia primer nivel
class PezOceano : public Pez {
protected:
    string tipoAlimentacion;

public:
    PezOceano(string _especie, string _color, string _tipoAlimentacion) : Pez(_especie, _color), tipoAlimentacion(_tipoAlimentacion) {}
    void nadar() const override {
        cout << "Nadando en el océano como un " << especie << " de color " << color << " y se alimenta de " << tipoAlimentacion << endl;
    }
};

// Herencia segundo nivel
class PezTropical : public PezOceano {
protected:
    bool aletasLuminosas;

public:
    PezTropical(string _especie, string _color, string _tipoAlimentacion, bool _aletasLuminosas)
        : PezOceano(_especie, _color, _tipoAlimentacion), aletasLuminosas(_aletasLuminosas) {}
    void nadar() const override {
        cout << "Nadando en el océano tropical como un " << especie << " de color " << color << " y se alimenta de " << tipoAlimentacion;
        if (aletasLuminosas) {
            cout << " con aletas luminosas";
        }
        cout << endl;
    }
};

int main() {
    Pez pezGenerico("Pez", "Gris");
    pezGenerico.nadar();

    PezOceano pezAzul("Pez Azul", "Azul", "Plancton");
    pezAzul.nadar();

    PezTropical pezMariposa("Pez Mariposa", "Amarillo", "Algas", true);
    pezMariposa.nadar();

    return 0;
}
