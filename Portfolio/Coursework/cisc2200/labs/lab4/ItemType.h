//  SPECIFICATION FILE ItemType.h 
#ifndef PITEMTYPE_H
#define PITEMTYPE_H

#include <iostream>

const int  MAX_ITEM = 15;
enum  RelationType { LESS, EQUAL, GREATER };

class  PItemType		// declares class data type
{						
public : 			// 4 public member functions

  PItemType() {}

  RelationType ComparePriority( PItemType  otherItem ) const 
  {						
    if ( priority  <  otherItem.priority )
      return  LESS;
    else if ( priority  > otherItem.priority )
      return  GREATER;
    else  return  EQUAL;
  }

  RelationType ComparedTo( PItemType  otherItem ) const 
  {						
    if ( value  <  otherItem.value)
      return  LESS;
    else if ( value  > otherItem.value)
      return  GREATER;
    else  return  EQUAL;
  }

  void Print( ) const 
  {
    std::cout  <<"["<<priority<<", "<<  value  <<"]"<<  std::endl;
  }
  
  // added by Domenico  
  friend std::ostream& operator << (std::ostream& output, PItemType item)
  {
    output << item.value;
    return output;
  }
 
  void Initialize( int value, int p )
  {
    this->value = value;      
    this->priority = p;
  } 	           

  int GetValue()
  {
    return value;
  }

  int GetPriority()
  {
    return priority;
  }

private :		// private data member
  int value; 		// could be any type 

  int priority;         //priority of this item
} ;
#endif	
