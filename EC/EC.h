#pragma once
#include "imgui.h"
namespace sys
{
	inline BOOL debug = false;
	inline BOOL norefresh = false;//禁止DMA内部刷新
	inline BOOL ReadType = false;//假:WINAPI		真:DMA
	inline BOOL loop = false;//主要的线程循环条件
	inline uint64_t 剩余时间 = NULL;
	inline HWND hWnd = NULL;//窗口句柄
	inline uint32_t dwPID = NULL;
	inline FLOAT dpi = NULL;
	inline uint32_t ScreenX = NULL;
	inline uint32_t ScreenY = NULL;
	inline uint32_t SizeX = NULL;
	inline uint32_t SizeY = NULL;
	inline BOOL 主界面状态 = NULL;
	inline BOOL 垂直同步 = NULL;
	inline ImFont* _默认字体_18 = nullptr;
	inline ImFont* _默认字体_22 = nullptr;
	inline ImFont* _默认字体_28 = nullptr;
	inline ImFont* _默认字体_48 = nullptr;
	inline ImFont* _数字字体2_18 = nullptr;
	inline ImFont* _数字字体2_32 = nullptr;
	inline ImFont* _数字字体2_64 = nullptr;
	inline ImFont* _数字字体_32 = nullptr;
	inline ImFont* _软件图标_28 = nullptr;
	inline ImFont* _武器字体 = nullptr;
}

namespace imp
{
	void imgui();
	inline nlohmann::json Weapon = {};
	inline nlohmann::json Config = {};
}

#define NT_SUCCESS(status) (static_cast<long>(status) >= 0)

struct __system_handle_t
{
	unsigned long m_process_id;
	uint8_t m_object_type_number;
	uint8_t m_flags;
	uint16_t m_handle;
	void* m_object;
	ACCESS_MASK m_granted_access;
};

struct system_handle_info_t
{
	unsigned long m_handle_count;
	__system_handle_t m_handles[1];
};
class memory
{
public:
	std::optional<uint32_t> get_process_id(const std::string_view& process_name);
};

inline const std::unique_ptr<memory> m_memory{ new memory() };

float GetSystemDPI();
void InputHandler(HWND hWnd);
BOOL UpdateWindowData(HWND hWnd, HWND im_hWnd);
void LoadFonts();