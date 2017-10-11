#ifndef MAIN_H
#define MAIN_H

#include "global.h"
#include "reader.h"

using namespace std;

class Macro;
class Component;

map<string, Macro> macro_list;
list<Component> component_list;

#endif
