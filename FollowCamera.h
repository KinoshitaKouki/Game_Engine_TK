#pragma once

#include "Camera.h"

class FollowCamera : public Camera
{
public:
	//���@�ƃJ�����̋���
	static const float CAMERA_DISTANCE;

	FollowCamera::FollowCamera(int width,int height);

	void Update() override;

	//�Ǐ]�Ώۂ̍��W
	void SetTargetPos(const DirectX::SimpleMath::Vector3& targetpos);

	void SetTargetAngle(float m_targetangle);

protected:
	//�Ǐ]�Ώۂ̍��W
	DirectX::SimpleMath::Vector3 m_targetPos;
	//�Ǐ]�Ώۂ̉�]�p	
	float m_targetAngle;
};