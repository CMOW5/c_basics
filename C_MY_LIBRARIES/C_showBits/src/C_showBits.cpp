//============================================================================
// Name        : C_showBits.cpp
// Author      : Cristian Mosquera
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <climits>
using namespace std;


void displayBits( unsigned int value ); // prototype

int main( void )
{
 unsigned int x; // variable to hold user input

 printf( "Enter a nonnegative int: " );
 fflush( stdout );
 scanf( "%u", &x );

 displayBits( x );
 return 0;
} // end main

// display bits of an unsigned int value
void displayBits( unsigned int value )
{
	unsigned int c; // counter

	// define displayMask and left shift 31 bits
	unsigned int displayMask = 1 << (CHAR_BIT * sizeof(unsigned int) - 1);
	//unsigned int displayMask = 1 << 31;

	printf( "%10u = ", value );

	// loop through bits
	for ( c = 1; c <= CHAR_BIT * sizeof(unsigned int); ++c ) {
		putchar( value & displayMask ? '1' : '0' );
		value <<= 1; // shift value left by 1
					 // same as value = value << 1
		if ( c % 8 == 0 ) { // output space after 8 bits
			putchar( ' ' );
		} // end if
	} // end for

	putchar( '\n' );
 } // end function displayBits
