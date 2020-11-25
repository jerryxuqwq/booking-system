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
	Gtk::Label m_label1, m_label2;
	Gtk::CheckButton m_check;
	Gtk::Entry m_entry;
	Gtk::Calendar m_calendar;

	Gtk::ScrolledWindow m_scrolledWindow;

	class ModelColumns : public Gtk::TreeModel::ColumnRecord
	{
	public:

		ModelColumns()
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

	ModelColumns m_Columns;

	//Child widgets:
	Gtk::TreeView m_TreeView;
	Glib::RefPtr<Gtk::ListStore> m_refTreeModel;

};

#endif // NEWAPOINTMENTPAGE_H
