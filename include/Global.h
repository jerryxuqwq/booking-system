#ifndef GLOBAL_H_
#define GLOBAL_H_
#include <gtkmm.h>
#include <vector>
#include "User.h"
#include <iostream>
#include "mysql++.h"
#include "Rooms.h"

extern Rooms room_list;
extern User LoginUser;
//Glib::ustring Username, Password; //input by User, use for check login


#endif /* GLOBAL_H_ */
