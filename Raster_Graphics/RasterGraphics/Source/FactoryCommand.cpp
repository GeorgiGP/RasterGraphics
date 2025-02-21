#include "../Factories/FactoryCommand.h"
#include <fstream>
#include <sstream>
#include "../Factories/FactoryImage.h"

namespace
{
	const unsigned short MAX_BUFF_SIZE = 1024;
}
AddRotateRight* createRotateRight(ListOfSessions*& list)
{
	return new AddRotateRight(list);
}
AddRotateLeft* createRotateLeft(ListOfSessions*& list)
{
	return new AddRotateLeft(list);
}
AddNegative* createNegative(ListOfSessions*& list)
{
	return new AddNegative(list);
}
AddMonochrome* createMonochrome(ListOfSessions*& list)
{
	return new AddMonochrome(list);
}

AddGrayscale* createGrayscale(ListOfSessions*& list)
{
	return new AddGrayscale(list);
}

VerticalCollage* createVerticalCollage(ListOfSessions *& list, std::stringstream & ss)
{
	Image* lhs, *rhs;
	char buff[MAX_BUFF_SIZE];
	ss >> buff;
	lhs = list->findImage(buff);
	ss >> buff;
	rhs = list->findImage(buff);
	ss >> buff;
	return new VerticalCollage(list, lhs, rhs, buff);
}

HorizontalCollage* createHorizontalCollage(ListOfSessions *& list, std::stringstream & ss)
{
	Image* lhs, *rhs;
	char buff[MAX_BUFF_SIZE];
	ss >> buff;
	lhs = list->findImage(buff);
	ss >> buff;
	rhs = list->findImage(buff);
	ss >> buff;
	return new HorizontalCollage(list, lhs, rhs, buff);
}

SwitchSession* createSwitchSession(ListOfSessions *& list, std::stringstream & ss)
{
	unsigned num;
	ss >> num;
	return new SwitchSession(list, num);
}

SessionInfo* createSessionInfo(ListOfSessions *& list)
{
	return new SessionInfo(list);
}

Undo* createUndo(ListOfSessions *& list)
{
	return new Undo(list);
}

Exit* createExit(ListOfSessions *& list)
{
	return new Exit(list);
}

CloseSession* createCloseSession(ListOfSessions *& list, std::stringstream & ss)
{
	unsigned num;
	ss >> num;
	return new CloseSession(list, num);
}

CloseImage* createCloseImage(ListOfSessions*& list)
{
	return new CloseImage(list);
}

Help* createHelp()
{
	return new Help();
}
Save* createSave(ListOfSessions*& list)
{
	return new Save(list);
}

SaveAs* createSaveAs(ListOfSessions *& list, std::stringstream & ss)
{
	char buff[MAX_BUFF_SIZE];
	ss >> buff;
	return new SaveAs(list, buff);
}
AddImage* createAdd(ListOfSessions *& list, std::stringstream & ss)
{
	char buff[MAX_BUFF_SIZE];
	ss >> buff;
	Image* img = factoryImage(buff);
	AddImage* result = new AddImage(list, img);
	return result;
}

Load* createLoad(ListOfSessions*& list, std::stringstream& ss)
{
	Load* result = new Load(list);
	try
	{
		char buff[MAX_BUFF_SIZE];
		while (!ss.eof())
		{
			ss >> buff;
			result->addImage(buff);
		}
	}
	catch (...)
	{
		delete result;
		result = nullptr;
	}
	return result;
}
Command* createCommand(ListOfSessions*& list)
{
	std::cout << std::endl << '>';
	char buff[MAX_BUFF_SIZE];
	std::cin.getline(buff, MAX_BUFF_SIZE);
	std::stringstream ss(buff);
	ss >> buff;
	if (!strcmp(buff, "load"))
	{
		return createLoad(list, ss);
	}
	else if (!strcmp(buff, "save"))
	{
		return createSave(list);
	}
	else if (!strcmp(buff, "saveas"))
	{
		return createSaveAs(list, ss);
	}
	else if (!strcmp(buff, "help"))
	{
		return createHelp();
	}
	else if (!strcmp(buff, "closeimage"))
	{
		return createCloseImage(list);
	}
	else if (!strcmp(buff, "close"))
	{
		return createCloseSession(list, ss);
	}
	else if (!strcmp(buff, "exit"))
	{
		return createExit(list);
	}
	else if (!strcmp(buff, "grayscale"))
	{
		return createGrayscale(list);
	}
	else if (!strcmp(buff, "monochrome"))
	{
		return createMonochrome(list);
	}
	else if (!strcmp(buff, "negative"))
	{
		return createNegative(list);
	}
	else if (!strcmp(buff, "rotate"))
	{
		if (ss.eof())
		{
			return nullptr;
		}
		ss >> buff;
		if (!strcmp(buff, "left"))
		{
			return createRotateLeft(list);
		}
		else if (!strcmp(buff, "right"))
		{
			return createRotateRight(list);
		}
		else
		{
			return nullptr;
		}
	}
	else if (!strcmp(buff, "undo"))
	{
		return createUndo(list);
	}
	else if (!strcmp(buff, "add"))
	{
		return createAdd(list, ss);
	}
	else if (!strcmp(buff, "session"))
	{
		if (ss.eof())
		{
			return nullptr;
		}
		ss >> buff;
		if (!strcmp(buff, "info"))
		{
			return createSessionInfo(list);
		}
		return nullptr;
	}
	else if (!strcmp(buff, "switch"))
	{
		return createSwitchSession(list, ss);
	}
	else if (!strcmp(buff, "collage"))
	{
		ss >> buff;
		if (!strcmp(buff, "horizontal"))
		{
			return createHorizontalCollage(list, ss);
		}
		else if (!strcmp(buff, "vertical"))
		{
			return createVerticalCollage(list, ss);
		}
		return nullptr;
	}
	return nullptr;
}
