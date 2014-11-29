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
//Utilizamos la funcion ofstream para escribir en el archivo
    ofstream out(nombre_archivo.c_str());
//Le asignamos la variable a nuestro archivo
    out<<num<<endl;
//Cerramos nuestro archivo
    out.close();

}
int leerNumeroTexto(string nombre_archivo)
{
//Utilizamos ifstream para leer en el archivo
    ifstream archivo(nombre_archivo.c_str());
//Creamos nuestra variable almacenadora
    int num;
//Leemos nuestra varible en el archivo
    archivo>>num;
//Retornamos el valor de nuestra varible
    return num;

}
//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo de texto
void escribirStringTexto(string nombre_archivo, string str)
{
//Tomando ejemplo de http://jsbsan.blogspot.com/2012/01/c-ejemplo-de-guardar-texto-en-un.html
//Se aplica exactamente al anterior solo que con string.
//Utilizamos la funcion ofstream para escribir en el archivo
    ofstream out(nombre_archivo.c_str());
//Le asignamos la variable a nuestro archivo
    out<<str<<endl;
//Cerramos nuestro archivo
    out.close();
}
string leerStringTexto(string nombre_archivo)
{
//Utilizamos ifstream para leer en el archivo
    ifstream in(nombre_archivo.c_str());
//Creamos nuestra variable almacenadora
    string str;
//Leemos nuestra varible en el archivo
    in>>str;
//Retornamos el valor de nuestra varible
    return str;
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo binario
void escribirNumeroBinario(string nombre_archivo, int num)
{
//Tomado de explicacion en clase https://github.com/Ceutec/ArchivosBinarios/blob/master/main.cpp
//y  http://informatica.uv.es/iiguia/AED/oldwww/2004_05/AED.Tema.07.pdf
// Seccion 7.7
//Utilizamos la funcion ofstream para escribir en el archivo
    ofstream out(nombre_archivo.c_str());
//Convertimos a char apuntador nuestro int
    out.write((char*)&num,4);
//Cerramos nuestro archivo
    out.close();

}
int leerNumeroBinario(string nombre_archivo)
{
//Utilizamos ifstream para leer en el archivo
    ifstream in(nombre_archivo.c_str());
//Creamos nuestra variable almacenadora
    int num;
//Leemos nuestra varible almacenadora
    in.read((char*)&num,4);
//Retornamos el valor de nuestra varible
    return num;
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo binario
void escribirStringBinario(string nombre_archivo, string str)
{
//Se aplica exactamente al anterior solo que con string.
//Utilizamos la funcion ofstream para escribir en el archivo
    ofstream out(nombre_archivo.c_str());
//Devolvemos el valor de nuestra variable en la primero posicion de nuestra cadena de string
    out.write(str.c_str(),4);
//Cerramos nuestro archivo
    out.close();
}
string leerStringBinario(string nombre_archivo)
{
//Utilizamos ifstream para leer en el archivo
   ifstream in(nombre_archivo.c_str());
//Creamos nuestra variable que sirve como cadena
    char leido[4];
//Se lee los valores asignados a nuestra variable
    in.read(leido,4);
//Retornamos el valor de nuestra varible
    return leido;
}

//Devuelve true si encuentra str (dada) en un archivo dado el nombre
bool existe(string nombre_archivo, string str)
{
//Utilizamos ifstream para leer en el archivo
   ifstream in(nombre_archivo.c_str());
//Creamos nuestra variable evaluadora
    string palabra;
//Creamos nuestra variable contadora y utilizamos el ciclo que recorra todo el archivo
    int cant;
    for(int i=0;i < cant;i++)
    {
//Le asignamos el valor de nuestra palabra al archivo y evalua si es existe o no existe
        in>>palabra;
        if(palabra == str)
        {
            return true;
        }
    }
    return false;
}

//Devuelve el numero mayor dado el nombre de un archivo binario
int obtenerMayor(string nombre)
{
//Utilizamos ifstream para leer en el archivo
    ifstream in(nombre.c_str());
//Seek para buscar el final y el principio.
    in.seekg(0,ios::end);
//Tellg para saber el espacio donde estamos del archivo(bits).
    int tamano = in.tellg();
    in.seekg(0,ios::beg);
//Le asignamos el valor a nuestra variable
    int mayor = -999;
//Creamos el ciclo para establecer la posicion de nuestro archivo
    while(in.tellg()<tamano)
        {
//Creamos nuestra variable y la convertimos a char apuntador
         int num;
         in.read((char*)&num,4);
//Evaluamos nuestra variable si es mayor a la del archivp
            if(mayor<num)
            mayor=num;
        }
//Muestra el numero de nuestro archivo
        return mayor;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
