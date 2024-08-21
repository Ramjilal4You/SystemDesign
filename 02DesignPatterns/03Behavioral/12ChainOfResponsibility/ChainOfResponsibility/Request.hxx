#pragma once
class Request {
private:
	int priority;
public:
	Request(int p);
	int getPriority();
};