#ifndef MEMBERSHIP_MANAGEMENT_H_INCLUDED
#define MEMBERSHIP_MANAGEMENT_H_INCLUDED

#include "buses_management.h"
#include "depots_management.h"
#include "messages.h"
#include "extracting.h"

void assign_to(char*, int);
void remove_assignment_from(char*, int);
void move_to(char*, int);

#endif /* MEMBERSHIP_MANAGEMENT_H_INCLUDED */
