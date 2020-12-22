#ifndef NEWAPOINTMENTPAGE_H
#define NEWAPOINTMENTPAGE_H

#include <gtkmm.h>
#include "Rooms.h"
#include "Global.h"
#include "Appointment.h"
#include "mysql++.h"
#include <time.h>


class NewApointmentPage: public Gtk::Assistant
{
public:
	NewApointmentPage();
	~NewApointmentPage();
protected:
	void on_assistant_apply();
	void on_assistant_cancel();
	void on_assistant_close();
	void on_assistant_prepare(Gtk::Widget* widget);
	void on_entry_changed();
	void on_entry_changed_APM();

	// Member functions:
	void print_status();

	void PullRoomData();
	void PullAPMData();
	Gtk::TextView m_TextView;
	// Child widgets:
	Gtk::Box m_box;
	Gtk::Box m_box1;
	Gtk::Label m_label1, m_label2, m_label3;
	Gtk::CheckButton m_check;
	Gtk::Entry m_entry;
	Gtk::Calendar m_calendar;

	Gtk::ScrolledWindow m_scrolledWindow;
	Gtk::ScrolledWindow m_scrolledWindow_APM;

	class ModelColumns : public Gtk::TreeModel::ColumnRecord
	{
	public:

		ModelColumns()
		{
			add(m_col_room_id);
			add(m_col_room_name);
			add(m_col_room_dsp);
			add(m_col_room_status);

			add(m_col_period);
			add(m_col_begin_time);
			add(m_col_end_time);
			add(m_col_approve_status);
		}

		Gtk::TreeModelColumn<int> m_col_period;
		Gtk::TreeModelColumn<Glib::ustring> m_col_end_time;
		Gtk::TreeModelColumn<Glib::ustring> m_col_begin_time;
		Gtk::TreeModelColumn<Glib::ustring> m_col_approve_status;

		Gtk::TreeModelColumn<unsigned int> m_col_room_id;
		Gtk::TreeModelColumn<Glib::ustring> m_col_room_name;
		Gtk::TreeModelColumn<Glib::ustring> m_col_room_dsp;
		Gtk::TreeModelColumn<int> m_col_room_status;
	};

	ModelColumns m_Columns;
	Gtk::TreeView m_TreeView_Rooms;
	Glib::RefPtr<Gtk::ListStore> m_refTreeModel_Rooms;
	Glib::RefPtr<Gtk::TreeSelection> refSelection;

	Gtk::TreeView m_TreeView_APM;
	Glib::RefPtr<Gtk::ListStore> m_refTreeModel_APM;
	Glib::RefPtr<Gtk::TreeSelection> refSelection_APM;

	//Child widgets:
private:
	int C_room,C_period;
	Glib::ustring text;
	Glib::ustring C_reason;
	Appointment NewAppointment;
	mysqlpp::sql_date Sdate;


};

#endif // NEWAPOINTMENTPAGE_H
