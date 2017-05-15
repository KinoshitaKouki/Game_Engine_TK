/// <summary>
/// �J�����𐧌䂷��N���X
/// </summary>
#pragma once

#include <d3d11_1.h>
#include <SimpleMath.h>

class Camera
{
public:
	//�������烁���o�֐�������

	
	Camera(int width, int height);
	virtual ~Camera();

	//�X�V
	virtual void Update();

	//�r���[�s��̎擾
	const DirectX::SimpleMath::Matrix& GetViewMatrix();

	//�ˉe�s��̎擾
	const DirectX::SimpleMath::Matrix& GetProjectionMatrix();

	//���_���W�̃Z�b�g
	void SetEyePos(DirectX::SimpleMath::Vector3 eyepos);

	void SetRefPos(DirectX::SimpleMath::Vector3 refpos);

	void SetUpvec(DirectX::SimpleMath::Vector3 upvec);

	void SetFovY(float fovY);

	void SetAspect(float aspect);

	void SetNearClip(float nearclip);

	void SetFarClip(float farclip);

protected:

	//�J�����̈ʒu(���_���W)
	DirectX::SimpleMath::Vector3 m_eyepos;
	//�J�����̌��Ă����
	DirectX::SimpleMath::Vector3 m_refpos;
	//�J�����̏�����x�N�g��
	DirectX::SimpleMath::Vector3 m_upvec;
	//�r���[�s��
	DirectX::SimpleMath::Matrix m_view;
	//������������p
	float m_FovY;
	//�A�X�y�N�g��
	float m_Aspect;
	//�ˉe�s��
	DirectX::SimpleMath::Matrix m_Projmat;
	//�j�A�N���b�v
	float m_NearClip;
	//�t�@�[�N���b�v
	float m_FarClip;

	
};
