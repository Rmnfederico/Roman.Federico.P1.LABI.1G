#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;                  //(comienza en 20000)
    char descripcion[25];   // (maximo 25 caracteres)
    float precio;

}eServicio;

int hardcodearServicios(eServicio servicios[], int tam, int cant, int* pNextId);
int listarServicios(eServicio servicios[],int tam);
int buscarServicio(eServicio servicios[], int tam, int id, int* pIndex);
int validarServicio(eServicio servicios[], int tam, int id);
int cargarDescripcionServicio(eServicio servicios[], int tam, int id, char desc[]);

#endif // SERVICIO_H_INCLUDED


