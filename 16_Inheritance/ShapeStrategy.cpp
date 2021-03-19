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

   void translate(double dx, double dy){
      x_ += dx;
      y_ += dy;
   }

   virtual void rotate(double angle_in_radians){
      angle_ += angle_in_radians;
   }

   virtual double area() const = 0;

   // pure virtual function "draw()" to be implemented using Strategy.cpp example 
   // (design pattern)
   virtual void draw() const = 0;

   virtual ~Shape() = default;

   double xpos() const { return x_; }
   double ypos() const { return y_; }
   double angle() const { return angle_; }
};

class Circle;

class DrawCircle{
public:
   virtual ~DrawCircle() = default;
   virtual void draw(const Circle& circle) const = 0;
};


class Circle
   : public Shape {
private:
   double radius_ {};
   std::unique_ptr<DrawCircle> draw_ {};

public:
   explicit Circle(double radius) : radius_ { radius } {}
   double radius() const { return radius_; }
   double area() const override{ return 3.14 * radius_ * radius_; }

   void draw() const override {
      // TODO: implement by means of Strategy object
      draw_->draw(*this);
   }

   // TODO: Implement a setter for the draw strategy!
   void setDrawStrategy(DrawCircle* stragtegy){
      draw_.reset(stragtegy);
   }

   void translate(double dx, double dy){
      x_ += 2.0*dx;
      y_ += 2.0*dy;
   }

   void rotate(double angle_in_radians) override {
      angle_ += 2.0*angle_in_radians;
   }
};


class TestDrawCircle
   : public DrawCircle
{
public:
   void draw(const Circle& circle) const override {
      std::cout << "circle: radius = " << circle.radius() << "\n"; 
   }
};


int main()
{
   std::unique_ptr<Circle> circle(new Circle(1.0));
   circle->setDrawStrategy(new TestDrawCircle());

   circle->draw();

   return EXIT_SUCCESS;
}
