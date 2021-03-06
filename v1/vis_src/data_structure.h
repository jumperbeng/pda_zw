#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include "global.h"

using namespace std;

class Macro{
	public:
		Macro();
		Macro(double w_value, double h_value);
		double get_w();
		double get_h();
		
	private:
		double w;
		double h;
};

class Component{
	public:
		//Constructors
		Component();
		Component(DefParser::Component c);
		
		//Set Functions
		void set_x(int x_value);
		void set_y(int y_value);
		void set_orient(string orient_value);
		
		//Get Functions
		string get_cell_name();
		string get_macro_name();
		int get_x();
		int get_y();
		string get_status();
		string get_orient();
		double get_w();
		double get_h();
			
	private:
		string cell_name;
		string macro_name;
		int x;
		int y;
		string status;
		string orient;
		double w;
		double h;	
};

#endif
