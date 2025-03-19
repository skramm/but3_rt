/**
Construction d'un index de commandes Linux

Produit deux fichiers Markdown:  
- un fichier classé par catégorie de commandes
- un fichier index général, classé par ordre alphabétique, avec un lien sur la catégorie dans l'autre index

Utilisation:
- build: g++ linux_gen.cpp
- run: ./a.out
*/



#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <cassert>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <iomanip>

//--------------------------------------------------
/// Split a line of CSV file into fields
std::vector<std::string>
split_string( const std::string &s, char delim )
{
	std::vector<std::string> velems;
//	std::stringstream ss( TrimSpaces(s) );
	std::stringstream ss( s );
	std::string item;
	while( std::getline( ss, item, delim ) )
		velems.push_back(item);

	if( s.back() == delim )                 // add empty field if last char is the delim
		velems.push_back( std::string() );
	return velems;
}


//--------------------------------------------------
/// read CSV fine \c filename
std::vector<std::vector<std::string>>
readCSV( std::string filename )
{
	std::ifstream file( filename );
	if( !file.is_open() )
		throw std::runtime_error( "Error, unable to open file " + filename );

	std::vector<std::vector<std::string>> out;

	std::string buff;
	int line = 0;
	while ( getline (file, buff ) )
	{
		line++;

		auto v_str = split_string( buff, ';' );
//		std::cout << "line " << line << ": " << buff << " size=" << v_str.size() << '\n';

		if( !v_str.empty() )
			out.push_back( v_str );
	}
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
		assert( vin.size() == 3 );
//		std::cout << "0:" << vin[0] << " 1:" << vin[1]<< " 2:" << vin[2] << '\n';
		name = vin[0];
		cat = stoi( vin[1] );
		comment = vin[2];
	}
	bool operator < ( const Command& other )
	{
		return name < other.name;
	}
};

//--------------------------------------------------
/// Read commands in input CSV file
std::vector<Command>
readCSV_cmd( std::string filename )
{
	auto vcmd = readCSV( filename );
	std::vector<Command> vout;//( vcmd.size() );
	for( const auto elems: vcmd )
	{
//		std::cout << "elems size=" << elems.size() << '\n';
		if( elems.size()  == 3 )
			vout.emplace_back( Command( elems ) );
	}
	return vout;
}

//--------------------------------------------------
void
printfooter( std::ofstream& f )
{
	auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	f << "\n_MAJ: " << std::put_time( std::localtime( &t ), "%FT%T%z" ) << "_\n";
}

//--------------------------------------------------
void
genGlobalList( std::string fn, std::vector<Command> cmds, const std::vector<std::string>& cats )
{
	std::ofstream f( fn );
	assert( f.is_open() );
	f << "# Linux Shell: liste alphabétique de commandes\n\n"
		<< "<a href='linux_cmds_list_cat.md'>Liste par catégorie</a>\n\n"
		<< "<a name='#top'></a>\n\n";
		
	for( uint8_t i=0;i<26;i++ )
		f << "[" << (char)(i+'A') << "](#" << (char)(i+'a') << ")-";
	f << "\n\n";
	
	std::sort( cmds.begin(), cmds.end() );
	auto first_letter = cmds[0].name.at(0);
	bool start = true;
	for( const auto& cmd: cmds )
	{
		auto first = cmd.name.at(0);
		if( first != first_letter || start )
		{
			f << "\n## " << (char)std::toupper(first)
				<< "\n<a name='" << first << "'></a>\n\n"
				<< "<a href='#top'>Haut de page</a>\n\n"
				<< "| Nom | Description | Catégorie |\n"
				<< "|-----|-----|-----|\n";
			first_letter = first;
			start = false;
		}
		f << "| " << cmd.name << " | " << cmd.comment  << " | <a href='linux_cmds_list_cat.md#cat"
			<< cmd.cat << "'>"
			<< cats.at(cmd.cat)
			<< "</a> |\n";
	}
	printfooter(f);
}

//--------------------------------------------------
int countCateg( int cat, const std::vector<Command>& vcmd )
{
	int c=0;
	for( const auto& cmd: vcmd )
		if( cmd.cat == cat )
			c++;
	return c;
}
//--------------------------------------------------
void
genCat( std::ofstream& f, int cat, std::string catname, const std::vector<Command>& vcmd )
{
	auto c = countCateg( cat, vcmd );

	f << "\n## " << cat << " - catégorie: " << catname
		<< " (" << c << " commandes)\n"
		<< "<a name='cat" << cat << "'></a>\n\n"
		<< "<a href='#top'>Haut de page</a>\n\n"
		<< "| Nom | Description|"
		<< "\n|-----|-----|\n";
	for( const auto& cmd: vcmd )
		if( cmd.cat == cat )
			f << "| " << cmd.name << " | " << cmd.comment  << " |\n";
}

//--------------------------------------------------
void
genCatList( std::string fn, const std::vector<Command>& cmds, const std::vector<std::string>& vcats )
{
	std::ofstream f( fn );
	assert( f.is_open() );
	f << "# Linux Shell: liste de commandes par catégorie\n\n"
		<< "<a href='linux_cmds_list_global.md'>Liste alphabétique</a>\n\n"
		<< "<a name='top'></a>\n\n"
		<< "Catégories:  \n";

// list of links
	int tot = 0;
	for(int idx=1; idx<vcats.size(); idx++ )
	{
		auto nb = countCateg(idx,cmds);
		f << "* " << idx << " - [" << vcats[idx] << "](#cat" << idx << ") #:" << nb << "\n";
		tot += nb;
	}
	f << "\nTotal: " << tot << " commandes\n";
	
	for(int idx=1; idx<vcats.size(); idx++ )
		genCat( f, idx, vcats[idx], cmds );
	printfooter(f);
}

//--------------------------------------------------
int main()
{
	auto cat = readCSV_cat( "linux_cat.csv" );
	auto cmds = readCSV_cmd( "linux_commands.csv" );
	genGlobalList( "../linux_cmds_list_global.md", cmds, cat );
	genCatList( "../linux_cmds_list_cat.md", cmds, cat );
}

