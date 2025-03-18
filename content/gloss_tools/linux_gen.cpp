/**
WIP !!!
*/



#include <string>
#include <vector>
#include <iostream>
#include <cassert>
#include <fstream>
#include <algorithm>

//--------------------------------------------------
std::vector<std::vector<std::string>>
readCSV( std::string filename )
{
	std::vector<std::vector<std::string>> out;

	return out;
}

//--------------------------------------------------
/// Read categories
std::vector<std::string>
readCSV_cat( std::string filename )
{
	auto vcat = readCSV( filename );
	std::vector<std::string> vout( vcat.size() );
	for( const auto& elems: vcat )
		vout.at(std::stoi(elems[0])) = elems[1];
	return vout;
}

//--------------------------------------------------
struct Command
{
	int cat;
	std::string name;
	std::string comment;
	Command() = default;
	Command( const std::vector<std::string>& vin )
	{
	}
	bool operator < ( const Command& other )
	{
		return name < other.name;
	}
};

//--------------------------------------------------
/// Read commands
std::vector<Command>
readCSV_cmd( std::string filename )
{
	auto vcmd = readCSV( filename );
	std::vector<Command> vout( vcmd.size() );
	for( const auto elems: vcmd )
		vout.emplace_back( Command( elems ) );
	return vout;
}

//--------------------------------------------------
void
genGlobalList( std::string fn, std::vector<Command> cmds, const std::vector<std::string>& cats )
{
	std::ofstream f( fn );
	assert( f.is_open() );
	std::sort( cmds.begin(), cmds.end() );
	f << "| Name | Description|\n";
	f << "|-----|-----|\n";
	for( const auto& cmd: cmds )
		f << '|' << cmd.name << '|' << cmd.comment  << "|\n";
}

//--------------------------------------------------
void
genCat( std::ofstream& f, int cat, std::string catname, const std::vector<Command>& vcmd )
{
	f << "## catégorie: " << catname << '\n';
	f << "| Name | Description|\n";
	f << "|-----|-----|\n";
	for( const auto& cmd: vcmd )
		if( cmd.cat == cat )
			f << '|' << cmd.name << '|' << cmd.comment  << "|\n";
}

//--------------------------------------------------
void
genCatList( std::string fn, const std::vector<Command>& cmds, const std::vector<std::string>& vcats )
{
	std::ofstream f( fn );
	assert( f.is_open() );
	for(int idx=0; idx<vcats.size(); idx++ )
		genCat( f, idx, vcats[idx], cmds );

}

//--------------------------------------------------
int main()
{
	auto cat = readCSV_cat( "linux_cat.csv" );
	auto cmds = readCSV_cmd( "linux_commands.csv" );
	genGlobalList( "list.md", cmds, cat );
	genCatList( "catlist.md", cmds, cat );
}
