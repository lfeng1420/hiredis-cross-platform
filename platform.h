#ifndef __PLATFORM_H
#define __PLATFORM_H

#if defined(_WIN32) || defined(_WIN64)

#include <Winsock2.h>

#define OS_WINDOWS
#define close_socket                closesocket
#define read_buffer(fd, buf, len)   recv(fd, buf, len, 0)
#define write_buffer(fd, buf, len)  send(fd, buf, len, 0)
#define strdup                      _strdup
#define poll                        WSAPoll
#define ERRNO                       WSAGetLastError()
#define SET_ERRNO(err)              WSASetLastError(err)
typedef SSIZE_T                     ssize_t;
#define strcasecmp                  _stricmp
#define strncasecmp                 _strnicmp

#else

#define close_socket    close
#define read_buffer(fd, buf, len)   read(fd, buf, len)
#define write_buffer(fd, buf, len)  write(fd, buf, len)
#define ERRNO                       errno
#define SET_ERRNO(err)              errno = err

#endif

#endif