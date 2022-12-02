/* utn.c
 * Biblioteca con funciones para pedir datos al usuario y validarlos
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

static int esNumeroNegativoOFloat(char *pResultado) ;
static int isCuit(char* pArray);
static int getFloat(float *pResultado) ;
/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
static int getInt(int *pResultado);
/**
 * \brief Verifica si la cadena ingresada es char
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un char y -1 (ERROR) si no
 */
static int getChar(char *pResultado);
/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
static int getShort(short *pResultado);
/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 */
static int myGets(char *cadena, int longitud);

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 */
static int esNumerica(char *cadena);
/**
 * \brief Verifica si la cadena ingresada es char
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es stringg y 0 (falso) si no lo es
 */
static int esString(char *cadena);
//-----------------------------------------------------
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {
	int bufferInt;
	int retorno = -1;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos >= 0) {
		while (reintentos >= 0) {
			reintentos--;
			printf("%s", mensaje);
			if (!getInt(&bufferInt)) {
				if (bufferInt >= minimo && bufferInt <= maximo) {
					*pResultado = bufferInt;
					retorno = 0;
					break;
				}
			}
			printf("%s", mensajeError);
			break;
		}
	}
	return retorno;
}
int utn_getNumeroFloat(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo, int reintentos) {
	int retorno = -1;
	float bufferFloat;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos >= 0) {
		do {
			printf("%s", mensaje);

			if (!getFloat(&bufferFloat) && bufferFloat >= minimo
					&& bufferFloat <= maximo) {
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			} else {
				printf("%s", mensajeError);
				reintentos--;
			}
		} while (reintentos >= 0);
	}
	return retorno;
}

//-----------------------------------------------------
int utn_getCharacter(char *pResultado, char *mensaje, char *mensajeError,
		char minimo, char maximo, int reintentos) {
	char bufferChar;
	int retorno = -1;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos >= 0) {
		while (reintentos >= 0) {
			reintentos--;
			printf("%s", mensaje);
			if (!getChar(&bufferChar)) {
				if (bufferChar >= minimo && bufferChar <= maximo) {
					*pResultado = bufferChar;
					retorno = 0;
					break;
				}
			}
			printf("%s", mensajeError);
		}
	}
	return retorno;
}
//-----------------------------------------------------
int utn_getString(char *aResultado, char *mensaje, char *mensajeError, int len, int reintentos) {
	int retorno = -1;
	char buffer[len];
	if (aResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& reintentos >= 0) {
		do {
			printf("%s", mensaje);
			fflush(stdin);

			if (!myGets(buffer, sizeof(buffer)) && esString(buffer)) {
				strncpy(aResultado, buffer, len);
				retorno = 0;
				break;
			} else {
				printf("%s", mensajeError);
				reintentos--;
				if (reintentos < 0) {
				}
			}
		} while (reintentos >= 0);
	}

	return retorno;
}
//-----------------------------------------------------
int utn_getNumeroShort(short *pResultado, char *mensaje, char *mensajeError,
		short minimo, short maximo, int reintentos) {
	short bufferInt;
	int retorno = -1;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos >= 0) {
		while (reintentos >= 0) {
			reintentos--;
			printf("%s", mensaje);
			if (!getShort(&bufferInt)) {
				if (bufferInt >= minimo && bufferInt <= maximo) {
					*pResultado = bufferInt;
					retorno = 0;
					break;
				}
			}
			printf("%s", mensajeError);
		}
	}
	return retorno;
}

//-----------------------------------------------------

int utn_getCuit (char* pArray, int len, char* msg, char* msgError, int attempts)
{
	int retorno = -1;
	char bufferString[len];

	if(pArray != NULL && msg != NULL && msgError != NULL && attempts >= 0)
	{
		do
		{
			printf("%s\n> ", msg);
			if(myGets(bufferString, len) == 0 && isCuit(bufferString) == 1)
			{
				strncpy(pArray, bufferString, len);
				retorno = 0;
				break;
			}else if (attempts > 0)
			{
				attempts--;
				printf("%s\n", msgError);
			}else
			{
				printf("No hay mas reintentos\n");
				break;
			}
		}while (attempts >= 0);
	}
	return retorno;
}


//-----------------------------------------------------

static int getInt(int *pResultado) {
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL) {
		if (!myGets(buffer, sizeof(buffer)) && esNumerica(buffer)) {
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

static int getFloat(float *pResultado) {
	int retorno = -1;
	char buffer[4096];
	if (pResultado != NULL) {
		if (!myGets(buffer, sizeof(buffer)) && esNumeroNegativoOFloat(buffer) == 1) {
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

//-----------------------------------------------------

static int getShort(short *pResultado) {
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL) {
		if (!myGets(buffer, sizeof(buffer)) && esNumerica(buffer)) {
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}
//-----------------------------------------------------

static int getChar(char *pResultado) {
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL) {
		if (!myGets(buffer, sizeof(buffer)) && esString(buffer)) {
			strcpy(pResultado, buffer);
			retorno = 0;
		}
	}
	return retorno;
}
//-----------------------------------------------------
static int myGets(char *cadena, int longitud) {
	int retorno = -1;
	if (cadena != NULL && longitud > 0
			&& fgets(cadena, longitud, stdin) == cadena) {
		fflush(stdin);
		if (cadena[strlen(cadena) - 1] == '\n') {
			cadena[strlen(cadena) - 1] = '\0';
		}
		retorno = 0;
	}
	return retorno;
}
//-----------------------------------------------------
static int esNumerica(char *cadena) {
	int i = 0;
	int retorno = -1;
	if (cadena != NULL && strlen(cadena) > 0) {
		while (cadena[i] != '\0') {
			if (cadena[i] < '0' || cadena[i] > '9') {
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}
static int esNumeroNegativoOFloat(char *pResultado) {
	int contadorPuntos = 0;
	int retorno = 1;
	int i = 0;
	if (pResultado != NULL) {
		if (pResultado[0] == '-') {
			i = 1;
		}
		for (; pResultado[i] != '\0'; i++) {
			if (pResultado[i] == '.') {
				contadorPuntos++;
			}
			if (((pResultado[i] > '9' || pResultado[i] < '0')
					&& pResultado[i] != '.') || contadorPuntos > 1) {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
//-----------------------------------------------------
static int esString(char *cadena) {
	int i = 0;
	int retorno = -1;
	if (cadena != NULL && strlen(cadena) > 0) {
		while (cadena[i] != '\0') {
			if ((cadena[i] < 'A' || cadena[i] > 'Z')
					&& (cadena[i] < 'a' || cadena[i] > 'z')
					&& cadena[i] != ' ') {
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;

}

static int isCuit(char* pArray)
{
	int retorno;
	int counter = 0;
	if(pArray[2] == '-' && pArray[11] == '-' && pArray[12] != '\0')
	{
		retorno = 1;
		for(int i = 0; pArray[i] != '\0' ; i++)
		{
			if(pArray[i] == '-')
			{
				counter++;
			}
			if((counter > 2) || ((pArray[i] > '9' || pArray[i] < '0') && pArray[i] != '-'))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
