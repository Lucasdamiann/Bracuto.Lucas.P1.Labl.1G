/*
 ============================================================================
 Name        : BracutoLucas-RecP1-Laboratorio-1G.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "prestamos.h"
#include "utn.h"

int main() {
	setbuf(stdout, NULL);
	int comandoPrincipal;
	int flagAlta=0;
	int bajaId;
	int contador=0;
	eCliente nuevoCliente[CANT_CLIENTE];
	ePrestamo nuevoPrestamo[CANT_PRESTAMO];
	cliente_inicializarEstructura(nuevoCliente, CANT_CLIENTE);
	prestamo_inicializarEstructura(nuevoPrestamo, CANT_PRESTAMO);
	do {


			if (!utn_getNumero(&comandoPrincipal, MSJ_OPCION_MENU,	"ERROR DE SELECCION\n", 1, 10, 3))
			{
				switch (comandoPrincipal)
				{
				case 1: //alta de cliente
					printf("\n-------ALTA-------\n");

					if (!cliente_darAlta(nuevoCliente, CANT_CLIENTE))
					{

						printf("\n-------ALTA SATISFACTORIA-------\n\n");
						flagAlta = 1;
						contador++;
					}
					break;
				case 2: //modificacion de cliente
					if (flagAlta && contador>0) {
						printf("\n-------MODIFICACION-------\n");

										cliente_mostrarLista(nuevoCliente, CANT_CLIENTE);

										if (!cliente_darModificacion(nuevoCliente, CANT_CLIENTE))
										{
											printf("-------MODIFICACION REALIZADA-------\n");
											cliente_mostrarLista(nuevoCliente, CANT_CLIENTE);

										} else {
											printf("-------ALGO SALIO MAL-------\n");
										}
									} else {
										printf("\nDEBE INGRESAR UN CLIENTE PARA PODER MODIFICARLO\n");
									}
									break;
				case 3: //baja de cliente
					if (flagAlta && contador>0) {
						printf("\n-------BAJA-------\n\n");


						cliente_mostrarLista(nuevoCliente, CANT_CLIENTE);

						if (!utn_getNumero(&bajaId, "INGRESE ID DE CLIENTE: ","ID INEXISTENTE\n", 1000, 1050, 2) && !cliente_darBaja(nuevoCliente, CANT_CLIENTE, bajaId))
						{
							printf("\n-------BAJA SATISFACTORIA-------\n\n");

						}
					}
					else
					{
						printf(
								"\nDEBE INGRESAR UN CLIENTE PARA PODER ELIMINARLO\n");
					}
					break;

				case 4://crear prestamos
					if (flagAlta && contador>0) {
						printf("\nPRESTAMOS\n");
						cliente_mostrarLista(nuevoCliente, CANT_CLIENTE);
						prestamo_darAlta(nuevoPrestamo, CANT_PRESTAMO, nuevoCliente, CANT_CLIENTE);

					} else {
						printf(
								"\nDEBE INGRESAR AL MENOS UN CLIENTE PARA PODER ASIGNARLE UN PRESTAMO\n");
					}
					break;
				case 5://saldar prestamo
					prestamo_mostrarLista(nuevoPrestamo, CANT_PRESTAMO);
					if(!prestamo_saldar(nuevoPrestamo, nuevoCliente))
					{
						printf("\nPrestamo saldado\n");
					}

					break;
				case 6://reanudar prestamo
					prestamo_mostrarLista(nuevoPrestamo, CANT_PRESTAMO);
					if(!prestamo_reanudar(nuevoPrestamo, nuevoCliente))
					{
						printf("\nPrestamo reanudado\n");
					}
					break;
				case 7://imprimir cliente
					prestamo_mostrarListaConPrestamos(nuevoCliente,CANT_CLIENTE, nuevoPrestamo, CANT_PRESTAMO);


					break;
				case 8://imprimir prestamos
					prestamo_mostrarListaPrestamos(nuevoPrestamo, CANT_PRESTAMO, nuevoCliente, CANT_CLIENTE);

					break;

				}
			} else {
				printf("\nYa no hay reintentos.Saliendo del programa\n");
				break;
			}

		} while (comandoPrincipal != 11);

		return 0;
		return EXIT_SUCCESS;
	}





