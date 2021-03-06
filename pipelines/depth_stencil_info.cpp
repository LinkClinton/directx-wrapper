#include "depth_stencil_info.hpp"

wrapper::directx12::depth_stencil_info::depth_stencil_info()
{
	mDesc.DepthEnable = true;
	mDesc.DepthWriteMask = D3D12_DEPTH_WRITE_MASK_ALL;
	mDesc.DepthFunc = D3D12_COMPARISON_FUNC_LESS;
	mDesc.StencilEnable = false;
	mDesc.StencilReadMask = D3D12_DEFAULT_STENCIL_READ_MASK;
	mDesc.StencilWriteMask = D3D12_DEFAULT_STENCIL_WRITE_MASK;
	mDesc.FrontFace.StencilDepthFailOp = D3D12_STENCIL_OP_KEEP;
	mDesc.FrontFace.StencilPassOp = D3D12_STENCIL_OP_KEEP;
	mDesc.FrontFace.StencilFailOp = D3D12_STENCIL_OP_KEEP;
	mDesc.FrontFace.StencilFunc = D3D12_COMPARISON_FUNC_ALWAYS;
	mDesc.BackFace.StencilDepthFailOp = D3D12_STENCIL_OP_KEEP;
	mDesc.BackFace.StencilPassOp = D3D12_STENCIL_OP_KEEP;
	mDesc.BackFace.StencilFailOp = D3D12_STENCIL_OP_KEEP;
	mDesc.BackFace.StencilFunc = D3D12_COMPARISON_FUNC_ALWAYS;
}

wrapper::directx12::depth_stencil_info& wrapper::directx12::depth_stencil_info::set_depth_enable(bool enable)
{
	mDesc.DepthEnable = enable;

	return *this;
}

wrapper::directx12::depth_stencil_info& wrapper::directx12::depth_stencil_info::set_depth_write_mask(
	const D3D12_DEPTH_WRITE_MASK& mask)
{
	mDesc.DepthWriteMask = mask;

	return *this;
}

wrapper::directx12::depth_stencil_info& wrapper::directx12::depth_stencil_info::set_depth_function(
	const D3D12_COMPARISON_FUNC& function)
{
	mDesc.DepthFunc = function;

	return *this;
}

wrapper::directx12::depth_stencil_info& wrapper::directx12::depth_stencil_info::set_depth_all_configs(
	const D3D12_COMPARISON_FUNC& function, const D3D12_DEPTH_WRITE_MASK& mask, bool enable)
{
	return
		set_depth_function(function).
		set_depth_write_mask(mask).
		set_depth_enable(enable);
}

D3D12_DEPTH_STENCIL_DESC wrapper::directx12::depth_stencil_info::desc() const
{
	return mDesc;
}
