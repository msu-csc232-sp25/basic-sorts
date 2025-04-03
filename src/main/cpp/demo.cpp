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
// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays,modernize-avoid-c-arrays,cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers,cppcoreguidelines-pro-bounds-pointer-arithmetic,cppcoreguidelines-pro-bounds-array-to-pointer-decay,cppcoreguidelines-pro-bounds-constant-array-index)

template <typename T>
class Node
{
private:
    T data_;
    std::shared_ptr<Node<T>> next_;

public:
    explicit Node( const T &data = T{ }, std::shared_ptr<Node<T>> next = nullptr ) : data_{ data }, next_{ std::move( next ) }
    {
    }
    void setItem( const T &data )
    {
        data_ = data;
    }

    [[nodiscard]] auto getItem( ) const -> T
    {
        return data_;
    }

    void setNext( std::shared_ptr<Node<T>> next )
    {
        next_ = next;
    }

    [[nodiscard]] auto getNext( ) const -> std::shared_ptr<Node<T>>
    {
        return next_;
    }
};

template <typename T>
void print_linked_nodes( std::shared_ptr<Node<T>> headPtr )
{
    auto current_node = headPtr;
    while ( current_node != nullptr )
    {
        std::cout << current_node->getItem( ) << "\t";
        current_node = current_node->getNext( );
    }
    std::cout << std::endl;
}

template <class ItemType>
auto insertionSort( std::shared_ptr<Node<ItemType>> headPtr )
{
    print_linked_nodes( headPtr );
    auto unsortedPtr = headPtr->getNext( );
    // separate the two lists
    headPtr->setNext( nullptr );

    // loop and perform insertion
    while ( unsortedPtr != nullptr )
    {
        // detach first unsorted node
        auto detachedNodePtr = unsortedPtr;
        unsortedPtr = unsortedPtr->getNext( );
        detachedNodePtr->setNext( nullptr );

        // find insertion location
        auto currentPtr = headPtr;
        std::shared_ptr<Node<ItemType>> previousPtr = nullptr;
        while ( ( currentPtr != nullptr ) && ( currentPtr->getItem( ) < detachedNodePtr->getItem( ) ) )
        {
            previousPtr = currentPtr;
            currentPtr = currentPtr->getNext( );
        } // end while searching for insert position

        // insert detached node
        if ( previousPtr != nullptr )
        {
            previousPtr->setNext( detachedNodePtr );
            detachedNodePtr->setNext( currentPtr );
        }
        else
        { // insert at head of chain
            detachedNodePtr->setNext( headPtr );
            headPtr = detachedNodePtr;
        } // end if to insert
    } // end while processing unsorted chain
    print_linked_nodes( headPtr );
} // end insertionSort

auto main( int argc, char *argv[] ) -> int
{
    std::cout << "Hello, Demo Target!" << std::endl;
    std::cout << "Check out this UUID: " << csc232::generate_uuid( ) << std::endl;
    std::cout << "And another UUID:    " << csc232::generate_uuid( ) << std::endl;

    auto node = std::make_shared<Node<int>>( 50 );
    auto node2 = std::make_shared<Node<int>>( 42, node );
    auto node3 = std::make_shared<Node<int>>( -3, node2 );
    auto node4 = std::make_shared<Node<int>>( 78, node3 );

    insertionSort( node4 );

    // print_linked_nodes( node4 );
    return EXIT_SUCCESS;
}
// NOLINTEND(cppcoreguidelines-avoid-c-arrays,modernize-avoid-c-arrays,cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers,cppcoreguidelines-pro-bounds-pointer-arithmetic,cppcoreguidelines-pro-bounds-array-to-pointer-decay,cppcoreguidelines-pro-bounds-constant-array-index)
