#pragma once

#include "../memory_utils.hpp"

struct IDXGISwapChain;

namespace sdk {
	class interface_swap_chain_dx11 {
	private:
		padding<0x170> m_pad0;

	public:
		IDXGISwapChain* swap_chain;
	};
}  // namespace sdk