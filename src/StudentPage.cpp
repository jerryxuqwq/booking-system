#include "StudentPage.h"

StudentPage::StudentPage()
{
	Pop_menu();
}

StudentPage::~StudentPage()
{
}
void StudentPage::Pop_menu()
{
	auto item = Gtk::make_managed<Gtk::MenuItem>("_New", true);
	item->signal_activate().connect(sigc::mem_fun(*this,
	                                &StudentPage::on_menu_file_popup_new));
	m_Menu_Popup.append(*item);

	item = Gtk::make_managed<Gtk::MenuItem>("_Delete", true);
	item->signal_activate().connect(
	    sigc::mem_fun(*this,&StudentPage::on_menu_file_popup_delete));
	m_Menu_Popup.append(*item);

	m_Menu_Popup.accelerate(*this);
	m_Menu_Popup.show_all(); //Show all menu items when the menu pops up
}

