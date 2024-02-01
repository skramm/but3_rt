
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

// a function to write a string in a file
void f_write( int fd, const char* str )
{
	ssize_t bytes_written = write( fd, str, strlen(str) );	
	if( bytes_written == -1 )
	{
		printf( "Error writing to file\n" );
		close(fd);  // Close the file before returning on error
		exit(3); // exit program with error code
	}
}

// main program
int main( int argc, const char** argv )
{
	if( argc < 2 )
	{
		printf( "Error, missing argument\n" );
		return 5;
	}
	printf( "arg=%s\n", argv[1] );

// system call, fills the given data structure
	struct timeval tval;
	int r1 = gettimeofday( &tval, 0 );
	if( r1 < 0 )
	{
		printf( "Error on time syscall\n" );
		return 6;
	}

// build a string buffer with the number of seconds
	char tmpbuf[50];
	int n1 = sprintf( tmpbuf, "%ld", tval.tv_sec );
	if( n1 < 0 )
	{
		printf( "Error building output string\n" );
		return 1;
	}

// File Descriptor
	int fd = STDOUT_FILENO;

// Write data to the file
	const char lf[]   = "\n";
	const char dash[] = "-";
	f_write( fd, tmpbuf );
	f_write( fd, dash );
	f_write( fd, argv[1] );
	f_write( fd, lf );		
	
	return 0; // everything was fine
}

