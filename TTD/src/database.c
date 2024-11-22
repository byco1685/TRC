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
/* Includes --------------------------------------------------------------------------------------------*/
#include "database.h"
/* End Includes ----------------------------------------------------------------------------------------*/

/* Local macros ----------------------------------------------------------------------------------------*/
#define RECORD_ENTRY_ERROR              -1
#define RECORD_OK                        0
#define LENGHT_MIN_WORD                  1
#define MAX_COLOR_VALUE                  255
#define QUANTITY_MIN_REACTIVE_ELEMENTS   1
/* End Local macros ------------------------------------------------------------------------------------*/

/* Local structs ---------------------------------------------------------------------------------------*/
/* End Local structs -----------------------------------------------------------------------------------*/

/* Typedefs --------------------------------------------------------------------------------------------*/
/* End Typedefs ----------------------------------------------------------------------------------------*/

/* Constants -------------------------------------------------------------------------------------------*/
/* End Constants ---------------------------------------------------------------------------------------*/

/* Define local variables ------------------------------------------------------------------------------*/
test_record_database_t database_comparative_table[LENGTH_DATABASE];
/* End Define local variables --------------------------------------------------------------------------*/

/* Local functions prototype ---------------------------------------------------------------------------*/
bool empty_the_database(void); //1
bool is_word_ok(char * word); //2
bool is_test_record_database_t_ok(test_record_database_t * record); //3
bool is_array_words_ok(test_record_database_t * record); //4
bool is_array_quantity_zones_ok(test_record_database_t * record); //5
bool is_rgb_ok(rgb_t color); //6
bool is_pads_ok (test_record_database_t * record); //7
bool is_reactive_element_t_ok(test_record_database_t * record); //8
bool is_record_ok(test_record_database_t * record); //9 

bool is_copy_record_in_database(test_record_database_t * record); //10
/* End local funtions prototype ------------------------------------------------------------------------*/

/* Global Variables ------------------------------------------------------------------------------------*/
/* End Global Variables --------------------------------------------------------------------------------*/

/* Configuration Parameters ----------------------------------------------------------------------------*/
/* End Configuration Parameters ------------------------------------------------------------------------*/

/* Queues, TaskHandles and Active Objects --------------------------------------------------------------*/
/* End Queues, TaskHandles and Active Objects ----------------------------------------------------------*/

/* Interrupt Service Routines (ISR) --------------------------------------------------------------------*/
/* End Interrupt Service Routines (ISR) ----------------------------------------------------------------*/

/* Local Functions -------------------------------------------------------------------------------------*/
/**
 * @brief Inicializa la base de datos estableciendo todos los registros en un estado vacío.
 * 
 * Esta función recorre la tabla comparativa de la base de datos y establece todos los registros en su 
 * estado inicial, es decir, todos los bytes se configuran a cero.
 * 
 * @return true Si la base de datos fue inicializada exitosamente.
 * @return false Si la inicialización de la base de datos falló. 
 */
bool empty_the_database(void)
{
    return(memset(database_comparative_table, 0, sizeof(test_record_database_t)* LENGTH_DATABASE));
}

/**
 * @brief Verifica si una palabra cumple con la longitud mínima requerida
 * 
 * Esta función evalúa la longitud de la cadena proporcionada y determina si cumple con un requisito de
 * longitud mínima definido por `LENGTH_MIN_WORD`.
 *
 * @param word Puntero a la cadena de caracteres que representa la palabra a evaluar. 
 * 
 * @return true Si la palabra tiene una longitud mayor o igual a `LENGTH_MIN_WORD`.
 * @return false Si la palabra tiene una longitud menor a `LENGTH_MIN_WORD`.
 */
bool is_word_ok(char * word)
{
  return (strlen(word) >= LENGHT_MIN_WORD); 
}

