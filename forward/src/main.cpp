#include <iostream>
#include <utility>
#include <string>

void printValue(const std::string &s){
	std::cout<<"Lvalue: "<<s<<'\n';
}

void printValue(const std::string &&s){
	std::cout<<"Rvalue: "<<s<<'\n';
}

template<class T> void f(T &&v){
	printValue(std::forward<T>(v));
}

int main(int argc, char **argv){
	std::string str="hello";
	f(str);
	f(std::string("hello1"));
	f(std::move<>(str));
	return 0; 
}
