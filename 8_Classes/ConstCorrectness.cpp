/**************************************************************************************************
*
* \file ConstCorrectness.cpp
* \brief C++ Training - Programming Task about Const Correctness
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Consider the following code. Don’t comment on or change the structure of this program;
*       it’s contrived and condensed for illustration only. Just add or remove const (including
*       minor variants and related keywords) wherever appropriate.
*
**************************************************************************************************/

#include <iostream>
#include <vector>


struct Point
{
   double x;
   double y;
};


class Polygon
{
 public:
   Polygon() : area_(-1.0) {}

   void AddPoint( const Point pt )
   {
      InvalidateArea();
      points_.push_back(pt);
   }

   Point GetPoint( const int i ) { return points_[i]; }

   int GetNumPoints() { return points_.size(); }

   double GetArea()
   {
      if ( area_ < 0.0 ) // if not yet calculated and cached
      {
         CalcArea();
      }
      return area_;
   }

 private:
   void InvalidateArea() { area_ = -1.0; }

   void CalcArea()
   {
      area_ = 0.0;
      std::vector<Point>::iterator i;
      for ( i = points_.begin(); i != points_.end(); ++i )
         area_ += 1.1;  /* some work */
   }

   std::vector<Point> points_;
   double area_;
};


Polygon operator+( Polygon& lhs, Polygon& rhs )
{
   Polygon ret = lhs;
   int last = rhs.GetNumPoints();
   for ( int i = 0; i < last; ++i ) // concatenate
   {
      ret.AddPoint( rhs.GetPoint(i) );
   }
   return ret;
}


int main()
{
   Polygon p;
   p.AddPoint( { 1.0, 1.0 } );
   p.AddPoint( { 3.0, 1.0 } );
   p.AddPoint( { 2.0, 5.0 } );

   double area = p.GetArea();

   std::cout << "\n area = " << area << "\n\n";
}
