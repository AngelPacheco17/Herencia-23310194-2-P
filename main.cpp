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
    virtual void descripcion() const {
        cout << "Este es un " << especie << " de color " << color << endl;
    }
    virtual ~Pez() {}
};

// Herencia primer nivel
class PezOceano : public Pez {
protected:
    string tipoAlimentacion;

public:
    PezOceano(string _especie, string _color, string _tipoAlimentacion) : Pez(_especie, _color), tipoAlimentacion(_tipoAlimentacion) {}
    void descripcion() const override {
        cout << "Este es un " << especie << " de color " << color << " y se alimenta de " << tipoAlimentacion << endl;
    }
};

// Herencia segundo nivel
class PezTropical : public PezOceano {
protected:
    bool aletasLuminosas;

public:
    PezTropical(string _especie, string _color, string _tipoAlimentacion, bool _aletasLuminosas)
        : PezOceano(_especie, _color, _tipoAlimentacion), aletasLuminosas(_aletasLuminosas) {}
    void descripcion() const override {
        cout << "Este es un " << especie << " del oceano tropical de color " << color << " y se alimenta de " << tipoAlimentacion;
        if (aletasLuminosas) {
            cout << ", tiene aletas luminosas";
        }
        cout << endl;
    }
};

int main() {
    Pez pezGenerico("pez", "gris");
    pezGenerico.descripcion();

    PezOceano pezAzul("pez azul", "azul", "plancton");
    pezAzul.descripcion();

    PezTropical pezMariposa("pez mariposa", "amarillo", "algas", true);
    pezMariposa.descripcion();

    return 0;
}
