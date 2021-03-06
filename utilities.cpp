#include "utilities.hpp"

wrapper::directx12::uint32 wrapper::directx12::size_of(const DXGI_FORMAT& format)
{
	// todo : support more DXGI_FORMAT
	switch (format) {
	case DXGI_FORMAT_R8G8B8A8_UNORM: return 4;
	case DXGI_FORMAT_R32G32_FLOAT: return 8;
	case DXGI_FORMAT_R32G32B32_FLOAT: return 12;
	case DXGI_FORMAT_R32G32B32A32_FLOAT: return 16;
	default:
		throw "";
	}
	return 0;
}

wrapper::directx12::uint64 wrapper::directx12::align_to(uint64 value, uint64 alignment)
{
	return ((value + alignment - 1) / alignment) * alignment;
}

D3D12_CPU_DESCRIPTOR_HANDLE wrapper::directx12::offset_handle(const D3D12_CPU_DESCRIPTOR_HANDLE& handle, size_t value)
{
	return { handle.ptr + value };
}

D3D12_GPU_DESCRIPTOR_HANDLE wrapper::directx12::offset_handle(const D3D12_GPU_DESCRIPTOR_HANDLE& handle, size_t value)
{
	return { handle.ptr + value };
}

std::string wrapper::directx12::copy_data_to_string(void* data, size_t size_in_bytes)
{
	std::string value; value.resize(size_in_bytes);

	std::memcpy(value.data(), data, size_in_bytes);

	return value;
}

std::string wrapper::directx12::wide_string_to_multi_bytes_string(const std::wstring& wide_string)
{
	const auto size = WideCharToMultiByte(
		CP_ACP, 0, wide_string.c_str(),
		-1, nullptr, 0, nullptr, nullptr);

	std::string result; result.resize(size);
	
	WideCharToMultiByte(
		CP_ACP, 0, wide_string.c_str(),
		-1, result.data(), size, nullptr, nullptr);

	return result;
}

std::wstring wrapper::directx12::multi_bytes_string_to_wide_string(const std::string& string)
{
	const auto size = MultiByteToWideChar(CP_ACP, 0, string.c_str(), 
		static_cast<int>(string.size()), nullptr, 0);

	std::wstring result; result.resize(size);

	MultiByteToWideChar(CP_ACP, 0, string.c_str(), static_cast<int>(string.size()),
		result.data(), size);

	return result;
}
