// dllmain.cpp : 定義 DLL 應用程式的進入點。
#include "pch.h"
#include "DirectXTex.h"

BOOL APIENTRY DllMain(HMODULE hModule,
                      DWORD ul_reason_for_call,
                      LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

extern "C" __declspec(dllexport) _Use_decl_annotations_
HRESULT GetMetadataFromDDSMemory(
	const uint8_t* pSource,
	size_t size,
	DirectX::DDS_FLAGS flags,
	DirectX::TexMetadata& metadata) noexcept
{
	return DirectX::GetMetadataFromDDSMemoryEx(pSource, size, flags, metadata, nullptr);
}

extern "C" __declspec(dllexport) _Use_decl_annotations_
HRESULT LoadFromDDSMemory(
	const uint8_t* pSource,
	size_t size,
	DirectX::DDS_FLAGS flags,
	DirectX::TexMetadata* metadata,
	DirectX::ScratchImage& image) noexcept
{
	return DirectX::LoadFromDDSMemoryEx(pSource, size, flags, metadata, nullptr, image);
}

extern "C" __declspec(dllexport) _Use_decl_annotations_
HRESULT Decompress(
	const DirectX::Image& cImage,
	DXGI_FORMAT format,
	DirectX::ScratchImage& image) noexcept
{
	return DirectX::Decompress(cImage, format, image);
}

extern "C" __declspec(dllexport) void ScratchImage_Release(DirectX::ScratchImage& image) noexcept
{
	image.Release();
}
