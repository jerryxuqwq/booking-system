/*
 * StudentPage.h
 *
 *  Created on: Oct 19, 2020
 *      Author: jerry
 */

#ifndef SRC_STUDENTPAGE_H_
#define SRC_STUDENTPAGE_H_

#include <gtkmm.h>
#include <ctime>
#include <Appointment.h>
#include "Rooms.h"
#include "Global.h"

class StudentPage: public Gtk::TreeView
{
public:
	StudentPage();
	virtual ~StudentPage();
	void Update();


protected:

	// Override Signal handler:
	// Alternatively, use signal_button_press_event().connect_notify()
	bool on_button_press_event(GdkEventButton *button_event) override;

	//Signal handler for popup menu items:
	void on_menu_file_popup_generic();

	//Tree model columns:
	class ModelColumns: public Gtk::TreeModel::ColumnRecord
	{
	public:

		ModelColumns()
		{
			add(m_col_apm_id);
			add(m_col_room_name);
			add(m_col_begin_time);
			add(m_col_begin_date);
			add(m_col_approve_status);
			add(m_col_reason);
		}

		Gtk::TreeModelColumn<unsigned int> m_col_apm_id;
		Gtk::TreeModelColumn<Glib::ustring> m_col_room_name;
		Gtk::TreeModelColumn<Glib::ustring> m_col_begin_date;
		Gtk::TreeModelColumn<Glib::ustring> m_col_begin_time;
		Gtk::TreeModelColumn<Glib::ustring> m_col_reason;
		Gtk::TreeModelColumn<Glib::ustring> m_col_approve_status;

	};

	ModelColumns m_Columns;

	//The Tree model:
	Glib::RefPtr<Gtk::ListStore> m_refTreeModel;

	Gtk::Menu m_Menu_Popup;


};

#endif /* SRC_STUDENTPAGE_H_ */
