#include "test.h"

int main(){
	Macro new_macro(3,6);
	macro_list.insert( pair<string, Macro>("test",new_macro) );
	cout<<macro_list.size()<<endl;
	cout<<macro_list["test"].get_w()<<" "<<macro_list["test"].get_h()<<endl;
	return 0;
}