/**
 * @brief Verifica que los nombres de proveedor y nombre general del test cumplan con la longitud 
 * mínima de caracteres. 
 * 
 * Esta función comprueba que tanto el nombre del proveedor de las tiras reactivas 
 * (`name_reagent_strip_supplier`) como el nombre general del test (`name_global_test`) dentro de la 
 * estructura `test_record_database_t` cumplan con la longitud mínima requerida de caracteres.
 * 
 * @param record puntero a la estructura `test_record_database_t` que contiene los nombres a evaluar.
 * 
 * @return true Si ambos nombres cumplen el mínimo de caracteres. 
 * @return false Si alguno de los nombres no cumple con el mínimo de caracteres.
 */
bool is_test_record_database_t_ok(test_record_database_t * record)
{
  return
  (
    is_word_ok(record->name_reagent_strip_supplier) &&
    is_word_ok(record->name_global_test)
  ); 
}

/**
 * @brief Verifica la validez de los nombres de los elementos reactivos en un registro.
 * 
 * Esta función recorre un arreglo de elementos reactivos dentro de la estructura `test_record_database_t`
 * y verifica que cada campo de `name_test` declarado en quantity_reactive_elements esté ok.
 * 
 * @param record Puntero a la estructura `test_record_database_t` que contiene el arreglo de elementos 
 * reactivos a evaluar.
 * 
 * @return true Si todos los nombres cumplen con la longitud mínima y sus posiciones son válidas.
 * @return false Si algún nombre no cumple con la longitud mínima o si alguna posición es inválida.
 */
bool is_array_words_ok(test_record_database_t * record)
{
  for(int i = 0; i < record->quantity_reactive_elements; i++)
  {
    bool word = is_word_ok(record->reactive_elements_array[i].name_test);

    if(!word)
    {
      return false;
    }
  }
    return true;
}

/**
 * @brief Verifica la validez de la cantidad de zonas de reacción en los elementos reactivos de un registro.
 * 
 * Esta función recorre el arreglo de elementos reactivos dentro de la estructura `test_record_database_t`
 * y comprueba que la cantidad de zonas de reacción (`quantity_reaction_zones`) de cada elemento esté dentro
 * de los límites permitidos, definidos por `QUANTITY_MIN_PADS` y `QUANTITY_MAX_TEST_PADS`.
 * 
 * @param record Puntero a la estructura `test_record_database_t` que contiene el arreglo de elementos 
 * reactivos a evaluar.
 * 
 * @return true Si todos los elementos reactivos tienen una cantidad de zonas de reacción dentro de los 
 * límites permitidos.
 * @return false Si algún elemento reactivo tiene una cantidad de zonas de reacción fuera de los límites 
 * permitidos.
 */
bool is_array_quantity_zones_ok (test_record_database_t * record)
{
  for(int i = 0; i < record->quantity_reactive_elements; i++)
  {
    if(record->reactive_elements_array[i].quantity_reaction_zones < QUANTITY_MIN_PADS ||
     record->reactive_elements_array[i].quantity_reaction_zones > QUANTITY_MAX_TEST_PADS)
     {
      return false;
     }
  }
  return true;
}

/**
 * @brief Verifica si los componentes de color RGB están dentro del rango permitido.
 * 
 * Esta función comprueba si los valores de los componentes rojo (`red`), verde (`green`) 
 * y azul (`blue`) de un color están dentro del rango permitido, definido por `MAX_COLOR_VALUE`.
 * 
 * @param color Estructura `rgb_t` que contiene los valores de los componentes de color RGB a evaluar.
 * 
 * @return true Si todos los componentes de color (rojo, verde y azul) están dentro del rango permitido.
 * @return false Si alguno de los componentes de color excede el valor máximo permitido.
 */
bool is_rgb_ok(rgb_t color)
{
  return(color.blue <= MAX_COLOR_VALUE && color.green <= MAX_COLOR_VALUE && color.red <= MAX_COLOR_VALUE);
}

