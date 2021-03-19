/**************************************************************************************************
*
* \file Shape.cpp
* \brief C++ Training - Example for an Inheritance Hierarchy
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Abstract the behavior of different kinds of shapes (e.g. 'Circle', 'Square', ...) by
*       means of a 'Shape' base class. Think about the implementation details of a translate()
*       rotate(), and area() function.
*
**************************************************************************************************/

#include <cmath> 
#include <iostream>
#include <memory>


// TODO: Implement the 'Shape', 'Circle' and 'Square classes

class Shape{
protected:
   double x_ {} ;
   double y_ {};
   double angle_ {};

public:
   // 3 types of functions:

   // regular function
   void translate(double dx, double dy);

   // virtual function: can be used by derived classes or also be overridden
   virtual void rotate(double angle_in_radians);
   
   // pure virtual function: needs to be implemented and overridden
   // in the derived classes otherwise will not let us compile
   // This is a function which has no default (since we don't know the shape)
   virtual double area() const = 0;


   // virtual destructor: If the class is going to be 
   // then you need to add the "virtual" keyword in front of the destructor
   virtual ~Shape() = default;

   double xpos() const { return x_; }
   double ypos() const { return y_; }
   double angle() const { return angle_; }
};

void Shape::translate(double dx, double dy){
   x_ += dx;
   y_ += dy;
}

void Shape::rotate(double angle_in_radians){
   angle_ += angle_in_radians;
}

class Circle
   : public Shape {
private:
   double radius_ {};
public:
   explicit Circle(double radius) : radius_ { radius } {}
   double radius() const { return radius_; }

   // Pure virtual function in Shape being overridden here
   double area() const override{
      return 3.14 * radius_ * radius_;
   }

   void translate(double dx, double dy){
      x_ += 2.0*dx;
      y_ += 2.0*dy;
   }

   // This function overrides the function in the base class
   void rotate(double angle_in_radians) override {
      angle_ += 2.0*angle_in_radians;
   }

   // Let's say if we write here float instead of double: 
   /*
   void rotate(float angle_in_radians){
      angle_ += 2.0*angle_in_radians;
   }
   */
   // Here, the function overloads the rotate function in the base class
   // Thus, if called via Shape pointer, the base class version will be called
   // instead of this float version


};


class Square
   : public Shape {
private:
   double side_ {};
public:
   double side() const { return side_; }
   explicit Square(double side) : side_ { side } {}

   // Pure virtual function in Shape being overridden here
   double area() const override{
      return side_ * side_;
   }
};

int main()
{
   std::unique_ptr<Shape> shape(new Circle(1.0));

   /*
   Circle circle(3.14);
   Square square(2.5);
   Shape* shape = &circle;
   
   // shape->translate(2.0, 4.5);
   shape->translate(2.0, 4.5);
   shape->rotate(0.1);     // virtual dispatch
   std::cout << "circle: xpos = " << circle.xpos() 
             << ", ypos = " << circle.ypos() 
             << ", angle = " << circle.angle() 
             << ", area = " << shape->area()
             << "\n";
   std::cout << "circle: radius = " << circle.radius() << "\n";
   
   square.translate(0.1, -0.2);
   std::cout << "square: xpos = " << square.xpos() << ", ypos = " << square.ypos() << "\n";
   */
   return EXIT_SUCCESS;
}
