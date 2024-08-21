#include "Request.hxx"

Request::Request(int p)
{
	priority = p;
}

int Request::getPriority()
{
	return priority;
}
