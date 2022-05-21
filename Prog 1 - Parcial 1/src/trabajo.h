#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"

#include "motos.h"
#include "servicio.h"

typedef struct
{
    int id;          //(autoincremental)
    int idMoto;      // (debe existir) Validar
    int idServicio;  //(debe existir) Validar
    eFecha fecha;    // (Validar día, mes y año)
    int isEmpty;

}eTrabajo;

int hardcodearTrabajos(eTrabajo trabajos[], int tam, int cant, int* pNextId);
int inicializarTrabajos(eTrabajo vec[], int tam);
int buscarLibreTrabajo(eTrabajo vec[], int tam, int* pIndex);
int altaTrabajo(eTrabajo trabajos[], int tamT, eMoto motos[], int tamM, eServicio servicios[], int tamS,eTipo tipos[], int tamTip, eColor colores[],int tamCol, eCliente clientes[], int tamCliente, int* pNextId);
int listarTrabajos(eTrabajo trabajos[], int tamT, eMoto motos[], int tamM, eServicio servicios[], int tamS);
void mostrarTrabajoFila(eTrabajo trab, eMoto motos[], int tamM, eServicio servicios[], int tamS);
int mostrarTrabajosRealizadosXMoto(eMoto motos[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCliente,eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamS);
int sumarServiciosParaUnaMoto(eMoto motos[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCliente,eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamS, int* suma);

int mostrarMotosxServicioyFecha(eMoto motos[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCliente,eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamS);

#endif // TRABAJO_H_INCLUDED
