#include "ApprovalPage.h"

ApprovalPage::ApprovalPage()
{
	Pop_menu();
}

ApprovalPage::~ApprovalPage()
{
}
void ApprovalPage::Pop_menu()
{
	auto item = Gtk::make_managed<Gtk::MenuItem>("_New", true);
	item->signal_activate().connect(sigc::mem_fun(*this,
	                                &ApprovalPage::on_menu_file_popup_new));
	m_Menu_Popup.append(*item);

	item = Gtk::make_managed<Gtk::MenuItem>("_Delete", true);
	item->signal_activate().connect(
	    sigc::mem_fun(*this,&ApprovalPage::on_menu_file_popup_delete));
	m_Menu_Popup.append(*item);

	item = Gtk::make_managed<Gtk::MenuItem>("_Approve", true);
	item->signal_activate().connect(
	    sigc::mem_fun(*this,&ApprovalPage::on_menu_file_popup_approve));
	m_Menu_Popup.append(*item);

	item = Gtk::make_managed<Gtk::MenuItem>("_Reject", true);
	item->signal_activate().connect(
	    sigc::mem_fun(*this,&ApprovalPage::on_menu_file_popup_reject));
	m_Menu_Popup.append(*item);

	m_Menu_Popup.accelerate(*this);
	m_Menu_Popup.show_all(); //Show all menu items when the menu pops up
}

void ApprovalPage::on_menu_file_popup_approve()
{

auto refSelection = get_selection();

	if(refSelection)
	{
		Gtk::TreeModel::iterator iter = refSelection->get_selected();

		if(iter)
		{
			int id = (*iter)[m_Columns.m_col_apm_id];
			//std::cout << "  Delete ID=" << id << std::endl;
			MyAppointment.change_approve(id,1);
			Update();
		}

	}	
}
void ApprovalPage::on_menu_file_popup_reject()
{
	auto refSelection = get_selection();

	if(refSelection)
	{
		Gtk::TreeModel::iterator iter = refSelection->get_selected();

		if(iter)
		{
			int id = (*iter)[m_Columns.m_col_apm_id];
			//std::cout << "  Delete ID=" << id << std::endl;
			MyAppointment.change_approve(id,-1);
			Update();
		}

	}
	
}
