#include "FollowCamera.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

const float FollowCamera::CAMERA_DISTANCE = 5.f;

FollowCamera::FollowCamera(int width, int height) : Camera(width, height)
{
	m_targetPos = Vector3::Zero;
	m_targetAngle = 0.f;

}

void FollowCamera::Update()
{
	Vector3 eyepos, refpos;

	refpos = m_targetPos + Vector3(0, 2, 0);

	Vector3 cameraV(0, 0, CAMERA_DISTANCE);

	Matrix rotmat = Matrix::CreateRotationY(m_targetAngle);

	cameraV = Vector3::TransformNormal(cameraV, rotmat);

	eyepos = refpos + cameraV;

	Camera::SetEyePos(eyepos);
	Camera::SetRefPos(refpos);

	Camera::Update();

	
}

void FollowCamera::SetTargetPos(const DirectX::SimpleMath::Vector3 & targetpos)
{
	m_targetPos = targetpos;
}

void FollowCamera::SetTargetAngle(float targetangle)
{
	m_targetAngle = targetangle;
}
