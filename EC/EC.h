#pragma once
#include "imgui.h"
namespace sys
{
	inline BOOL debug = false;
	inline BOOL norefresh = false;//��ֹDMA�ڲ�ˢ��
	inline BOOL ReadType = false;//��:WINAPI		��:DMA
	inline BOOL loop = false;//��Ҫ���߳�ѭ������
	inline uint64_t ʣ��ʱ�� = NULL;
	inline HWND hWnd = NULL;//���ھ��
	inline uint32_t dwPID = NULL;
	inline FLOAT dpi = NULL;
	inline uint32_t ScreenX = NULL;
	inline uint32_t ScreenY = NULL;
	inline uint32_t SizeX = NULL;
	inline uint32_t SizeY = NULL;
	inline BOOL ������״̬ = NULL;
	inline BOOL ��ֱͬ�� = NULL;
	inline ImFont* _Ĭ������_18 = nullptr;
	inline ImFont* _Ĭ������_22 = nullptr;
	inline ImFont* _Ĭ������_28 = nullptr;
	inline ImFont* _Ĭ������_48 = nullptr;
	inline ImFont* _��������2_18 = nullptr;
	inline ImFont* _��������2_32 = nullptr;
	inline ImFont* _��������2_64 = nullptr;
	inline ImFont* _��������_32 = nullptr;
	inline ImFont* _���ͼ��_28 = nullptr;
	inline ImFont* _�������� = nullptr;
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