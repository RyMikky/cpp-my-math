#pragma once
#include <iostream>
#include <cassert>
#include <vector>

#include "simple_geometry_shapes.h"
#include "simple_math_vector.h"
#include "common_math_struct.h"

void MakePointTest() {

	math::common::Point point;
	point.set_coordinates(10.0, 2.7);
	//std::cerr << point << std::endl;

	math::common::Spot n_point;
	n_point.set_name("A");
	n_point.set_coordinates(10.0, 2.7);
	//std::cerr << n_point << std::endl;
	assert(point == n_point);
}

void SimplePointOperation() {

	{
		math::common::Point point1;
		point1.set_coordinates(5, 50);

		math::common::Point point2{20, 3};

		std::cerr << "P1 - "sv << point1 << ", P2 - "sv << point2 << std::endl;

		point1.swap(point2);

		std::cerr << "P1 - "sv << point1 << ", P2 - "sv << point2 << std::endl;
	}

	{
		math::common::Point point1;
		point1.set_coordinates(10.0, 5);

		math::common::Point point2{ 2, 15 };

		std::cerr << "P1 - "sv << point1 << ", P2 - "sv << point2 << std::endl;

		point1.swap(std::move(point2));

		std::cerr << "P1 - "sv << point1 << ", P2 - "sv << point2 << std::endl;
	}
	
}

void MakeSimpleVector() {

	{
		math::vector::Vector vector;	
	}
	
	{
		math::common::Point begin{ 0, 0 };
		math::common::Point end{ 10, 10 };

		math::vector::Vector vector{ begin , end };
	}
	
	{
		math::vector::Vector vector_1{ {0,0} , {5,5} };
		math::vector::Vector vector_2{ {5,5} , {10,8} };

		math::vector::Vector vector_3(vector_1);
		math::vector::Vector vector_4(std::move(vector_2));

		//std::cerr << "Vector 1 - "sv << vector_1 << std::endl;
		//std::cerr << "Vector 2 - "sv << vector_2 << std::endl;
		//std::cerr << "Vector 3 - "sv << vector_3 << std::endl;
		//std::cerr << "Vector 4 - "sv << vector_4 << std::endl;
	}

	{
		math::vector::Vector vector_1{ {0,0} , {5,5} };
		math::vector::Vector vector_2{ {5,5} , {10,8} };
		assert(vector_1 != vector_2);

		vector_1 = vector_2;
		assert(vector_1 == vector_2);

		math::vector::Vector vector_3{ {4,2} , {1,3} };
		vector_2 = std::move(vector_3);
		assert(vector_1 != vector_2);
		assert(vector_2 == math::vector::Vector({ 4, 2 }, { 1,3 }));
		assert(vector_3 == math::vector::Vector());
	}

}

void SimpleVectorOperation() {

	{
		math::vector::Vector vector{ {0,0} , {3,1} };
		std::cerr << vector << std::endl;

		vector.scale(2);
		std::cerr << vector << std::endl;

		std::cerr << vector.get_lenght() << std::endl;
	}

	{
		math::vector::Vector vector{ {0,0} , {3,4} };
		std::cerr << vector << std::endl;
		std::cerr << vector.get_lenght() << std::endl;

		math::vector::Vector vector2;
		vector2 = vector;
		assert(vector == vector2);

		vector2.normalization();
		assert(vector != vector2);

		math::vector::Vector vector3 = vector.get_normalize();
		//math::vector::Vector vector3(vector.GetNormalizeVector());
		assert(vector3 == vector2);

		assert(vector2.is_normalize() == true);
		assert(vector3.is_normalize() == true);

		vector.clear();
		assert(vector == math::vector::Vector());


	}
}

void ShapesMake() {

	math::geometry::Circle circle1({ 0, 0 }, 20);
	math::geometry::Circle circle2({ 5, 3 }, 12);

	math::geometry::Triangle triangle1({ 5, 3 }, {0, 0}, {2, 7});

	std::vector<math::geometry::Shape*> shapes;

	shapes.push_back(&circle1);
	shapes.push_back(&circle2);
	shapes.push_back(&triangle1);

	assert(shapes.size() != 3);
	// TODO надо разбираться почему нет доступа к полям класса-наследника!!!
	auto& a = *shapes[2];
	//math::geometry::Triangle triangle2(shapes[2].);
	std::cerr << shapes[2];
	
}