#include "usermode.h"
#include <iostream>
using namespace std;
int main(int argc,char* argv[]){
	system("title 【Shrimp】Exterior auto - 1.413");
	for (int i = 1; i < argc; i++)	{	//从1开始,网上说0通常是程序名而已
			std::string arg = argv[i];
			if (arg == "debug"){
				sys::debug = 1;
			}
			else if(arg=="norefresh") {
				sys::norefresh = 1;
			}
			else if (arg == "WINAPI") {
				sys::ReadType = false;
			}
			else if (arg == "DMA") {
				sys::ReadType = true;
			}
	}
	if (sys::debug == 1)
	{
		LOG_WARNING("调试模式");
	}
	else if (argc <= 1)
	{
		LOG_WARNING("运行参数错误!");
		cin.get();
		return 0;
	}
	LOG_INFO("初始化...");
	sys::剩余时间 = 869918530;
	if (startInit()) {
		imp::imgui();
		cin.get();
	}
	return 0;
}

BOOL startInit()//初始化.获取游戏窗口句柄|进程PID or DMA相关初始化
{
	sys::loop = sys::剩余时间 > 0;
	if (sys::debug){
		return 1;
	}
	LOG_INFO("获取游戏进程PID...");
	if (sys::ReadType){

	}
	else {
		HWND hWnd = FindWindow ("SDL_app", "Counter-Strike 2");
		if (hWnd==NULL) {
			hWnd = FindWindow ("SDL_app", "反恐精英：全球攻势");
		}
		if (hWnd==NULL) {
			LOG_WARNING("游戏未运行!");
			return 0;
		}
		else {
			sys::hWnd = hWnd;
			const auto dwPID = m_memory->get_process_id("cs2.exe");
			if (!dwPID.has_value())
			{
				LOG_ERROR("游戏未运行!")
					return 0;
			}
			sys::dwPID = dwPID.value();
			if (sys::dwPID > 1)
			{
				return 1;
			}
		}
	}
	return 0;
}

BOOL GetGameClientAddress()
{

	return 1;
}