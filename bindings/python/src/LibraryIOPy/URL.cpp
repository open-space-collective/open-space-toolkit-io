////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/IO
/// @file           Library/IO/LibraryIOPy/Types.hpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        TBD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Library/IO/URL.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline void						LibraryIOPy_URL								( )
{
	
	using namespace boost::python ;

	using library::io::URL ;

	// class_<URL>("URL", init<int>())
	// class_<URL>("URL")

		// .def(int_(self))

		// .def(self == self)
		// .def(self != self)
		// .def(self < self)
		// .def(self <= self)
		// .def(self > self)
		// .def(self >= self)

		// .def(self + self)
		// .def(self += self)
		// .def(self - self)
		// .def(self -= self)
		// .def(self * self)
		// .def(self *= self)
		// .def(self / self)
		// .def(self /= self)

		// .def(self + int())
		// .def(self += int())
		// .def(self - int())
		// .def(self -= int())
		// .def(self * int())
		// .def(self *= int())
		// .def(self / int())
		// .def(self /= int())

		// .def(int() + self)
		// .def(int() - self)
		// .def(int() * self)
		// .def(int() / self)

		// .def("__str__", +[] (const library::io::Integer& anInteger) -> std::string { return anInteger.getString() ; })
		// .def("__repr__", +[] (const library::io::Integer& anInteger) -> std::string { return anInteger.getString() ; })

		// .def("isDefined", &Integer::isDefined)
		// .def("isZero", &Integer::isZero)
		// .def("isPositive", &Integer::isPositive)
		// .def("isNegative", &Integer::isNegative)
		// .def("isStrictlyPositive", &Integer::isStrictlyPositive)
		// .def("isStrictlyNegative", &Integer::isStrictlyNegative)
		// .def("isInfinity", &Integer::isInfinity)
		// .def("isPositiveInfinity", &Integer::isPositiveInfinity)
		// .def("isNegativeInfinity", &Integer::isNegativeInfinity)
		// .def("getSign", &Integer::getSign)
		// .def("getString", &Integer::getString)
		// // .def("getObject", &Integer::getObject)

		// .def("Undefined", &Integer::Undefined).staticmethod("Undefined")
		// .def("Zero", &Integer::Zero).staticmethod("Zero")
		// .def("PositiveInfinity", &Integer::PositiveInfinity).staticmethod("PositiveInfinity")
		// .def("NegativeInfinity", &Integer::NegativeInfinity).staticmethod("NegativeInfinity")
		// .def("String", &Integer::String).staticmethod("String")
		// // .def("Object", &Integer::Object).staticmethod("Object")

		// ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////