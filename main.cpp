#include "Evaluador.h"
#include <fstream>
#include <math.h>
#include <iostream>
//Trabajo en grupo realizado con Kevin Lanza
//Tomadas algunas anotaciones de http://informatica.uv.es/iiguia/AED/oldwww/2004_05/AED.Tema.07.pdf
using namespace std;

//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo de texto
void escribirNumeroTexto(string nombre_archivo, int num)
{
//Tomando ejemplo de http://jsbsan.blogspot.com/2012/01/c-ejemplo-de-guardar-texto-en-un.html
    ofstream out(nombre_archivo.c_str());
    out<<num<<endl;
    out.close();

}
int leerNumeroTexto(string nombre_archivo)
{
    ifstream archivo(nombre_archivo.c_str());
    int num;
    archivo>>num;
    return num;

}
//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo de texto
void escribirStringTexto(string nombre_archivo, string str)
{
//Tomando ejemplo de http://jsbsan.blogspot.com/2012/01/c-ejemplo-de-guardar-texto-en-un.html
//Se aplica exactamente al anterior solo que con string.
    ofstream out(nombre_archivo.c_str());
    out<<str<<endl;
    out.close();
}
string leerStringTexto(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());
    string str;
    in>>str;
    return str;
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo binario
void escribirNumeroBinario(string nombre_archivo, int num)
{
//Tomado de explicacion en clase https://github.com/Ceutec/ArchivosBinarios/blob/master/main.cpp
//y  http://informatica.uv.es/iiguia/AED/oldwww/2004_05/AED.Tema.07.pdf
// Seccion 7.7
    ofstream out(nombre_archivo.c_str());
    out.write((char*)&num,4);
    out.close();

}
int leerNumeroBinario(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());
    int num;
    in.read((char*)&num,4);
    return num;
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo binario
void escribirStringBinario(string nombre_archivo, string str)
{
}
string leerStringBinario(string nombre_archivo)
{
    return "";
}

//Devuelve true si encuentra str (dada) en un archivo dado el nombre
bool existe(string nombre_archivo, string str)
{
    return false;
}

//Devuelve el numero mayor dado el nombre de un archivo binario
int obtenerMayor(string nombre)
{
    ifstream in(nombre.c_str());
    //seek para buscar el final y el principio.
    in.seekg(0,ios::end);
    //tellg para saber el espacio donde estamos del archivo(bits).
    int tamano = in.tellg();
    in.seekg(0,ios::beg);

    int mayor = -999;
    while(in.tellg()<tamano)
        {
         int num;
         in.read((char*)&num,4);

            if(mayor<num)
            mayor=num;
        }
        return mayor;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
