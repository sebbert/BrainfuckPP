all:
	g++ Main.cpp Parser.cpp -o bf++

debug:
	g++ -g Main.cpp Parser.cpp -o bf++

output:
	g++ bf_out.cpp -o bf_out

out_debug:
	g++ -g bf_out.cpp -o bf_out