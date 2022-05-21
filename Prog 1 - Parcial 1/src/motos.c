#include "motos.h"





int hardcodearMotos(eMoto motos[], int tam, int cant, int* pNextId)
{
    int retorno = 0;
    eMoto auxMotos[10] =
    {
        //50, 125, 500, 600, 750
        {0, "Yamaha RX", 1000, 10003, 50, 10,3000,0},
        {0, "Zanella Ceccato", 1001, 10004, 125, 9,3001,0},
        {0, "Honda CG", 1003, 10001, 500, 8,3002,0},
        {0, "Honda Titan", 1002, 10000,600,7,3003,0},
        {0, "Ducati Scrambler", 1002, 10002,750,5,3004,0},
        {0, "Royal Enfield", 1001, 10004,50,6,3005,0},
        {0, "Rouser NS200", 1003, 10000,125,8,3006,0},
        {0, "Zanella Eagle", 1000, 10003,500,7,3007,0},
        {0, "KTM 250", 1002, 10002,600,9,3008,0},
        {0, "Dominar 400", 1001, 10004,750,10,3009,0}
    };

    if( motos != NULL && pNextId != NULL && tam > 0 && cant <= tam)
    {
        for(int i=0; i < cant; i++)
        {
            motos[i] = auxMotos[i];
            motos[i].id = *pNextId;
            (*pNextId)++;
        }
        retorno = 1;
    }
    return retorno;

}

int inicializarMotos(eMoto vec[], int tam)
{
    int retorno = 0;
    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        retorno = 1;
    }
    return retorno;
}

int menuMotos(int* opcion)
{
    int retorno = 0;


    system("cls");
    printf("     *** ABM Motos ***\n\n");
    printf("1. ALTA MOTO\n");
    printf("2. MODIFICAR MOTO: Se ingresará el id, permitiendo en un submenú modificar:\n");
    printf("    • Color\n");
    printf("    • Puntaje\n");
    printf("3. BAJA MOTO: Se ingresara el id de la moto y se realizara una baja lógica.\n");
    printf("4. LISTAR MOTOS: Hacer un unico listado de todas las motos ordenadas por tipo y id.\n");
    printf("5. LISTAR TIPOS\n");
    printf("6. LISTAR COLORES\n");
    printf("7. LISTAR SERVICIOS\n");
    printf("8. ALTA TRABAJO: Se dara de alta cada ocurrencia de trabajo pidiendole al usuario que elija una moto\n");
    printf("9. LISTAR TRABAJOS\n");
    printf("10. LISTAR MOTOS POR COLOR\n");
    printf("11.CALCULAR PROMEDIO POR TIPO\n");
    printf("12. LISTAR MOTOS CON MAYOR CILINDRADA\n");
    printf("13. LISTAR MOTOS SEPARADAS TIPO\n");
    printf("14. CONTAR MOTOS POR COLOR Y TIPO\n");
    printf("15. MOSTRAR COLOR/ES MAS ELEGIDOS\n");
    printf("16.MOSTRAR LOS TRABAJOS REALIZADOS A UNA MOTO\n");
    printf("17.MOSTRAR LA SUMA DE PRECIO DE SERVICIOS PARA UNA MOTO\n");
    printf("18.MOSTRAR MOTOS POR UN SERVICIO Y SU FECHA\n");
    printf("20. Salir\n\n");

    printf("Ingrese opcion: ");
    fflush(stdin);

    if(opcion != NULL)
    {
        scanf("%d", opcion);
        retorno = 1;
    }



    return retorno;

}

int buscarLibreMoto(eMoto vec[], int tam, int* pIndex)
{

    int retorno = 0;
    if( vec != NULL && pIndex != NULL && tam > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(vec[i].isEmpty)
            {
                *pIndex = i;
                break;
            }
        }
        retorno = 1;
    }
    return retorno;
}



