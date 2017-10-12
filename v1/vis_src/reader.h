#ifndef READER_H
#define READER_H

#include "data_structure.h"
#include "global.h"

class Macro;
class Component;

using namespace std;

class LefDataBase : public LefParser::LefDataBase{
	public:
		typedef LefParser::LefDataBase base_type;

		LefDataBase() : base_type(){}
		virtual void lef_version_cbk(string const& v){}
		virtual void lef_version_cbk(double v){}
		virtual void lef_dividerchar_cbk(string const& v){} 
		virtual void lef_units_cbk(LefParser::lefiUnits const& v){}
		virtual void lef_manufacturing_cbk(double v){}
		virtual void lef_busbitchars_cbk(string const& v){}
		virtual void lef_layer_cbk(LefParser::lefiLayer const& v){}
		virtual void lef_via_cbk(LefParser::lefiVia const& v){}
		virtual void lef_viarule_cbk(LefParser::lefiViaRule const& v){}
		virtual void lef_spacing_cbk(LefParser::lefiSpacing const& v){}
		virtual void lef_site_cbk(LefParser::lefiSite const& v){}
		virtual void lef_macrobegin_cbk(std::string const& v){}
		
		virtual void lef_macro_cbk(LefParser::lefiMacro const& v){
			Macro new_macro(v.sizeX(), v.sizeY());
			macro_list.insert( pair<string, Macro>(v.name(),new_macro) );
		}

		virtual void lef_prop_cbk(LefParser::lefiProp const& v){}
		virtual void lef_maxstackvia_cbk(LefParser::lefiMaxStackVia const& v){}
		virtual void lef_obstruction_cbk(LefParser::lefiObstruction const& v){}
		virtual void lef_pin_cbk(lefiPin const& v){}
};

class DefDataBase : public DefParser::DefDataBase{
	public:
		DefDataBase(){}
		virtual void set_def_dividerchar(string const& token){}
		virtual void set_def_busbitchars(string const& token){}
		virtual void set_def_version(string const& token){}
		virtual void set_def_design(string const& token){}
		virtual void set_def_unit(int token){}
		virtual void set_def_diearea(int t1, int t2, int t3, int t4){}
		virtual void add_def_row(DefParser::Row const&){}

		virtual void add_def_component(DefParser::Component const& c){
			Component new_component(c);
			component_list.push_back(new_component);
		}

		virtual void resize_def_component(int token){}
		virtual void add_def_pin(DefParser::Pin const& p){}
		virtual void resize_def_pin(int token){}
		virtual void add_def_net(DefParser::Net const& n){}
		virtual void resize_def_net(int token){}
        virtual void resize_def_blockage(int n){}
        virtual void add_def_placement_blockage(std::vector<std::vector<int> > const& vBbox){}
        virtual void end_def_design(){}
};

#endif
