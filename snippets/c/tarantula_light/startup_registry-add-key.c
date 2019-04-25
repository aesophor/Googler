#include <windows.h>

int main(void)
{
    TCHAR szPath[MAX_PATH];
    
    GetModuleFileName(NULL,szPath,MAX_PATH);
    HKEY newValue;
    RegOpenKey(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows\\CurrentVersion\\Run",&newValue);
    
    RegSetValueEx(newValue,"name_me",0,REG_SZ,(LPBYTE)szPath,sizeof(szPath));
    RegCloseKey(newValue);
    return 0;
}