int altaMoto(eMoto vec[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol,eCliente clientes[], int tamCliente, int* pNextId)
{
    int retorno = 0;
    int indice;

    int idTipo;
    int idColor;
    //int idCliente;

    eMoto auxMoto;


    if( vec != NULL && pNextId != NULL)
    {
        system("cls");
        printf("    *** Alta Moto ***\n\n");
        buscarLibreMoto(vec, tam, &indice);

        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            auxMoto.id = *pNextId;
            printf("Ingrese marca: ");
            fflush(stdin);
            gets(auxMoto.marca);



            ///////////////////////////////////////////////////// funciones listarTipos - validarTipos / listarColores - validarColores
            listarTipos(tipos, tamTip);


            printf("Ingrese el ID del tipo: ");
            scanf("%d", &idTipo);

            // validar si existe ese id sector
            while(!validarTipo(tipos,tamTip, idTipo))
            {
                printf("Id invalido. Reingrese ID del tipo: ");
                scanf("%d", &idTipo);
            }


            auxMoto.idTipo = idTipo;
            /////////////////////////////////////////////////////
            listarColores(colores, tamCol);

            printf("Ingrese ID del color: ");
            scanf("%d", &idColor);

            // validar si existe ese id sector
            while( !validarColor(colores, tamCol , idColor))
            {
                printf("Id invalido. Reingrese ID del color: ");
                scanf("%d", &idColor);
            }


            auxMoto.idColor = idColor;

            /////////////////////////////////////////////////////

            printf("ingrese cilindrada: ");
            scanf("%d", &auxMoto.cilindrada);
            //Validar int

            printf("ingrese puntaje: ");
            scanf("%d", &auxMoto.puntaje);
            //Validar int

            /////////////////////////////////////////////////////


            auxMoto.isEmpty = 0;

            vec[indice] = auxMoto;

            (*pNextId)++;

            retorno = 1;
        }
    }
    return retorno;
}



void mostrarMotoFila(eMoto moto, eTipo tipos[],int tamTip,eColor colores[], int tamCol, eCliente clientes[], int tamClientes)
{

    char descripcionTipo[20];
    char descripcionColor[20];
    char nombreCliente[20];

    cargarDescripcionTipo(tipos, tamTip, moto.idTipo, descripcionTipo);
    cargarDescripcionColor(colores, tamCol, moto.idColor, descripcionColor);
    cargarNombreCliente(clientes, tamClientes, moto.idCliente, nombreCliente);



    printf("    %d    %20s      %8s    %10s    %6d   %6d   %12s\n",
           moto.id,
		   moto.marca,
		   descripcionTipo,
		   descripcionColor,
		   moto.cilindrada,
           moto.puntaje,
		   nombreCliente
          );
}



