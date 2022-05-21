
#include "tipo.h"

//////////////////////////////////////////////////////////////////
int hardcodearTipos(eTipo tipos[], int tam, int cant, int* pNextId)
{
    int retorno = 0;
    eTipo auxTipos[4] =
    {
        //(Enduro, Chopera, Scooter, Vintage)
        {0, "Enduro"},
        {0, "Chopera"},
        {0, "Scooter"},
        {0, "Vintage"}

    };

    if( tipos != NULL && pNextId != NULL && tam > 0 && tam <= 4 && cant <= tam) //ta feo, ponele define a los min/max
    {
        for(int i=0; i < cant; i++)
        {
            tipos[i] = auxTipos[i];
            tipos[i].id = *pNextId;
            (*pNextId)++;
        }
        retorno = 1;
    }
    return retorno;

}

int listarTipos(eTipo tipos[],int tam)
{

 int retorno = 0;
    if(tipos != NULL && tam > 0 )
    {

        printf("   *** Listado de Tipos ***\n");
        printf("-------------------------\n");
        printf("  ID          Descripcion\n");
        printf("-------------------------\n");

         for(int i= 0; i < tam; i++)
         {

           printf("  %2d      %10s\n", tipos[i].id, tipos[i].descripcion);

         }
         retorno = 1;
    }
    return retorno;
}

int buscarTipo(eTipo vec[], int tam, int id, int* pIndex)
{
    int retorno = 0;
    if( vec != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(vec[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        retorno = 1;
    }
    return retorno;
}


int validarTipo(eTipo vec[], int tam, int id)
{
    int esValido = 0;
    int indice;

    if (buscarTipo(vec, tam, id, &indice))
        {
            if(indice != -1)
            {
                esValido = 1;
            }
        }

    return esValido;
}



int cargarDescripcionTipo(eTipo tipos[], int tam, int id, char desc[])
{

    int retorno = 0;
    if(tipos != NULL && tam > 0 && desc != NULL){

         for(int i= 0; i < tam; i++){

            if( tipos[i].id == id){
                strcpy( desc, tipos[i].descripcion);
                retorno = 1;
                break;
            }

         }
    }
    return retorno;
}



