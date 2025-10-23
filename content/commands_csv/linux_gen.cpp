/**
Construction d'un index de commandes Linux, à partir de deux fichiers csv:  
- linux_cat.csv
- linux_commands.csv

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
/// read CSV file \c filename
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
			if( v_str[0][0] != '#' )
				out.push_back( v_str );
	}
	return out;
}

//--------------------------------------------------
/// Read categories
auto
readCSV_cat( std::string filename )
{
	auto vcat = readCSV( filename );
	std::vector<std::pair<int,std::string>> vout;
	for( const auto& elems: vcat )
		vout.push_back(
			std::make_pair(
				std::stoi(elems[0]),
				elems[1]
			)
		);
	return vout;
}

//--------------------------------------------------
/// Contenu d'une commande: nom, commentaire, catégorie, "voir aussi"
struct Command
{
	int         _cat;
	std::string _name;
	std::string _comment;
	std::string _seealso;
	std::string _type;
	Command() = default;
	Command( const std::vector<std::string>& vin )
	{
//		std::cout << "#=" << vin.size() << "\n";
		assert( vin.size() == 5 ); //|| vin.size() == 4 );
//		std::cout << "0:" << vin[0] << " 1:" << vin[1]<< " 2:" << vin[2] << " 3:" << vin[3] << " 4:" << vin[4]  << '\n';
		_name    = vin[0];
		_cat     = stoi( vin[1] );
		_comment = vin[2];
		_seealso = vin[3];
		_type    = vin[4];
	}
	bool operator < ( const Command& other )
	{
		return _name < other._name;
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
		if( elems.size() > 2 )
			vout.emplace_back( Command( elems ) );
	}
	return vout;
}

//--------------------------------------------------
void
printfooter( std::ofstream& f )
{
	auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	f << "\n\n_MAJ: " << std::put_time( std::localtime( &t ), "%FT%T%z" ) << "_,\n";
}

//--------------------------------------------------
void
printHeader( std::ofstream& f )
{
	f << "**Statut**: \n- _builtin_: commande intégrée au Shell\n"
		<< "- _installed_: programme installé et disponible dans l'OS local (VM Github)\n"
		<< "- NI (_Not Installed_): programme non installé\n\n";
}

//--------------------------------------------------
void
printAlpha( std::ofstream& f )
{
	for( uint8_t i=0;i<26;i++ )
		f << "[" << (char)(i+'A') << "](#" << (char)(i+'a') << ")-";
	f << "\n\n";
}

//--------------------------------------------------
void
genListAlpha(
	std::string                                    fn,
	std::vector<Command>                           cmds,
	const std::vector<std::pair<int,std::string>>& cats
)
{
	std::ofstream f( fn );
	assert( f.is_open() );
	f << "# Linux Shell: liste alphabétique de commandes\n\n"
		<< "<a href='linux_cmds_list_cat.md'>Liste par catégorie</a>\n\n"
		<< "<a name='#top'></a>\n\n";

	printHeader( f );

	std::sort( cmds.begin(), cmds.end() );
	auto first_letter = cmds[0]._name.at(0);
	bool start = true;
	for( const auto& cmd: cmds )
	{
		auto first = cmd._name.at(0);
		if( first != first_letter || start )
		{
			f << "\n## " << (char)std::toupper(first)
				<< "\n<a name='" << first << "'></a>\n\n"
				<< "<a href='#top'>Haut de page</a>"
				<< " - <a href='linux_cmds_list_cat.md'>Liste par catégorie</a>\n\n";
			printAlpha( f );
				
			f << "| Nom | Description | Catégorie | Voir aussi | Statut |\n"
				<< "|-----|-----|-----|-----|-----|\n";
			first_letter = first;
			start = false;
		}
		auto cat = std::find_if(
			cats.begin(),
			cats.end(), 
			[cmd](const auto& elem){ return elem.first == cmd._cat; } // lambda
		);
		f << "| <a href='https://www.google.fr/search?q=linux+"
			<< cmd._name << "'>" 
			<< cmd._name << "</a> | " << cmd._comment 
			<< " | <a href='linux_cmds_list_cat.md#cat"
			<< cmd._cat << "'>"
			<< cat->second
			<< "</a> | ";
		if( !cmd._seealso.empty() )
		{
			auto letter = cmd._seealso.at(0);
			f << "[" << cmd._seealso << "](#" << letter << ")";
		}
		f << " | " << cmd._type << " |\n";		
	}
	printfooter(f);
}

//--------------------------------------------------
int countCateg( int cat, const std::vector<Command>& vcmd )
{
	int c=0;
	for( const auto& cmd: vcmd )
		if( cmd._cat == cat )
			c++;
	return c;
}
//--------------------------------------------------
void
genCat(
	std::ofstream&              f,
	int                         idx,
	std::pair<int,std::string>  pcat,
	const std::vector<Command>& vcmd
)
{
	auto cat = pcat.first;
	auto nbc = countCateg( cat, vcmd );

	f << "\n## " << idx << " - catégorie: " << pcat.second
		<< "\n<a name='cat" << cat << "'></a>\n\n" 
		<< nbc << " commandes - <a href='#top'>Haut de page</a>"
		<< "- <a href='linux_cmds_list_alpha.md'>Liste alphabétique</a>\n\n"
		<< "| Nom | Description | Voir aussi | Statut |"
		<< "\n|-----|-----|-----|-----|\n";

	std::vector<Command> newvec;
	for( const auto& cmd: vcmd )
		if( cmd._cat == cat )
			newvec.push_back( cmd );
	std::sort( newvec.begin(), newvec.end() );
	
	for( const auto& cmd: newvec )
	{
		f << "| <a href='https://www.google.fr/search?q=linux+"
			<< cmd._name << "'>" 
			<< cmd._name << "</a> | "
			<< cmd._comment << " | ";
		if( !cmd._seealso.empty() )
		{
			auto letter = cmd._seealso.at(0);
			f << "[" << cmd._seealso << "](linux_cmds_list_alpha.md#" << letter << ")";
		}
		f << " | " << cmd._type << " |\n";
	}
}

//--------------------------------------------------
void
genListCat(
	std::string                                    fn,
	const std::vector<Command>&                    cmds,
	const std::vector<std::pair<int,std::string>>& vcats
)
{
	std::ofstream f( fn );
	assert( f.is_open() );
	f << "# Linux Shell: liste de commandes par catégorie\n\n"
		<< "<a href='linux_cmds_list_alpha.md'>Liste alphabétique</a>\n\n"
		<< "<a name='top'></a>\n\n"
		<< "Catégories:  \n";

// list of links
	int tot = 0;
	for( int idx=1; idx<vcats.size(); idx++ )
	{
		auto nb = countCateg(idx,cmds);
		f << "* " << idx << " - [" << vcats[idx].second << "](#cat" << vcats[idx].first << ")\n";
		tot += nb;
	}
	f << "\nTotal: " << tot << " commandes\n\n";
	printHeader( f );
	
	for(int idx=1; idx<vcats.size(); idx++ )
		genCat( f, idx, vcats[idx], cmds );
	printfooter(f);
}

//--------------------------------------------------

int main( int argc, const char* argv[] )
{
	auto cat = readCSV_cat( "linux_cat.csv" );
	auto cmds = readCSV_cmd( std::string(argv[1]) );
	genListAlpha( "../linux_cmds_list_alpha.md", cmds, cat );
	genListCat( "../linux_cmds_list_cat.md", cmds, cat );
}

