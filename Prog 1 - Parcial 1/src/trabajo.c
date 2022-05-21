#include "trabajo.h"



//BONUS TRACK
int hardcodearTrabajos(eTrabajo trabajos[], int tam, int cant, int* pNextId)
{
    int retorno = 0;
    eTrabajo auxTrabajos[10] =
    {

        {0, 1, 20003, {15,2,2020},0},
		{0, 4, 20000, {10,11,2021},0},
		{0, 7, 20003, {5,8,2022},0},
		{0, 11, 20000, {9,6,2019},0},
		{0, 8, 20000, {13,1,2018},0},
		{0, 3, 20001, {16,3,2019},0},
		{0, 2, 20002, {21,5,2020},0},
		{0, 9, 20003, {28,9,2021},0},
		{0, 5, 20002, {1,12,2022},0},
		{0, 6, 20001, {4,2,2021},0},
    };

    if( trabajos != NULL && pNextId != NULL && tam > 0 && cant <= tam)
    {
        for(int i=0; i < cant; i++)
        {
        	trabajos[i] = auxTrabajos[i];
        	trabajos[i].id = *pNextId;
            (*pNextId)++;
        }
        retorno = 1;
    }
    return retorno;

}


int buscarLibreTrabajo(eTrabajo vec[], int tam, int* pIndex)
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



int altaTrabajo(eTrabajo trabajos[], int tamT, eMoto motos[], int tamM, eServicio servicios[], int tamS,eTipo tipos[], int tamTip, eColor colores[],int tamCol, eCliente clientes[], int tamCliente, int* pNextId)
{
	int retorno = 0;
	int indice;
	int idMoto;
	int idServicio;

	eTrabajo auxTrabajo;

	if(trabajos != NULL && tamT > 0 && motos != NULL && tamM > 0 && servicios != NULL && tamS > 0 && pNextId != NULL && tipos != NULL && tamTip > 0 && colores != NULL && tamCol > 0)
	{
		printf("    *** Alta Trabajo ***\n\n");
		buscarLibreTrabajo(trabajos, tamT, &indice);

		if(indice == -1)
		        {
		            printf("No hay lugar en el sistema\n");
		        }else
		        	{
		        		//SI HAY LUGAR MUESTRO MOTOS, SE INGRESA ID Y SE VALIDA - SE GUARDA en aux
		        		auxTrabajo.id = *pNextId;

		        		listarMotos(motos, tamM, tipos, tamTip, colores, tamCol, clientes, tamCliente);
		        		//listarMotos(motos, tamM);

		        		printf("Ingrese el ID de la moto: ");
		        		scanf("%d", &idMoto);

		        		 // validar si existe ese id sector
		        		 while(!validarMoto(motos,tamM, idMoto))
		        		 	 {
		        			 	 printf("Id invalido. Reingrese ID de la moto: ");
		        			 	 scanf("%d", &idMoto);
		        		 	 }


		        		 auxTrabajo.idMoto = idMoto;
		        		////////////////////////////////////////
		        		 listarServicios(servicios, tamS);

		        		 printf("Ingrese el ID del servicio: ");
		        		 scanf("%d", &idServicio);

		        		 // validar si existe ese id sector
		        		 while(!validarServicio(servicios,tamS, idServicio))
		        		 	 {
		        			 	 printf("Id invalido. Reingrese ID del servicio: ");
		        			 	 scanf("%d", &idServicio);
		        		 	 }


		        		 auxTrabajo.idServicio = idServicio;

		        		 //PEDIR FECHA
		 	            printf("Ingrese fecha del trabajo: dd/mm/aaaa: ");
		 	            scanf("%d/%d/%d",
		 	            		&auxTrabajo.fecha.dia,
								&auxTrabajo.fecha.mes,
								&auxTrabajo.fecha.anio);

		        		 auxTrabajo.isEmpty = 0;

		        		 trabajos[indice] = auxTrabajo;

		        		 (*pNextId)++;

		        		 retorno = 1;


		        	}
	}


	return retorno;

}





void mostrarTrabajoFila(eTrabajo trab, eMoto motos[], int tamM, eServicio servicios[], int tamS)
{
	char descripcionMoto[20];
	char descripcionServicio[20];
	//eFecha fechaTrabajo;

	cargarDescripcionMoto(motos, tamM, trab.idMoto, descripcionMoto);
	cargarDescripcionServicio(servicios, tamS, trab.idServicio, descripcionServicio);



	printf("    %d    %16s      %16s    %6d/%02d/%02d\n",
			trab.id,
			descripcionMoto,
			descripcionServicio,
			trab.fecha.dia,
			trab.fecha.mes,
			trab.fecha.anio
      	  	  	  	  	  );

}




