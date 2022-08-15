#include "simple_geometry_shapes.h"

namespace math {

	namespace geometry {

		// ------------ class Circle --------------------

		// ------------ конструкторы класса -------------

		Circle::Circle(const Point& center, const double& radius) 
			: center_(center), radius_(radius) {
		}

		Circle::Circle(const Circle& circle) 
			: center_(circle.center_), radius_(circle.radius_) {
		}

		Circle::Circle(Circle&& circle) noexcept 
			: center_(std::move(circle.center_)), radius_(std::move(circle.radius_)) {
		}

		// ------------ назначение параметров -----------

		Circle& Circle::set_center(Point center) {
			center_ = center;
			return *this;
		}

		Circle& Circle::set_radius(double radius) {
			radius_ = radius;
			return *this;
		}

		// ------------ получение параметров ------------

		Point Circle::get_center() const {
			return center_;
		}

		double Circle::get_radius() const {
			return radius_;
		}

		double Circle::get_sqrt() const {
			return M_PI * radius_ * radius_;
		}

		// ------------ булевые операции ----------------

		bool Circle::operator==(const Circle& other) {
			return center_ == other.center_ && radius_ == other.radius_;
		}

		bool Circle::operator!=(const Circle& other) {
			return center_ != other.center_ && radius_ != other.radius_;
		}

		// ------------ class Circle END ----------------


		// ------------ class Triangle ------------------

		// ------------ конструкторы класса -------------

		Triangle::Triangle(const Point& a, const Point& b, const Point& c) : a_(a), b_(b), c_(c) {
		}

		Triangle::Triangle(const Triangle& other)
			: a_(other.a_), b_(other.b_), c_(other.c_) {
		}

		Triangle::Triangle(Triangle&& other) noexcept
			: a_(std::move(other.a_)), b_(std::move(other.b_)), c_(std::move(other.c_)) {
		}

		// ------------ назначение параметров -----------

		Triangle& Triangle::set_point_a(Point point) {
			a_ = point;
			return *this;
		}

		Triangle& Triangle::set_point_b(Point point) {
			b_ = point;
			return *this;
		}

		Triangle& Triangle::set_point_c(Point point) {
			c_ = point;
			return *this;
		}

		// ------------ получение параметров ------------

		Point Triangle::get_point_a() const {
			return a_;
		}

		Point Triangle::get_point_b() const {
			return b_;
		}

		Point Triangle::get_point_c() const {
			return c_;
		}

		double Triangle::get_perimeter() const {
			double line_ab = vector::Vector(a_, b_).get_lenght();
			double line_bc = vector::Vector(b_, c_).get_lenght();
			double line_ca = vector::Vector(c_, a_).get_lenght();
			return line_ab + line_bc + line_ca;
		}

		double Triangle::get_sqrt() const {
			double line_ab = vector::Vector(a_, b_).get_lenght();
			double line_bc = vector::Vector(b_, c_).get_lenght();
			double line_ca = vector::Vector(c_, a_).get_lenght();

			double half_p = (line_ab + line_bc + line_ca) / 2;

			double result = half_p * (half_p - line_ab) * (half_p - line_bc) * (half_p - line_ca);

			return std::sqrt(result);
		}

		// ------------ булевые операции ----------------

		bool Triangle::operator==(const Triangle& other) {
			return a_ == other.a_ && b_ == other.b_ && c_ == other.c_;
		}

		bool Triangle::operator!=(const Triangle& other) {
			return a_ != other.a_ || b_ != other.b_ || c_ != other.c_;
		}

		// ------------ class Triangle END --------------
	}

}