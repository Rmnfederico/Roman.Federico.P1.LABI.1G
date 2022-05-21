#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;                 // (comienza en 10000)
    char descripcion[20];     //(máx 20 caracteres)


}eColor;

int hardcodearColores(eColor colores[], int tam, int cant, int* pNextId);
int listarColores(eColor colores[],int tam);
int buscarColor(eColor colores[], int tam, int id, int* pIndex);
int validarColor(eColor colores[], int tam, int id);
int cargarDescripcionColor(eColor colores[], int tam, int id, char desc[]);


#endif // COLOR_H_INCLUDED
