#include "MyForm.h"
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	AIproj1::MyForm form;
	Application::Run(%form);

	
}
