#include "menu.hpp"

#include "globals.hpp"
#include "hooks.hpp"
#include "interfaces.hpp"

#include <imgui/imgui.h>
#include <imgui/imgui_impl_dx11.h>
#include <imgui/imgui_impl_win32.h>

#include <stdexcept>

static WNDPROC original_wndproc = nullptr;

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

LRESULT __stdcall hook_wndproc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	if (msg == WM_KEYDOWN && wparam == VK_INSERT) {
		globals::menu_opened = !globals::menu_opened;

		hooks::original_set_relative_mouse_mode(
			interfaces::input_system, globals::menu_opened ? false : globals::relative_mouse_mode);

		// ImGui::GetIO().MouseDrawCusor = globals::menuu_opened;

	}

	if (globals::menu_opened) {
		ImGui_ImplWin32_WndProcHandler(hwnd, msg, wparam, lparam);
		return true;
	}
	else {
		return CallWindowProcA(original_wndproc, hwnd, msg, wparam, lparam);
	}
}

namespace menu {
	void create() {
		if (interfaces::d3d11_device || !interfaces::d3d11_device_context) {
			throw std::runtime_error("interfaces not initialized");
		}

		original_wndproc = reinterpret_cast<WNDPROC>(SetWindowLongPtrA(
			interfaces::hwnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(hook_wndproc)));

		ImGui::CreateContext();

		ImGuiIO& io = ImGui::GetIO();
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls

		ImGui::StyleColorsDark(); // Setup Dear ImGui style

		if (!ImGui_ImplWin32_Init(interfaces::hwnd)) {
			throw std::runtime_error("ImGui_ImplWin32_Init failed");
		}
		
		if (!ImGui_ImplDX11_Init(interfaces::d3d11_device, interfaces::d3d11_device_context)) {
			throw std::runtime_error("ImGui_ImplDX11_Init failed");
		}
	}

	void destroy() {
		ImGui_ImplDX11_Shutdown();
		ImGui_ImplWin32_Shutdown();
		ImGui::DestroyContext();

		if (original_wndproc) {
			SetWindowLongPtrA(interfaces::hwnd, GWLP_WNDPROC,
								reinterpret_cast<LONG_PTR>(original_wndproc));
			original_wndproc = nullptr;
		}
	}

	void render() {
		if (!globals::menu_opened) {
			return;
		}

		ImGui::Begin("GIA Menu");
		ImGui::Text("Hello, Wavey!");
		ImGui::Text("This is a simple menu example.");
		ImGui::Text("Press INSERT to toggle the menu.");
		ImGui::End();

	}
}	// namespace menu

