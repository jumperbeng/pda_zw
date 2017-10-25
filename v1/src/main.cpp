#include "main.h"

int main(int argc, char** argv){

	if(argc<2)
		cout<<"You need exactly one lef file and one def file."<<endl;
	
	// Read lef file
	LefDataBase lef_db;
	if (not LefParser::read(lef_db, argv[1])){
		cout<<"Your lef file cannot be read!"<<endl;
		return -1;
	}

	// Read def file
	DefDataBase def_db;
	if (not DefParser::read(def_db, argv[2])){
		cout<<"Your def file cannot be read!"<<endl;
		return -1;			
	}
	
	cout<<"############################################"<<endl;
	cout<<"The std_out of our program starts from here."<<endl;
	cout<<"############################################"<<endl;
	
	cout<<"Your files are read successfully!"<<endl;
	cout<<macro_list.size()<<" macros are loaded."<<endl;
	cout<<component_list.size()<<" components are loaded."<<endl;

	cout<<"# of rows: "<<site_map.get_num_row()<<endl;
	cout<<"# of cols: "<<site_map.get_num_col()<<endl;
	cout<<"h of rows: "<<site_map.get_row_h()<<endl;
	cout<<"w of cols: "<<site_map.get_col_w()<<endl;
	cout<<"Shape of sitemap is ("<<site_map.site.size()<<", "<<site_map.site[0].size()<<", "<<site_map.site[0][0].size()<<")"<<endl;
	//Call your legalization functions here.
		
	return 0;
}
