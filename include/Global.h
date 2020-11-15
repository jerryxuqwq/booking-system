#ifndef GLOBAL_H_
#define GLOBAL_H_
#include <gtkmm.h>
struct User_data
{
	int user_id; // as same as database
	Glib::ustring user_name, user_loginname, user_password,
	     user_email; // as same as database
	int user_level, user_status; // as same as database
	bool is_login = 0; // The login status for users.
};

static char *db = "meetingsystem", *server = "127.0.0.1",
             *user = "library",
              *password = "jtO3ngAeISZKFH0O";
extern User_data LoginUserData;

//Glib::ustring Username, Password; //input by User, use for check login


#endif /* GLOBAL_H_ */
