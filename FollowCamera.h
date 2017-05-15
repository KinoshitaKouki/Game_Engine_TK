#pragma once

#include "Camera.h"

class FollowCamera : public Camera
{
public:
	//‹@‚ÆƒJƒƒ‰‚Ì‹——£
	static const float CAMERA_DISTANCE;

	FollowCamera::FollowCamera(int width,int height);

	void Update() override;

	//’Ç]‘ÎÛ‚ÌÀ•W
	void SetTargetPos(const DirectX::SimpleMath::Vector3& targetpos);

	void SetTargetAngle(float m_targetangle);

protected:
	//’Ç]‘ÎÛ‚ÌÀ•W
	DirectX::SimpleMath::Vector3 m_targetPos;
	//’Ç]‘ÎÛ‚Ì‰ñ“]Šp	
	float m_targetAngle;
};