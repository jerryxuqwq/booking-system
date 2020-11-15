/*
 * User.h
 *
 *  Created on: Oct 26, 2020
 *      Author: jerry
 */

#ifndef USER_H_
#define USER_H_
#include <gtkmm.h>
#include <mysql++.h>
#include "Global.h"



class User
{
public:
	User();
	virtual ~User();
	int CheakLogin(std::string Username, std::string Password);
	int Login(Glib::ustring Username, Glib::ustring Password);
	int Update(int in_user_id);
	int window();

};

#endif /* USER_H_ */
