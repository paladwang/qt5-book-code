#ifndef TWOLEVEL_H
#define TWOLEVEL_H
#include "common.h"

class twolevel {
private:
    string  m_name; // 指标名称
    unsigned m_levelid; //指标ID
    double  m_value; //指标值
    bool m_bIsPositive; //true: 正向指标
public:
    twolevel(string& name,unsigned levelID,double value,bool bIsPositive):m_name(name),m_levelid(levelID),m_value(value),m_bIsPositive(bIsPositive) {;}
    twolevel(char* name,unsigned levelID,double value,bool bIsPositive):m_name(name),m_levelid(levelID),m_value(value),m_bIsPositive(bIsPositive) {;}
    twolevel():m_name("default twolevel"),m_value(DBL_MAX),m_levelid(tlevel::unkown),m_bIsPositive(true) {;}

public:
    string getName() {return m_name;}
    double getValue() {return m_value;}
    unsigned getLevelID() {return m_levelid;}
    bool isPositive() {return m_bIsPositive;}
    bool isReady() {
        if (m_value!=DBL_MAX && m_levelid>=tlevel::t1 && m_levelid<=tlevel::t7) {
            return true;
        }
        return false;
    }
};


#endif // TWOLEVEL_H
