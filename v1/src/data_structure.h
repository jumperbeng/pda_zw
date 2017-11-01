#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include "global.h"

using namespace std;

class Macro{
	public:
		//Constructors
		Macro();
		Macro(double w_value, double h_value, bool bottom_value);

		//Set Functions

		//Get Functions
		double get_w();
		double get_h();
		bool get_bottom();
		
	private:
		double w;
		double h;
		bool bottom; //false(by default) is vss, true is vdd
};

class Component{
	public:
		//Constructors
		Component();
		Component(DefParser::Component c, int id);
		
		//Set Functions
		void set_x(int x_value);
		void set_y(int y_value);
		void set_orient(string orient_value);
		
		//Get Functions
		string get_cell_name();
		string get_macro_name();
		int get_initial_x();
		int get_initial_y();
		int get_x();
		int get_y();
		int get_cost();
		string get_status();
		string get_orient();
		double get_w();
		double get_h();
		bool get_bottom();

		//Util Functions
		void flip();
		void place_component();		
		void align_component();
			
	private:
		int index;		
		int initial_x;
		int initial_y;
		int x;
		int y;
		string cell_name;
		string macro_name;
		string status;
		string orient;
		double w;
		double h;	
		bool bottom; //false(by default) is vss, true is vdd
};

class SiteMap{
	public:
		//Constructors
		SiteMap();	

		//Set Functions
		void inc_num_row();
		void set_num_col(int num);
		void set_row_h(int num);
		void set_col_w(int num);
		void set_bottom(bool value);
		
		//Get Functions
		int get_num_row();
		int get_num_col();
		int get_row_h();
		int get_col_w();
		int get_total_h();
		int get_total_w();

		//Util Functions
		void initialize();
		
		vector< vector< vector<int> > > site;  //dim0: row(y index); dim1: col(x index); dim2: resident

	private:		
		int num_row;
		int num_col;
		int row_h;
		int col_w;
		int total_h;
		int total_w;
};
#endif
