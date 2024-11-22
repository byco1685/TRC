/*
 * MIT License
 *
 * Copyright (c) [2024] By_Co
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this 
 * software and associated documentation files (the "Software"), to deal in the Software 
 * without restriction, including without limitation the rights to use, copy, modify, 
 * merge, publish, distribute, sublicense, and/or sell copies of the Software, and to 
 * permit persons to whom the Software is furnished to do so, subject to the following 
 * conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or 
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR 
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE 
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT 
 * OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR 
 * OTHER DEALINGS IN THE SOFTWARE.
 * 
 * Granted by By_Co.
 */

#ifndef DATABASE_H
#define DATABASE_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ---------------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
/* End Includes -----------------------------------------------------------------------*/

/* Macros -----------------------------------------------------------------------------*/
#define LENGTH_DATABASE                 250
#define LENGHT_MAX_NAME_TEST            100
#define LENGTH_MAX_NAME_GLOBAL_TEST     100       
#define LENGTH_NAME_STRIP_SUPPLIER      100
#define LENGTH_NAME_TEST_PAD            50
#define QUANTITY_MAX_TEST_PADS          10
#define QUANTITY_MAX_REACTIVE_ELEMENTS  15
#define QUANTITY_MIN_PADS               1
/* End Macros -------------------------------------------------------------------------*/
/* Typedefs ---------------------------------------------------------------------------*/
typedef struct rgb{
    uint16_t red;
    uint16_t green;
    uint16_t blue;
}rgb_t;

typedef struct pads{
    rgb_t rgb;
    char reaction_pad[LENGTH_NAME_TEST_PAD];
}pads_t;


typedef struct reactive_elements{   
    char name_test[LENGHT_MAX_NAME_TEST];
    uint8_t quantity_reaction_zones;
    pads_t pads_array[QUANTITY_MAX_TEST_PADS];
}reactive_element_t;

typedef struct test_record_database{
    char name_global_test[LENGTH_MAX_NAME_GLOBAL_TEST];
    char name_reagent_strip_supplier[LENGTH_NAME_STRIP_SUPPLIER];
    uint8_t quantity_reactive_elements;
    reactive_element_t reactive_elements_array[QUANTITY_MAX_REACTIVE_ELEMENTS]; 
}test_record_database_t;


/* End Typedefs -----------------------------------------------------------------------*/

/* Constants --------------------------------------------------------------------------*/
/* End Constants ----------------------------------------------------------------------*/

/* Global Variables -------------------------------------------------------------------*/
/* End Global Variables ---------------------------------------------------------------*/

/* Function Prototypes ----------------------------------------------------------------*/
/**
 * @brief Inicializa la base de datos estableciendo todos los registros en un estado vacío.
 * 
 * Esta función se encarga de preparar la base de datos para su uso, 
 * asegurándose de que todos los registros se encuentren en un estado inicial vacío.
 * Es crucial llamar a esta función antes de intentar almacenar o recuperar 
 * datos para evitar inconsistencias.
 * 
 * @return true Si se inicializó la base de datos con éxito.
 * @return false Si hubo un error al intentar inicializar la base de datos.
 *
 * @note Si la función retorna `false`, es posible que haya un problema 
 * con la configuración inicial o con la disponibilidad de recursos.
 */
bool init_database();

/**
 * @brief Create a record db ctr object
 * 
 * @param record 
 * @return int 
 * - (-1) Si el registro a ingresar no es  
 */
int create_database_record(test_record_database_t * record);
/* End Function Prototypes ------------------------------------------------------------*/

/* Preprocessor directives ------------------------------------------------------------*/
#if  QUANTITY_MAX_TEST_PADS < 1 
#error "QUANTITY_MIN_TEST_PADS MUST BE LESS OR EQUAL THAT 1"
#endif

/* End preprocessor directives --------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif/* DATABASE_h */
