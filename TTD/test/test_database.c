
#include "unity.h"
#include "database.h"
#include "database.c"

void setUp(void) {
  init_database();
}
 /**
  * Requerimientos de verificacion de registro a la base de datos. 
  * - Requerimiento  1
  */
 void test_header_database_record(void)
 {
    //
    test_record_database_t test_log;
    TEST_ASSERT_EQUAL(-1, create_database_record(&test_log));
    //
    strcpy(test_log.name_global_test, "Nombre general del test");
    strcpy(test_log.name_reagent_strip_supplier, "Nombre del proveedor de tiras reactivas");
    
    TEST_ASSERT_EQUAL(-1, create_database_record(&test_log));
    //
    test_log.quantity_reactive_elements = 1;
    TEST_ASSERT_EQUAL(-1, create_database_record(&test_log));
    //
    strcpy(test_log.reactive_elements_array[0].name_test, "Nombre del reactivo a analizar");
    test_log.reactive_elements_array[0].quantity_reaction_zones = 1;
    strcpy(test_log.reactive_elements_array[0].pads_array->reaction_pad, "Descripción de la reacción");
    test_log.reactive_elements_array[0].pads_array[0].rgb.blue = 10;
    test_log.reactive_elements_array[0].pads_array[0].rgb.green = 80;
    test_log.reactive_elements_array[0].pads_array[0].rgb.red = 10;
    TEST_ASSERT_EQUAL(0, create_database_record(&test_log));
 }

  
