#include "../include/filtering.h"


/* filtering returns a pointer to static List variable
 * which contains matching records. Passed list can be
 * also previously filtered List
 */
static List filter_buses_by_side_no(List*, int);
static List filter_buses_by_line_no(List*, int);
static List filter_buses_by_driver_name(List*, char*);
static List filter_buses_by_driver_pesel(List*, char*);
static List filter_depots_by_name(List*, char*);


void print_filtered_by(enum FilterType filter_type, void* value)
{
    List filtered;
    int a_number;
    char *a_string;

    switch(filter_type)
    {
    case SIDE_NO:
        a_number = *(int*)value;
        filtered = filter_buses_by_side_no(&buses, a_number);
        for_each_in(&filtered, print_bus_info);
        break;
    case LINE_NO:
        a_number = *(int*)value;
        filtered = filter_buses_by_line_no(&buses, a_number);
        for_each_in(&filtered, print_bus_info_with_refs);
        break;
    case DRIVER_NAME:
        a_string = (char*)value;
        filtered = filter_buses_by_driver_name(&buses, a_string);
        for_each_in(&filtered, print_bus_info_with_refs);
        break;
    case DRIVER_PESEL:
        a_string = (char*)value;
        filtered = filter_buses_by_driver_pesel(&buses, a_string);
        for_each_in(&filtered, print_bus_info_with_refs);
        break;
    case DEPOT_NAME:
        a_string = (char*)value;
        filtered = filter_depots_by_name(&depots, a_string);
        for_each_in(&filtered, print_depot_info_with_refs);
        break;
    }
    delete_list(&filtered, del_node_only);
}

List filter_buses_by_side_no(List* the_list, int side_no)
{
    static List occurences;
    occurences = find_occurrences(the_list, (void*)(&side_no), get_side_no, side_no_cmp);
    return occurences;
}

List filter_buses_by_line_no(List* the_list, int line_no)
{
    static List occurences;
    occurences = find_occurrences(the_list, (void*)(&line_no), get_line_no, line_no_cmp);
    return occurences;
}

List filter_buses_by_driver_name(List* the_list, char* driver_name)
{
    static List occurences;
    occurences = find_occurrences(the_list, (void*)driver_name, get_driver_name, drivers_names_cmp);
    return occurences;
}

List filter_buses_by_driver_pesel(List* the_list, char* driver_pesel)
{
    static List occurences;
    occurences = find_occurrences(the_list, (void*)driver_pesel, get_driver_pesel, drivers_pesels_cmp);
    return occurences;
}

List filter_depots_by_name(List* the_list, char* depot_name)
{
    static List occurences;
    occurences = find_occurrences(the_list, (void*)depot_name, get_depot_name, names_cmp);
    return occurences;
}
