#include "KeyboardController.h"



CKeyboardController::CKeyboardController( CTank *tank )
    : CController(tank)
    , m_bShooting(false)
{

}


CKeyboardController::~CKeyboardController(void)
{
}

void CKeyboardController::update( float dt )
{
    if (m_pTank)
    {
        if (m_pTank->isMoving() == false)
        {
            // �ƶ�
            for (int key = VK_LEFT; key <= VK_DOWN; key++)
            {
                if (KEY_DOWN(key))
                {
                    m_pTank->move((eMoveDirection)(MOVE_LEFT + (key - VK_LEFT)));
                    break;
                }
            }
        }

        
        // ����
        if (KEY_DOWN(VK_NUMPAD0))
        {
            if (m_bShooting == false)
            {
                m_pTank->shoot();
                m_bShooting = true;
            }
        }
        else
        {
            m_bShooting = false;
        }


        // �л�̹��
        if (KEY_DOWN(VK_NUMPAD7))
        {
            m_pTank->changeControllTank();
        }
    }
}


CKeyboardController2::CKeyboardController2( CTank *tank )
    : CController(tank)
    , m_bShooting(false)
{

}


CKeyboardController2::~CKeyboardController2(void)
{
}

void CKeyboardController2::update( float dt )
{
    if (m_pTank)
    {
        if (m_pTank->isMoving() == false)
        {
            // �ƶ�
            if (KEY_DOWN('W'))
            {
                m_pTank->move(MOVE_UP);
            }
            else if (KEY_DOWN('S'))
            {
                m_pTank->move(MOVE_DOWN);
            }
            else if (KEY_DOWN('A'))
            {
                m_pTank->move(MOVE_LEFT);
            }
            else if (KEY_DOWN('D'))
            {
                m_pTank->move(MOVE_RIGHT);
            }
        }

        // ����
        if (KEY_DOWN(VK_SPACE))
        {
            if (m_bShooting == false)
            {
                m_pTank->shoot();
                m_bShooting = true;
            }
        }
        else
        {
            m_bShooting = false;
        }

         // �л�̹��
        if (KEY_DOWN(VK_LCONTROL))
        {
            m_pTank->changeControllTank();
        }
    }
}
