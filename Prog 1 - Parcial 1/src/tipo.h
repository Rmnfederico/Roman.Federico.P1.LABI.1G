#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;                      //(comienza en 1000)
    char descripcion[20];       //(max 20 caracteres)

}eTipo;

int hardcodearTipos(eTipo tipos[], int tam, int cant, int* pNextId);
int listarTipos(eTipo tipos[],int tam);
int validarTipo(eTipo vec[], int tam, int id);
int buscarTipo(eTipo vec[], int tam, int id, int* pIndex);
int cargarDescripcionTipo(eTipo tipos[], int tam, int id, char desc[]);

#endif // TIPO_H_INCLUDED

