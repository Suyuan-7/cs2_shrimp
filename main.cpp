#include "usermode.h"
#include <iostream>
using namespace std;
int main(int argc,char* argv[]){
	system("title ��Shrimp��Exterior auto - 1.413");
	for (int i = 1; i < argc; i++)	{	//��1��ʼ,����˵0ͨ���ǳ���������
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
		LOG_WARNING("����ģʽ");
	}
	else if (argc <= 1)
	{
		LOG_WARNING("���в�������!");
		cin.get();
		return 0;
	}
	LOG_INFO("��ʼ��...");
	sys::ʣ��ʱ�� = 869918530;
	if (startInit()) {
		imp::imgui();
		cin.get();
	}
	return 0;
}

BOOL startInit()//��ʼ��.��ȡ��Ϸ���ھ��|����PID or DMA��س�ʼ��
{
	sys::loop = sys::ʣ��ʱ�� > 0;
	if (sys::debug){
		return 1;
	}
	LOG_INFO("��ȡ��Ϸ����PID...");
	if (sys::ReadType){

	}
	else {
		HWND hWnd = FindWindow ("SDL_app", "Counter-Strike 2");
		if (hWnd==NULL) {
			hWnd = FindWindow ("SDL_app", "���־�Ӣ��ȫ����");
		}
		if (hWnd==NULL) {
			LOG_WARNING("��Ϸδ����!");
			return 0;
		}
		else {
			sys::hWnd = hWnd;
			const auto dwPID = m_memory->get_process_id("cs2.exe");
			if (!dwPID.has_value())
			{
				LOG_ERROR("��Ϸδ����!")
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