/**
 * @brief Verifica la validez del nombre de la zona reactiva y su componente RGB de un registro.
 * 
 * Esta función recorre los elementos reactivos dentro de la estructura `test_record_database_t` y
 * verifica la validez de cada una de sus zonas de reacción (`pads`). Para cada zona de reacción, la 
 * función comprueba lo siguiente:
 * 
 * - Que los valores de color RGB estén dentro del rango permitido, utilizando la función `is_rgb_ok`.
 * - Que el nombre de la zona de reacción (`reaction_pad`) cumpla con la longitud mínima requerida, 
 *   utilizando la función `is_word_ok`.
 * 
 * @param record Puntero a la estructura `test_record_database_t` que contiene los elementos reactivos 
 * y sus zonas de reacción a evaluar.
 * 
 * @return true Si todas las zonas de reacción en todos los elementos reactivos son válidas.
 * @return false Si alguna zona de reacción tiene valores RGB fuera del rango permitido o si el nombre no 
 * cumple con la longitud mínima.
 */
bool is_pads_ok (test_record_database_t * record)
{
  for(int i = 0; i < record->quantity_reactive_elements; i++)
  {
    for(int j = 0; j < record->reactive_elements_array[i].quantity_reaction_zones; j++)
    {
      if(!is_rgb_ok(record->reactive_elements_array[i].pads_array[j].rgb) || 
         !is_word_ok(record->reactive_elements_array[i].pads_array[j].reaction_pad))
      {
        return false;
      }
    }
  }
  return true;
}

/**
 * @brief Verifica la validez de los elementos reactivos en una estructura `test_record_database_t`.
 *
 * Esta función se asegura de que la cantidad de elementos reactivos en la estructura 
 * `test_record_database_t` esté dentro de un rango válido y que las zonas asociadas cumplan con 
 * criterios de validación adicionales.
 *
 * @param[in] record Puntero a la estructura `test_record_database_t` que contiene 
 * los elementos reactivos y la información relacionada a validar.
 *
 * @return `true` si la estructura `test_record_database_t` es válida, `false` en caso contrario.
 *
 * La función realiza las siguientes verificaciones:
 * - La cantidad de elementos reactivos (`quantity_reactive_elements`) está dentro de los
 *   límites definidos por `QUANTITY_MAX_REACTIVE_ELEMENTS` y `QUANTITY_MIN_REACTIVE_ELEMENTS`.
 * - La validez de las palabras almacenadas en el arreglo (función `is_array_words_ok`).
 * - La validez de las cantidades de zonas asociadas a los elementos reactivos (función `is_array_quantity_zones_ok`).
 * - La validez de las almohadillas relacionadas con los elementos reactivos (función `is_pads_ok`).
 */
bool is_reactive_element_t_ok(test_record_database_t * record)
{
  if(record->quantity_reactive_elements > QUANTITY_MAX_REACTIVE_ELEMENTS || 
  record->quantity_reactive_elements < QUANTITY_MIN_REACTIVE_ELEMENTS)
  {
    return false;
  }
  if(!is_array_words_ok(record) ||   
    !is_array_quantity_zones_ok(record) ||
    !is_pads_ok(record))
  {
    return false;
  }
  return true;
}

/**
 * @brief  Verifica la validez general de el registro `test_record_database_t`.
 * 
 * @param record Puntero a la estructura `test_record_database_t` que contiene los elementos reactivos
 *  y la información relacionada a validar.
 * 
 * @return true Si los datos están dentro de los limites.
 * @return false Si los datos no están dentro de los limites.
 */
bool is_record_ok(test_record_database_t * record)
{
  return (is_test_record_database_t_ok(record) &&
  is_reactive_element_t_ok(record));
}
//TODO: Este codigo verificará si hay espacio en la base de datos. 
bool is_copy_record_in_database(test_record_database_t * record){

}
/* End Local Functions ---------------------------------------------------------------------------------*/

/* Global functions ------------------------------------------------------------------------------------*/
bool init_database(void)
{
   return (empty_the_database());
}

int create_database_record(test_record_database_t * record)
{
  //verifica que el registro a grabar esté ok. 
  if(!is_record_ok(record))
  {
    return RECORD_ENTRY_ERROR;
  }

  if(!is_copy_record_in_database(record)){

  }

   return RECORD_OK; 
}
/* End Global functions --------------------------------------------------------------------------------*/