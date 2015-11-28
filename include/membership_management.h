#ifndef MEMBERSHIP_MANAGEMENT_H_INCLUDED
#define MEMBERSHIP_MANAGEMENT_H_INCLUDED

#include "buses_management.h"
#include "depots_management.h"

void assign_to(Depot*, Bus*);
void remove_assignment_from(Depot*, Bus*);

#endif /* MEMBERSHIP_MANAGEMENT_H_INCLUDED */
