/*
 * Windows.h
 *
 *  Created on: Nov 5, 2020
 *      Author: jerry
 */

#ifndef INCLUDE_WINDOWS_H_
#define INCLUDE_WINDOWS_H_

#include <gtkmm.h>
#include <User.h>

class Windows: public Gtk::Window
{
public:
	Windows(User* input_User);
	virtual ~Windows();
protected:

	Gtk::Box m_VBox;
	Gtk::Button m_Button_Login;


};

#endif /* INCLUDE_WINDOWS_H_ */
