/*********************************************************************
 *           Copyright (C) 2017 mwl4 - All rights reserved           *
 *********************************************************************
 * File       : pma.h
 * Project    : ConverterPIX
 * Developers : Michal Wojtowicz (mwl450@gmail.com)
 			  : Piotr Krupa (piotrkrupa06@gmail.com)
 *********************************************************************/

#pragma once

#include <math/vector.h>
#include <math/matrix.h>
#include <math/quaternion.h>
#include <utils/token.h>

#pragma pack(push, 1)

namespace prism
{
	struct pma_header_t
	{
		u32 m_version;				// +0
		token_t m_name;				// +4
		u16 m_frames;				// +12
		u16 m_flags;				// +14
		u32 m_bones;				// +16
		float m_anim_length;		// +20
		i32 m_lengths_offset;		// +24
		i32 m_bones_offset;			// +28
		i32 m_frames_offset;		// +32
		i32 m_delta_trans_offset;	// +36
		i32 m_delta_rot_offset;		// +40

		static const u32 SUPPORTED_VERSION = 0x03;
	};	ENSURE_SIZE(pma_header_t, 44);

	struct pma_frame_t
	{
		quat_t m_scale_orient;		// +0
		quat_t m_rot;				// +16
		float3 m_trans;				// +32
		float3 m_scale;				// +44
	};	ENSURE_SIZE(pma_frame_t, 56);
} // namespace prism

#pragma pack(pop)

/* eof */
