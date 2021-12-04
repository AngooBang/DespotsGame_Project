#include "stdafx.h"
#include "Animator.h"

HRESULT Animator::Init(const WCHAR* path, POINT pos, int renderSizeX, int renderSizeY, int maxFrameX, int maxFrameY, bool isLoop, float motionSpeed, float scale)
{
    m_path = path;

    m_renderPos = pos;
    m_renderSizeX = renderSizeX;
    m_renderSizeY = renderSizeY;

    m_img = FROM_FILE(m_path);
    m_maxFrameX = maxFrameX;
    m_maxFrameY = maxFrameY;

    mb_isLoop = isLoop;

    m_currFrameX = 0;
    m_currFrameY = 0;

    m_frameSizeX = m_img->GetWidth() / (m_maxFrameX + 1);
    m_frameSizeY = m_img->GetHeight() / (m_maxFrameY + 1);

    m_motionSpeed = motionSpeed;
    m_scale = scale;
    
    return S_OK;
}

void Animator::Update()
{
    m_animationElapsed += TimerManager::GetSingleton()->GetDeltaTime();
    if (m_animationElapsed > m_motionSpeed)
    {
        ++m_currFrameX;
        if (m_currFrameX > m_maxFrameX)
        {
            if (mb_isLoop)
            {
                m_currFrameX = 0;
            }
            else
            {
                --m_currFrameX;
            }
        }
        m_animationElapsed = 0.0f;
    }
}

void Animator::Render(HDC hdc)
{
    Graphics g(hdc);

    g.DrawImage(m_img, Rect(m_renderPos.x + CAMERA_VIEW_X, m_renderPos.y + CAMERA_VIEW_Y, m_renderSizeX, m_renderSizeY),
        m_frameSizeX * m_currFrameX, m_frameSizeY * m_currFrameY, m_frameSizeX, m_frameSizeY, UnitPixel);
}

void Animator::Release()
{
}

void Animator::DownFrame()
{
    m_animationElapsed += TimerManager::GetSingleton()->GetDeltaTime();
    if (m_animationElapsed > m_motionSpeed)
    {
        --m_currFrameX;
        if (m_currFrameX < 0)
        {
            if (mb_isLoop)
            {
                m_currFrameX = m_maxFrameX;
            }
            else
            {
                ++m_currFrameX;
            }
        }
        m_animationElapsed = 0.0f;
    }
}
