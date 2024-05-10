/*-------------------------------------------
   File: shape.cpp
   Course: CS 251, Fall 2023, UIC
   Author: MaryJo Santos
   Description: implemeted shape and child functions that were defined in shape.h
  ------------------------------------------- */

#include "shape.h"

using namespace std;

Shape::Shape() {  // default constructor
    x = 0;
    y = 0;
}

Shape::Shape(int xVal, int yVal) {
    x = xVal;
    y = yVal;
}

Shape::~Shape() {
    // deconstructor
}

Shape* Shape::copy() {
    return new Shape(x, y);
}

int Shape::getX() const {
    return x;
}

int Shape::getY() const {
    return y;
}

void Shape::setX(int val) {
    x = val;
}

void Shape::setY(int val) {
    y = val;
}

string Shape::printShape() const {
    string print = "It's a Shape at x: ";
    print += to_string(getX());
    print += ", y: ";
    print += to_string(getY());

    return print;
}


// circle child class functions
Circle::Circle() {  // default constructor
    setX(0);
    setY(0);
    radius = 0;
}

Circle::Circle(int r) {
    radius = r;
    setX(0);
    setY(0);
}

Circle::Circle(int x, int y, int r) {
    setX(x);
    setY(y);
    radius = r;
}

Circle::~Circle() {
    // deconstructor
}

Circle* Circle::copy() {
    return new Circle(x, y, radius);
}

int Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(int val) {
    radius = val;
}
        
string Circle::printShape() const {
    string print = "It's a Circle at x: ";
    print += to_string(getX());
    print += ", y: ";
    print += to_string(getY());
    print += ", radius: ";
    print += to_string(getRadius());

    return print;
}


// rectangle class functions
Rect::Rect() {  // default constructor
    width = 0;
    height = 0;
    setX(0);
    setY(0);
}

Rect::Rect(int w, int h) {
    width = w;
    height = h;
    setX(0);
    setY(0);
}

Rect::Rect(int x, int y, int w, int h) {
    setX(x);
    setY(y);
    width = w;
    height = h;
}
        
Rect::~Rect() {
    // deconstructor
}

Rect* Rect::copy() {
    return new Rect(x, y, width, height);
}
        
int Rect::getWidth() const {
    return width;
}

int Rect::getHeight() const {
    return height;
}

void Rect::setWidth(int val) {
    width = val;
}

void Rect::setHeight(int val) {
    height = val;
}
        
string Rect::printShape() const {
    string print = "It's a Rectangle at x: ";
    print += to_string(getX());
    print += ", y: ";
    print += to_string(getY());
    print += " with width: ";
    print += to_string(getWidth());
    print += " and height: ";
    print += to_string(getHeight());
    
    return print;
}


// right triangle class functions
RightTriangle::RightTriangle() {  // default constructor
    setX(0);
    setY(0);
    base = 0;
    height = 0;
}

RightTriangle::RightTriangle(int b, int h) {
    setX(0);
    setY(0);
    base = b;
    height = h;
}

RightTriangle::RightTriangle(int x, int y, int b, int h) {
    setX(x);
    setY(y);
    base = b;
    height = h;
}
        
RightTriangle::~RightTriangle() {
    // deconstructor
}

RightTriangle* RightTriangle::copy() {
    return new RightTriangle(x, y, base, height);
}
        
int RightTriangle::getBase() const {
    return base;
}

int RightTriangle::getHeight() const {
    return height;
}

void RightTriangle::setBase(int val) {
    base = val;
}

void RightTriangle::setHeight(int val) {
    height = val;
}

string RightTriangle::printShape() const {
    string print = "It's a Right Triangle at x: ";
    print += to_string(getX());
    print += ", y: ";
    print += to_string(getY());
    print += " with base: ";
    print += to_string(getBase());
    print += " and height: ";
    print += to_string(getHeight());

    return print;
}
