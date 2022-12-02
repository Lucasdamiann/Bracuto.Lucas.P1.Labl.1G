#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "prestamos.h"
#include "utn.h"


static int cliente_autoIncrementarId();
int cliente_inicializarEstructura(eCliente cliente[], int len) {
	int retorno = -1;
	if (cliente != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			cliente[i].isEmpty = 1; //1 es vacio
		}
		retorno = 0;
	}

	return retorno;
}

/**
*\brief: Busca una confederacion libre y devuelve su indice
*\param: eJugador jugador[] array de tipo eJugador
*\param: int len
*\param: int* pIndice puntero a entero
*\return:  int 0 si Ok, -1 si Nok
**/
int cliente_buscarLibre(int *pIndice, eCliente cliente[], int len) {
	int retorno = -1;
	int indice = -1;
	if (pIndice != NULL && cliente != NULL && len > 0) {

		for (int i = 0; i < len; i++) {
			if (cliente[i].isEmpty) {
				indice = i;
				retorno = 0;
				break;
			}
		}
		*pIndice = indice;
	}
	return retorno;
}

int cliente_darAlta(eCliente cliente[], int len) {
	int retorno = -1;
	int indice;
	eCliente auxiliar;
	if (cliente != NULL && len > 0) {
		if(!cliente_buscarLibre(&indice, cliente, len))
		{
			if (indice == -1)
			{
				printf("No hay lugar");
			}
			else
			{
				auxiliar.id = cliente_autoIncrementarId();

				cliente[indice].id = auxiliar.id;

				if(!utn_getString(auxiliar.nombre, "Ingrese nombre: \n>", "ERROR", 50, 3)
						&& !utn_getString(auxiliar.apellido, "Ingrese apellido: \n>", "ERROR", 50, 3)
						&& !utn_getCuit(auxiliar.cuil, 50, "Ingrese C.U.I.L. : \n>", "ERROR", 3))
				{
					{
						auxiliar.isEmpty = 0;
						cliente[indice] = auxiliar;

						retorno = 0;
					}
				}
			}
		}
	}
	return retorno;
}


static int cliente_autoIncrementarId() {
	static int idInicial = 1000;
	return idInicial++;
}

void cliente_mostrarLista(eCliente cliente[], int len) {
	if (cliente != NULL && len > 0 ) {
		printf(
				"============================================================================\n"
				"|  ID   |         NOMBRE            |       APELLIDO         |    C.U.I.L. |\n"
				"----------------------------------------------------------------------------\n");
		for (int i = 0; i < len; i++) {
				if (!cliente[i].isEmpty) {
					printf(	"| %-5d | %-20s | %-20s|     %-15s   |\n",	cliente[i].id, cliente[i].nombre,
							cliente[i].apellido, cliente[i].cuil);
					break;
				}
			}
		}
		printf(
				"=================================================================\n");
	}


/**
*\brief: Busca un cliente  por id y devuelve si existe
*\param: eCliente cliente[] array de tipo eCliente
*\param: int len
*\param: int id
*\return:  int 0 si Ok, -1 si Nok
**/
int cliente_verificarExistencia(eCliente cliente[], int len, int id) {
	int retorno = -1;
	if (cliente != NULL && len > 0 && id >= 1000	&& id < 1050) {
		for (int i = 0; i < len; i++)
		{
			if (cliente[i].id == id && cliente[i].isEmpty == 0) {

				retorno = 0;
				break;
			}
		}

	}
	return retorno;
}

/**
*\brief: Busca un cliente  por id y devuelve su indice
*\param: eCliente cliente[] array de tipo eCliente
*\param: int len
*\param: int* pIndice puntero a entero
*\param: int id
*\return:  int 0 si Ok, -1 si Nok
**/
int cliente_buscarPorId(int *pIndice, eCliente cliente[], int len, int id) {
	int retorno = -1;
	int indice=-1;
	if (pIndice != NULL && cliente != NULL && len > 0 && id >= 1000	&& id < 1050) {
		for (int i = 0; i < len; i++)
		{
			if (cliente[i].id == id && cliente[i].isEmpty == 0) { //
				indice = i;

				retorno = 0;
				break;
			}
		}*pIndice=indice;
	}
	return retorno;
}


/**
*\brief: Modificar parametros de entidad eCliente
*\param: eCliente* this array de tipo eCliente
*\param: int len
*\return:  int 0 si Ok, -1 si Nok
**/
int cliente_darModificacion(eCliente cliente[], int len) {
	int retorno = -1;
	int indice=0;
	int opcion;
	int idModificar;
	eCliente auxiliar;
	if (cliente != NULL && len > 0) {


	if(!utn_getNumero(&idModificar,"INGRESE ID DE CLIENTE: ",	"ERROR DE SELECCCION\n", 1000, 1050, 3))
	{

			if (!cliente_buscarPorId(&indice,cliente, len, idModificar))
			{
				auxiliar = cliente[indice];
				do{
					if(!utn_getNumero(&opcion,"\n1-NOMBRE.\n2-APELLIDO.\n3-N°C.U.I.L.\n4-SALIR\n#Opcion: \n",	"ERROR DE SELECCION\n", 1, 4, 3))
					{
						switch (opcion)
						{
						case 1:
							if (!utn_getString(auxiliar.nombre, "INGRESAR NOMBRE: ",		"ERROR DE INGRESO", 50, 3)) {

								printf("Nombre Cambiado con exito\n");
							}
							break;
						case 2:
							if (!utn_getString(auxiliar.apellido, "INGRESAR APELLIDO: ",		"ERROR DE INGRESO", 50, 3)) {

								printf("Apellido Cambiado con exito\n");
								}
							break;
						case 3:
							if (!utn_getCuit(auxiliar.cuil, 50, "INGRESAR C.U.I.L.: ", "ERROR DE INGRESO", 3)) {
								printf("\nNumero de CUIL cambiado con exito\n");
							}
							break;
						}

						cliente[indice] = auxiliar;
						retorno = 0;
					}
				}while(opcion!=4);


			}else
			{
				printf("CLIENTE INEXISTENTE\n");
			}
		}

	}
	return retorno;

}


/**
*\brief: Da de baja un cliente
*\param: eCliente cliente[]
*\param: int len
*\param: int id
*\return:  int 0 si Ok, -1 si Nok
**/
int cliente_darBaja(eCliente cliente[], int len, int id) {
	int retorno = -1;
	if (cliente != NULL && len > 0 && id >= 1000) {
		for (int i = 0; i < len; i++) {
			if (cliente[i].id == id) {
				cliente[i].isEmpty = 1;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;

}


