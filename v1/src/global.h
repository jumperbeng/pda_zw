#ifndef GLOBAL_H
#define GLOBAL_H

#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <string>

#include <limbo/parsers/def/adapt/DefDriver.h>
#include <limbo/parsers/lef/adapt/LefDriver.h>

#include "data_structure.h"

using namespace std;

class Macro;
class Component;

extern map<string, Macro> macro_list;
extern list<Component> component_list;

#endif
