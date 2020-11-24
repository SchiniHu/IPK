#include <iostream>
#include <string>

void print(std::string msg)
{
	std::cout<< msg << std::endl;
}
/* this comment is very long */
int main(int argc, char** argv)
{
	std::string greeting = "Hello, world!";
	print(greeting);
	return 0;
}
