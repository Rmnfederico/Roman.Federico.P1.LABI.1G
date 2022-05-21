/* ********************************************************
//////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

Desarrollar en ANSI C:
Se necesita gestionar un Service de motos y para eso se deberá desarrollar lo siguiente:

ENTIDADES:

Fecha:
• dia
• mes
• año

Tipo:
• id (comienza en 1000)
• descripción (máx 20 caracteres)

Color:
• id (comienza en 10000)
• nombreColor(máx 20 caracteres)

Moto:
• id
• marca (máx 20 caracteres)
• idTipo Validar
• idColor Validar
• cilindrada
• puntaje( 1 a 10)

Servicio:
• id(comienza en 20000)
• descripción (máximo 25 caracteres)
• precio

Trabajo:
• id (autoincremental)
• idMoto (debe existir) Validar
• idServicio (debe existir) Validar
• fecha ( Validar día, mes y año)



DATOS PREVIOS:
Los arrays de tipos, color y servicios deberán ser hardcodeados.
Tipos (Enduro, Chopera, Scooter, Vintage)
Colores (Gris, Negro, Azul, Blanco, Rojo)
Servicios (Limpieza: $450, Ajuste: $300, Balanceo: $150, Cadena: $390)
Las cilindradas pueden ser: 50, 125, 500, 600, 750



MENU DE OPCIONES:
A. ALTA MOTO
B. MODIFICAR MOTO: Se ingresara el id, permitiendo en un submenu modificar:

- Color
- Puntaje

C. BAJA MOTO: Se ingresara el id de la moto y se realizara una baja logica.
D. LISTAR MOTOS: Hacer un único listado de todas las motos ordenadas por tipo y id.
E. LISTAR TIPOS
F. LISTAR COLORES
G. LISTAR SERVICIOS
H. ALTA TRABAJO: Se dara de alta cada ocurrencia de trabajo pidiéndole al usuario que elija una moto
y un Servicio
I. LISTAR TRABAJOS

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
 *
 * 	1- Mostrar las motos del color seleccionado por el usuario.
	2- Informar el promedio de puntaje de un tipo seleccionado por el usuario.
	3- Informar la o las motos de mayor cilindrada.
	4- Mostrar un listado de las motos separadas por tipo. 			//////////////////
	5- Elegir un color y un tipo y contar cuantas motos hay de ese color y ese tipo.
	6- Mostrar el o los colores más elegidos por los clientes.
	7- Pedir una moto y mostrar todos los trabajos que se le hicieron a la misma.
	8- Pedir una moto e informar la suma de los importes de los servicios que se le hicieron a la
	   misma.


	9- Pedir un servicio y mostrar las motos a las que se les realizo ese servicio y la fecha.
	10- Pedir una fecha y mostrar todos los servicios realizados en la misma.

	Bonus Track
	Hardcodear algunos trabajos

 *
 *
 *
 *
 *
 *
********************************************************  */

#include <stdio.h>
#include <stdlib.h>

#define TAM_T 4
#define TAM_C 5
#define TAM_S 4
#define TAM_M 20
#define TAM_TR 20
#define TAM_CL 10


//#include "motos.h"
//#include "tipo.h"
//#include "color.h"
//#include "servicio.h"
#include "trabajo.h"


