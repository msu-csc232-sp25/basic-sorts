/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2025
 *
 * @file    main.cpp
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Entry-point of the main target.
 * @version 1.0.0
 * @date    01/01/2025
 *
 * @copyright Copyright (c) 202 James R. Daehn
 */

#include "csc232.h"
// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays,modernize-avoid-c-arrays,cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers,cppcoreguidelines-pro-bounds-pointer-arithmetic,cppcoreguidelines-pro-bounds-array-to-pointer-decay,cppcoreguidelines-pro-bounds-constant-array-index)
const int unsorted_data[] = { 45, 20, 85, 16, 50, 72, 60, 80, 90, 50, 15, 30, 95, 33, 58, 12 };
constexpr int SIZE = 16;

template <typename T>
void initialize_data( T data[], int size )
{
    for ( auto index = 0; index < size; ++index )
    {
        data[ index ] = unsorted_data[ index ];
    }
}

template <typename T>
void print_data( T data[], int size )
{
    for ( auto index = 0; index < size; ++index )
    {
        std::cout << data[ index ] << "\t";
    }
    std::cout << std::endl;
}

auto main( int argc, char *argv[] ) -> int
{
    std::cout << "Shell sort in action!" << std::endl;

    int data[ SIZE ];
    initialize_data( data, SIZE );
    std::cout << "Initial, unsorted data: " << std::endl;
    print_data( data, SIZE );

    csc232::shell_sort( data, SIZE );
    std::cout << "After sorting:" << std::endl;
    print_data( data, SIZE );

    return EXIT_SUCCESS;
}
// NOLINTEND(cppcoreguidelines-avoid-c-arrays,modernize-avoid-c-arrays,cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers,cppcoreguidelines-pro-bounds-pointer-arithmetic,cppcoreguidelines-pro-bounds-array-to-pointer-decay,cppcoreguidelines-pro-bounds-constant-array-index)
