#include "Rutas.h"

Rutas::Rutas()
{

}

void Rutas::llenarPuntos()
{
    puntos[0] = "sanPedro";
    puntos[1] = "ceiba";
    puntos[2] = "trujillo";
    puntos[3] = "yoro";
    puntos[4] = "olancho";
    puntos[5] = "tegus";
    puntos[6] = "elParaiso";
    puntos[7] = "choluteca";
    puntos[8] = "nacaome";
    puntos[9] = "comayagua";
    puntos[10] = "laEsperanza";
    puntos[11] = "gracias";
    puntos[12] = "santaBarbara";
    puntos[13] = "santaRosa";
    puntos[14] = "ocotepeque";
}

void Rutas::rutasPosibles()
{
    nuevaAdyacencia("sanPedro","santaRosa");
    nuevaAdyacencia("santaRosa","ocotepeque");
    nuevaAdyacencia("ceiba","sanPedro");
    nuevaAdyacencia("ceiba","olancho");
    nuevaAdyacencia("comayagua","laEsperanza");
    nuevaAdyacencia("comayagua","santaBarbara");
    nuevaAdyacencia("comayagua","yoro");
    nuevaAdyacencia("elParaiso","olancho");
    nuevaAdyacencia("elParaiso","choluteca");
    nuevaAdyacencia("gracias","laEsperanza");
    nuevaAdyacencia("nacaome","choluteca");
    nuevaAdyacencia("sanPedro","santaBarbara");
    nuevaAdyacencia("sanPedro","yoro");
    nuevaAdyacencia("santaBarbara","gracias");
    nuevaAdyacencia("santaRosa","gracias");
    nuevaAdyacencia("santaRosa","santaBarbara");
    nuevaAdyacencia("tegus","comayagua");
    nuevaAdyacencia("tegus","elParaiso");
    nuevaAdyacencia("tegus","nacaome");
    nuevaAdyacencia("tegus","olancho");
    nuevaAdyacencia("trujillo","ceiba");
    nuevaAdyacencia("yoro","ceiba");
    nuevaAdyacencia("yoro","olancho");
}

bool Rutas::existeCamino(char* nombre_punto1, char* nombre_punto2)
{
    bool visitados[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    visitados[obtenerPosicion(nombre_punto1)] = true;
    stack<int> siguiente;
    siguiente.push(obtenerPosicion(nombre_punto1));

    while(!siguiente.empty())
    {
        int actual = siguiente.top();
        siguiente.pop();

        for(int n = 0; n < 15; ++n)
        {
            if(!visitados[n] && adyacencieas[actual][n] == true)
            {
                visitados[n] = true;
                siguiente.push(n);
            }
        }
    }
    return visitados[obtenerPosicion(nombre_punto2)];
}

int Rutas::obtenerPosicion(char* nombre_punto)
{
    for(int n = 0; n < _size; n++)
    {
        if(utility->compareTo(puntos[n],nombre_punto))
        {
            return n;
        }
    }
    return -1;
}

void Rutas::setAdyacencias()
{
    for(int fila = 0; fila < _size; fila++)
    {
        for(int col = 0; col < _size; col++)
        {
            adyacencieas[fila][col] = false;
        }
    }
}

void Rutas::nuevaAdyacencia(char* nombre_punto1, char* nombre_punto2)
{
    adyacencieas[obtenerPosicion(nombre_punto1)][obtenerPosicion(nombre_punto2)] = true;
    adyacencieas[obtenerPosicion(nombre_punto2)][obtenerPosicion(nombre_punto1)] = true;
}

void Rutas::setCaminos()
{
    for(int fila = 0; fila < _size; fila++)
    {
        for(int col = 0; col < _size; col++)
        {
            caminos[fila][col] = false;
        }
    }
}

void Rutas::nuevoCamino(char* nombre_punto1, char* nombre_punto2)
{
    caminos[obtenerPosicion(nombre_punto1)][obtenerPosicion(nombre_punto2)] = true;
    caminos[obtenerPosicion(nombre_punto2)][obtenerPosicion(nombre_punto1)] = true;
}

bool Rutas::consultarCamino(char* nombre_punto1, char* nombre_punto2)
{
    if(caminos[obtenerPosicion(nombre_punto1)][obtenerPosicion(nombre_punto2)] &&
       caminos[obtenerPosicion(nombre_punto2)][obtenerPosicion(nombre_punto1)])
    {
        return true;
    }
    return false;
}

void Rutas::obtenerCaminosDirectos(char* nombre_punto1)
{
    int posicion = obtenerPosicion(nombre_punto1);

    for(int x = 0; x < _size; x++)
    {
        if(adyacencieas[posicion][x])
        {
            for(int n = 0; n < 5; n++)
            {
                if(caminoDirecto[n] == NULL)
                {
                    caminoDirecto[n] = obtenerPunto(x);
                    break;
                }
            }
        }
    }
}

char* Rutas::obtenerPunto(int posicion)
{
    for(int c = 0; c < _size; c++)
    {
        if(c == posicion)
        {
            return puntos[c];
        }
    }
}

void Rutas::reestablecerCaminosDirectos()
{
    for(int s = 0; s < 5; s++)
    {
        caminoDirecto[s] = NULL;
    }
}

Rutas::~Rutas()
{
    delete puntos;
    delete caminoDirecto;
    delete adyacencieas;
    delete caminos;
}
