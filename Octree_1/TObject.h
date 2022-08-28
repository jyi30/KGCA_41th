#pragma once
#include "TCollision.h"
#include <string>
class TBaseObject
{
public:
    std::string  m_csName;
    float       m_fFriction;
    float       m_fMass;
    float       m_fSpeed;
public:
    TVector    m_vDirection;
    TBox       m_Box;
    TSphere    m_Sphere;
    TVector    m_vAcceleration;
    TVector    m_vVelocity;
    TVector    m_vForces;
public:
    virtual void   Init() {};
    virtual void   Frame(float fDeltaTime, float fGameTime) {};
};

class TObject : public TBaseObject
{
public:
    void   SetSphere(TVector vCenter, float radius);
    void   SetSphere(TBox box);
    void   SetPosition(TVector p, TVector s);
public:
    virtual void   Init() override;
    virtual void   Frame(float fDeltaTime, float fGameTime)override;
public:
    virtual void   AddForces(TVector f);
public:
    TObject();
    TObject(std::string name);
};