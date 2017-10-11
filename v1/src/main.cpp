#include "main.h"

int main(int argc, char** argv){

	if(argc!=2)
		cout<<"You need exactly one lef file and one def file."<<endl;
	
	// Read lef file
	LefDataBase lef_db;
	if (not LefParser::read(lef_db, argv[1])){
		cout<<"Your lef file cannot be read!"<<endl;
		return -1;
	}
	
	// Read def file
	//DefDataBase def_db;
	//if (not DefParser::read(def_db, argv[2])){
	//	cout<<"Your def file cannot be read!"<<endl;
	//	return -1;			
	//}
	
	cout<<"Your files are read successfully!"<<endl;
	cout<<macro_list.size()<<" macros are loaded."<<endl;
	//cout<<component_list.size()<<" components are loaded."<<endl;
	//Call your legalization functions here.
		

	return 0;
}