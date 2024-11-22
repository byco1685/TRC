#include "src/database.c"
#include "src/database.h"
#include "C:/Users/royer.sanabria/.local/share/gem/ruby/3.1.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"




void setUp(void) {

  init_database();

}









 void test_header_database_record(void)

 {



    test_record_database_t test_log;

    UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((create_database_record(&test_log))), (

   ((void *)0)

   ), (UNITY_UINT)(17), UNITY_DISPLAY_STYLE_INT);



    strcpy(test_log.name_global_test, "Nombre general del test");

    strcpy(test_log.name_reagent_strip_supplier, "Nombre del proveedor de tiras reactivas");



    UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((create_database_record(&test_log))), (

   ((void *)0)

   ), (UNITY_UINT)(22), UNITY_DISPLAY_STYLE_INT);



    test_log.quantity_reactive_elements = 1;

    UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((create_database_record(&test_log))), (

   ((void *)0)

   ), (UNITY_UINT)(25), UNITY_DISPLAY_STYLE_INT);



    strcpy(test_log.reactive_elements_array[0].name_test, "Nombre del reactivo a analizar");

    test_log.reactive_elements_array[0].quantity_reaction_zones = 1;

    strcpy(test_log.reactive_elements_array[0].pads_array->reaction_pad, "Descripcin de la reaccin");

    test_log.reactive_elements_array[0].pads_array[0].rgb.blue = 10;

    test_log.reactive_elements_array[0].pads_array[0].rgb.green = 80;

    test_log.reactive_elements_array[0].pads_array[0].rgb.red = 10;

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((create_database_record(&test_log))), (

   ((void *)0)

   ), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_INT);

 }
