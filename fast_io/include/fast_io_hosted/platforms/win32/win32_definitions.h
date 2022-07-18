﻿#pragma once

namespace fast_io::win32
{

struct overlapped
{
std::conditional_t<(sizeof(std::uintptr_t)>4),std::uint_least64_t,std::uint_least32_t> Internal,InternalHigh;
union dummy_union_name_t
{
struct dummy_struct_name_t
{
std::uint_least32_t Offset;
std::uint_least32_t OffsetHigh;
} dummy_struct_name;
void* Pointer;
}
dummy_union_name;
void* hEvent;
};
struct security_attributes
{
std::uint_least32_t nLength;
void* lpSecurityDescriptor;
int bInheritHandle;
};
struct startupinfo
{
std::uint_least32_t cb;
wchar_t* lpReserved;
wchar_t* lpDesktop;
wchar_t* lpTitle;
std::uint_least32_t dwX;
std::uint_least32_t dwY;
std::uint_least32_t dwXSize;
std::uint_least32_t dwYSize;
std::uint_least32_t dwXCountChars;
std::uint_least32_t dwYCountChars;
std::uint_least32_t dwFillAttribute;
std::uint_least32_t dwFlags;
std::uint_least16_t wShowWindow;
std::uint_least16_t cbReserved2;
int* lpReserved2;
void* hStdInput;
void* hStdOutput;
void* hStdError;
};
struct process_information
{
void* hProcess;
void* hThread;
std::uint_least32_t dwProcessId;
std::uint_least32_t dwThreadId;
};
/*
https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getfileinformationbyhandleex
*/
struct file_standard_info
{
std::int_least64_t AllocationSize;
std::int_least64_t EndOfFile;
std::uint_least32_t NumberOfLinks;
int DeletePending;
int Directory;
};

struct file_attribute_tag_info
{
std::uint_least32_t FileAttributes;
std::uint_least32_t ReparseTag;
};
enum class file_info_by_handle_class
{
FileBasicInfo,
FileStandardInfo,
FileNameInfo,
FileRenameInfo,
FileDispositionInfo,
FileAllocationInfo,
FileEndOfFileInfo,
FileStreamInfo,
FileCompressionInfo,
FileAttributeTagInfo,
FileIdBothDirectoryInfo,
FileIdBothDirectoryRestartInfo,
FileIoPriorityHintInfo,
FileRemoteProtocolInfo,
FileFullDirectoryInfo,
FileFullDirectoryRestartInfo,
FileStorageInfo,
FileAlignmentInfo,
FileIdInfo,
FileIdExtdDirectoryInfo,
FileIdExtdDirectoryRestartInfo,
FileDispositionInfoEx,
FileRenameInfoEx,
FileCaseSensitiveInfo,
FileNormalizedNameInfo,
MaximumFileInfoByHandleClass
};

struct filetime
{
std::uint_least32_t dwLowDateTime,dwHighDateTime;
};

struct by_handle_file_information
{
std::uint_least32_t    dwFileAttributes;
filetime	 ftCreationTime;
filetime	 ftLastAccessTime;
filetime	 ftLastWriteTime;
std::uint_least32_t    dwVolumeSerialNumber;
std::uint_least32_t    nFileSizeHigh;
std::uint_least32_t    nFileSizeLow;
std::uint_least32_t    nNumberOfLinks;
std::uint_least32_t    nFileIndexHigh;
std::uint_least32_t    nFileIndexLow;
};

struct coord
{
	std::int_least16_t X, Y;
};

struct small_rect
{
	std::int_least16_t Left, Top, Right, Bottom;
};

struct char_info
{
	char16_t character;
	std::uint_least16_t Attrib;
};

struct console_screen_buffer_info
{
	coord Size, CursorPosition;
	std::uint_least16_t Attrib;
	small_rect Window;
	coord MaxWindowSize;
};

struct guid
{
unsigned long  Data1;
unsigned short Data2;
unsigned short Data3;
unsigned char  Data4[8];
};

inline constexpr std::size_t wsaprotocol_len{255};

struct wsaprotocolchain
{
	int ChainLen;
	std::uint_least32_t ChainEntries[7];
};

struct wsaprotocol_infow
{
std::uint_least32_t            dwServiceFlags1;
std::uint_least32_t            dwServiceFlags2;
std::uint_least32_t            dwServiceFlags3;
std::uint_least32_t            dwServiceFlags4;
std::uint_least32_t            dwProviderFlags;
guid             ProviderId;
std::uint_least32_t            dwCatalogEntryId;
wsaprotocolchain ProtocolChain;
int              iVersion;
int              iAddressFamily;
int              iMaxSockAddr;
int              iMinSockAddr;
int              iSocketType;
int              iProtocol;
int              iProtocolMaxOffset;
int              iNetworkByteOrder;
int              iSecurityScheme;
std::uint_least32_t            dwMessageSize;
std::uint_least32_t            dwProviderReserved;
wchar_t  szProtocol[wsaprotocol_len + 1];
};

struct wsaprotocol_infoa
{
std::uint_least32_t            dwServiceFlags1;
std::uint_least32_t            dwServiceFlags2;
std::uint_least32_t            dwServiceFlags3;
std::uint_least32_t            dwServiceFlags4;
std::uint_least32_t            dwProviderFlags;
guid             ProviderId;
std::uint_least32_t            dwCatalogEntryId;
wsaprotocolchain ProtocolChain;
int              iVersion;
int              iAddressFamily;
int              iMaxSockAddr;
int              iMinSockAddr;
int              iSocketType;
int              iProtocol;
int              iProtocolMaxOffset;
int              iNetworkByteOrder;
int              iSecurityScheme;
std::uint_least32_t            dwMessageSize;
std::uint_least32_t            dwProviderReserved;
char  szProtocol[wsaprotocol_len + 1];
};

inline constexpr std::size_t wsadescription_len{256};
inline constexpr std::size_t wsasys_status_len{128};

struct wsadata {
	std::uint_least16_t	wVersion;
	std::uint_least16_t	wHighVersion;
#ifdef _WIN64
	unsigned short	iMaxSockets;
	unsigned short	iMaxUdpDg;
	char		*lpVendorInfo;
	char		szDescription[wsadescription_len+1];
	char		szSystemStatus[wsasys_status_len+1];
#else
	char		szDescription[wsadescription_len+1];
	char		szSystemStatus[wsasys_status_len+1];
	unsigned short	iMaxSockets;
	unsigned short	iMaxUdpDg;
	char		*lpVendorInfo;
#endif
};

struct wsabuf
{
std::uint_least32_t len;
char* buf;
};

struct wsamsg
{
void* name;
int namelen;
wsabuf* lpBuffers;
std::uint_least32_t dwBufferCount;
wsabuf Control;
std::uint_least32_t dwflags;
};

using lpwsaoverlapped_completion_routine = void (__stdcall*)(std::uint_least32_t dwError,std::uint_least32_t cbTransferred,overlapped* lpOverlapped,std::uint_least32_t dwFlags) noexcept;

struct flowspec
{
std::uint_least32_t TokenRate;
std::uint_least32_t TokenBucketSize;
std::uint_least32_t PeakBandwidth;
std::uint_least32_t Latency;
std::uint_least32_t DelayVariation;
std::uint_least32_t ServiceType;
std::uint_least32_t MaxSduSize;
std::uint_least32_t MinimumPolicedSize;
};

struct qualityofservice
{
flowspec SendingFlowspec;
flowspec ReceivingFlowspec;
wsabuf ProviderSpecific;
};


using lpconditionproc = void (__stdcall*)(wsabuf*,wsabuf*,qualityofservice*,qualityofservice*,wsabuf*,wsabuf*,std::uint_least32_t*,std::uintptr_t) noexcept;

template<win32_family fam>
requires (fam==win32_family::ansi_9x||fam==win32_family::wide_nt)
struct
#if __has_cpp_attribute(__gnu__::__may_alias__)
[[__gnu__::__may_alias__]]
#endif
win32_family_addrinfo
{
int              ai_flags{};
int              ai_family{};
int              ai_socktype{};
int              ai_protocol{};
std::size_t	 ai_addrlen{};
std::conditional_t<fam==win32_family::ansi_9x,char,wchar_t>  *ai_canonname{};
posix_sockaddr *ai_addr{};
win32_family_addrinfo<fam> *ai_next{};
};

using win32_addrinfo_9xa = win32_family_addrinfo<win32_family::ansi_9x>;
using win32_addrinfo_ntw = win32_family_addrinfo<win32_family::wide_nt>;

}
