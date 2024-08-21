/* Logger Framework */
/**/
#include "Logger.hxx"
#include "Constents.hxx"

int main() {
	Logger* logger = Logger::getLoggerInstance();

	/*logger->log(ERROR, "Error msg");
	logger->log(DEBUG, "Debug msg");
	logger->log(INFO, "Info msg");*/


	thread t1(&Logger::log, logger, ERROR, "This is Error msg");
	thread t2(&Logger::log, logger, DEBUG, "This is Debug msg");
	thread t3(&Logger::log, logger, INFO, "This is Info msg");

	t1.join();
	t2.join();
	t3.join();

	return 0;
}