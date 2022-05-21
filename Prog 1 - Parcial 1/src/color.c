#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"

int hardcodearColores(eColor colores[], int tam, int cant, int* pNextId)
{
    int retorno = 0;
    eColor auxColores[5] =
    {
        //(Gris, Negro, Azul, Blanco, Rojo)
        {0, "Gris"},
        {0, "Negro"},
        {0, "Azul"},
        {0, "Blanco"},
        {0, "Rojo"}

    };

    if( colores != NULL && pNextId != NULL && tam > 0 && tam <= 10 && cant <= tam)
    {
        for(int i=0; i < cant; i++)
        {
            colores[i] = auxColores[i];
            colores[i].id = *pNextId;
            (*pNextId)++;
        }
        retorno = 1;
    }
    return retorno;

}


int listarColores(eColor colores[],int tam)
{

 int retorno = 0;
    if(colores != NULL && tam > 0 )
    {

        printf("   *** Listado de Colores ***\n");
        printf("-------------------------\n");
        printf("  ID          Descripcion\n");
        printf("-------------------------\n");

         for(int i= 0; i < tam; i++)
         {

           printf("  %2d      %10s\n", colores[i].id, colores[i].descripcion);

         }
         retorno = 1;
    }
    return retorno;
}



int buscarColor(eColor colores[], int tam, int id, int* pIndex)
{
    int retorno = 0;
    if( colores != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(colores[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        retorno = 1;
    }
    return retorno;
}


int validarColor(eColor colores[], int tam, int id)
{
    int esValido = 0;
    int indice;

    if (buscarColor(colores, tam, id, &indice))
        {
            if(indice != -1)
            {
                esValido = 1;
            }
        }

    return esValido;
}


int cargarDescripcionColor(eColor colores[], int tam, int id, char desc[])
{

    int retorno = 0;
    if(colores != NULL && tam > 0 && desc != NULL){

         for(int i= 0; i < tam; i++){

            if( colores[i].id == id){
                strcpy( desc, colores[i].descripcion);
                retorno = 1;
                break;
            }

         }
    }
    return retorno;
}


