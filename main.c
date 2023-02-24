#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <pthread.h>
#include <string.h>


typedef struct
{
    char nombre[30];
    struct nodo * sig;
} nodo;

typedef struct
{
    int idCancion;
    char titulo [30];
    char artista [20];
    int duracion;
    char album [20];
    int anio;
    char genero [20];
    char comentario [100];
    int eliminado;
} stCancion;

typedef struct
{
    int idUsuario;
    char nombreUsuario[40];
    char pass[40];
    int anioNacimiento;
    char genero[40];
    char pais[40];
    //int eliminado; // indica 1 o 0 si el cliente fue eliminado
} stUsuario;

typedef struct
{
 int idPlaylist;
 int idUsuario;
 int idCancion;
} stPlaylist;

nodo * inicLista();
nodo * crearNodo(char nombre[30]);
nodo * agregarAlPrincipioDeLalista(nodo * lista, nodo * nuevoNodo);
stUsuario crearUsuario(char nombreUsuario[40], char password[40], int IDusuario, int anioNacimiento, char genero[40], char pais[40]);
stUsuario eliminarUsuario(stUsuario usuario);

void mostrarArchivo(char ruta[30])
{
    stUsuario usuario;
    FILE * archivo = fopen(ruta, "rb");
    if(archivo != NULL)
    {
        while(fread(&usuario, sizeof(usuario), 1, archivo) > 0)
        {
            mostrarUsuario(usuario);
        }
    }
}



int main()
{

    //Inicio();
    MenuPrincipal();



}



