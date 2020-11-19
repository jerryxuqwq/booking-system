/*
 * LoginPage.h
 *
 *  Created on: Sep 8, 2020
 *      Author: jerry
 */
#ifndef LOGIN_PAGE_H
#define LOGIN_PAGE_H

#include <gtkmm.h>
#include "User.h"
#include <ctime>
#include "UserPage.h"
#include "Global.h"

class LoginPage: public Gtk::Window
{

public:
	LoginPage();
	virtual ~LoginPage();


protected:

	//Signal handlers:
	void on_Buttom_Login_A();
	void on_Buttom_Login_B();

	//Child widgets:
//	Gtk::Box m_HBox1, m_HBox2;
//	Gtk::Box m_VBox;
	Gtk::Grid m_grid;
	Gtk::Entry m_Entry_Username, m_Entry_Password;
	Gtk::Button m_Button_Login;
	Gtk::Label m_Label_Password, m_Label_Username;
	UserPage win;


};

#endif //GTKMM_EXAMPLEWINDOW_H
