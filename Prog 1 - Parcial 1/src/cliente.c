#include "cliente.h"


int hardcodearClientes(eCliente clientes[], int tam, int cant, int* pNextId)
{
    int retorno = 0;
    eCliente auxClientes[10] =
    {

        {0, "Perla", 'f'},
		{0, "Juan", 'm'},
		{0, "Marta", 'f'},
		{0, "Carlos", 'm'},
		{0, "Ariel", 'm'},
		{0, "Fabio", 'm'},
		{0, "Laura", 'f'},
		{0, "Julia", 'f'},
		{0, "Raul", 'm'},
		{0, "Micaela", 'f'}
    };

    if( clientes != NULL && pNextId != NULL && tam > 0 && cant <= tam)
    {
        for(int i=0; i < cant; i++)
        {
        	clientes[i] = auxClientes[i];
        	clientes[i].id = *pNextId;
            (*pNextId)++;
        }
        retorno = 1;
    }
    return retorno;

}



int cargarNombreCliente(eCliente clientes[], int tam, int id, char nombre[])
{

    int retorno = 0;
    if(clientes != NULL && tam > 0 && nombre != NULL){

         for(int i= 0; i < tam; i++){

            if( clientes[i].id == id){
                strcpy( nombre, clientes[i].nombre);
                retorno = 1;
                break;
            }

         }
    }
    return retorno;
}



int listarClientes(eCliente clientes[],int tam)
{

 int retorno = 0;
    if(clientes != NULL && tam > 0 )
    {

        printf("   *** Listado de Servicios ***\n");
        printf("--------------------------------------\n");
        printf("  ID          Nombre       Sexo\n");
        printf("--------------------------------------\n");

         for(int i= 0; i < tam; i++)
         {

           printf("  %2d      %10s     %10c\n", clientes[i].id, clientes[i].nombre, clientes[i].sexo);

         }
         retorno = 1;
    }
    return retorno;
}

