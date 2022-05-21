#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//#ifndef MOTOS_H_INCLUDED
//#define MOTOS_H_INCLUDED

#include "tipo.h"
#include "color.h"
#include "cliente.h"


typedef struct
{
    int id;
    char marca[20];       // (máx 20 caracteres)
    int idTipo;          // Validar
    int idColor;         // Validar
    int cilindrada;
    int puntaje;        // (1 a 10)
    int idCliente;
    int isEmpty;

}eMoto;


int menuMotos(int* opcion);
////////////////////

int hardcodearMotos(eMoto motos[], int tam, int cant, int* pNextId);
int inicializarMotos(eMoto vec[], int tam);
int buscarLibreMoto(eMoto vec[], int tam, int* pIndex);

int altaMoto(eMoto vec[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol,eCliente clientes[], int tamCliente, int* pNextId);
int listarMotos(eMoto motos[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCliente);
void mostrarMotoFila(eMoto moto, eTipo tipos[],int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamClientes);
int buscarMoto(eMoto motos[], int tam, int id, int* pIndex);
int bajaMoto(eMoto motos[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCliente);
int modificarMoto(eMoto motos[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCliente);
int menuModificarMoto();

int validarMoto(eMoto motos[], int tam, int id);
int cargarDescripcionMoto(eMoto motos[], int tam, int id, char marca[]);

/////////////////
int listarMotosPorColor(eMoto motos[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCliente);
int promedioPuntajePorTipo(eMoto motos[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCliente, float* promedio);
int listarMotosMayorCilindrada(eMoto motos[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCliente);
int contarMotosPorTipoyColor(eMoto motos[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCliente, int* contador);
int mostarColoresMasElegidos(eMoto motos[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCliente);

//#endif // MOTOS_H_INCLUDED

