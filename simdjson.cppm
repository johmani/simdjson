module;

#include <simdjson.h>

export module simdjson;

export namespace simdjson {

	using simdjson::error_code;
	using simdjson::error_message;

	namespace dom {

		using dom::parser;
		using dom::document;
		using dom::element;
		using dom::array;
	}
}

