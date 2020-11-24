#include <gtkmm/application.h>
#include <iostream>
//#include <string>
#include <mysql++.h>
//#include <Windows.h>
#include <Appointment.h>
#include "User.h"
#include "LoginPage.h"
#include "UserPage.h"
#include "Rooms.h"
#include "Global.h"
#include <gtkmm/calendar.h>
using namespace std;

int main(int argc, char *argv[])
{
//	Appointment test;
//	test.Update();

	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");
	//User NewUser;
	LoginPage window;
	return app->run(window);

//	Rooms room;
//	cout<<"get"<<string(room.GetRoom(1).room_name)<<endl;

//	User NewUser;
//	NewUser.window();
	/*************************************************
	 * Database test
	 *
	 *************************************************/
//	int in_user_id = 1;
//	cout << endl;
//	mysqlpp::Connection conn(false);
//	const char *db = "meetingsystem", *server = "127.0.0.1", *user = "library",
//			*password = "jtO3ngAeISZKFH0O";
//	cout << conn.connect(db, server, user, password) << endl;
//
//	mysqlpp::Query query = conn.query(
//	//"SELECT * FROM `user` WHERE `apm_user_id` = 1");
//			"SELECT * FROM `user` WHERE `user_id` = 2");
//	if (mysqlpp::StoreQueryResult res = query.store())
//	{
//		cout.setf(ios::left);
//
//		mysqlpp::StoreQueryResult::const_iterator it;
//		for (it = res.begin(); it != res.end(); ++it)
//		{
//			mysqlpp::Row row = *it;
//			std::cout << " " << row[0] << row[1] << row[3] << row[4] << row[5]
//					<< row[6] << endl;
//		}
//	}
	return 0;
}
