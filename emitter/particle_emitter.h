#ifndef HINAPE_PARTICLE_EMITTER_H
#define HINAPE_PARTICLE_EMITTER_H

// Copyright (c) 2023 Xayah Hina
// MPL-2.0 license

#include "backends/objects/arrow.h"

namespace HinaPE
{
class ParticleEmitter3 : public Kasumi::ArrowObject
{
public:
	virtual void emit(std::vector<mVector3> *positions, std::vector<mVector3> *velocities) = 0;
};

class PointParticleEmitter3 final : public ParticleEmitter3
{
public:
	void emit(std::vector<mVector3> *positions, std::vector<mVector3> *velocities) final;
	PointParticleEmitter3();

	struct Opt
	{
		bool enable = true;

		real speed = 20;
		real spread_angle = 30;

		size_t particles_at_once = 1000;
		size_t remaining_particles = 50000;
	} _opt;

private:
	std::mt19937 _rng;
};

class VolumeParticleEmitter3 final : public ParticleEmitter3
{
public:
	void emit(std::vector<mVector3> *positions, std::vector<mVector3> *velocities) final;
	VolumeParticleEmitter3();

	struct Opt
	{
		real multiplier = 1;
		real spacing = 1.4 * 0.017;
		bool one_shot = true;
		bool shot = false;
	} _opt;

private:
	std::mt19937 _rng;
	Geom::ImplicitSurface3Ptr _surface; // TODO
};

using ParticleEmitter3Ptr = std::shared_ptr<ParticleEmitter3>;
using PointParticleEmitter3Ptr = std::shared_ptr<PointParticleEmitter3>;
} // namespace HinaPE

#endif //HINAPE_PARTICLE_EMITTER_H
