# Brainfuck++ Reference

The Brainfuck++ language is an esoteric programming language, based on the popular language Brainfuck.
It features the same instruction set as Brainfuck, but adds if blocks.

The compiler works by parsing the Brainfuck++ code and turning it into compileable C++.

## How to use if-blocks
To check if the value at the current register is equal to 0, simply type:

	{code}

The code inside the curlybrackets will be run if the value at the current register is equal to 0.
But wait, there's more!
To check for other things (i.e. if the value is NOT equal to 0), you use If block modifiers.
They should be placed before the opening of an if block.
I.e. to check if the value at the current register is not equal to 0, use this:

	!{code}

For a full reference of if block modifiers, see this list:

- __!__	If the value at the current register != 0.
- __/__	If the value at the current register is > than the value at the next register.
- __\\__	If the value at the current register is < than the value at the next register.
- __=__	If the value at the current register == the value at the next register.
- __#__	If the value at the current register != the value at the next register.

There's also else blocks, which are simply parenteses. They are used like this:

	(code)

So a full if-block with a modifier and an else statement would look like this:

	={if}(else)
	>{if}(else)

Of course, you replace _if_ and _else_ with your own brainfuck statements.

## Full reference sheet

- __\+__	Increment the value at the current register by 1.
- __\-__	Decrement the value at the current register by 1.
- __>__	Jump to the next register.
- __<__	Jump to the previous register.
- __.__	Print the value at the current register to STDOUT (in ASCII format).
- __,__	Set the value at the current register to the next char from STDIN (in ASCII format).
- __[__	The beginning of a loop. runs until the value at the current register == 0.
- __]__	The end of a loop.
- __{__	The beginning of an if statement. Checks if the value at the current register == 0 if there's no modifier before it.
- __}__	The end of an if statement.
- __(__	The beginning of an else statement.
- __)__	The end of an else statement.
- __;__	Break out of the current if statement or loop.
- __:__	Continue at the top of the current loop.