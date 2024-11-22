       
# Data Structures
## `test_record_database_t` Comparative_table_record

| Field                         | Type                        | Description                                      | Related Table      |
|-------------------------------|-----------------------------|--------------------------------------------------|--------------------|
| `name_reagent_strip_supplier` | `char` array                | Nombre del proveedor de tiras reactivas          | N/A                |
| `name_global_test`            | `char` array                | Nombre general del test                          | N/A                |
| `reactive_elements_array`     | `reactive_element_t` array | Matriz de elementos de tira reactiva de color    | See `reactive_element_t` |

## `reactive_element_t`teactive_elements_table

| Field                     | Type               | Description                            | Related Table |
|---------------------------|--------------------|----------------------------------------|---------------|
| `name_test`               | `char` array       | Nombre del elemento reactivo           | N/A           |
| `quantity_reaction_zones` | `uint8_t`          | cantidad de zonas reactivas            | N/A           |
| `pads_array`              | `pads_t` array     | Array of pads with reaction information| See `pads_t`  |

## `pads_t`

| Field           | Type               | Description                           | Related Table |
|-----------------|--------------------|---------------------------------------|---------------|
| `rgb`           | `rgb_t`            | RGB color values for the pad          | See `rgb_t`   |
| `reaction_pad`  | `char` array       | Name of the reaction pad              | N/A           |


## `rgb_t`

| Field  | Type      | Description                  | Related Table |
|--------|-----------|------------------------------|---------------|
| `red`  | `uint16_t`| Red component of RGB color   | N/A           |
| `green`| `uint16_t`| Green component of RGB color | N/A           |
| `blue` | `uint16_t`| Blue component of RGB color  | N/A           |
