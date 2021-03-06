/*********************************************************************
 *           Copyright (C) 2017 mwl4 - All rights reserved           *
 *********************************************************************
 * File       : bone.h
 * Project    : ConverterPIX
 * Developers : Michal Wojtowicz (mwl450@gmail.com)
 			  : Piotr Krupa (piotrkrupa06@gmail.com)
 *********************************************************************/

#pragma once

#include <math/vector.h>
#include <math/matrix.h>
#include <math/quaternion.h>

class Bone
{
	friend Model;
	friend Animation;
private:
	int32_t m_index = 0;
	String m_name;
	Float4x4 m_transformation;
	Float4x4 m_transReversed;
	Quaternion m_stretch;
	Quaternion m_rotation;
	Float3 m_translation;
	Float3 m_scale;
	float m_signOfDeterminantOfMatrix = 1.f;
	int32_t m_parent = -1;
};

/* eof */
