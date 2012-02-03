#include <stdio.h>
#include <iostream>
#include <string>

#include "Parser.h"

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		std::cout << "Error: too few arguments!\n";
		return 1;
	}
	
	char buffer[1024];
	std::string input;
	
	FILE* file = fopen(argv[1], "rb");
	
	while(!feof(file))
	{
		fread(buffer, sizeof(char), 1024, file);
		input.append(buffer);
	}
	
	fclose(file);

	Parser* p = new Parser();
	p->SetInput(input);
	
	p->Parse();
	p->Build(S_STDIN);
	
	std::string out = p->GetOutput();
	
	delete p;
	
	file = fopen("bf_out.cpp", "wb");
	fwrite(out.c_str(), sizeof(char), out.length(), file);
	fclose(file);

	return 0;
}