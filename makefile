build:
	g++ -o program main.cpp \
	Extensions/random_generator.cpp \
	Extensions/utility_functions.cpp \
	Extensions/output.cpp \
	Extensions/input_file.cpp \
	Extensions/student_functions.cpp \
	Extensions/input_console.cpp \
	Extensions/m_exceptions.cpp \
	Extensions/timer.cpp

build_all:
	g++ -o program main.cpp \
	random_generator.o \
	utility_functions.o \
	output.o input_file.o \
	student_functions.o \
	input_console.o \
	m_exceptions.o \
	timer.o

compile_all:
	g++ -c Extensions/random_generator.cpp \
	Extensions/utility_functions.cpp \
	Extensions/output.cpp \
	Extensions/input_file.cpp \
	Extensions/student_functions.cpp \
	Extensions/input_console.cpp \
	Extensions/m_exceptions.cpp \
	Extensions/timer.cpp

clean:
	rm *.o