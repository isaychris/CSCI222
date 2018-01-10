// recording.h

#ifndef _RECORDING_H
#define _RECORDING_H

#include "holding.h"

class Recording : public Holding //inherits holding class
{
private:
	char* performer;
	char* format;

public:
	Recording(const Recording&); 
	Recording(char*, char, char*, int);

	virtual ~Recording();
	virtual void print();
};

#endif