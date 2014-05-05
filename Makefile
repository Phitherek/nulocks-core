all:
	@echo "Not yet..."
debug:
	@echo "Not yet..."
testall:
	${CXX} -o BlockTest BlockTest.cpp Block.cpp
	${CXX} -o BoardTest BoardTest.cpp Board.cpp Block.cpp
	${CXX} -o BoardMovesTest BoardMovesTest.cpp Board.cpp Block.cpp
testdebug:
	${CXX} -o BlockTest BlockTest.cpp Block.cpp -g
	${CXX} -o BoardTest BoardTest.cpp Board.cpp Block.cpp -g
	${CXX} -o BoardMovesTest BoardMovesTest.cpp Board.cpp Block.cpp -g
