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
#include <User.h>

class UserPage: public Gtk::Window
{
public:
	UserPage();
	virtual ~UserPage();
protected:
	//Signal handlers:
	void on_button_quit();
	//Child widgets:
	Gtk::Box m_VBox;

	Gtk::ScrolledWindow m_ScrolledWindow;
	Gtk::Label m_Label_Username;
	StudentPage m_TreeView;

	Gtk::ButtonBox m_ButtonBox;
	Gtk::Button m_Button_Quit;
	Gtk::Button m_Button_New;
};

#endif /* INCLUDE_USERPAGE_H_ */