int listarTrabajos(eTrabajo trabajos[], int tamT, eMoto motos[], int tamM, eServicio servicios[], int tamS)
{
    int retorno = 0;
    int flag = 1;
    if( trabajos != NULL && tamT > 0)
    {
        //system("cls");
        printf("       			  *** Listado de Trabajos ***\n");
        printf("------------------------------------------------------------------------------\n");
        printf("   ID               Moto               Servicio          Fecha\n");
        printf("------------------------------------------------------------------------------\n");
        for(int i=0; i < tamT; i++)
        {
            if( !trabajos[i].isEmpty)
            {

                mostrarTrabajoFila(trabajos[i], motos, tamM, servicios, tamS);
                flag = 0;
            }
        }
        printf("------------------------------------------------------------------------------\n");
        if(flag)
        {
            printf("     No hay motos cargadas en el sistema\n\n");
        }

        retorno = 1;
    }
    return retorno;
}




int inicializarTrabajos(eTrabajo vec[], int tam)
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


int mostrarTrabajosRealizadosXMoto(eMoto motos[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCliente,eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamS)
{
		int retorno = 0;
		int idMoto;

		if( motos != NULL && tam > 0 && tipos != NULL && tamTip > 0 && colores != NULL && tamCol > 0 && clientes != NULL && tamCliente > 0)
				{
					listarMotos(motos, tam, tipos, tamTip, colores, tamCol, clientes, tamCliente);
					printf("ingrese el ID de la moto para mostrar los trabajos realizados:");
					scanf("%d",&idMoto);

				    while( !validarMoto(motos, tam, idMoto))
				      	  {
				           	   printf("Id invalido. Reingrese ID del color: ");
				           	   scanf("%d", &idMoto);
				      	  }

				    printf("       	 *** Listado de Trabajos Realizados ***\n");
			        printf("------------------------------------------------------------------------------\n");
			        printf("   ID               Moto               Servicio          Fecha\n");
			        printf("------------------------------------------------------------------------------\n");
				    for(int i=0; i<tamTrab; i++)
				    {
				    	if(!trabajos[i].isEmpty && (trabajos[i].idMoto == idMoto))
				    	{
				    		mostrarTrabajoFila(trabajos[i], motos, tam, servicios, tamS);
				    		retorno = 1;
				    	}
				    }
				}

		return retorno;
}

int sumarServiciosParaUnaMoto(eMoto motos[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCliente,eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamS, int* suma)
{
			int retorno = 0;
			int idMoto;
			int idServicio;
			*suma = 0;


			if( motos != NULL && tam > 0 && tipos != NULL && tamTip > 0 && colores != NULL && tamCol > 0 && clientes != NULL && tamCliente > 0)
					{
						listarMotos(motos, tam, tipos, tamTip, colores, tamCol, clientes, tamCliente);
						printf("ingrese el ID de la moto para mostrar los trabajos realizados:");
						scanf("%d",&idMoto);

					    while( !validarMoto(motos, tam, idMoto))
					      	  {
					           	   printf("Id invalido. Reingrese ID del color: ");
					           	   scanf("%d", &idMoto);
					      	  }

					    for(int i=0; i<tam; i++)
					    {
					    	if(!trabajos[i].isEmpty && trabajos[i].idServicio == idServicio)
					    	{
					    		idServicio = trabajos[i].idServicio;
					    		for(int j=0; j<tamS; j++)
					    		{
					    			if(servicios[j].id == idServicio)
					    			{
					    				*(suma) += servicios[j].precio;
					    				retorno = 1;
					    			}
					    		}
					    	}
					    }
					}



			return retorno;
}


//9- Pedir un servicio y mostrar las motos a las que se les realizo ese servicio y la fecha.
int mostrarMotosxServicioyFecha(eMoto motos[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCliente,eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamS)
{
			int retorno = 0;
			int idServicio;





			if( motos != NULL && tam > 0 && tipos != NULL && tamTip > 0 && colores != NULL && tamCol > 0 && clientes != NULL && tamCliente > 0)
					{
						listarServicios(servicios, tamS);
						printf("ingrese el ID del servicio para listar motos:");
						scanf("%d",&idServicio);

					    while( !validarServicio(servicios, tamS, idServicio))
					      	  {
					           	   printf("Id invalido. Reingrese ID: ");
					           	   scanf("%d", &idServicio);
					      	  }

					    for(int i=0; i<tam; i++)
					    {
					    	if(!trabajos[i].isEmpty && trabajos[i].idServicio == idServicio)
					    	{
					    		for(int j=0; j<tam; j++)
					    		{
					    			if(trabajos[i].idMoto == motos[j].id)
					    			{
					    				mostrarMotoFila(motos[i], tipos, tamTip, colores, tamCol, clientes, tamCliente);
					    				retorno = 1;
					    			}
					    		}
					    	}
					    }
					}
			return retorno;

}
