/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2025
 *
 * @file    demo.cpp
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Entry-point of the demo target.
 * @version 1.0.0
 * @date    01/01/2025
 *
 * @copyright Copyright (c) 2025 James R. Daehn
 */

#include "csc232.h"

auto main( int argc, char *argv[] ) -> int
{
    std::cout << "Hello, Demo Target!" << std::endl;
    std::cout << "Check out this UUID: " << csc232::generate_uuid( ) << std::endl;
    std::cout << "And another UUID:    " << csc232::generate_uuid( ) << std::endl;
    return EXIT_SUCCESS;
}
