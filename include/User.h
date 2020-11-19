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
#include "Database.h"



class User
{
public:
	User();
	virtual ~User();
	int CheakLogin(std::string Username, std::string Password);
	int Login(Glib::ustring Username, Glib::ustring Password);
	int Update();
	int window();

	/**
	 * @brief Getter and Setter
	 * @param user_id
	 * @return
	 */

	User& SetUserId(int user_id)
	{
		this->user_id = user_id;
		return *this;
	}
	User& SetUserLevel(int user_level)
	{
		this->user_level = user_level;
		return *this;
	}
	User& SetUserStatus(int user_status)
	{
		this->user_status = user_status;
		return *this;
	}
	int GetUserId() const
	{
		return user_id;
	}
	int GetUserLevel() const
	{
		return user_level;
	}
	int GetUserStatus() const
	{
		return user_status;
	}
	Glib::ustring GetUserName() const
	{
		return user_name;
	}
		Glib::ustring GetUserLoginName() const
	{
		return user_loginname;
	}
		Glib::ustring GetUserPassWord() const
	{
		return user_password;
	}
		Glib::ustring GetUserEmail() const
	{
		return user_email;
	}
	

private:

	int user_id; // as same as database
	Glib::ustring user_name, user_loginname, user_password,
	     user_email; // as same as database
	int user_level, user_status; // as same as database
	bool is_login = 0; // The login status for users.

};

#endif /* USER_H_ */
