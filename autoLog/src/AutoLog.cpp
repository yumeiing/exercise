#include "AutoLog.h"

AutoLog::AutoLog(std::string func_name):
	my_func_name(func_name){
		std::printf("%s - start\n",my_func_name.c_str());
	}

AutoLog::~AutoLog() {
	std::printf("%s - end\n",my_func_name.c_str());
}
