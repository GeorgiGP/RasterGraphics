#pragma once
#include "../Manage.h"
#include "../../Sessions/ElementsSession/Image/Image.h"
class VerticalCollage : public Manage
{
	Image* lhs;
	Image* rhs;
	char* collageFileName = nullptr;

public:
	VerticalCollage(ListOfSessions*& list, Image* lhs, Image* rhs, const char* collageFileName);
	VerticalCollage(const VerticalCollage&) = delete;
	VerticalCollage& operator=(const VerticalCollage&) = delete;
	void execute() override;

	~VerticalCollage();
};

