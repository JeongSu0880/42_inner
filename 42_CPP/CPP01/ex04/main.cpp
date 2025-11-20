#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

std::string		getNewLine(const std::string &line, std::string str1, std::string str2) {
	
	std::string	newLine;
	size_t idx = 0;

	while (1) {
		size_t find_idx = line.find(str1, idx);
		if (find_idx == std::string::npos) {
			newLine.append(line, idx, std::string::npos);
			break;
		}
		newLine.append(line, idx, find_idx - idx);
		newLine.append(str2);
		idx = find_idx + str1.size();
	}

	return newLine;
}


void getNewStringStream(std::stringstream &ss, std::ifstream &inFile, std::string str1, std::string str2) {

	std::string			read_buf;

	while (std::getline(inFile, read_buf))
	{
		if (!inFile.eof())
			read_buf.append("\n");
		ss << getNewLine(read_buf, str1, str2);
		
	}
	
}

int main(int argc, char *argv[]) {

	if (argc != 4)
	{
		std::cerr << "Error : invalid arguments" << std::endl;
		return 1;
	}

	if (argv[2][0] == '\0')
		return 1;

	std::string inFileName = argv[1];
	std::string outFileName = inFileName + ".replace";

	std::ifstream inFile(argv[1]);
	if (!inFile) {
        std::cerr << "Error: Could not open input file "<< std::endl;
        return 1;
    }
	std::ofstream outFile(outFileName.c_str());
	if (!outFile) {
        std::cerr << "Error: Could not open output file "<< std::endl;
        return 1;
    }

	std::stringstream ss; 
	getNewStringStream(ss, inFile, argv[2], argv[3]);

	outFile << ss.str();
	if (outFile.fail()) {
        std::cerr << "Error: Writing to file failed" << std::endl;
		return 1;
    }

	inFile.close();
	outFile.close();
}
