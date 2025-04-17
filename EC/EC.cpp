#include "../usermode.h"

std::optional<uint32_t> memory::get_process_id(const std::string_view& process_name)
{
	const auto snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (snapshot == INVALID_HANDLE_VALUE)
		return {};

	PROCESSENTRY32 process_entry = { 0 };
	process_entry.dwSize = sizeof(process_entry);

	for (Process32First(snapshot, &process_entry); Process32Next(snapshot, &process_entry);)
	{
		if (std::string_view(process_entry.szExeFile) == process_name)
		{
			CloseHandle(snapshot);
			return process_entry.th32ProcessID;
		}
	}

	CloseHandle(snapshot);
	return {};
}

float GetSystemDPI()
{
	HDC hdc = NULL;
	int dpi_a = NULL, dpi_b = NULL,dpi=NULL;
	hdc = GetDC(0);
	dpi_a = GetDeviceCaps(hdc, 118) / GetDeviceCaps(hdc, 8) * 100;
	dpi_b = GetDeviceCaps(hdc, 88) / 96 * 100;
	ReleaseDC(NULL,hdc);
	if (dpi_a == 100) {
		dpi = dpi_b;
	}
	else if (dpi_b == 100) {
		dpi = dpi_a;
	}
	else if (dpi_a == dpi_b) {
		dpi = dpi_a;
	}
	else {
		dpi = 0;
	}
	return (float)dpi / 100;
}