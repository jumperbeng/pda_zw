#include "data_structure.h"

Macro::Macro(){
	w=0;
	h=0;
}

Macro::Macro(double w_value, double h_value){
	w=w_value;
	h=h_value;
}

double Macro::get_w(){
	return w;
}

double Macro::get_h(){
	return h;
}
		
Component::Component(){
	
}

Component::Component(DefParser::Component c){
	cell_name=c.comp_name;
	macro_name=c.macro_name;
	x=c.origin[0];
	y=c.origin[1];
	status=c.status;
	orient=c.orient;
	w=macro_list[macro_name].get_w();
	h=macro_list[macro_name].get_h();	
}

//Set Functions
void Component::set_x(int x_value){
	x=x_value;
}

void Component::set_y(int y_value){
	y=y_value;
}

void Component::set_orient(string orient_value){
	orient=orient_value;
}

//Get Functions
string Component::get_cell_name(){
	return cell_name;
}

string Component::get_macro_name(){
	return macro_name;
}

int Component::get_x(){
	return x;
}

int Component::get_y(){
	return y;
}

string Component::get_status(){
	return status;
}

string Component::get_orient(){
	return orient;
}

double Component::get_w(){
	return w;
}

double Component::get_h(){
	return h;
}
