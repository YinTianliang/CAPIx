#define _CRT_SECURE_NO_WARNINGS

#include "CPWDLLA.H"

//#include <shlwapi.h>
#include <direct.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

BOOL WINAPI	PathFileExistsA(const char *);
LPTSTR WINAPI	GetCommandLineA(void);
PTSTR WINAPI	PathGetArgsA(PTSTR pszPath);

int main(int argc, char *argv[])
{
	int			n;
	char			strDll[MAX_PATH];
	char			cmdLine[8192] = "";
	const char		*argument = PathGetArgsA(GetCommandLineA());

	STARTUPINFO		si = { sizeof(si), 0 };
	PROCESS_INFORMATION	pi = { 0 };

	GetModuleFileNameA(NULL, strDll, MAX_PATH);
	strrchr(strDll, '\\')[1] = '\0';
	strcat(strDll, "CAPIx.dll");

	// puts(strDll);
	if(!PathFileExistsA(strDll)) * (void **) 0 = 0;

	strcpy(cmdLine, getenv("ComSpec"));
	strcat(cmdLine, " ");
	strcat(cmdLine, argument);

	// puts(cmdLine);
	if(argument[0] == '\0') puts("This is a CMD with CAPIx.dll");

	CreateProcessWithDllA(NULL, cmdLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi, strDll, NULL);

	WaitForSingleObject(pi.hProcess, INFINITE);

	return 0;
}
