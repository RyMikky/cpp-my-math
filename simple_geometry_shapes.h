#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>

#include "common_math_struct.h"
#include "simple_math_vector.h"

namespace math {

	namespace geometry {

		using namespace common;

		enum ShapeType
		{
			circle, rectangle, line
		};

		class Shape
		{
		public:

			Shape() = default;
			virtual ~Shape() = default;

		private:

		};

		class Circle : public Shape 
		{
		public:

			// ------------ конструкторы класса -------------

			Circle() = default;
			Circle(const Point&, const double&);
			Circle(const Circle&);
			Circle(Circle&&) noexcept;

			~Circle() = default;

			// ------------ назначение параметров -----------

			Circle& set_center(Point);                              // назначить центр круга
			Circle& set_radius(double);                             // назначить радиус круга

			// ------------ получение параметров ------------

			Point get_center() const;                               // получить центр круга
			double get_radius() const;                              // получить радиус круга
			double get_sqrt() const;                                // получить площадь круга

			// ------------ булевые операции ----------------

			bool operator==(const Circle&);                         // равенство двух кругов
			bool operator!=(const Circle&);                         // неравенство двух кругов

		private:
			Point center_;
			double radius_ = 1.0;
		};

		class Triangle : public Shape {
		public:

			// ------------ конструкторы класса -------------

			Triangle() = default;
			Triangle(const Point&, const Point&, const Point&);
			Triangle(const Triangle&);
			Triangle(Triangle&&) noexcept;

			~Triangle() = default;

			// ------------ назначение параметров -----------

			Triangle& set_point_a(Point);                             // назначить вершину A
			Triangle& set_point_b(Point);                             // назначить вершину B
			Triangle& set_point_c(Point);                             // назначить вершину C

			// ------------ получение параметров ------------

			Point get_point_a() const;                                // получить вершину A
			Point get_point_b() const;                                // получить вершину B
			Point get_point_c() const;                                // получить вершину C
			double get_perimeter() const;                             // получить периметр треугольника
			double get_sqrt() const;                                  // получить площадь треугольника

			// ------------ булевые операции ----------------

			bool operator==(const Triangle&);                         // равенство двух треугольников
			bool operator!=(const Triangle&);                         // неравенство двух треугольников

		private:
			Point a_;
			Point b_;
			Point c_;
		};

	}

}