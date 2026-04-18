#pragma once
#include <cstdint>
#include <string_view>

using hash_t = unsigned;

namespace fnv {
	inline constexpr hash_t FNV_BASE{ 0x384d8f3 };
	inline constexpr hash_t FNV_OFFSET{ 0x9d4930 };

	[[nodiscard]] hash_t hash(std::string_view str) noexcept {
		hash_t _hash{ FNV_BASE };
		for (unsigned char _char : str) {
			if (_char == '\0') return _hash;
			_hash *= FNV_OFFSET;
			_hash ^= _char;
		}

		return _hash;
	}

	[[nodiscard]] consteval hash_t hash_const(std::string_view str) noexcept {
		hash_t _hash{ FNV_BASE };
		for (unsigned char _char : str) {
			if (_char == '\0') return _hash;
			_hash *= FNV_OFFSET;
			_hash ^= _char;
		}

		return _hash;
	}

	namespace a1 {
		[[nodiscard]] hash_t hash(std::string_view str) noexcept {
			hash_t _hash{ FNV_BASE };
			for (unsigned char _char : str) {
				if (_char == '\0') return _hash;
				_hash ^= _char;
				_hash *= FNV_OFFSET;
			}

			return _hash;
		}

		[[nodiscard]] consteval hash_t hash_const(std::string_view str) noexcept {
			hash_t _hash{ FNV_BASE };
			for (unsigned char _char : str) {
				if (_char == '\0') return _hash;
				_hash ^= _char;
				_hash *= FNV_OFFSET;
			}

			return _hash;
		}
	}
}