#ifndef SHASH
#define SHASH
#include <stdint.h>
#include <string_view>

namespace fnv {
	using hash32_t = int32_t;
	using hash64_t = int64_t;

	inline constexpr hash32_t FNV32_BASE{ 2166136261 };
	inline constexpr hash32_t FNV32_OFFSET{ 16777619u };
	inline constexpr hash64_t FNV64_BASE{ 14695981039346656037 };
	inline constexpr hash64_t FNV64_OFFSET{ 1099511628211 };

	[[nodiscard]] constexpr hash32_t hash(std::string_view str) noexcept {
		hash32_t _hash{ FNV32_BASE };
		for (unsigned char _char : str) {
			_hash *= FNV32_OFFSET;
			_hash ^= _char;
		}

		return _hash;
	}

	[[nodiscard]] constexpr hash64_t hash64(std::string_view str) noexcept {
		hash64_t _hash{ FNV64_BASE };
		for (unsigned char _char : str) {
			_hash *= FNV64_OFFSET;
			_hash ^= _char;
		}

		return _hash;
	}

	namespace a1 {
		[[nodiscard]] constexpr hash32_t hash(std::string_view str) noexcept {
			hash32_t _hash{ FNV32_BASE };
			for (unsigned char _char : str) {
				_hash ^= _char;
				_hash *= FNV32_OFFSET;
			}

			return _hash;
		}

		[[nodiscard]] constexpr hash64_t hash64(std::string_view str) noexcept {
			hash64_t _hash{ FNV64_BASE };
			for (unsigned char _char : str) {
				_hash ^= _char;
				_hash *= FNV64_OFFSET;
			}

			return _hash;
		}
	}
}
#endif
