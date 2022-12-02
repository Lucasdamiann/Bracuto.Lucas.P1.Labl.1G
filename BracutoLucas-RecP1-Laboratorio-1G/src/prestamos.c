/*
 * prestamos.c
 *
 *  Created on: 1 dic. 2022
 *      Author: Lucasdamiann
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"
#include "prestamos.h"

static int prestamo_autoIncrementarId();
static int prestamo_contarPrestamos(ePrestamo prestamo[], eCliente cliente[],int* prestamos);

int prestamo_darAlta(ePrestamo prestamo[], int len, eCliente cliente[],int lenCliente) {
	int retorno = -1;
	int indice;
	ePrestamo auxiliarPrestamo;
	if (prestamo != NULL && len > 0) {
		if(!prestamo_buscarLibre(&indice, prestamo, len))
		{
			if (indice == -1)
			{
				printf("No hay lugar");
			}
			else
			{
				auxiliarPrestamo.id = prestamo_autoIncrementarId();

				prestamo[indice].id = auxiliarPrestamo.id;

				if(!utn_getNumero(&auxiliarPrestamo.idCliente, "Ingrese el ID del cliente: ", "ERROR", 1000, 1050, 3)
						&& !cliente_verificarExistencia(cliente, len, auxiliarPrestamo.idCliente)
						&& !utn_getNumeroFloat(&auxiliarPrestamo.importe, "INGRESE IMPORTE: ", "ERROR", 1000, 10000, 3)
						&& !utn_getNumero(&auxiliarPrestamo.cuotas, "INGRESE CANTIDAD DE CUOTAS: ", "ERROR", 3, 72, 3))
				{
					{
						auxiliarPrestamo.isEmpty = 0;
						prestamo[indice] = auxiliarPrestamo;

						retorno = 0;
					}

				}
			}
		}
		prestamo_mostrar(prestamo, indice);
	}
	return retorno;
}
static int prestamo_autoIncrementarId() {
	static int idInicial = 5000;
	return idInicial++;
}


/**
*\brief: Busca una confederacion libre y devuelve su indice
*\param: eJugador jugador[] array de tipo eJugador
*\param: int len
*\param: int* pIndice puntero a entero
*\return:  int 0 si Ok, -1 si Nok
**/
int prestamo_buscarLibre(int *pIndice, ePrestamo prestamo[], int len) {
	int retorno = -1;
	int indice = -1;
	if (pIndice != NULL && prestamo != NULL && len > 0) {

		for (int i = 0; i < len; i++) {
			if (prestamo[i].isEmpty) {
				indice = i;
				retorno = 0;
				break;
			}
		}
		*pIndice = indice;
	}
	return retorno;
}
int prestamo_inicializarEstructura(ePrestamo prestamo[], int len) {
	int retorno = -1;
	if (prestamo != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			prestamo[i].isEmpty = 1; //1 es vacio
		}
		retorno = 0;
	}

	return retorno;
}

void prestamo_mostrar(ePrestamo prestamo[],int indice)
{
	if(prestamo!=NULL)
	{
		printf(
					"========================================================\n"
					"|     ID    |  ID CLIENTE  |    IMPORTE    |    CUOTAS |\n"
					"--------------------------------------------------------\n"
				"| %-5d | %-5d | %-8.2f| %-4d  |\n", prestamo[indice].id,	prestamo[indice].idCliente, prestamo[indice].importe,prestamo[indice].cuotas);

	}
}

int prestamo_saldar(ePrestamo prestamo[],eCliente cliente[])
{
	int retorno=-1;
	int idPrestamo;
	int opcion;
	int index;
	if(prestamo!=NULL && cliente !=NULL)
	{
		if(!utn_getNumero(&idPrestamo, "INGRESE ID DEL PRESTAMO: ", "ERROR", 5000, 5050, 3))
		{
			for(int i=0;i<CANT_PRESTAMO;i++)
			{
				for(int j=0;j<CANT_CLIENTE;j++)
				{
					if(prestamo[i].id==idPrestamo && prestamo[i].idCliente==cliente[j].id && cliente[j].isEmpty==0)
					{
						printf(	"============================================================================\n"
								"|  ID   |         NOMBRE            |       APELLIDO         |    C.U.I.L. |\n"
								"----------------------------------------------------------------------------\n");
						printf(	"| %-5d |          %-15s |      %-15s|     %-15s   |\n ============================================================================\n"
								,	cliente[i].id, cliente[i].nombre,cliente[i].apellido, cliente[i].cuil);
						index=i;
						break;
					}

				}
			}
			if(!utn_getNumero(&opcion, "CAMBIAR DE ESTADO A 'SALDADO'?\n1-SI,CAMBIAR\n2-NO,NO CAMBIAR\nOpcion>> ", "ERROR", 1, 2, 3) && opcion ==1)
			{
				strcpy(prestamo[index].estado,"SALDADO");
				printf("\nESTADO: %s\n",prestamo[index].estado);
			}
		}
	}
	return retorno;

}

