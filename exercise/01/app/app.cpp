#include "pch.h"
#include "../lib/public.h"
#include "../dll2/public.h"

typedef double(*MYPROC)(int);

int main()
{
	// funkcije get_value iz static_library.lib (lib/public.h)
	std::cout << static_lib::get_value(1) << std::endl;

	// funkcije get_value iz dynamic_library.dll(potpis: double get_value(int))
	HINSTANCE libModule = LoadLibrary(TEXT("dynamic_library.dll"));
	if (libModule != NULL)
	{
		MYPROC procAdd = (MYPROC)GetProcAddress(libModule, "get_value");
		if (procAdd != NULL)
		{
			std::cout << procAdd(1) << std::endl;
		}
		FreeLibrary(libModule);
	}

	// funkcije get_value iz dynamic_library_with_implib.dll (dll2/public.h)
	std::cout << get_value(1) << std::endl;
}
