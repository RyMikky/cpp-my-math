#pragma once
#include <iostream>
#include <string_view>
#include <utility>

using namespace std::literals;

namespace math {

	namespace common {

		class Point
		{
		public:

			// ------------ ������������ ������ -------------

			Point() = default;
			Point(double, double);
			Point(const Point&);
			Point(Point&&) noexcept;

			virtual ~Point() = default;

			// ------------ ���������� ���������� -----------

			Point& set_x(double);                                // ���������� ���������� X
			Point& set_y(double);                                // ���������� ���������� Y
			Point& set_coordinates(double, double);               // ���������� ���������
			Point& operator=(const Point&);                      // �������� ������������
			Point& operator=(Point&&) noexcept;                  // �������� �����������

			// ------------ ��������� ���������� ------------

			double get_x() const;                                // ��������� ���������� X
			double get_y() const;                                // ��������� ���������� Y

			// ------------ �������������� �������� ---------

			Point& operator+(const Point&);                      // ������������ �������� ���� �����
			Point& operator+=(const Point&);                     // ������������ �������� ���� �����
			Point& operator-(const Point&);                      // ������������ ��������� ����� 
			Point& operator-=(const Point&);                     // ������������ ��������� ����� 
			Point& operator*(const double&);                     // ��������� ��������� ����� �� ������
			Point& operator*=(const double&);                    // ��������� ��������� ����� �� ������
			Point& operator/(const double&);                     // ������� ��������� ����� �� ������
			Point& operator/=(const double&);                    // ������� ��������� ����� �� ������

			// ------------ ������� �������� ----------------

			bool operator==(const Point&);                       // ������������ ��������� � ������ ������
			bool operator!=(const Point&);                       // ������������ ����������� � ������ ������

			// ------------ ������ �������� -----------------

			Point& swap(Point&);                                 // ����� ��������� � ������ ������
			Point& swap(Point&&);                                // ����� ��������� � ������ ������
			Point& clear();                                      // ���������� ����� � ����������� 0:0

		private:
			double x_ = 0.0;
			double y_ = 0.0;
		};

		std::ostream& operator<<(std::ostream&, const Point&);

		class Spot : public Point
		{
		public:
			Spot() = default;

			Spot& set_name(std::string);                          // ������ ��� �����
			std::string get_name() const;                         // �������� ��� �����

		private:
			std::string name_ = "";
		};

		std::ostream& operator<<(std::ostream&, const Spot&);
	}

}