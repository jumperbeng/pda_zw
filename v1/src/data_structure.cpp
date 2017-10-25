#include "data_structure.h"

////////////////
//   Macro   //
//////////////
//Constructors
Macro::Macro(){
	w=0;
	h=0;
}

Macro::Macro(double w_value, double h_value){
	w=w_value;
	h=h_value;
	bottom=false;
	bottom_vss=-2;
	bottom_vdd=-2;
}
	
//Set Functions
bool Macro::set_bottom(){
	if((bottom_vss>-2) and (bottom_vdd>-2)){
		if(bottom_vss>bottom_vdd)
			bottom=true;
	}
}

bool Macro::set_bottom_vss(double v){
	bottom_vss=v;
}

bool Macro::set_bottom_vdd(double v){
	bottom_vdd=v;
}

//Get Functions
double Macro::get_w(){
	return w;
}

double Macro::get_h(){
	return h;
}
	
bool Macro::get_bottom(){
	return bottom;
}


////////////////
// Component //
//////////////
//Constructors	
Component::Component(){
	cell_name="";
	macro_name="";
	x=0;
	y=0;
	status="";
	orient="";
	w=0;
	h=0;	
}

Component::Component(DefParser::Component c, int id){
	index=id;
	cell_name=c.comp_name;
	macro_name=c.macro_name;
	x=c.origin[0];
	y=c.origin[1];
	initial_x=x;
	initial_y=y;
	status=c.status;
	orient=c.orient;
	w=macro_list[macro_name].get_w();
	h=macro_list[macro_name].get_h();	
	place_component();
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

//Util Functions
void Component::place_component(){
	for(int j=y/site_map.get_row_h();j<(y+h)/site_map.get_row_h();j++){
		for(int i=x/site_map.get_col_w();i<(x+w)/site_map.get_col_w();i++){
			if((j>=0) and (j<site_map.get_num_row()) and (i>=0) and (i<site_map.get_num_col()))
				site_map.site[j][i].push_back(index);
		}	
	}
}

////////////////
//  SiteMap  //
//////////////
//Constructors
SiteMap::SiteMap(){
	num_row=0;
	num_col=0;
}

//Set Functions
void SiteMap::inc_num_row(){
	num_row++;
	vector< vector<int> > temp(num_col, vector<int>(0));
	site.push_back(temp);
}

void SiteMap::set_num_col(int num){
	num_col=num;
}

void SiteMap::set_row_h(int num){
	row_h=num;
}

void SiteMap::set_col_w(int num){
	col_w=num;
}

//Get Functions
int SiteMap::get_num_row(){
	return num_row;
}

int SiteMap::get_num_col(){
	return num_col;
}

int SiteMap::get_row_h(){
	return row_h;
}

int SiteMap::get_col_w(){
	return col_w;
}
