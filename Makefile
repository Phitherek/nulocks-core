LIBPREFIX=/usr/lib
INCLUDEPREFIX=/usr/include
all:
	${CXX} -Wall -fPIC -c Block.cpp Board.cpp
	${CXX} -shared -Wl,-soname,libnulockscore.so.0 -o libnulockscore.so.0.1 Block.o Board.o
debug:
	${CXX} -Wall -fPIC -c Block.cpp Board.cpp -g
	${CXX} -shared -Wl,-soname,libnulockscore.so.0 -o libnulockscore.so.0.1 Block.o Board.o	
clean:
	rm -rf libnulockscore.so.* *.o
install:
	mv libnulockscore.so.0.1 ${LIBPREFIX}
	ln -sf ${LIBPREFIX}/libnulockscore.so.0.1 ${LIBPREFIX}/libnulockscore.so.0
	ln -sf ${LIBPREFIX}/libnulockscore.so.0.1 ${LIBPREFIX}/libnulockscore.so
	mkdir -p ${INCLUDEPREFIX}/nulocks-core
	cp -f *.h ${INCLUDEPREFIX}/nulocks-core
testall:
	${CXX} -o BlockTest BlockTest.cpp Block.cpp
	${CXX} -o BoardTest BoardTest.cpp Board.cpp Block.cpp
	${CXX} -o BoardMovesTest BoardMovesTest.cpp Board.cpp Block.cpp
testdebug:
	${CXX} -o BlockTest BlockTest.cpp Block.cpp -g
	${CXX} -o BoardTest BoardTest.cpp Board.cpp Block.cpp -g
	${CXX} -o BoardMovesTest BoardMovesTest.cpp Board.cpp Block.cpp -g
testclean:
	rm -rf BlockTest BoardTest BoardMovesTest
