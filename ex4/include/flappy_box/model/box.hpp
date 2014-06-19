#pragma once

#include "model/game_object.hpp"
#include "math.hpp"

namespace flappy_box
{
namespace model
{
    class Box : public ::model::GameObject
	{
	public:
		typedef ::model::GameObject super;

        Box(const bool dynamic_flag = true, const std::string& name = "untitled GameObject");
		virtual ~Box();

		vec3_type position() const;
		vec3_type& position();
		vec3_type acceleration() const;
		vec3_type& acceleration();
		vec3_type graviton() const;
		float speed() const;
		float& speed();
		float degree() const;
		
		void setPosition(vec3_type&);
		void setSpeed(float);
		void setAcceleration(vec3_type&);
		void setDegree(float);

	private:
		vec3_type _graviton;
        vec3_type _position;
		vec3_type _accel;
        float _deg;
		float _speed;
	};
}
}
