host/main.o: src/main.cpp src/BTNode.hpp src/BTNodeToolkit.hpp
	${CXX} -c -o $@ $< ${CXXFLAGS}
