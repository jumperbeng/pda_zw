#include "data_structure.h"

////////////////
//   Macro   //
//////////////
//Constructors
Macro::Macro(){
	w=0;
	h=0;
}

Macro::Macro(double w_value, double h_value, bool bottom_value){
	w=w_value;
	h=h_value;
	bottom=bottom_value;
}
	
//Set Functions


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
	bottom=macro_list[macro_name].get_bottom();	
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

int Component::get_initial_x(){
	return initial_x;
}

int Component::get_initial_y(){
	return initial_y;
}

int Component::get_x(){
	return x;
}

int Component::get_y(){
	return y;
}

int Component::get_cost(){
	return abs(x-initial_x)+abs(y-initial_y);
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

bool Component::get_bottom(){
	return bottom;
}

//Util Functions
void Component::flip(){
	//Write your codes here
}

void Component::place_component(){
	for(int j=y/site_map.get_row_h();j<(y+h)/site_map.get_row_h();j++){
		for(int i=x/site_map.get_col_w();i<(x+w)/site_map.get_col_w();i++){
			if((j>=0) and (j<site_map.get_num_row()) and (i>=0) and (i<site_map.get_num_col()))
				site_map.site[j][i].push_back(index);
		}	
	}
}

void Component::align_component(){
	if(status.compare("FIXED")==0){
		return;
	}

	int num_row=h*1000/site_map.get_row_h();
	if(y<0){
		y=0;
		return;
	}	
	if(y>site_map.get_total_h()){
		y=site_map.get_total_h();
		return;
	}

	
	int row_index=y/site_map.get_row_h();
	if (num_row%2){
		if(y<(row_index+0.5)*site_map.get_row_h()){
    			y=row_index*site_map.get_row_h();
			//row_index%2==1 iff the bottom of component will be placed at an odd-index row, which should be vdd
			//bottom==1 iff the bottom of component is connected to vdd
			//if they are not equal, then flip
			if(bottom!=(row_index%2)){
				flip();
			}
		}else{
    			y=(row_index+1)*site_map.get_row_h();
			//row_index%2==1 iff the bottom of component will be placed at an even-index row(row_index+1), which should be vss
			//bottom==1 iff the bottom of component is connected to vdd
			//if they are equal, then flip			
			if(bottom==(row_index%2)){
				flip();
			}			
		}
	}else{
		if(bottom==(row_index%2)){
			y=row_index*site_map.get_row_h();
		}else{
			y=(row_index+1)*site_map.get_row_h();
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

int SiteMap::get_total_h(){
	return total_h;
}

int SiteMap::get_total_w(){
	return total_w;
}

void SiteMap::initialize(){
	total_h=num_row*row_h;
	total_w=num_col*col_w;
}
