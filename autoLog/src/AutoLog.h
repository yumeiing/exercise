#include <string>

struct AutoLog{
	AutoLog(std::string func_name="main");
	~AutoLog();
	const std::string my_func_name;
};
