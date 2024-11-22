
#include "unity.h"
#include "database.h"
#include "database.c"
//extern struct_database_ts database[LENGTH_DATABASE]; 

/**
 * @brief Configuración de objeto:
 * 
 * inicialización de la base de datos.
 * 
 */
void setUp(void) {
  init_database();
}

/**
 * @brief Verifica la inicialización de la base de datos. 
 *  
 */
void test_init_database(void){
  TEST_ASSERT_TRUE(init_database());
}
/* Test Local Functions ------------------------------------------------------*/

void test_is_word_ok(void)
{
  comparative_table_record_t test_log = 
  {
    .name_global_test = "",
    .name_reagent_strip_supplier = "This text is Ok"
  };
  TEST_ASSERT_FALSE(is_comparative_table_record_t_ok(&test_log));
  TEST_ASSERT_TRUE(is_word_ok(test_log.name_reagent_strip_supplier));
}


void test_is_array_word_ok(void){
  comparative_table_record_t test_log = {
    .quantity_reactive_elements = 2,
    .reactive_elements_array =
    {
      [0] = {
        .name_test = ""
      },
      [1] ={
        .name_test = "This text is OK"
      }
    }
  };
  TEST_ASSERT_FALSE(is_array_words_ok(&test_log)); 
  strcpy(test_log.reactive_elements_array[0].name_test, "This text is Ok");
  TEST_ASSERT_TRUE(is_array_words_ok(&test_log)); 
}

void test_is_array_quantity_zones_ok(void){
  comparative_table_record_t test_log = {
    .quantity_reactive_elements = 2,
    .reactive_elements_array = {
      [0] = {
        .quantity_reaction_zones = 50
      },
      [1] =  {
        .quantity_reaction_zones = 1
      }
    }
  };

  TEST_ASSERT_FALSE(is_array_quantity_zones_ok(&test_log));
  test_log.reactive_elements_array[0].quantity_reaction_zones = 2; 
  TEST_ASSERT_TRUE(is_array_quantity_zones_ok(&test_log));
}

void test_is_pads_ok(void){
  comparative_table_record_t test_log = {
    .name_global_test = "kkkj",
    .name_reagent_strip_supplier = "mkjh",
    .quantity_reactive_elements = 2 ,
    .reactive_elements_array = {
      [0] = {
        .quantity_reaction_zones = 1,
        .name_test = "lkkl",
        .pads_array = { 
          [0] = {
            .reaction_pad = "khgf",
            .rgb = {
              .blue = 20,
              .green = 0,
              .red = 250
            }
          },
          [1] = {
            .reaction_pad = "olo",
            .rgb = {
              .blue = 10,
              .green = 25,
              .red = 54
            }
          }
        }
      },
      [1] = {
        .name_test = "dfdf",
        .quantity_reaction_zones = 1,
        .pads_array = {
        [0] = {
          .reaction_pad = "ffff",
          .rgb = {
            .blue = 250,
            .green = 200,
            .red = 0
          }
        }
        }
        
      }
    }
  };

  //  TEST_ASSERT_TRUE(is_comparative_table_record_t_ok(&test_log));
  // TEST_ASSERT_FALSE(is_pads_ok(&test_log));
  // test_log.reactive_elements_array[0].pads_array[1].rgb.blue = 200;
  // strcpy(test_log.reactive_elements_array[0].pads_array[1].reaction_pad, "This text is Ok");
  // TEST_ASSERT_TRUE(is_pads_ok(&test_log));
  TEST_ASSERT_TRUE(is_record_ok(&test_log));
}

/* End local functions ------------------------------------------------------*/

// bool is_record_ok(comparative_table_record_t * record);

// bool is_reactive_elements_t_ok(comparative_table_record_t * record);
// bool is_reactive_elements_array_ok(comparative_table_record_t * record);

 <th name="th_image" class="text-center" style="width: 30mm;">Imagen</th>

                 <td name="td_image" class="text-center">
                    <span t-field="line.x_studio_related_field_2v0_1hge6p2jv" t-options-widget="'image'" t-options-qweb_img_raw_data="1"/>
                    <br/>
                  </td>