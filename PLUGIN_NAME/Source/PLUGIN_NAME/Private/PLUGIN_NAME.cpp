#include "PLUGIN_NAME.h"

#define LOCTEXT_NAMESPACE "FPLUGIN_NAMEModule"

void FPLUGIN_NAMEModule::StartupModule()
{
	// ���� ��� ����� �������� ����� �������� ������ ������ � ������; ������ ����� ������� � ����� .plugin ��� ������� ������
	
}

void FPLUGIN_NAMEModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	// ��� ������� ����� ���� ������� �� ����� ���������� ��� ������� ������ ������. ��� �������, �������������� ������������ ������������,
	// �� �������� ��� ������� ����� ��������� ������.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FPLUGIN_NAMEModule, PLUGIN_NAME)