#include <iostream>
#include <string>

static void megaphoneStr(std::string str) {
	for (size_t i = 0; i < str.size(); i++)
		str[i] = std::toupper(str[i]);
	std::cout << str;
}

int main(int argc, char **argv) {
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for (int i = 1; i < argc; i++)
			megaphoneStr(argv[i]);
	std::cout << std::endl;
}
