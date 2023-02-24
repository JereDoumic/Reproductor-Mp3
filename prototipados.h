#ifndef PROTOTIPADOS_H_INCLUDED
#define PROTOTIPADOS_H_INCLUDED

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
    char nombreUsuario[30];
    char pass[20];
    int anioNacimiento;
    char genero;
    char pais [20];
    int eliminado;
} stUsuario;

typedef struct
{
    stCancion c;
    struct nodoListaCancion * sig;
} nodoListaCancion;

typedef struct
{
    stUsuario usr;
    nodoListaCancion * listaCanciones;
} stCelda;

typedef struct
{
    int idPlaylist;
    int idUsuario;
    int idCancion;
} stPlaylist;



typedef struct
{
    stCancion c;
    struct nodoArbolCancion * izq;
    struct nodoArbolCancion * der;
} nodoArbolCancion;

nodoArbolCancion * inicArbol ();
nodoArbolCancion * crearNodoArbol (stCancion cancion);
nodoArbolCancion * insertarNodoArbol (nodoArbolCancion * playlist, stCancion cancion);
void preorder (nodoArbolCancion * playlist);
void inorder (nodoArbolCancion * playlist);
void postorder (nodoArbolCancion * playlist);
nodoArbolCancion * buscarCancion (nodoArbolCancion * playlist, int idCancion);
/*nodoArbolCancion * buscarMasIzquierdo (nodoArbolCancion * playlist -> der, int idCancion);
nodoArbolCancion * buscarMasDerecho (nodoArbolCancion * playlist -> izq, int idCancion);*/
nodoArbolCancion * borrarUnNodoArbol (nodoArbolCancion * playlist, int idCancion);
/*int contarArchivoDeCanciones(char ruta[40]);
int calculoMitadParaArbol (int contador);
void cargarArbolDesdeArchivo(char ruta [40]);*/







#endif // PROTOTIPADOS_H_INCLUDED
