#ifndef APPROVALPAGE_H
#define APPROVALPAGE_H
#include "DataPage.h"
#include "User.h"

class ApprovalPage : public DataPage
{
public:
	ApprovalPage();
	~ApprovalPage();
	void Update();

protected:

	void on_menu_file_popup_approve();
	void on_menu_file_popup_reject();

	void on_menu_file_popup_new();

	void on_menu_file_popup_delete();

private:
	void Pop_menu();


};

#endif // APPROVALPAGE_H
