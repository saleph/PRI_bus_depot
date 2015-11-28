#include "../include/membership_management.h"


int assign_a_depot_to(Bus* the_bus, Depot* the_depot)
{
    append_to(&(the_bus->memberships), the_depot);
    append_to(&(the_depot->members), the_bus);
    return 1;
}
