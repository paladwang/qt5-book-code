#ifndef ONELEVEL_H
#define ONELEVEL_H
#include "common.h"
#include "twolevel.h"

class onelevel {
private:
    string  m_name; // 指标名称
    unsigned m_levelid; //指标ID
    map<int,twolevel*> m_mapTwoLevel;
public:
    onelevel(string& name,unsigned levelID):m_name(name),m_levelid(levelID){;}
    onelevel(char* name,unsigned levelID):m_name(name),m_levelid(levelID){;}
    onelevel():m_name("default onelevel"),m_levelid(tlevel::unkown) {;}
    onelevel(onelevel& c) {
        m_name = c.m_name;
        m_levelid = c.m_levelid;
        map<int,twolevel*>::iterator it;
        for(it=c.m_mapTwoLevel.begin();it!=c.m_mapTwoLevel.end();++it) {
            twolevel* twoLevel = new twolevel(*(it->second));
            m_mapTwoLevel[twoLevel->getLevelID()] = twoLevel;
        }
    }

public:
    string getName() {return m_name;}
    unsigned getLevelID() {return m_levelid;}
    bool isReady() {
        map<int,twolevel*>::iterator it;
        for(it=m_mapTwoLevel.begin();it!=m_mapTwoLevel.end();++it) {
            if (!it->second->isReady()) {
                return false;
            }
        }
        if (m_levelid<tlevel::t1 || m_levelid>tlevel::t7) {
            return false;
        }
        return true;
    }
    unsigned getTwoLevelNum() { return m_mapTwoLevel.size();}
    map<int,twolevel*>::const_iterator begin() {return m_mapTwoLevel.begin();}
    map<int,twolevel*>::const_iterator end() { return m_mapTwoLevel.end();}
public:
    void setTwoLevel(twolevel* twoLevel) {
        if(!twoLevel->isReady()) {
            throw std::runtime_error("the twolevel is not ready");
        }
        if( m_mapTwoLevel.count(twoLevel->getLevelID())>0 ) {
            delete m_mapTwoLevel[twoLevel->getLevelID()]; //delete就的twolevel
        }
        m_mapTwoLevel[twoLevel->getLevelID()] = twoLevel;
    }
};

#endif // ONELEVEL_H
