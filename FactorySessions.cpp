#include "FactorySessions.h"
#include <sstream>
#include "FactoryCommand.h"

namespace
{
	const unsigned short MAX_BUFF_LEN = 1024;
}


static void printDirections()
{
	std::cout << "There are no created sessions!" << std::endl;
	std::cout << "1.load - loads a session." << std::endl;
	std::cout << "2.help - shows instructions." << std::endl;
	std::cout << "3.exit" << std::endl;
}
void factoryListOfSessions(ListOfSessions*& list)
{
	std::cout << std::endl << '>';
	char buff[MAX_BUFF_LEN];
	std::cin.getline(buff, MAX_BUFF_LEN);
	std::stringstream ss(buff);
	ss >> buff;
	if (!strcmp(buff, "load"))
	{
		Command* c = nullptr;
		try
		{
			c = createLoad(list, ss);
			c->execute();
			delete c;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what();
			delete c;
		}
		catch (...)
		{
			delete c;
		}
		
	}
	else if (!strcmp(buff, "help"))
	{
		Command* c = createHelp();
		c->execute();
		delete c;
	}
	else if (!strcmp(buff, "exit"))
	{
		throw std::exception("exit");
	}
	else
	{
		printDirections();
	}
}

