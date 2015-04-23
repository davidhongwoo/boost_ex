#include <boost/program_options.hpp>
#include <iostream>

namespace opt = boost::program_options;

int main(int argc, char** argv) {
	opt::options_description desc("All options");
	desc.add_options()
		("apples", opt::value<int>()->default_value(10), "how many apples do you have")
		("oranges", opt::value<int>()->default_value(0), "how many oranges do you have")
		("name", opt::value<std::string>(), "your name")
		("help", "produce help message")
		;

	opt::variables_map vm;
	try {
		opt::store(opt::parse_command_line(argc, argv, desc), vm);
	} catch (const std::exception& e) {
		std::cout << "Failed to parse command line : " << e.what();
	}
	opt::notify(vm);

	if (vm.count("help")) {
		std::cout << desc << std::endl;
		return 1;
	}

	try {
		opt::store(opt::parse_config_file<char>("apples_oranges.cfg", desc), vm);
	} catch (const opt::reading_file& e) {
		std::cout << "Failed to open configuration file 'apples_oranges.cfg : " << e.what();
	}
	opt::notify(vm);

	std::cout << "Fruits count: "
			<< vm["apples"].as<int>() + vm["oranges"].as<int>()
			<< std::endl;

	// variable_map 이 boost::any_cast를 사용하는 것 같다. 
	// 그렇다면, RTTI를 사용한다는 의미... 
	// variables_map이 편하긴 하지만, 이 정도 비용을 써가면서 쓸 일은 없을듯... 

	return 0;
}
