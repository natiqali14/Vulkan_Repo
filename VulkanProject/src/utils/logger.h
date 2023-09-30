#pragma once
#include "../defines.h"
template<typename ... Args>
void log_msg(FILE* stream, const char* msg, Args&&... args) {
	if (!DEBUG_MODE) return;
	if (!stream) return;	
	fprintf(stream, msg, args...); 
	fprintf(stream, "\n");

}
template<typename ... Args>
void log_msg_fatal(FILE* stream , const char* msg, Args&&... args) {
	if (!stream) return;
	fprintf(stream, "----- Fatal Error -----\n");
	fprintf(stream, msg, args...);
	fprintf(stream, "\n");
	/*if (!stream) return;
	fprintf(stream, "----- Fatal Error -----\n");

	const char* escape_1 = "\033[31m";
	const char* escape_2 = "\033[0m";
	u32 count = strlen(msg) + 2 + strlen(escape_1) + strlen(escape_2);
	char* new_char = new char[count];
	sprintf(new_char, "%s%s%s", escape_1, msg, escape_2);

	fprintf(stream, new_char, args...);*/
	//delete[] new_char;
	//HANDLE console_handle = GetStdHandle(STD_ERROR_HANDLE);
	//static u8 levels[] = { 64, 4, 6, 2, 1, 8 };
	//SetConsoleTextAttribute(console_handle, levels[0]);

	//OutputDebugStringA(msg);
	//u64 length = strlen(msg);
	//LPDWORD written_numbers = 0;
	//WriteConsoleA(console_handle, msg, (DWORD)length, written_numbers, 0);
}
