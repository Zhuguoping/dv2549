#include <stdafx.h>

#include <Matrix.h>
#include <Printer.h>
#include <Matrixgen.h>
#include <Ampersand.h>

Matrixgen::Matrixgen( unsigned p_dim, unsigned p_min, unsigned p_max ) {
	m_dim = p_dim;
	m_min = p_min;
	m_max = p_max;
}
Matrixgen::~Matrixgen() {
	// Do nothing.
}

bool Matrixgen::run() {
	std::cout << "\n" << "---" << "\n" << "Matrixgen Utility" << "\n" << "---" << "\n";
	bool success = true;

	Matrix< int >* mA = new Matrix< int >( 100, 100 );
	Matrix< int >* mB = new Matrix< int >( 100, 100 );
	Matrix< int >* mC = new Matrix< int >( 100, 100 );
	
	Ampersand< int >* m_amp = new Ampersand< int >();
	m_amp->matrixPopulate( mA, m_min, m_max );
	m_amp->matrixPopulate( mB, m_min, m_max );
	m_amp->matrixMultiply( mC, mA, mB );

	Printer< int >* m_printer = new Printer< int >( MatrixgenPrecisions_INTEGER, mA, mB, mC );
	success = m_printer->print();
	
	delete mA;
	delete mB;
	delete mC;
	delete m_amp;
	delete m_printer;

	if( success==true ) {
		std::cout << "\n" << "Matrixgen was run sucessfully.";
	} else {
		std::cout << "\n" << "Matrixgen encountered an error!";
	}
	getchar();
	
	return success;
}