#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

const char* FOLDER1 = ".";
const char* FOLDER2 = "C:\\ProgramData\\TestVirtualStore";
const char* FILENAME = "myfile.txt";

int _tmain( int argc, _TCHAR* argv[] )
{
	std::cout << "This program illustrates issues with VirtualStore" << std::endl;
	std::cout << "1 - Working directory" << std::endl;
	std::cout << "2 - ProgramData folder (ensure " << FOLDER2 << " exists)" << std::endl;
	std::cout << std::endl;
	std::cout << "Please select: ";
	std::string selection;
	std::getline( std::cin, selection );
	
	std::string filename;
	if( selection == "1" )
	{
		filename = FOLDER1;
	}
	else if( selection == "2" )
	{
		filename = FOLDER2;
	}
	else
	{
		return 0;
	}

	filename += "\\";
	filename += FILENAME;

	std::ifstream input( filename );
	if( input.good() )
	{
		std::string line;
		std::getline( input, line );

		std::cout << filename << " was found and contains:" << std::endl;
		std::cout << line << std::endl << std::endl;

		std::cout << "Replacing file" << std::endl;

	}
	else
	{
		std::cout << filename << " was not found." << std::endl;
	}


	std::ofstream output;
	output.open( filename, std::ofstream::out | std::ofstream::trunc );
	if( output.good() )
	{
		std::cout << "Please enter some text:" << std::endl;

		std::string line;
		std::getline( std::cin, line );

		output << line << std::endl;
	}
	else
	{
		std::cout << "Couldn't create file " << filename << std::endl;
	}

	std::string dummy;
	std::getline( std::cin, dummy );

	return 0;
}
