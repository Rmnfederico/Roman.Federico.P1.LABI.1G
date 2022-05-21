#include "servicio.h"



int hardcodearServicios(eServicio servicios[], int tam, int cant, int* pNextId)
{
    int retorno = 0;
    eServicio auxServicios[4] =
    {
        //(Limpieza: $450, Ajuste: $300, Balanceo: $150, Cadena: $390)
        {0, "Limpieza",450},
        {0, "Ajuste",300},
        {0, "Balanceo",150},
        {0, "Cadena",390}

    };

    if( servicios != NULL && pNextId != NULL && tam > 0 && tam <= 10 && cant <= tam)
    {
        for(int i=0; i < cant; i++)
        {
            servicios[i] = auxServicios[i];
            servicios[i].id = *pNextId;
            (*pNextId)++;
        }
        retorno = 1;
    }
    return retorno;

}


int listarServicios(eServicio servicios[],int tam)
{

 int retorno = 0;
    if(servicios != NULL && tam > 0 )
    {

        printf("   *** Listado de Servicios ***\n");
        printf("--------------------------------------\n");
        printf("  ID          Descripcion       Precio\n");
        printf("--------------------------------------\n");

         for(int i= 0; i < tam; i++)
         {

           printf("  %2d      %10s     %10.2f\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);

         }
         retorno = 1;
    }
    return retorno;
}



int buscarServicio(eServicio servicios[], int tam, int id, int* pIndex)
{
    int retorno = 0;
    if( servicios != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(servicios[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        retorno = 1;
    }
    return retorno;
}



int validarServicio(eServicio servicios[], int tam, int id)
{
    int esValido = 0;
    int indice;

    if (buscarServicio(servicios, tam, id, &indice))
        {
            if(indice != -1)
            {
                esValido = 1;
            }
        }

    return esValido;
}



int cargarDescripcionServicio(eServicio servicios[], int tam, int id, char desc[])
{

    int retorno = 0;
    if(servicios != NULL && tam > 0 && desc != NULL){

         for(int i= 0; i < tam; i++){

            if( servicios[i].id == id){
                strcpy( desc, servicios[i].descripcion);
                retorno = 1;
                break;
            }

         }
    }
    return retorno;
}
