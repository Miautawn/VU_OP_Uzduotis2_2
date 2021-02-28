#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include "martyno_lib.hpp"
#include <vector>
#include <exception>
#include <stdexcept>
#include <system_error>
#include <new>
#include <ios>
#include <future>
#include <typeinfo>


// Čia funkcijos yra skirtos dirbti su klaidų išimtimis
///////////////////////////////////////////////////////

template <typename T>
void processCodeException (const T& e);

void processException(); //throw'ina exceptioną

#endif