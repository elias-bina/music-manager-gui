#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "ressources-loading/download-management.h"

bool basic_youtube_audio_download(std::string name, std::string link){

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
			STARTUPINFO si;
			PROCESS_INFORMATION pi;

			ZeroMemory( &si, sizeof(si) );
			si.cb = sizeof(si);
			ZeroMemory( &pi, sizeof(pi) );

			char* cmdline = strdup(("./dependencies/yt-dlp/yt-dlp.sh " + link + "-x --audio-format mp3 -o " + "downloaded_songs/" + name).c_str());
			// Start the child process. 
			if( !CreateProcessA( NULL,   // No module name (use command line)
				cmdline,        // Command line
				NULL,           // Process handle not inheritable
				NULL,           // Thread handle not inheritable
				FALSE,          // Set handle inheritance to FALSE
				0,              // No creation flags
				NULL,           // Use parent's environment block
				NULL,           // Use parent's starting directory 
				&si,            // Pointer to STARTUPINFO structure
				&pi )           // Pointer to PROCESS_INFORMATION structure
			) 
			{
				printf( "CreateProcess failed (%d).\n", (int)GetLastError() );
				return;
			}
#else
			if (fork() == 0) {
			/*
			* fork() returns 0 to the child process
			* and the child's PID to the parent.
			*/
			execl("./dependencies/yt-dlp/yt-dlp.sh", "yt-dlp.sh", link.c_str(), "-x", "--audio-format", "mp3", "-o", ("downloaded_songs/" + name).c_str(), 0);
			//   execl("./dependencies/yt-dlp/yt-dlp.sh", "yt-dlp.sh", _link.c_str(), "-x", "--audio-format", "mp3", "-o", ("downloaded_songs/" + _name).c_str(), "-q", 0);
			/*
			* We wouldn't still be here if execl() was successful,
			* so a non-zero exit value is appropriate.
			*/
			exit(1);
			}
#endif

	return false;
}