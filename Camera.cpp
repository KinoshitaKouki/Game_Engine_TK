#include "Camera.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

Camera::Camera(int width,int height)
{
	//�����o�ϐ��̏�����
	m_eyepos = Vector3(0, 0, 5);
	m_refpos = Vector3(0, 0, 0);
	m_upvec  = Vector3(0, 1, 0);

	m_FovY = XMConvertToRadians(60.f);
	m_Aspect = (float) width / height;
	m_NearClip = 0.1f;
	m_FarClip = 1000.f;

	//�r���[�s��̐���
	m_view = Matrix::CreateLookAt(m_eyepos, m_refpos, m_upvec);

	//�ˉe�s��̐���ddd
	m_Projmat = Matrix::CreatePerspectiveFieldOfView(m_FovY, m_Aspect, m_NearClip, m_FarClip);
	
}

Camera::~Camera()
{
}

void Camera::Update()
{
	//�r���[�s��̐���
	m_view = Matrix::CreateLookAt(m_eyepos, m_refpos, m_upvec);

	//�ˉe�s��̐���
	m_Projmat = Matrix::CreatePerspectiveFieldOfView(m_FovY, m_Aspect, m_NearClip, m_FarClip);
}

const Matrix& Camera::GetViewMatrix()
{
	return m_view;
}

const Matrix& Camera::GetProjectionMatrix()
{
	return m_Projmat;
}

void Camera::SetEyePos(DirectX::SimpleMath::Vector3 eyepos)
{
	m_eyepos = eyepos;
}

void Camera::SetRefPos(DirectX::SimpleMath::Vector3 refpos)
{
	m_refpos = refpos;
}

void Camera::SetUpvec(DirectX::SimpleMath::Vector3 upvec)
{
	m_upvec = upvec;
}

void Camera::SetFovY(float FovY)
{
	m_FovY = FovY;
}

void Camera::SetAspect(float aspect)
{
	m_Aspect = aspect;
}

void Camera::SetNearClip(float nearclip)
{
	m_NearClip = nearclip;
}

void Camera::SetFarClip(float farclip)
{
	m_FarClip = farclip;
}





