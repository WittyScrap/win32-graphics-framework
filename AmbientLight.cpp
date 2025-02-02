#include "AmbientLight.h"

//
// Call superconstructor.
//
AmbientLight::AmbientLight() : Light()
{ }

//
// Returns a constant value related to its intensity.
//
Colour AmbientLight::CalculateContribution(const Vertex& position, const Vector3& normal, const Colour& ambient, const float& roughness, const float& specular)
{
	return ambient * GetIntensity();
}
