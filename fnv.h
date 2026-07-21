#ifndef FNV
#define FNV
#include <stdint.h>
#include <string_view>

namespace fnv {
	using hash32_t = uint32_t;
	using hash64_t = uint64_t;

	inline constexpr hash32_t FNV32_BASE{ 2166136261 };
	inline constexpr hash32_t FNV32_OFFSET{ 16777619u };
	inline constexpr hash64_t FNV64_BASE{ 14695981039346656037 };
	inline constexpr hash64_t FNV64_OFFSET{ 1099511628211 };

	[[nodiscard]] constexpr hash32_t hash(std::string_view str) noexcept {
		hash32_t tmp{ FNV32_BASE };

		for (char c : str) {
			tmp *= FNV32_OFFSET;
			tmp ^= c;
		}
	}

	[[nodiscard]] constexpr hash32_t hash64(std::string_view str) noexcept {
		hash32_t tmp{ FNV32_BASE };

		for (char c : str) {
			tmp *= FNV64_OFFSET;
			tmp ^= c;
		}
	}

	namespace a1 {
		[[nodiscard]] constexpr hash32_t hash(std::string_view str) noexcept {
			hash32_t tmp{ FNV32_BASE };

			for (char c : str) {
				tmp ^= c;
				tmp *= FNV32_OFFSET;
			}
		}

		[[nodiscard]] constexpr hash32_t hash64(std::string_view str) noexcept {
			hash32_t tmp{ FNV32_BASE };

			for (char c : str) {
				tmp ^= c;
				tmp *= FNV64_OFFSET;
			}
		}
	}
}
#endif
