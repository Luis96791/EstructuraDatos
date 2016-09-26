#include "Rutas.h"

Rutas::Rutas()
{

}

void Rutas::llenarPuntos()
{
    puntos[0] = "San Pedro";
    puntos[1] = "Ceiba";
    puntos[2] = "Trujillo";
    puntos[3] = "Yoro";
    puntos[4] = "Olancho";
    puntos[5] = "Tegucigalpa";
    puntos[6] = "El Paraiso";
    puntos[7] = "Choluteca";
    puntos[8] = "Nacaome";
    puntos[9] = "Comayagua";
    puntos[10] = "La Esperanza";
    puntos[11] = "Gracias";
    puntos[12] = "Santa Barbara";
    puntos[13] = "Santa Rosa";
    puntos[14] = "Ocotepeque";
}

void Rutas::rutasPosibles()
{
    nuevaAdyacencia("San Pedro","Santa Rosa");
    nuevaAdyacencia("Santa Rosa","Ocotepeque");
    nuevaAdyacencia("Ceiba","San Pedro");
    nuevaAdyacencia("Ceiba","Olancho");
    nuevaAdyacencia("Comayagua","La Esperanza");
    nuevaAdyacencia("Comayagua","Santa Barbara");
    nuevaAdyacencia("Comayagua","Yoro");
    nuevaAdyacencia("El Paraiso","Olancho");
    nuevaAdyacencia("El Paraiso","Choluteca");
    nuevaAdyacencia("Gracias","La Esperanza");
    nuevaAdyacencia("Nacaome","Choluteca");
    nuevaAdyacencia("San Pedro","Santa Barbara");
    nuevaAdyacencia("San Pedro","Yoro");
    nuevaAdyacencia("Santa Barbara","Gracias");
    nuevaAdyacencia("Santa Rosa","Gracias");
    nuevaAdyacencia("Santa Rosa","Santa Barbara");
    nuevaAdyacencia("Tegucigalpa","Comayagua");
    nuevaAdyacencia("Tegucigalpa","El Paraiso");
    nuevaAdyacencia("Tegucigalpa","Nacaome");
    nuevaAdyacencia("Tegucigalpa","Olancho");
    nuevaAdyacencia("Trujillo","Ceiba");
    nuevaAdyacencia("Yoro","Ceiba");
    nuevaAdyacencia("Yoro","Olancho");
}

bool Rutas::existeCamino(char* nombre_punto1, char* nombre_punto2)
{
    bool visitados[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    if(obtenerPosicion(nombre_punto1) == -1 || obtenerPosicion(nombre_punto2) == -1)
    {
        return false;
    }

    visitados[obtenerPosicion(nombre_punto1)] = true;
    stack<int> siguiente;
    siguiente.push(obtenerPosicion(nombre_punto1));

    while(!siguiente.empty())
    {
        int actual = siguiente.top();
        siguiente.pop();
        for(int n = 0; n < 15; ++n)
        {
            if(!visitados[n] && caminos[actual][n] == true)
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

void Rutas::setPesos()
{
    for(int f = 0; f < _size; f++)
    {
        for(int c = 0; c < _size; c++)
        {
            pesos[f][c] = 9999;
        }
    }
}

void Rutas::agregarPeso(char* nombre_punto1, char* nombre_punto2, int peso)
{
    if(adyacencieas[obtenerPosicion(nombre_punto1)][obtenerPosicion(nombre_punto2)] &&
       adyacencieas[obtenerPosicion(nombre_punto2)][obtenerPosicion(nombre_punto1)])
    {
        pesos[obtenerPosicion(nombre_punto1)][obtenerPosicion(nombre_punto2)] = peso;
        pesos[obtenerPosicion(nombre_punto2)][obtenerPosicion(nombre_punto1)] = peso;
    }
}

void Rutas::nuevoCamino(char* nombre_punto1, char* nombre_punto2)
{
    if(adyacencieas[obtenerPosicion(nombre_punto1)][obtenerPosicion(nombre_punto2)] &&
       adyacencieas[obtenerPosicion(nombre_punto2)][obtenerPosicion(nombre_punto1)])
    {
        caminos[obtenerPosicion(nombre_punto1)][obtenerPosicion(nombre_punto2)] = true;
        caminos[obtenerPosicion(nombre_punto2)][obtenerPosicion(nombre_punto1)] = true;
    }
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

void Rutas::eliminarCamino(char* nombre_punto1, char* nombre_punto2)
{
    if(caminos[obtenerPosicion(nombre_punto1)][obtenerPosicion(nombre_punto2)] &&
       caminos[obtenerPosicion(nombre_punto2)][obtenerPosicion(nombre_punto1)])
   {
        caminos[obtenerPosicion(nombre_punto1)][obtenerPosicion(nombre_punto2)] = false;
        caminos[obtenerPosicion(nombre_punto2)][obtenerPosicion(nombre_punto1)] = false;
   }
}

void Rutas::eliminarPeso(char* nombre_punto1, char* nombre_punto2)
{
    if(pesos[obtenerPosicion(nombre_punto1)][obtenerPosicion(nombre_punto2)] < 9999 &&
       pesos[obtenerPosicion(nombre_punto2)][obtenerPosicion(nombre_punto1)] < 9999)
   {
        pesos[obtenerPosicion(nombre_punto1)][obtenerPosicion(nombre_punto2)] = 9999;
        pesos[obtenerPosicion(nombre_punto2)][obtenerPosicion(nombre_punto1)] = 9999;
   }
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

int Rutas::caminoMinimo(char* nombre_punto1, char* nombre_punto2)
{

	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			distancias[i][j] = pesos[i][j];
		}
	}

    for(int a = 0; a < _size; a++)
    {
        for(int b = 0; b < _size; b++)
        {
            for(int c = 0; c < _size; c++)
            {
                if(distancias[b][a]+distancias[a][c] < distancias[b][c])
                {
                    distancias[b][c] = distancias[b][a]+distancias[a][c];
                }
            }
        }
    }
    return distancias[obtenerPosicion(nombre_punto1)][obtenerPosicion(nombre_punto2)];
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
    delete distancias;
    delete adyacencieas;
    delete caminos;
}
