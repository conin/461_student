#ifndef PARTICLEEMITTER_H
#define PARTICLEEMITTER_H

#include "Math\Matrix.h"
#include "Math\Vect4D.h"
#include "Particle.h"

#include <list>

class ParticleEmitter
{
public:
	ParticleEmitter();
	~ParticleEmitter();

	void SpawnParticle();
	void update();
	void draw();

	void addParticleToList(Particle *const p);
	void removeParticleFromList(const Particle *const p);

	void Execute(Vect4D& pos, Vect4D& vel, Vect4D& sc);

private:

	
	float	spawn_frequency;
	float	last_spawn;
	float	last_loop;
	Particle *headParticle;

	int		max_particles;
	int		last_active_particle;
	float	max_life;
	float	scale_variance;
	
	Vect4D	start_position;
	Vect4D	start_velocity;
	Vect4D	vel_variance;
	Vect4D	pos_variance;
};

#endif // PARTICLEEMITTER_H
