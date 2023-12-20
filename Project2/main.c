#include <Windows.h>
#include <stdio.h>

int main()
{
	char* path = ("E:\\Project\\New\\Visual stadio\\Project2\\New\\*");

	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = FindFirstFileA(path, &FindFileData);

	if (hFind == INVALID_HANDLE_VALUE)
	{
		printf("%d\n", GetLastError());
		return 1;
	}

	/*
	Since technically they are both directories (".." is the parent directory
	and the "." is the current directory), you can test the dwFileAttributes
	field for the directory bit.
	*/

	/*
	while (FindNextFileA(hFind, &FindFileData) != 0)  **Using while insted of do - While, you can delete "."
	*/
	do
	{
		if (FindFileData.cFileName[0] == '.' || FindFileData.cFileName[0] == '..') continue;
		/*
		//if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) continue; **Using this,
		it will exclude all directories. So if you only want to exclude the parent 
		and current directories, you can test first character like (line28)
		*/

		printf("File name: %s\n", FindFileData.cFileName);
	} while (FindNextFileA(hFind, &FindFileData) != 0);

	FindClose(hFind);
	return 0;
}