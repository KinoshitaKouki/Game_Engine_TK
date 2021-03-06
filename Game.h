//
// Game.h
//

#pragma once

#include "StepTimer.h"
#include "DebugCamera.h"
#include "Camera.h"
#include "FollowCamera.h"

#include <PrimitiveBatch.h>
#include <VertexTypes.h>
#include <Effects.h>
#include <CommonStates.h>
#include <SimpleMath.h>
#include <Keyboard.h>
#include <Model.h>



// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game
{
public:

    Game();

    // Initialization and management
    void Initialize(HWND window, int width, int height);

    // Basic game loop
    void Tick();

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowSizeChanged(int width, int height);

    // Properties
    void GetDefaultSize( int& width, int& height ) const;

private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();
    void Present();

    void CreateDevice();
    void CreateResources();

    void OnDeviceLost();

    // Device resources.
    HWND                                            m_window;
    int                                             m_outputWidth;
    int                                             m_outputHeight;

    D3D_FEATURE_LEVEL                               m_featureLevel;
    Microsoft::WRL::ComPtr<ID3D11Device>            m_d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11Device1>           m_d3dDevice1;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext>     m_d3dContext;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext1>    m_d3dContext1;

    Microsoft::WRL::ComPtr<IDXGISwapChain>          m_swapChain;
    Microsoft::WRL::ComPtr<IDXGISwapChain1>         m_swapChain1;
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView>  m_renderTargetView;
    Microsoft::WRL::ComPtr<ID3D11DepthStencilView>  m_depthStencilView;

    // Rendering loop timer.
    DX::StepTimer                                   m_timer;

	//プリミティブバッチ
	std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionNormal>> m_batch;
	//エフェクト
	std::unique_ptr<DirectX::BasicEffect> m_effect;
	//入力レイアウト
	Microsoft::WRL::ComPtr<ID3D11InputLayout> m_Layout;
	//汎用ステート
	std::unique_ptr<DirectX::CommonStates> m_states;
	//キーボード
	std::unique_ptr<DirectX::Keyboard> keyboard;

	//ワールド行列
	DirectX::SimpleMath::Matrix m_world;
	//ビュー行列
	DirectX::SimpleMath::Matrix m_view;
	//プロジェクション行列
	DirectX::SimpleMath::Matrix m_proj;

	//デバッグカメラ
	std::unique_ptr<DebugCamera> m_debugCamera;

	//エフェクトファクトリ
	std::unique_ptr<DirectX::EffectFactory>m_factory;

	//地面モデル
	std::unique_ptr<DirectX::Model>m_modelGround;

	//球モデル
	std::unique_ptr<DirectX::Model>m_modelSkyDome;

	//頭のモデル
	std::unique_ptr<DirectX::Model>m_modelHead;
	
	//ティーポットモデル
	std::unique_ptr<DirectX::Model>m_modelTeaPot;
	
	//球のワールド行列
	DirectX::SimpleMath::Matrix m_worldBall[20];

	//地面のワールド行列
	DirectX::SimpleMath::Matrix m_worldGround;

	//ティーポットのワールド行列
	DirectX::SimpleMath::Matrix m_worldTeaPot;

	//頭のワールド行列
	DirectX::SimpleMath::Matrix head_world;

	//頭のポジション
	DirectX::SimpleMath::Vector3 head_pos;

	float head_rot;

	int m_count;

	//カメラ
	std::unique_ptr<FollowCamera>m_Camera;
};