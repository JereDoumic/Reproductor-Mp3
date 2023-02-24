#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipados.h"


nodoArbolCancion * inicArbol ()
{
    return NULL;
}

nodoArbolCancion * crearNodoArbol (stCancion cancion)
{
    nodoArbolCancion * aux = malloc (sizeof (nodoArbolCancion));
    aux -> c = cancion;
    aux -> izq = NULL;
    aux -> der = NULL;
    return aux;
}

nodoArbolCancion * insertarNodoArbol(nodoArbolCancion * playlist, stCancion cancion)
{
    if (playlist == NULL)
    {
        playlist = crearNodoArbol (cancion);
    }
    else
    {
        if (cancion.idCancion > playlist -> c.idCancion)
        {
            playlist -> der = insertarNodoArbol (playlist -> der, cancion);
        }
        else
        {
            if (cancion.idCancion < playlist -> c.idCancion)
            {
                 playlist -> izq = insertarNodoArbol (playlist -> izq, cancion);
            }
            else
            {
                printf ("La canción ingresada ya está registrada\n");
            }
        }
    }
    return playlist;
}

//mostrarArbol

void preorder (nodoArbolCancion * playlist)
{
    if (playlist != NULL)
    {
        printf ("Id Canción : %d\n", playlist -> c.idCancion);
        preorder (playlist -> izq);
        preorder (playlist -> der);
    }
}

void inorder (nodoArbolCancion * playlist)
{
    if (playlist != NULL)
    {
        inorder (playlist -> izq);
        printf ("Id Canción : %d\n", playlist -> c.idCancion);
        inorder (playlist -> der);
    }
}


void postorder (nodoArbolCancion * playlist)
{
    if (playlist != NULL)
    {
        postorder (playlist -> izq);
        postorder (playlist -> der);
        printf ("Id Canción : %d\n", playlist -> c.idCancion);
    }
}

nodoArbolCancion * buscarCancion (nodoArbolCancion * playlist, int idCancion)
{
    nodoArbolCancion * rta = NULL;
    if (playlist != NULL)
    {
        if (idCancion == playlist -> c.idCancion)
        {
            rta =playlist;
        }
        else
        {
            if (idCancion > playlist -> c.idCancion)
            {
                rta = buscarCancion(playlist -> der, idCancion);
            }
            else
            {
                rta = buscarCancion (playlist -> izq, idCancion);
            }
        }
    }
    return rta;
}

/*nodoArbolCancion * buscarMasIzquierdo(nodoArbolCancion * playlist -> der, int idCancion)
{
    nodoArbolCancion * rta = NULL;
    while (playlist != NULL)
    {
        rta = playlist;
        buscarMasIzquierdo (playlist -> der);
    }
    return rta;
}

nodoArbolCancion * buscarMasDerecho (nodoArbolCancion * playlist -> izq, int idCancion)
{
    nodoArbolCancion * rta = NULL;
    while (playlist != NULL)
    {
        rta = playlist;
        buscarMasDerecho (playlist -> izq);
    }
    return rta;
}*/

/*nodoArbolCancion* borrarUnNodoArbol (nodoArbolCancion * playlist, int idCancion)
{
    if (playlist != NULL)
    {
        if (idCancion == playlist -> c.idCancion)
        {
            if (playlist -> izq != NULL)
            {
                nodoArbolCancion * masDerecho = bucarMasDerecho (playlist -> izq);
                playlist -> c = masDerecho -> c;
                playlist -> izq = borrarUnNodoArbol (playlist -> izq, masDerecho -> c.id);
            }
            else
            {
                if (playlist -> der != NULL)
                {
                    nodoArbolCancion *masIzquierdo = buscarMasIzquierdo (playlist -> der);
                    playlist -> c = masIzquierdo -> c;
                    playlist -> der = borrarUnNodoArbol (playlist -> der, masIzquierdo -> c);
                }
                else
                {
                    Free (playlist -> c);
                    playlist -> c = NULL;
                }
            }
        }
        else
        {
            if (idCancion > playlist -> idCancion)
            {
                playlist -> der = borrarUnNodoArbol (playlist -> der, idCancion);
            }
            else
            {
                playlist -> izq = borrarUnNodoArbol (playlist -> izq, idCancion);
            }
        }
    }
    else
    {
        printf ("La canción ingresada no está en la playlist n");
    }
    return playlist;
}*/

int contarArchivoDeCanciones(char ruta[40])
{
    int contador = 0;
    FILE * archivo = fopen("canciones.bin", "rb");
    if(archivo != NULL)
    {
        stCancion cancion;
        while(fread(&cancion, sizeof(cancion), 1, archivo))
        {
            contador++;
        }
    }
    return contador;
}

int calculoMitadParaArbol (int contador)
{
    int rta;
    rta = contador / 2;
}

void cargarArbolDesdeArchivo(char ruta [40], nodoArbolCancion * playlist)
{
    FILE * archivo = fopen("canciones.bin", "rb");
    stCancion cancion;
    if(archivo != NULL)
    {
        fread(&cancion, sizeof(cancion), 1, archivo);
        insertarNodoArbol (playlist , cancion);
    }
     fclose(archivo);
}



