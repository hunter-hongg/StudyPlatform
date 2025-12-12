all:
	mkdir -p obj
	g++ src/markdown_parser.cpp -Iinclude -c -o obj/markdown_parser.o -std=c++23 
	mkdir -p lib 
	ar rcs lib/libMdParser.a obj/markdown_parser.o 
test:
	g++ src/markdown_parser_example.cpp -Iinclude -c -o obj/markdown_parser_example.o -std=c++23 
	mkdir -p target
	g++ obj/markdown_parser_example.o -Llib -lMdParser -o target/example 
clean: 
	rm -rf obj/ target/ lib/