void prestamo_mostrarLista(ePrestamo prestamo[], int len) {
	if (prestamo != NULL && len > 0 ) {
		for(int i=0;i<CANT_PRESTAMO;i++)
		{
			if(prestamo[i].isEmpty==0)
			printf(
								"========================================================\n"
								"|     ID    |  ID CLIENTE  |    IMPORTE    |    CUOTAS |\n"
								"--------------------------------------------------------\n"
							    "|     %-5d |   %-5d |    %-8.2f|     %-4d  |\n", prestamo[i].id,	prestamo[i].idCliente, prestamo[i].importe,prestamo[i].cuotas);

		}
		}
		printf(
				"=================================================================\n");
	}


int prestamo_reanudar(ePrestamo prestamo[],eCliente cliente[])
{
	int retorno=-1;
	int idPrestamo;
	int opcion;
	int index;
	if(prestamo!=NULL && cliente !=NULL)
	{
		if(!utn_getNumero(&idPrestamo, "INGRESE ID DEL PRESTAMO: ", "ERROR", 5000, 5050, 3))
		{
			for(int i=0;i<CANT_PRESTAMO;i++)
			{
				for(int j=0;j<CANT_CLIENTE;j++)
				{
					if(prestamo[i].id==idPrestamo && prestamo[i].idCliente==cliente[j].id && cliente[j].isEmpty==0)
					{
						printf(	"============================================================================\n"
								"|  ID   |         NOMBRE            |       APELLIDO         |    C.U.I.L. |\n"
								"----------------------------------------------------------------------------\n");
						printf(	"| %-5d |          %-15s |      %-15s|     %-15s   |\n ============================================================================\n"
								,	cliente[i].id, cliente[i].nombre,cliente[i].apellido, cliente[i].cuil);
						index=i;
						break;
					}

				}
			}
			if(!utn_getNumero(&opcion, "CAMBIAR DE ESTADO A 'ACTIVO'?\n1-SI,CAMBIAR\n2-NO,NO CAMBIAR\nOpcion>> ", "ERROR", 1, 2, 3) && opcion ==1)
			{
				strcpy(prestamo[index].estado,"ACTIVO");
				printf("\nESTADO: %s\n",prestamo[index].estado);
			}
		}
	}
	return retorno;

}


void prestamo_mostrarListaPrestamos(ePrestamo prestamo[], int len, eCliente cliente[], int lenC) {

	if (prestamo != NULL && len > 0 ) {
		for(int i=0;i<CANT_PRESTAMO;i++)
		{
			for(int j=0;j<CANT_CLIENTE;j++)
			{

			if(prestamo[i].isEmpty==0 && strcmp(prestamo[i].estado,"ACTIVO")==0 && prestamo[i].idCliente==cliente[j].id)
			printf(
								"======================================================================\n"
								"|     ID    |  ID CLIENTE  |    IMPORTE    |    CUOTAS |   C.U.I.L   |\n"
								"----------------------------------------------------------------------\n"
							    "|     %-5d |   %-5d |    %-8.2f|     %-4d  |    %-10s    |\n", prestamo[i].id,	prestamo[i].idCliente, prestamo[i].importe,prestamo[i].cuotas,cliente[j].cuil);
			}

		}
		}
		printf(
				"======================================================================\n");
	}

void prestamo_mostrarListaConPrestamos(eCliente cliente[], int len,ePrestamo prestamo[],int lenP) {

	int cantidadPrestamos;
	if (cliente != NULL && len > 0 ) {
		printf(
				"========================================================================================\n"
				"|  ID   |         NOMBRE            |       APELLIDO         |    C.U.I.L. | PRESTAMOS |\n"
				"----------------------------------------------------------------------------------------\n");
		for (int i = 0; i < len; i++)
		{
			for(int j=0;j<50;j++)
			{
				if (!cliente[i].isEmpty && prestamo[j].idCliente==cliente[i].id && !prestamo_contarPrestamos(prestamo, cliente, &cantidadPrestamos))
				{

					printf(	"| %-5d | %-20s | %-20s|     %-15s   |  %-4d |\n",	cliente[i].id, cliente[i].nombre,
										cliente[i].apellido, cliente[i].cuil,cantidadPrestamos);
					break;
				}
			}

			}
		}
		printf(
				"=================================================================\n");
	}



static int prestamo_contarPrestamos(ePrestamo prestamo[], eCliente cliente[],int* prestamos)
{
	int retorno=-1;
	int contadorPrestamos=0;
	if(prestamo!=NULL && cliente!=NULL)
	{

	for(int j=0;j<CANT_PRESTAMO;j++)
	{
		for(int i=0;i<CANT_CLIENTE;i++)
		{
			if(prestamo[j].idCliente==cliente[i].id && cliente[i].isEmpty==0)
			{
				contadorPrestamos++;

			}
		}
	}
				*prestamos=contadorPrestamos;
				retorno=0;
	}
	return retorno;
}


