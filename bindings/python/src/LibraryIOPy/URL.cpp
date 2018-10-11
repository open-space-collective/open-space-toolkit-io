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

	using library::core::types::Integer ;
	using library::core::types::String ;

	using library::io::URL ;
	using library::io::url::Query ;

	scope in_URL = class_<URL>("URL", init<const String&, const String&, const String&, const Integer&, const String&, const String&, const Query&, const String&>())

		.def(self == self)
        .def(self != self)

        .def(self + String())
        .def(self += String())

        .def(self_ns::str(self_ns::self))
        
		.def("__repr__", +[] (const URL& aUrl) -> std::string { return aUrl.toString() ; })

		.def("isDefined", &URL::isDefined)
		
		.def("getScheme", &URL::getScheme)
		.def("getHost", &URL::getHost)
		.def("getPath", &URL::getPath)
		.def("getPort", &URL::getPort)
		.def("getUser", &URL::getUser)
		.def("getPassword", &URL::getPassword)
		.def("getQuery", &URL::getQuery)
		.def("getFragment", &URL::getFragment)
		.def("toString", &URL::toString)
		.def("setScheme", &URL::setScheme)
		.def("setHost", &URL::setHost)
		.def("setPath", &URL::setPath)
		.def("setPort", &URL::setPort)
		.def("setUser", &URL::setUser)
		.def("setPassword", &URL::setPassword)
		.def("setQuery", &URL::setQuery)
		.def("setFragment", &URL::setFragment)

		.def("Undefined", &URL::Undefined).staticmethod("Undefined")
		.def("Parse", &URL::Parse).staticmethod("Parse")
		// .def("EncodeString", &URL::EncodeString).staticmethod("EncodeString")
		// .def("DecodeString", &URL::DecodeString).staticmethod("DecodeString")

		;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////