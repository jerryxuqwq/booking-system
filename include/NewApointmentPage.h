#ifndef NEWAPOINTMENTPAGE_H
#define NEWAPOINTMENTPAGE_H

#include <gtkmm.h>
#include "Rooms.h"
#include "Global.h"

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

	// Member functions:
	void print_status();

	void PullRoomData();

	// Child widgets:
	Gtk::Box m_box;
	Gtk::Box m_box1;
	Gtk::Label m_label1, m_label2, m_label3;
	Gtk::CheckButton m_check;
	Gtk::Entry m_entry;
	Gtk::Calendar m_calendar;

	Gtk::ScrolledWindow m_scrolledWindow;
	Gtk::ScrolledWindow m_scrolledWindow_APM;
	Glib::RefPtr<Gtk::TreeSelection> refSelection;

	class ModelColumns_Rooms : public Gtk::TreeModel::ColumnRecord
	{
	public:

		ModelColumns_Rooms()
		{
			add(m_col_room_id);
			add(m_col_room_name);
			add(m_col_room_dsp);
			add(m_col_room_status);
		}

		Gtk::TreeModelColumn<unsigned int> m_col_room_id;
		Gtk::TreeModelColumn<Glib::ustring> m_col_room_name;
		Gtk::TreeModelColumn<Glib::ustring> m_col_room_dsp;
		Gtk::TreeModelColumn<int> m_col_room_status;
	};

	ModelColumns_Rooms m_Columns_Rooms;


	//for showing exsiting appointments
	class ModelColumns_APM : public Gtk::TreeModel::ColumnRecord
	{
	public:

		ModelColumns_APM()
		{
			add(m_col_apm_id);
			add(m_col_room_name);
			add(m_col_end_time);
			add(m_col_begin_time);
			add(m_col_approve_status);
		}
		Gtk::TreeModelColumn<unsigned int> m_col_apm_id;
		Gtk::TreeModelColumn<Glib::ustring> m_col_room_name;
		Gtk::TreeModelColumn<Glib::ustring> m_col_end_time;
		Gtk::TreeModelColumn<Glib::ustring> m_col_begin_time;
		Gtk::TreeModelColumn<Glib::ustring> m_col_approve_status;
	};
	ModelColumns_APM m_Columns_APM;
	//Child widgets:
	Gtk::TreeView m_TreeView_Rooms;
	Gtk::TreeView m_TreeView_APM;
	
	Glib::RefPtr<Gtk::ListStore> m_refTreeModel_Rooms;



};

#endif // NEWAPOINTMENTPAGE_H
