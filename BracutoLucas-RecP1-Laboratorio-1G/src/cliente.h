/*
 * cliente.h
 *
 *  Created on: 1 dic. 2022
 *      Author: Lucasdamiann
 */


#ifndef CLIENTE_H_
#define CLIENTE_H_


#define CANT_CLIENTE 50
#define MSJ_OPCION_MENU  "\n\n---[ SELECCIONE UNA OPCION ]---\n[1]  -> ALTA DE CLIENTE\n[2]  -> MODIFICAR DATOS DE CLIENTE\n[3]  -> BAJA DE CLIENTE\n[4]  -> PRESTAMO\n[5]  -> SALDAR PRESTAMO\n[6]  -> REANUDAR PRESTAMO\n[7]  -> IMPRIMIR CLIENTES\n[8]  -> IMPRIMIR PRESTAMOS\n[9]  -> INFORMAR CLIENTES\n[10] -> INFORMAR PRESTAMOS\n[11] -> SALIR\n\n[OPCION SELECCIONADA]>> "
typedef struct{
	int id;
	char nombre[50];
	char apellido[50];
	char cuil[40];
	int isEmpty;
}eCliente;

#endif /* CLIENTE_H_ */
int cliente_inicializarEstructura(eCliente cliente[], int len);
int cliente_buscarLibre(int *pIndice, eCliente cliente[], int len);
int cliente_darAlta(eCliente cliente[], int len);
void cliente_mostrarLista(eCliente cliente[], int len);
int cliente_buscarPorId(int *pIndice, eCliente cliente[], int len, int id);
int cliente_darModificacion(eCliente cliente[], int len);
int cliente_darBaja(eCliente cliente[], int len, int id);
int cliente_verificarExistencia(eCliente cliente[], int len, int id);

