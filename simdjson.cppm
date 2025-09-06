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

    template<typename T>
    inline void getValue(simdjson::dom::element& element, const char* key, T& outVar)
    {
        auto val = element[key];
        if (val.error())
            return;

        if constexpr (std::is_same_v<T, float>)
            outVar = static_cast<float>(val.get_double().value());
        else if constexpr (std::is_same_v<T, int>)
            outVar = static_cast<int>(val.get_int64().value());
        else if constexpr (std::is_same_v<T, int64_t>)
            outVar = val.get_int64().value();
        else if constexpr (std::is_same_v<T, uint64_t>)
            outVar = val.get_uint64().value();
        else if constexpr (std::is_same_v<T, bool>)
            outVar = val.get_bool().value();
        else if constexpr (std::is_same_v<T, std::string>)
            outVar = std::string(val.get_string().value());
        else if constexpr (std::is_same_v<T, const char*>)
            outVar = val.get_c_str().value();
        else
            static_assert(sizeof(T) == 0, "Unsupported type in getValue");
    }
}

