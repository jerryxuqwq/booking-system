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



struct User_data
{
	int user_id; // as same as database
	Glib::ustring user_name, user_loginname, user_password, user_email; // as same as database
	int user_level, user_status; // as same as database
	bool is_login = 0; // The login status for users.
};

class User
{
public:
	User();
	virtual ~User();
	int CheakLogin(std::string Username, std::string Password);
	void Login();
	int Update(int in_user_id);
	int window();

	const Glib::ustring& GetPassword() const
	{
		return Password;
	}

	void SetPassword(const Glib::ustring &password)
	{
		Password = password;
	}

	const Glib::ustring& GetUsername() const
	{
		return Username;
	}

	void SetUsername(const Glib::ustring &username)
	{
		Username = username;
	}

	const User_data& GetLoginUser() const;
	void SetLoginUser(const User_data &loginUser);

private:
	const char *db = "meetingsystem", *server = "127.0.0.1", *user = "library",
			*password = "jtO3ngAeISZKFH0O";
	User_data LoginUser;

	Glib::ustring Username, Password; //input by User, use for check login

};

#endif /* USER_H_ */
