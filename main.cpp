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
//	std::vector<appointment_data> data;
//	Appointment test;
//	data = test.Update(1);
//	for(int i=0;i<data.size();i++)
//	cout<<data[i].apm_begin_time<< "   " <<data[i].apm_period<<endl;


	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");
	//User NewUser;
	LoginPage window;
	return app->run(window);

//	int in_user_id = 1;
//	cout << endl;
	mysqlpp::Connection conn(false);
	char *db = "meetingsystem", *server = "127.0.0.1",
	      *user = "test",
	       *password = "PN$iQTg3";

	return 0;
}
