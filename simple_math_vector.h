#pragma once
#include <cmath>

#include "common_math_struct.h"

namespace math {

	namespace vector {

		using namespace common;

		class Vector
		{
		public:

			// ------------ ������������ ������ -------------

			Vector() = default;
			Vector(const Vector&);                                 // ����������� ����������� �� ������� �������
			Vector(Vector&&) noexcept;                             // ����������� ������������ �� ������� �������
			Vector(const Point&);                                  // ����������� ����������� �� ������ ���������
			Vector(Point&&) noexcept;                              // ����������� ����������� �� ������ ���������
			Vector(const Point&, const Point&);                    // ����������� ����������� �� ���� ������
			Vector(Point&&, Point&&) noexcept;                     // ����������� ����������� �� ���� ������

			~Vector() = default;

			// ------------ ���������� ���������� -----------

			Vector& set_start_point(const Point&);                  // ���������� ��������� ����� �������
			Vector& set_end_point(const Point&);                    // ���������� �������� ����� �������
			Vector& operator=(const Vector&);                       // �������� ������������ lvalue
			Vector& operator=(Vector&&) noexcept;                   // �������� ����������� rvalue

			// ------------ ��������� ���������� ------------

			double get_lenght() const;                              // ���������� ����� �������
			Vector get_normalize();                                 // �������� ����� �������������� �������
			Point get_begin_point() const;                          // ���������� ����� ������ �������
			Point get_end_point() const;                            // ���������� ����� ����� �������

			// ------------ �������������� �������� ---------

			Vector& operator+(const Vector&);                       // �������� � ������ ��������
			Vector& operator+=(const Vector&);                      // �������� � ������ ��������
			Vector& operator-(const Vector&);                       // ��������� ������� �������
			Vector& operator-=(const Vector&);                      // ��������� ������� �������

			// ------------ ������� �������� ----------------

			bool operator==(const Vector&);                         // ��������� ���� ��������
			bool operator!=(const Vector&);                         // ����������� ���� ��������

			// ------------ ������ �������� -----------------

			Vector& clear();                                        // �������� ������� ������
			Vector& scale(double);                                  // ������������ ������� �� ������
			Vector& set_zero();                                     // �������� ��������� �����
			Vector& normalization();                                // ����������� ������� ������
			Vector& change_basis(const Vector&, const Vector&);     // ����������� �� ����� �������� ��������
			bool is_normalize();                                    // ���������� ����� ���������� �� ������

		private:
			common::Point begin_;
			common::Point end_;
			bool isNormalize_ = false;

			// ------------ ��������� ������ ----------------

			void PointReconfiguration(Point&, const Point&, const Point&);      // �������������� ����� ��� ����� ������
		};

		std::ostream& operator<<(std::ostream&, const Vector&);
	}

}