int main()
{
	setbuf(stdout, NULL);

    //Hardcodeo de IDs iniciales
	int idServicios = 20000;
    int idColores = 10000;
    int idTipos = 1000;
    int idMotos = 1;
    int idTrabajos = 1;
    int idClientes = 3000;

    //Declaracion array por c/ struct
    eTipo arrayTipos[TAM_T];
    eColor arrayColores[TAM_C];
    eServicio arrayServicios[TAM_S];
    eMoto arrayMotos[TAM_M];
    eTrabajo arrayTrabajos[TAM_TR];

    eCliente arrayClientes[TAM_CL];


    int opcionMenu;
    float promedio;
    int contadorMotos;
    int suma;


    inicializarMotos(arrayMotos, TAM_M);
    hardcodearMotos(arrayMotos, TAM_M, 10, &idMotos);

    hardcodearTipos(arrayTipos, TAM_T, 4, &idTipos);
    hardcodearColores(arrayColores, TAM_C, 5, &idColores);
    hardcodearServicios(arrayServicios, TAM_S, 4, &idServicios);

    inicializarTrabajos(arrayTrabajos, TAM_TR);
    hardcodearTrabajos(arrayTrabajos, TAM_TR, 10, &idTrabajos);

    hardcodearClientes(arrayClientes, TAM_CL, 10, &idClientes);




//Casos 8 y 9
//Validaciones de -->
    //puntaje (int & max/min) -Parseado desde string
    //Cilindrada (array de ints) -Parseado desde string
    //Fecha (31 dias, 12 meses, de 1980 a 2022)
    //


    do
    {
        menuMotos(&opcionMenu);

        switch(opcionMenu)
        {
            case 1:

             if(altaMoto(arrayMotos, TAM_M, arrayTipos, TAM_T, arrayColores, TAM_C, arrayClientes, TAM_CL, &idMotos))
            {
                printf("Moto cargada con exito!\n\n");
            }
            else
            {
                printf("No se pudo cargar el dato.\n\n");
            }

            break;

            case 2:
            	modificarMoto(arrayMotos, TAM_M,arrayTipos, TAM_T, arrayColores, TAM_C, arrayClientes, TAM_CL);
            break;

            case 3:
            	bajaMoto(arrayMotos, TAM_M, arrayTipos, TAM_T, arrayColores, TAM_C, arrayClientes, TAM_CL);
            break;

            case 4:
            	listarMotos(arrayMotos, TAM_M, arrayTipos, TAM_T, arrayColores, TAM_C, arrayClientes, TAM_CL);
            break;

            case 5:
            	listarTipos(arrayTipos, TAM_T);
            break;

            case 6:
            	listarColores(arrayColores, TAM_C);
            break;

            case 7:
            	listarServicios(arrayServicios, TAM_S);
            break;

            case 8:
            	altaTrabajo(arrayTrabajos, TAM_TR, arrayMotos, TAM_M, arrayServicios, TAM_S, arrayTipos, TAM_T, arrayColores, TAM_C, arrayClientes, TAM_CL, &idTrabajos);
            break;

            case 9:
            	listarTrabajos(arrayTrabajos, TAM_TR, arrayMotos, TAM_M, arrayServicios, TAM_S);
            break;

            case 10:
            	listarMotosPorColor(arrayMotos, TAM_M, arrayTipos, TAM_T, arrayColores, TAM_C, arrayClientes, TAM_CL);
            break;

            case 11:
            	if(promedioPuntajePorTipo(arrayMotos, TAM_M, arrayTipos, TAM_T, arrayColores, TAM_C, arrayClientes, TAM_CL, &promedio))
            	{
            		printf("El promedio para ese tipo es: %.2f\n", promedio);
            	}else
            	{
            		printf("No hay motos cargadas para ese tipo.\n\n");
            	}

            break;

            case 12:
            	listarMotosMayorCilindrada(arrayMotos, TAM_M, arrayTipos, TAM_T, arrayColores, TAM_C, arrayClientes, TAM_CL);
            break;

            case 13:

            break;

            case 14:
            	if(contarMotosPorTipoyColor(arrayMotos, TAM_M, arrayTipos, TAM_T, arrayColores, TAM_C, arrayClientes, TAM_CL, &contadorMotos))
            	{
            		printf("La cantidad de motos es: %d\n\n", contadorMotos);
            	}else
            	{
            		printf("No hubo motos para contar con esas caracteristicas.\n\n");
            	}
            break;

            case 15:

            break;

            case 16:
            	mostrarTrabajosRealizadosXMoto( arrayMotos,  TAM_M, arrayTipos, TAM_T, arrayColores, TAM_C, arrayClientes, TAM_CL, arrayTrabajos,TAM_TR ,  arrayServicios, TAM_S);

            break;

            case 17:
            	sumarServiciosParaUnaMoto(arrayMotos,TAM_M, arrayTipos, TAM_T, arrayColores, TAM_C, arrayClientes, TAM_CL, arrayTrabajos,TAM_TR ,  arrayServicios, TAM_S, &suma);

            break;

            case 18:
            	mostrarMotosxServicioyFecha(arrayMotos,TAM_M, arrayTipos, TAM_T, arrayColores, TAM_C, arrayClientes, TAM_CL, arrayTrabajos,TAM_TR ,  arrayServicios, TAM_S);
            break;

            case 19:
            break;

            case 20:
            	printf("Programa finalizado.\n");
            break;

        }
        //system("pause");

    }while(opcionMenu != 20);



    return 0;
}

