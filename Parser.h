#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <sstream>

/**
 * Defines different types of instructions.
 */
enum Instruction
{
	/* Buffer manipulation */
		ADD = 0,	///< Increment the value at the current register by 1.
		SUB, 		///< Decrement the value at the current register by 1.
		NEXT,		///< Jump to the next register.
		PREV,		///< Jump to the previous register.

	/* IO */
		OUTPUT,		///< Print the value at the current register to STDOUT (in ASCII format).
		INPUT,		///< Set the value at the current register to the next char from STDIN (in ASCII format).
		
	/* Loops */
		L_BEG,		///< The beginning of a loop. Checks if the value at the current register == 0.
		L_END,		///< The end of a loop.
		
	/* If blocks */
		I_BEG,		///< The beginning of an if statement. (If value at current register == 0).
		I_END,		///< The end of an if statement. (If value at current register == 0).
		I_ELSE,		///< The beginning of an else block.
		I_ENDELSE,	///< The end of an else block.

	/* If modifiers */
		I_NOT,		///< If the value at the current register != 0.
		I_GT,		///< If the value at the current register is > the value at the next register.
		I_LT,		///< If the value at the current register is < the value at the next register.
		I_EQ,		///< If the value at the current register == the value at the next register.
		I_NEQ,		///< If the value at the current register != the value at the next register.

	/* Other control statements */
		BREAK,		///< Break out of the current if statement or loop.
		CONTINUE	///< Continue at the top of the current loop.
};

/**
 * Defines where the program should read the STD input from.
 */
enum Stdin
{
	S_ARGV,	///< Read from arguments.
	S_STDIN	///< Read from STDIN.
};

/**
 * The parser class. Parses a brainfuck program and turns it into compileable C.
 */
class Parser
{
private:
	/**
	 * The brainfuck program to compile.
	 */
	std::string m_input;

	/**
	 * The resulting C++ code.
	 */
	std::string m_output;

	/**
	 * A std::vector, containing all of the instructions in Instruction format
	 */
	std::vector<Instruction> m_instructions;

public:
	/**
	 * The constructor. Sets the input string.
	 * @param input The input string.
	 */
	Parser(std::string& input);

	/**
	 * The constructor.
	 */
	Parser();

	/**
	 * Parses the brainfuck code, and puts the result in m_instructions.
	 */
	void Parse();

	/**
	 * Converts the instructions into C++ code.
	 * @param in Defines where the program should take the standard input from. 
	 */
	void Build(Stdin in);

	/**
	 * Sets the input std::string.
	 * @param input The input std::string, as brainfuck code.
	 */
	void SetInput(std::string& input);

	/**
	 * Returns the resulting C++ code.
	 * @return The compiled C++ code.
	 */
	std::string& GetOutput();
};

#endif