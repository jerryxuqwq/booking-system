/*
 * Windows.cpp
 *
 *  Created on: Nov 5, 2020
 *      Author: jerry
 */

#include "Windows.h"

Windows::Windows(User *input_User) :
	m_Button_Login("Test")
{

	set_size_request(250, 100);
	set_title("Login");
	//add(m_VBox);
	add(m_Button_Login);
	m_Button_Login.show();
	std::string Username = "jerry", Password = "jerry";
//	m_Button_Login.signal_clicked().connect(
//			sigc::bind<Glib::ustring,Glib::ustring >(
//					sigc::mem_fun(*input_User, &User::Login), Username, Password));

	//Add the TreeView, inside a ScrolledWindow, with the button underneath:
	// TODO Auto-generated constructor stub

}

Windows::~Windows()

{

	// TODO Auto-generated destructor stub
}
