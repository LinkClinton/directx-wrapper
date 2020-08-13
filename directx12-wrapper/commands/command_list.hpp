#pragma once

#include "command_allocator.hpp"

namespace wrapper::directx12 {

	struct value32bit {
		union {
			uint32 uint32;
			int32 int32;
			real real;
		};

		value32bit() = default;

		value32bit(const directx12::uint32& value) : uint32(value) {}

		value32bit(const directx12::int32& value) : int32(value) {}

		value32bit(const directx12::real& value) : real(value) {}
	};
	
	class graphics_command_list final : public wrapper_t<ID3D12GraphicsCommandList4> {
	public:
		graphics_command_list() = default;

		explicit graphics_command_list(const ComPtr<ID3D12GraphicsCommandList4>& source);

		~graphics_command_list() = default;

		void clear_render_target_view(const D3D12_CPU_DESCRIPTOR_HANDLE& view,  const std::array<float, 4>& color) const;

		void set_descriptor_heaps(const std::vector<ComPtr<ID3D12DescriptorHeap>>& heaps) const;
		
		void set_render_targets(const std::vector<D3D12_CPU_DESCRIPTOR_HANDLE>& views, const D3D12_CPU_DESCRIPTOR_HANDLE& depth_stencil) const;
		
		void set_render_targets(const std::vector<D3D12_CPU_DESCRIPTOR_HANDLE>& views) const;

		void set_vertex_buffers(const std::vector<D3D12_VERTEX_BUFFER_VIEW>& views, size_t start_slot = 0) const;

		void set_index_buffer(const D3D12_INDEX_BUFFER_VIEW& view) const;
		
		void set_view_ports(const std::vector<D3D12_VIEWPORT>& viewports) const;

		void set_scissor_rects(const std::vector<D3D12_RECT>& rects) const;

		void set_graphics_constants(size_t index, const void* data, size_t count, size_t offset) const;

		void set_graphics_constants(size_t index, const std::vector<value32bit>& values) const;
		
		static graphics_command_list create(const device& device, const command_allocator& allocator);
	};
	
}
