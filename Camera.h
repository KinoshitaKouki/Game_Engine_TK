/// <summary>
/// カメラを制御するクラス
/// </summary>
#pragma once

#include <d3d11_1.h>
#include <SimpleMath.h>

class Camera
{
public:
	//ここからメンバ関数を書く

	
	Camera(int width, int height);
	virtual ~Camera();

	//更新
	virtual void Update();

	//ビュー行列の取得
	const DirectX::SimpleMath::Matrix& GetViewMatrix();

	//射影行列の取得
	const DirectX::SimpleMath::Matrix& GetProjectionMatrix();

	//視点座標のセット
	void SetEyePos(DirectX::SimpleMath::Vector3 eyepos);

	void SetRefPos(DirectX::SimpleMath::Vector3 refpos);

	void SetUpvec(DirectX::SimpleMath::Vector3 upvec);

	void SetFovY(float fovY);

	void SetAspect(float aspect);

	void SetNearClip(float nearclip);

	void SetFarClip(float farclip);

protected:

	//カメラの位置(視点座標)
	DirectX::SimpleMath::Vector3 m_eyepos;
	//カメラの見ている先
	DirectX::SimpleMath::Vector3 m_refpos;
	//カメラの上方向ベクトル
	DirectX::SimpleMath::Vector3 m_upvec;
	//ビュー行列
	DirectX::SimpleMath::Matrix m_view;
	//垂直方向視野角
	float m_FovY;
	//アスペクト比
	float m_Aspect;
	//射影行列
	DirectX::SimpleMath::Matrix m_Projmat;
	//ニアクリップ
	float m_NearClip;
	//ファークリップ
	float m_FarClip;

	
};
