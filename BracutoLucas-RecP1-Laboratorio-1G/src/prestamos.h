/*
 * prestamos.h
 *
 *  Created on: 1 dic. 2022
 *      Author: Lucasdamiann
 */


#ifndef PRESTAMOS_H_
#define PRESTAMOS_H_

#define CANT_PRESTAMO 50
typedef struct{
	int id;
	int idCliente;
	float importe;
	int cuotas;
	char estado[50];
	int isEmpty;
}ePrestamo;

#endif /* PRESTAMOS_H_ */
int prestamo_buscarLibre(int *pIndice, ePrestamo prestamo[], int len);
int prestamo_darAlta(ePrestamo prestamo[], int len, eCliente cliente[],int lenCliente);
int prestamo_inicializarEstructura(ePrestamo prestamo[], int len);
void prestamo_mostrar(ePrestamo prestamo[],int indice);
void prestamo_mostrarLista(ePrestamo prestamo[], int len);
int prestamo_saldar(ePrestamo prestamo[],eCliente cliente[]);
int prestamo_reanudar(ePrestamo prestamo[],eCliente cliente[]);
void prestamo_mostrarListaPrestamos(ePrestamo prestamo[], int len, eCliente cliente[], int lenC);
void prestamo_mostrarListaConPrestamos(eCliente cliente[], int len,ePrestamo prestamo[],int lenP);
void prestamo_mostrarListaConcliente(eCliente cliente[], int len,ePrestamo prestamo[],int lenP);
