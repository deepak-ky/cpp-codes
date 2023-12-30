#include<iostream>
#include<vector>
#include<map>
using namespace std ;
map < pair < pair < int , int >, int >, bool > mp ;
vector < pair < pair < int , int >, int >> vec ;
bool findpath ( int left_bank [], int right_bank [], int b )
{
	if ( b == 0 )
		vec . push_back ({{ left_bank [ 0 ], left_bank [ 1 ]}, 0 });
	else
		vec . push_back ({{ right_bank [ 0 ], right_bank [ 1 ]}, 1 });
	if ( mp [ {{ left_bank [ 0 ], left_bank [ 1 ]}, b }] == true )
	{
		vec . pop_back ();
		return false ;
	}
	if (( left_bank [ 1 ] > left_bank [ 0 ] && left_bank [ 0 ] > 0 ) ||
	        ( right_bank [ 1 ] > right_bank [ 0 ] && right_bank [ 0 ] > 0 ))
	{
		vec . pop_back ();
		return false ;
	}
	if ( right_bank [ 0 ] == 3 && right_bank [ 1 ] == 3 && b == 1 )
	{
		return true ;
	}
	mp [ {{ left_bank [ 0 ], left_bank [ 1 ]}, b }] = true ;
	if ( b == 0 )
	{
		if ( left_bank [ 0 ] >= 2 )
		{
			left_bank [ 0 ] -= 2 ;
			right_bank [ 0 ] += 2 ;
			if ( findpath ( left_bank , right_bank , 1 ))
				return true ;
			else
			{
				left_bank [ 0 ] += 2 ;
				right_bank [ 0 ] -= 2 ;
			}
		}
		if ( left_bank [ 0 ] >= 1 )
		{
			left_bank [ 0 ] -= 1 ;
			right_bank [ 0 ] += 1 ;
			if ( findpath ( left_bank , right_bank , 1 ))
				return true ;
			else
			{
				left_bank [ 0 ] += 1 ;
				right_bank [ 0 ] -= 1 ;
			}
		}
		if ( left_bank [ 1 ] >= 2 )
		{
			left_bank [ 1 ] -= 2 ;
			right_bank [ 1 ] += 2 ;
			if ( findpath ( left_bank , right_bank , 1 ))
				return true ;
			else
			{
				left_bank [ 1 ] += 2 ;
				right_bank [ 1 ] -= 2 ;
			}
		}
		if ( left_bank [ 1 ] >= 1 )
		{
			left_bank [ 1 ] -= 1 ;
			right_bank [ 1 ] += 1 ;
			if ( findpath ( left_bank , right_bank , 1 ))
				return true ;
			else
			{
				left_bank [ 1 ] += 1 ;
				right_bank [ 1 ] -= 1 ;
			}
		}
		if ( left_bank [ 0 ] >= 1 && left_bank [ 1 ] >= 1 )
		{
			left_bank [ 0 ] -= 1 ;
			left_bank [ 1 ] -= 1 ;
			right_bank [ 0 ] += 1 ;
			right_bank [ 1 ] += 1 ;
			if ( findpath ( left_bank , right_bank , 1 ))
				return true ;
			else
			{
				left_bank [ 0 ] += 1 ;
				left_bank [ 1 ] += 1 ;
				right_bank [ 0 ] = - 1 ;
				right_bank [ 1 ] -= 1 ;
			}
		}
	}
	if ( b == 1 )
	{
		if ( right_bank [ 0 ] >= 2 )
		{
			right_bank [ 0 ] -= 2 ;
			left_bank [ 0 ] += 2 ;
			if ( findpath ( left_bank , right_bank , 0 ))
				return true ;
			else
			{
				right_bank [ 0 ] += 2 ;
				left_bank [ 0 ] -= 2 ;
			}
		}
		if ( right_bank [ 0 ] >= 1 )
		{
			right_bank [ 0 ] -= 1 ;
			left_bank [ 0 ] += 1 ;
			if ( findpath ( left_bank , right_bank , 0 ))
				return true ;
			else
			{
				right_bank [ 0 ] += 1 ;
				left_bank [ 0 ] -= 1 ;
			}
		}
		if ( right_bank [ 1 ] >= 2 )
		{
			right_bank [ 1 ] -= 2 ;
			left_bank [ 1 ] += 2 ;
			if ( findpath ( left_bank , right_bank , 0 ))
				return true ;
			else
			{
				right_bank [ 1 ] += 2 ;
				left_bank [ 1 ] -= 2 ;
			}
		}
		if ( right_bank [ 1 ] >= 1 )
		{
			right_bank [ 1 ] -= 1 ;
			left_bank [ 1 ] += 1 ;
			if ( findpath ( left_bank , right_bank , 0 ))
				return true ;
			else
			{
				right_bank [ 1 ] += 1 ;
				left_bank [ 1 ] -= 1 ;
			}
		}
		if ( right_bank [ 0 ] >= 1 && right_bank [ 1 ] >= 1 )
		{
			right_bank [ 0 ] -= 1 ;
			right_bank [ 1 ] -= 1 ;
			left_bank [ 0 ] += 1 ;
			left_bank [ 1 ] += 1 ;
			if ( findpath ( left_bank , right_bank , 0 ))
				return true ;
			else
			{
				right_bank [ 0 ] += 1 ;
				right_bank [ 1 ] += 1 ;
				left_bank [ 0 ] -= 1 ;
				left_bank [ 1 ] -= 1 ;
			}
		}
	}
	vec . pop_back ();
	return false ;
}
int main ()
{
	int left_bank [ 2 ] = { 3 , 3 };
	int right_bank [ 2 ] = { 0 , 0 };
	cout << "State Space : L<M,C,B>:R<M,C,B>\n" ;
	cout << "L = leftbank , R = rightbank\n" ;
	cout << "M = Missionaries , C = Cannibals , B =
	     Boat\n" ;
	bool x = findpath ( left_bank , right_bank , 0 );
	if ( x )
		cout << "The Path Found is : " << "\n" ;
	for ( auto p : vec )
	{
		if ( p . second == 0 )
		{
			cout << "L<" << p . first . first << "," << p . first . second << "," << 1 - p .
			     second << ">:" ;
			cout << "R<" << 3 - p . first . first << "," << 3 - p . first . second << "," <<
			     p . second << ">" ;
		}
		else
		{
			cout << "L<" << 3 - p . first . first << "," << 3 - p . first . second << "," <<
			     1 - p . second << ">:" ;
			cout << "R<" << p . first . first << "," << p . first . second << "," << p . se
			     cond << ">" ;
		}
		if ( p . first . first != 3 || p . first . second != 3 ||
		        p . second != 1 )
			cout << "\n" ;
	}
}