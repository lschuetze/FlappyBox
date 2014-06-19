#include "flappy_box/view/box_audible.hpp"

using namespace ::flappy_box::view;

BoxAudible::BoxAudible(std::shared_ptr<::flappy_box::model::Box> object)
: _object(object), base_frequency(400.0), target_frequency(100.0)
{
	alGenBuffers(2, _al_buffer);
	alGenSources(2, _al_box_source);

	alSource3f(_al_box_source[0], AL_POSITION, 0.5, 0.0, 0.0);
	_al_buffer[0] = alutCreateBufferWaveform(ALUT_WAVEFORM_SINE, base_frequency, 0.0, 10.0);
	alSourcei(_al_box_source[0], AL_BUFFER, _al_buffer[0]);
	alSourcei(_al_box_source[0], AL_LOOPING, AL_TRUE);
	alSourcePlay(_al_box_source[0]);

	alSource3f(_al_box_source[1], AL_POSITION, -0.5, 0.0, 0.0);
	_al_buffer[1] = alutCreateBufferWaveform(ALUT_WAVEFORM_SINE, target_frequency, 0.0, 10.0);
	alSourcei(_al_box_source[1], AL_BUFFER, _al_buffer[1]);
	alSourcei(_al_box_source[1], AL_LOOPING, AL_TRUE);
	alSourcePlay(_al_box_source[1]);
}

BoxAudible::~BoxAudible()
{
}


void BoxAudible::auralize(::view::AlRenderer & r)
{
	double val = (target_frequency + 10 * std::abs(_object->position()(2))) / base_frequency;
	alSourcef(_al_box_source[0], AL_PITCH, val);
	alSourcef(_al_box_source[1], AL_PITCH, val);
}