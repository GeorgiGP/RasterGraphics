#include "ListOfSessions.h"

bool ListOfSessions::resize()
{
	if (capacity >= INT_MAX)
	{
		return false;
	}
	Session** newSessions = new Session*[capacity * MULTIPLIER] { nullptr };
	for (size_t i = 0; i < capacity; i++)
	{
		if (sessions[i])
		{
			newSessions[i] = sessions[i];
		}
	}
	delete[] sessions;
	capacity *= MULTIPLIER;
	sessions = newSessions;
	return true;
}

bool ListOfSessions::isCurrIdValid() const
{
	return isIdValid(currentSessionId);
}

bool ListOfSessions::isIdValid(unsigned sessionId) const
{
	if (!sessionId || sessionId > capacity || !sessions[sessionId - 1])
	{
		return false;
	}
	return true;
}

void ListOfSessions::free()
{
	for (size_t i = 0; i < capacity; i++)
	{
		delete sessions[i];
		sessions[i] = nullptr;

	}
	delete[] sessions;
	sessions = nullptr;
	capacity = currentSessionId = 0;
	
}
ListOfSessions::~ListOfSessions()
{
	free();
}

bool ListOfSessions::isEmpty() const
{
	return !currentSessionId;
}

ListOfSessions::ListOfSessions()
{
	capacity = DEFAULT_CAPACITY;
	currentSessionId = 0;
	sessions = new Session*[capacity] {nullptr};
}

void ListOfSessions::addImage(Image* img)
{
	if (!img)
	{
		return;
	}
	if (!isCurrIdValid())
	{
		warningIndex();
		return;
	}
	sessions[currentSessionId - 1]->addImage(img);
}

void ListOfSessions::addTransformation(Transformation * tr)
{
	if (!tr)
	{
		throw std::nullptr_t();
	}
	if (!isCurrIdValid())
	{
		warningIndex();
		return;
	}
	sessions[currentSessionId - 1]->addTransformation(tr);
}

void ListOfSessions::undo()
{
	if (!isCurrIdValid())
	{
		warningIndex();
		return;
	}
	sessions[currentSessionId - 1]->undo();
}

bool ListOfSessions::closeSession(unsigned sessionId)
{
	if (!isIdValid(sessionId))
	{
		return false;
	}
	delete sessions[sessionId - 1];
	sessions[sessionId - 1] = nullptr;

	return true;
}

void ListOfSessions::sessionInfo() const
{
	if (!isCurrIdValid())
	{
		warningIndex();
		return;
	}
	sessions[currentSessionId - 1]->sessionInfo();
}

bool ListOfSessions::switchSession(unsigned sessionId)
{
	if (!isIdValid(sessionId))
	{
		return false;
	}
	currentSessionId = sessionId;
	return true;
}

bool ListOfSessions::loadSession()
{
	Session* add = new Session();
	unsigned indexId = Session::getLastId() - 1;
	if (indexId >= capacity && !resize())
	{
		delete add;
		return false;
	}

	sessions[indexId] = add;
	currentSessionId = Session::getLastId();
	return true;
}

void ListOfSessions::closeFirstImage()
{
	if (!isCurrIdValid())
	{
		warningIndex();
		return;
	}
	sessions[currentSessionId - 1]->closeFirstImage();
}

void ListOfSessions::saveAsFirstImage(const char* withName)
{
	if (!withName)
	{
		throw std::nullptr_t();
	}
	if (!isCurrIdValid())
	{
		warningIndex();
		return;
	}
	sessions[currentSessionId - 1]->saveAsFirstImage(withName);
}

Image * ListOfSessions::findImage(const char * withName) const
{
	if (!isCurrIdValid())
	{
		warningIndex();
		return nullptr;
	}
	return sessions[currentSessionId - 1]->findImage(withName);
}

void ListOfSessions::save()
{
	if (!isCurrIdValid())
	{
		warningIndex();
		return;
	}
	sessions[currentSessionId - 1]->save();
}

void ListOfSessions::warningIndex() const
{
	std::cout << std::endl << "Choose valid Session ID!" << std::endl;
	std::cout << "Current available are: ";

	unsigned maxSize = Session::getLastId();
	for (size_t i = 0; i < maxSize; i++)
	{
		if (sessions[i])
		{
			std::cout << i + 1 << ' ';
		}
	}
	std::cout << std::endl;
}
