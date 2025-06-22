#include "bladex_int.h"


/*
* Module:                 Bladex.dll
* Entry point:            0x100190B0
*/

void init_properties()
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100190D7
*/

int insert_property(
        const char *name, int property_kind, int data_type, int flags,
        PyObject *(*get_func)(PyObject *, char *),
        int (*set_func)(PyObject *, char *, PyObject *)
)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100191E0
*/

int get_new_property_index(property_info_t *properties, char *name, int num)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100192AB
*/

void shift_elements(property_info_t *properties, int from, int num_elements)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100192FF
*/

void make_tree(int first, int last)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1001940A
*/

void make_sub_tree(int first, int last, int char_index, int *node_index)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10019563
*/

int find_property(property_info_t *properties, const char *name)
{
}
