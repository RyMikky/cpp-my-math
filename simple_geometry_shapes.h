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

			// ------------ ������������ ������ -------------

			Circle() = default;
			Circle(const Point&, const double&);
			Circle(const Circle&);
			Circle(Circle&&) noexcept;

			~Circle() = default;

			// ------------ ���������� ���������� -----------

			Circle& set_center(Point);                              // ��������� ����� �����
			Circle& set_radius(double);                             // ��������� ������ �����

			// ------------ ��������� ���������� ------------

			Point get_center() const;                               // �������� ����� �����
			double get_radius() const;                              // �������� ������ �����
			double get_sqrt() const;                                // �������� ������� �����

			// ------------ ������� �������� ----------------

			bool operator==(const Circle&);                         // ��������� ���� ������
			bool operator!=(const Circle&);                         // ����������� ���� ������

		private:
			Point center_;
			double radius_ = 1.0;
		};

		class Triangle : public Shape {
		public:

			// ------------ ������������ ������ -------------

			Triangle() = default;
			Triangle(const Point&, const Point&, const Point&);
			Triangle(const Triangle&);
			Triangle(Triangle&&) noexcept;

			~Triangle() = default;

			// ------------ ���������� ���������� -----------

			Triangle& set_point_a(Point);                             // ��������� ������� A
			Triangle& set_point_b(Point);                             // ��������� ������� B
			Triangle& set_point_c(Point);                             // ��������� ������� C

			// ------------ ��������� ���������� ------------

			Point get_point_a() const;                                // �������� ������� A
			Point get_point_b() const;                                // �������� ������� B
			Point get_point_c() const;                                // �������� ������� C
			double get_perimeter() const;                             // �������� �������� ������������
			double get_sqrt() const;                                  // �������� ������� ������������

			// ------------ ������� �������� ----------------

			bool operator==(const Triangle&);                         // ��������� ���� �������������
			bool operator!=(const Triangle&);                         // ����������� ���� �������������

		private:
			Point a_;
			Point b_;
			Point c_;
		};

	}

}