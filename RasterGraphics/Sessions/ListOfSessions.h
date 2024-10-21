#pragma once
#include "Session.h"

class ListOfSessions
{
private:
	static const unsigned short DEFAULT_CAPACITY = 8;
	static const unsigned short MULTIPLIER = 2;
private:

	Session** sessions = nullptr;
	unsigned capacity = DEFAULT_CAPACITY;

	unsigned currentSessionId = 0;

	bool resize();
	bool isCurrIdValid() const;
	bool isIdValid(unsigned sessionId) const;

	void free();
public:
	ListOfSessions();

	ListOfSessions(const ListOfSessions& other) = delete;
	ListOfSessions& operator=(const ListOfSessions& other) = delete;

	~ListOfSessions();

	bool isEmpty() const;

	bool loadSession();
	void addImage(Image* img);
	void addTransformation(Transformation* tr);
	void undo();
	
	void sessionInfo() const;
	bool switchSession(unsigned sessionId);
	bool closeSession(unsigned sessionId);
	void closeFirstImage();
	void saveAsFirstImage(const char* withName);
	Image* findImage(const char* withName) const;
	void save();
	
	void warningIndex() const;
};

