/*
 * UserPage.h
 *
 *  Created on: Sep 9, 2020
 *      Author: jerry
 */

#ifndef INCLUDE_USERPAGE_H_
#define INCLUDE_USERPAGE_H_

#include <gtkmm.h>
#include <StudentPage.h>
#include "NewApointmentPage.h"
#include <User.h>

class UserPage: public Gtk::Window
{
public:
	UserPage();
	virtual ~UserPage();
	void Update();

protected:
	//Signal handlers:
	void on_button_quit();
	void on_button_new();
	
	
	void on_button_refresh();
	
	//Child widgets:
	Gtk::Box m_VBox;

	Gtk::ScrolledWindow m_ScrolledWindow;
	Gtk::Label m_Label_Username;
	StudentPage m_TreeView;

	Gtk::ButtonBox m_ButtonBox;
	Gtk::Button m_Button_Quit;
	Gtk::Button m_Button_New;
	Gtk::Button m_Button_Refresh;
	NewApointmentPage m_assistant_new;
};

#endif /* INCLUDE_USERPAGE_H_ */
