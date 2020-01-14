//  SPECIFICATION FILE ItemType.h 
#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <iostream>

// changed MAX_ITEM to test larger arrays
const int  MAX_ITEM = 15;
enum  RelationType { LESS, EQUAL, GREATER };

class  ItemType		// declares class data type
{						
public : 			// 4 public member functions

  ItemType() {}

  RelationType ComparedTo( ItemType  otherItem ) const 
  {						
    if ( value  <  otherItem.value )
       return  LESS;
    else if ( value  > otherItem.value )
       return  GREATER;
    else  return  EQUAL;
  }

  void Print( ) const 
  {
   std::cout  <<  value  <<  std::endl;
  }

   void Initialize( int value )
  {
    this->value  =  value;              
  } 	           

private :			// 1 private data member
	int  value; 		// could be any type 
} ;
#endif	
