#include "SimpleDemo.h"
#include "Camera.h"
#include "Input.h"
#include <cmath>
#include "Environment.h"

//
// Initialises the class.
//
void SimpleDemo::OnInit()
{
	_pedistal = CreateShape<Mesh>();
	_pedistal->LoadFromFile("Meshes/cube.md2", "lines.pcx");
	_pedistal->SetColour(Colour::White);
	_pedistal->Mode(Mesh::DrawMode::DRAW_FRAGMENT);
	_pedistal->Shade(Mesh::ShadeMode::SHADE_PHONG);
	_pedistal->SetPosition({ 0, -43.f, 0 });

	_figurine = CreateShape<Mesh>();
	_figurine->LoadFromFile("Meshes/marvin.md2", "marvin.pcx");
	_figurine->SetColour(Colour::White);
	_figurine->Mode(Mesh::DrawMode::DRAW_FRAGMENT);
	_figurine->Shade(Mesh::ShadeMode::SHADE_PHONG);

	// Create light
	_directional = Environment::GetActive().CreateLight<DirectionalLight>().get();
	_directional->SetDirection(Vector3(-1.f, -1.f, 1.f));
	_directional->SetIntensity(Colour(1.f, 0.f, 0.f));

	// Create ambient light
	_ambient = Environment::GetActive().CreateLight<AmbientLight>().get();
	_ambient->SetIntensity(Colour(.1f, .1f, .1f));

	// Create point light
	_point = Environment::GetActive().CreateLight<PointLight>().get();
	_point->SetPosition(Vector3(0, 50, -50.f));
	_point->SetIntensity(Colour(.5f, .5f, 1.f));

	Camera::GetMainCamera()->SetPosition({ 0, 0, -50 });
	Camera::GetMainCamera()->SetRotation({ 0, 0, 0 });
}

//
// Will be called on every frame.
//
void SimpleDemo::OnTick(const float& deltaTime)
{
	Vector3 angle = { 0.f, .025f, 0.f };

	// A nice spinning animation!
	_figurine->Rotate(angle);
	_pedistal->Rotate(-angle);

	// Move the camera, hurray!
	Vector3 cameraMovement{ 0, 0, 0 };
	Vector3 cameraRotation{ 0, 0, 0 };

	// Cache input manager's pointer.
	Input* const inputManager = Input::Get();

	cameraMovement.SetX(inputManager->GetAxis("Horizontal"));
	cameraMovement.SetY(inputManager->GetAxis("Vertical"));
	cameraMovement.SetZ(inputManager->GetAxis("Forward"));

	cameraRotation.SetX(inputManager->GetAxis("Y") * .01f);
	cameraRotation.SetY(inputManager->GetAxis("X") * .01f);

	Camera* const mainCamera = Camera::GetMainCamera();

	Vector3 cameraCurrentPosition = mainCamera->GetPosition();
	Vector3 cameraCurrentRotation = mainCamera->GetRotation();

	cameraCurrentPosition = cameraCurrentPosition + cameraMovement;
	cameraCurrentRotation = cameraCurrentRotation + cameraRotation;

	mainCamera->SetPosition(cameraCurrentPosition);
	mainCamera->SetRotation(cameraCurrentRotation);

	Vector3 lightDir = _directional->GetDirection();
	lightDir = Matrix::RotationMatrix(0.f, .1f, 0.f) * lightDir;

	_directional->SetDirection(lightDir);
}