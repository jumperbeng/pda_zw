#include "main.h"
#include <ctime>

int main(int argc, char** argv){

	if(argc<2)
		cout<<"You need exactly one lef file and one def file."<<endl;
	
	clock_t begin = clock();
	
	// Read lef file
	LefDataBase lef_db;
	if (not LefParser::read(lef_db, argv[1])){
		cout<<"Your lef file cannot be read!"<<endl;
		return -1;
	}

	clock_t lef_time = clock();
	cout<<"lef time:"<< double(lef_time - begin) / CLOCKS_PER_SEC<<endl;

	// Read def file
	DefDataBase def_db;
	if (not DefParser::read(def_db, argv[2])){
		cout<<"Your def file cannot be read!"<<endl;
		return -1;			
	}
	site_map.initialize();

	clock_t def_time = clock();
	cout<<"def time:"<< double(def_time - lef_time) / CLOCKS_PER_SEC<<endl;

	//cout<<"############################################"<<endl;
	//cout<<"The std_out of our program starts from here."<<endl;
	//cout<<"############################################"<<endl;
	
	//cout<<"Your files are read successfully!"<<endl;
	//cout<<macro_list.size()<<" macros are loaded."<<endl;
	//cout<<component_list.size()<<" components are loaded."<<endl;

	//cout<<"# of rows: "<<site_map.get_num_row()<<endl;
	//cout<<"# of cols: "<<site_map.get_num_col()<<endl;
	//cout<<"h of rows: "<<site_map.get_row_h()<<endl;
	//cout<<"w of cols: "<<site_map.get_col_w()<<endl;
	//cout<<"Shape of sitemap is ("<<site_map.site.size()<<", "<<site_map.site[0].size()<<", "<<site_map.site[0][0].size()<<")"<<endl;
	//Call your legalization functions here.

	//Test Macro reader
	//for (map<string, Macro>::iterator it=macro_list.begin(); it!=macro_list.end(); ++it){
	//	cout<<"macro:  "<<it->first<<"  w="<<it->second.get_w()<<",  h="<<it->second.get_h()<<",  bottom="<<it->second.get_bottom()<<endl;
	//}

	//Test Component reader
	for(int i=0;i<component_list.size();i++){
		component_list[i].align_component();
	}

	clock_t finish_time = clock();
	cout<<"finish time:"<< double(finish_time - def_time) / CLOCKS_PER_SEC<<endl;	
	cout<<"total time:"<< double(finish_time - begin) / CLOCKS_PER_SEC<<endl;	
	return 0;
}
