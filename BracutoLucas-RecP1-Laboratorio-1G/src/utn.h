/*
 * utn.h
 *
 *  Created on: 8 sep. 2022
 *      Author: Lucasdamiann
 */


#ifndef UTN_H_
#define UTN_H_



/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos);
/**
 * \brief Solicita una letra al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es la letra maxima a ser aceptada
 * \param maximo Es la letra minima a ser aceptada
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getCharacter(char *pResultado, char *mensaje, char *mensajeError,
		char minimo, char maximo, int reintentos);
/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getNumeroShort(short *pResultado, char *mensaje, char *mensajeError,
		short minimo, short maximo, int reintentos);

/**
 * \brief Solicita un numero float al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado float*
 * \param mensaje char*
 * \param mensajeError char*
 * \param minimo float
 * \param maximo float
 * \param reintentos int
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getNumeroFloat(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo, int reintentos);
/**
 * \brief Solicita un string al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado char*
 * \param mensaje char*
 * \param mensajeError char*
 * \param minimo float
 * \param maximo float
 * \param reintentos int
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getString(char *pResultado, char *mensaje, char *mensajeError, int len,	 int reintentos);
int utn_getCuit (char* pArray, int len, char* msg, char* msgError, int attempts);
#endif /* UTN_H_ */
