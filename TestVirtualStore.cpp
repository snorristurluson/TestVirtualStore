#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

const char* FILENAME = "c:\\ProgramData\\TestVirtualStore\\testvirtualstore.txt";

int _tmain( int argc, _TCHAR* argv[] )
{
	std::string prevContents;
	int lineCount = 0;
	{
		std::ifstream input( FILENAME );
		while( input.good() )
		{
			std::string line;
			std::getline( input, line );
			prevContents += line + '\n';
			lineCount++;
		}
	}

	std::ofstream output;
	output.open( FILENAME, std::ofstream::out | std::ofstream::trunc );
	if( output.good() )
	{
		output << prevContents;
		output << "This is line number " << lineCount + 1;
	}
	else
	{
		std::cout << "Couldn't open file " << FILENAME << std::endl;
		std::string dummy;
		std::getline( std::cin, dummy );
	}

	return 0;
}
