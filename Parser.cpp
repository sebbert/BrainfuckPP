#include "Parser.h"

const char* PREFIX =
"#include <iostream>\n"
"int main()\n"
"{\n"
"char buffers[131072];\n"
"for(int i = 0; i < 131072; i++) buffers[i] = 0;\n"
"unsigned long p = 0;\n"
"\n";

const char* SUFFIX = 
"std::cout << std::endl;\n"
"return 0;\n"
"}";

Parser::Parser()
{

}

Parser::Parser(std::string& input)
{
	m_input = input;
}

void Parser::Parse()
{
	size_t len = m_input.length();

	for(size_t i = 0; i < len; i++)	///< Loop through all the instructions.
	{
		char inst = m_input.at(i);	///< Fetch the next instruction.
		
		switch(inst)
		{
			case '+':
				m_instructions.push_back(ADD);
				break;
			case '-':
				m_instructions.push_back(SUB);
				break;
			case '>':
				m_instructions.push_back(NEXT);
				break;
			case '<':
				m_instructions.push_back(PREV);
				break;
			case '[':
				m_instructions.push_back(L_BEG);
				break;
			case ']':
				m_instructions.push_back(L_END);
				break;
			case '{':
				m_instructions.push_back(I_BEG);
				break;
			case '}':
				m_instructions.push_back(I_END);
				break;
			case '.':
				m_instructions.push_back(OUTPUT);
				break;
			case ',':
				m_instructions.push_back(INPUT);
				break;
			default:
				break;
		}
	}
}

void Parser::Build(Stdin in)
{
	m_output.append(PREFIX);

	size_t len = m_instructions.size();
	for(size_t i = 0; i < len; i++)
	{
		Instruction inst = m_instructions[i];
		switch(inst)
		{
			case ADD:
				m_output.append("buffers[p]++;\n");
				break;
			case SUB:
				m_output.append("buffers[p]--;\n");
				break;
			case NEXT:
				m_output.append("if(p<131072)p++;else p=0;\n");
				break;
			case PREV:
				m_output.append("if(p>0)p--;else p=131072;\n");
				break;
			case L_BEG:
				m_output.append("while(buffers[p] != 0) {\n");
				break;
			case L_END:
				m_output.append("}\n");
				break;
			case I_BEG:
				m_output.append("if(buffers[p] == 0) {\n");
				break;
			case I_END:
				m_output.append("}\n");
				break;
			case OUTPUT:
				m_output.append("std::cout << (char)buffers[p];\n");
				break;
			case INPUT:
				m_output.append("std::cin >> (char)buffers[p];\n");
				break;
			default:
				break;
			
		}
	}

	m_output.append(SUFFIX);
}

void Parser::SetInput(std::string& input)
{
	m_input = input;
}

std::string& Parser::GetOutput()
{
	return m_output;
}