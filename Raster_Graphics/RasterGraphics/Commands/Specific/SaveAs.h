#pragma once
#include "../Manage.h"

class SaveAs : public Manage
{
	char* withName = nullptr;
public:
	SaveAs(ListOfSessions*& list, const char* withName);
	SaveAs(const SaveAs&) = delete;
	SaveAs& operator=(const SaveAs&) = delete;

	void execute() override;

	~SaveAs();
};

