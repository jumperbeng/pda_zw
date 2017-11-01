#include <iostream>
#include <map>
#include <utility>

using namespace std;

class Macro{
	public:
		Macro(){w=0;h=0;}
		Macro(double w_value, double h_value){w=w_value;h=h_value;}
		double get_w(){return w;}
		double get_h(){return h;}

	private:
		double w;
		double h;
};

//extern 
map<string, Macro> macro_list;
