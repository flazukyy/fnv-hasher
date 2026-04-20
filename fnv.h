#pragma once
#include <cstdint>
#include <string_view>

namespace fnv {
	using hash32_t = unsigned;
	using hash64_t = long long;

	inline constexpr hash32_t FNV32_BASE{ 0x384d8f3 };
	inline constexpr hash32_t FNV32_OFFSET{ 0x9d4930 };
	inline constexpr hash64_t FNV64_BASE{ 0x384d8f3399827c7c };
	inline constexpr hash64_t FNV64_OFFSET{ 0x9d493034d9430c };

	[[nodiscard]] hash32_t hash(std::string_view str) noexcept {
		hash32_t _hash{ FNV32_BASE };
		for (unsigned char _char : str) {
			_hash *= FNV32_OFFSET;
			_hash ^= _char;
		}

		return _hash;
	}

	[[nodiscard]] consteval hash32_t hash_const(std::string_view str) noexcept {
		hash32_t _hash{ FNV32_BASE };
		for (unsigned char _char : str) {
			_hash *= FNV32_OFFSET;
			_hash ^= _char;
		}

		return _hash;
	}

	[[nodiscard]] hash64_t hash64(std::string_view str) noexcept {
		hash64_t _hash{ FNV64_BASE };
		for (unsigned char _char : str) {
			_hash *= FNV64_OFFSET;
			_hash ^= _char;
		}

		return _hash;
	}

	[[nodiscard]] consteval hash64_t hash64_const(std::string_view str) noexcept {
		hash64_t _hash{ FNV64_BASE };
		for (unsigned char _char : str) {
			_hash *= FNV64_OFFSET;
			_hash ^= _char;
		}

		return _hash;
	}

	namespace a1 {
		[[nodiscard]] hash32_t hash(std::string_view str) noexcept {
			hash32_t _hash{ FNV32_BASE };
			for (unsigned char _char : str) {
				_hash ^= _char;
				_hash *= FNV32_OFFSET;
			}

			return _hash;
		}

		[[nodiscard]] consteval hash32_t hash_const(std::string_view str) noexcept {
			hash32_t _hash{ FNV32_BASE };
			for (unsigned char _char : str) {
				_hash ^= _char;
				_hash *= FNV32_OFFSET;
			}

			return _hash;
		}

		[[nodiscard]] hash64_t hash64(std::string_view str) noexcept {
			hash64_t _hash{ FNV64_BASE };
			for (unsigned char _char : str) {
				_hash ^= _char;
				_hash *= FNV64_OFFSET;
			}

			return _hash;
		}

		[[nodiscard]] consteval hash64_t hash64_const(std::string_view str) noexcept {
			hash64_t _hash{ FNV64_BASE };
			for (unsigned char _char : str) {
				_hash ^= _char;
				_hash *= FNV64_OFFSET;
			}

			return _hash;
		}
	}
}
