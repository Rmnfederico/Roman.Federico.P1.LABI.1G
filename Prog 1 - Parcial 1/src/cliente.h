#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct
{
	int id;
	char nombre[20];
	char sexo;

}eCliente;

int hardcodearClientes(eCliente clientes[], int tam, int cant, int* pNextId);
int cargarNombreCliente(eCliente clientes[], int tam, int id, char nombre[]);
int listarClientes(eCliente clientes[],int tam);

#endif /* CLIENTE_H_ */