int listarMotos(eMoto motos[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCliente)
{
    int retorno = 0;
    int flag = 1;
    if( motos != NULL && tam > 0 && tipos != NULL && tamTip > 0 && colores != NULL && tamCol > 0 && clientes != NULL && tamCliente > 0)
    {
        //system("cls");
        printf("      		      	 *** Listado de Motos ***\n");
        printf("--------------------------------------------------------------------------------------------\n");
        printf("   ID               Marca             Tipo          Color       Cil.     Ptje.      Cliente\n");
        printf("--------------------------------------------------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            if( !motos[i].isEmpty)
            {
                mostrarMotoFila(motos[i], tipos, tamTip, colores, tamCol, clientes, tamCliente);
                flag = 0;
            }
        }
        printf("----------------------------------------------------------------------------------------------\n");
        if(flag)
        {
            printf("     No hay motos cargadas en el sistema\n\n");
        }

        retorno = 1;
    }
    return retorno;
}




int buscarMoto(eMoto motos[], int tam, int id, int* pIndex)
{
    int retorno = 0;
    if( motos != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( !motos[i].isEmpty  && motos[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        retorno = 1;
    }
    return retorno;
}



int bajaMoto(eMoto motos[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCliente)
{
    int retorno = 0;
    int indice;
    int id;
    char confirma;

    if( motos != NULL && tam > 0 && tipos != NULL && tamTip > 0 && colores != NULL && tamCol > 0)
    {
        listarMotos(motos, tam, tipos, tamTip, colores, tamCol, clientes, tamCliente);
        printf("Ingrese id: ");
        scanf("%d", &id);

        if( buscarMoto(motos, tam, id, &indice))
        {

            if(indice == -1)
            {
                printf("No existe una moto con id: %d en el sistema\n", id);
            }
            else
            {

                mostrarMotoFila(motos[indice], tipos, tamTip, colores, tamCol, clientes, tamCliente);
                printf("Confirma baja?(s): ");
                fflush(stdin);
                scanf("%c", &confirma);

                if(confirma == 's' || confirma == 'S')
                {
                    motos[indice].isEmpty = 1;
                    printf("Baja exitosa!\n");
                }
                else
                {
                    printf("Baja cancelada por el usuario.\n");
                }

            }

            retorno = 1;
        }
    }
    return retorno;
}


int modificarMoto(eMoto motos[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCliente)
{
    int retorno = 0;
    int indice;
    int id;

    int idColor;
    int puntaje;


    if( motos != NULL && tam > 0 && tipos != NULL && tamTip > 0 && colores != NULL && tamCol > 0)
    {
        listarMotos(motos, tam, tipos, tamTip, colores, tamCol, clientes, tamCliente);
        printf("Ingrese id: ");
        scanf("%d", &id);

        if(buscarMoto(motos, tam, id, &indice))
        {

            if(indice == -1)
            {
                printf("No existe una moto con id: %d en el sistema\n", id);
            }
            else
            {

            	mostrarMotoFila(motos[indice], tipos, tamTip, colores, tamCol, clientes, tamCliente);

                switch(menuModificarMoto()) //////////////////////// DESARROLLAR
                {

                	case 1:
                    listarColores(colores, tamCol);

                    printf("Ingrese el ID del color:");
                    scanf("%d", &idColor);

                    // validar si existe ese id color
                    while( !validarColor(colores, tamCol, idColor) )
                    {
                        printf("Id invalido. Reingrese el ID del color:");
                        scanf("%d", &idColor);
                    }
                    motos[indice].idColor = idColor;
                    printf("Color modificado!\n\n");
                    break;

                	case 2:
                	printf("Ingrese el nuevo puntaje:");
                	scanf("%d",&puntaje);

                	//validar puntaje solo INT entre 1 y 10
                	motos[indice].puntaje = puntaje;
                	printf("Puntaje modificado!\n\n");
                    break;

                	case 3:
                		printf("Modificacion finalizada.\n");
                	break;

                }
            }
            retorno = 1;
        }
    }
    return retorno;
}




int menuModificarMoto()
{
    int opcion;

    printf("     *** Campo a modificar ***\n\n");
    printf("1. Color\n");
    printf("2. Puntaje.\n");
    printf("3. Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}



int validarMoto(eMoto motos[], int tam, int id)
{
    int esValido = 0;
    int indice;

    if (buscarMoto(motos, tam, id, &indice))
    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }
    return esValido;
}

int cargarDescripcionMoto(eMoto motos[], int tam, int id, char marca[])
{

    int retorno = 0;
    if(motos != NULL && tam > 0 && marca != NULL)
    {

         for(int i= 0; i < tam; i++)
         {

            if( motos[i].id == id)
            {
                strcpy( marca, motos[i].marca);
                retorno = 1;
                break;
            }

         }
    }
    return retorno;
}

int listarMotosPorColor(eMoto motos[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCliente)
{
	int retorno = 0;
	int flag = 1;
	int idColor;

	if( motos != NULL && tam > 0 && tipos != NULL && tamTip > 0 && colores != NULL && tamCol > 0 && clientes != NULL && tamCliente > 0)
		{
			listarColores(colores, tamCol);
			printf("ingrese el ID del color a mostrar:");
			scanf("%d",&idColor);

		    while( !validarColor(colores, tamCol , idColor))
		      	  {
		           	   printf("Id invalido. Reingrese ID del color: ");
		           	   scanf("%d", &idColor);
		      	  }


			printf("      		      	 *** Listado de Motos por Color ***\n");
			printf("--------------------------------------------------------------------------------------------\n");
			printf("   ID               Marca             Tipo          Color       Cil.     Ptje.      Cliente\n");
			printf("--------------------------------------------------------------------------------------------\n");
		        for(int i=0; i < tam; i++)
		        {
		            if( !motos[i].isEmpty && motos[i].idColor == idColor)
		            {
		                mostrarMotoFila(motos[i], tipos, tamTip, colores, tamCol, clientes, tamCliente);
		                flag = 0;
		            }
		        }
		        printf("----------------------------------------------------------------------------------------------\n");
		        if(flag)
		        {
		            printf("     No hay motos cargadas en el sistema\n\n");
		        }

		        retorno = 1;
		    }
		    return retorno;
		}

int promedioPuntajePorTipo(eMoto motos[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCliente, float* promedio)
{
	int retorno = 0;
	int flag = 1;
	int idTipo;
	float acumulador = 0;
	int contador = 0;


	if( motos != NULL && tam > 0 && tipos != NULL && tamTip > 0 && colores != NULL && tamCol > 0 && clientes != NULL && tamCliente > 0)
	{
		listarTipos(tipos, tamTip);
		printf("Ingrese el ID del tipo a promediar:");
		scanf("%d", &idTipo);

		 while( !validarTipo(tipos, tamTip , idTipo))
		 	 {
			 	 printf("Id invalido. Reingrese ID del color: ");
			 	 scanf("%d", &idTipo);
		 	 }

		 for(int i=0; i<tam; i++)
		 {
			 if(motos[i].idTipo == idTipo)
			 {
				 acumulador += motos[i].puntaje;
				 contador++;
				 flag = 0;
				 retorno = 1;
			 }
		 }
		 if(!flag)
		 {
			 *promedio = acumulador/contador;
		 }


	}

	return retorno;
}

int listarMotosMayorCilindrada(eMoto motos[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCliente)
{
	  	  int retorno = 0;
	  	  int flag = 1;
	  	  int mayor;

	  	  if( motos != NULL && tam > 0 && tipos != NULL && tamTip > 0 && colores != NULL && tamCol > 0 && clientes != NULL && tamCliente > 0)
	      {
	          system("cls");
	          printf("     *** Motos/s Mayor Cilindrada ***\n\n");
	          for(int i=0; i < tam; i++)
	          {
	              if( !motos[i].isEmpty && (flag || motos[i].cilindrada > mayor))
	              {
	                  mayor = motos[i].cilindrada;
	                  flag = 0;
	              }
	          }

	          for(int i=0; i < tam; i++)
	          {
	              if( !motos[i].isEmpty && motos[i].cilindrada == mayor)
	              {
	            	  mostrarMotoFila(motos[i], tipos, tamTip, colores, tamCol, clientes, tamCliente);
	              }

	          }

	          if(flag)
	          {
	              printf("No hay motos en el sistema\n");
	          }
	          retorno = 1;
	      }

	      return retorno;
}
/*
int listarMotosSeparadasPorTipo(eMoto motos[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCliente)
{

}
*/

int contarMotosPorTipoyColor(eMoto motos[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCliente, int* contador)
{
	int retorno = 0;
	int flag = 1;
	int idColor;
	int idTipo;
	*contador = 0;

	if( motos != NULL && tam > 0 && tipos != NULL && tamTip > 0 && colores != NULL && tamCol > 0 && clientes != NULL && tamCliente > 0)
		{
			listarColores(colores, tamCol);
			printf("ingrese el ID del color a contar:");
			scanf("%d",&idColor);

		    while( !validarColor(colores, tamCol , idColor))
		      	  {
		           	   printf("Id invalido. Reingrese ID del color: ");
		           	   scanf("%d", &idColor);
		      	  }

			listarTipos(tipos, tamTip);
			printf("ingrese el ID del tipo a contar:");
			scanf("%d",&idTipo);

		    while( !validarTipo(tipos, tamTip , idTipo))
		      	  {
		           	   printf("Id invalido. Reingrese ID del color: ");
		           	   scanf("%d", &idTipo);
		      	  }




		        for(int i=0; i < tam; i++)
		        {
		            if( !motos[i].isEmpty && motos[i].idColor == idColor && motos[i].idTipo == idTipo)
		            {
		                (*contador)++;
		                flag = 0;
		                retorno = 1;
		            }
		        }

		        if(flag)
		        {
		            printf("     No hay motos cargadas en el sistema\n\n");
		        }


		    }
		return retorno;
}
/*
int mostarColoresMasElegidos(eMoto motos[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCliente)
{
		int retorno = 0;
		int flag = 1;
		int idColor;
		int idTipo;
		int auxIdColores[5] = {10000,10001,10002,10003,10004};
		int contadores[5] = {0};

		if( motos != NULL && tam > 0 && tipos != NULL && tamTip > 0 && colores != NULL && tamCol > 0 && clientes != NULL && tamCliente > 0)
		{
			for(int i=0; i<5; i++)
			{
				for(int j=0;i<tam; j++)
				{
					if(motos[j].idColor == auxIdColores[i])
					{
						contadores[i]++;
						flag = 0;
					}
				}
			}

		}
		return retorno;
}
*/



